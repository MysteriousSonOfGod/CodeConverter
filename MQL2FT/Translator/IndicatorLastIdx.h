#pragma once
#include <string>

struct IndicatorLastIdx {

	std::string shift = "";
	int lastIndex;

	IndicatorLastIdx(int lastIdx, std::string& shift);
	~IndicatorLastIdx();
};