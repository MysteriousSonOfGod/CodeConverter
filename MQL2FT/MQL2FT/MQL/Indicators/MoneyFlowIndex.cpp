#include "../pch.h"

#include "MoneyFlowIndex.h"


MoneyFlowIndex::MoneyFlowIndex(const std::string& symbol, const int timeframe, const int period) :
	UpdatableIndicator{ symbol, timeframe }, m_period{ period }, m_last_calculated{ 0 }
{
}


MoneyFlowIndex::~MoneyFlowIndex()
{
}

void MoneyFlowIndex::update()
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
		const int reverse_index = bars - 1;

		m_values[0] = m_history.Typical(reverse_index) * m_history.Volume(reverse_index);;
		m_last_calculated = 1; // Avoid calculating of the first bar in the following for loop
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		const int reverse_index = bars - 1 - i;

		const double curr_price_typical = m_history.Typical(reverse_index);
		const double prev_price_typical = m_history.Typical(reverse_index + 1);
		const double money_flow = curr_price_typical * m_history.Volume(reverse_index);

		if (curr_price_typical > prev_price_typical)
		{
			m_values[i] = money_flow;
		}
		else if (curr_price_typical < prev_price_typical)
		{
			m_values[i] = money_flow * (-1.0);
		}
		else
		{
			m_values[i] = 0.0;
		}
	}

	m_last_calculated = bars - 1;
}

double MoneyFlowIndex::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	const double sum_negative_money_flow = getNegativeMoneyFlow(reverse_index);
	const double sum_positive_money_flow = getPossitiveMoneyFlow(reverse_index);

	double money_ratio;
	double money_flow_index;

	if (sum_negative_money_flow != 0.0)
	{
		money_ratio = sum_positive_money_flow / fabs(sum_negative_money_flow);
		money_flow_index = 100.0 - (100.0 / (1.0 + money_ratio));
    }
	else money_flow_index = 100.0;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_values[reverse_index];
#else
	if (reverse_index < m_period)
	{
		return 0.0;
	}
	else
	{
		return money_flow_index;
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double MoneyFlowIndex::getNegativeMoneyFlow(const int reverse_index) const
{
	double sum_negative{};

	if (reverse_index < m_period - 1)
	{
		for (int i = 0; i < reverse_index; ++i)
		{
			if (m_values[i] < 0.0)
			{
				sum_negative += m_values[i];
			}
		}
	}
	else
	{
		const int end_calculate = reverse_index - m_period;
		for (int i = reverse_index; i > end_calculate; --i)
		{
			if (m_values[i] < 0.0)
			{
				sum_negative += m_values[i];
			}
		}
	}

	return sum_negative;
}

double MoneyFlowIndex::getPossitiveMoneyFlow(const int reverse_index) const
{
	double sum_possitive{};

	if (reverse_index < m_period)
	{
		for (int i = 0; i < reverse_index; ++i)
		{
			if (m_values[i] > 0.0)
			{
				sum_possitive += m_values[i];
			}
		}
	}
	else
	{
		const int end_calculate = reverse_index - m_period;
		for (int i = reverse_index; i > end_calculate; --i)
		{
			if (m_values[i] > 0.0)
			{
				sum_possitive += m_values[i];
			}
		}
	}

	return sum_possitive;
}