#pragma once

#include <string>
#include <ostream>
#include "datetime.h"
#include "color.h"
#include "Array.h"

namespace mql4
{
	class string
	{
	public:
		// Constructors
		string() = default;
		string(string&&) = default;
		string(const string& other);
		string(const char* cstr);
		string(const std::string& cppstr);

		string(double d);
		string(float f);

		string(char c);
		string(short s);
		string(int i);
		string(long long ll);

		string(unsigned char uc);
		string(unsigned short us);
		string(unsigned int ui);
		string(unsigned long long ull);

		string(bool b); // Depends on #strict

		string(const color& col);
		string(const datetime& dt); // Direct cast to num. of seconds

		// Operators
		string& operator=(const string&) = default;
		string& operator=(string&&) = default;
		char& operator[](size_t pos);
		const char& operator[](size_t pos) const;
		string& operator+=(const string& other);
		string operator+(const string& other) const;
		friend bool operator==(const string& lhs, const string& rhs);
		friend bool operator<(const string& lhs, const string& rhs);

		// Type casts
		operator std::string() const;
		explicit operator long long() const;
		explicit operator unsigned long long() const;
		explicit operator int() const;
		explicit operator unsigned int() const;
		explicit operator short() const;
		explicit operator unsigned short() const;
		explicit operator char() const;
		explicit operator unsigned char() const;

		explicit operator double() const;
		explicit operator float() const;
		explicit operator bool() const;

		// Std string functions wrappers
		bool empty() const;
		size_t length() const;
		size_t size() const;
		const char* c_str() const;
		string& replace(size_t pos, size_t len, const string& str);
		size_t find(const string& str, size_t pos = 0) const;
		void push_back(char c);

	private:
		std::string str_;
	};

	inline string::operator int() const { return (int)operator long long(); }
	inline string::operator unsigned int() const { return (unsigned int)operator long long(); }
	inline string::operator short() const { return (short)operator long long(); }
	inline string::operator unsigned short() const { return (unsigned short)operator long long(); }
	inline string::operator char() const { return (char)operator long long(); }
	inline string::operator unsigned char() const { return (unsigned char)operator long long(); }

	inline bool string::empty() const { return str_.empty(); }

	inline size_t string::length() const { return str_.length(); }
	inline size_t string::size() const { return str_.size(); }
	inline const char* string::c_str() const { return str_.c_str(); }

	inline string& string::replace(size_t pos, size_t len, const string& str)
	{
		str_.replace(pos, len, str);
		return *this;
	}

	inline size_t string::find(const string& str, size_t pos) const { return str_.find(str, pos); }

	inline void string::push_back(char c) { str_.push_back(c); }
	
	// Operators

	inline string operator+(const char* lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(const std::string& lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(double lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(float lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(char lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(short lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(int lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(long long lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(unsigned char lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(unsigned short lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(unsigned int lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(unsigned long long lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(bool lhs, const string& rhs) { return string(lhs) + rhs; }
	inline string operator+(const datetime& lhs, const string& rhs) { return string(lhs) + rhs; }
#ifdef __INDICATOR
	inline string operator+(const string& lhs, const IndexBuffer::Item& rhs) { return lhs + (double)rhs; }
#endif

	inline bool operator==(const string& lhs, const string& rhs) { return lhs.str_ == rhs.str_; }
	inline bool operator==(const char*   lhs, const string& rhs) { return string(lhs) == rhs; }

	inline bool operator!=(const string& lhs, const string& rhs) { return !(lhs == rhs); }
	inline bool operator!=(const char*   lhs, const string& rhs) { return string(lhs) != rhs; }

	inline bool operator<(const string& lhs, const string& rhs) { return lhs.str_ < rhs.str_; }
	inline bool operator<(const char*   lhs, const string& rhs) { return string(lhs) < rhs; }

	inline bool operator>(const string& lhs, const string& rhs) { return rhs < lhs; }
	inline bool operator>(const char*   lhs, const string& rhs) { return string(lhs) > rhs; }

	inline bool operator<=(const string& lhs, const string& rhs) { return !(lhs > rhs); }
	inline bool operator<=(const char*   lhs, const string& rhs) { return string(lhs) <= rhs; }

	inline bool operator>=(const string& lhs, const string& rhs) { return !(lhs < rhs); }
	inline bool operator>=(const char*   lhs, const string& rhs) { return string(lhs) >= rhs; }

	inline std::ostream& operator<<(std::ostream& os, const string& str)
	{
		return os << (std::string)str;
	}
}