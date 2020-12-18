#include "MultivariableDeclaration.h"


MultivariableDeclaration::MultivariableDeclaration()
{
}

MultivariableDeclaration::~MultivariableDeclaration()
{
}

const string & MultivariableDeclaration::Type()
{
	return this->type;
}

bool MultivariableDeclaration::IsConst()
{
	return this->isConst;
}

void MultivariableDeclaration::IsConst(bool is_const)
{
	this->isConst = is_const;
}

bool MultivariableDeclaration::IsReference()
{
	return this->isFunctionParam;
}

void MultivariableDeclaration::IsReference(bool flag)
{
	this->isFunctionParam = flag;
}

void MultivariableDeclaration::LastName(string&& name)
{
	lastVar->SetName(name);
}

const std::string& MultivariableDeclaration::LastName()
{
	return lastVar->Name();
}

int MultivariableDeclaration::Dimension()
{
	return this->lastVar->GetDim();
}

std::string MultivariableDeclaration::GetSizeAt(unsigned int dim)
{
	return this->lastVar->GetDimSize(dim);
}

void MultivariableDeclaration::AppendSize(string&& size)
{
	this->lastVar->AddDimSize(size);
}

void MultivariableDeclaration::Set1DInitList(bool value)
{
	this->lastVar->Is1DInitList(value);
}

void MultivariableDeclaration::SetInitValue(string init_lst)
{
	lastVar->SetInitValue(init_lst);
}

ModifierType MultivariableDeclaration::Modifier()
{
	return this->modifier;
}

void MultivariableDeclaration::Modifier(ModifierType mod)
{
	modifier = mod;
}

void MultivariableDeclaration::Type(string && type)
{
	Type(type);
}

void MultivariableDeclaration::Type(string & type)
{
	this->type = string(type);
}

VariableDeclaration * MultivariableDeclaration::NextDeclaration()
{
	this->lastVar = new VariableDeclaration();
	this->variables.push(lastVar);
	return this->lastVar;
}

VariableDeclaration * MultivariableDeclaration::GetDeclaration()
{
	if (this->variables.size() > 0)
	{
		VariableDeclaration* item = this->variables.front();
		this->variables.pop();
		return item;
	}
	else return nullptr;
}
