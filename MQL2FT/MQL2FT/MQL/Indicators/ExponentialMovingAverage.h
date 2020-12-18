#pragma once

#include "MovingAverage.h"


class ExponentialMovingAverage final : public MovingAverage
{
public:
	ExponentialMovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type);
	ExponentialMovingAverage(const std::vector<double>* const history_vector, const int period);
	virtual ~ExponentialMovingAverage();

	virtual double getValue(const int index) const override;
	virtual void update() override;

private:
	double m_factor;
};

