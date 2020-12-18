#include "../pch.h"

#include "AverageTrueRange.h"


AverageTrueRange::AverageTrueRange(const std::string& symbol, const int timeframe, const int period) :
	UpdatableIndicator{ symbol, timeframe }, m_period{ period }, m_last_calculated{ 0 }
{
}


AverageTrueRange::~AverageTrueRange()
{
}


void AverageTrueRange::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_atr_values.size() < bars || m_tr_values.size() < bars)
	{
		m_atr_values.resize(bars);
		m_tr_values.resize(bars);
	}

	if (m_last_calculated < 1 || bars == 1)
	{
		double price_high = m_history.High(bars - 1);
		double price_low = m_history.Low(bars - 1);
		double tr = fabs(price_high - price_low);
		m_tr_values[0] = tr;
		m_last_calculated = 1;
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		int reverse_index = bars - 1 - i;
		double price_high = m_history.High(reverse_index);
		double price_low = m_history.Low(reverse_index);
		double tr = fabs(price_high - price_low);
		double prev_close = m_history.Close(reverse_index + 1);
		double tr_high = fabs(price_high - prev_close);
		double tr_low = fabs(price_low - prev_close);

#undef max

		double current_tr = std::max(std::max(tr, tr_high), tr_low);

		//ATR[i] = ATR[i - 1] + (tr[i] - tr[i - n]) / n;
		if (i <= m_period)
		{
			m_tr_values[i] = current_tr;

			double sum = 0.0;
			for (int k = 0; k < i; ++k)
			{
				sum += m_tr_values[i - k];
			}

			m_atr_values[i] = sum / m_period;
		}
		else
		{
			m_tr_values[i] = current_tr;
			m_atr_values[i] = m_atr_values[i - 1] + (m_tr_values[i] - m_tr_values[i - m_period]) / m_period;
		}

	}

	m_last_calculated = bars - 1;
}

double AverageTrueRange::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	#ifdef CALCULATE_USING_AVAILABLE_DATA
		return m_atr_values[reverse_index];
	#else
		if (reverse_index < m_period - 1)
		{
			return 0.0;
		}
		else
		{
			return m_atr_values[reverse_index];
		}
	#endif // CALCULATE_USING_AVAILABLE_DATA
}
