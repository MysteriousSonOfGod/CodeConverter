#pragma once

#include "MovingAverage.h"


class SmoothedMovingAverage final : public MovingAverage
{
public:
	SmoothedMovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type);
	SmoothedMovingAverage(const std::vector<double>* const history_vector, const int period);
	virtual ~SmoothedMovingAverage();

	virtual double getValue(const int index) const override;
	virtual void update() override;
};

