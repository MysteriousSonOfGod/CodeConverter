#pragma once

#include "Indicator.h"
#include "SimpleMovingAverage.h"

class DeMarker final :
	public Indicator
{
public:
	DeMarker(const std::string& symbol, const int timeframe, const int period);

	virtual ~DeMarker() = default;

	inline int getPeriod() const;

	double getValue(const int index) const;

private:
	mutable std::vector<double> m_demax;
	mutable std::vector<double> m_demin;

	std::unique_ptr<SimpleMovingAverage> m_sma_demax;
	std::unique_ptr<SimpleMovingAverage> m_sma_demin;

	mutable std::vector<double> m_val;

	int m_period;
	mutable int m_last_calculated;
};

inline int DeMarker::getPeriod() const
{
	return m_period;
}
