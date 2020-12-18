#pragma once

#include "UpdatableIndicator.h"

class AccumulationDistribution :
	public UpdatableIndicator
{
public:
	AccumulationDistribution(const std::string& symbol, const int timeframe);
	virtual ~AccumulationDistribution();

	double getValue(const int index)const;
	virtual void update() override;

private:
	std::vector<double> m_values;
	int m_last_calculated;
};

