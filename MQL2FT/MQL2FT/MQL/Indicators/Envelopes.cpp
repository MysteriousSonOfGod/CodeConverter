#include "../pch.h"

#include "Envelopes.h"


Envelopes::Envelopes(const std::string& symbol, const int timeframe, const int price_type,
	const ENUM_MA_METHOD ma_method, const int period,
	std::weak_ptr<MovingAverage> moving_average_indicator) :
	Indicator{ symbol, timeframe, price_type },
	m_ma_method(ma_method), m_period{ period },
	m_moving_average_indicator{ moving_average_indicator }
{
}


Envelopes::~Envelopes()
{
}


double Envelopes::getUpperBand(const int index, const double deviation) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_moving_average_indicator.lock()->getValue(index) * (1.0 + deviation / 100.0);
}

double Envelopes::getLowerBand(const int index, const double deviation) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_moving_average_indicator.lock()->getValue(index) * (1.0 - deviation / 100.0);
}