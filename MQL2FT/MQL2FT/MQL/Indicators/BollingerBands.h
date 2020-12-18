#pragma once

#include "Indicator.h"
#include "SimpleMovingAverage.h"
#include "StandardDeviation.h"

class BollingerBands final :
	public Indicator
{
public:
	BollingerBands(const std::string& symbol, const int timeframe, const int price_type,
		std::weak_ptr<SimpleMovingAverage> sma_values, std::weak_ptr<StandardDeviation> deviation);

	virtual ~BollingerBands();

	inline int getPeriod() const;

	double getMainValue(const int index) const;
	double getDeviationValue(const double deviation, const int mode, const int index) const;
private:
	std::weak_ptr<SimpleMovingAverage> m_sma_values;
	std::weak_ptr<StandardDeviation> m_deviation;
};


inline int BollingerBands::getPeriod() const
{
	return m_sma_values.lock()->getPeriod();
}