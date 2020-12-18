#include "../pch.h"

#include "SimpleMovingAverage.h"


SimpleMovingAverage::SimpleMovingAverage(const std::string& symbol, const int timeframe, const int period,
	const int price_type) :
	MovingAverage{ symbol, timeframe, period, price_type }
{
}

SimpleMovingAverage::SimpleMovingAverage(const std::vector<double>* const history_vector, const int period) :
	MovingAverage{ history_vector, period }
{
}

SimpleMovingAverage::~SimpleMovingAverage()
{
}

void SimpleMovingAverage::update()
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
		const double curr_price = m_history.AppliedPrice(bars - 1 - i);

		if (i < m_period)
		{
			m_values[i] = (m_values[i - 1] * i + curr_price) / (i + 1);
		}
		else
		{
			double first_price_in_period = m_history.AppliedPrice(bars - 1 - i + m_period);
			m_values[i] = m_values[i - 1] - (first_price_in_period - curr_price) / m_period;
		}
	}

	m_last_calculated = bars - 1;
}

double SimpleMovingAverage::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	#ifdef CALCULATE_USING_AVAILABLE_DATA
		return m_values[reverse_index];
	#else
		if (reverse_index < m_period - 1)
		{
			return 0.0;
		}
		else
		{
			return m_values[reverse_index];
		}
	#endif // CALCULATE_USING_AVAILABLE_DATA
}
