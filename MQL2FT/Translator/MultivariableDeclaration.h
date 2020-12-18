#include <string>
#include <queue>
#include "VariableDeclaration.h"

#pragma once

enum ModifierType {
	M_NONE,
	M_FUNC_ARG,
	M_STATIC,
	M_EXTERN,
	M_INPUT
};

class MultivariableDeclaration
{
private:
	VariableDeclaration* lastVar;
	ModifierType modifier = M_NONE;
	bool isConst = false;
	std::string type;
	std::queue<VariableDeclaration*> variables;
	bool isFunctionParam;
public:

	MultivariableDeclaration();
	~MultivariableDeclaration();

	ModifierType Modifier();
	void Modifier(ModifierType mod);

	void Type(string&& type);
	void Type(string& type);
	const string& Type();

	bool IsConst();
	void IsConst(bool is_const);

	bool IsReference();
	void IsReference(bool flag);

	void LastName(string&& name);
	const std::string& LastName();

	void SetInitValue(string init_lst);
	int Dimension();
	std::string GetSizeAt(unsigned int dim);
	void AppendSize(string&& size);
	void Set1DInitList(bool value);

	VariableDeclaration* NextDeclaration();
	VariableDeclaration* GetDeclaration();

};

