#pragma once

#include <string>
#include "MqlString.h"
#include "datetime.h"

#undef NULL

#pragma warning( disable : 4716 )

struct MqlNull
{
	operator int() const;
	operator std::string() const;
	operator mql4::string() const;
	operator datetime() const;
} NULL;

inline MqlNull::operator int() const
{
	return 0;
}

inline MqlNull::operator datetime() const
{
	return datetime(0);
}

inline MqlNull::operator std::string() const
{
	return "";
}

inline MqlNull::operator mql4::string() const
{
	return "";
}

inline bool operator==(const MqlNull& lhs, const datetime& rhs) { return 0 == (time_t)rhs; }
inline bool operator!=(const MqlNull& lhs, const datetime& rhs) { return !(lhs == rhs); }
inline bool operator==(const datetime& lhs, const MqlNull& rhs) { return 0 == (time_t)lhs; }
inline bool operator!=(const datetime& lhs, const MqlNull& rhs) { return !(lhs == rhs); }
inline bool operator==(const MqlNull& lhs, const ExternDatetime& rhs) { return 0 == (time_t)rhs; }
inline bool operator!=(const MqlNull& lhs, const ExternDatetime& rhs) { return !(lhs == rhs); }
inline bool operator==(const ExternDatetime& lhs, const MqlNull& rhs) { return 0 == (time_t)lhs; }
inline bool operator!=(const ExternDatetime& lhs, const MqlNull& rhs) { return !(lhs == rhs); }

template<typename T>
bool operator==(const MqlNull& lhs, const T& rhs) { return (T)0 == rhs; }

template<typename T>
inline bool operator!=(const MqlNull& lhs, const T& rhs) { return !(lhs == rhs); }

template<typename T>
inline bool operator==(const T& lhs, const MqlNull& rhs) { return (T)0 == lhs; }

template<typename T>
inline bool operator!=(const T& lhs, const MqlNull& rhs) { return !(lhs == rhs); }