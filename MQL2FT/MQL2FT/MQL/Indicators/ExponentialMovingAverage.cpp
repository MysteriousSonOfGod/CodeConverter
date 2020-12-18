#include "../pch.h"

#include "ExponentialMovingAverage.h"


ExponentialMovingAverage::ExponentialMovingAverage(const std::string& symbol, const int timeframe,
	const int period, const int price_type) :
	MovingAverage{ symbol, timeframe, period, price_type },
	m_factor{ 2.0 / (m_period + 1) }
{
}

ExponentialMovingAverage::ExponentialMovingAverage(const std::vector<double>* const history_vector, const int period) :
	MovingAverage{ history_vector, period }
{
}

ExponentialMovingAverage::~ExponentialMovingAverage()
{
}

void ExponentialMovingAverage::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_values.size() < bars)
	{
		m_values.resize(bars); // Avoid removing already calculated values
	}

	if (m_last_calculated < 1 || bars == 1)
	{
		// Initialize or update the first value with the price of the first bar
		m_values[0] = m_history.AppliedPrice(bars - 1);
		m_last_calculated = 1; // Avoid calculating of the first bar in the following for loop
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		const double prev_value = m_values[i - 1];
		m_values[i] = prev_value + m_factor * (m_history.AppliedPrice(bars - 1 - i) - prev_value);
	}

	m_last_calculated = bars - 1;
}

double ExponentialMovingAverage::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	// In MT4 it always calculates values using available data ignoring a specified period
	return m_values[bars - 1 - index];  
}
