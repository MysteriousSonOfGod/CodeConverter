#pragma once

#include "UpdatableIndicator.h"

class RelativeVigorIndex final : public UpdatableIndicator
{
public:
	RelativeVigorIndex(const std::string& symbol, const int timeframe, const int period);
	virtual ~RelativeVigorIndex();

	inline int getPeriod() const;
	
	double getMainValue(const int index) const;
	double getSignalValue(const int index) const;

	virtual void update() override;

private:
	int m_period;
	int m_last_calculated_main;
	int m_last_calculated_signal;

	std::vector<double> m_main_values;
	std::vector<double> m_signal_values;

	inline double getMovingAverage(const int reversed_start_index);
	inline double getRangeAverage(const int reversed_start_index);
};


inline int RelativeVigorIndex::getPeriod() const
{
	return m_period;
}


inline double RelativeVigorIndex::getMovingAverage(const int reversed_start_index)
{
	return ((m_history.Close(reversed_start_index) - m_history.Open(reversed_start_index)) +
	       2.0 * (m_history.Close(reversed_start_index + 1) - m_history.Open(reversed_start_index + 1)) +
		   2.0 * (m_history.Close(reversed_start_index + 2) - m_history.Open(reversed_start_index + 2)) +
		   (m_history.Close(reversed_start_index + 3) - m_history.Open(reversed_start_index + 3))) / 6.0;
}


inline double RelativeVigorIndex::getRangeAverage(const int reversed_start_index)
{
	return ((m_history.High(reversed_start_index) - m_history.Low(reversed_start_index)) +
		   2.0 * (m_history.High(reversed_start_index + 1) - m_history.Low(reversed_start_index + 1)) +
		   2.0 * (m_history.High(reversed_start_index + 2) - m_history.Low(reversed_start_index + 2)) +
		   (m_history.High(reversed_start_index + 3) - m_history.Low(reversed_start_index + 3))) / 6.0;
}
