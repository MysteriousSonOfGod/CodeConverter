#pragma once

#ifndef __INDICATOR

#pragma warning(disable : 4996)  

#define EXPORT __declspec(dllexport)

#define PChar char*
#define CSTR const char*
#define TDateTime double
#define TColor long
#define PCurrencyInfo TCurrencyInfo*
#define PInterfaceProcRec TInterfaceProcRec*

#ifdef ENABLE_HOOKING
typedef BOOL(WINAPI *pExtTextOutW)(HDC, int, int, UINT, RECT*, LPCWSTR, UINT, INT*);
extern HWND ft4_main_wnd;
extern pExtTextOutW ft4_text_out_orig;
extern WNDPROC origWndProc;
extern HWND chart_wnd;
#endif

extern std::string _Symbol;
extern std::string object_prefix_;

typedef unsigned short    Word;
typedef unsigned long     LongWord;

enum TPenStyle {psSolid, psDash, psDot, psDashDot, psDashDotDot, psClear, psInsideFrame};

#define clNone			0x1FFFFFFF
#define clAqua			0xFFFF00
#define clBlack			0x000000
#define clBlue			0xFF0000
#define clCream			0xF0FBFF
#define clDkGray		0x808080
#define clFuchsia		0xFF00FF
#define clGray			0x808080
#define clGreen			0x008000
#define clLime			0x00FF00
#define clLtGray		0xC0C0C0
#define clMaroon		0x000080
#define clMedGray		0xA4A0A0
#define clMoneyGreen	0xC0DCC0
#define clNavy			0x800000
#define clOlive			0x008080
#define clPurple		0x800080
#define clRed			0x0000FF
#define clSilver		0xC0C0C0
#define clSkyBlue		0xF0CAA6
#define clTeal			0x808000
#define clWhite			0xFFFFFF
#define clYellow		0x00FFFF


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma pack(push, 1)

//-------------------------------------------
// currency information
//-------------------------------------------
struct TCurrencyInfo {
  PChar Symbol;               // currency name
  int Digits;                 // number of digits after '.'
  int spread;                 // spread in pips
  double Point;               // minimal currency point
  int lot;                    // 1 lot cost
  PChar curr;                 // lot currency
  double SwapLong;            // swap points long
  double SwapShort;           // swap points short
};

//-------------------------------------------
// trade position
//-------------------------------------------
struct TTradePosition {
  int ticket;                  // order handle
  TDateTime OpenTime;          // order open time
  TDateTime CloseTime;         // order close time
  int PosType;                 // position type (tp_Buy ... tp_Credit)
  double lot;                  // lot
  PChar Symbol;                // currency name
  double OpenPrice;            // open price
  double ClosePrice;           // close price
  double StopLoss;             // stop loss
  double TakeProfit;           // take profit
  double commission;           // comission
  double swap;                 // swap
  double profit;               // profit in USD
  int ProfitPips;              // profit in pips
  PChar comments;              // comments
  double margin;               // margin
};

// option type
enum TOptionType {
  ot_Longword  = 0,
  ot_Integer   = 1,
  ot_Double    = 2,
  ot_String    = 3,
  ot_Boolean   = 4,
  ot_EnumType  = 5,
  ot_TimeFrame = 6,
  ot_Currency  = 7,
  ot_LineStyle = 8,
  ot_Separator = 9,
  ot_Reserved0 = 10,
  ot_Color     = 11,
  ot_Reserved1 = 12,
  ot_DateTime  = 13
};

// search mode
enum TSearchMode {
  MODE_TRADES  = 0,
  MODE_HISTORY = 1
};

// order select mode
enum TOrderSelectMode {
  SELECT_BY_POS     = 0,
  SELECT_BY_TICKET  = 1
};

// market info constants
enum TMarketInfo {
  MODE_BID   = 0,
  MODE_ASK   = 1
};

// trade position type
enum TTradePositionType {
  tp_Buy       = 0,
  tp_Sell      = 1,
  tp_BuyLimit  = 2,
  tp_SellLimit = 3,
  tp_BuyStop   = 4,
  tp_SellStop  = 5,
  tp_Balance   = 6,
  tp_Credit    = 7
};

// instant operation type
enum TInstantOrderType {
  op_Buy       = 0,
  op_Sell      = 1
};

// pending operation type
enum TPendingOrderType {
  op_BuyLimit  = 0,
  op_BuyStop   = 1,
  op_SellLimit = 2,
  op_SellStop  = 3
};

// object types
enum TObjectType {
  obj_AnyObject        = 0,
  obj_VLine            = 1,
  obj_HLine            = 2,
  obj_TrendLine        = 3,
  obj_Ray              = 4,
  obj_PolyLine         = 5,
  obj_FiboRetracement  = 6,
  obj_FiboTimeZones    = 7,
  obj_FiboArc          = 8,
  obj_FiboFan          = 9,
  obj_AndrewsPitchfork = 10,
  obj_Text             = 11,
  obj_TextLabel        = 12,
  obj_Rectangle		   = 13,
  obj_Ellipse		   = 14,
  obj_Triangle		   = 15,
  obj_FiboChannel	   = 16,
  obj_LRChannel		   = 17,
  obj_FiboExtension    = 18,
};


// indicator window
enum TOutputWindow  {
  ow_ChartWindow    = 0,
  ow_SeparateWindow = 1
};
#pragma pack(pop)

// timeframes
enum ENUM_TIMEFRAMES
{
	PERIOD_CURRENT = 0,
	PERIOD_M1 = 1,
	PERIOD_M5 = 5,
	PERIOD_M15 = 15,
	PERIOD_M30 = 30,
	PERIOD_H1 = 60,
	PERIOD_H4 = 240,
	PERIOD_D1 = 1440,
	PERIOD_W1 = 10080,
	PERIOD_MN1 = 43200
};

//#define PERIOD_M1  1
//#define PERIOD_M5  5
//#define PERIOD_M15 15
//#define PERIOD_H1  60
//#define PERIOD_H4  60*4
//#define PERIOD_D1  60*24
//#define PERIOD_W1  60*24*7

namespace ft
{
	constexpr const int OBJPROP_TIME1 = 0;
	constexpr const int OBJPROP_PRICE1 = 1;
	constexpr const int OBJPROP_TIME2 = 2;
	constexpr const int OBJPROP_PRICE2 = 3;
	constexpr const int OBJPROP_TIME3 = 4;
	constexpr const int OBJPROP_PRICE3 = 5;
	constexpr const int OBJPROP_COLOR = 6;
	constexpr const int OBJPROP_STYLE = 7;
	constexpr const int OBJPROP_WIDTH = 8;
	constexpr const int OBJPROP_ELLIPSE = 11;
	constexpr const int OBJPROP_FIBOCLOSEDENDS = 12;
	constexpr const int OBJPROP_FIBOSHOWPRICE = 13;
	constexpr const int OBJPROP_FIBOENDWIDTH = 14;
	constexpr const int OBJPROP_FIBOLEVELS = 15;
	constexpr const int OBJPROP_FIBOLEVELN = 16;
	constexpr const int OBJPROP_LEVELCOLOR = 17;
	constexpr const int OBJPROP_LEVELSTYLE = 18;
	constexpr const int OBJPROP_LEVELWIDTH = 19;
	constexpr const int OBJPROP_LEVELVALUE = 20;
	constexpr const int OBJPROP_FONTSIZE = 21;
	constexpr const int OBJPROP_HALIGNMENT = 22;
	constexpr const int OBJPROP_VALIGNMENT = 23;
	constexpr const int OBJPROP_FONTNAME = 24;
	constexpr const int OBJPROP_XDISTANCE = 25;
	constexpr const int OBJPROP_YDISTANCE = 26;
	constexpr const int OBJPROP_TEXT = 27;
	constexpr const int OBJPROP_NAME = 28;
	constexpr const int OBJPROP_SCREENCOORDS = 29;
	constexpr const int OBJPROP_SCRHALIGNMENT = 30;
	constexpr const int OBJPROP_SCRVALIGNMENT = 31;
	constexpr const int OBJPROP_FILLINSIDE = 32;
	constexpr const int OBJPROP_FILLCOLOR = 33;
}

// text alignment
#define tlTop             0
#define tlCenter          1
#define tlBottom          2

#define taLeftJustify     0
#define taRightJustify    1
#define taCenter          2

#define MODE_OPEN    0
#define MODE_LOW     1
#define MODE_HIGH    2
#define MODE_CLOSE   3
#define MODE_VOLUME  4
#define MODE_TIME    5


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Get currency information
// Symbol - currency name
// info - pointer to TCurrencyInfo record
// result: true if success
bool GetCurrencyInfo(const std::string& Symbol, PCurrencyInfo& info);

// Register option
// OptionName - name of option
// OptionType - see TOptionType enumeration
// option - pointer to first byte
void RegOption(PChar OptionName, TOptionType OptionType, void* option);

// Add separator to options dialog
// text - separator caption
void AddSeparator(PChar text);

// Add option value (for drop down box options)
// OptionName - name of previously registered option
// value - new value in drop down box
void AddOptionValue(PChar OptionName, PChar value);

// Set option range (for integer, longword and double types)
// OptionName - name of previously registered option
// LowValue - lowest value in range
// HighValue - highest value in range
// note: in dialog box after entering option value it will be checked
//       to be in range LowValue <= value <= HighValue
void SetOptionRange(PChar OptionName, double LowValue, double HighValue);

// Set option digits (for double options) defines number of digits after point
// OptionName - name of option
// digits - number of digits after point
void SetOptionDigits(PChar OptionName, Word digits);

// Print text in "Journal" window in ForexTester
// s - text
void Print(PChar s);
void Print(std::string s);		// s - string
void Print(std::stringstream& s);// s - stringstream 
void Print(int i);          // s - int
void Print(double d);       // s - double

// Set strategy short name
// name - short name
void StrategyShortName(PChar name);

// Set strategy description
// desc - description
void StrategyDescription(PChar desc);

// Set currency and timeframe (after that such functions will be enabled:
// Bid, Ask, Symbol, Point, Digits, Open, Close, High, Low, Volume, Time, Bars)
// Symbol - requested currency
// TimeFrame - requested timeframe
// result: true if success
bool SetCurrencyAndTimeframe(PChar Symbol, int TimeFrame);

namespace ft
{
	// Get market information
	// Symbol - requested currency
	// _type - requested item (MODE_BID, MODE_ASK)
	double MarketInfo(PChar Symbol, TMarketInfo _type);
}

// Send instant order
// Symbol - currency name
// OperationType - type of operation (op_Sell, op_Buy)
// LotSize - lot size
// StopLoss - stop loss
// TakeProfit - take profit
// Comment - text comment
// MagicNumber - special number that will mark this order
// OrderHandle - returned handle of order (-1 if fail)
// result: true if success OrderHandle = ticket, false if failed OrderHandle = -1
bool SendInstantOrder(PChar Symbol, TInstantOrderType OperationType,
  double LotSize, double StopLoss, double TakeProfit, PChar Comment,
  int MagicNumber, int& OrderHandle);

// Send pending order
// Symbol - currency name
// OperationType - type of operation (op_SellLimit, op_SellStop, op_BuyLimit, op_BuyStop)
// LotSize - lot size
// StopLoss - stop loss
// TakeProfit - take profit
// ExecutionPrice - price where order should be placed
// Comment - text comment
// MagicNumber - special number that will mark this order
// OrderHandle - returned handle of order (-1 if fail)
// result: true if success OrderHandle = ticket, false if failed OrderHandle = -1
bool SendPendingOrder(PChar Symbol, TPendingOrderType OperationType,
  double LotSize, double StopLoss, double TakeProfit, double ExecutionPrice,
  PChar Comment, int MagicNumber, int& OrderHandle);

// Modify order
// OrderHandle - handle of the order
// NewPrice - new order price (only for pending order)
// StopLoss - new stop loss
// TakeProfit - new take profit
// result: true if success
bool ModifyOrder(int OrderHandle, double NewPrice, double StopLoss, double TakeProfit);

// Delete order
// OrderHandle - handle of the order
// result: true if success
bool DeleteOrder(int OrderHandle);

// Close order
// OrderHandle - handle of the order
// result: true if success
bool CloseOrder(int OrderHandle);

// Get order information
// OrderHandle - handle of the order
// info - if order is found this structure will be filled with order info
// result: true if success info will contain order information
bool GetOrderInfo(int OrderHandle, TTradePosition& info);

// Get Bid price
double Bid();

// Get Ask price
double Ask();

// Currency name
std::string Symbol();

// Currency digits after point
int Digits();

// Minimal currency point
double Point();

// Select order
// index - order index or order handle (depending on flags)
// flags - selecting flags (SELECT_BY_POS, SELECT_BY_TICKET)
// pool - where to find order (MODE_TRADES, MODE_HISTORY) only matters
//        when flags = SELECT_BY_POS
// result: true if success
bool OrderSelect(int index, TOrderSelectMode flags = SELECT_BY_POS, TSearchMode pool = MODE_TRADES);

// Get profit in dollars of selected order
double OrderProfit();

// Get profit in pips of selected order
double OrderProfitPips();

// Check if order was closed
// OrderHandle - order handle
// result: true if order is closed, otherwise false
bool OrderClosed(int OrderHandle);

// Number of closed positions
int HistoryTotal();

// Number of opened positions
int OrdersTotal();

namespace ft
{
	// Open time of selected order
	TDateTime OrderOpenTime();

	// Close time of selected order
	TDateTime OrderCloseTime();
}

// Lot size of selected order
double OrderLots();

// Handle of selected order
int OrderTicket();

// Type of the selected order (tp_Buy, tp_Sell, tp_BuyLimit, tp_SellLimit,
// tp_BuyStop, tp_SellStop, tp_Balance, tp_Credit)
TTradePositionType OrderType();

// Stop loss of selected order
double OrderStopLoss();

// Take profit of selected order
double OrderTakeProfit();

// Open price of selected order
double OrderOpenPrice();

// Close price of selected order
double OrderClosePrice();

// Currency of selected order
std::string OrderSymbol();

// Get order MagicNumber
int OrderMagicNumber();

namespace ft
{
	// Get order comment
	PChar OrderComment();
}

// Get order swap
double OrderSwap();

namespace ft
{
	// Get open value
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	double iOpen(PChar symbol, int TimeFrame, int index);

	// Get close value
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	double iClose(PChar symbol, int TimeFrame, int index);

	// Get high value
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	double iHigh(PChar symbol, int TimeFrame, int index);

	// Get low value
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	double iLow(PChar symbol, int TimeFrame, int index);

	// Get volume
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	int iVolume(PChar symbol, int TimeFrame, int index);

	// Get time of bar
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// index - shift in bars from last bar
	TDateTime iTime(PChar symbol, int TimeFrame, int index);

	// Get number of bars
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	int iBars(const std::string&, int TimeFrame);
}

// Get open value in default currency and timeframe
// index - shift in bars from last bar
double Open(int index);

// Get close value in default currency and timeframe
// index - shift in bars from last bar
double Close(int index);

// Get high value in default currency and timeframe
// index - shift in bars from last bar
double High(int index);

// Get low value in default currency and timeframe
// index - shift in bars from last bar
double Low(int index);

// Get volume in default currency and timeframe
// index - shift in bars from last bar
int Volume(int index);

namespace ft
{
	// Get time of bar in default currency and timeframe
	// index - shift in bars from last bar
	TDateTime Time(int index);
}

// Get number of bars in default currency and timeframe
int Bars();

namespace ft
{
	// Get account balance
	double AccountBalance();

	// Get account equity
	double AccountEquity();
}

// Get account margin
double AccountMargin();

// Get account free margin
double AccountFreeMargin();

// Get account leverage
int AccountLeverage();

// Get account profit
double AccountProfit();

// Breakpoint
// Stop strategy execution and show debug window with text
// number - breakpoint number
// text - text to show
void Breakpoint(int number, PChar text);

// Pause - set pause mode
// text - text to show in message box, if text = '' then no message will appear
void Pause(PChar text = "");

// continue testing
void Resume();

// Create indicator and obtaind id
// Symbol - currency name
// TimeFrame - desired timeframe
// IndicatorName - case sensitive indicator name that you can see in progam
// parameters - indicator parameters separated with ';'
// result: id that will be used in GetIndicatorValue
int CreateIndicator(PChar Symbol, int TimeFrame, PChar IndicatorName, PChar parameters);

// Get indicator value
// IndicatorHandle - id obtained with CreateIndicator
// index - inder in array of values
// BufferIndex - index of buffer
// result: indicator value
double GetIndicatorValue(int IndicatorHandle, int index, int BufferIndex);

// Get interface version
void GetInterfaceVersion(int& MajorValue, int& MinorValue);

namespace ft
{
	// Create object
	// name - object name (must be unique)
	// ObjType - type of object (see TObjectType)
	// window - in what window to show object (ignored)
	// time1, price1 .. time3, price3 - time and price coordinates of object
	// function returns true if successful
	bool ObjectCreate(const std::string& name, TObjectType ObjType, int window,
		TDateTime time1, double price1, TDateTime time2 = 0, double price2 = 0,
		TDateTime time3 = 0, double price3 = 0);

	// Delete object by name
	// name - name of the object
	void ObjectDelete(const std::string& name);

	// Check if object already exists
	// name  - name of the object
	bool ObjectExists(const std::string& name);

	// Get object type
	// name - name of the object
	TObjectType ObjectType(const std::string& name);

	// Set object property
	// name - name of the object
	// index - property index
	// value - new value
	// function returns true if successful
	bool ObjectSet(const std::string& name, int index, double value);

	// Get object property
	// name - name of the object
	// index - property index
	double ObjectGet(const std::string& name, int index);

	// Delete all objects
	// window - window where to delete
	// ObjType - type of objects
	void ObjectsDeleteAll(int window = 0, TObjectType ObjType = obj_AnyObject);

	// set text/description for object
	// name - name of the object
	// text - text to set
	// FontSize - font size
	// FontName - font name
	// Color - font color
	// function returns true if successful
	bool ObjectSetText(const std::string& name, const std::string& text, int FontSize = 12,
		const std::string& FontName = "Arial", TColor Color = clNone);
}

// get text/description of the object
// name - name of the object
// function returns text or empty string if failed
std::string ObjectGetText(const std::string& name);

namespace ft
{
	// get current server time
	TDateTime  TimeCurrent();
}

// set indicator's buffer style
// IndicatorHandle - indicator's handle received with CreateIndicator
// BuffIndex - index of indicator's buffer where you want to change style
// _style - line style
// width - line width
// clr - line color
void SetIndicatorBuffStyle(int IndicatorHandle, int BuffIndex, TPenStyle _style,
  int width, TColor color);

namespace ft
{
	// get bar index by its time
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// time - time of the bar
	// Exact - if this parameter is true then time should be exactly the same
	//         otherwise will be returned index of the bar where time is
	//         between time[index] and time[index + 1]
	// function returns index of the bar if successful, and -1 if failed
	int iBarShift(const std::string& symbol, int TimeFrame, TDateTime time, bool Exact);

	// get highest value in array
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// _type - type of value (see constants MODE_OPEN .. MODE_TIME)
	// count - number of bars to search
	// index - first index to start searching
	// function returns index of the bar if successful, and -1 if failed
	int iHighest(const std::string& symbol, int TimeFrame, int _type, int count, int index);

	// get lowest value in array
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// _type - type of value (see constants MODE_OPEN .. MODE_TIME)
	// count - number of bars to search
	// index - first index to start searching
	// function returns index of the bar if successful, and -1 if failed
	int iLowest(const std::string& symbol, int TimeFrame, int _type, int count, int index);
}
// close part of position
// OrderHandle - handle of the order
// LotSize - part of position to close
// function returns "true" if successful
bool CloseOrderPartial(int OrderHandle, double LotSize);


int Sell(double LotSize, double StopLoss, double TakeProfit);
int Buy(double LotSize, double StopLoss, double TakeProfit);
//PChar StrTime(TDateTime DateTime);
int GetStopLossPoints(int OrderHandle);
int GetTakeProfitPoints(int OrderHandle);
void SetStopLossPoints(int OrderHandle, int NewStopLoss);
void SetTakeProfitPoints(int OrderHandle, int NewTakeProfit);


bool _SendInstantOrder(PChar Symbol, TInstantOrderType OperationType,
  double price, double LotSize, double StopLoss, double TakeProfit, PChar Comment,
  int MagicNumber, int& OrderHandle);

bool _CloseOrder(int OrderHandle, double price);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// indicator interface procedures
typedef bool (__stdcall *TGetCurrencyInfoFunc) (void* ptr, const char* Symbol, PCurrencyInfo& info);
typedef void (__stdcall *TSetPropertyProc) (void* ptr, int PropertyID, void* value);
typedef void (__stdcall *TRegOptionProc) (void* ptr, PChar OptionName, int OptionType, void* OptionPtr);
typedef void (__stdcall *TAddOptionValueProc) (void* ptr, PChar OptionName, PChar value);
typedef void (__stdcall *TSetOptionRange) (void* ptr, PChar OptionName, double LowValue, double HighValue);  

typedef void (__stdcall *TSetOptionDigitsProc) (void* ptr, PChar OptionName, Word digits);
typedef void (__stdcall *TPrintProc) (void* ptr, PChar s);
typedef double (__stdcall *TGetDoubleFunc) (void* ptr);
typedef PChar (__stdcall *TGetPCharFunc) (void* ptr);
typedef int (__stdcall *TGetIntegerFunc) (void* ptr);

typedef TDateTime (__stdcall *TGetDateTimeFunc) (void* ptr);
typedef double (__stdcall *TGet_iOHLCVFunc) (void* ptr, PChar Symbol, int TimeFrame, int index);
typedef TDateTime (__stdcall *TGet_iTimeFunc) (void* ptr, PChar Symbol, int TimeFrame, int index);
typedef unsigned long int (__stdcall *TGet_iBarsFunc) (void* ptr, const char* Symbol, int TimeFrame);
typedef double (__stdcall *TGetOHLCVFunc) (void* ptr, int index);

typedef TDateTime (__stdcall *TGetTimeFunc) (void* ptr, int index);
typedef unsigned long int (__stdcall *TGetBarsFunc) (void* ptr);

typedef bool (__stdcall *TSendInstantOrderFunc) (void* ptr, PChar Symbol, int OperationType,
  double LotSize, double StopLoss, double TakeProfit, int& OrderHandle);

typedef bool (__stdcall *TSendInstantOrder2Func) (void* ptr, PChar Symbol, int OperationType,
  double LotSize, double StopLoss, double TakeProfit, PChar comment, int MagicNumber, int& OrderHandle);

typedef bool (__stdcall *T_SendInstantOrderFunc) (void* ptr, PChar Symbol, int OperationType,
  double price, double LotSize, double StopLoss, double TakeProfit, PChar comment, int MagicNumber, int& OrderHandle);

typedef bool (__stdcall *TSendPendingOrderFunc) (void* ptr, PChar Symbol, int OperationType,
  double LotSize, double StopLoss, double TakeProfit, double ExecutionPrice, int& OrderHandle);

typedef bool (__stdcall *TSendPendingOrder2Func) (void* ptr, PChar Symbol, int OperationType,
  double LotSize, double StopLoss, double TakeProfit, double ExecutionPrice, PChar comment, int MagicNumber, int& OrderHandle);

typedef bool (__stdcall *TModifyOrderFunc) (void* ptr, int OrderHandle, double NewPrice, double StopLoss, double TakeProfit);
typedef bool (__stdcall *TDeleteOrderFunc) (void* ptr, int OrderHandle);
typedef bool (__stdcall *TCloseOrderFunc) (void* ptr, int OrderHandle);
typedef bool (__stdcall *T_CloseOrderFunc) (void* ptr, int OrderHandle, double peice);
typedef bool (__stdcall *TGetOrderInfoFunc) (void* ptr, int OrderHandle, TTradePosition& info);

typedef bool (__stdcall *TSetCurrencyAndTimeframeFunc) (void* ptr, PChar Symbol, int TimeFrame);
typedef bool (__stdcall *TOrderSelectFunc) (void* ptr, int index, int flags, int pool);
typedef bool (__stdcall *TOrderClosedFunc) (void* ptr, int OrderHandle);
typedef double (__stdcall *TMarketInfoFunc) (void* ptr, PChar Symbol, int _type);
typedef void (__stdcall *TStrategyShortNameProc) (void* ptr, PChar name);

typedef void (__stdcall *TStrategyDescriptionProc) (void* ptr, PChar desc);
typedef void (__stdcall *TBreakpointProc) (void* ptr, int number, PChar text);
typedef int (__stdcall *TCreateIndicatorFunc) (void* ptr, PChar CurrencyName, int Timeframe,
  PChar IndicatorName, PChar parameters);

typedef double (__stdcall *TGetIndicatorValueFunc) (void* ptr, int IndicatorHandle, int index, int BufferIndex);
typedef void (__stdcall *TPauseProc) (void* ptr, PChar text);
typedef void (__stdcall *TResumeProc) (void* ptr);
typedef void (__stdcall *TGetInterfaceVersionProc) (void* ptr, int& MajorValue, int& MinorValue);

typedef bool (__stdcall *TObjectCreateFunc) (void* ptr, CSTR name, int ObjType, int window,
  TDateTime time1, double price1, TDateTime time2, double price2, TDateTime time3, double price3);

typedef void (__stdcall *TObjectDeleteProc) (void* ptr, CSTR name);
typedef bool (__stdcall *TObjectExistsFunc) (void* ptr, CSTR name);
typedef int (__stdcall *TObjectTypeFunc) (void* ptr, CSTR name);
typedef bool (__stdcall *TObjectSetFunc) (void* ptr, CSTR name, int index, double value);
typedef double (__stdcall *TObjectGetFunc) (void* ptr, CSTR name, int index);

typedef void (__stdcall *TObjectsDeleteAllProc) (void* ptr, int window, int ObjType);
typedef bool (__stdcall *TObjectSetTextFunc) (void* ptr, const char* name, const char* text, int FontSize,
  const char* FontName, int Color);

typedef void (__stdcall *TSetIndicatorBuffStyleProc) (void* ptr, int IndicatorHandle, 
  int BuffIndex, int _style, int width, int color);

typedef int (__stdcall *TIBarShiftFunc) (void* ptr, const char* Symbol, int TimeFrame, TDateTime time, bool Exact);  
typedef int (__stdcall *TIHighestFunc) (void* ptr, const char* Symbol, int TimeFrame, int _type, int count, int index);
typedef int (__stdcall *TILowestFunc) (void* ptr, const char* Symbol, int TimeFrame, int _type, int count, int index);

typedef bool (__stdcall *TCloseOrderPartialFunc) (void* ptr, int OrderHandle, double LotSize);

typedef PChar (__stdcall *TObjectGetTextFunc) (void* ptr, CSTR name);


// pointers to interface procedures

#pragma pack(push)
struct TInterfaceProcRec {
  LongWord dwSize;

  TRegOptionProc RegOption;
  void* pRegOption;
  
  TAddOptionValueProc AddOptionValue;
  void* pAddOptionValue;   
  
  TSetOptionRange SetOptionRange;
  void* pSetOptionRange;

  TSetOptionDigitsProc SetOptionDigits;
  void* pSetOptionDigits;

  TPrintProc Print;
  void* pPrint;

  TStrategyShortNameProc StrategyShortName;
  void* pStrategyShortName;

  TStrategyDescriptionProc StrategyDescription;
  void* pStrategyDescription;

  TGetCurrencyInfoFunc GetCurrencyInfo;
  void* pGetCurrencyInfo;

  TSetCurrencyAndTimeframeFunc SetCurrencyAndTimeframe;
  void* pSetCurrencyAndTimeframe;
  
  TMarketInfoFunc MarketInfo;
  void* pMarketInfo;

  TGetDoubleFunc Bid;
  void* pBid;

  TGetDoubleFunc Ask;
  void* pAsk;

  TGetPCharFunc Symbol;
  void* pSymbol;

  TGetIntegerFunc Digits;
  void* pDigits;

  TGetDoubleFunc Point;
  void* pPoint;

  TSendInstantOrderFunc SendInstantOrder;
  void* pSendInstantOrder;

  TSendPendingOrderFunc SendPendingOrder;
  void* pSendPendingOrder;

  TModifyOrderFunc ModifyOrder;
  void* pModifyOrder;

  TDeleteOrderFunc DeleteOrder;
  void* pDeleteOrder;

  TCloseOrderFunc CloseOrder;
  void* pCloseOrder;

  TOrderClosedFunc OrderClosed;
  void* pOrderClosed;

  TGetOrderInfoFunc GetOrderInfo;
  void* pGetOrderInfo;

  TOrderSelectFunc OrderSelect;
  void* pOrderSelect;

  TGetDoubleFunc OrderProfit;
  void* pOrderProfit;

  TGetDoubleFunc OrderProfitPips;
  void* pOrderProfitPips;

  TGetIntegerFunc HistoryTotal;
  void* pHistoryTotal;

  TGetIntegerFunc OrdersTotal;
  void* pOrdersTotal;

  TGetDateTimeFunc OrderOpenTime;
  void* pOrderOpenTime;

  TGetDateTimeFunc OrderCloseTime;
  void* pOrderCloseTime;

  TGetDoubleFunc OrderLots;
  void* pOrderLots;

  TGetIntegerFunc OrderTicket;
  void* pOrderTicket;

  TGetIntegerFunc OrderType;
  void* pOrderType;

  TGetDoubleFunc OrderStopLoss;
  void* pOrderStopLoss;

  TGetDoubleFunc OrderTakeProfit;
  void* pOrderTakeProfit;

  TGetDoubleFunc OrderOpenPrice;
  void* pOrderOpenPrice;

  TGetDoubleFunc OrderClosePrice;
  void* pOrderClosePrice;

  TGetPCharFunc OrderSymbol;
  void* pOrderSymbol;

  TGet_iOHLCVFunc iOpen;
  void* p_iOpen;

  TGet_iOHLCVFunc iClose;
  void* p_iClose;

  TGet_iOHLCVFunc iHigh;
  void* p_iHigh;

  TGet_iOHLCVFunc iLow;
  void* p_iLow;

  TGet_iOHLCVFunc iVolume;
  void* p_iVolume;

  TGet_iTimeFunc iTime;
  void* p_iTime;

  TGet_iBarsFunc iBars;
  void* p_iBars;

  TGetOHLCVFunc Open;
  void* pOpen;

  TGetOHLCVFunc Close;
  void* pClose;

  TGetOHLCVFunc High;
  void* pHigh;

  TGetOHLCVFunc Low;
  void* pLow;

  TGetOHLCVFunc Volume;
  void* pVolume;

  TGetTimeFunc Time;
  void* pTime;

  TGetBarsFunc Bars;
  void* pBars;

  // extensions ver 1.1 (dwSize > 412)
  TGetDoubleFunc AccountBalance;
  void* pAccountBalance;

  TGetDoubleFunc AccountEquity;
  void* pAccountEquity;

  TGetDoubleFunc AccountMargin;
  void* pAccountMargin;

  TGetDoubleFunc AccountFreeMargin;
  void* pAccountFreeMargin;

  TGetIntegerFunc AccountLeverage;
  void* pAccountLeverage;

  TGetDoubleFunc AccountProfit;
  void* pAccountProfit;

  TBreakpointProc Breakpoint;
  void* pBreakpoint;

  // extensions ver 1.2 (dwSize > 468)
  TCreateIndicatorFunc CreateIndicator;
  void* pCreateIndicator;

  TGetIndicatorValueFunc GetIndicatorValue;
  void* pGetIndicatorValue;

  // extensions ver 1.3 (dwSize > 484)
  TSendInstantOrder2Func SendInstantOrder2;
  void* pSendInstantOrder2;

  TSendPendingOrder2Func SendPendingOrder2;
  void* pSendPendingOrder2;

  TGetPCharFunc OrderComment;
  void* pOrderComment;

  TGetIntegerFunc OrderMagicNumber;
  void* pOrderMagicNumber;

  // extensions ver 1.4 (dwSize > 516)
  TPauseProc Pause;
  void* pPause;

  TResumeProc Resume;
  void* pResume;

  // extensions ver 1.41 (dwSize > 532)
  T_SendInstantOrderFunc _SendInstantOrder;
  void* p_SendInstantOrder;

  T_CloseOrderFunc _CloseOrder;
  void* p_CloseOrder;

  // extensions ver 1.5 (dwSize > 548)
  TGetInterfaceVersionProc GetInterfaceVersion;
  void* pGetInterfaceVersion;

  TObjectCreateFunc ObjectCreate;
  void* pObjectCreate;

  TObjectDeleteProc ObjectDelete;
  void* pObjectDelete;

  TObjectExistsFunc ObjectExists;
  void* pObjectExists;

  TObjectTypeFunc ObjectType;
  void* pObjectType;

  TObjectSetFunc ObjectSet;
  void* pObjectSet;

  TObjectGetFunc ObjectGet;
  void* pObjectGet;

  TObjectsDeleteAllProc ObjectsDeleteAll;
  void* pObjectsDeleteAll;

  TObjectSetTextFunc ObjectSetText;
  void* pObjectSetText;

  // extentions ver 1.7
  TGetDateTimeFunc TimeCurrent;
  void* pTimeCurrent;

  TSetIndicatorBuffStyleProc SetIndicatorBuffStyle;
  void* pSetIndicatorBuffStyle;

  // extensions ver 1.8 (dwSize > 636)
  TIBarShiftFunc iBarShift;
  void* piBarShift;

  TIHighestFunc iHighest;
  void* piHighest;

  TILowestFunc iLowest;
  void* piLowest;

  // extensions ver 1.9 (dwSize > 660)
  TCloseOrderPartialFunc CloseOrderPartial;
  void* pCloseOrderPartial;

  // extensions ver 1.10 (dwSize > 668)
  TObjectGetTextFunc ObjectGetText;
  void* pObjectGetText;

  // extensions ver 1.11 (dwSize > 676)
  TGetDoubleFunc OrderSwap;
  void* pOrderSwap;
};
#pragma pack(pop)


/*-----------------------------------------------------------------------------

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) 
{
  switch (dwReason) 
  {
    case DLL_PROCESS_ATTACH:
    {
      memset(&IntrfProcsRec, 0, sizeof(TInterfaceProcRec));
      IntrfProcsRec.dwSize = sizeof(TInterfaceProcRec);
      break;
    }

    case DLL_THREAD_ATTACH:
    break;

    case DLL_THREAD_DETACH:
    break;

    case DLL_PROCESS_DETACH:
    break;
  }

  return TRUE;
}
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define rec IntrfProcsRec

//-----Replace PChar string with new one--------------------------------------
#pragma comment(linker, "/EXPORT:ReplaceStr=_ReplaceStr@8") // for VisualStudio's linker to "solve" __stdcall function name mangling
extern "C" __declspec(dllexport) void __stdcall ReplaceStr(char* &dest, const char* source);

//-----Sell-------------------------------------------------------------------
int Sell(double LotSize, double StopLoss, double TakeProfit);

//-----Buy-------------------------------------------------------------------
int Buy(double LotSize, double StopLoss, double TakeProfit);

#endif
