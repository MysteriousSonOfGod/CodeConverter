#include "../pch.h"
#include "StandardDeviation.h"


StandardDeviation::StandardDeviation(const std::string& symbol, const int timeframe,
	const int price_type, const ENUM_MA_METHOD ma_method, std::weak_ptr<MovingAverage> moving_average) :
	UpdatableIndicator{ symbol, timeframe, price_type },
	m_last_calculated{ 0 }, m_ma_method{ ma_method }, m_moving_average{ moving_average }
{
}


StandardDeviation::~StandardDeviation()
{
}

void StandardDeviation::update()
{
	const int bars = m_history.Bars();

	if (bars < 1) return;

	if (m_deviation_values.size() < bars)
	{
		m_deviation_values.resize(bars); // Avoid removing already calculated values
	}

	for (int i = m_last_calculated; i < bars; ++i)
	{
		const double current_ma_value = m_moving_average.lock()->getValue(bars - 1 - i);
		const int ma_period = m_moving_average.lock()->getPeriod();
		double amount{};
		for (int j = 0; j < ma_period; j++)
		{
			double applied_price = m_history.AppliedPrice(bars - 1 - i + j);
			amount += std::pow(applied_price - current_ma_value, 2);
		}
		m_deviation_values[i] = sqrt(amount / ma_period);
	}

	m_last_calculated = bars - 1;
}

double StandardDeviation::getValue(const int index) const
{
	const int bars = m_history.Bars();

	if (bars < 1 || index < 0 || index >= bars) return 0.0;

	return m_deviation_values[bars - 1 - index];
}