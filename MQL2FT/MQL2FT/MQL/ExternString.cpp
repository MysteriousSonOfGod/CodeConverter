#include "pch.h"

#include "ExternString.h"

// Constructors
ExternString::ExternString(const ExternString& other)
{
	if(&other != this)
	{
		free((void*)m_cstr);
		Init(other);
	}
}

ExternString::ExternString(const mql4::string& mqlstr)
{
	Init(mqlstr);
}

ExternString::ExternString(double d) { Init(mql4::string(d)); }
ExternString::ExternString(float f) { Init(mql4::string(f)); }

ExternString::ExternString(char c) { Init(mql4::string(c)); }
ExternString::ExternString(short s) { Init(mql4::string(s)); }
ExternString::ExternString(int i) { Init(mql4::string(i)); }
ExternString::ExternString(long long ll) { Init(mql4::string(ll)); }

ExternString::ExternString(unsigned char uc) { Init(mql4::string(uc)); }
ExternString::ExternString(unsigned short us) { Init(mql4::string(us)); }
ExternString::ExternString(unsigned int ui) { Init(mql4::string(ui)); }
ExternString::ExternString(unsigned long long ull) { Init(mql4::string(ull)); }

ExternString::ExternString(bool b) { Init(mql4::string(b)); }

ExternString::ExternString(const color& col) { Init(mql4::string(col)); }
ExternString::ExternString(const datetime& dt) { Init(mql4::string(dt)); }

// Operators
ExternString& ExternString::operator=(const ExternString& other)
{
	free((void*)m_cstr);
	Init(mql4::string(other.m_cstr));
	return *this;
}

ExternString& ExternString::operator=(const mql4::string& other)
{
	free((void*)m_cstr);
	Init(other);
	return *this;
}

char& ExternString::operator[](size_t pos)
{
	return m_cstr[pos];
}

const char& ExternString::operator[](size_t pos) const
{
	return m_cstr[pos];
}

ExternString& ExternString::operator+=(const ExternString& other)
{
	mql4::string tmp(m_cstr);
	tmp += mql4::string(other.m_cstr);
	Init(tmp);
	return *this;
}

ExternString ExternString::operator+(const ExternString& other) const
{
	return mql4::string(m_cstr) + mql4::string(other.m_cstr);
}

// Private functions
void ExternString::Init(const mql4::string& mqlstr)
{
	const int s = mqlstr.size() + 1;
	m_cstr = (char*)malloc(s);
	memcpy(m_cstr, mqlstr.c_str(), s);
}