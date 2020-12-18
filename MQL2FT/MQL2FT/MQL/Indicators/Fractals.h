#pragma once

#include "..\Enums.h"

#include "UpdatableIndicator.h"


class Fractals final: public UpdatableIndicator
{
public:
	Fractals(const std::string& symbol, const int timeframe);

	virtual ~Fractals();

	double getUpperValue(const int index) const;
	double getLowerValue(const int index) const;
	virtual void update() override;

private:
	int m_last_calculated;

	std::vector<double> m_upper_values;
	std::vector<double> m_lower_values;
};
