#pragma once

#if defined ENABLE_HOOKING && __STRATEGY

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#else
#include "StrategyInterfaceUnit.h"
#endif

#include "Enums.h"
#include "MqlEnums.h"
#include "MqlString.h"

extern HWND ft4_main_wnd;
extern pExtTextOutW ft4_text_out_orig;
extern WNDPROC origWndProc;
extern HWND chart_wnd;

extern std::string _Symbol;
extern mql4::ENUM_TIMEFRAMES _Period;

extern bool chart_mmove;
extern bool chart_mmove_timeprice;

namespace mql4
{
	inline bool ChartSetInteger(long chart_id, int prop_id, long value)
	{
		if(prop_id == CHART_EVENT_MOUSE_MOVE)
		{
			chart_mmove = (bool)value;
			return true;
		}
		else if(prop_id == CHART_EVENT_MOUSE_MOVE_TIMEPRICE)
		{
			chart_mmove_timeprice = (bool)value;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void OnChartEvent(const int id, const long& lparam, const double& dparam, const mql4::string& sparam);
}

namespace ft
{
	HWND findMainWindow(const unsigned long process_id);

	double getMinChartPrice();
	double getMaxChartPrice();
	int getBarsPerChart();

	void prepareJumps();
	void setChartDimensions();
}

#endif