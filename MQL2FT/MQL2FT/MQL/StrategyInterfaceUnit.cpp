#include "pch.h"

#include "StrategyInterfaceUnit.h"
#include "Hook.h"

#ifdef __STRATEGY

#ifdef ENABLE_HOOKING
HWND ft4_main_wnd;
pExtTextOutW ft4_text_out_orig;
WNDPROC origWndProc;
#endif

// Helper functions
inline std::string pcharToStr(PChar cstr)
{
	return cstr ? std::string(cstr) : std::string();
}

using namespace std;

extern "C" {
	__declspec(dllexport) TInterfaceProcRec IntrfProcsRec;
}

//-----------------------------------------------------------------------------

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) 
{
  switch (dwReason) 
  {
    case DLL_PROCESS_ATTACH:
    {
      memset(&IntrfProcsRec, 0, sizeof(TInterfaceProcRec));
      IntrfProcsRec.dwSize = sizeof(TInterfaceProcRec);

#ifdef ENABLE_HOOKING
	  DWORD pid = GetCurrentProcessId();
	  ft4_main_wnd = ft::findMainWindow(pid);

	  ft4_text_out_orig = (pExtTextOutW)GetProcAddress(GetModuleHandleW(L"gdi32.dll"), "ExtTextOutW");
	  ft::prepareJumps();
#endif
      break;
    }

    case DLL_THREAD_ATTACH:
    break;

    case DLL_THREAD_DETACH:
    break;

    case DLL_PROCESS_DETACH:
#ifdef ENABLE_HOOKING
		(WNDPROC)SetWindowLongPtrA(chart_wnd, GWLP_WNDPROC, (LONG_PTR)origWndProc); // For FT messages hooking
#endif
    break;
  }

  return TRUE;
}

//-----Replace PChar string with new one--------------------------------------
extern "C" __declspec(dllexport) void __stdcall ReplaceStr(char* &dest, const char* source)
{
  free(dest);
  dest = (char*)malloc(strlen(source) + 1);
  strcpy(dest, source);
}

//-----Sell-------------------------------------------------------------------
int Sell(double LotSize, double StopLoss, double TakeProfit)
{
  double tp, sl;

  if (TakeProfit == 0) tp = 0; else tp = Bid() - TakeProfit*Point();
  if (StopLoss == 0) sl = 0; else sl = Bid() + StopLoss*Point();

  int result;
  SendInstantOrder((char*)Symbol().c_str(), op_Sell, LotSize, sl, tp, "", 0, result);
  return result;
}

//-----Buy-------------------------------------------------------------------
int Buy(double LotSize, double StopLoss, double TakeProfit)
{
  double tp, sl;

  if (TakeProfit == 0) tp = 0; else tp = Ask() + TakeProfit*Point();
  if (StopLoss == 0) sl = 0; else sl = Ask() - StopLoss*Point();

  int result;
  SendInstantOrder((char*)Symbol().c_str(), op_Buy, LotSize, sl, tp, "", 0, result);
  return result;
}

/*
//-----Convert time to string-------------------------------------------------
function StrTime(DateTime: TDateTime): string;
{
  DateTimeToString(result, 'yyyy.mm.dd hh:nn', DateTime);
}
*/

//-----Get currency information-----------------------------------------------
bool GetCurrencyInfo(const std::string& symbol, PCurrencyInfo& info)
{
  return IntrfProcsRec.GetCurrencyInfo(
	  IntrfProcsRec.pGetCurrencyInfo,
	  symbol.c_str(),
	  info);
}

//-----Register option--------------------------------------------------------
void RegOption(PChar OptionName, TOptionType OptionType, void* option)
{
  IntrfProcsRec.RegOption(IntrfProcsRec.pRegOption, OptionName, OptionType, option);
}

//-----Add separator----------------------------------------------------------
void AddSeparator(PChar text)
{
  IntrfProcsRec.RegOption(IntrfProcsRec.pRegOption, text, ot_Separator, NULL);
}

//-----Add option value (for drop down box options)---------------------------
void AddOptionValue(PChar OptionName, PChar value)
{
  IntrfProcsRec.AddOptionValue(IntrfProcsRec.pAddOptionValue, OptionName, value);
}

//-----Set option range (for integer, longword and double types)--------------
void SetOptionRange(PChar OptionName, double LowValue, double HighValue)
{
  IntrfProcsRec.SetOptionRange(IntrfProcsRec.pSetOptionRange, OptionName, LowValue, HighValue);
}

//-----Set option digits------------------------------------------------------
void SetOptionDigits(PChar OptionName, Word digits)
{
  IntrfProcsRec.SetOptionDigits(IntrfProcsRec.pSetOptionDigits, OptionName, digits);
}

//-----Print text in "Journal" window in ForexTester--------------------------
void Print(PChar s)
{
  IntrfProcsRec.Print(IntrfProcsRec.pPrint, s);
}

void Print(string s){
	char* dstP;
	dstP = new char[ s.length()+1 ];
	strcpy(dstP, s.c_str());
	//strcpy_s(dstP, s.length()+1, s.c_str());
	Print( dstP );
	delete[] dstP;
}

void Print(stringstream& s){
	Print( s.str() );
}

void Print(int i){
	std::stringstream s;
	s << i;
	Print(s.str());
}

void Print(double d){
	std::stringstream s;
	s << d; 
	Print(s.str());
}

//-----Set strategy short name------------------------------------------------
void StrategyShortName(PChar name)
{
  IntrfProcsRec.StrategyShortName(IntrfProcsRec.pStrategyShortName, name);
}

//-----Set strategy description-----------------------------------------------
void StrategyDescription(PChar desc)
{
  IntrfProcsRec.StrategyDescription(IntrfProcsRec.pStrategyDescription, desc);
}

//-----Get Bid price----------------------------------------------------------
double Bid()
{
  return IntrfProcsRec.Bid(IntrfProcsRec.pBid);
}

//-----Get Ask price----------------------------------------------------------
double Ask()
{
  return IntrfProcsRec.Ask(IntrfProcsRec.pAsk);
}

//-----Currency name----------------------------------------------------------
std::string Symbol()
{
	if(IntrfProcsRec.pSymbol != NULL)
	{
		return std::string(IntrfProcsRec.Symbol(IntrfProcsRec.pSymbol));
	}
	else
	{
		return "ERROR";
	}
}

//-----Currency digits after point--------------------------------------------
int Digits()
{
  return IntrfProcsRec.Digits(IntrfProcsRec.pDigits);
}

//-----Minimal currency point-------------------------------------------------
double Point()
{
  return IntrfProcsRec.Point(IntrfProcsRec.pPoint);
}

namespace ft
{
	//-----Get open value---------------------------------------------------------
	double iOpen(PChar symbol, int TimeFrame, int index)
	{
		return IntrfProcsRec.iOpen(IntrfProcsRec.p_iOpen, symbol, TimeFrame, index);
	}

	//-----Get close value--------------------------------------------------------
	double iClose(PChar symbol, int TimeFrame, int index)
	{
		return IntrfProcsRec.iClose(IntrfProcsRec.p_iClose, symbol, TimeFrame, index);
	}

	//-----Get high value---------------------------------------------------------
	double iHigh(PChar symbol, int TimeFrame, int index)
	{
		return IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, symbol, TimeFrame, index);
	}

	//-----Get low value----------------------------------------------------------
	double iLow(PChar symbol, int TimeFrame, int index)
	{
		return IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, symbol, TimeFrame, index);
	}

	//-----Get volume-------------------------------------------------------------
	int iVolume(PChar symbol, int TimeFrame, int index)
	{
		return (int)IntrfProcsRec.iVolume(IntrfProcsRec.p_iVolume, symbol, TimeFrame, index);
	}


	//-----Get time of bar--------------------------------------------------------
	TDateTime iTime(PChar symbol, int TimeFrame, int index)
	{
		return IntrfProcsRec.iTime(IntrfProcsRec.p_iTime, symbol, TimeFrame, index);
	}

	//-----Get number of bars-----------------------------------------------------
	int iBars(const std::string& symbol, int TimeFrame)
	{
		return IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol.c_str(), TimeFrame);
	}
}

//-----Get open value in default currency and timeframe-----------------------
double Open(int index)
{
  return IntrfProcsRec.Open(IntrfProcsRec.pOpen, index);
}

//-----Get close value in default currency and timeframe----------------------
double Close(int index)
{
  return IntrfProcsRec.Close(IntrfProcsRec.pClose, index);
}

//-----Get high value in default currency and timeframe-----------------------
double High(int index)
{
  return IntrfProcsRec.High(IntrfProcsRec.pHigh, index);
}

//-----Get low value in default currency and timeframe------------------------
double Low(int index)
{
  return IntrfProcsRec.Low(IntrfProcsRec.pLow, index);
}

//-----Get volume in default currency and timeframe---------------------------
int Volume(int index)
{
  return (int)IntrfProcsRec.Volume(IntrfProcsRec.pVolume, index);
}

namespace ft
{
	//-----Get time of bar in default currency and timeframe----------------------
	TDateTime Time(int index)
	{
		return IntrfProcsRec.Time(IntrfProcsRec.pTime, index);
	}
}

//-----Get number of bars in default currency and timeframe-------------------
int Bars()
{
  return IntrfProcsRec.Bars(IntrfProcsRec.pBars);
}

//-----Set currency and timeframe---------------------------------------------
bool SetCurrencyAndTimeframe(PChar Symbol, int TimeFrame)
{
  return IntrfProcsRec.SetCurrencyAndTimeframe(IntrfProcsRec.pSetCurrencyAndTimeframe, Symbol, TimeFrame);
}

namespace ft
{
	//-----Get market information-------------------------------------------------
	double MarketInfo(PChar Symbol, TMarketInfo _type)
	{
		return IntrfProcsRec.MarketInfo(IntrfProcsRec.pMarketInfo, Symbol, _type);
	}
}

//-----Send instant order-----------------------------------------------------
bool SendInstantOrder(PChar Symbol, TInstantOrderType OperationType, double LotSize, 
  double StopLoss, double TakeProfit, PChar Comment, int MagicNumber, int& OrderHandle)
{
  return IntrfProcsRec.SendInstantOrder2(IntrfProcsRec.pSendInstantOrder2, Symbol, OperationType,
    LotSize, StopLoss, TakeProfit, Comment, MagicNumber, OrderHandle);
}

//-----Send pending order-----------------------------------------------------
bool SendPendingOrder(PChar Symbol, TPendingOrderType OperationType, double LotSize, 
  double StopLoss, double TakeProfit, double ExecutionPrice, 
  PChar Comment, int MagicNumber, int& OrderHandle)
{
  return IntrfProcsRec.SendPendingOrder2(IntrfProcsRec.pSendPendingOrder2, Symbol, OperationType,
    LotSize, StopLoss, TakeProfit, ExecutionPrice, Comment, MagicNumber, OrderHandle);
}

//-----Modify order-----------------------------------------------------------
bool ModifyOrder(int OrderHandle, double NewPrice, double StopLoss, double TakeProfit)
{
  return IntrfProcsRec.ModifyOrder(IntrfProcsRec.pModifyOrder, OrderHandle, NewPrice, StopLoss, TakeProfit);
}

//-----Delete order-----------------------------------------------------------
bool DeleteOrder(int OrderHandle)
{
  return IntrfProcsRec.DeleteOrder(IntrfProcsRec.pDeleteOrder, OrderHandle);
}

//-----Close order------------------------------------------------------------
bool CloseOrder(int OrderHandle)
{
  return IntrfProcsRec.CloseOrder(IntrfProcsRec.pCloseOrder, OrderHandle);
}

//-----Get order information--------------------------------------------------
bool GetOrderInfo(int OrderHandle, TTradePosition& info)
{
  return IntrfProcsRec.GetOrderInfo(IntrfProcsRec.pGetOrderInfo, OrderHandle, info);
}

//-----Select order-----------------------------------------------------------
bool OrderSelect(int index, TOrderSelectMode flags, TSearchMode pool)
{
  return IntrfProcsRec.OrderSelect(IntrfProcsRec.pOrderSelect, index, flags, pool);
}

//-----Get profit in dollars of selected order--------------------------------
double OrderProfit()
{
  return IntrfProcsRec.OrderProfit(IntrfProcsRec.pOrderProfit);
}

//-----Get profit in pips of selected order-----------------------------------
double OrderProfitPips()
{
  return IntrfProcsRec.OrderProfitPips(IntrfProcsRec.pOrderProfitPips);
}

//-----Check if order was closed----------------------------------------------
bool OrderClosed(int OrderHandle)
{
  return IntrfProcsRec.OrderClosed(IntrfProcsRec.pOrderClosed, OrderHandle);
}

//-----Number of closed positions---------------------------------------------
int HistoryTotal()
{
  return IntrfProcsRec.HistoryTotal(IntrfProcsRec.pHistoryTotal);
}

//-----Number of opened positions---------------------------------------------
int OrdersTotal()
{
  return IntrfProcsRec.OrdersTotal(IntrfProcsRec.pOrdersTotal);
}

namespace ft
{
	//-----Open time of selected order--------------------------------------------
	TDateTime OrderOpenTime()
	{
		return IntrfProcsRec.OrderOpenTime(IntrfProcsRec.pOrderOpenTime);
	}

	//-----Close time of selected order-------------------------------------------
	TDateTime OrderCloseTime()
	{
		return IntrfProcsRec.OrderCloseTime(IntrfProcsRec.pOrderCloseTime);
	}
}

//-----Lot size of selected order---------------------------------------------
double OrderLots()
{
  return IntrfProcsRec.OrderLots(IntrfProcsRec.pOrderLots);
}

//-----Handle of selected order-----------------------------------------------
int OrderTicket()
{
  return IntrfProcsRec.OrderTicket(IntrfProcsRec.pOrderTicket);
}

//-----Type of the selected order---------------------------------------------
TTradePositionType OrderType()
{
  return TTradePositionType(IntrfProcsRec.OrderType(IntrfProcsRec.pOrderType));
}

//-----Stop loss of selected order--------------------------------------------
double OrderStopLoss()
{
  return IntrfProcsRec.OrderStopLoss(IntrfProcsRec.pOrderStopLoss);
}

//-----Take profit of selected order------------------------------------------
double OrderTakeProfit()
{
  return IntrfProcsRec.OrderTakeProfit(IntrfProcsRec.pOrderTakeProfit);
}

//-----Open price of selected order-------------------------------------------
double OrderOpenPrice()
{
  return IntrfProcsRec.OrderOpenPrice(IntrfProcsRec.pOrderOpenPrice);
}

//-----Close price of selected order------------------------------------------
double OrderClosePrice()
{
  return IntrfProcsRec.OrderClosePrice(IntrfProcsRec.pOrderClosePrice);
}

//-----Currency of selected order---------------------------------------------
std::string OrderSymbol()
{
  return pcharToStr(IntrfProcsRec.OrderSymbol(IntrfProcsRec.pOrderSymbol));
}

//-----Get stop loss in points------------------------------------------------
int GetStopLossPoints(int OrderHandle)
{
  int result = 0;

  if (OrderSelect(OrderHandle, SELECT_BY_TICKET, MODE_TRADES))
  {
    if (OrderStopLoss() == 0) return result;

    PCurrencyInfo pInfo;
    if (!GetCurrencyInfo(OrderSymbol(), pInfo)) return result;

    result = int((OrderOpenPrice()-OrderStopLoss())/pInfo->Point);
    if (OrderType() == tp_Buy) result = -result;
  }

  return result;
}

//-----Get take profit points-------------------------------------------------
int GetTakeProfitPoints(int OrderHandle)
{
  int result = 0;

  if (OrderSelect(OrderHandle, SELECT_BY_TICKET, MODE_TRADES))
  {
    if (OrderTakeProfit() == 0) return result;
    
    PCurrencyInfo pInfo;
    if (!GetCurrencyInfo(OrderSymbol(), pInfo)) return result;

    result = int((OrderOpenPrice()-OrderTakeProfit())/pInfo->Point);
    if (OrderType() == tp_Sell) result = -result;
  }

  return result;
}


//-----Set stop loss in points------------------------------------------------
void SetStopLossPoints(int OrderHandle, int NewStopLoss)
{
  if (OrderSelect(OrderHandle, SELECT_BY_TICKET, MODE_TRADES))
  {
    PCurrencyInfo pInfo;
    if (!GetCurrencyInfo(OrderSymbol(), pInfo)) return;

    switch (OrderType())
    {
      case tp_Buy:  
      ModifyOrder(OrderHandle, OrderOpenPrice(),
        OrderOpenPrice() - NewStopLoss*pInfo->Point, OrderTakeProfit());
      break;

      case tp_Sell: 
      ModifyOrder(OrderHandle, OrderOpenPrice(),
        OrderOpenPrice() + NewStopLoss*pInfo->Point, OrderTakeProfit());
      break;
    }
  }
}

//-----Set take profit in points----------------------------------------------
void SetTakeProfitPoints(int OrderHandle, int NewTakeProfit)
{
  if (OrderSelect(OrderHandle, SELECT_BY_TICKET, MODE_TRADES))
  {
    PCurrencyInfo pInfo;
    if (!GetCurrencyInfo(OrderSymbol(), pInfo)) return;

    switch (OrderType())
    {
      case tp_Buy:  
      ModifyOrder(OrderHandle, OrderOpenPrice(),
        OrderOpenPrice() + NewTakeProfit*pInfo->Point, OrderTakeProfit());
      break;

      case tp_Sell: 
      ModifyOrder(OrderHandle, OrderOpenPrice(),
        OrderOpenPrice() - NewTakeProfit*pInfo->Point, OrderTakeProfit());
      break;
    }
  }
}

namespace ft
{
	//-----Get account balance----------------------------------------------------
	double AccountBalance()
	{
		 if (IntrfProcsRec.pAccountBalance == nullptr) return 0;
		 return IntrfProcsRec.AccountBalance(IntrfProcsRec.pAccountBalance);
	}

	//-----Get account equity-----------------------------------------------------
	double AccountEquity()
	{
		if(IntrfProcsRec.pAccountEquity == nullptr) return 0;
		return IntrfProcsRec.AccountEquity(IntrfProcsRec.pAccountEquity);
	}
}

//-----Get account margin-----------------------------------------------------
double AccountMargin()
{
  if (IntrfProcsRec.pAccountMargin == nullptr) return 0;
  return IntrfProcsRec.AccountMargin(IntrfProcsRec.pAccountMargin);
}

//-----Get account free margin------------------------------------------------
double AccountFreeMargin()
{
  if (IntrfProcsRec.pAccountFreeMargin == nullptr) return 0;
  return IntrfProcsRec.AccountFreeMargin(IntrfProcsRec.pAccountFreeMargin);
}

//-----Get account leverage---------------------------------------------------
int AccountLeverage()
{
  if (IntrfProcsRec.pAccountLeverage == nullptr) return 0;
  return IntrfProcsRec.AccountLeverage(IntrfProcsRec.pAccountLeverage);
}

//-----Get account profit-----------------------------------------------------
double AccountProfit()
{
  if (IntrfProcsRec.pAccountProfit == nullptr) return 0;
  return IntrfProcsRec.AccountProfit(IntrfProcsRec.pAccountProfit);
}

//-----Breakpoint-------------------------------------------------------------
void Breakpoint(int number, PChar text)
{
  if (IntrfProcsRec.pBreakpoint == nullptr) return;
  IntrfProcsRec.Breakpoint(IntrfProcsRec.pBreakpoint, number, text);
}


//-----Create indicator and obtaind id----------------------------------------
int CreateIndicator(PChar Symbol, int TimeFrame, PChar IndicatorName, PChar parameters)
{
  if (IntrfProcsRec.pCreateIndicator == nullptr) return 0;

  PChar IndicatorNameEx = (PChar)malloc(strlen(IndicatorName) + 4 + 1);
  strcpy(IndicatorNameEx, IndicatorName);
  strcat(IndicatorNameEx, ".dll");

  return IntrfProcsRec.CreateIndicator(IntrfProcsRec.pCreateIndicator, Symbol, TimeFrame,
    IndicatorNameEx, parameters);

  free(IndicatorNameEx);
}

//-----Get indicator value----------------------------------------------------
double GetIndicatorValue(int IndicatorHandle, int index, int BufferIndex)
{
  if (IntrfProcsRec.pGetIndicatorValue == nullptr) return 0;
  return IntrfProcsRec.GetIndicatorValue(IntrfProcsRec.pGetIndicatorValue, IndicatorHandle, index, BufferIndex);
}

//-----Get order MagicNumber--------------------------------------------------
int OrderMagicNumber()
{
  if (IntrfProcsRec.pOrderMagicNumber == nullptr) return 0;
  return IntrfProcsRec.OrderMagicNumber(IntrfProcsRec.pOrderMagicNumber);
}

namespace ft
{
	//-----Get order comment------------------------------------------------------
	PChar OrderComment()
	{
		if(IntrfProcsRec.pOrderComment == nullptr) return "";
		return IntrfProcsRec.OrderComment(IntrfProcsRec.pOrderComment);
	}
}

//-----Order swap-------------------------------------------------------------
double OrderSwap()
{
  if (IntrfProcsRec.pOrderSwap == nullptr) return 0;
  return IntrfProcsRec.OrderSwap(IntrfProcsRec.pOrderSwap);
}

//-----Pause------------------------------------------------------------------
void Pause(PChar text)
{
  if (IntrfProcsRec.pPause == nullptr) return;
  IntrfProcsRec.Pause(IntrfProcsRec.pPause, text);
}

//-----Resume-----------------------------------------------------------------
void Resume()
{
  if (IntrfProcsRec.pResume) return;
  IntrfProcsRec.Resume(IntrfProcsRec.pResume);
}


//-----Send instant order with selected price---------------------------------
bool _SendInstantOrder(PChar Symbol, TInstantOrderType OperationType, double price, 
  double LotSize, double StopLoss, double TakeProfit, PChar Comment, int MagicNumber, int& OrderHandle)
{
  if (IntrfProcsRec.p_SendInstantOrder == nullptr)
  {
    OrderHandle = -1;
    return false;  
  }

  return IntrfProcsRec._SendInstantOrder(IntrfProcsRec.p_SendInstantOrder, Symbol, OperationType,
    price, LotSize, StopLoss, TakeProfit, Comment, MagicNumber, OrderHandle);
}

//-----Close order with requested price---------------------------------------
bool _CloseOrder(int OrderHandle, double price)
{
  if (IntrfProcsRec.p_CloseOrder == nullptr) return false;
  return IntrfProcsRec._CloseOrder(IntrfProcsRec.p_CloseOrder, OrderHandle, price);
}


namespace ft
{
	//-----Create object----------------------------------------------------------
	bool ObjectCreate(const std::string& name, TObjectType ObjType, int window, 
	  TDateTime time1, double price1, TDateTime time2, double price2, 
	  TDateTime time3, double price3)
	{
	  if (IntrfProcsRec.pObjectCreate == nullptr) return false;
	  return IntrfProcsRec.ObjectCreate(IntrfProcsRec.pObjectCreate, (object_prefix_ + name).c_str(), ObjType,
		window, time1, price1, time2, price2, time3, price3);
	}

	//-----Delete object by name--------------------------------------------------
	void ObjectDelete(const std::string& name)
	{
	  if (IntrfProcsRec.pObjectDelete == nullptr) return;
	  IntrfProcsRec.ObjectDelete(IntrfProcsRec.pObjectDelete, (object_prefix_ + name).c_str());
	}

	//-----Check if object already exists-----------------------------------------
	bool ObjectExists(const std::string& name)
	{
	  if (IntrfProcsRec.pObjectExists == nullptr) return false;
	  return IntrfProcsRec.ObjectExists(IntrfProcsRec.pObjectExists, (object_prefix_ + name).c_str());
	}

	//-----Get object type--------------------------------------------------------
	TObjectType ObjectType(const std::string& name)
	{
	  if (IntrfProcsRec.pObjectType == nullptr) return obj_Text;
	  return TObjectType(IntrfProcsRec.ObjectType(IntrfProcsRec.pObjectType, (object_prefix_ + name).c_str()));
	}

	//-----Set object property----------------------------------------------------
	bool ObjectSet(const std::string& name, int index, double value)
	{
	  if (IntrfProcsRec.pObjectSet == nullptr) return false;
	  return IntrfProcsRec.ObjectSet(IntrfProcsRec.pObjectSet, (object_prefix_ + name).c_str(), index, value);
	}

	//-----Get object property----------------------------------------------------
	double ObjectGet(const std::string& name, int index)
	{
	  if (IntrfProcsRec.pObjectGet == nullptr) return 0;
	  return IntrfProcsRec.ObjectGet(IntrfProcsRec.pObjectGet, (object_prefix_ + name).c_str(), index);
	}

	//-----Delete all objects-----------------------------------------------------
	void ObjectsDeleteAll(int window, TObjectType ObjType)
	{
		if(IntrfProcsRec.pObjectsDeleteAll == nullptr) return;
		IntrfProcsRec.ObjectsDeleteAll(IntrfProcsRec.pObjectsDeleteAll, window, ObjType);
	}

	//-----Set text---------------------------------------------------------------
	bool ObjectSetText(const std::string& name, const std::string& text, int FontSize,
		const std::string& FontName, TColor Color)
	{
		std::string n(name);
		if(IntrfProcsRec.pObjectSetText == nullptr) return false;
		return IntrfProcsRec.ObjectSetText(IntrfProcsRec.pObjectSetText, (object_prefix_ + n).c_str(), text.c_str(), FontSize, FontName.c_str(), Color);
	}
}

//-----Get interface version--------------------------------------------------
void GetInterfaceVersion(int& MajorValue, int& MinorValue)
{
  if (IntrfProcsRec.pGetInterfaceVersion == nullptr)
  {
    MajorValue = 1;
    MinorValue = 4;
    return;  
  }
  
  IntrfProcsRec.GetInterfaceVersion(IntrfProcsRec.pGetInterfaceVersion, MajorValue, MinorValue);
}

//-----Get text---------------------------------------------------------------
string ObjectGetText(const std::string& name)
{
  if (IntrfProcsRec.pObjectGetText == nullptr) return string();
  return pcharToStr(IntrfProcsRec.ObjectGetText(IntrfProcsRec.pObjectGetText, (object_prefix_ + name).c_str()));
}

namespace ft
{
	//-----Get current time-------------------------------------------------------
	TDateTime  TimeCurrent()
	{
		if(IntrfProcsRec.pTimeCurrent == nullptr) return false;
		return IntrfProcsRec.TimeCurrent(IntrfProcsRec.pTimeCurrent);
	}
}

//-----Set indicator's buffer style-------------------------------------------
void SetIndicatorBuffStyle(int IndicatorHandle, int BuffIndex, TPenStyle _style,
  int width, TColor color)
{
  if (IntrfProcsRec.pSetIndicatorBuffStyle == nullptr) return;
  IntrfProcsRec.SetIndicatorBuffStyle(IntrfProcsRec.pSetIndicatorBuffStyle, IndicatorHandle, BuffIndex, _style,
    width, color);
}

namespace ft
{
	//-----Get bar shift by its time----------------------------------------------
	int iBarShift(const std::string& symbol, int TimeFrame, TDateTime time, bool Exact)
	{
		if(IntrfProcsRec.iBarShift == nullptr) return -1;

		return IntrfProcsRec.iBarShift(
			IntrfProcsRec.piBarShift,
			symbol.c_str(),
			TimeFrame,
			time,
			false  // Always false due to MT4 bug, exact true gives same result as false
		);
	}

	//-----Get highest value in array---------------------------------------------
	int iHighest(const std::string& symbol, int TimeFrame, int _type, int count, int index)
	{
		if(IntrfProcsRec.iHighest == nullptr) return -1;

		const int bars = iBars(symbol, TimeFrame);
		if(index >= bars) return -1; // MQL4 emulation

		return IntrfProcsRec.iHighest(IntrfProcsRec.piHighest, symbol.c_str(), TimeFrame, _type, count == 0 ? bars : count, index);
	}

	//-----Get lowest value in array----------------------------------------------
	int iLowest(const std::string& symbol, int TimeFrame, int _type, int count, int index)
	{
		if(IntrfProcsRec.iLowest == nullptr) return -1;

		const int bars = iBars(symbol, TimeFrame);
		if(index >= bars) return -1; // MQL4 emulation

		return IntrfProcsRec.iLowest(IntrfProcsRec.piLowest, symbol.c_str(), TimeFrame, _type, count == 0 ? bars : count, index);
	}
}

//-----Close part of position-------------------------------------------------
bool CloseOrderPartial(int OrderHandle, double LotSize)
{
  if (IntrfProcsRec.CloseOrderPartial == nullptr) return false;
  return IntrfProcsRec.CloseOrderPartial(IntrfProcsRec.pCloseOrderPartial, OrderHandle, LotSize);
}

#endif
