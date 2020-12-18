#pragma once

#include <sys\stat.h>

#include "Array.h"
#include "color.h"
#include "datetime.h"
#include "Enums.h"
#include "MqlEnums.h"
#include "FileData.h"
#include "GlobalVariablesStore.h"
#include "Indicators/IndicatorStorage.h"
#include "Indicators/IMAOnArray.h"
#include "MqlString.h"
#include "TechnicalFunctions.h"
#include "MqlObjects.h"
#include "StringFormat.h"
#include "Hook.h"

#ifdef __STRATEGY
#include "StrategyInterfaceUnit.h"
#endif // _STRATEGY

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#include "PropertyStyle.h"

#define MODE_BID 9
#define MODE_ASK 10

#endif // _INDICATOR

#pragma warning(disable : 4996)

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulong;
typedef unsigned char uchar;
typedef long long mqllong;

#define True true
#define False false
#undef PlaySound

#ifndef _MATH_DEFINES_DEFINED
	#define _MATH_DEFINES_DEFINED

	#define M_E        2.71828182845904523536   // e
	#define M_LOG2E    1.44269504088896340736   // log2(e)
	#define M_LOG10E   0.434294481903251827651  // log10(e)
	#define M_LN2      0.693147180559945309417  // ln(2)
	#define M_LN10     2.30258509299404568402   // ln(10)
	#define M_PI       3.14159265358979323846   // pi
	#define M_PI_2     1.57079632679489661923   // pi/2
	#define M_PI_4     0.785398163397448309616  // pi/4
	#define M_1_PI     0.318309886183790671538  // 1/pi
	#define M_2_PI     0.636619772367581343076  // 2/pi
	#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
	#define M_SQRT2    1.41421356237309504880   // sqrt(2)
	#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#endif


using std::string;
using std::stringstream;
using std::ostringstream;
using std::vector;
using std::map;
using std::min;


const int INVALID_HANDLE = -1;
const int EMPTY = -1;
const int EMPTY_VALUE = 0x7FFFFFFF;
const int CHARTS_MAX = 100;
const int WRONG_VALUE = -1;

const int REASON_PROGRAM = 0;
const int REASON_REMOVE = 1;
const int REASON_RECOMPILE = 2;
const int REASON_CHARTCHANGE = 3;
const int REASON_CHARTCLOSE = 4;
const int REASON_PARAMETERS = 5;
const int REASON_ACCOUNT = 6;
const int REASON_TEMPLATE = 7;
const int REASON_INITFAILED = 8;
const int REASON_CLOSE = 9;

const int CHAR_VALUE = 1;
const int SHORT_VALUE = 2;
const int INT_VALUE = 4;
const int LONG_VALUE = 4;
const int FLOAT_VALUE = 4;
const int DOUBLE_VALUE = 8;

extern map<int, FileData*> files;
extern int _last_file_handle;

extern std::string _Symbol;
extern int _Digits;
extern double _Point;
extern mql4::ENUM_TIMEFRAMES _Period;
extern int _UninitReason;
extern int _LastError;
extern int ft_counted_bars_;
extern unsigned int _RandomSeed;

const std::string __comment__object_name = "__comment__function_text_object";

namespace mql4
{

#ifdef __INIT_INT
	int init();
#endif
#ifdef __INIT_VOID
	void init();
#endif
#ifdef __INT_ON_INIT
	int OnInit();
#endif
#ifdef __VOID_ON_INIT
	void OnInit();
#endif
#ifdef __INIT_UNDEFINED
	void init();
#endif

#ifdef __DEINIT_INT
	int deinit();
#endif
#ifdef __DEINIT_VOID
	void deinit();
#endif
#ifdef __VOID_ON_DEINIT
	void OnDeinit(const int reason);
#endif
#ifdef __DEINIT_UNDEFINED
	void deinit();
#endif

#ifdef __START_INT
	int start();
#endif
#ifdef __START_VOID
	void start();
#endif

#ifdef __STRATEGY
#ifdef __ON_TICK
	void OnTick();
#endif
#endif // __STRATEGY

#ifdef __START_UNDEFINED
	void start();
#endif

#ifdef __ON_TIMER
	void OnTimer();
#endif
}

bool ftCheckVersion(float& f1, float& f2, int& ver);

inline mql4::string getSymbol(const mql4::string& symbol)
{
	return symbol.empty() || symbol == "0" ? _Symbol : (std::string)symbol;
}

inline int getTf(int tf) { return tf ? tf : (int)_Period; }

#ifdef __STRATEGY

void StrategyShortName(const mql4::string& name);

int OrderSend(
	const mql4::string&   symbol,                // symbol
	int                   cmd,                   // operation
	double                volume,                // volume
	double                price,                 // price
	int                   slippage,              // slippage
	double                stoploss,              // stop loss
	double                takeprofit,            // take profit
	const mql4::string&   comment = "",          // comment
	int                   magic = 0,             // magic number
	datetime              expiration = 0,        // pending order expiration
	color                 arrow_color = clrNONE  // color
);

bool  OrderClose(
	int        ticket,					// ticket
	double     lots,					// volume
	double     price,					// close price
	int        slippage,				// slippage
	color      arrow_color = clrNONE    // color
);

bool OrderCloseBy(int ticket, int opposite, color Color = CLR_NONE);

bool  OrderDelete(
	int        ticket,					// ticket
	color      arrow_color = clrNONE    // color
);

bool  OrderModify(
	int        ticket,					// ticket
	double     price,					// price
	double     stoploss,				// stop loss
	double     takeprofit,				// take profit
	datetime   expiration = 0,				// expiration
	color      arrow_color = clrNONE    // color
);

double OrderCommission();

inline int OrdersHistoryTotal() { return HistoryTotal(); }

datetime  OrderOpenTime();

datetime  OrderCloseTime();

datetime OrderExpiration();

inline void ExpertRemove() { Pause("ExpertRemove function called"); }

inline mql4::string OrderComment() { return mql4::string(ft::OrderComment()); }

void OrderPrint();

#endif // __STRATEGY

inline mqllong ChartID() { return -1; }

inline datetime CurTime() { return datetime::FromVariantTime(ft::TimeCurrent()); }

inline datetime TimeCurrent() { return datetime::FromVariantTime(ft::TimeCurrent()); }

#ifdef __STRATEGY
inline int Timeframe() { return _Period; }
#endif

// IFunctions

inline double  iOpen(const mql4::string& symbol, int timeframe, int shift) { return ft::iOpen((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift); }

inline double iClose(const mql4::string& symbol, int timeframe, int shift) { return ft::iClose((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift); }

inline double iHigh(const mql4::string& symbol, int timeframe, int shift) { return ft::iHigh((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift); }

inline double iLow(const mql4::string& symbol, int timeframe, int shift) { return ft::iLow((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift); }

inline mqllong iVolume(const mql4::string& symbol, int timeframe, int shift) { return ft::iVolume((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift); }

inline datetime iTime(const mql4::string& symbol, int timeframe, int shift) { return datetime::FromVariantTime(ft::iTime((char*)getSymbol(symbol).c_str(), getTf(timeframe), shift)); }

inline datetime Time(int index) { return datetime::FromVariantTime(ft::Time(index)); }

inline int iBars(const mql4::string& symbol, int timeframe) { return ft::iBars(getSymbol(symbol), getTf(timeframe)); }

inline int iBarShift(const mql4::string& symbol, int timeframe, const datetime& time, bool exact = false) { return ft::iBarShift(getSymbol(symbol), getTf(timeframe), time.ToDelphiTime(), exact); }

inline int iLowest(const mql4::string& Symbol, int TimeFrame, int _type, int count = WHOLE_ARRAY, int index = 0) { return ft::iLowest(getSymbol(Symbol), getTf(TimeFrame), _type, count, index); }

inline int iHighest(const mql4::string& Symbol, int TimeFrame, int _type, int count = WHOLE_ARRAY, int index = 0) { return ft::iHighest(getSymbol(Symbol), getTf(TimeFrame), _type, count, index); }

inline int Lowest(const mql4::string& Symbol, int TimeFrame, int _type, int count = WHOLE_ARRAY, int index = 0) { return iLowest(Symbol, getTf(TimeFrame), _type, count, index); }

inline int Highest(const mql4::string& Symbol, int TimeFrame, int _type, int count = WHOLE_ARRAY, int index = 0) { return iHighest(Symbol, getTf(TimeFrame), _type, count, index); }

// End of iFunctions

#ifdef __INDICATOR
inline void SetIndexLabel(int index, const mql4::string& text)
{ 
	// FT bug temporial workaround, first buffer among buffers with same name has same color as last buffer
	static std::list<mql4::string> indx_n;

	int found = 0;
	for(std::list<mql4::string>::iterator it = indx_n.begin(); it != indx_n.end(); ++it)
	{
		if(*it == text)
		{
			++found;
		}
	}

	std::string tmp(text);

	if(!found)
	{
		indx_n.push_back(text);
	}
	else
	{
		for(int i = 0; i < found; ++i)
		{
			tmp.push_back(' ');
		}
		indx_n.push_back(text);
	}
	
	ft::SetIndexLabel(index, tmp);
}
inline void IndicatorShortName(const mql4::string& name) { ft::IndicatorShortName(name); }
#endif

double  AccountBalance();

double  AccountEquity();

double MarketInfo(
	const mql4::string& symbol,     // symbol
	int                type        // information type
);

double  SymbolInfoDouble(
	const mql4::string&           name,
	ENUM_SYMBOL_INFO_DOUBLE prop_id
);

bool  SymbolInfoDouble(
	const mql4::string&            name,
	ENUM_SYMBOL_INFO_DOUBLE  prop_id,
	double&                  double_var
);

mqllong  SymbolInfoInteger(
	const mql4::string&             name,
	ENUM_SYMBOL_INFO_INTEGER  prop_id
);

bool  SymbolInfoInteger(
	const mql4::string&             name,
	ENUM_SYMBOL_INFO_INTEGER  prop_id,
	mqllong&                     mqllong_var
);

int MessageBox(const mql4::string& text, const mql4::string& caption = "", int flags = 0);

extern IndicatorStorage indicatorStorage;

#ifdef __INDICATOR

extern map<int, PropertyStyle*> __property_styles;

#ifdef __INT_ON_CALCULATE

#include "Series.h"

namespace mql4
{

int OnCalculate(const int rates_total,  // size of input time series
	const int prev_calculated,			// bars handled in previous call
	TimeSeries& time,					// Time
	OpenSeries& open,					// Open
	HighSeries& high,					// High
	LowSeries& low,						// Low
	CloseSeries& close,			        // Close
	TickVolumeSeries& tick_volume,		// Tick Volume
	VolumeSeries& volume,	            // Real Volume
	SpreadSeries& spread                // Spread
);

}

#endif

bool  SetIndexBuffer(
	int                    index,        // buffer index
	const IndexBuffer&  container    // buffer container
);

bool  SetIndexBuffer(
	int                    index,        // buffer index
	const IndexBuffer&  container,    // buffer container
	ENUM_INDEXBUFFER_TYPE  data_type
);

void  SetIndexStyle(
	int     index,			// line number
	int     type,			// type
	int     style = EMPTY,	// line style
	int     width = EMPTY,	// line width
	const color& clr = clrNONE	// color
);

void  SetIndexArrow(
	int     index,       // line number
	int     code         // symbol code
);

void  SetLevelValue(
	int     level,       // level
	double  value        // value
);

void  SetLevelStyle(
	int     draw_style,       // line style
	int     line_width,       // width
	const color& clr=CLR_NONE // color
);

void  SetIndexEmptyValue(
	int     index,       // line index
	double  value        // new value
);

void  SetIndexShift(
	int     index,       // line index
	int     shift        // shift
);

void  SetIndexDrawBegin(
	int     index,       // line index
	int     begin        // position
);

inline int IndicatorCounted() { return ft_counted_bars_ ? ft_counted_bars_-1 : 0; }

int WindowFind(const mql4::string& name);

void  ArrayFill(IndexBuffer& arr, int start, int count, double value);

#endif // __INDICATOR

// Moving Average
double iMA(const mql4::string& symbol, int timeframe, int ma_period, int ma_shift, int ma_method, int applied_price, int shift);

// Average True Range indicator
double iATR(const mql4::string& symbol, int timeframe, int period, int shift);

double iCCI( const mql4::string& symbol, int timeframe, int period, int applied_price, int shift);

// Moving Averages Convergence/Divergence indicator
double iMACD(const mql4::string& symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period, int applied_price, int mode, int shift);

double iOsMA(const mql4::string& symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period, int applied_price, int shift);

double iRSI(const mql4::string& symbol, int timeframe, int period, int priceType, int shift);

double iAO(const mql4::string& symbol, int timeframe, int shift);

double iBearsPower(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift);

double iBullsPower(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift);

double iForce(const mql4::string& symbol, int timeframe, int period, int ma_method, int applied_price, int shift);

double iMomentum(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift);

double iOBV(const mql4::string& symbol, int timeframe, int applied_price, int shift);

double iEnvelopes(const mql4::string& symbol, int timeframe, int ma_period, int ma_method,
	int ma_shift, int applied_price,double deviation, int mode, int shift);

double iAD(const mql4::string& symbol, int timeframe, int shift);

double iMFI(const mql4::string& symbol, int timeframe, int period, int shift);

double iStochastic(const mql4::string& symbol, int timeframe, int k_period, int d_period, int slowing,
	int ma_method, int price_field, int mode, int shift);

double iStdDev(const mql4::string& symbol, int timeframe, int ma_period, int ma_shift, int ma_method,
	int applied_price, int shift);

double iSAR(const mql4::string& symbol, int timeframe, double step, double maximum, int shift);

double iBands(const mql4::string& symbol, int timeframe, const int period, const double deviation,
	const int bands_shift, const int price_type, const int mode, int index);

double iAC(const mql4::string& symbol, int timeframe, int shift);

double iDeMarker(const mql4::string& symbol, int timeframe, int period, int shift);

double iWPR(const mql4::string& symbol, int timeframe, int period, int shift);

double iADX(const mql4::string& symbol, int timeframe, int period, int applied_price, int mode, int shift);

double iRVI(const mql4::string& symbol, int timeframe, int period, int mode, int shift);

double iIchimoku(const mql4::string& symbol, int timeframe, int tenkan_sen, int kijun_sen, int senkou_span_b,
	int mode, int shift);

double iFractals(const mql4::string& symbol, int timeframe, int mode, int shift);

mql4::string  DoubleToStr(
	double  value,     // value
	int     digits = 8 // precision
);

mql4::string  DoubleToString(
	double  value,     // number
	int     digits = 8 // number of digits after decimal point
);

mql4::string  IntegerToString(
	mqllong    number,              // number
	int     str_len = 0,           // length of result string
	ushort  fill_symbol = ' '      // filler
);

int  StrToInteger(
	const mql4::string&  value      // string
);

mqllong  StringToInteger(
	const mql4::string&  value      // string
);

double  StrToDouble(
	const mql4::string&  value      // value
);

double  StringToDouble(
	const mql4::string&  value      // string
);

mql4::string  TimeToStr(
	const datetime&  value,                           // value
	int       mode = TIME_DATE | TIME_MINUTES      // format
);

mql4::string  TimeToString(
	const datetime&  value,                           // value
	int       mode = TIME_DATE | TIME_MINUTES      // format
);

datetime  StrToTime(
	const mql4::string&  value      // string
);

datetime  StringToTime(
	const mql4::string&  value      // date string
);

mql4::string  CharToStr(
	uchar  char_code     // ASCII-code
);

inline mql4::string  CharToString(
	uchar  char_code     // ASCII-code
)
{
	return CharToStr(char_code);
}

int  StringToCharArray(
	const mql4::string&  text_string,       // source string
	Array<uchar>&        array,             // array
	int                  start = 0,         // starting position in the array
	int                  count = -1,        // number of symbols
	uint                 codepage = CP_ACP  // code page
);

mql4::string  CharArrayToString(
	Array<uchar>&  array,          // array
	int    start = 0,              // starting position in the array
	int    count = -1,             // number of symbols
	uint   codepage = CP_ACP       // code page
);

int  TimeDay(
	const datetime&      date            // date and time
);

int  TimeHour(
	const datetime&      date            // date and time
);

int  TimeDayOfWeek(
	const datetime&      date            // date and time
);

int TimeDayOfYear(
	const datetime&      date
);

int  TimeMonth(
	const datetime&      date            // date and time
);

int  TimeMinute(
	const datetime&      date            // date and time
);

int  TimeYear(
	const datetime&      date            // date and time
);

int  TimeSeconds(
	const datetime&      date            // date and time
);

mql4::string WindowExpertName();

inline int WindowOnDropped() { return 0; }

namespace mql4
{
	int GetLastError();
}

void  ResetLastError();

void SetLastError(int err_code);

namespace mql4
{
	inline void Sleep(int milliseconds) {}
}

double  NormalizeDouble(
	double  value,      // normalized number
	int     digits      // number of digits after decimal point
);

mql4::string EnumToString(const mql4::MqlEnum& enume);
mql4::string EnumToString(int enume);

bool RefreshRates();

namespace mql4
{
	inline bool PlaySound(const mql4::string& filename) { return true; }
}

inline bool IsDemo() { return false; }

inline bool IsTradeAllowed() { return true; }

inline bool IsTradeAllowed(const mql4::string& symbol, datetime tested_time) { return true; }

inline bool IsLibrariesAllowed() { return true; }

inline bool IsTesting() { return false; }

inline bool IsTradeContextBusy() { return false; }

inline bool IsConnected() { return true; }

inline bool IsStopped() { return false; }

inline bool IsVisualMode() { return false; }

inline bool IsOptimization() { return false; }

inline bool IsDllsAllowed() { return false; }

inline mql4::string AccountServer() { return "www.forextester.com"; }

inline mql4::string ServerAddress() { return "www.forextester.com"; }

inline mql4::string AccountCurrency() { return "USD"; }

inline int AccountNumber() { return 42; }

inline int AccountCredit() { return 0.0; }

inline int AccountStopoutLevel() { return 0.0; }

inline double AccountFreeMarginMode() { return 0.0; }

inline int AccountStopoutMode() { return 0.0; }

inline mql4::string AccountName() { return "ForexTester Account"; }

inline mql4::string AccountCompany() { return "Forex Tester Software"; }

inline bool SendFTP(const mql4::string& filename, const mql4::string& ftp_path = "") { SetLastError(4059); return false; }

inline bool SendNotification(const mql4::string& text) { SetLastError(4059); return false; }

inline bool SendMail(const mql4::string& subject, const mql4::string& some_text) { SetLastError(4059); return false; }

inline bool  IsExpertEnabled() { return true; }

inline mql4::ENUM_TIMEFRAMES ChartPeriod(long chart_id = 0) { return chart_id ? PERIOD_CURRENT : _Period; }

mql4::string  TerminalInfoString(int property_id);

mql4::string  AccountInfoString(int property_id);

mqllong  AccountInfoInteger(int property_id);

double AccountInfoDouble(int property_id);

double AccountFreeMarginCheck(
	const mql4::string& symbol,
    int           cmd,
    double        volume
);

#ifdef __INDICATOR

int WindowFirstVisibleBar();

#endif

int  WindowBarsPerChart();
double WindowPriceMax(int index = 0);
double WindowPriceMin(int index = 0);

int  TerminalInfoInteger(int property_id);

template<typename T>
int  ArrayDimension(
	const T&  arr
)
{
	return arr.Dimentions();
}

template<typename T>
int  ArrayResize( T& arr,           // array passed by reference
	int    new_size,                // new array size
	int    reserve_size = 0         // reserve size value (excess)
) 
{
	if (new_size > -1)
		arr.Resize(new_size);
	if (reserve_size > 0)
		arr.Reserve(reserve_size);
	return arr.Count();
}

template<typename T>
int  ArraySize(const ArrayBase<T>& arr) 
{
	return arr.Count();
}

template<typename T, size_t N>
int ArraySize(
	const T (&arr)[N]      // checked array
) {
	return N;
}

template<typename T>
bool ArraySetAsSeries(T& container, bool direction)
{
	return container.SetIndexDirection(direction);
}

template<typename T>
bool ArrayGetAsSeries(T& container)
{
	return container.GetIndexDirection();
}

template<typename T>
bool ArrayIsSeries(const T& container) { return false; }

#ifdef __INT_ON_CALCULATE
inline bool ArrayIsSeries(const mql4::Series& series) { return true; }
#endif

template<typename T>
bool ArrayIsDynamic(T& container) {
	return container.IsDynamic();
}

template<typename T1, typename T2>
int  ArrayCopy(T1& dst_array, T2& src_array, int dst_start = 0, int src_start = 0, int count = WHOLE_ARRAY)
{
	int src_l = src_array.LinearSize();
	int dst_l = dst_array.LinearSize();
	int dst_l1 = dst_array.Count();

	int cn = min(src_l - src_start, dst_l - dst_start);
	if (count > WHOLE_ARRAY && cn > count) {
		cn = count;
	}
	if (dst_l1 == dst_l) {
		if (count > WHOLE_ARRAY) {
			cn = min(src_l - src_start, count);
			if (cn > dst_l - dst_start) {
				dst_l = dst_start + cn;
				dst_array.Resize(dst_l);
			}
		}
		else if (src_l - src_start > dst_l - dst_start) {
			cn = src_l - src_start;
			dst_l = dst_start + cn;
			dst_array.Resize(dst_l);
		}
	}

	int cnt = 0;
	for (int i = src_start, j = dst_start, c = 0; c < cn; i++, j++, c++) {
		if (i >= 0 && i < src_l && j >= 0 && j < dst_l) {
			dst_array.Set(j, src_array.Get(i));
			cnt++;
		}
	}
	return cnt;
}

template<typename T>
void ArrayFree(T& arr)
{
	arr.Free();
}

template<typename T>
int ArrayCopy(T& dst_array, double(*func)(int), int dst_start = 0, int src_start = 0, int count = WHOLE_ARRAY)
{
	const int s = Bars();
	Array<double> arr(s);

	for(int i = 0; i < s; ++i)
	{
		arr[i] = func(i);
	}

	return ArrayCopy(dst_array, arr, dst_start, src_start, count);
}

template<typename T>
int  ArrayCopySeries(T& arr, int series_index, const mql4::string& symbol = _Symbol, int timeframe = 0)
{
	std::string symb = getSymbol(symbol);
	return arr.CopySeries(series_index, const_cast<char*>(symb.c_str()), timeframe);
}

template<typename T>
int  ArrayMinimum(const T& arr, int count = WHOLE_ARRAY, int start = 0)
{
	return arr.Minimum(count < 0 ? 0 : count, start < 0 ? 0 : start);
}

inline int ArrayMinimum(double(*func)(int), int count = WHOLE_ARRAY, int start = 0)
{
	const int bars = Bars();
	if(count < 0 || start < 0 || count + start >= bars)
	{
		return -1;
	}

	int s;
	if(WHOLE_ARRAY == count)
	{
		s = bars;
	}
	else
	{
		s = count;
	}

	double min = 1e+308;
	int min_i = -1;

	for(int i = start; i < s; ++i)
	{
		const double d = func(i);
		if(d < min)
		{
			min = d;
			min_i = i;
		}
	}

	return min_i;
}

template<typename T>
int  ArrayMaximum(const T& arr, int count = WHOLE_ARRAY, int start = 0)
{
	return arr.Maximum(count < 0 ? 0 : count, start < 0 ? 0 : start);
}

inline int ArrayMaximum(double(*func)(int), int count = WHOLE_ARRAY, int start = 0)
{
	const int bars = Bars();
	if(count < 0 || start < 0 || count + start >= bars)
	{
		return -1;
	}
	
	int s;
	if(WHOLE_ARRAY == count)
	{
		s = bars;
	}
	else
	{
		s = count;
	}

	double max = -1e+308;
	int max_i = -1;

	for(int i = start; i < s; ++i)
	{
		const double d = func(i);
		if(d > max)
		{
			max = d;
			max_i = i;
		}
	}

	return max_i;
}

template<typename T> int  ArrayRange(T& arr, int rank_index)
{
	return arr.Range(rank_index);
}

template<typename T> bool  ArraySort(T& array, int count = WHOLE_ARRAY, int start = 0, int direction = MODE_ASCEND)
{
	return array.Sort(count < 0 ? 0 : count, start < 0 ? 0 : start, direction);
}

template<typename T, typename V> void  ArrayFill(T&  arr, int start, int count, V value) {
	arr.Fill(start, count, value);
}

template<typename T, typename V> int  ArrayInitialize(T& arr, V value) {
	arr.Fill(0, 0, value);
	return 0;
}

datetime  TimeLocal();
datetime LocalTime();

int  Period();

inline int PeriodSeconds(mql4::ENUM_TIMEFRAMES period = PERIOD_CURRENT)
{
	if(!period)
	{
		period = _Period;
	}

	return (int)period * 60;
}

bool  FileIsExist(
	mql4::string  file_name,         // File name
	int           common_flag = 0    // Search area
);

bool  FileDelete(
	mql4::string  file_name,       // File name to delete 
	int           common_flag = 0  // Location of the file to delete
);

bool  FileIsEnding(
	int  file_handle      // file handle
);

int  FileOpen(
	mql4::string  file_name,            // File name
	int           open_flags,           // Combination of flags
	short         delimiter = -1,       // Delimiter: ';' by default
	uint          codepage = CP_ACP     // Code page
);

int FileOpen(mql4::string file_name, int open_flags, const mql4::string& delimiter, uint codepage = CP_ACP);

void  FileClose(
	int  file_handle      // File handle
);

mql4::string  FileReadString(
	int  file_handle,     // File handle
	int  length = -1         // Length of the string
);

int  FileReadInteger(
    int  file_handle,      // File handle
    int  size = INT_VALUE  // Size of an integer in bytes
);

double  FileReadDouble(
    int  file_handle,         // File handle
    int  size = DOUBLE_VALUE  // Size in bytes
);

bool  FileSeek(
	int                  file_handle,     // File handle
	mqllong                 offset,          // In bytes
	int   origin						  // Position for reference
);

ulong FileTell(int file_handle);

void  FileFlush(
	int  file_handle      // File handle
);

ulong FileSize(int file_handle);

int  StringLen(
	const mql4::string&  string_value      // string
);

mql4::string  StringSubstr(
	const mql4::string&  string_value,     // string
	int                  start_pos,        // position to start with
	int                  length = EMPTY    // length of extracted string
);

int  StringFind(
	const mql4::string&  string_value,        // string in which search is made
	const mql4::string&  match_substring,     // what is searched
	int                  start_pos = 0        // from what position search starts
);

datetime GlobalVariableSet(const mql4::string& variable_name, double variable_value);

double GlobalVariableGet(const mql4::string& variable_name);

bool GlobalVariableGet(const mql4::string& variable_name, double& output_value);

bool GlobalVariableCheck(const mql4::string& variable_name);

bool GlobalVariableDel(const mql4::string& variable_name);

int GlobalVariablesTotal();

mql4::string  GlobalVariableName(int index);

uint  FileWriteString(
	int                  file_handle,    // File handle
	const mql4::string&  text_string,    // string to write
	int                  length = -1     // number of symbols
);

uint  FileWriteInteger(
    int      file_handle,      // File handle
    int      value,            // Value to be written
    int      size = INT_VALUE  // Size in bytes
);

uint  FileWriteDouble(
    int      file_handle,         // File handle
    double   value,               // Value to write
    int      size = DOUBLE_VALUE  // Size in bytes
);

FileData* __getFileData(int file_handle);

uint __file_write(
	int  file_handle, 
	stringstream& ss, 
	int length = -1		// -1 is used for FileWrite; 0 or more is used for FileWriteString
);

template<typename T1>
uint  FileWriteArray(
    int                file_handle,         // File handle
    const Array<T1>&   some_array,          // Array
    int                start = 0,           // Start index in the array
    int                count = WHOLE_ARRAY  // Number of elements
)
{	
	const int some_array_size = some_array.Count();
    if (some_array_size == 0)
        return 0;

    // set to default values if incorrect input
    if (count <= WHOLE_ARRAY || count > some_array_size) count = some_array_size;
    if (start < 0) start = 0;

    int items_count = count - start;
    if (count == start || items_count < 0)
        return items_count;


    const int kElements = items_count;
    const int kArraySize = sizeof(T1) * kElements;

    T1* temp_arr = new T1[kElements];
    for (int i = 0, j = start; i < kElements; ++i, ++j)
        temp_arr[i] = some_array.Get(j);

    stringstream ss;
    ss.write((const char*)temp_arr, kArraySize);

    delete[] temp_arr;

    return __file_write(file_handle, ss, kArraySize) / sizeof(T1);
}

int  Hour();

int  Minute();

int Seconds();

int Year();

int Month();

int Day();

int DayOfWeek();

int DayOfYear();

bool Compare(double a, double b, double epsilon = 0.000001);

namespace mql4
{
	inline bool MathIsValidNumber(double number) { return number == 0.0 ? true : std::isnormal(number); }

	double MathAbs(double value);

	inline double MathArctan(double value) { return atan(value); }

	inline double MathExp(double value) { return exp(value); }

	double MathPow(double base, double exponent);

	double  MathRound(double value);

	double  MathSqrt(double value);

	double  MathSin(double value);

	inline double MathArcsin(double  value) { return asin(value); }

	double  MathCos(double value);

	inline double MathArccos(double value) { return acos(value); }

	double  MathLog(double value);

	double  MathLog10(double value);

	double  MathMax(double value1, double value2);

	double  MathMin(double value1, double value2);

	double  MathMod(double value1, double value2);

	double  MathTan(double rad);

	double MathFloor(double val);

	double MathCeil(double val);

	int MathRand();

	void MathSrand(unsigned int seed);
}

string FtDllPath();

string FtPath();

// Timers
bool EventSetTimer(int seconds);
bool EventSetMillisecondTimer(int milliseconds);
void EventKillTimer();


// Print
inline void print_to_stream(std::ostream&) {}

template<typename T, typename...Ts> void print_to_stream(std::ostream& stream, const T& val, const Ts&... ts)
{
	stream << val;
	print_to_stream(stream, ts...);
}

template<typename...Ts> void Print(const Ts&... ts)
{
	stringstream ss;
	print_to_stream(ss, ts...);
	Print((char*)ss.str().c_str());
}

// Comment
void mql2ft_comment(const ostringstream& oss);

template<typename...Ts> void Comment(const Ts&... ts)
{
	ostringstream oss;
	print_to_stream(oss, ts...);
	mql2ft_comment(oss);
}

// PrintFormat
template<typename... Ts>
void PrintFormat(const mql4::string& format, const Ts&... args)
{
	Print(StringFormat(format, args...));
}

// StringConcatenate
template<typename...Ts> mql4::string StringConcatenate(const Ts&... ts)
{
	stringstream ss;
	print_to_stream(ss, ts...);
	return ss.str();
}

// FileWrite
template<typename T> void print_to_file(std::ostream& stream, FileData* fp, const T& val)
{
	stream << val;
}

template<typename T, typename...Ts> void print_to_file(std::ostream& stream, FileData* fp, const T& val, const Ts&... ts)
{
	stream << val;
	if(fp->delimiter)
	{
		stream << (char)fp->delimiter;
	}
	print_to_file(stream, fp, ts...);
}

template<typename...Ts> uint FileWrite(int file_handle, const Ts&... ts)
{
	FileData* fd = __getFileData(file_handle);
	stringstream ss;
	print_to_file(ss, fd, ts...);
	return __file_write(file_handle, ss);
}

namespace mql4
{
	void RegisterOptions();
}

void _close_files();

// MQL functions stubs

inline void WindowRedraw() {}
inline void ObjectsRedraw() {}

inline bool ScreenShot(const mql4::string& fn, int w, int h)
{ 
	NotImplementedMessage("ScreenShot()");
	return false;
}
inline bool ChartScreenShot(mqllong chat_id, const mql4::string& fn, int w, int h, int align_mode = 0)
{
	NotImplementedMessage("ChartScreenShot()");
	return false;
}
inline bool WindowScreenShot(const mql4::string& fn, int x, int y, int start_bar = -1, int chart_scale = -1, int chart_mode = -1)
{ 
	NotImplementedMessage("WindowScreenShot()");
	return false;
}

inline void ChartRedraw(mqllong chart_id=0) { }

inline int UninitializeReason() { return REASON_REMOVE; }

bool StringInit(mql4::string& string_var, int new_len = 0, ushort character = 0);

bool StringToLower(mql4::string& string_var);

bool StringToUpper(mql4::string& string_var);

mql4::string StringTrimLeft(const mql4::string& text);

mql4::string StringTrimRight(const mql4::string&  text);

int StringSplit(const mql4::string& string_value, const ushort separator, Array<mql4::string>& result);

int StringReplace(mql4::string& str, const mql4::string& find, const mql4::string& replacement);

ushort StringGetCharacter(const mql4::string& string_value, int pos);

int StringGetChar(const mql4::string& string_value, int pos);

mql4::string StringSetChar(const mql4::string& string_var, int pos, ushort value);

inline string StringSetCharacter(const mql4::string& string_var, int pos, ushort value) { return StringSetChar(string_var, pos, value); }

namespace mql4
{
	inline mql4::string operator"" s(const char* cstr, unsigned int len)
	{
		return mql4::string(cstr);
	}
}