#pragma once


class GlobalVariable
{
public:
	GlobalVariable(const std::string variable_name, const double variable_value, const long unix_time);
	~GlobalVariable();

public:
	std::string m_name;
	double m_value;
	long m_unix_time;
};

