#include "pch.h"

#include "datetime.h"
#include "FTCore.h"

using namespace std;

const unsigned long day_seconds = 24 * 60 * 60;
const double unix_start_date = 25569.0; // Days from 30 dec 1899 to 01.01.1970 including leap years

time_t tmToUnixTime(const tm& tm);
bool isLeapYear(int y);

datetime::datetime()
{
	_seconds = 0;
	_systime = SYSTEMTIME();
	_variant_is_defined = false;
	_variant_time = 0.0;
	_variant_time = ToDelphiTime();
}

datetime::datetime(time_t a)
{
	_variant_time = 0.0;
	_variant_is_defined = false;

	_seconds = a;
	
	if(a >= 0)
	{
		tm* _time = gmtime(&this->_seconds);
		ToLPSysTime(_time, _systime);
		wDayOfYear = static_cast<unsigned short>(_time->tm_yday);
		_variant_time = ToDelphiTime();
	}
}

datetime::datetime(int hour, int min)
{
	_variant_time = 0.0;
	_variant_is_defined = false;
	
	this->_seconds = time(NULL); 
	tm* _time = gmtime(&_seconds);
	_time->tm_hour = hour;
	_time->tm_min = min;
	_time->tm_sec = 0;

	ToLPSysTime(_time, this->_systime);
	this->wDayOfYear = static_cast<unsigned short>(_time->tm_wday);

	this->_seconds = tmToUnixTime(*_time);

	_variant_time = ToDelphiTime();
}

datetime::datetime(int year, int month, int day)
{
	_variant_time = 0.0;
	_variant_is_defined = false;
	
	//tm* time = new tm();
	//LPSYSTEMTIME lpst = new SYSTEMTIME();
	FILETIME ft;
	this->_systime.wYear = year;
	this->_systime.wMonth = month;
	this->_systime.wDay = day;
	this->_systime.wHour = 0;
	this->_systime.wMinute = 0;
	this->_systime.wSecond = 0;
	this->_systime.wMilliseconds = 0;

	::SystemTimeToFileTime(&_systime, &ft);
	::FileTimeToSystemTime(&ft, &_systime);
	this->initialize(this->_systime);

	_variant_time = ToDelphiTime();
}

datetime::datetime(int year, int month, int day, int hour, int min, int sec)
{
	_variant_time = 0.0;
	_variant_is_defined = false;
	
	//LPSYSTEMTIME lpst = new SYSTEMTIME();
	FILETIME ft;
	this->_systime.wYear = year;
	this->_systime.wMonth = month;
	this->_systime.wDay = day;
	this->_systime.wHour = hour;
	this->_systime.wMinute = min;
	this->_systime.wSecond = sec;
	this->_systime.wMilliseconds = 0;

	::SystemTimeToFileTime(&_systime, &ft);
	::FileTimeToSystemTime(&ft, &_systime);
	this->initialize(this->_systime);

	_variant_time = ToDelphiTime();
}

void datetime::initialize(SYSTEMTIME& dt)
{
	this->_systime = dt;
	tm _time;
	this->ToTm(this->_systime, &_time);
	this->_seconds = tmToUnixTime(_time);
}

datetime datetime::FromVariantTime(double variant)
{
	datetime dt;
	time_t seconds = (unsigned long)round((variant - unix_start_date) * (double)day_seconds);

	dt._seconds = seconds;
	tm * _time = gmtime(&dt._seconds);
	
	dt.ToLPSysTime(_time, dt._systime);

	dt.wDayOfYear = static_cast<unsigned short>(_time->tm_yday);

	dt._variant_time = variant;
	dt._variant_is_defined = true;

	return dt;
}

datetime datetime::None()
{
	datetime none;
	none._seconds = 0;
	return none;
}

int datetime::Seconds() const
{
	return this->_systime.wSecond;
}

int datetime::Minutes() const
{
	return this->_systime.wMinute;
}

int datetime::Hours() const
{
	return this->_systime.wHour;
}

int datetime::DayOfMonth() const
{
	return this->_systime.wDay;
}

int datetime::Month() const
{
	return this->_systime.wMonth;
}

int datetime::Year() const
{
	return this->_systime.wYear;
}

int datetime::DayOfWeek() const
{
	return this->_systime.wDayOfWeek;
}

int datetime::DayOfYear() const
{
	return this->wDayOfYear;
}

time_t datetime::TotalSeconds() const
{
	return this->_seconds;
}

string datetime::ToString(TimeOutputMode mode) const
{
	if(_seconds < 0 /*|| _seconds > 32535244799*/) // 3001.01.01 07:59:59
	{
		return "";
	}

	stringstream ss;
	bool put_date = (mode & TIME_DATE) != 0;
	bool put_minutes = (mode & TIME_MINUTES) != 0;
	bool put_seconds = (mode & TIME_SECONDS) != 0;

	if(put_date)
	{
		ss << setfill('0') << setw(2) << this->Year() << '.'
			<< setfill('0') << setw(2) << this->Month() << "."
			<< setfill('0') << setw(2) << this->DayOfMonth()
			;
	}
	if(put_seconds)
	{
		if (put_date) ss << ' ';

		ss  << setfill('0') << setw(2) << this->Hours() << ':'
			<< setfill('0') << setw(2) << this->Minutes() << ':'
			<< setfill('0') << setw(2) << this->Seconds()
			;
	}
	else if(put_minutes)
	{
		if(put_date) ss << ' ';

		ss << setfill('0') << setw(2) << this->Hours() << ':'
			<< setfill('0') << setw(2) << this->Minutes()
			;
	}

	return ss.str();
}

datetime& datetime::operator+=(const datetime& other)
{
	_seconds += other._seconds;
	return *this;
}

datetime& datetime::operator-=(const datetime& other)
{
	_seconds -= other._seconds;
	return *this;
}

datetime& datetime::operator+=(const ExternDatetime& other)
{
	_seconds += (time_t)other;
	return *this;
}

datetime& datetime::operator-=(const ExternDatetime& other)
{
	_seconds -= (time_t)other;
	return *this;
}

datetime& datetime::operator+=(int x)
{
	_seconds += (time_t)x;
	return *this;
}

datetime& datetime::operator-=(int x)
{
	_seconds -= (time_t)x;
	return *this;
}

datetime& datetime::operator++()
{
	++_seconds;
	return *this;
}

datetime datetime::operator++(int)
{
	datetime tmp(*this);
	operator++();
	return tmp;
}

double datetime::ToDelphiTime() const
{	
	double variant = _variant_is_defined ?
		this->_variant_time :
		(double)(this->_seconds)/(double)day_seconds + unix_start_date;

	return variant;
}

datetime::operator time_t() const
{
	return _seconds;
}

bool datetime::ToTm(SYSTEMTIME& time, tm * target)
{
	if (target != nullptr) 
	{
		target->tm_hour = time.wHour;
		target->tm_min = time.wMinute;
		target->tm_sec = time.wSecond;
		target->tm_year = time.wYear - 1900;
		target->tm_mon = time.wMonth - 1;
		target->tm_mday = time.wDay;
		target->tm_wday = time.wDayOfWeek;

		return true;
	}

	return false;
}

void datetime::ToLPSysTime(tm * time, SYSTEMTIME & target)
{
	target.wHour = static_cast<unsigned short>(time->tm_hour);
	target.wMinute = static_cast<unsigned short>(time->tm_min);
	target.wSecond = static_cast<unsigned short>(time->tm_sec);
	target.wYear = static_cast<unsigned short>(time->tm_year + 1900);
	target.wMonth = static_cast<unsigned short>(time->tm_mon + 1);
	target.wDay = static_cast<unsigned short>(time->tm_mday);
	target.wDayOfWeek = static_cast<unsigned short>(time->tm_wday);
}

ostream& operator<<(std::ostream & os, const datetime& obj)
{
#ifndef MQL2FT_STRICT_MODE
	return os << std::to_string((time_t)obj);
#else
	if(obj._seconds < 0)
	{
		os << "";
	}
	else {
		os << setfill('0') << setw(2) << obj.DayOfMonth()
			<< '.'
			<< setfill('0') << setw(2) << obj.Month()
			<< '.'
			<< setfill('0') << setw(4) << obj.Year()
			<< " "
			<< setfill('0') << setw(2) << obj.Hours()
			<< ':'
			<< setfill('0') << setw(2) << obj.Minutes()
			<< ':'
			<< setfill('0') << setw(2) << obj.Seconds();
	}
	return os;
#endif
}

// ExternDatetime
ExternDatetime::ExternDatetime(const datetime& dt) : datetime(dt)
{
	_past_variant_time = _variant_time;
}

void ExternDatetime::CheckTime() const
{
	if(_variant_time == _past_variant_time)
	{
		return;
	}

	_past_variant_time = _variant_time;

	time_t seconds = (unsigned long)round((_variant_time - unix_start_date) * (double)day_seconds);

	_seconds = seconds;
	tm * _time = gmtime(&_seconds);

	ToLPSysTime(_time, _systime);

	wDayOfYear = static_cast<unsigned short>(_time->tm_yday);
	_variant_is_defined = true;
}

std::ostream& operator<<(std::ostream& os, const ExternDatetime& obj)
{
	obj.CheckTime();
	os << (datetime)obj;
	return os;
}

datetime ExternDatetime::operator+(const ExternDatetime& other)
{
	CheckTime();
	other.CheckTime();
	time_t res = _seconds + other._seconds;
	return datetime(res);
}

datetime ExternDatetime::operator-(const ExternDatetime& other)
{
	CheckTime();
	other.CheckTime();
	time_t res = _seconds - other._seconds;
	return datetime(res);
}

datetime& ExternDatetime::operator+=(const ExternDatetime& other)
{
	CheckTime();
	other.CheckTime();
	_seconds += other._seconds;
	return *this;
}

datetime& ExternDatetime::operator-=(const ExternDatetime& other)
{
	CheckTime();
	other.CheckTime();
	_seconds -= other._seconds;
	return *this;
}

datetime& ExternDatetime::operator+=(const datetime& other)
{
	CheckTime();
	_seconds += (time_t)other;
	return *this;
}

datetime& ExternDatetime::operator-=(const datetime& other)
{
	CheckTime();
	_seconds -= (time_t)other;
	return *this;
}

ExternDatetime& ExternDatetime::operator++()
{
	CheckTime();
	++_seconds;
	return *this;
}

datetime ExternDatetime::operator++(int)
{
	datetime tmp(*this);
	operator++();
	return tmp;
}

// Arithmetic operators
datetime operator+(const datetime& lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(const datetime& lhs, int rhs)
{
	time_t res = (time_t)lhs + rhs;
	return datetime(res);
}

datetime operator+(int lhs, const datetime& rhs)
{
	time_t res = lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(const datetime& lhs, double rhs)
{
	time_t res = (time_t)lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(double lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(const datetime& lhs, time_t rhs)
{
	time_t res = (time_t)lhs + rhs;
	return datetime(res);
}

datetime operator+(time_t lhs, const datetime& rhs)
{
	time_t res = lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(const datetime& lhs, ulong rhs)
{
	time_t res = (time_t)lhs + rhs;
	return datetime(res);
}

datetime operator+(ulong lhs, const datetime& rhs)
{
	time_t res = lhs + (time_t)rhs;
	return datetime(res);
}


datetime operator-(const datetime& lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(const datetime& lhs, int rhs)
{
	time_t res = (time_t)lhs - rhs;
	return datetime(res);
}

datetime operator-(int lhs, const datetime& rhs)
{
	time_t res = lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(const datetime& lhs, double rhs)
{
	time_t res = (time_t)lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(double lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(const datetime& lhs, time_t rhs)
{
	time_t res = (time_t)lhs - rhs;
	return datetime(res);
}

datetime operator-(time_t lhs, const datetime& rhs)
{
	time_t res = lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(const datetime& lhs, ulong rhs)
{
	time_t res = (time_t)lhs - rhs;
	return datetime(res);
}

datetime operator-(ulong lhs, const datetime& rhs)
{
	time_t res = lhs - (time_t)rhs;
	return datetime(res);
}

// Extern datetime
datetime operator+(const ExternDatetime& lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator+(const datetime& lhs, const ExternDatetime& rhs)
{
	time_t res = (time_t)lhs + (time_t)rhs;
	return datetime(res);
}

datetime operator-(const ExternDatetime& lhs, const datetime& rhs)
{
	time_t res = (time_t)lhs - (time_t)rhs;
	return datetime(res);
}

datetime operator-(const datetime& lhs, const ExternDatetime& rhs)
{
	time_t res = (time_t)lhs - (time_t)rhs;
	return datetime(res);
}

// Helper functions
time_t tmToUnixTime(const tm& tm)
{
	/*
		int tm_sec;   // seconds after the minute - [0, 60] including leap second
		int tm_min;   // minutes after the hour - [0, 59]
		int tm_hour;  // hours since midnight - [0, 23]
		int tm_mday;  // day of the month - [1, 31]
		int tm_mon;   // months since January - [0, 11]
		int tm_year;  // years since 1900
		int tm_wday;  // days since Sunday - [0, 6]
		int tm_yday;  // days since January 1 - [0, 365]
		int tm_isdst; // daylight savings time flag
	*/

	const int y = tm.tm_year + 1900;

	int tot_days = 0;
	for(int i = 1970; i < y; ++i)
	{
		int days = isLeapYear(i) ? 366 : 365;
		tot_days += days;
	}

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if(isLeapYear(y))
	{
		days[1] = 29;
	}

	for(int i = 0; i < tm.tm_mon; ++i)
	{
		tot_days += days[i];
	}

	tot_days += tm.tm_mday - 1;

	int tot_hrs = tot_days * 24 + tm.tm_hour;
	int tot_mins = tot_hrs * 60 + tm.tm_min;
	int tot_sec = tot_mins * 60 + tm.tm_sec;

	return (time_t)tot_sec;
}

bool isLeapYear(int y)
{
	if(y % 4)
	{
		return false;
	}
	else if(y % 100)
	{
		return true;
	}
	else if(y % 400)
	{
		return false;
	}
	else
	{
		return true;
	}
}