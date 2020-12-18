#pragma once

#if defined __INDICATOR && __INT_ON_CALCULATE

#include "datetime.h"
#include "IndicatorInterfaceUnit.h"

namespace mql4
{

	class Series
	{
	public:
		bool SetIndexDirection(bool direction) const { index_dir_ = direction; return true; }
		bool GetIndexDirection() const { return index_dir_; }
	protected:
		mutable bool index_dir_ = true;
		int GetIndex(int i) const { return index_dir_ ? i : Bars() - 1 - i; }
	};
	
	class TimeSeries : public Series
	{
	public:
		datetime operator[](int i) { return ft::Time(GetIndex(i)); }
	};

	class OpenSeries : public Series
	{
	public:
		double operator[](int i) { return Open(GetIndex(i)); }
	};

	class CloseSeries : public Series
	{
	public:
		double operator[](int i) { return Close(GetIndex(i)); }
	};


	class HighSeries : public Series
	{
	public:
		double operator[](int i) { return High(GetIndex(i)); }
	};

	class LowSeries : public Series
	{
	public:
		double operator[](int i) { return Low(GetIndex(i)); }
	};

	class VolumeSeries : public Series
	{
	public:
		double operator[](int i) { return 0.0; }
	};

	class TickVolumeSeries : public Series
	{
	public:
		double operator[](int i) { return Volume(GetIndex(i)); }
	};

	class SpreadSeries : public Series
	{
	public:
		double operator[](int i) { return 0.0; }
	};

}

#endif