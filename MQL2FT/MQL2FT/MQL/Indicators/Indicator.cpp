#include "../pch.h"

#include "Indicator.h"


Indicator::Indicator(const std::string& symbol, const int timeframe, const int price_type) :
	m_history{ symbol, timeframe, static_cast<ENUM_APPLIED_PRICE>(price_type) }
{
}

Indicator::Indicator(const std::vector<double>* const history_vector) :
	m_history{ history_vector }
{
}

Indicator::~Indicator()
{
}


const std::string& Indicator::getSymbol() const
{
	return m_history.Symbol();
}

int Indicator::getTimeframe() const
{
	return m_history.Timeframe();
}

int Indicator::getPriceType() const
{
	return m_history.PriceType();
}
