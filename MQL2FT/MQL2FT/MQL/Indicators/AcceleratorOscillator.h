#pragma once

#include "Indicator.h"
#include "AwesomeOscillator.h"

class AcceleratorOscillator final :
	public Indicator
{
public:
	AcceleratorOscillator(const std::string& symbol, const int timeframe,
		std::weak_ptr<AwesomeOscillator> ao);

	virtual ~AcceleratorOscillator() = default;

	double getValue(const int index) const;

private:
	std::weak_ptr<AwesomeOscillator> m_ao;
};