#include "pch.h"

#include "GlobalVariablesStore.h"



GlobalVariablesStore::GlobalVariablesStore()
{
	memset(m_variable_name, '\0', sizeof(m_variable_name));
	m_variable_value = 0.0;
	m_unix_time = 0L;

	m_p_name = reinterpret_cast<char*>(&m_variable_name);
	m_p_value = reinterpret_cast<char*>(&m_variable_value);
	m_p_unix_time = reinterpret_cast<char*>(&m_unix_time);
	 
	m_value_size = sizeof(m_variable_value);
	m_name_size = sizeof(m_variable_name);
	m_time_size = sizeof(m_unix_time);

	std::string path_to_file = createGlobalVariableFile();

	m_stream_for_write.open(path_to_file, std::ios_base::in | std::ofstream::binary);
	
	m_stream_for_read.open(path_to_file, std::ofstream::binary);
}


GlobalVariablesStore::~GlobalVariablesStore()
{
	m_stream_for_read.close();
	m_stream_for_write.close();
}


double GlobalVariablesStore::getVariable(const std::string& variable_name)
{
	serialize();

	auto lambda = [&](const GlobalVariable& global_variable)
	{
		return global_variable.m_name == variable_name;
	};

	auto global_variable1 = std::find_if(m_variables_in_file.cbegin(), m_variables_in_file.cend(), lambda);

	if (global_variable1 != m_variables_in_file.cend()) {
		return global_variable1->m_value;
	}
	else {
		return 0.0;
	}
}


long GlobalVariablesStore::setVariable(const std::string& variable_name, const double variable_value)
{
	long result = 0L;

	const size_t lenght = variable_name.length();
	if (lenght == 0 || lenght > 63)
	{
		return result;
	}

	serialize();

	auto lambda = [&](const GlobalVariable& global_variable)
	{
		return global_variable.m_name == variable_name;
	};

	auto global_variable1 = std::find_if(m_variables_in_file.cbegin(), m_variables_in_file.cend(), lambda);

	if (global_variable1 != m_variables_in_file.cend()) {

		m_stream_for_write.clear();
		m_stream_for_write.seekp(0);

		size_t index = std::distance(m_variables_in_file.cbegin(), global_variable1);
		size_t filePos = index * (m_name_size + m_value_size + m_time_size);
		filePos += m_name_size;
		
		m_variable_value = variable_value;
		m_stream_for_write.seekp(filePos, m_stream_for_write.beg);
		m_stream_for_write.write(m_p_value, m_value_size);

		auto current_time_point = std::chrono::system_clock::now();
		std::time_t tm = std::chrono::system_clock::to_time_t(current_time_point);
		m_unix_time = (long)tm;
		m_stream_for_write.write(m_p_unix_time, m_time_size);

		m_stream_for_write.flush();

		result = m_unix_time;
	}
	else {
		m_stream_for_write.clear();
		m_stream_for_write.seekp(0, m_stream_for_write.end);

		memset(m_variable_name, '\0', m_name_size);
		variable_name.copy(m_variable_name, variable_name.length()+1);
		m_stream_for_write.write(m_p_name, m_name_size);

		m_variable_value = variable_value;
		m_stream_for_write.write(m_p_value, m_value_size);

		auto current_time_point = std::chrono::system_clock::now();
		std::time_t tm = std::chrono::system_clock::to_time_t(current_time_point);
		m_unix_time = (long)tm;
		m_stream_for_write.write(m_p_unix_time, m_time_size);

		m_stream_for_write.flush();

		result = m_unix_time;
	}

	return result;
}


bool GlobalVariablesStore::checkVariable(const std::string& variable_name)
{
	serialize();

	auto lambda = [&](const GlobalVariable& global_variable)
	{
		return global_variable.m_name == variable_name;
	};

	auto global_variable1 = std::find_if(m_variables_in_file.cbegin(), m_variables_in_file.cend(), lambda);

	if (global_variable1 != m_variables_in_file.cend()) {
		return true;
	}
	else {
		return false;
	}
}


bool GlobalVariablesStore::delVariable(const std::string& variable_name)
{
	serialize();

	auto lambda = [&](const GlobalVariable& global_variable)
	{
		return global_variable.m_name == variable_name;
	};

	auto global_variable1 = std::find_if(m_variables_in_file.cbegin(), m_variables_in_file.cend(), lambda);

	if (global_variable1 != m_variables_in_file.cend()) {

		m_stream_for_write.clear();
		m_stream_for_write.seekp(0);

		size_t index = std::distance(m_variables_in_file.cbegin(), global_variable1);
		size_t filePos = index * (m_name_size + m_value_size + m_time_size);

		m_stream_for_write.seekp(filePos, m_stream_for_write.beg);

		memset(m_variable_name, ' ', m_name_size);
		m_stream_for_write.write(m_p_name, m_name_size);

		m_variable_value = 0.0;
		m_stream_for_write.write(m_p_value, m_value_size);
	
		m_unix_time = 0L;
		m_stream_for_write.write(m_p_unix_time, m_time_size);

		m_stream_for_write.flush();

		return true;
	}
	else {
		return true;
	}
}

int GlobalVariablesStore::totalVars()
{
	return m_variables_in_file.size();
}

std::string GlobalVariablesStore::getVarName(int i)
{
	return m_variables_in_file[i].m_name;
}

void GlobalVariablesStore::serialize()
{
	m_variables_in_file.clear();
	
	if (m_stream_for_read.is_open())
	{
		m_stream_for_read.clear();
		m_stream_for_read.seekg(0);
		
		while (!m_stream_for_read.eof())
		{
			memset(m_variable_name, '\0', m_name_size);
			m_stream_for_read.read(m_p_name, m_name_size);
			m_stream_for_read.read(m_p_value, m_value_size);
			m_stream_for_read.read(m_p_unix_time, m_time_size);
			m_variables_in_file.emplace_back(GlobalVariable(m_variable_name, m_variable_value, m_unix_time));
		}
	}
}

std::string GlobalVariablesStore::createGlobalVariableFile()
{
	char path_to_FT[MAX_PATH];
	GetModuleFileNameA(NULL, path_to_FT, MAX_PATH);

	std::string path{ path_to_FT };
	size_t last_slash = path.rfind("\\");
	path.erase(last_slash + 1);

	std::string file_name = "global_variables.txt";

	HANDLE hFile = CreateFileA((path + file_name).c_str(),
		FILE_READ_DATA | FILE_WRITE_DATA,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN,
		NULL);
	CloseHandle(hFile);
	return path + file_name;
}