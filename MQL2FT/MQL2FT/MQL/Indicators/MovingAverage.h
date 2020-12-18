#pragma once

#include "UpdatableIndicator.h"


class MovingAverage : public UpdatableIndicator
{
public:
	MovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type);
	MovingAverage(const std::vector<double>* const history_vector, const int period);

	virtual ~MovingAverage();

	virtual double getValue(const int index) const = 0;

	inline int getPeriod() const;

protected:
	int m_period;
	std::vector<double> m_values;
	int m_last_calculated;
};

inline int MovingAverage::getPeriod() const
{
	return m_period;
}
