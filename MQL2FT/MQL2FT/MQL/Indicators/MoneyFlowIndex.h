#pragma once

#include "UpdatableIndicator.h"


class MoneyFlowIndex final : public UpdatableIndicator
{
public:
	MoneyFlowIndex(const std::string& symbol, const int timeframe, const int period);

	virtual ~MoneyFlowIndex();

	double getValue(const int index) const;
	virtual void update() override;

	inline const int getPeriod() const;

private:
	int m_period;
	int m_last_calculated;

	std::vector<double> m_values;

	double getNegativeMoneyFlow(const int reverse_index) const;
	double getPossitiveMoneyFlow(const int reverse_index) const;
};


inline const int MoneyFlowIndex::getPeriod()const
{
	return m_period;
}
