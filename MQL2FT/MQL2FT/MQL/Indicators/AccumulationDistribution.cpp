#include "../pch.h"

#include "AccumulationDistribution.h"


AccumulationDistribution::AccumulationDistribution(const std::string& symbol, const int timeframe) :
	UpdatableIndicator{symbol, timeframe}, m_last_calculated { 0 }
{
}


AccumulationDistribution::~AccumulationDistribution()
{
}


void AccumulationDistribution::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_values.size() < bars)
	{
		m_values.resize(bars);
	}

	if (m_last_calculated < 1 || bars == 1)
	{
		const double price_close = m_history.Close(bars - 1);
		const double price_high = m_history.High(bars - 1);
		const double price_low = m_history.Low(bars - 1);
		const double volume = m_history.Volume(bars - 1);

		double div = (price_high - price_low);
		if (div != 0.0)
		{
			m_values[0] = (((price_close - price_low) - (price_high - price_close)) /
				(price_high - price_low)) * volume;
		}
		else
		{
			m_values[0] = ((price_close - price_low) - (price_high - price_close)) * volume;
		}
		m_last_calculated = 1;
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		const double price_close = m_history.Close(bars - 1 - i);
		const double price_high = m_history.High(bars - 1 - i);
		const double price_low = m_history.Low(bars - 1 - i);
		const double volume = m_history.Volume(bars - 1 - i);

		double div = (price_high - price_low);
		if (div != 0.0)
		{
			m_values[i] = (((price_close - price_low) - (price_high - price_close)) /
				(price_high - price_low)) * volume + m_values[i - 1];
		}
		else
		{
			m_values[i] = ((price_close - price_low) - (price_high - price_close)) * volume + m_values[i - 1];
		}
	}

	m_last_calculated = bars - 1;
}

double AccumulationDistribution::getValue(const int index)const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_values[bars - 1 - index];
}