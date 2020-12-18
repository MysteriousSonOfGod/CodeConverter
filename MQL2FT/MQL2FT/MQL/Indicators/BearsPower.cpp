#include "../pch.h"
#include "BearsPower.h"


BearsPower::BearsPower(const std::string& symbol, const int timeframe, const int period,
	const int price_type, std::weak_ptr<ExponentialMovingAverage> ema_values) :
	Indicator{ symbol, timeframe, price_type }, m_period{ period },
	m_ema_values { ema_values }
{
}


BearsPower::~BearsPower()
{
}


double BearsPower::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_history.Low(index) - m_ema_values.lock()->getValue(index);
}
