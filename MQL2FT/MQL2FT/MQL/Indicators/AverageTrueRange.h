#pragma once

#include "UpdatableIndicator.h"


class AverageTrueRange final : public UpdatableIndicator
{
public:
	AverageTrueRange(const std::string& symbol, const int timeframe, const int period);

	virtual ~AverageTrueRange();

	double getValue(const int index) const;
	virtual void update() override;

	inline const int getPeriod() const;

private:
	int m_period;
	int m_last_calculated;

	std::vector<double> m_tr_values;
	std::vector<double> m_atr_values;
};


inline const int AverageTrueRange::getPeriod()const
{
	return m_period;
}
