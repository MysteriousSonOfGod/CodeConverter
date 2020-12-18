#include "../pch.h"

#include "MovingAverageOscillator.h"


MovingAverageOscillator::MovingAverageOscillator(const std::string& symbol, const int timeframe, const int price_type,
	                                             const int short_period, const int long_period, const int signal_period,
	                                             std::weak_ptr<Macd> macd) :
	                                             Indicator{ symbol, timeframe, price_type },
	                                             m_short_period {short_period},
												 m_long_period{ long_period },
												 m_signal_period{ signal_period },
												 m_macd{ macd }
{
}


MovingAverageOscillator::~MovingAverageOscillator()
{
}


double MovingAverageOscillator::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_macd.lock()->getMacd(index) - m_macd.lock()->getSignal(index);
}
