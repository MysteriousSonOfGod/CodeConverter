#pragma once

#include "Indicator.h"

class OnBalanceVolume :
	public Indicator
{
public:
	OnBalanceVolume(const std::string& symbol, const int timeframe, const int price_type);
	virtual ~OnBalanceVolume();

	double getValue(const int index) const;

private:
	mutable int m_last_calculated;
	mutable std::vector<double> m_values;
};

