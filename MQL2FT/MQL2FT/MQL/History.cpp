#include "pch.h"

#include "History.h"


extern "C" __declspec(dllexport) TInterfaceProcRec IntrfProcsRec;
extern mql4::ENUM_TIMEFRAMES _Period;


History::History() :
	m_history_vector{ nullptr }
{
	Setup(Symbol(), Timeframe());
}

History::History(const std::string& symbol, int timeframe, ENUM_APPLIED_PRICE applied_price) :
	m_history_vector{ nullptr }
{
	Setup(symbol, timeframe, applied_price);
}

History::History(const std::vector<double>* const history_vector) :
	m_symbol_c_str{ "" }, m_symbol{ "" }, m_timeframe{ 0 },
	m_applied_price{ PRICE_CLOSE }, m_history_vector{ history_vector }
{
	pBars = &History::f_hBars;
	pOpen = &History::f_hPrice;
	pHigh = &History::f_hPrice;
	pLow = &History::f_hPrice;
	pClose = &History::f_hPrice;
	pMedian = &History::f_hPrice;
	pTypical = &History::f_hPrice;
	pWeighted = &History::f_hPrice;
	pVolume = &History::f_hVolume;
	pAppliedPrice = &History::f_hPrice;
}

History::~History()
{
}


void History::Setup(const std::string& symbol, int timeframe, ENUM_APPLIED_PRICE applied_price)
{
	std::string current_chart_symbol = ::Symbol();
	int current_chart_timeframe = _Period;

	m_symbol = symbol.empty() ? current_chart_symbol : symbol;
	m_timeframe = timeframe == 0 ? current_chart_timeframe : timeframe;
	m_applied_price = applied_price;

	m_symbol_c_str = const_cast<char*>(m_symbol.c_str());

	if (m_symbol == current_chart_symbol && m_timeframe == current_chart_timeframe)
	{
		pBars = &History::f_Bars;
		pOpen = &History::f_Open;
		pHigh = &History::f_High;
		pLow = &History::f_Low;
		pClose = &History::f_Close;
		pMedian = &History::f_Median;
		pTypical = &History::f_Typical;
		pWeighted = &History::f_Weighted;
		pVolume = &History::f_Volume;

		switch (applied_price)
		{
		case PRICE_OPEN:
			pAppliedPrice = &History::f_Open;
			break;
		case PRICE_HIGH:
			pAppliedPrice = &History::f_High;
			break;
		case PRICE_LOW:
			pAppliedPrice = &History::f_Low;
			break;
		case PRICE_CLOSE:
			pAppliedPrice = &History::f_Close;
			break;
		case PRICE_MEDIAN:
			pAppliedPrice = &History::f_Median;
			break;
		case PRICE_TYPICAL:
			pAppliedPrice = &History::f_Typical;
			break;
		case PRICE_WEIGHTED:
			pAppliedPrice = &History::f_Weighted;
			break;
		default:
			pAppliedPrice = &History::f_Close;
			break;
		}
	}
	else
	{
		pBars = &History::f_iBars;
		pOpen = &History::f_iOpen;
		pHigh = &History::f_iHigh;
		pLow = &History::f_iLow;
		pClose = &History::f_iClose;
		pMedian = &History::f_iMedian;
		pTypical = &History::f_iTypical;
		pWeighted = &History::f_iWeighted;
		pVolume = &History::f_iVolume;

		switch (applied_price)
		{
		case PRICE_OPEN:
			pAppliedPrice = &History::f_iOpen;
			break;
		case PRICE_HIGH:
			pAppliedPrice = &History::f_iHigh;
			break;
		case PRICE_LOW:
			pAppliedPrice = &History::f_iLow;
			break;
		case PRICE_CLOSE:
			pAppliedPrice = &History::f_iClose;
			break;
		case PRICE_MEDIAN:
			pAppliedPrice = &History::f_iMedian;
			break;
		case PRICE_TYPICAL:
			pAppliedPrice = &History::f_iTypical;
			break;
		case PRICE_WEIGHTED:
			pAppliedPrice = &History::f_iWeighted;
			break;
		default:
			pAppliedPrice = &History::f_iClose;
			break;
		}
	}
}

int History::f_Bars() const
{
	return IntrfProcsRec.Bars(IntrfProcsRec.pBars);
}

double History::f_Open(int i) const
{
	return IntrfProcsRec.Open(IntrfProcsRec.pOpen, i);
}

double History::f_High(int i) const
{
	return IntrfProcsRec.High(IntrfProcsRec.pHigh, i);
}

double History::f_Low(int i) const
{
	return IntrfProcsRec.Low(IntrfProcsRec.pLow, i);
}

double History::f_Close(int i) const
{
	return IntrfProcsRec.Close(IntrfProcsRec.pClose, i);
}

double History::f_Median(int i) const
{
	return (IntrfProcsRec.High(IntrfProcsRec.pHigh, i) +
			IntrfProcsRec.Low(IntrfProcsRec.pLow, i)) / 2.0;
}

double History::f_Typical(int i) const
{
	return (IntrfProcsRec.High(IntrfProcsRec.pHigh, i) +
			IntrfProcsRec.Low(IntrfProcsRec.pLow, i) +
			IntrfProcsRec.Close(IntrfProcsRec.pClose, i)) / 3.0;
}

double History::f_Weighted(int i) const
{
	return (IntrfProcsRec.High(IntrfProcsRec.pHigh, i) +
			IntrfProcsRec.Low(IntrfProcsRec.pLow, i) +
			IntrfProcsRec.Close(IntrfProcsRec.pClose, i) * 2.0) / 4.0;
}

long History::f_Volume(int i) const
{
	return IntrfProcsRec.Volume(IntrfProcsRec.pVolume, i);
}

int History::f_iBars() const
{
	return IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, m_symbol_c_str, m_timeframe);
}

double History::f_iOpen(int i) const
{
	return IntrfProcsRec.iOpen(IntrfProcsRec.p_iOpen, m_symbol_c_str, m_timeframe, i);
}

double History::f_iHigh(int i) const
{
	return IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, m_symbol_c_str, m_timeframe, i);
}

double History::f_iLow(int i) const
{
	return IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, m_symbol_c_str, m_timeframe, i);
}

double History::f_iClose(int i) const
{
	return IntrfProcsRec.iClose(IntrfProcsRec.p_iClose, m_symbol_c_str, m_timeframe, i);
}

double History::f_iMedian(int i) const
{
	return (IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, m_symbol_c_str, m_timeframe, i) +
			IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, m_symbol_c_str, m_timeframe, i)) / 2.0;
}

double History::f_iTypical(int i) const
{
	return (IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, m_symbol_c_str, m_timeframe, i) +
			IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, m_symbol_c_str, m_timeframe, i) +
			IntrfProcsRec.iClose(IntrfProcsRec.p_iClose, m_symbol_c_str, m_timeframe, i)) / 3.0;
}

double History::f_iWeighted(int i) const
{
	return (IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, m_symbol_c_str, m_timeframe, i) +
			IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, m_symbol_c_str, m_timeframe, i) +
			IntrfProcsRec.iClose(IntrfProcsRec.p_iClose, m_symbol_c_str, m_timeframe, i) * 2.0) / 4.0;
}

long History::f_iVolume(int i) const
{
	return IntrfProcsRec.iVolume(IntrfProcsRec.p_iVolume, m_symbol_c_str, m_timeframe, i);
}

int History::f_hBars() const
{
	return m_history_vector ? m_history_vector->size() : 0;
}

double History::f_hPrice(int i) const
{
	double value;

	try
	{
		if (m_history_vector)
		{
			value = m_history_vector->at(m_history_vector->size() - 1 - i);
		}
		else value = 0.0;
	}
	catch (const std::out_of_range& e)
	{
		value = 0.0;
	}

	return value;
}
