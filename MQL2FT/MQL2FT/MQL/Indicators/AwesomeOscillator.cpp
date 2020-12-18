#include "../pch.h"

#include "AwesomeOscillator.h"


AwesomeOscillator::AwesomeOscillator(const std::string& symbol, const int timeframe,
	std::weak_ptr<SimpleMovingAverage> sma_values_p5,
	std::weak_ptr<SimpleMovingAverage> sma_values_p34) :
	Indicator{ symbol, timeframe },
	m_sma_values_p5 { sma_values_p5 },
	m_sma_values_p34 { sma_values_p34 }
{
}


AwesomeOscillator::~AwesomeOscillator()
{
}

double AwesomeOscillator::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;
	if (reverse_index < 34) {
		return 0.0;
	}
	else {
		return m_sma_values_p5.lock()->getValue(index) - m_sma_values_p34.lock()->getValue(index);
	}
}
