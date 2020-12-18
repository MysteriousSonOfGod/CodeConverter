#pragma once

#include "..\Enums.h"
#include "MovingAverage.h"
#include "UpdatableIndicator.h"

class StandardDeviation final :
	public UpdatableIndicator
{
public:
	StandardDeviation(const std::string& symbol, const int timeframe, 
		const int price_type, const ENUM_MA_METHOD ma_method, std::weak_ptr<MovingAverage> moving_average);
	virtual ~StandardDeviation();

	inline int getPeriod() const;
	inline ENUM_MA_METHOD getMaMethod() const;

	double getValue(const int index) const;

	virtual void update() override;

private:
	int m_last_calculated;
	ENUM_MA_METHOD m_ma_method;
	std::weak_ptr<MovingAverage> m_moving_average;

	std::vector<double> m_deviation_values;
};


inline int StandardDeviation::getPeriod() const
{
	return m_moving_average.lock()->getPeriod();
}


inline ENUM_MA_METHOD StandardDeviation::getMaMethod() const
{
	return m_ma_method;
}