#pragma once

//#define CALCULATE_USING_AVAILABLE_DATA

#include "..\History.h"


class Indicator
{
public:
	Indicator(const std::string& symbol, const int timeframe, const int price_type = PRICE_CLOSE);
	Indicator(const std::vector<double>* const history_vector);

	virtual ~Indicator();

	const std::string& getSymbol() const;
	int getTimeframe() const;
	int getPriceType() const;

protected:
	History m_history;
};
