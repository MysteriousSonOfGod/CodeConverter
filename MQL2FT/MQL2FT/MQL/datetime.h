#pragma once

#include "Enums.h"

typedef unsigned long long ulong;

struct MqlNull;

class ExternDatetime;

class datetime
{
public:
	datetime();
	datetime(time_t a);
	datetime(int hour, int min);
	datetime(int year, int month, int day);
	datetime(int year, int month, int day, int hour, int min, int sec = 0);

	virtual ~datetime() = default;

	static datetime FromVariantTime(double variant);
	static datetime None();

	virtual int Seconds() const;
	virtual int Minutes() const;
	virtual int Hours() const;

	virtual int DayOfMonth() const;
	virtual int Month() const;
	virtual int Year() const;

	virtual int DayOfWeek() const;
	virtual int DayOfYear() const;

	virtual time_t TotalSeconds() const;

	virtual std::string ToString(TimeOutputMode mode) const;
	virtual double ToDelphiTime() const;
	
	// Friend functions
	friend std::ostream& operator<<(std::ostream& os, const datetime& obj);
	
	// Operators
	datetime& operator+=(const datetime& other);
	datetime& operator-=(const datetime& other);
	datetime& operator+=(const ExternDatetime& other);
	datetime& operator-=(const ExternDatetime& other);
	datetime& operator+=(int x);
	datetime& operator-=(int x);

	datetime& operator++();
	datetime operator++(int);

	operator time_t() const;

protected:
	void initialize(SYSTEMTIME& dt);

	static bool ToTm(SYSTEMTIME& time, tm * target);
	static void ToLPSysTime(tm* time, SYSTEMTIME& target);

	// Data
	mutable time_t _seconds;
	mutable SYSTEMTIME _systime;
	mutable double _variant_time;
	mutable bool _variant_is_defined;
	mutable WORD wDayOfYear;
};

class ExternDatetime : public datetime
{
public:
	ExternDatetime() : datetime() { CheckTime(); }
	ExternDatetime(time_t a) : datetime(a) { CheckTime(); }
	ExternDatetime(int hour, int min) : datetime(hour, min) { CheckTime(); }
	ExternDatetime(int year, int month, int day) : datetime(year, month, day) { CheckTime(); }
	ExternDatetime(int year, int month, int day, int hour, int min, int sec = 0)
	: datetime(year, month, day, hour, min, sec) { CheckTime(); }
	ExternDatetime(const datetime& dt);

	//ExternDatetime& operator=(const datetime& dt);

	int Seconds() const { CheckTime(); return datetime::Seconds(); }
	int Minutes() const { CheckTime(); return datetime::Minutes(); }
	int Hours() const { CheckTime(); return datetime::Hours(); }

	int DayOfMonth() const { CheckTime(); return datetime::DayOfMonth(); }
	int Month() const { CheckTime(); return datetime::Month(); }
	int Year() const { CheckTime(); return datetime::Year(); }

	int DayOfWeek() const { CheckTime(); return datetime::DayOfWeek(); }
	int DayOfYear() const { CheckTime(); return datetime::DayOfYear(); }

	time_t TotalSeconds() const { CheckTime(); return datetime::TotalSeconds(); }

	std::string ToString(TimeOutputMode mode) const { CheckTime(); return datetime::ToString(mode); }

	double ToDelphiTime() const { CheckTime(); return datetime::ToDelphiTime(); }

	void CheckTime() const;

	// Operators
	datetime operator+(const ExternDatetime& other);
	datetime operator-(const ExternDatetime& other);
	datetime& operator+=(const ExternDatetime& other);
	datetime& operator-=(const ExternDatetime& other);
	datetime& operator+=(const datetime& other);
	datetime& operator-=(const datetime& other);

	ExternDatetime& operator++();
	datetime operator++(int);

	double* operator&();

	operator time_t() const { CheckTime(); return _seconds; }

	// Friend functions
	friend std::ostream& operator<<(std::ostream& os, const ExternDatetime& obj);

private:
	mutable double _past_variant_time = 0.0;
};

// Relational operators
inline bool operator<(const datetime& lhs, const datetime& rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(const datetime& lhs, const datetime& rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(const datetime& lhs, const datetime& rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(const datetime& lhs, const datetime& rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(const datetime& lhs, const datetime& rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(const datetime& lhs, const datetime& rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(const datetime& lhs, int rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(const datetime& lhs, int rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(const datetime& lhs, int rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(const datetime& lhs, int rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(const datetime& lhs, int rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(const datetime& lhs, int rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(int lhs, const datetime& rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(int lhs, const datetime& rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(int lhs, const datetime& rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(int lhs, const datetime& rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(int lhs, const datetime& rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(int lhs, const datetime& rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(const datetime& lhs, long long rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(const datetime& lhs, long long rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(const datetime& lhs, long long rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(const datetime& lhs, long long rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(const datetime& lhs, long long rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(const datetime& lhs, long long rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(long long lhs, const datetime& rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(long long lhs, const datetime& rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(long long lhs, const datetime& rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(long long lhs, const datetime& rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(long long lhs, const datetime& rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(long long lhs, const datetime& rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(const datetime& lhs, double rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(const datetime& lhs, double rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(const datetime& lhs, double rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(const datetime& lhs, double rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(const datetime& lhs, double rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(const datetime& lhs, double rhs) { return !((time_t)lhs == (time_t)rhs); }

inline bool operator<(double lhs, const datetime& rhs) { return (time_t)lhs < (time_t)rhs; }
inline bool operator>(double lhs, const datetime& rhs) { return (time_t)rhs < (time_t)lhs; }
inline bool operator<=(double lhs, const datetime& rhs) { return !((time_t)lhs >(time_t)rhs); }
inline bool operator>=(double lhs, const datetime& rhs) { return !((time_t)lhs < (time_t)rhs); }
inline bool operator==(double lhs, const datetime& rhs) { return (time_t)lhs == (time_t)rhs; }
inline bool operator!=(double lhs, const datetime& rhs) { return !((time_t)lhs == (time_t)rhs); }

// Arithmetic operators
datetime operator+(const datetime& lhs, const datetime& rhs);
datetime operator+(const datetime& lhs, int rhs);
datetime operator+(int lhs, const datetime& rhs);
datetime operator+(const datetime& lhs, double rhs);
datetime operator+(double lhs, const datetime& rhs);
datetime operator+(const datetime& lhs, time_t rhs);
datetime operator+(time_t lhs, const datetime& rhs);
datetime operator+(const datetime& lhs, ulong rhs);
datetime operator+(ulong lhs, const datetime& rhs);
datetime operator-(const datetime& lhs, const datetime& rhs);
datetime operator-(const datetime& lhs, int rhs);
datetime operator-(int lhs, const datetime& rhs);
datetime operator-(const datetime& lhs, double rhs);
datetime operator-(double lhs, const datetime& rhs);
datetime operator-(const datetime& lhs, time_t rhs);
datetime operator-(time_t lhs, const datetime& rhs);
datetime operator-(const datetime& lhs, ulong rhs);
datetime operator-(ulong lhs, const datetime& rhs);

// Extern datetime
datetime operator+(const ExternDatetime& lhs, const datetime& rhs);
datetime operator+(const datetime& lhs, const ExternDatetime& rhs);

inline double* ExternDatetime::operator&() { return &_variant_time; }