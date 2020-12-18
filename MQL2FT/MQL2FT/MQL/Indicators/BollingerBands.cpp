#include "../pch.h"

#include "BollingerBands.h"


BollingerBands::BollingerBands(const std::string& symbol, const int timeframe, const int price_type,
	std::weak_ptr<SimpleMovingAverage> sma_values, std::weak_ptr<StandardDeviation> deviation) :
	Indicator { symbol, timeframe, price_type },
	m_sma_values { sma_values }, m_deviation { deviation }
{
}


BollingerBands::~BollingerBands()
{
}


double BollingerBands::getMainValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_sma_values.lock()->getValue(index);
}

double BollingerBands::getDeviationValue(const double deviation_factor, const int mode, const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	const double main_value = m_sma_values.lock()->getValue(index);
	const double deviation = m_deviation.lock()->getValue(index);

	switch (mode)
	{
		case 1:
			return main_value + deviation_factor * deviation;

		case 2:
			return main_value - deviation_factor * deviation;

		default:
			return 0.0;
	}
}