#pragma once

#include "UpdatableIndicator.h"
#include "SimpleMovingAverage.h"


class CommodityChannelIndex final : public UpdatableIndicator
{
public:
	CommodityChannelIndex(const std::string& symbol, const int timeframe, const int price_type,
		const int period, std::weak_ptr<SimpleMovingAverage> sma_values);

	virtual ~CommodityChannelIndex();

	double getValue(const int index) const;
	virtual void update() override;

	inline const int getPeriod() const;

private:
	int m_period;
	double m_factor;
	int m_last_calculated;
	std::weak_ptr<SimpleMovingAverage> m_sma_values;

	std::vector<double> m_prices;
	std::vector<double> m_indicator_values;
};

inline const int CommodityChannelIndex::getPeriod() const
{
	return m_period;
}
