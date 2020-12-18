#pragma once

#include "UpdatableIndicator.h"


class RelativeStrengthIndex final : public UpdatableIndicator
{
public:
	RelativeStrengthIndex(const std::string& symbol, const int timeframe, const int price_type, const int period);
	virtual ~RelativeStrengthIndex();

	double getValue(const int index) const;
	virtual void update() override;

	inline int getPeriod() const;

private:
	int m_period;

	unsigned int m_last_calculated;

	std::vector<double> m_price_diff;
	std::vector<double> m_possitive_sma_values;
	std::vector<double> m_negative_sma_values;
	std::vector<double> m_rsi_values;

	double getNegativeSma() const;
	double getPossitiveSma() const;
};

inline int RelativeStrengthIndex::getPeriod() const
{
	return m_period;
}
