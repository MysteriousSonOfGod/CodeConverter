#include "../pch.h"

#include "IchimokuKinkoHyo.h"


IchimokuKinkoHyo::IchimokuKinkoHyo(const std::string& symbol, const int timeframe, const int tenkan_sen_period,
        const int kijun_sen_period, const int senkou_span_period) : UpdatableIndicator{ symbol, timeframe },
	m_tenkan_sen_period{ tenkan_sen_period },
    m_kijun_sen_period{ kijun_sen_period },
    m_senkou_span_period{ senkou_span_period },
    m_last_calculated{ 0 }
{
}

IchimokuKinkoHyo::~IchimokuKinkoHyo()
{
}

double IchimokuKinkoHyo::getTenkanSenValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_tenkan_sen_values[reverse_index];
#else
	if (reverse_index < m_tenkan_sen_period - 1)
	{
		return 0.0;
	}
	else
	{
		return m_tenkan_sen_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double IchimokuKinkoHyo::getKijunSenValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_kijun_sen_values[reverse_index];
#else
	if (reverse_index < m_kijun_sen_period - 1)
	{
		return 0.0;
	}
	else
	{
		return m_kijun_sen_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double IchimokuKinkoHyo::getChinkouSpanValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_chinkou_span_values[reverse_index];
#else
	if (index < m_kijun_sen_period)
	{
		return 0.0;
	}
	else
	{
		return m_history.Close(index - m_kijun_sen_period);
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double IchimokuKinkoHyo::getSenkouSpanAValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < -m_kijun_sen_period || index >= bars - m_kijun_sen_period) return 0.0;

	const int reverse_index = bars - 1 - m_kijun_sen_period - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_senkou_span_a_values[reverse_index];
#else
	if (reverse_index < m_kijun_sen_period - 1)
	{
		return 0.0;
	}
	else
	{
		return m_senkou_span_a_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double IchimokuKinkoHyo::getSenkouSpanBValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < -m_kijun_sen_period || index >= bars - m_kijun_sen_period) return 0.0;

	const int reverse_index = bars - 1 - m_kijun_sen_period - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_senkou_span_b_values[reverse_index];
#else
	if (reverse_index < m_senkou_span_period - 1)
	{
		return 0.0;
	}
	else
	{
		return m_senkou_span_b_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

void IchimokuKinkoHyo::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_tenkan_sen_values.size() < bars || m_kijun_sen_values.size() < bars ||
		m_senkou_span_a_values.size() < bars || m_senkou_span_b_values.size() < bars)
	{
		m_tenkan_sen_values.resize(bars);
		m_kijun_sen_values.resize(bars);
		m_senkou_span_a_values.resize(bars);
		m_senkou_span_b_values.resize(bars);
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		int reverse_index = bars - 1 - i;
		m_tenkan_sen_values[i] = HighestLowestAverage(bars, reverse_index, m_tenkan_sen_period);
		m_kijun_sen_values[i] = HighestLowestAverage(bars, reverse_index, m_kijun_sen_period);
		m_senkou_span_a_values[i] = (m_tenkan_sen_values[i] + m_kijun_sen_values[i]) / 2.0;
		m_senkou_span_b_values[i] = HighestLowestAverage(bars, reverse_index, m_senkou_span_period);
	}

	m_last_calculated = bars - 1;
}

double IchimokuKinkoHyo::HighestLowestAverage(const int bars, int reverse_index, const int period) const
{
	double min = 1.79769e+308, max = 0;
	int stop_index = reverse_index + period;
	if (stop_index >= bars) stop_index = bars - 1;

	while (reverse_index < stop_index)
	{
		double low = m_history.Low(reverse_index);
		if (low < min) min = low;
		double high = m_history.High(reverse_index);
		if (high > max) max = high;
		++reverse_index;
	}

	return (min + max) / 2.0;
}