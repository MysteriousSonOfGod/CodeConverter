#pragma once

#include "Indicator.h"
#include "ExponentialMovingAverage.h"

class BearsPower final :
	public Indicator
{
public:
	BearsPower(const std::string& symbol, const int timeframe, const int period,
		const int price_type, std::weak_ptr<ExponentialMovingAverage> ema_values);

	virtual ~BearsPower();

	inline int getPeriod() const;

	double getValue(const int index) const;

private:
	int m_period;
	std::weak_ptr<ExponentialMovingAverage> m_ema_values;
};

inline int BearsPower::getPeriod() const
{
	return m_period;
}

