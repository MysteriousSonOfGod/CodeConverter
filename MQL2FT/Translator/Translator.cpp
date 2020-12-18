// Translator.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <filesystem>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <locale>
#include <codecvt>
#include <tchar.h>
#include "RegexData.h"
#include "GrammarListener.h"
//#include "ANTLR_Runtime\src\ANTLRInputStream.h"
#include "src\ANTLRInputStream.h"
#include "GrammarLexer.h"
//#include "..\ANTLR_Runtime\src\CommonTokenStream.h"
#include "src\CommonTokenStream.h"
#include "GrammarParser.h"
#include "Listener.h"
#include "ListenerTeller.h"

using namespace std;

string add_at_begining = "\n#include \"pch.h\"\n\n#include \"FTCore.h\"\n#include \"MqlStdIncludes.h\"\n#include \"mql4.h\"\n#include \"MqlEnums.enm\"\n\nnamespace mql4\n{\n\n";

bool preprocess(ifstream& input, istringstream& output, wstring srcpath);
void postprocess(const string& fname, bool header = false);
wstring extractFileName(const wstring& srcPath);
void insertFileNameToDestFile(const wstring& destPath, const wstring& fileName);

int checkAndReplaceLong(string& file, int i);
int checkAndReplaceFloat(string& file, int i);

void fileToStr(ifstream& file, string& str);
void fileToStr(wifstream& file, wstring& str);
wstring utf8ToUtf16(const string& utf8Str);
string utf16ToUtf8(const wstring& utf16Str);

bool findStr(const string& str, int i, const string& srch);
inline bool isWspace(char c) { return c == ' ' || c == '\t' || c == '\r' || c == '\n'; }


int translateANTLR(wstring srcpath, const string& destpath, const string& destpath_header, bool needAST = false)
{
	ifstream from(srcpath);
	ofstream to(destpath);
	ofstream head(destpath_header);
    ofstream treefile;

	cout << "-> Translating...";

	istringstream from_str;

	if(!preprocess(from, from_str, srcpath))
	{
		from.close();
		to.close();
		head.close();
		return -1;
	}
	from.close();

	antlr4::ANTLRInputStream* inputStream = new antlr4::ANTLRInputStream(from_str);
	GrammarLexer* lexer = new GrammarLexer(inputStream);
	antlr4::CommonTokenStream* tokens = new antlr4::CommonTokenStream(lexer);
	GrammarParser* primaryParser = new GrammarParser(tokens);
	GrammarParser* parser = new GrammarParser(tokens);

	//ParseTree* primaryTree = primaryParser->primaryTraverse();
	//tokens->seek(0);
	ParseTree* tree = parser->compileUnit();

    Listener* listener = nullptr;
    antlr4::tree::ParseTreeWalker* walker = nullptr;

    if (needAST) {
        treefile.open("Tree.txt");
        listener = new ListenerTeller(&to, &head, &add_at_begining, &treefile);
    }
    else {
        listener = new Listener(&to, &head, &add_at_begining);
    }

    walker = new antlr4::tree::ParseTreeWalker();
    walker->walk(listener, tree);

    listener->addToBuffers = false;
	listener->SetOutpuTraverse();
    walker->walk(listener, tree);

    int scriptType = listener->getScriptType();

	//system("cls");
	/*delete inputStream;
	delete lexer;
	delete tokens;
	delete parser;
	delete listener;
	delete tree;*/
	
	treefile.close();
	to.close();
	head.close();
    if (needAST) treefile.close();

	postprocess(destpath);
	postprocess(destpath_header, true);
    insertFileNameToDestFile(utf8ToUtf16(destpath), extractFileName(srcpath));

	cout << "\n-> Done translation.\n";
	return scriptType;
}

int _tmain(int argc, _TCHAR** argsv)
{
	int scriptType = 0;

    const string argv2 = utf16ToUtf8(argsv[2]);
    const string argv3 = utf16ToUtf8(argsv[3]);

    if (argc == 4)
    {
        scriptType = translateANTLR(argsv[1], argv2, argv3);
    }
    else if (argc == 5 && wstring(argsv[4]) == L"/t")
    {
        // translate with AST to file
        scriptType = translateANTLR(argsv[1], argv2, argv3, true);
    }
    else {
        printf("\nUsage: Translator.exe [source_file] [dest.cpp] [dest.h]\n"
               "       Translator.exe [source_file] [dest.cpp] [dest.h] [/t]\n\n"
               "       /t        debug mode, writing AST to file\n\n");
    }
    return scriptType;
}

bool preprocess(ifstream& input, istringstream& output, wstring srcpath)
{
	string file;
	fileToStr(input, file);

	int pos = 0;
	while((pos = file.find("#include", pos)) != string::npos)
	{
		string inc_line = file.substr(pos, file.find('\n', pos)-pos);

		if(inc_line.find('<') != string::npos)
		{
			file.insert(pos, "//");
			pos += inc_line.find_last_of('>');
			continue;
		}

		const int first = inc_line.find_first_of('"');
		const int last = inc_line.find_last_of('"');

		const string inc_fname = inc_line.substr(first+1, last-first-1);

		if(inc_fname == "..//Libraries//stdlib.mq4")
		{
			file.insert(pos, "//");
			pos += last;
			continue;
		}

		srcpath.replace(srcpath.find_last_of(L'\\')+1, wstring::npos, utf8ToUtf16(inc_fname));

		ifstream inc_ifs(srcpath);
		if(!inc_ifs.is_open())
		{
			cout << "\nInclude file \"" << inc_fname << "\" not found!\n";
			return false;
		}

		string inc_file("\n");
		fileToStr(inc_ifs, inc_file);
		inc_file += "\n";
		inc_ifs.close();

		file.replace(pos, last+1, inc_file);
	}

	bool in_str = false;
	unsigned short back_slash = 0;
	for(int i = 0; i < file.size(); ++i)
	{
		if(!in_str)
		{
			i += checkAndReplaceFloat(file, i);
		}

		if(!in_str && file[i] == '"')
		{
			in_str = true;
		}
		else if(file[i] == '"' && file[i - 1] != '\\')
		{
			in_str = false;
		}
		else if(file[i] == '\\')
		{
			++back_slash;
		}
		else if(file[i] == '"' && !(back_slash & 1))
		{
			in_str = false;
			back_slash = 0;
		}
		else
		{
			back_slash = 0;
		}
	}

	output.str(file);
	return true;
}

void postprocess(const string& fname, bool header)
{
	ifstream ifs(fname);
	string file;
	fileToStr(ifs, file);
	ifs.close();

	string mql_file;
	string transtor_gen_code;

	string add_begin;

	if(header)
	{
		add_begin = file.substr(0, file.find("namespace mql4"));
		mql_file = file.substr(file.find("namespace mql4"));
	}
	else
	{
		const size_t pos = file.find("void RegisterOptions()");
		mql_file = file.substr(0, pos);
		mql_file = mql_file.substr(add_at_begining.size());
		transtor_gen_code = file.substr(pos);
	}

	bool in_str = false;
	unsigned short back_slash = 0;
	for (int i = 0; i < mql_file.size(); ++i)
	{
		if(!in_str)
		{
			i += checkAndReplaceLong(mql_file, i);

			if(mql_file.find("MqlEnum::Element", i, 16) != string::npos)
			{
				while(mql_file[i] != '\n')
				{
					++i;
				}
			}
		}
		
		if(!in_str && mql_file[i] == '"')
		{
			in_str = true;
		}
		else if (mql_file[i] == '"' && mql_file[i - 1] != '\\')
		{
			in_str = false;
			mql_file.insert(i + 1, "s");
		}
		else if (mql_file[i] == '\\')
		{
			++back_slash;
		}
		else if (mql_file[i] == '"' && !(back_slash & 1))
		{
			in_str = false;
			back_slash = 0;
			mql_file.insert(i + 1, "s");
		}
		else
		{
			back_slash = 0;
		}
	}

	// Comment #imports
	size_t imp = mql_file.find("#import");
	if(imp != string::npos)
	{
		mql_file.insert(imp, "//");
		imp = mql_file.find((char)10, imp);
		while(true)
		{
			++imp;
			size_t end = mql_file.find((char)10, imp);
			string line = mql_file.substr(imp, end - imp);

			if(line.find("#import") != string::npos)
			{
				mql_file.insert(imp, "//");
				end += 2;
				imp = end;
				continue;
			}

			if(line.find_first_not_of(" \t") == string::npos)
			{
				imp = end;
				continue;
			}
			
			size_t obracket = line.find('(');
			size_t cbracket = line.find(')', obracket);
			size_t smcol = line.find(';', cbracket);
			size_t eq = line.find('=');

			// If this is first non-function declaration after #import stop commenting
			if(obracket == string::npos || cbracket == string::npos || smcol == string::npos || eq != string::npos)
			{
				break;
			}

			mql_file.insert(imp, "//");
			end += 2;

			imp = end;
		}
	}

	ofstream ofs(fname, ios::out | ios::trunc);
	if(header)
	{
		ofs << add_begin << mql_file;
	}
	else
	{
		ofs << add_at_begining << mql_file << transtor_gen_code;
	}
	ofs.close();
}

wstring extractFileName(const wstring& srcPath)
{
    wstring filename;
    wstring srcpath_str(srcPath);
    int backslash_pos = srcpath_str.find_last_of(L'\\');
    if (backslash_pos != -1) filename = srcpath_str.substr(backslash_pos + 1, srcpath_str.length());
    else filename = srcpath_str;

    int ext_pos = filename.find_last_of(L'.');
    if (ext_pos != -1) filename = filename.substr(0, ext_pos);

    return filename;
}

void insertFileNameToDestFile(const wstring& destPath, const wstring& fileName)
{
    wifstream fromFile(destPath);
    wstring dest_cpp_file;
    fileToStr(fromFile, dest_cpp_file);
    fromFile.close();
    
    const vector<wstring> funcsForScriptName = {
        L"StrategyShortName(\"",
        L"IndicatorShortName(\"",
        L"StrategyDescription(\""
    };

    const size_t posOfRegisterOptionsFunc = dest_cpp_file.rfind(L"void RegisterOptions()");
    for (const auto& shortName : funcsForScriptName)
    {
        const size_t pos_short_name = dest_cpp_file.find(shortName, posOfRegisterOptionsFunc + 1);
        if (pos_short_name != wstring::npos)
        {
            dest_cpp_file.insert(shortName.length() + pos_short_name, fileName);
        }
    }
    
    const locale utf8_locale(locale(), new codecvt_utf8<wchar_t>());
    wofstream toFile(destPath);
    toFile.imbue(utf8_locale);
      
    toFile << dest_cpp_file;
    toFile.close();
}

int checkAndReplaceLong(string& file, int i)
{
	if(file.size() - i < 5 || i < 1)
	{
		return 0;
	}

	if(!isWspace(file[i-1]) || file[i] != 'l' || file[i+1] != 'o' || file[i+2] != 'n' ||
	   file[i+3] != 'g' || (!isWspace(file[i+4]) && file[i+4] != '(' && file[i+4] != ')'))
	{
		return 0;
	}

	for(int j = i+4; j < file.size(); ++j)
	{
		if(isWspace(file[j]))
		{
			continue;
		}

		if(file[j] == '(')
		{
			file.replace(i, j-i, "(long long)");
			return 11;
		}
		else
		{
			file.replace(i, j-i, "long long ");
			return 10;
		}
	}

	return 0;
}

int checkAndReplaceFloat(string& file, int i)
{
	if(file.size() - i < 6 || i < 1)
	{
		return 0;
	}

	if(!isWspace(file[i-1]) || file[i] != 'f' || file[i+1] != 'l' || file[i+2] != 'o' ||
		file[i+3] != 'a' ||	file[i+4] != 't' || (!isWspace(file[i+5]) && file[i+5] != '(' && file[i+5] != ')'))
	{
		return 0;
	}

	file.replace(i, 5, "double");
	return 6;
}

void fileToStr(ifstream& file, string& str)
{
	char c;
	while(file.get(c))
	{
		str.push_back(c);
	}
}

void fileToStr(wifstream& file, wstring& str)
{
    wchar_t c;
    while (file.get(c))
    {
        str.push_back(c);
    }
}

wstring utf8ToUtf16(const string& utf8Str)
{
    wstring_convert<codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(utf8Str);
}

string utf16ToUtf8(const wstring& utf16Str)
{
    wstring_convert<codecvt_utf8_utf16<wchar_t>> conv;
    return conv.to_bytes(utf16Str);
}

bool findStr(const string& str, int i, const string& srch)
{
	int s = srch.size();
	if(str.size() - i < s || str.size() < s)
	{
		return false;
	}

	for(int j = 0; j < s; ++j, ++i)
	{
		if(str[i] != srch[j])
		{
			return false;
		}
	}

	return true;
}