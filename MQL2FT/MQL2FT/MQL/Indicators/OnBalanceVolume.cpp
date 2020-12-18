#include "../pch.h"

#include "OnBalanceVolume.h"
#undef min

OnBalanceVolume::OnBalanceVolume(const std::string& symbol, const int timeframe, const int price_type) :
	Indicator{ symbol, timeframe, price_type },
	m_last_calculated{0}
{
}


OnBalanceVolume::~OnBalanceVolume()
{
}


bool is_equal(double x, double y) {
	return (std::fabs(x - y) <  std::numeric_limits<double>::epsilon());


}


double OnBalanceVolume::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	if (m_values.size() < bars)
	{
		m_values.resize(bars);
	}

	if (m_last_calculated < 1 || bars == 1)
	{
		std::string symbol = getSymbol();
		m_values[0] = m_history.Volume(bars - 1);
		m_last_calculated = 1;
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		std::string symbol = getSymbol();
		
		const double curr_price = m_history.AppliedPrice(bars - 1 - i);
		const double previous_price = m_history.AppliedPrice(bars - i);
		
		if (std::fabs(curr_price - previous_price) <= std::numeric_limits<double>::epsilon() ||
			std::fabs(curr_price - previous_price) <= std::fabs(std::min(curr_price, previous_price)) * std::numeric_limits<double>::epsilon())
		{
			m_values[i] = m_values[i - 1];
		}
		else
		{
			if (curr_price > previous_price)
			{
				m_values[i] = m_values[i - 1] + m_history.Volume(bars - 1 - i);
			}
			else if (curr_price < previous_price)
			{
				m_values[i] = m_values[i - 1] - m_history.Volume(bars - 1 - i);
			}
		}

	}

	m_last_calculated = bars - 1;

	return m_values[bars - 1 - index];
}
