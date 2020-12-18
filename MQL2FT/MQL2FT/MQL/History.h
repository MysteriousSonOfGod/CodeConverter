#pragma once

#include "Enums.h"
#include "MqlEnums.h"

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#endif

#ifdef __STRATEGY
#include "StrategyInterfaceUnit.h"
#endif



class History
{
public:
	History();
	History(const std::string& symbol, int timeframe, ENUM_APPLIED_PRICE applied_price = PRICE_CLOSE);
	History(const std::vector<double>* const history_vector);
	~History();

	void Setup(const std::string& symbol, int timeframe, ENUM_APPLIED_PRICE applied_price = PRICE_CLOSE);

	const std::string& Symbol() const;
	int Timeframe() const;
	int PriceType() const;

	int Bars() const;
	double AppliedPrice(int i) const;
	double Open(int i) const;
	double High(int i) const;
	double Low(int i) const;
	double Close(int i) const;
	double Median(int i) const;
	double Typical(int i) const;
	double Weighted(int i) const;
	long Volume(int i)const;
private:
	std::string m_symbol;
	char* m_symbol_c_str;
	int m_timeframe;
	ENUM_APPLIED_PRICE m_applied_price;
	const std::vector<double>* const m_history_vector;

	int(History::*pBars)() const;
	double(History::*pAppliedPrice)(int i) const;
	double(History::*pOpen)(int i) const;
	double(History::*pHigh)(int i) const;
	double(History::*pLow)(int i) const;
	double(History::*pClose)(int i) const;
	double(History::*pMedian)(int i) const;
	double(History::*pTypical)(int i) const;
	double(History::*pWeighted)(int i) const;
	long(History::*pVolume)(int i) const;

	// functions returning values for current chart
	int f_Bars() const;
	double f_Open(int i) const;
	double f_High(int i) const;
	double f_Low(int i) const;
	double f_Close(int i) const;
	double f_Median(int i) const;
	double f_Typical(int i) const;
	double f_Weighted(int i) const;
	long f_Volume(int i) const;

	// functions returning values for other than currnet chart symbol and timeframe
	int f_iBars() const;
	double f_iOpen(int i) const;
	double f_iHigh(int i) const;
	double f_iLow(int i) const;
	double f_iClose(int i) const;
	double f_iMedian(int i) const;
	double f_iTypical(int i) const;
	double f_iWeighted(int i) const;
	long f_iVolume(int i) const;

	// functions returning values from a vector
	int f_hBars() const;
	double f_hPrice(int i) const;
	long f_hVolume(int i) const { return 0L; }
};

inline const std::string& History::Symbol() const
{
	return m_symbol;
}

inline int History::Timeframe() const
{
	return m_timeframe;
}

inline int History::PriceType() const
{
	return m_applied_price;
}

inline int History::Bars() const
{
	return (*this.*pBars)();
}

inline double History::AppliedPrice(int i) const
{
	return (*this.*pAppliedPrice)(i);
}

inline double History::Open(int i) const
{
	return (*this.*pOpen)(i);
}

inline double History::High(int i) const
{
	return (*this.*pHigh)(i);
}

inline double History::Low(int i) const
{
	return (*this.*pLow)(i);
}

inline double History::Close(int i) const
{
	return (*this.*pClose)(i);
}

inline double History::Median(int i) const
{
	return (*this.*pMedian)(i);
}

inline double History::Typical(int i) const
{
	return (*this.*pTypical)(i);
}

inline double History::Weighted(int i) const
{
	return (*this.*pWeighted)(i);
}

inline long History::Volume(int i)const
{
	return (*this.*pVolume)(i);
}
