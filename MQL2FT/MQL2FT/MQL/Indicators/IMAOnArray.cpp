#include "../pch.h"
#include "IMAOnArray.h"

#include "../FTCore.h"

double iMAOnArray(const Array<double>& arr, int total, int ma_period, int ma_shift, int ma_method, int shift)
{
	if(ma_period <= 0)
	{
		return 0.0;
	}

	const int real_size = arr.Count();
	int size = real_size;

	if(total && total < size)
	{
		size = total;
	}

	const int tot_shift = ma_shift + shift;

	if(tot_shift < 0 || tot_shift >= size)
	{
		return 0.0;
	}

	const bool is_series = arr.GetIndexDirection();
	arr.SetIndexDirection(true);

	double sum = 0.0;
	double ma, a, res;
	int max = ma_period + tot_shift;
	int weight, limit;

	switch(ma_method)
	{
	case MODE_SMA:
	{
		if(max > size)
		{
			return 0.0;
		}

		for(int i = tot_shift; i < max; ++i)
		{
			sum += arr[i];
		}
		res = sum/(double)ma_period;
		break;
	}

	case MODE_EMA:
		max = real_size;
		a = 2.0/((double)ma_period + 1.0);
		ma = arr[max-1];
		limit = real_size - size + tot_shift;

		for(int i = max-2; i >= limit; --i)
		{
			ma = ma + a * (arr[i] - ma);
		}

		res = ma;
		break;

	case MODE_SMMA:
	{
		if(ma_period + tot_shift > size)
		{
			return 0.0;
		}

		for(int i = size-ma_period; i < size; ++i)
		{
			sum += arr[i];
		}

		ma = sum/ma_period;
		const double p = (double)ma_period;

		for(int i = size-ma_period-1; i >= tot_shift; --i)
		{
			ma = (ma * (p - 1.0) + arr[i])/p;
			//ma = ma + (arr[i] - ma)/(p + 1.0); >>> Optimised formula
		}

		res = ma;
		break;
	}

	// May be inaccuracy due to not counting all array from the end, if EMPTY_VALUE present in array.
	case MODE_LWMA:
		if(max > size)
		{
			return 0.0;
		}

		weight = (ma_period * (ma_period + 1))/2;

		for(int i = tot_shift, j = ma_period; i < max; ++i, --j)
		{
			sum += j * arr[i];
		}

		res = sum/(double)weight;
		break;

	default:
		res = 0.0;
		break;
	}

	arr.SetIndexDirection(is_series);

	return res;
}