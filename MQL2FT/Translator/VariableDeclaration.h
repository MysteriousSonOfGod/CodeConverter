#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

enum VarType { Int, UInt, Long, ULong, Short, UShort, Char, UChar, Double, Float, Bool, Other};

class VariableDeclaration
{
private:
	std::string name;

	int dimention = 0;
	std::vector<std::string> sizes;

	std::string initList;
	bool _1DInitList = true;

	static std::map<string, VarType> variable_names;
	static const std::string variable_prefix;
	static const set<string> onCalculateParams;
public:
	VariableDeclaration();
	~VariableDeclaration();

	const string& Name();
	void SetName(string& name);
	void SetName(string&& name);

	static void InsertVarName(const std::string&& name, VarType type = Other);
	static const std::string PrefixedVarName(const std::string& name);
	static const std::string PrefixedVarName(const std::string&& name);
	static const std::string CheckVarName(const std::string& name, VarType& type, bool except = false);
	static const std::string CheckVarName(const std::string&& name, VarType& type, bool except = false);
	static const std::string CheckVarName(const std::string& name, bool except = false);
	static const std::string CheckVarName(const std::string&& name, bool except = false);

	bool IsArray();

	void SetInitValue(string& init_lst);
	void SetInitValue(string&& init_lst);
	std::string GetInitializer();
	const string& GetInitValue();
	bool HasInitializer();

	bool Is1DInitList();
	void Is1DInitList(bool value);

	//void SetDim(int dim);
	int GetDim();
	void AddDimSize(string& size);
	const string& GetDimSize(int dim);
};

