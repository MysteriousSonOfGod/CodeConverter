#pragma once

#include "Indicator.h"

class UpdatableIndicator :
	public Indicator
{
public:
	UpdatableIndicator(const std::string& symbol, const int timeframe, const int price_type = PRICE_CLOSE);
	UpdatableIndicator(const std::vector<double>* const history_vector);

	virtual ~UpdatableIndicator();

	virtual void update() = 0;
};

