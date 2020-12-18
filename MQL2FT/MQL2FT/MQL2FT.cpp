#include "MQL\pch.h"

#include "MQL2FT.h"
#include "MQL\FTCore.h"
#include "MQL\VersionChecker.h"
#include "MQL\Hook.h"

#pragma warning(disable : 4996) 

std::string _Symbol = "EURUSD";
int _Digits = 5;
double _Point = 1e-5;
mql4::ENUM_TIMEFRAMES _Period = PERIOD_M1;
int _UninitReason = REASON_REMOVE;
int ft_counted_bars_;
int g_number_of_bars_for_safe_testing = 100;

#ifdef __STRATEGY

std::string object_prefix_;
PChar mql2ft_strategy_symbol;


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void InitStrategy()
{
	// Version check block //////////////////
	int major = 0, minor = 0, rev = 0, build = 0;
	ftGetVersion(major, minor, rev, build);
	VersionCheckerParent* vc_parent = new VersionChecker(major, build);
	vc_parent->Check();
	delete vc_parent;
	// DLL must not work in FT3/FT2/FT1 /////

	// Set object prefix for this strategy
	if(object_prefix_.empty())
	{
		mql4::MathSrand(GetTickCount());
		for(int i = 0; i < 4; ++i)
		{
			object_prefix_.push_back(char(mql4::MathRand() % 25 + 65));
		}
		object_prefix_.push_back('_');
	}


#ifdef ENABLE_DEBUG_PRINTS
	Print(WindowExpertName(), " :: Executing init() on start");
    Print(WindowExpertName(), " :: N.B. First 100 bars will be skipped");
#endif

	AddSeparator("Testing");
	
	_Symbol = "EURUSD";
	_Digits = 5;
	_Point = 1e-5;
	_Period = PERIOD_H1;
	
	RegOption("Symbol", ot_Currency, &mql2ft_strategy_symbol);
	ReplaceStr(mql2ft_strategy_symbol, "EURUSD");

	_Period.GenerateExtern("Timeframe");

	RegOption("Bars to skip", ot_Integer, &g_number_of_bars_for_safe_testing);
	SetOptionRange("Bars to skip", 0.0, (double)0x7FFFFFFF);

	AddSeparator("Common");

	mql4::RegisterOptions();

#if defined(__INIT_INT) || defined (__INIT_VOID)
	mql4::init();
#elif defined(__INT_ON_INIT) || defined(__VOID_ON_INIT)
	mql4::OnInit();
#endif
}


//---------------------------------------------------------------------------
extern "C" __declspec( dllexport ) void DoneStrategy()
{
	bool unload = _UninitReason == REASON_REMOVE || _UninitReason == REASON_CLOSE;

#ifdef ENABLE_DEBUG_PRINTS
	if (unload)	Print("Executing deinit() on unload");
#endif
	
#if defined(__DEINIT_INT) || defined(__DEINIT_VOID)
	mql4::deinit();
#elif defined(__VOID_ON_DEINIT)
	mql4::OnDeinit(_UninitReason);
#endif
	if (unload) free(mql2ft_strategy_symbol);
	else _UninitReason = REASON_REMOVE;

	ft::ObjectDelete((char*)__comment__object_name.c_str());

	_close_files();
}


//---------------------------------------------------------------------------
extern "C" __declspec( dllexport ) void ResetStrategy()
{
#ifdef ENABLE_DEBUG_PRINTS
	Print("Executed ResetStrategy()");
	Print("Executing deinit() on parameters change");
#endif

    _UninitReason = REASON_PARAMETERS; // Input parameters have been changed by a user
    DoneStrategy();

#ifdef ENABLE_DEBUG_PRINTS
	Print("Executing init() on parameters change");
#endif

    SetCurrencyAndTimeframe(mql2ft_strategy_symbol, _Period);

    _Symbol = mql2ft_strategy_symbol;
    _Digits = Digits();
    _Point = Point();

#ifdef ENABLE_HOOKING
	ft::setChartDimensions();
#endif

    ft_counted_bars_ = 0;

#if defined(__INIT_INT) || defined (__INIT_VOID)
    mql4::init();
#elif defined(__INT_ON_INIT) || defined(__VOID_ON_INIT)
    mql4::OnInit();
#endif
}


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void GetSingleTick()
{
	if(Symbol() != mql2ft_strategy_symbol ||
		iBars(mql2ft_strategy_symbol, _Period) <= g_number_of_bars_for_safe_testing) return;

	SetCurrencyAndTimeframe(mql2ft_strategy_symbol, _Period);

	indicatorStorage.update();

#ifdef __ON_TICK
	mql4::OnTick();
#endif

#ifdef __INT_ON_CALCULATE

	int rates_total = Bars();

	static TimeSeries time_series;
	static OpenSeries open_series;
	static HighSeries high_series;
	static LowSeries low_series;
	static CloseSeries close_series;
	static TickVolumeSeries tick_volume_series;
	static VolumeSeries volume_series;
	static SpreadSeries spread_series;
	static int prev_calclated = 0;

	prev_calclated = OnCalculate(
		rates_total,
		prev_calclated,
		time_series,
		open_series,
		high_series,
		low_series,
		close_series,
		tick_volume_series,
		volume_series,
		spread_series);
#endif

#if defined(__START_INT) || defined(__START_VOID)
	mql4::start();
#endif
}

#endif

#ifdef __INDICATOR


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void Init()
{
	// Version check block //////////////////
	int major = 0, minor = 0, rev = 0, build = 0;
	ftGetVersion(major, minor, rev, build);
	VersionCheckerParent* vc_parent = new VersionChecker(major, build);
	vc_parent->Check();
	delete vc_parent;
	// DLL must not work in FT3/FT2/FT1 /////

#ifdef ENABLE_DEBUG_PRINTS
	Print("Executing Init");
#endif

	// enable Mql4 compatible mode 
	SetCalcModeMT4();

	AddSeparator("Common");
	
	mql4::RegisterOptions();

	_Symbol = Symbol();
	_Digits = Digits();
	_Point = Point();
	_Period = Timeframe();

//#ifdef ENABLE_HOOKING
//	ft::setChartDimensions();
//#endif

#if defined(__INIT_INT) || defined (__INIT_VOID)
	mql4::init();
#elif defined(__INT_ON_INIT) || defined(__VOID_ON_INIT)
	mql4::OnInit();
#endif
}


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void OnParamsChange()
{
#ifdef ENABLE_DEBUG_PRINTS
	Print("Executing OnParamsChange");
#endif

	_UninitReason = REASON_PARAMETERS;

#if defined(__DEINIT_INT) || defined(__DEINIT_VOID)
#ifdef ENABLE_DEBUG_PRINTS
	Print("Calling deinit() on params change");
#endif
	mql4::deinit();
#elif defined(__VOID_ON_DEINIT)
#ifdef ENABLE_DEBUG_PRINTS
	Print("Calling OnDeinit() on params change");
#endif
	mql4::OnDeinit(_UninitReason);
#endif

    ft_counted_bars_ = 0;

#if defined(__INIT_INT) || defined (__INIT_VOID)
#ifdef ENABLE_DEBUG_PRINTS
	Print("Calling init() on params change");
#endif
	mql4::init();
#elif defined(__INT_ON_INIT) || defined(__VOID_ON_INIT)
#ifdef ENABLE_DEBUG_PRINTS
	Print("Calling OnInit() on params change");
#endif
	mql4::OnInit();
#endif
}


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void Calculate(int index)
{
#ifdef ENABLE_DEBUG_PRINTS
	Print("Executing Calculate");
#endif
}

#ifdef __INT_ON_CALCULATE
#include "MQL\Series.h"
#endif

extern "C" __declspec(dllexport) void Start()
{
	indicatorStorage.update();

#ifdef __INT_ON_CALCULATE

	int rates_total = Bars();

	static mql4::TimeSeries time_series;
	static mql4::OpenSeries open_series;
	static mql4::HighSeries high_series;
	static mql4::LowSeries low_series;
	static mql4::CloseSeries close_series;
	static mql4::TickVolumeSeries tick_volume_series;
	static mql4::VolumeSeries volume_series;
	static mql4::SpreadSeries spread_series;
	static int prev_calclated = 0;

	prev_calclated = mql4::OnCalculate(
		rates_total,
		prev_calclated,
		time_series,
		open_series,
		high_series,
		low_series,
		close_series,
		tick_volume_series,
		volume_series,
		spread_series);
#endif
#if defined(__START_INT) || defined(__START_VOID)
	mql4::start();
#endif
	
	ft_counted_bars_ = Bars();
}


//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void Done() 
{
#ifdef ENABLE_DEBUG_PRINTS
	Print("Executing Done");
#endif

    _UninitReason = REASON_REMOVE;

#if defined(__DEINIT_INT) || defined(__DEINIT_VOID)
	mql4::deinit();
#elif defined(__VOID_ON_DEINIT)
	mql4::OnDeinit(_UninitReason);
#endif

	ft::ObjectDelete((char*)__comment__object_name.c_str());

	_close_files();
}


#endif
