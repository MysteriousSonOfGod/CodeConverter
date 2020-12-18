#include "../pch.h"

#include "Stochastic.h"


Stochastic::Stochastic(const std::string& symbol, const int timeframe, const int k_period, const int d_period,
	const int slowing, const ENUM_MA_METHOD ma_method, const ENUM_STO_PRICE price_field) :
	Indicator{ symbol, timeframe },
	m_k_period{ k_period }, m_d_period{ d_period }, m_slowing{ slowing }, m_ma_method(ma_method),
	m_price_field{ price_field }, m_invalid_parameters{ false }, m_last_calculated{ 0 },
	m_moving_average_indicator{ nullptr }
{
	if (k_period < 1 || d_period < 1 || slowing < 1) m_invalid_parameters = true;

	switch (ma_method)
	{
	case MODE_EMA:
		m_moving_average_indicator = std::unique_ptr<ExponentialMovingAverage>(new ExponentialMovingAverage(&m_main_values, d_period));
		break;

	case MODE_SMA:
		m_moving_average_indicator = std::unique_ptr<SimpleMovingAverage>(new SimpleMovingAverage(&m_main_values, d_period));
		break;

	case MODE_LWMA:
		m_moving_average_indicator = std::unique_ptr<WeightedMovingAverage>(new WeightedMovingAverage(&m_main_values, d_period));
		break;

	case MODE_SMMA:
		m_moving_average_indicator = std::unique_ptr<SmoothedMovingAverage>(new SmoothedMovingAverage(&m_main_values, d_period));
		break;

	default:
		m_invalid_parameters = true;
		break;
	}
}


Stochastic::~Stochastic()
{
}


void Stochastic::calculateValues() const
{
	const int bars = m_history.Bars();

	m_main_values.resize(bars);
	m_high_values.resize(bars);
	m_low_values.resize(bars);

	// Calculate main values
	for (int i = m_last_calculated; i < bars; ++i)
	{
		const int reverse_index = bars - 1 - i;
		double highest, lowest;

		if (m_price_field == STO_CLOSECLOSE)
		{
			highest = lowest = m_history.Close(reverse_index);

			for (int j = 1; j < m_k_period; ++j)
			{
				double close_price = m_history.Close(reverse_index + j);
				if (close_price > highest) highest = close_price;
				if (close_price < lowest) lowest = close_price;
			}
		}
		else
		{
			highest = m_history.High(reverse_index);
			lowest = m_history.Low(reverse_index);

			for (int j = 1; j < m_k_period; ++j)
			{
				double high_price = m_history.High(reverse_index + j);
				double low_price = m_history.Low(reverse_index + j);
				if (high_price > highest) highest = high_price;
				if (low_price < lowest) lowest = low_price;
			}
		}

		m_high_values[i] = highest;
		m_low_values[i] = lowest;

		double sum_low = 0.0;
		double sum_high = 0.0;

		for (int j = m_slowing - 1; j >= 0; --j)
		{
			if (i - j < 0)
			{
				sum_low += m_history.Close(reverse_index + j);
			}
			else
			{
				sum_low += m_history.Close(reverse_index + j) - m_low_values[i - j];
				sum_high += m_high_values[i - j] - m_low_values[i - j];
			}
		}

		if (sum_high == 0.0) m_main_values[i] = 100.0;
		else m_main_values[i] = sum_low / sum_high * 100.0;
	}

	m_last_calculated = bars - 1;
}

double Stochastic::getMainValue(const int index) const
{
	if (index < 0 || m_invalid_parameters) return 0.0;

	const int bars = m_history.Bars();

	if (bars < 1 || index >= bars) return 0.0;

	calculateValues();

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	return m_main_values[reverse_index];
#else
	if (reverse_index < m_k_period + m_slowing)
	{
		return 0.0;
	}
	else
	{
		return m_main_values[reverse_index];
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}

double Stochastic::getSignalValue(const int index) const
{
	if (index < 0 || m_invalid_parameters) return 0.0;

	const int bars = m_history.Bars();

	if (bars < 1 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

#ifdef CALCULATE_USING_AVAILABLE_DATA
	m_moving_average_indicator->update();
	return m_moving_average_indicator.get()->getValue(index);
#else
	if (reverse_index < m_k_period + m_d_period + m_slowing - 1)
	{
		return 0.0;
	}
	else
	{
		m_moving_average_indicator->update();
		return m_moving_average_indicator.get()->getValue(index);
	}
#endif // CALCULATE_USING_AVAILABLE_DATA
}
