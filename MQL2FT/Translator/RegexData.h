#include <regex>
#include <string>
#pragma once

using namespace std;

class RegexData
{
private:
	string* reg_expr;
	string* func_name;
	string* format;
	regex* re;
public:
	RegexData(const string& exp, const string& func, const string& form);
	~RegexData();

	regex* GetRegex();
	string* GetFormat();
};

