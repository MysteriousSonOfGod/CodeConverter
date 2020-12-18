#pragma once

#include "MovingAverage.h"


class WeightedMovingAverage final : public MovingAverage
{
public:
	WeightedMovingAverage(const std::string& symbol, const int timeframe, const int period, const int price_type);
	WeightedMovingAverage(const std::vector<double>* const history_vector, const int period);
	virtual ~WeightedMovingAverage();

	virtual double getValue(const int index) const override;
	virtual void update() override;
private:
	double m_factor;
	mutable double m_prevPriceSum;
};

