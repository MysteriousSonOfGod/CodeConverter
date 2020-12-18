#include "../pch.h"

#include "RelativeVigorIndex.h"


RelativeVigorIndex::RelativeVigorIndex(const std::string& symbol,
	                                   const int timeframe,
	                                   const int period) :
	                                   UpdatableIndicator{ symbol, timeframe },
									   m_period { period }, m_last_calculated_main { 0 },
									   m_last_calculated_signal { 0 }

{
}


RelativeVigorIndex::~RelativeVigorIndex()
{
}

void RelativeVigorIndex::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_main_values.size() < bars)
	{
		m_main_values.resize(bars); // Avoid removing already calculated values
	}

	for (int i = m_last_calculated_main; i < bars; ++i)
	{
		double moving_average = 0.0, range_average = 0.0, dNum = 0.0, dDeNum = 0.0;

		for (int j = i; j > i - m_period; j--)
		{
			moving_average = getMovingAverage(bars - 1 - j);
			range_average = getRangeAverage(bars - 1 - j);
			dNum += moving_average;
			dDeNum += range_average;
		}
		if (dDeNum != 0.0)
			m_main_values[i] = dNum / dDeNum;
		else
			m_main_values[i] = dNum;
	}

	m_last_calculated_main = bars - 1;

	if (m_signal_values.size() < bars)
	{
		m_signal_values.resize(bars); // Avoid removing already calculated values
	}

	for (int i = m_last_calculated_signal; i < bars; ++i)
	{
		m_signal_values[i] = (getMainValue(bars - 1 - i) + 2.0 * getMainValue(bars - 1 - i + 1) +
			2.0 * getMainValue(bars - 1 - i + 2) + getMainValue(bars - 1 - i + 3)) / 6.0;
	}

	m_last_calculated_signal = bars - 1;
}


double RelativeVigorIndex::getMainValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	#ifdef CALCULATE_USING_AVAILABLE_DATA
		return m_main_values[reverse_index];
	#else
		if (reverse_index < m_period - 1 + 3)
		{
			return 0.0;
		}
		else
		{
			return m_main_values[reverse_index];
		}
	#endif // CALCULATE_USING_AVAILABLE_DATA

}


double RelativeVigorIndex::getSignalValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_signal_values[reverse_index];
#else
	if (reverse_index < m_period - 1 + 6)
	{
		return 0.0;
	}
	else
	{
		return m_signal_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}
