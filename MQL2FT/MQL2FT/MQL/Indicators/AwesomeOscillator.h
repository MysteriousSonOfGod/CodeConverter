#pragma once

#include "Indicator.h"
#include "SimpleMovingAverage.h"

class AwesomeOscillator final :
	public Indicator
{
public:
	AwesomeOscillator(const std::string& symbol, const int timeframe,
		std::weak_ptr<SimpleMovingAverage> sma_values_p5,
		std::weak_ptr<SimpleMovingAverage> sma_values_p34);

	virtual ~AwesomeOscillator();

	double getValue(const int index) const;

private:
	std::weak_ptr<SimpleMovingAverage> m_sma_values_p5;
	std::weak_ptr<SimpleMovingAverage> m_sma_values_p34;
};

