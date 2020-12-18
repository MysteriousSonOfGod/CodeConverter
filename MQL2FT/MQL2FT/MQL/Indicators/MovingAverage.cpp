#include "../pch.h"

#include "MovingAverage.h"


MovingAverage::MovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type) :
	UpdatableIndicator{ symbol, timeframe, price_type }, m_period{ period }, m_last_calculated{ 0 }
{
}

MovingAverage::MovingAverage(const std::vector<double>* const history_vector, const int period) :
	UpdatableIndicator{ history_vector }, m_period{ period }, m_last_calculated{ 0 }
{
}

MovingAverage::~MovingAverage()
{
}
