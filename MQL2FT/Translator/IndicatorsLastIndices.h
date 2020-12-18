#pragma once

#include "IndicatorType.h"

struct IndicatorsLastIndices
{
	int iMa;
	int iMaOnArray;
	int iMaCD;
	int iRSI;
	int iCCI;
	int iATR;

	IndicatorsLastIndices();
	~IndicatorsLastIndices();

	int get(IndicatorType type);
	void set(IndicatorType type, int value);
	int increment(IndicatorType type);
};

