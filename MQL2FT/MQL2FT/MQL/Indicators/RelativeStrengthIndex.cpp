#include "../pch.h"

#include "RelativeStrengthIndex.h"


RelativeStrengthIndex::RelativeStrengthIndex(const std::string& symbol, const int timeframe, const int price_type,
	const int period) :
	UpdatableIndicator{ symbol,timeframe, price_type },
	m_period{ period }, m_last_calculated{ 0 }
{
	m_price_diff.resize(m_period + 1);
}

RelativeStrengthIndex::~RelativeStrengthIndex()
{
}

void RelativeStrengthIndex::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_rsi_values.size() < bars || m_negative_sma_values.size() < bars || m_possitive_sma_values.size() < bars)
	{
		m_rsi_values.resize(bars);
		m_negative_sma_values.resize(bars);
		m_possitive_sma_values.resize(bars);
	}

	if (m_last_calculated < 1 || bars == 1)
	{
		m_rsi_values[0] = 50.0;
		m_negative_sma_values[0] = 0.0;
		m_possitive_sma_values[0] = 0.0;
		m_last_calculated = 1;
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		const double prev_price = m_history.AppliedPrice(bars - 1 - i + 1);
		const double current_price = m_history.AppliedPrice(bars - 1 - i);

		const double current_diff = current_price - prev_price;

		if (i < m_period)
		{
			m_price_diff.resize(i + 1);
			m_price_diff[i] = current_diff;
			m_negative_sma_values[i] = getNegativeSma();
			m_possitive_sma_values[i] = getPossitiveSma();

			if (m_negative_sma_values[i] == 0.0)
			{
				if (m_possitive_sma_values[i] > 0.0)
				{
					m_rsi_values[i] = 50.0;
				}
				else m_rsi_values[i] = 100.0;
			}
			else
			{
				double rs = m_possitive_sma_values[i] / m_negative_sma_values[i];
				m_rsi_values[i] = 100.0 - (100.0 / (1 + rs));
			}
		}
		else
		{
			if (i == m_period)
			{
				m_price_diff.resize(i + 1);
				m_price_diff[i] = current_diff;
				m_negative_sma_values[i] = getNegativeSma();
				m_possitive_sma_values[i] = getPossitiveSma();

				if (m_negative_sma_values[i] == 0.0)
				{
					if (m_possitive_sma_values[i] > 0.0)
					{
						m_rsi_values[i] = 50.0;
					}
					else m_rsi_values[i] = 100.0;
				}
				else
				{
					double rs = m_possitive_sma_values[i] / m_negative_sma_values[i];
					m_rsi_values[i] = 100.0 - (100.0 / (1 + rs));
				}
			}
			else
			{
				m_possitive_sma_values[i] = (m_possitive_sma_values[i - 1] * (m_period - 1) +
					(current_diff > 0.0 ? current_diff : 0.0)) / m_period;

				m_negative_sma_values[i] = (m_negative_sma_values[i - 1] * (m_period - 1) +
					(current_diff < 0.0 ? fabs(current_diff) : 0.0)) / m_period;

				if (m_negative_sma_values[i] == 0.0)
				{
					if (m_possitive_sma_values[i] > 0.0)
					{
						m_rsi_values[i] = 50.0;
					}
					else m_rsi_values[i] = 100.0;
				}
				else
				{
					double rs = m_possitive_sma_values[i] / m_negative_sma_values[i];
					auto res = 100.0 - (100.0 / (1 + rs));
					m_rsi_values[i] = res;
				}
			}
		}
	}

	m_last_calculated = bars - 1;
}

double RelativeStrengthIndex::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	#ifdef CALCULATE_USING_AVAILABLE_DATA
		return m_rsi_values[reverse_index];
	#else
		if (reverse_index < m_period)
		{
			return 0.0;
		}
		else
		{
			return m_rsi_values[reverse_index];
		}
	#endif // CALCULATE_USING_AVAILABLE_DATA
}



double RelativeStrengthIndex::getNegativeSma() const
{
	double sum = 0.0;
	for (auto value : m_price_diff)
	{
		if (value < 0.0)
		{
			sum += value;
		}
	}

	return (fabs(sum) / m_period);
}


double RelativeStrengthIndex::getPossitiveSma() const
{
	double sum = 0.0;
	for (auto value : m_price_diff)
	{
		if (value > 0.0)
		{
			sum += value;
		}
	}

	return sum / m_period;
}
