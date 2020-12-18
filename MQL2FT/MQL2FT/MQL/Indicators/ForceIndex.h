#pragma once

#include "..\Enums.h"

#include "SimpleMovingAverage.h"
#include "SmoothedMovingAverage.h"
#include "ExponentialMovingAverage.h"
#include "WeightedMovingAverage.h"


class ForceIndex final:
	public Indicator
{
public:
	ForceIndex(const std::string& symbol, const int timeframe, const int price_type,
		const ENUM_MA_METHOD ma_metod, const int period, std::weak_ptr<MovingAverage> moving_average_indicator);
	virtual ~ForceIndex();

	inline int getPeriod() const;
	inline ENUM_MA_METHOD getMaMethod() const;

	double getValue(const int index) const;
private:
	int m_period;
	ENUM_MA_METHOD m_ma_method;

	std::weak_ptr<MovingAverage> m_moving_average_indicator;
};

inline int ForceIndex::getPeriod() const
{
	return m_period;
}

inline ENUM_MA_METHOD ForceIndex::getMaMethod() const
{
	return m_ma_method;
}
