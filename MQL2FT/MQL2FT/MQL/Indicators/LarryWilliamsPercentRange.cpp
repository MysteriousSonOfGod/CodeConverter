#include "../pch.h"

#include "LarryWilliamsPercentRange.h"


LarryWilliamsPercentRange::LarryWilliamsPercentRange(const std::string& symbol, const int timeframe,
	const int period) :
	Indicator { symbol, timeframe }, m_period { period }
{
}


LarryWilliamsPercentRange::~LarryWilliamsPercentRange()
{
}


double LarryWilliamsPercentRange::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	std::string symbol = getSymbol();
	int timeframe = getTimeframe();

	double max_high = m_history.High(ft::iHighest(const_cast<char*>(symbol.c_str()), timeframe, MODE_HIGH, m_period, index));
	double min_low = m_history.Low(ft::iLowest(const_cast<char*>(symbol.c_str()), timeframe, MODE_LOW, m_period, index));

	double wpr{};
	double current_close = m_history.Close(index);
	if (max_high - min_low != 0.0)
	{
		wpr = -100.0 * (max_high - current_close) / (max_high - min_low);
	}

	return wpr;
}