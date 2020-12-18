#include "..\pch.h"

#include "ParabolicStopAndReverse.h"


ParabolicStopAndReverse::ParabolicStopAndReverse(const std::string& symbol, const int timeframe, const double step,
	const double maximum) :
	Indicator{ symbol, timeframe }, m_step{ step }, m_maximum{ maximum }, m_last_calculated{ 0 }
{
}


ParabolicStopAndReverse::~ParabolicStopAndReverse()
{
}

double ParabolicStopAndReverse::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 3 || index < 0 || index >= bars) return 0.0;

	m_values.resize(bars);

	bool dir_long = true;
	double start = m_step;
	double last_low = 1.7e+308;
	double last_high = -1.7e+308;
	int i = bars - 2;

	double ep, price, price_low, price_high;
	double sar = 0.0;

	if (m_last_calculated < bars - 1)
	{
		while (i > 0)
		{
			price_low = m_history.Low(i);
			if (last_low > price_low)
			{
				last_low = price_low;
			}

			price_high = m_history.High(i);
			if (last_high < price_high)
			{
				last_high = price_high;
			}

			double prev_high = m_history.High(i + 1);
			double prev_low = m_history.Low(i + 1);

			if (price_high > prev_high && price_low > prev_low)
			{
				break;
			}

			if (price_high < prev_high && price_low < prev_low)
			{
				dir_long = false;
				break;
			}

			--i;
		}

		if (dir_long)
		{
			m_values[bars - 1 - i] = m_history.Low(i + 1);
			ep = m_history.High(i);
		}
		else
		{
			m_values[bars - 1 - i] = m_history.High(i + 1);
			ep = m_history.Low(i);
		}

		--i;

		while (i >= index)
		{
			price_low = m_history.Low(i);
			price_high = m_history.High(i);

			// begin check for reverse
			if (dir_long && price_low < m_values[bars - i - 2])
			{
				start = m_step;
				dir_long = false;
				ep = price_low;
				last_low = price_low;
				m_values[bars - 1 - i] = last_high;
				--i;
				continue;
			}
			if (!dir_long && price_high > m_values[bars - i - 2])
			{
				start = m_step;
				dir_long = true;
				ep = price_high;
				last_high = price_high;
				m_values[bars - 1 - i] = last_low;
				--i;
				continue;
			}
			// end check for reverse

			price = m_values[bars - i - 2];
			sar = price + start * (ep - price);
			if (dir_long)
			{
				if (ep < price_high && start + m_step <= m_maximum)
				{
					start += m_step;
				}

				if (price_high < m_history.High(i + 1) && i == bars - 2)
				{
					sar = m_values[bars - i - 2];
				}

				price = m_history.Low(i + 1);
				if (sar > price)
				{
					sar = price;
				}
				price = m_history.Low(i + 2);
				if (sar > price)
				{
					sar = price;
				}

				if (sar > price_low)
				{
					start = m_step;
					dir_long = false;
					ep = price_low;
					last_low = price_low;
					m_values[bars - 1 - i] = last_high;
					--i;
					continue;
				}

				if (ep < price_high)
				{
					last_high = price_high;
					ep = price_high;
				}
			}
			else
			{
				if (ep > price_low && start + m_step <= m_maximum)
				{
					start += m_step;
				}

				if (price_low < m_history.Low(i + 1) && i == bars - 2)
				{
					sar = m_values[bars - i - 2];
				}

				price = m_history.High(i + 1);
				if (sar < price)
				{
					sar = price;
				}
				price = m_history.High(i + 2);
				if (sar < price)
				{
					sar = price;
				}

				if (sar < price_high)
				{
					start = m_step;
					dir_long = true;
					ep = price_high;
					last_high = price_high;
					m_values[bars - 1 - i] = last_low;
					--i;
					continue;
				}

				if (ep > price_low)
				{
					last_low = price_low;
					ep = price_low;
				}
			}
		
			m_values[bars - 1 - i] = sar;
			--i;
		}

		m_last_calculated = bars - 1;
	}

	return m_values[bars - 1 - index];
}
