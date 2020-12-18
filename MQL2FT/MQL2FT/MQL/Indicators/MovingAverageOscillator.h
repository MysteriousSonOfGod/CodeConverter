#pragma once

#include "Indicator.h"
#include "Macd.h"


class MovingAverageOscillator :
	public Indicator
{
public:
	MovingAverageOscillator(const std::string& symbol, const int timeframe, const int price_type,
		                    const int short_period, const int long_period, const int signal_period,
		                    std::weak_ptr<Macd> macd);
	virtual ~MovingAverageOscillator();

	inline int getShortPeriod() const;
	inline int getLongPeriod() const;
	inline int getSignalPeriod() const;

	double getValue(const int index) const;

private:
	int m_short_period;
	int m_long_period;
	int m_signal_period;

	std::weak_ptr<Macd> m_macd;
};


inline int MovingAverageOscillator::getShortPeriod() const
{
	return m_short_period;
}


inline int MovingAverageOscillator::getLongPeriod() const
{
	return m_long_period;
}


inline int MovingAverageOscillator::getSignalPeriod() const
{
	return m_signal_period;
}