#include "../pch.h"

#include "CommodityChannelIndex.h"


CommodityChannelIndex::CommodityChannelIndex(const std::string& symbol, const int timeframe, const int price_type,
	const int period, std::weak_ptr<SimpleMovingAverage> sma_values) :
	UpdatableIndicator{ symbol,timeframe, price_type }, m_period{ period },
	m_factor{ 0.015 / m_period }, m_last_calculated{ 0 }, m_sma_values{ sma_values }
{
}

CommodityChannelIndex::~CommodityChannelIndex()
{
}

void CommodityChannelIndex::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_indicator_values.size() < bars || m_prices.size() < bars)
	{

		m_indicator_values.resize(bars);
		m_prices.resize(bars);
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		m_prices[i] = m_history.AppliedPrice(bars - 1 - i);
		const double current_sma = m_sma_values.lock()->getValue(bars - 1 - i);

		double sum = 0.0;
		if (i < m_period - 1)
		{
			for (const auto price : m_prices)
			{
				sum += fabs(current_sma - price);
			}
		}
		else
		{
			for (int k = 0; k < m_period; ++k)
			{
				sum += fabs(current_sma - m_prices[i - k]);
			}
		}

		if (sum != 0.0)
		{
			m_indicator_values[i] = (m_prices[i] - current_sma) / (sum * m_factor);
		}
		else m_indicator_values[i] = 0.0; //?????
	}

	m_last_calculated = bars - 1;
}

double CommodityChannelIndex::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const int reverse_index = bars - 1 - index;

	#ifdef CALCULATE_USING_AVAILABLE_DATA
		return m_indicator_values[reverse_index];
	#else
		if (reverse_index < m_period - 1)
		{
			return 0.0;
		}
		else
		{
			return m_indicator_values[reverse_index];
		}
	#endif // CALCULATE_USING_AVAILABLE_DATA
}
