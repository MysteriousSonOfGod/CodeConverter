#include "stdafx.h"
#include "RegexData.h"


RegexData::RegexData(const string& exp, const string& func, const string& form)
{
	char buff[100];
	sprintf_s(buff, 100, exp.c_str(), func.c_str());
	(this)->reg_expr = new string(buff);

	char buff2[100]; 
	sprintf_s(buff2, 100, form.c_str(), func.c_str());
	this->format = new string(buff2);
	this->re = new regex(*this->reg_expr);
}

RegexData::~RegexData()
{
}

regex * RegexData::GetRegex()
{
	return this->re;
}

string * RegexData::GetFormat()
{
	return this->format;
}
