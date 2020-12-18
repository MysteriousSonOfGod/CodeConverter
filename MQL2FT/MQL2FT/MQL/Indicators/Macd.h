#pragma once

#include "ExponentialMovingAverage.h"
#include "UpdatableIndicator.h"



class Macd final : public UpdatableIndicator
{
public:
	Macd(const std::string& symbol, const int timeframe, const int price_type, const int short_period,
		const int long_period, const int signal_period, std::weak_ptr<ExponentialMovingAverage> ema_short_period,
		std::weak_ptr<ExponentialMovingAverage> ema_long_period);

	virtual ~Macd();

	inline int getShortPeriod() const;
	inline int getLongPeriod() const;
	inline int getSignalPeriod() const;

	double getMacd(const int index) const;
	double getSignal(const int index) const;
	virtual void update() override;

private:
	int m_short_period;
	int m_long_period;
	int m_signal_period;

	std::weak_ptr<ExponentialMovingAverage> m_ema_short;
	std::weak_ptr<ExponentialMovingAverage> m_ema_long;

	std::vector<double> m_macd_values;
	unsigned int m_last_calculated_macd;

	std::vector<double> m_signal_values;
	unsigned int m_last_calculated_signal;
};

inline int Macd::getShortPeriod() const
{
	return m_short_period;
}


inline int Macd::getLongPeriod() const
{
	return m_long_period;
}


inline int Macd::getSignalPeriod() const
{
	return m_signal_period;
}
