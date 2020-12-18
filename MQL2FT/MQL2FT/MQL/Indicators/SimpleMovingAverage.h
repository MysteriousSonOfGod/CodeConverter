#pragma once

#include "MovingAverage.h"


class SimpleMovingAverage final : public MovingAverage
{
public:
	SimpleMovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type);
	SimpleMovingAverage(const std::vector<double>* const history_vector, const int period);
	virtual ~SimpleMovingAverage();

	virtual double getValue(const int index) const override;
	virtual void update() override;
};

