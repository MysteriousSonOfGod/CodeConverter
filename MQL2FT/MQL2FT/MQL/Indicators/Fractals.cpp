#include "../pch.h"

#include "Fractals.h"


Fractals::Fractals(const std::string& symbol, const int timeframe) :
	UpdatableIndicator{ symbol, timeframe},	m_last_calculated{ 0 }
{
}

Fractals::~Fractals()
{
}

void Fractals::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_upper_values.size() < bars || m_lower_values.size() < bars)
	{
		m_upper_values.resize(bars);
		m_lower_values.resize(bars);
	}

	if (m_last_calculated < 1 || bars < 5)
	{
		m_last_calculated = 5;
	}

	for (int i = m_last_calculated - 1, ri = bars - m_last_calculated; i < bars; ++i, --ri)
	{
		double high = m_history.High(ri + 2);

        if (high >= m_history.High(ri + 4) && high >= m_history.High(ri + 3) &&
            high > m_history.High(ri + 1) && high > m_history.High(ri))
        {
            m_upper_values[i - 2] = high;
        }

		double low = m_history.Low(ri + 2);

        if (low <= m_history.Low(ri + 4) && low <= m_history.Low(ri + 3) &&
            low < m_history.Low(ri + 1) && low < m_history.Low(ri))
        {
            m_lower_values[i - 2] = low;
        }
	}

	m_last_calculated = bars - 1;
}

double Fractals::getUpperValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

    return m_upper_values[bars - 1 - index];
}

double Fractals::getLowerValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_lower_values[bars - 1 - index];
}
