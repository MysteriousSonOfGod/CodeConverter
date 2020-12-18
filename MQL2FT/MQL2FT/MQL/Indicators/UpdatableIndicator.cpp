#include "../pch.h"
#include "UpdatableIndicator.h"


UpdatableIndicator::UpdatableIndicator(const std::string& symbol, const int timeframe, const int price_type) :
	Indicator{ symbol, timeframe, price_type}
{
}

UpdatableIndicator::UpdatableIndicator(const std::vector<double>* const history_vector) :
	Indicator{ history_vector }
{
}


UpdatableIndicator::~UpdatableIndicator()
{
}
