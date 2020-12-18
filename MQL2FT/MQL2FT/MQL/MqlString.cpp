#include "pch.h"

#include "MqlString.h"

namespace mql4
{

	// Helper functions
	std::string toStr(double d)
	{
		std::stringstream ss;
		ss.precision(14);
		ss << std::fixed << d;
		std::string s = ss.str();
		bool dot_found = false;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '.')
			{
				dot_found = true;
				if(s[i+1] == '0')
				{
					return s.substr(0, i);
				}
			}

			if(s[i] == '0' && dot_found)
			{
				return s.substr(0, i);
			}

		}

		return s;
	}

	// Constructors
	string::string(const string& other) : str_(other.str_) {}
	string::string(const char* cstr) : str_(cstr) {}
	string::string(const std::string& cppstr) : str_(cppstr) {}

	string::string(double d)
	{
		str_ = toStr(d);
	}
	string::string(float f)
	{
		str_ = toStr((double)f);
	}

	string::string(char c)
	{
		str_ = std::to_string((int)c);
	}
	string::string(short s)
	{
		str_ = std::to_string((int)s);
	}
	string::string(int i)
	{
		str_ = std::to_string(i);
	}
	string::string(long long ll)
	{
		str_ = std::to_string(ll);
	}

	string::string(unsigned char uc)
	{
		str_ = std::to_string((unsigned int)uc);
	}
	string::string(unsigned short us)
	{
		str_ = std::to_string((unsigned int)us);
	}
	string::string(unsigned int ui)
	{
		str_ = std::to_string(ui);
	}
	string::string(unsigned long long ull)
	{
		str_ = std::to_string(ull);
	}

	string::string(bool b) // Depends on #strict
	{
#ifdef MQL2FT_STRICT_MODE
		str_ = b ? "true" : "false";
#else
		str_ = b ? "1" : "0";
#endif
	}

	string::string(const color& col)
	{
		str_ = std::to_string((long)col);
	}
	string::string(const datetime& dt) // Direct cast to num. of seconds
	{
		str_ = std::to_string((time_t)dt);
	}

	// Operators
	char& string::operator[](size_t pos)
	{
		return str_[pos];
	}
	const char& string::operator[](size_t pos) const
	{
		return str_[pos];
	}
	string& string::operator+=(const string& other)
	{
		str_ += other.str_;
		return *this;
	}
	string string::operator+(const string& other) const
	{
		return string(str_ + other.str_);
	}

	// Type casts
	string::operator std::string() const
	{
		return str_;
	}

	string::operator long long() const
	{ 
		try
		{
			return std::stoll(str_);
		}
		catch(std::exception& ex)
		{
			return 0;
		}
	}

	string::operator unsigned long long() const
	{
		try
		{
			return std::stoull(str_);
		}
		catch(std::exception& ex)
		{
			return 0;
		}
	}

	string::operator double() const
	{
		try
		{
			return std::stod(str_);
		}
		catch(std::exception& ex)
		{
			return 0.0;
		}
	}

	string::operator float() const
	{
		try
		{
			return std::stof(str_);
		}
		catch(std::exception& ex)
		{
			return 0.0;
		}
	}

	string::operator bool() const
	{
		if(str_ == "true" || str_ == "TRUE")
		{
			return true;
		}

		if(operator long long() != 0)
		{
			return true;
		}

		if(operator double() != 0.0)
		{
			return true;
		}

		return false;
	}

}