#include "IndicatorsLastIndices.h"

IndicatorsLastIndices::IndicatorsLastIndices()
{
	iMa = 0;
	iMaOnArray = 0;
	iMaCD = 0;
	iRSI = 0;
	iCCI = 0;
	iATR = 0;
}

IndicatorsLastIndices::~IndicatorsLastIndices()
{
}

int IndicatorsLastIndices::get(IndicatorType type)
{
	switch (type)
	{
	case I_IMA:
		return this->iMa;
	case I_MAONARRAY:
		return this->iMaOnArray;
	case I_MACD:
		return this->iMaCD;
	case I_RSI:
		return this->iRSI;
	case I_CCI:
		return this->iCCI;
	case I_ATR:
		return this->iATR;
	default:
		return -1;
	}
}

void IndicatorsLastIndices::set(IndicatorType type, int value)
{
	switch (type)
	{
	case I_IMA:
		this->iMa = value;
		return;
	case I_MAONARRAY:
		this->iMaOnArray = value;
		return;
	case I_MACD:
		this->iMaCD = value;
		return;
	case I_RSI:
		this->iRSI = value;
		return;
	case I_CCI:
		this->iCCI = value;
		return;
	case I_ATR:
		this->iATR = value;
		return;
	default:
		return;
	}
}

int IndicatorsLastIndices::increment(IndicatorType type)
{
	switch (type)
	{
	case I_IMA:
		return this->iMa++;
	case I_MAONARRAY:
		return this->iMaOnArray++;
	case I_MACD:
		return this->iMaCD++;
	case I_RSI:
		return this->iRSI++;
	case I_CCI:
		return this->iCCI++;
	case I_ATR:
		return this->iATR++;
	default:
		return -1;
	}
}
