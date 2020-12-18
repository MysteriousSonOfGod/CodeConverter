#pragma once

#include "MqlString.h"

class ExternString
{
public:
	// Constructors
	ExternString();
	ExternString(const ExternString& other);
	ExternString(const mql4::string& mqlstr);

	ExternString(double d);
	ExternString(float f);

	ExternString(char c);
	ExternString(short s);
	ExternString(int i);
	ExternString(long l);
	ExternString(long long ll);

	ExternString(unsigned char uc);
	ExternString(unsigned short us);
	ExternString(unsigned int ui);
	ExternString(unsigned long ul);
	ExternString(unsigned long long ull);

	ExternString(bool b);

	ExternString(const color& col);
	ExternString(const datetime& dt);
	// Operators
	char** operator&();
	ExternString& operator=(const ExternString& other);
	ExternString& operator=(const mql4::string& other);
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;
	ExternString& operator+=(const ExternString& other);
	ExternString operator+(const ExternString& other) const;
	//friend bool operator==(const ExternString& lhs, const ExternString& rhs);
	//friend bool operator<(const ExternString& lhs, const ExternString& rhs);
	
	// Type casts
	operator mql4::string() const;
	
private:
	void Init(const mql4::string& mqlstr);

	// Data
	char* m_cstr;
};

inline ExternString::ExternString() { m_cstr = nullptr; }

inline char** ExternString::operator&() { return &m_cstr; }

inline ExternString::operator mql4::string() const { return mql4::string(m_cstr); }

inline std::ostream& operator<<(std::ostream& os, const ExternString& str)
{
	return os << (mql4::string)str;
}