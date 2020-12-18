#pragma once

#include "GlobalVariable.h"

class GlobalVariablesStore
{
public:
	GlobalVariablesStore();
	~GlobalVariablesStore();

	double getVariable(const std::string& variable_name);
	long setVariable(const std::string& variable_name, const double variable_value);
	bool checkVariable(const std::string& variable_name);
	bool delVariable(const std::string& variable_name);

	int totalVars();
	std::string getVarName(int i);

private:
	double m_variable_value;
	char m_variable_name[63];
	long m_unix_time;

	char* m_p_name;
	char* m_p_value;
	char* m_p_unix_time;

	size_t m_value_size;
	size_t m_name_size;
	size_t m_time_size;

	std::ofstream m_stream_for_write;
	std::ifstream m_stream_for_read;

	std::vector<GlobalVariable> m_variables_in_file;

	void serialize();

	std::string createGlobalVariableFile();
};

