#pragma once

#include "UpdatableIndicator.h"


class IchimokuKinkoHyo final : public UpdatableIndicator
{
public:
	IchimokuKinkoHyo(const std::string& symbol, const int timeframe, const int tenkan_sen_period,
        const int kijun_sen_period, const int senkou_span_period);
	virtual ~IchimokuKinkoHyo();

	double getTenkanSenValue(const int index) const;
	double getKijunSenValue(const int index) const;
	double getChinkouSpanValue(const int index) const;
	double getSenkouSpanAValue(const int index) const;
	double getSenkouSpanBValue(const int index) const;

	virtual void update() override;

	inline int getTenkanSenPeriod() const;
	inline int getKijunSenPeriod() const;
	inline int getSenkouSpanPeriod() const;

private:
	int m_tenkan_sen_period, m_kijun_sen_period, m_senkou_span_period;

	unsigned int m_last_calculated;

	std::vector<double> m_tenkan_sen_values;
	std::vector<double> m_kijun_sen_values;
	std::vector<double> m_senkou_span_a_values;
	std::vector<double> m_senkou_span_b_values;

	double HighestLowestAverage(const int bars, int reverse_index, const int period) const;
};

inline int IchimokuKinkoHyo::getTenkanSenPeriod() const
{
	return m_tenkan_sen_period;
}

inline int IchimokuKinkoHyo::getKijunSenPeriod() const
{
	return m_kijun_sen_period;
}

inline int IchimokuKinkoHyo::getSenkouSpanPeriod() const
{
	return m_senkou_span_period;
}
