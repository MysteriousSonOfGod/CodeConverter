#include "../pch.h"

#include "Macd.h"


Macd::Macd(const std::string& symbol, const int timeframe, const int price_type, const int short_period,
	const int long_period, const int signal_period, std::weak_ptr<ExponentialMovingAverage> ema_short_period,
	std::weak_ptr<ExponentialMovingAverage> ema_long_period) :
	UpdatableIndicator{ symbol, timeframe, price_type },
	m_short_period{ short_period }, m_long_period{ long_period }, m_signal_period{ signal_period },
	m_ema_short{ ema_short_period }, m_ema_long{ ema_long_period },
	m_last_calculated_macd{ 0 }, m_last_calculated_signal{ 0 }
{
}

Macd::~Macd()
{
}

void Macd::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_macd_values.size() < bars)
	{
		m_macd_values.resize(bars);
	}

	for (int i = m_last_calculated_macd; i < bars; ++i)
	{
		m_macd_values[i] = m_ema_short.lock()->getValue(bars - 1 - i) - m_ema_long.lock()->getValue(bars - 1 - i);
	}

	m_last_calculated_macd = bars - 1;

	if (m_signal_values.size() < bars)
	{
		m_signal_values.resize(bars);
	}

	for (int i = m_last_calculated_signal; i < bars; ++i)
	{
		double sum = 0.0;
		for (size_t k = 0; k < m_signal_period; ++k)
		{
			sum += getMacd(bars - 1 - i + k);
		}
		m_signal_values[i] = sum / m_signal_period;
	}

	m_last_calculated_signal = bars - 1;
}

double Macd::getMacd(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_macd_values[bars - 1 - index];
}


double Macd::getSignal(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_signal_values[bars - 1 - index];
}
