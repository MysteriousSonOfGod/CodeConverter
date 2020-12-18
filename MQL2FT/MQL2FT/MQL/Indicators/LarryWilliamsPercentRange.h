#pragma once

#include "Indicator.h"

class LarryWilliamsPercentRange :
	public Indicator
{
public:
	LarryWilliamsPercentRange(const std::string& symbol, const int timeframe, const int period);
	virtual ~LarryWilliamsPercentRange();

	inline int getPeriod() const;

	double getValue(const int index) const;

private:
	int m_period;
};

inline int LarryWilliamsPercentRange::getPeriod() const
{
	return m_period;
}