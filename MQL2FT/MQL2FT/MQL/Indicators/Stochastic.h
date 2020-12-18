#pragma once

#include "..\Enums.h"
#include "..\Enums.h"

#include "ExponentialMovingAverage.h"
#include "SimpleMovingAverage.h"
#include "SmoothedMovingAverage.h"
#include "WeightedMovingAverage.h"


class Stochastic final:	public Indicator
{
public:
	Stochastic(const std::string& symbol, const int timeframe, const int k_period, const int d_period,
		const int slowing, const ENUM_MA_METHOD ma_method, const ENUM_STO_PRICE price_field);

	virtual ~Stochastic();

	inline int getKPeriod() const;
	inline int getDPeriod() const;
	inline int getSlowing() const;
	inline ENUM_MA_METHOD getMaMethod() const;
	inline ENUM_STO_PRICE getPriceField() const;

	double getMainValue(const int index) const;
	double getSignalValue(const int index) const;

private:
	int m_k_period;
	int m_d_period;
	int m_slowing;
	ENUM_MA_METHOD m_ma_method;
	ENUM_STO_PRICE m_price_field;
	bool m_invalid_parameters;

	mutable int m_last_calculated;
	mutable std::vector<double> m_main_values;
	mutable std::vector<double> m_high_values;
	mutable std::vector<double> m_low_values;

	std::unique_ptr<MovingAverage> m_moving_average_indicator;

	void calculateValues() const;
};


inline int Stochastic::getKPeriod() const
{
	return m_k_period;
}

inline int Stochastic::getDPeriod() const
{
	return m_d_period;
}

inline int Stochastic::getSlowing() const
{
	return m_slowing;
}

inline ENUM_MA_METHOD Stochastic::getMaMethod() const
{
	return m_ma_method;
}

inline ENUM_STO_PRICE Stochastic::getPriceField() const
{
	return m_price_field;
}
