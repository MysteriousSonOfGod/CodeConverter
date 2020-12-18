#pragma once

#include "..\Enums.h"

#include "Indicator.h"
#include "MovingAverage.h"


class Envelopes final:
	public Indicator
{
public:
	Envelopes(const std::string& symbol, const int timeframe, const int price_type,
		const ENUM_MA_METHOD ma_method, const int period,
		std::weak_ptr<MovingAverage> moving_average_indicator);

	virtual ~Envelopes();

	inline int getPeriod() const;
	inline ENUM_MA_METHOD getMaMethod() const;

	double getUpperBand(const int index, const double deviation) const;
	double getLowerBand(const int index, const double deviation) const;

private:
	int m_period;
	ENUM_MA_METHOD m_ma_method;

	std::weak_ptr<MovingAverage> m_moving_average_indicator;
};


inline int Envelopes::getPeriod() const
{
	return m_period;
}

inline ENUM_MA_METHOD Envelopes::getMaMethod() const
{
	return m_ma_method;
}

