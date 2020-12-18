#include "../pch.h"
#include "AverageDirectionalIndex.h"
#undef max


AverageDirectionalIndex::AverageDirectionalIndex(const std::string& symbol,
	const int timeframe, const int price_type, const int period) :
	UpdatableIndicator{ symbol, timeframe, price_type} , m_period { period },
	m_ema_factor { 2.0 / (m_period + 1) }, m_last_calculated_main{ 0 }
{
}


AverageDirectionalIndex::~AverageDirectionalIndex()
{
}

void AverageDirectionalIndex::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_main_values.size() < bars)
	{
		m_main_values.resize(bars);
		m_minus_di_values.resize(bars);
		m_plus_di_values.resize(bars);
	}

	if (m_last_calculated_main < 1 || bars == 1)
	{
		// Initialize or update the first value with the price of the first bar
		m_main_values[0] = m_minus_di_values[0] = m_plus_di_values[0] = 0.0;
		m_last_calculated_main = 1; // Avoid calculating of the first bar in the following for loop
	}

	for (int i = m_last_calculated_main; i < bars; ++i)
	{
		const double current_low = m_history.Low(bars - 1 - i);
		const double current_high = m_history.High(bars - 1 - i);
		const double previous_applied_price = m_history.AppliedPrice(bars - 1 - i + 1);
		const double previous_low = m_history.Low(bars - 1 - i + 1);
		const double previous_high = m_history.High(bars - 1 - i + 1);

		double pdm = current_high - previous_high;
		double ndm = previous_low - current_low;

		if (pdm < 0.0) pdm = 0.0;
		if (ndm < 0.0) ndm = 0.0;
		if (pdm == ndm)
		{
			pdm = ndm = 0.0;
		}
		else if (pdm < ndm)
		{
			pdm = 0.0;
		}
		else if (ndm < pdm)
		{
			ndm = 0.0;
		}

		const double true_range = getTrueRange(current_high, current_low, previous_applied_price);
		if (true_range == 0.0)
		{
			m_minus_di_values[i] = m_minus_di_values[i - 1] + m_ema_factor * (0.0 - m_minus_di_values[i - 1]);;
			m_plus_di_values[i] = m_plus_di_values[i - 1] + m_ema_factor * (0.0 - m_plus_di_values[i - 1]);
		}
		else {
			m_plus_di_values[i] = m_plus_di_values[i - 1] + m_ema_factor * (100.0 * pdm / true_range - m_plus_di_values[i - 1]);
			m_minus_di_values[i] = m_minus_di_values[i - 1] + m_ema_factor * (100.0 * ndm / true_range - m_minus_di_values[i - 1]);
		}

		const double div = fabs(m_plus_di_values[i] + m_minus_di_values[i]);
		if (div == 0.0)
		{
			m_main_values[i] = m_main_values[i - 1] + m_ema_factor * (0.0 - m_main_values[i - 1]);
		}
		else
		{
			m_main_values[i] = m_main_values[i - 1] + m_ema_factor * (100.0 * (fabs(m_plus_di_values[i] - m_minus_di_values[i]) / div) - m_main_values[i - 1]);
		}

	}

	m_last_calculated_main = bars - 1;
}

double AverageDirectionalIndex::getMainValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_main_values[bars - 1 - index];
}


double AverageDirectionalIndex::getPlusDiValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_plus_di_values[bars - 1 - index];
}

double AverageDirectionalIndex::getMinusDiValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_minus_di_values[bars - 1 - index];
}

double AverageDirectionalIndex::getTrueRange(const double price_high, const double price_low, 
	const double prev_applied_price) const
{
	return std::max(std::max(fabs(price_high - price_low), fabs(price_high - prev_applied_price)), fabs(price_low - prev_applied_price));
}
