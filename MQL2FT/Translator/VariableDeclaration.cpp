#include "VariableDeclaration.h"

std::map<string, VarType> VariableDeclaration::variable_names;
const std::string VariableDeclaration::variable_prefix = "var_";
const set<string> VariableDeclaration::onCalculateParams = {
			"time", "open", "high", "low", "close", "tick_volume", "volume", "spread"
};

VariableDeclaration::VariableDeclaration()
{
}

VariableDeclaration::~VariableDeclaration()
{
}

void VariableDeclaration::InsertVarName(const string && name, VarType type)
{
	variable_names.insert(std::pair<string, VarType>(name, type));
}

const std::string VariableDeclaration::PrefixedVarName(const std::string & name)
{
	return variable_prefix + name;
}

const std::string VariableDeclaration::PrefixedVarName(const std::string && name)
{
	return PrefixedVarName(name);
}

const string VariableDeclaration::CheckVarName(const string & name, VarType& type, bool except)
{
	std::map<string, VarType>::iterator res = variable_names.find(name);

	if (except &&
		onCalculateParams.find(name) != onCalculateParams.end())
	{
		if (res != variable_names.end())
		{
			type = res->second;
		}
		return name;
	}
	else {
		if (res != variable_names.end())
		{
			type = res->second;
			return variable_prefix + name;
		}
		else return name;
	}
}

const string VariableDeclaration::CheckVarName(const string && name, VarType& type, bool except)
{
	return CheckVarName(name, type, except);
}

const string VariableDeclaration::CheckVarName(const string & name, bool except)
{
	if (except && 
		onCalculateParams.find(name) != onCalculateParams.end())
	{
		return name;
	}
	else {
		if (variable_names.find(name) != variable_names.end())
		{
			return variable_prefix + name;
		}
		else return name;
	}
}

const string VariableDeclaration::CheckVarName(const string && name, bool except)
{
	return CheckVarName(name, except);
}

void VariableDeclaration::AddDimSize(string& size)
{
	this->dimention++;
	this->sizes.push_back(size);
}

const string & VariableDeclaration::GetDimSize(int dim)
{
	if (dim >= sizes.size() || dim < 0) return "";
	return this->sizes[dim];
}

const string & VariableDeclaration::Name()
{
	return this->name;
}

void VariableDeclaration::SetName(string & name)
{
	this->name = name;
}

void VariableDeclaration::SetName(string && name)
{
	this->name = name;
}

void VariableDeclaration::SetInitValue(string& init_lst)
{
	this->initList = init_lst;
}

void VariableDeclaration::SetInitValue(string && init_lst)
{
	this->initList = init_lst;
}

std::string VariableDeclaration::GetInitializer()
{
	return string(" = " + this->initList);
}

const string & VariableDeclaration::GetInitValue()
{
	return this->initList;
}

bool VariableDeclaration::HasInitializer()
{
	return this->initList != "";
}

bool VariableDeclaration::Is1DInitList()
{
	return this->_1DInitList;
}

void VariableDeclaration::Is1DInitList(bool value)
{
	this->_1DInitList = value;
}

/*
void VariableDeclaration::SetDim(int dim)
{
	this->dimention = dim;
}
*/

int VariableDeclaration::GetDim()
{
	//return this->dimention;
	return this->sizes.size();
}

bool VariableDeclaration::IsArray()
{
	return this->dimention > 0;
}
