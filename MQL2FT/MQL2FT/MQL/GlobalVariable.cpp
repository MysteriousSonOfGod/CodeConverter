#include "pch.h"

#include "GlobalVariable.h"



GlobalVariable::GlobalVariable(const std::string variable_name, const double variable_value, const long unix_time) :
	m_name{variable_name},m_value{variable_value},m_unix_time{unix_time}
{
	m_name.erase(std::remove_if(m_name.begin(), m_name.end(), isspace), m_name.end());
}


GlobalVariable::~GlobalVariable()
{
}
