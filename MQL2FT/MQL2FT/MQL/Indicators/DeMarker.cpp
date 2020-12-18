#include "../pch.h"

#include "DeMarker.h"


DeMarker::DeMarker(const std::string& symbol, const int timeframe, const int period) :
	Indicator(symbol, timeframe, period), m_period(period), m_last_calculated(0)
{
	m_sma_demax = std::unique_ptr<SimpleMovingAverage>(new SimpleMovingAverage(&m_demax, period));
	m_sma_demin = std::unique_ptr<SimpleMovingAverage>(new SimpleMovingAverage(&m_demin, period));
}

double DeMarker::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if(bars < 1 || index < 0 || index >= bars) return 0.0;

	if(m_val.size() < bars)
	{
		m_val.resize(bars);
		m_demax.resize(bars);
		m_demin.resize(bars);
	}

	const int ri = bars - 1 - index;

	if(ri < m_period)
	{
		return 0.0;
	}

	for(int i = m_last_calculated; i < bars; ++i)
	{
		const double h = m_history.High(bars-i-1);
		const double prev_h = m_history.High(bars-i);
		const double l = m_history.Low(bars-i-1);
		const double prev_l = m_history.Low(bars-i);
		
		m_demax[i] = h > prev_h ? h - prev_h : 0.0; // Error migh be here due to first bar's previous bar diff vlas in mql ft
		m_demin[i] = l < prev_l ? prev_l - l : 0.0;
	}

	for(int i = m_last_calculated; i < bars; ++i)
	{
		m_sma_demax->update();
		m_sma_demin->update();
		const double sma_demax = m_sma_demax->getValue(bars-i-1);
		m_val[i] = sma_demax/(sma_demax + m_sma_demin->getValue(bars-i-1));
	}

	m_last_calculated = bars - 1;

	return m_val[ri];
}