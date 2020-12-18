#pragma once

#include "UpdatableIndicator.h"

class AverageDirectionalIndex final :
	public UpdatableIndicator
{
public:
	AverageDirectionalIndex(const std::string& symbol, const int timeframe, const int price_type, const int period);
	virtual ~AverageDirectionalIndex();

	double getMainValue(const int index) const;
	double getPlusDiValue(const int index) const;
	double getMinusDiValue(const int index) const;

	virtual void update() override;

	inline int getPeriod() const;
private:
	int m_period;
	double m_ema_factor;
	int m_last_calculated_main;

	std::vector<double> m_main_values;
	std::vector<double> m_minus_di_values;
	std::vector<double> m_plus_di_values;

	double getTrueRange(const double price_high, const double price_low, const double prev_applied_price) const;
};

inline int AverageDirectionalIndex::getPeriod() const
{
	return m_period;
}