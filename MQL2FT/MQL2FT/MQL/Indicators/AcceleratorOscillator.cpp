#include "../pch.h"

#include "AcceleratorOscillator.h"


AcceleratorOscillator::AcceleratorOscillator(const std::string& symbol, const int timeframe,
	std::weak_ptr<AwesomeOscillator> ao) :
	Indicator(symbol, timeframe),
	m_ao(ao)
{}

double AcceleratorOscillator::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if(bars < 1 || index < 0 || index >= bars) return 0.0;

	const int ri = bars - 1 - index;

	if(ri < 38)
	{
		return 0.0;
	}
	else
	{
		double sum = 0.0;
		for(int i = 0; i < 5; ++i)
		{
			sum += m_ao.lock()->getValue(index + i);
		}

		return m_ao.lock()->getValue(index) - sum/5.0;
	}
}