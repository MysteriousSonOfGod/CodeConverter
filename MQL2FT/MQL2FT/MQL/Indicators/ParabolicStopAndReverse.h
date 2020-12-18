#pragma once

#include "Indicator.h"

class ParabolicStopAndReverse final : public Indicator
{
public:
	ParabolicStopAndReverse(const std::string& symbol, const int timeframe, const double step, const double maximum);
	virtual ~ParabolicStopAndReverse();

	double getStep() const;
	double getMaximum() const;

	double getValue(const int index) const;

private:
	double m_step;
	double m_maximum;

	mutable int m_last_calculated;
	mutable std::vector<double> m_values;
};

inline double ParabolicStopAndReverse::getStep() const
{
	return m_step; 
}

inline double ParabolicStopAndReverse::getMaximum() const
{
	return m_maximum;
}
