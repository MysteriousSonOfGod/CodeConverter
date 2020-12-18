#include "../pch.h"
#include "ForceIndex.h"


ForceIndex::ForceIndex(const std::string& symbol, const int timeframe, const int price_type,
	const ENUM_MA_METHOD ma_metod, const int period, std::weak_ptr<MovingAverage> moving_average_indicator) :
	Indicator{ symbol, timeframe, price_type },
	m_ma_method(ma_metod), m_period {period}, m_moving_average_indicator{moving_average_indicator}
{
}


ForceIndex::~ForceIndex()
{
}

double ForceIndex::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_history.Volume(index) * ( m_moving_average_indicator.lock()->getValue(index) - m_moving_average_indicator.lock()->getValue(index + 1));
}
