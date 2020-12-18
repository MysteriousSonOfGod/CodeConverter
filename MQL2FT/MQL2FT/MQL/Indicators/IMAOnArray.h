#pragma once

#include "../Array.h"
#include "../IndicatorInterfaceUnit.h"
#include "../Enums.h"

double iMAOnArray(const Array<double>& arr, int total, int ma_period, int ma_shift, int ma_method, int shift);