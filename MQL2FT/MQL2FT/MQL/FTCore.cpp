#include "pch.h"

#include "FTCore.h"

#include <random>
#include <regex>

#ifdef __STRATEGY
#include "StrategyInterfaceUnit.h"
#include "TechnicalFunctions.h"
#endif // __STRATEGY

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#endif

#pragma warning(disable : 4996)  

using namespace std;

map<int, FileData*> files;
int _last_file_handle = 1;
int _LastError;
int unsigned _RandomSeed = 17845671;

TPenStyle _draw_level_style = psDot; // line style
int       _line_level_width = 1;     // width
color     _level_clr = clSilver;     // color

const unsigned long lnNAN[2] = { 0x00000000, 0x7FF80000 };
const double negative_nan_ = -*(double*)lnNAN;
const unsigned long lnINF[2] = { 0x00000000, 0x7FF00000 };
const double negative_inf_ = -*(double*)lnINF;

UINT_PTR timer;

// Helper functions definitions
bool sandboxFnameCheck(const string& name);
bool createSubDirs(const string& fname);


#ifdef __STRATEGY

void StrategyShortName(const mql4::string& name)
{
	char *c_name = new char[name.length() + 1];
	strcpy(c_name, name.c_str());
	StrategyShortName(c_name);
}

int OrderSend(
	const mql4::string&   symbol,              // symbol
	int                  cmd,                 // operation
	double               volume,              // volume
	double               price,               // price
	int                  slippage,            // slippage
	double               stoploss,            // stop loss
	double               takeprofit,          // take profit
	const mql4::string&   comment,        // comment
	int                  magic,             // magic number
	datetime             expiration,        // pending order expiration
	color                arrow_color   // color
)
{

	int defaultOrderNumber = 0;
	int& orderHandle = defaultOrderNumber;

	std::string symb = getSymbol(symbol);
	char *c_symbol = new char[symb.length() + 1];
	strcpy(c_symbol, symb.c_str());
	char *c_comment;
	if (comment.empty())
	{
		c_comment = NULL;
	}
	else
	{
		c_comment = new char[comment.length() + 1];
		strcpy(c_comment, comment.c_str());
	}

	bool result;
	if (cmd == 0 || cmd == 1) {
		result = SendInstantOrder(c_symbol, (TInstantOrderType)cmd, volume, stoploss, takeprofit, c_comment, magic, orderHandle);
	}
	else {
		switch (cmd)
		{
		case OP_BUYLIMIT:
			cmd = op_BuyLimit;
			break;
		case OP_SELLLIMIT:
			cmd = op_SellLimit;
			break;
		case OP_BUYSTOP:
			cmd = op_BuyStop;
			break;
		case OP_SELLSTOP:
			cmd = op_SellStop;
			break;
		}

		result = SendPendingOrder(c_symbol, (TPendingOrderType)cmd, volume, stoploss, takeprofit, price, c_comment, magic, orderHandle);
	}
	if (!result) {
		SetLastError(ERR_TRADE_ERROR);
	}
	return orderHandle;
}

bool  OrderClose(
	int        ticket,      // ticket
	double     lots,        // volume
	double     price,       // close price
	int        slippage,    // slippage
	color      arrow_color // color
)
{
	bool result = CloseOrderPartial(ticket, lots);
	if (!result)
		SetLastError(ERR_TRADE_ERROR);
	return result;
}

bool OrderCloseBy(int ticket, int opposite, color Color)
{
	// Function is not implemented in API by now.
	SetLastError(ERR_CANNOT_CALL_FUNCTION);
	return false;
}

bool  OrderDelete(
	int        ticket,      // ticket
	color      arrow_color // color
)
{
	bool result = DeleteOrder(ticket);
	if (!result)
		SetLastError(ERR_TRADE_ERROR);
	return result;
}

bool  OrderModify(
	int        ticket,      // ticket
	double     price,       // price
	double     stoploss,    // stop loss
	double     takeprofit,  // take profit
	datetime   expiration,  // expiration
	color      arrow_color  // color
)
{
	bool result = ModifyOrder(ticket, price, stoploss, takeprofit);
	if (!result)
		SetLastError(ERR_TRADE_ERROR);
	return result;
}

double OrderCommission()
{
	TTradePosition info;
	GetOrderInfo(OrderTicket(), info);
	return info.commission;
}

datetime  OrderOpenTime() 
{
	return datetime::FromVariantTime(ft::OrderOpenTime());
}

datetime OrderCloseTime()
{
	double close_time = ft::OrderCloseTime();

	if (!OrderClosed(OrderTicket())) return datetime::None();
	return datetime::FromVariantTime(close_time);
}

datetime OrderExpiration()
{
	SetLastError(ERR_TRADE_EXPIRATION_DENIED);
	return 0;
}

void OrderPrint()
{
	string order_type;
	switch(OrderType())
	{
	case OP_BUY:
		order_type = "buy";
		break;
	case OP_SELL:
		order_type = "sell";
		break;
	case OP_BUYLIMIT:
		order_type = "buylimit";
		break;
	case OP_BUYSTOP:
		order_type = "buystop";
		break;
	case OP_SELLLIMIT:
		order_type = "sellimit";
		break;
	case OP_SELLSTOP:
		order_type = "sellstop";
		break;
	}

	TTradePosition info;
	GetOrderInfo(OrderTicket(), info);

	string s = " ";

	string close_t;
	if(OrderCloseTime() != 0)
	{
		close_t = " " + TimeToStr(OrderCloseTime());
	}
	
	Print("#", OrderTicket(), s, TimeToStr(OrderOpenTime()), s, order_type, s, OrderLots(), s, OrderSymbol(), s, OrderOpenPrice(),
		s, OrderStopLoss(), s, OrderTakeProfit(), close_t, s, OrderClosePrice(), s, info.commission, s, OrderSwap(), s,
		OrderProfit(), s, OrderComment(), s, OrderMagicNumber());
}

#endif // __STRATEGY

double AccountBalance()
{
#ifdef __STRATEGY
	return ft::AccountBalance();
#endif
#ifdef __INDICATOR
	return 0;
#endif
}

double AccountEquity()
{
#ifdef __STRATEGY
	return ft::AccountEquity();
#endif
#ifdef __INDICATOR
	return 0;
#endif
}

double MarketInfo(const mql4::string& symbol, int type)
{
	std::string symb = getSymbol(symbol);
	
	if(type == 9) // Translate MQL codes
	{
		type = MODE_BID;
	}
	else if(type == 10)
	{
		type = MODE_ASK;
	}

	switch (type)
	{
	case MODE_BID:
		return Bid();
	case MODE_ASK:
		return Ask();
	case MODE_TICKVALUE:
		return 1;
	case MODE_LOTSIZE:
		return 100000;
	case MODE_MARGINREQUIRED:
		return 1000;


	case MODE_MINLOT:
		return 0.1;
	case MODE_MAXLOT:
		return 100;
	case MODE_STOPLEVEL:
		return 0;
	case MODE_LOTSTEP:
		return 0.1;
	case MODE_TRADEALLOWED:
		return true;
	case MODE_FREEZELEVEL:
		return 0;

	default:
		PCurrencyInfo info;

		const bool res = GetCurrencyInfo(symb, info);
		double result;
		
		switch (type)
		{
		case MODE_POINT:
		case MODE_TICKSIZE:
			result = res ? info->Point : 0.00001;
			break;
		case MODE_DIGITS:
			result = res ? info->Digits : 5;
			break;
		case MODE_SPREAD:
			result = res ? info->spread : 0.0005;
			break;
		default:
			result = 0.0;
		}
		
		return result;
	}
}

double  SymbolInfoDouble(const mql4::string& name, ENUM_SYMBOL_INFO_DOUBLE prop_id)
{	
	std::string n = getSymbol(name);
	
	PCurrencyInfo cinf;
	if(!GetCurrencyInfo((char*)n.c_str(), cinf))
	{
		SetLastError(4024);
		return 0.0;
	}
	
	switch(prop_id)
	{
	case SYMBOL_BID:
#ifdef __STRATEGY
		return ft::MarketInfo((char*)n.c_str(), MODE_BID);
#else
		SetLastError(4024);
		return 0.0;
#endif
		break;

	case SYMBOL_BIDHIGH: // Not supported in MQL
	case SYMBOL_BIDLOW:
		SetLastError(4051);
		return 0.0;
		break;

	case SYMBOL_ASK:
#ifdef __STRATEGY
		return ft::MarketInfo((char*)n.c_str(), MODE_ASK);
#else
		SetLastError(4024);
		return 0.0;
#endif
		break;

	case SYMBOL_ASKHIGH: // Not supported in MQL
	case SYMBOL_ASKLOW:
	case SYMBOL_LAST:
	case SYMBOL_LASTHIGH:
	case SYMBOL_LASTLOW:
		SetLastError(4051);
		return 0.0;
		break;

	case SYMBOL_POINT:
		return cinf->Point;
		break;
	case SYMBOL_TRADE_TICK_VALUE: // Not supported in FT
		SetLastError(4024);
		return 0.0;
		break;

	case SYMBOL_TRADE_TICK_VALUE_PROFIT: // Not supported in MQL
	case SYMBOL_TRADE_TICK_VALUE_LOSS:
		SetLastError(4051);
		return 0.0;
		break;

	case SYMBOL_TRADE_TICK_SIZE: // Not supported in FT
	case SYMBOL_TRADE_CONTRACT_SIZE:
	case SYMBOL_VOLUME_MIN:
	case SYMBOL_VOLUME_MAX:
	case SYMBOL_VOLUME_STEP:
	case SYMBOL_VOLUME_LIMIT:
		SetLastError(4024);
		return 0.0;
		break;

	case SYMBOL_SWAP_LONG:
		return cinf->SwapLong;
		break;
	case SYMBOL_SWAP_SHORT:
		return cinf->SwapShort;
		break;

	case SYMBOL_MARGIN_INITIAL: // Not supported in FT
	case SYMBOL_MARGIN_MAINTENANCE:
		SetLastError(4024);
		return 0.0;
		break;

	case SYMBOL_MARGIN_LONG: // Not supported in MQL
	case SYMBOL_MARGIN_SHORT:
	case SYMBOL_MARGIN_LIMIT:
	case SYMBOL_MARGIN_STOP:
	case SYMBOL_MARGIN_STOPLIMIT:
	case SYMBOL_SESSION_VOLUME:
	case SYMBOL_SESSION_TURNOVER:
	case SYMBOL_SESSION_INTEREST:
	case SYMBOL_SESSION_BUY_ORDERS_VOLUME:
	case SYMBOL_SESSION_SELL_ORDERS_VOLUME:
	case SYMBOL_SESSION_OPEN:
	case SYMBOL_SESSION_CLOSE:
	case SYMBOL_SESSION_AW:
	case SYMBOL_SESSION_PRICE_SETTLEMENT:
	case SYMBOL_SESSION_PRICE_LIMIT_MIN:
	case SYMBOL_SESSION_PRICE_LIMIT_MAX:
	default:
		SetLastError(4051);
		return 0.0;
		break;
	}
}

bool  SymbolInfoDouble(const mql4::string& name, ENUM_SYMBOL_INFO_DOUBLE prop_id, double& double_var)
{
	_LastError = 0;
	const double result = SymbolInfoDouble(name, prop_id);
	if(_LastError == 4051 || _LastError == 4024)
	{
		return false;
	}

	double_var = result;
	return true;
}

mqllong SymbolInfoInteger(const mql4::string& name, ENUM_SYMBOL_INFO_INTEGER prop_id)
{
	std::string n = getSymbol(name);

	PCurrencyInfo cinf;
	if(!GetCurrencyInfo((char*)n.c_str(), cinf))
	{
		SetLastError(4024);
		return 0;
	}
	
	switch(prop_id)
	{
	case SYMBOL_SELECT: // Not supported in FT
	case SYMBOL_VISIBLE:
		SetLastError(4024);
		return 0;
		break;

	case SYMBOL_SESSION_DEALS: // Not supported in MQL
	case SYMBOL_SESSION_BUY_ORDERS:
	case SYMBOL_SESSION_SELL_ORDERS:
	case SYMBOL_VOLUME:
	case SYMBOL_VOLUMEHIGH:
	case SYMBOL_VOLUMELOW:
		SetLastError(4051);
		return 0;
		break;

	case SYMBOL_TIME:
		return (time_t)datetime(iTime(n, Timeframe(), 0));
		break;
	case SYMBOL_DIGITS:
		return cinf->Digits;
		break;

	case SYMBOL_SPREAD_FLOAT: // Not supported in FT
		SetLastError(4024);
		return 0;
		break;

	case SYMBOL_SPREAD:
		return cinf->spread;
		break;

	case SYMBOL_TRADE_CALC_MODE: // Not supported in FT
	case SYMBOL_TRADE_MODE:
	case SYMBOL_START_TIME:
	case SYMBOL_EXPIRATION_TIME:
	case SYMBOL_TRADE_STOPS_LEVEL:
	case SYMBOL_TRADE_FREEZE_LEVEL:
	case SYMBOL_TRADE_EXEMODE:
	case SYMBOL_SWAP_MODE:
	case SYMBOL_SWAP_ROLLOVER3DAYS:
		SetLastError(4024);
		return 0;
		break;

	case SYMBOL_EXPIRATION_MODE: // Not supported in MQL
	case SYMBOL_FILLING_MODE:
	case SYMBOL_ORDER_MODE:
		SetLastError(4051);
		return 0;
		break;
	}
}

bool  SymbolInfoInteger(const mql4::string& name, ENUM_SYMBOL_INFO_INTEGER prop_id, mqllong& mqllong_var)
{
	_LastError = 0;
	const mqllong result = SymbolInfoInteger(name, prop_id);
	if(_LastError == 4051 || _LastError == 4024)
	{
		return false;
	}

	mqllong_var = result;
	return true;
}

int MessageBox(const mql4::string& text, const mql4::string& caption, int flags)
{
#ifdef __INDICATOR
	return 0;
#else
	return MessageBoxA(nullptr, text.c_str(), caption.c_str(), flags);
#endif
}

IndicatorStorage indicatorStorage;
GlobalVariablesStore globalVariableStore;

#ifdef __INDICATOR

map<int, PropertyStyle*> __property_styles;

bool SetIndexBuffer(int index, const IndexBuffer& container)
{
	container.SetBuffer(index);
	return true;
}

bool SetIndexBuffer(int index, const IndexBuffer& container, ENUM_INDEXBUFFER_TYPE data_type)
{
	return SetIndexBuffer(index, container);
}

TDrawStyle FromMQLDrawStyle(int type) 
{
	switch (type) {
	case DRAW_LINE:
		return ds_Line;
	case DRAW_SECTION:
		return ds_Section;
	case DRAW_HISTOGRAM:
		return ds_Histogram;
	case DRAW_ARROW:
		return ds_Symbol;
	case DRAW_ZIGZAG:
		return ds_Section;
	case DRAW_NONE:
		return ds_None;
	default:
		return (TDrawStyle)type;
	}
}

void SetIndexStyle(int index, int type, int style, int width, const color& clr)
{
	TDrawStyle drawstyle = FromMQLDrawStyle(type);
	PropertyStyle* saved;
	if (__property_styles.find(index) == __property_styles.end())
	{
		saved = new PropertyStyle();
		__property_styles[index] = saved;
	}
	else
	{
		saved = __property_styles[index];

		if(saved->type == drawstyle && saved->style == style && saved->width == width && saved->color == clr)
		{
			return;
		}
	}

	bool something_changed = false;

	if (style != EMPTY && saved->style != style)
	{
		saved->style = style;
		something_changed = true;
	}
	TPenStyle penstyle = (saved->style == EMPTY) ? psSolid : (TPenStyle)saved->style;

	if(width != EMPTY && saved->width != width)
	{
		saved->width = width;
		something_changed = true;
	}

	if(saved->width == EMPTY)
	{
		width = 1;
	}
	else
	{
		width = saved->width;
	}

	if (clr != clrNONE && saved->color != clr)
	{
		saved->color = clr;
		something_changed = true;
	}

	if(saved->type != drawstyle)
	{
		saved->type = drawstyle;
		something_changed = true;
	}

	if(!something_changed)
	{
		return;
	}

	unsigned long col = (unsigned long)saved->color;
	ft::SetIndexStyle(index, (TDrawStyle)saved->type, penstyle, width, col);
}

void SetIndexArrow(int index, int code)
{
	SetIndexSymbol(index, code);
}

void SetLevelValue(int level, double value)
{
	// TODO: when FT will support deleting levels, implement MT index functionality

	static std::list<double> levels;

	if(std::find(levels.begin(), levels.end(), value) != levels.end())
	{
		return;
	}
	
	levels.push_back(value);
	AddLevel(value, _draw_level_style, _line_level_width, (unsigned long)_level_clr);
}

void SetLevelStyle(int draw_style, int line_width, const color& clr)
{
	_draw_level_style = (TPenStyle)draw_style;
	_line_level_width = line_width;
	if (clr != CLR_NONE) _level_clr = clr;
}

void SetIndexShift(int index, int shift)
{
	SetBufferShift(index, shift);
}

extern string ft_api_indicator_short_name;
extern int ft_api_indicator_window;

int WindowFind(const mql4::string& name)
{
	return name == ft_api_indicator_short_name ? ft_api_indicator_window : -1;
}

#endif


double iATR(const mql4::string& symbol, int timeframe, int period, int shift)
{
	if (shift < 0 || period <= 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getAtrValue(symbol, timeframe, period, shift);
}

double  iCCI(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift)
{
	if (shift < 0 || period <= 0 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getCciValue(symbol, timeframe, period, applied_price, shift);
}

double iMA(const mql4::string& symbol, int timeframe, int ma_period, int ma_shift, int ma_method, int applied_price, int shift)
{
	if (ma_period <= 0 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	switch (ma_method)
	{
		case MODE_EMA:
		{
			return indicatorStorage.getEmaValue(symbol, timeframe, ma_period, applied_price, ma_shift + shift);
		}

		case MODE_SMA:
		{
			return indicatorStorage.getSmaValue(symbol, timeframe, ma_period, applied_price, ma_shift + shift);
		}

		case MODE_LWMA:
		{
			return indicatorStorage.getWmaValue(symbol, timeframe, ma_period, applied_price, ma_shift + shift);
		}

		case MODE_SMMA:
		{
			return indicatorStorage.getSmmaValue(symbol, timeframe, ma_period, applied_price, ma_shift + shift);
		}

		default:
		{
			return 0.0;
		}
	}
}

double iMACD(const mql4::string& symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period,
	int applied_price, int mode, int shift)
{
	if (shift < 0 || fast_ema_period <= 0 || slow_ema_period <= 0 || signal_period <= 0 ||
		applied_price < 0 || applied_price > 6 || mode < 0 || mode > 1) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getMacdValue(symbol, timeframe, applied_price, fast_ema_period, slow_ema_period,
		signal_period, mode, shift);
}

double iOsMA(const mql4::string& symbol, int timeframe, int fast_ema_period, int slow_ema_period, int signal_period,
	int applied_price, int shift)
{
	if (shift < 0 || fast_ema_period <= 0 || slow_ema_period <= 0 || signal_period <= 0 ||
		applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getOsmaValue(symbol, timeframe, applied_price, fast_ema_period, slow_ema_period,
		signal_period, shift);
}

double iRSI(const mql4::string& symbol, int timeframe, int period, int priceType, int shift)
{
	if (shift < 0 || period <= 0 || priceType < 0 || priceType > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getRsiValue(symbol, timeframe, period, priceType, shift);
}

double iAO(const mql4::string& symbol, int timeframe, int shift)
{
	if (shift < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getAoValue(symbol, timeframe, shift);
}

double iBearsPower(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift)
{
	if (shift < 0 || period <= 0 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getBearsPowerValue(symbol, timeframe,period,applied_price,shift);
}

double iBullsPower(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift)
{
	if (shift < 0 || period <= 0 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getBullsPowerValue(symbol, timeframe, period, applied_price, shift);
}

double iForce(const mql4::string& symbol, int timeframe, int period, int ma_method, int applied_price, int shift)
{
	if (shift < 0 || period <= 0 || ma_method < 0 || ma_method > 3 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getForceIndexValue(symbol, timeframe, period, (ENUM_MA_METHOD)ma_method, applied_price,
		shift);
}

double iMomentum(const mql4::string& symbol, int timeframe, int period, int applied_price, int shift)
{
	if (shift < 0 || period <= 0 || applied_price < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	if(shift + period >= Bars())
	{
		return 0.0;
	}

	double result{};

	switch (applied_price)
	{
	case PRICE_CLOSE:
		{
			result = iClose(symbol, timeframe, shift) / iClose(symbol, timeframe, shift + period) * 100.0;
			break;
		}

		case PRICE_OPEN:
		{
			result = iOpen(symbol, timeframe, shift) / iOpen(symbol, timeframe, shift + period) * 100.0;
			break;
		}

		case PRICE_HIGH:
		{
			result = iHigh(symbol, timeframe, shift) / iHigh(symbol, timeframe, shift + period) * 100.0;
			break;
		}

		case PRICE_LOW:
		{
			result = iLow(symbol, timeframe, shift) / iLow(symbol, timeframe, shift + period) * 100.0;
			break;
		}

		case PRICE_MEDIAN:
		{
			result = ((iHigh(symbol, timeframe, shift) + iLow(symbol, timeframe, shift)) / 2.0) /
				     ((iHigh(symbol, timeframe, shift + period) + iLow(symbol, timeframe, shift + period)) / 2.0) *
				     100.0;
			break;
		}

		case PRICE_TYPICAL:
		{
			result = ((iHigh(symbol, timeframe, shift) + iLow(symbol, timeframe, shift) +
				       iClose(symbol, timeframe, shift)) / 3.0) /
				     ((iHigh(symbol, timeframe, shift + period) + iLow(symbol, timeframe, shift + period) +
					   iClose(symbol, timeframe, shift + period)) / 3.0) * 100.0;
			break;
		}

		case PRICE_WEIGHTED:
		{
			result = (((iHigh(symbol, timeframe, shift) + iLow(symbol, timeframe, shift) +
				        iClose(symbol, timeframe, shift)) * 2.0) / 4.0) /
				     (((iHigh(symbol, timeframe, shift + period) + iLow(symbol, timeframe, shift + period) +
						iClose(symbol, timeframe, shift + period)) * 2.0) / 4.0) * 100.0;
			break;
		}

		default:
			return 0.0;
	}

	return result;
}

double iEnvelopes(const mql4::string& symbol, int timeframe, int ma_period, int ma_method,
	int ma_shift, int applied_price, double deviation, int mode, int shift)
{
	if (ma_period <= 0 || ma_method < 0 || ma_method > 3 || applied_price < 0 || applied_price > 6 ||
		mode < 0 || mode > 2) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getEnvelopesValue(symbol, timeframe, ma_period, (ENUM_MA_METHOD)ma_method,
		applied_price, deviation, mode, ma_shift + shift);
}

double iAD(const mql4::string& symbol, int timeframe, int shift)
{
	if (shift < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getAdValue(symbol, timeframe, shift);
}

double iMFI(const mql4::string& symbol, int timeframe, int period, int shift)
{
	if (shift < 0 || period <= 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getMfiValue(symbol, timeframe, period, shift);
}

double iStochastic(const mql4::string& symbol, int timeframe, int k_period, int d_period, int slowing,
	int ma_method, int price_field, int mode, int shift)
{
	if (shift <0 || k_period <= 0 || d_period <= 0 || slowing <= 0 || ma_method < 0 || ma_method > 3 ||
		mode < 0 || mode > 1) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	if (price_field > STO_CLOSECLOSE) price_field = STO_LOWHIGH;

	return indicatorStorage.getStochasticValue(symbol, timeframe, k_period, d_period, slowing,
		(ENUM_MA_METHOD)ma_method, (ENUM_STO_PRICE)price_field, mode, shift);
}

double iStdDev(const mql4::string& symbol, int timeframe, int ma_period, int ma_shift, int ma_method,
	int applied_price, int shift)
{
	if (ma_period <= 0 || ma_method < 0 || ma_method > 3 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getStdDevValue(symbol, timeframe, applied_price, (ENUM_MA_METHOD)ma_method, ma_period,
		ma_shift + shift);
}

double iBands(const mql4::string& symbol, int timeframe, const int period, const double deviation,
	const int bands_shift, const int price_type, const int mode, int shift)
{
	if (period <= 0 || price_type < 0 || price_type > 6 || mode < 0 || mode > 2) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getBandsValue(symbol, timeframe, period, deviation, price_type, mode, bands_shift + shift);
}

double iOBV(const mql4::string& symbol, int timeframe, int applied_price, int shift)
{
	if (shift < 0 || applied_price < 0 || applied_price > 6) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getOnBalanceVolumeValue(symbol, timeframe, applied_price, shift);
}

double iSAR(const mql4::string& symbol, int timeframe, double step, double maximum, int shift)
{
	if (shift < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getSarValue(symbol, timeframe, step, maximum, shift);
}

double iAC(const mql4::string& symbol, int timeframe, int shift)
{
	if (shift < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getAcValue(symbol, timeframe, shift);
}

double iDeMarker(const mql4::string& symbol, int timeframe, int period, int shift)
{
	if (shift < 0 || period <= 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getDeMarkerValue(symbol, timeframe, period, shift);
}

double iWPR(const mql4::string& symbol, int timeframe, int period, int shift)
{
	if (shift < 0 || period <= 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getWprValue(symbol, timeframe, period, shift);
}

double iADX(const mql4::string& symbol, int timeframe, int period, int applied_price, int mode, int shift)
{
	if (shift < 0 || period <= 0 || applied_price < 0 || applied_price > 6 || mode < 0 || mode > 2) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getAdxValue(symbol, timeframe, period, applied_price, mode, shift);
}

double iRVI(const mql4::string& symbol, int timeframe, int period, int mode, int shift)
{
	if (shift < 0 || period <= 0 || mode < 0 || mode > 1) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getRviValue(symbol, timeframe, period, mode, shift);
}

double iIchimoku(const mql4::string& symbol, int timeframe, int tenkan_sen, int kijun_sen, int senkou_span_b,
	int mode, int shift)
{
	if (tenkan_sen <= 0 || kijun_sen <= 0 || senkou_span_b <= 0 || mode < 1 || mode > 5) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getIchimokuValue(symbol, timeframe, tenkan_sen, kijun_sen, senkou_span_b,
		mode, shift);
}

double iFractals(const mql4::string& symbol, int timeframe, int mode, int shift)
{
	if (shift < 0) return 0.0;
	if (timeframe < 0) timeframe = Timeframe();
	return indicatorStorage.getFractalsValue(symbol, timeframe, mode, shift);
}

mql4::string DoubleToStr(double value, int digits)
{
	stringstream ss;
	if (digits < 0) {
		ss << scientific;
	}
	else {
		ss << fixed;
	}
	ss << std::setprecision(abs(digits)) << value;
	return ss.str();
}

mql4::string DoubleToString(double value, int digits)
{
	return DoubleToStr(value, digits);
}

mql4::string IntegerToString(mqllong number, int str_len, ushort fill_symbol)
{
	if (str_len < 0) str_len = 0;
	stringstream ss;
	char symbol = static_cast<char>(fill_symbol);
	ss << setfill(symbol) << setw(str_len) << number;
	return ss.str();
}

int StrToInteger(const mql4::string& value)
{
	stringstream ss;
	ss << value;
	int val_int;
	ss >> val_int;
	return val_int;
}

mqllong StringToInteger(const mql4::string& value)
{
	stringstream ss;
	ss << value;
	mqllong val_mqllong;
	ss >> val_mqllong;
	return val_mqllong;
}

double StrToDouble(const mql4::string& value)
{
	stringstream ss;
	ss << value;
	char last = value[value.length() - 1];
	if (toupper(last) == 'E') ss << "+0";
	double val_double;
	ss >> val_double;
	return val_double;
}

double  StringToDouble(const mql4::string& value)
{
	return StrToDouble(value);
}

mql4::string TimeToStr(const datetime& value, int mode)
{
	return value.ToString((TimeOutputMode)mode);
}

mql4::string TimeToString(const datetime& value, int mode)
{
	return value.ToString((TimeOutputMode)mode);
}

inline datetime TimeFromString(const mql4::string& value)
{
	const std::string val = value;
	regex reTime("(\\d{1,2}):(\\d{1,2})");
	smatch sres;
	if (regex_match(val.begin(), val.end(), sres, reTime))
	{
		int h = stoi(sres[1]);
		if (h > -1 && h < 24) {
			int m = stoi(sres[2]);
			if (m > -1 && m < 60)
			{
				return datetime(h, m);
			}
		}
	}
}

inline datetime DateFromString(const mql4::string& value)
{
	const std::string val = value;
	regex reDate("(\\d{4})[./](\\d{1,2})[./](\\d{1,2})");
	smatch sres;
	if (regex_match(val.begin(), val.end(), sres, reDate))
	{
		int year = stoi(sres[1]);
		if (year > 0)
		{
			int month = stoi(sres[2]);
			if (month > 0 && month < 13)
			{
				int day = stoi(sres[3]);
				if (day > 0 && day < 32)
				{
					return datetime(year, month, day);
				}
			}
		}
	}
}

inline datetime DateTimeFromString(const mql4::string& value)
{
	const std::string val = value;
	regex reDateTime("(\\d{4})[./](\\d{1,2})[./](\\d{1,2}) (\\d{1,2}):(\\d{1,2})");
	smatch sres;
	if (regex_match(val.begin(), val.end(), sres, reDateTime))
	{
		int year = stoi(sres[1]);
		if (year > 0)
		{
			int month = stoi(sres[2]);
			if (month > 0 && month < 13)
			{
				int day = stoi(sres[3]);
				if (day > 0 && day < 32)
				{
					int h = stoi(sres[4]);
					if (h > -1 && h < 24) {
						int m = stoi(sres[5]);
						if (m > -1 && m < 60)
						{
							return datetime(year, month, day, h, m);
						}
					}
				}
			}
		}
	}
}

datetime StrToTime(const mql4::string& value)
{
	size_t length = value.length();
	if (length > 2 && length < 6) 
	{
		return TimeFromString(value);
	}
	else if (length > 7 && length < 11)
	{
		return DateFromString(value);
	}
	else if (length > 10 && length < 17)
	{
		return DateTimeFromString(value);
	}
	
	return datetime();
}

datetime StringToTime(const mql4::string& value)
{
	return StrToTime(value);
}

mql4::string CharToStr(uchar char_code)
{
	return string(1, (char)char_code);
}

int StringToCharArray(const mql4::string& text_string, Array<uchar>& arr, int start, int count, uint codepage)
{
	size_t string_size = text_string.size();

	if (start > string_size) return 0;

	if (count == -1 || start + count > string_size) {
		count = string_size + 1;
	}
	size_t new_size = start + count;

	if (arr.Count() < new_size)
	{
		arr.Resize(new_size);
	}

	for (size_t i = 0; i < count; i++)
	{
		arr[start + i] = static_cast<uchar>(text_string[i]);
	}

	return count;
}

mql4::string CharArrayToString(Array<uchar>& arr, int start, int count, uint codepage)
{
	size_t arr_size = arr.Count();
	if (start >= arr_size) return "";
	if (count == -1 || start + count > arr_size) count = arr_size - start;

	stringstream ss;
	for (size_t i = start; i < start + count; i++)
	{
		ss << static_cast<uchar>(arr[i]);
	}

	return ss.str();
}

int  TimeDay(
	const datetime&      date            // date and time
) {
	return date.DayOfMonth();
}

int  TimeHour(
	const datetime&      date            // date and time
) {
	return date.Hours();
}

int  TimeDayOfWeek(
	const datetime&      date            // date and time
) {
	return date.DayOfWeek();
}

int TimeDayOfYear(
	const datetime&      date
) {
	return date.DayOfYear() + 1;
}

int  TimeMonth(
	const datetime&      date            // date and time
) {
	return date.Month();
}

int  TimeMinute(
	const datetime&      date            // date and time
) {
	return date.Minutes();
}

int  TimeYear(
	const datetime&      date            // date and time
) {
	return date.Year();
}

int  TimeSeconds(
	const datetime&      date            // date and time
) {
	return date.Seconds();
}

mql4::string WindowExpertName()
{
	char path[MAX_PATH];
	HMODULE hm = NULL;

	GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		(LPCSTR)&DayOfWeek, &hm);

	GetModuleFileNameA(hm, path, sizeof(path));

	const auto pos = string(path).find_last_of("\\/");
	const string full_dll_name = string(path).substr(pos + 1);

	return full_dll_name.substr(0, full_dll_name.find_last_of('.'));
}

namespace mql4
{
	int GetLastError()
	{
		return _LastError;
	}
}

void ResetLastError()
{
	_LastError = 0;
	SetLastError((DWORD)0);
}

void SetLastError(int err_code)
{
	_LastError = err_code;
	SetLastError((DWORD)err_code);
}

double mqlRound(double x)
{
	double integer = (int)x;
	double frac = x - integer;

	if(fabs(frac - 0.5) < 1e-8 || frac > 0.5)
	{
		return integer + 1.0;
	}
	
	return integer;
}

double NormalizeDouble(double value, int digits)
{
	double integer = (int)value;
	double frac = value - integer;
	if (digits < 0) digits = 0;
	double pw = pow(10, digits);
	return integer + mqlRound(frac * pw) / pw;
}

mql4::string EnumToString(const mql4::MqlEnum& enume)
{
	return enume.ToStr();
}

mql4::string EnumToString(int enume)
{
	return "";
}

bool RefreshRates()
{
	return true;
}

datetime TimeLocal()
{
	return TimeCurrent();
}

datetime LocalTime()
{
	return TimeCurrent();
}

int Period()
{
	return Timeframe();
}

void mql2ft_setFullFileName(mql4::string& file_name)
{
	char buf[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, buf);

	string full_fname(buf);

	string dots;

	if(full_fname.substr(full_fname.find_last_of('\\')+1) != "Scripts")
	{
		dots = "../../../";
	}
	else
	{
		dots = "../";
	}


#ifdef __STRATEGY
	file_name = dots + "Strategies/" + file_name;
#endif
#ifdef __INDICATOR
	file_name = dots + "Indicators/" + file_name;
#endif

}

bool FileIsExist(mql4::string file_name, int common_flag)
{
	if(!sandboxFnameCheck(file_name))
	{
		SetLastError(ERR_FILE_WRONG_FILENAME);
		return INVALID_HANDLE;
	}
	
	struct stat buffer;
	mql2ft_setFullFileName(file_name);
	return (stat(file_name.c_str(), &buffer) == 0);
	/*ifstream fi(file_name.c_str());
	return static_cast<bool>(fi);*/
}

bool FileDelete(mql4::string file_name, int common_flag)
{
	if(!sandboxFnameCheck(file_name))
	{
		SetLastError(ERR_FILE_WRONG_FILENAME);
		return INVALID_HANDLE;
	}
	
	mql2ft_setFullFileName(file_name);
	bool ret = (remove(file_name.c_str()) == 0);
	if (!ret) {
#ifdef ENABLE_DEBUG_PRINTS
		Print(strerror(errno));
#endif

		/*for (auto i =  files.begin(); i != files.end(); i++)
		{
			if (i->second->stream->is_open())
				Print(i->first);
		}*/
	}
	return ret;
}

bool FileIsEnding(int file_handle)
{
	auto fdata = __getFileData(file_handle);
	if (fdata)
	{
		return fdata->stream->peek() == EOF;
	}
	else return 1;
}

int FileOpen(mql4::string file_name, int open_flags, short delimiter, uint codepage)
{
	if(!sandboxFnameCheck(file_name))
	{
		SetLastError(ERR_FILE_WRONG_FILENAME);
		return INVALID_HANDLE;
	}
	
	const string orig_fname = file_name;
	mql2ft_setFullFileName(file_name);
	
	FileData* fd = new FileData();
	fd->flags = open_flags;
	if (!fd->isBinary() && !fd->isCSV()) fd->flags |= FILE_TXT;

	std::ios_base::openmode mode = (std::ios_base::openmode)0;
	if (fd->isBinary()) { mode |= ios::binary; }

	if (fd->canRead())
	{
		mode |= ios::in;

		if(fd->canWrite())
		{
			fstream tmp(file_name, ios::in);
			if(!tmp.is_open())
			{
				tmp.open(file_name, ios::out);
			}
			tmp.close();
		}
	}

	if (fd->canWrite())
	{  
		mode |= ios::out;
		createSubDirs(orig_fname);
	}
	if (fd->rewrite()) 
	{  
		mode |= ios::trunc;
	}

	fstream* fs = new fstream(file_name, mode);

	if (*fs) {
		fd->stream = fs;
		fd->size = fd->stream->tellp();

		if (fd->rewrite()) {
			fd->writepos = 0;
			fs->seekp(0);
		}
		else { fd->writepos = fd->stream->tellp(); }

		fs->seekg(0);

		if (delimiter == -1) {
			if (fd->isCSV()) delimiter = ';';
			else if (fd->isTXT()) delimiter = 0;
		}
		fd->delimiter = delimiter;

		files[_last_file_handle] = fd;
		return _last_file_handle++;
	}
	else {
		return INVALID_HANDLE;
	}
}

int FileOpen(mql4::string file_name, int open_flags, const mql4::string& delimiter, uint codepage)
{
	return FileOpen(file_name, open_flags, (short)delimiter[0], codepage);
}


uint FileWriteString(int file_handle, const mql4::string& text_string, int length)
{
	stringstream ss;
	ss << text_string;
	if (length == -1) length = text_string.length();

	return __file_write(file_handle, ss, length);

}

uint FileWriteInteger(int file_handle, int value, int size)
{
    if (size < CHAR_VALUE || size > LONG_VALUE || size == 3)
        size = LONG_VALUE;

    stringstream ss;
    ss.write((const char*)&value, size);
    return __file_write(file_handle, ss, size);
}

uint FileWriteDouble(int file_handle, double value, int size)
{
    if (size != FLOAT_VALUE && size != DOUBLE_VALUE)
        size = DOUBLE_VALUE;

    stringstream ss;
    if (size == FLOAT_VALUE) {
        float flt_value = (float)value;
        ss.write((const char*)&flt_value, size);
    }
    else {
        ss.write((const char*)&value, size);
    }
    return __file_write(file_handle, ss, size);
}

FileData* __getFileData(int file_handle) {
	map<int, FileData*>::iterator it = files.find(file_handle);
	if (it != files.end()) {
		return it->second;
	}
	else return nullptr;
}

uint __file_write(int  file_handle, stringstream& ss, int length)
{
	auto fd = __getFileData(file_handle);
	
	bool nl = false;

	if (fd != nullptr) {
		size_t prev_pos = fd->stream->tellp();

		string str = ss.str();
		if (length != -1) 
		{
			if (length == 0) length = ss.tellg();
			else if ((int)ss.tellg() != length) 
			{
				if (fd->isBinary()) {
					char* buff = new char[length];
					strncpy(buff, str.c_str(), length);
					ss.write(buff, length);
				}
			}
		}
		else {
			nl = true;
			length = str.length();
		}

		if (fd->size != -1 && fd->writepos > fd->size) {

			int diff = fd->writepos - fd->size;
			for (size_t i = 0; i < diff; i++) {
				fd->stream->put(' ');
			}
		}

		fd->stream->write(str.c_str(), length);

		if (nl) {
			fd->stream->write("\n", 1);
		}

		size_t pos = fd->stream->tellp();
		size_t diff = pos - prev_pos;
		fd->writepos += diff;
		if (pos > fd->size) fd->size = pos;

		return uint(diff);
	}
	else {
		return 0;
	}
}

void FileClose(int file_handle)
{
	auto fd = __getFileData(file_handle);
	if (fd) {
		fd->stream->close();
		files.erase(file_handle);
		delete fd->stream;
		delete fd;
	}
}

void _close_files()
{
	for(auto i = files.begin(); i != files.end(); i++)
	{
		i->second->stream->close();
		delete i->second->stream;
		delete i->second;
	}
	files.clear();
}

mql4::string FileReadString(int file_handle, int length)
{
	auto fd = __getFileData(file_handle);

	if (fd != nullptr) {
		string buff;

		fd->ReadString(length, buff);
		
		return buff;
	}
	else {
		return string('\0');
	}
}

int FileReadInteger(int file_handle, int size)
{
    auto fd = __getFileData(file_handle);
    if (fd != nullptr) {
        int value;
        fd->ReadInteger(size, value);
        return value;
    }
    return 0;
}

double FileReadDouble(int file_handle, int size)
{
    auto fd = __getFileData(file_handle);
    if (fd != nullptr) {
        double value;
        fd->ReadDouble(size, value);
        return value;
    }
    return 0.0;
}

bool FileSeek(int file_handle, mqllong offset, int origin)
{
	auto fd = __getFileData(file_handle);

	if (!fd) return false;

	fd->Seek(offset, origin);

	return true;
}

ulong FileTell(int file_handle)
{
	FileData* fd = __getFileData(file_handle);

	if(fd == nullptr)
	{
		return 0;
	}

	return fd->stream->tellp();
}

void FileFlush(int file_handle)
{
	auto fd = __getFileData(file_handle);
	fd->stream->flush();
}

ulong FileSize(int file_handle) 
{ 
	FileData* fd = __getFileData(file_handle); 
 
	const long long pos = fd->stream->tellp(); 
	fd->stream->seekp(0, ios::end); 
	ulong s = fd->stream->tellp(); 
	fd->stream->seekp(pos); 
 
	return s; 
}

int StringLen(const mql4::string& string_value)
{
	return string_value.length();
}

mql4::string StringSubstr(const mql4::string& string_value, int start_pos, int length)
{
	const std::string str = string_value;
	if (start_pos < 0 || start_pos >= str.length()) return "";

	if (length < 0 || length + start_pos > str.length())
		length = str.length() - start_pos;
	 
	return str.substr(start_pos, length);
}

int StringFind(const mql4::string& string_value, const mql4::string& match_substring, int start_pos)
{
	const std::string str = string_value;
	if (start_pos < 0 || start_pos >= str.length()) return -1;
	if (match_substring.empty() || str.empty()) return -1;

	return str.find(match_substring, start_pos);
}

void mql2ft_comment(const std::ostringstream& oss)
{
	static char* __comment__object_name = (char*)::__comment__object_name.c_str();
	static char* __comment__font_name = "Arial Bold";

	std::string msg = oss.str();

	bool comment_object_exists = ft::ObjectExists(__comment__object_name);

	// If Comment("") called, just remove an existing comment and return 
	if (msg.empty() && comment_object_exists)
	{
		ft::ObjectDelete(__comment__object_name);
		return;
	}

	size_t start_pos = 0;
	while ((start_pos = msg.find("\n", start_pos)) != std::string::npos) {
		msg.replace(start_pos, 1, "\r\n");
		start_pos += 2;
	}

	if (!comment_object_exists)
	{
		if (ft::ObjectCreate(__comment__object_name, obj_Text, 0, 0, 0) || ft::ObjectExists(__comment__object_name))
		{
			ft::ObjectSet(__comment__object_name, ft::OBJPROP_SCREENCOORDS, 1);
			ft::ObjectSet(__comment__object_name, ft::OBJPROP_TIME1, 9);
			ft::ObjectSet(__comment__object_name, ft::OBJPROP_PRICE1, 22);
			ft::ObjectSet(__comment__object_name, ft::OBJPROP_VALIGNMENT, tlTop);
			ft::ObjectSet(__comment__object_name, ft::OBJPROP_HALIGNMENT, taLeftJustify);

			comment_object_exists = true;
		}
	}

	if (comment_object_exists) ObjectSetText(__comment__object_name, msg, 8, __comment__font_name, clrWhite);
}


datetime GlobalVariableSet(const mql4::string& variable_name, double variable_value)
{
	return globalVariableStore.setVariable(variable_name, variable_value);
}

double GlobalVariableGet(const mql4::string& variable_name)
{
	return globalVariableStore.getVariable(variable_name);
}

bool GlobalVariableGet(const mql4::string& variable_name, double& output_value)
{
	output_value = globalVariableStore.getVariable(variable_name);
	return true;
}

bool GlobalVariableCheck(const mql4::string& variable_name)
{
	return globalVariableStore.checkVariable(variable_name);
}

bool GlobalVariableDel(const mql4::string& variable_name)
{
	globalVariableStore.delVariable(variable_name);
	return true;
}

int GlobalVariablesTotal()
{
	return globalVariableStore.totalVars();
}

mql4::string  GlobalVariableName(int index)
{
	return globalVariableStore.getVarName(index);
}

int Hour()
{
	return TimeCurrent().Hours();
}

int Minute()
{
	return TimeCurrent().Minutes();
}

int Seconds()
{
	return TimeCurrent().Seconds();
}

int Year()
{
	return TimeCurrent().Year();
}

int Month()
{
	return TimeCurrent().Month();
}

int Day()
{
	return TimeCurrent().DayOfMonth();
}

int DayOfWeek()
{
	return TimeCurrent().DayOfWeek();
}

int DayOfYear()
{
	return TimeCurrent().DayOfYear();
}

bool Compare(double a, double b, double epsilon)
{
	return fabs(a - b) < epsilon;
}

namespace mql4
{
	double MathAbs(double value)
	{
		return fabs(value);
	}

	double MathPow(double base, double exponent)
	{

		return pow(base, exponent);
	}

	double  MathRound(double value)
	{
		return round(value);
	}

	double  MathSqrt(double  value)
	{
		if(value < 0)
			return NAN;
		else
			return sqrt(value);
	}

	double  MathSin(double  value)
	{
		return sin(value);
	}

	double  MathCos(double  value)
	{
		return cos(value);
	}

	double  MathLog(double  value)
	{

		if(value < 0.0)
		{
			return negative_nan_;
		}
		else if(value == 0.0)
		{
			return negative_inf_;
		}

		return log(value);
	}

	double  MathLog10(double  value)
	{

		if(value < 0.0)
		{
			return negative_nan_;
		}
		else if(value == 0.0)
		{
			return negative_inf_;
		}

		return log10(value);
	}

	double  MathMax(double  value1, double value2)
	{

		return fmax(value1, value2);
	}

	double  MathMin(double  value1, double value2)
	{

		return fmin(value1, value2);
	}

	double  MathMod(double  value1, double value2)
	{

		return fmod(value1, value2);
	}

	double  MathTan(double  rad)
	{

		return tan(rad);
	}

	double MathFloor(double val)
	{
		return floor(val);
	}

	double MathCeil(double val)
	{
		return ceil(val);
	}

	int MathRand()
	{
		_RandomSeed = _RandomSeed * 214013 + 2531011;
		return (_RandomSeed >> 16) & 0x7FFF;
	}

	void MathSrand(unsigned int seed)
	{
		_RandomSeed = seed;
	}
}

mql4::string  TerminalInfoString(int  property_id)
{
	switch(property_id)
	{
		case TERMINAL_LANGUAGE:
			return "English";
		case TERMINAL_COMPANY:
			return "Forex Tester Software, Inc.";
		case TERMINAL_NAME:
			return "Forex Tester";
		case TERMINAL_PATH:
			return FtPath();
		case TERMINAL_DATA_PATH:
			return FtDllPath();
		case TERMINAL_COMMONDATA_PATH:
			return FtDllPath();
	}
	
	return "";
}

string FtDllPath()
{
	string res = FtPath();
	#ifdef __STRATEGY
    return res.append("\\Strategies");
	#endif
	return res.append("\\Indicators");
}

string FtPath()
{
	char buffer[MAX_PATH];
    GetModuleFileNameA( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

mql4::string  AccountInfoString(int property_id)
{
	switch(property_id)
	{
		case ACCOUNT_NAME:
			return AccountName();
		case ACCOUNT_SERVER:
			return AccountServer();
		case ACCOUNT_CURRENCY:
			return AccountCurrency();
		case ACCOUNT_COMPANY:
			return "Forex Tester Software, Inc.";
	}
	
	return "";
}

mqllong  AccountInfoInteger(int  property_id)
{
	switch(property_id)
	{
		case ACCOUNT_LOGIN:
			return AccountNumber();
		case ACCOUNT_TRADE_MODE:
			return ACCOUNT_TRADE_MODE_REAL;
		case ACCOUNT_LEVERAGE:
			return 100;
		case ACCOUNT_LIMIT_ORDERS:
			return 0;
		case ACCOUNT_MARGIN_SO_MODE:
			return 0;
		case ACCOUNT_TRADE_ALLOWED:
			return 1;
		case ACCOUNT_TRADE_EXPERT:
			return 1;
	}
	
	return 0;
}

double AccountInfoDouble(int property_id)
{
#ifdef __STRATEGY
	switch(property_id)
	{
	case ACCOUNT_BALANCE:
		return AccountBalance();
		break;
	case ACCOUNT_CREDIT:
		return AccountLeverage();
		break;
	case ACCOUNT_PROFIT:
		return AccountProfit();
		break;
	case ACCOUNT_EQUITY:
		return AccountEquity();
		break;
	case ACCOUNT_MARGIN:
		return AccountMargin();
		break;
	case ACCOUNT_MARGIN_FREE:
		return AccountFreeMargin();
		break;

	case ACCOUNT_MARGIN_LEVEL: // Not supported in FT
	case ACCOUNT_MARGIN_SO_CALL:
	case ACCOUNT_MARGIN_SO_SO:
		SetLastError(4024);
		return 0.0;
		break;

	case ACCOUNT_MARGIN_INITIAL: // Not supported in MQL
	case ACCOUNT_MARGIN_MAINTENANCE:
	case ACCOUNT_ASSETS:
	case ACCOUNT_LIABILITIES:
	case ACCOUNT_COMMISSION_BLOCKED:
	default:
		SetLastError(4051);
		return 0.0;
		break;
	}
#else
	SetLastError(4024);
	return 0.0;
#endif
}


double AccountFreeMarginCheck(const mql4::string& symbol, int cmd, double volume)
{
    // AccountFreeMarginCheck =  FreeMargin - Margin1Lot * Lot;
    // FreeMargin = Equity - Margin;
    // Equity = Balance + Profit;
    // FreeMargin =  Balance + Profit - Margin;
    // AccountFreeMarginCheck = Balance + Profit - Margin - Margin1Lot * Lot;

	const std::string symb = getSymbol(symbol);

    double free_margin = 0.0;
#ifdef __STRATEGY
    const double leverage = AccountLeverage();
    const double contract = MarketInfo(symb, MODE_LOTSIZE);
    const double margin_1_lot = (cmd == OP_BUY ? Ask() : Bid()) * contract / leverage;

    free_margin = AccountFreeMargin() - margin_1_lot * volume;
#endif

    if (free_margin < 0)
        SetLastError(ERR_NOT_ENOUGH_MONEY);

    return free_margin;
}

#ifdef __INDICATOR

int WindowBarsPerChart()
{
	TChartInfo chartInfo;
    GetChartInfo(chartInfo);
	
	return chartInfo.LastIndex - chartInfo.FirstIndex + 1;
}

double WindowPriceMax(int index)
{
	double highest = 0.0;
	TChartInfo chartInfo;
	if(GetChartInfo(chartInfo))
	{
		for(int idx = chartInfo.FirstIndex; idx >= chartInfo.LastIndex; --idx)
		{
			double high = High(idx);
			if(highest < high) highest = high;
		}
	}
	return highest;
}

double WindowPriceMin(int index)
{
	double lowest = 1.7e+308;
	TChartInfo chartInfo;
	if(GetChartInfo(chartInfo))
	{
		for(int idx = chartInfo.FirstIndex; idx >= chartInfo.LastIndex; --idx)
		{
			double low = Low(idx);
			if(lowest > low) lowest = low;
		}
	}
	return lowest;
}

int WindowFirstVisibleBar()
{
	TChartInfo chartInfo;
	if (GetChartInfo(chartInfo))
		return chartInfo.FirstIndex;
	else return 0;
}

void ArrayFill(IndexBuffer& arr, int start, int count, double value)
{
	int cn = count == WHOLE_ARRAY ? arr.Count() - start : min(arr.Count() - start, count);
	for(int i = start, c = 0; c < cn; i++, c++)
	{
		arr[i] = value;
	}
}

#else

#ifdef ENABLE_HOOKING
double WindowPriceMax(int index)
{
	return ft::getMaxChartPrice();
}

double WindowPriceMin(int index)
{
	return ft::getMinChartPrice();
}

int WindowBarsPerChart()
{
	return ft::getBarsPerChart();
}
#endif

#endif

int  TerminalInfoInteger(int  property_id)
{
	switch(property_id)
	{
		case TERMINAL_BUILD: //need to implement
			return 0;
		case TERMINAL_COMMUNITY_ACCOUNT: //need to implement
			return 0;
		case TERMINAL_COMMUNITY_CONNECTION: //need to implement
			return 0;
		case TERMINAL_CONNECTED:
			return 1;
		case TERMINAL_DLLS_ALLOWED:
			return 0;
		case TERMINAL_TRADE_ALLOWED:
			return 1;
		case TERMINAL_EMAIL_ENABLED:
			return 1;
		case TERMINAL_FTP_ENABLED: //need to implement
			return 1;
		case TERMINAL_NOTIFICATIONS_ENABLED: //need to implement
			return 1;
		case TERMINAL_MAXBARS: //need to implement
			return 0;
		case TERMINAL_MQID: //need to implement
			return 0;
		case TERMINAL_CODEPAGE: //need to implement
			return 0;
		case TERMINAL_CPU_CORES: //need to implement
			return 0;
		case TERMINAL_DISK_SPACE: //need to implement
			return 0;
		case TERMINAL_MEMORY_PHYSICAL: //need to implement
			return 0;
		case TERMINAL_MEMORY_TOTAL: //need to implement
			return 0;
		case TERMINAL_MEMORY_AVAILABLE: //need to implement
			return 0;
		case TERMINAL_MEMORY_USED: //need to implement
			return 0;
		case TERMINAL_SCREEN_DPI: //need to implement
			return 0;
		case TERMINAL_PING_LAST:
			return 1;
	}
	
	return 0;
}

bool StringInit(mql4::string& string_var, int new_len, ushort character)
{
	if(new_len < 0)
	{
		return false;
	}
	
	std::string str = string_var;
	str.clear();
	str.resize(new_len, (const char)character);
	string_var = str;

	return true;
}

bool StringToLower(mql4::string& string_var)
{
	for(int i = 0; i < string_var.size(); ++i)
	{
		char& c = string_var[i];
		if(c > 64 && c < 91)
		{
			c |= 32u;
		}
	}

	return true;
}

bool StringToUpper(mql4::string& string_var)
{
	for(int i = 0; i < string_var.size(); ++i)
	{
		char& c = string_var[i];
		if(c > 96 && c < 123)
		{
			c &= 223u;
		}
	}

	return true;
}

mql4::string  StringTrimLeft(const mql4::string& text) {
	const std::string str = text;
	
	if (str.length() == 0)
		return str;
	size_t first = str.find_first_not_of(" \t\n");
	if (string::npos == first)
	{
		return "";
	}
	size_t cnt = str.length() - first;
	return str.substr(first, cnt);
}

mql4::string  StringTrimRight(const mql4::string&  text) {
	const std::string str = text;

	if (str.length() == 0)
		return str;
	size_t last = str.find_last_not_of(" \t\n");
	if (string::npos == last)
	{
		return "";
	}
	return str.substr(0, last+1);
}

mql4::string  StringTrim(const mql4::string&  text) {
	return StringTrimRight(StringTrimLeft(text));
}

int  StringSplit(const mql4::string& text, const ushort separator, Array<mql4::string>& result) {
	result.Clear();
	std::string token;
	std::istringstream tokenStream(text);
	while (std::getline(tokenStream, token, (char)separator))
	{
		result.Add(token);
	}
	return result.Count();
}

int  StringReplace(mql4::string& text, const mql4::string& what, const mql4::string& replacement){
	
	if (text.length() == 0 || what == "")
		return -1;
	int cnt = 0;
	size_t pos = 0;
	do{
		pos = text.find(what, pos);
		if (pos == string::npos)
			break;
		text.replace(pos, what.length(), replacement);
		pos += replacement.length();
		cnt++;
	} while (pos != string::npos);

	return cnt;
}

ushort  StringGetCharacter(const mql4::string& string_value, int pos) {
	if (pos < 0 || pos >= string_value.length())
		return 0;
	return string_value[pos];
}

int  StringGetChar(const mql4::string& string_value, int pos) {
	return StringGetCharacter(string_value, pos);
}

mql4::string StringSetChar(const mql4::string& string_var, int pos, ushort value)
{
	string tmp = string_var;

	if(pos == string_var.size())
	{
		tmp.push_back((char)value);
		return tmp;
	}
	else if(pos > string_var.size())
	{
		return tmp;
	}
	
	char c[2] = { (char)value, 0 };
	tmp.replace(pos, 1, (const char*)c);

	return tmp;
}

// Timers
void CALLBACK mql2ft_timer_callback(HWND arg1, UINT arg2, UINT_PTR arg3, DWORD arg4)
{
#ifdef __ON_TIMER
	mql4::OnTimer();
#endif
}

bool EventSetTimer(int seconds)
{
	if(timer)
	{
		return false;
	}

	timer = SetTimer(NULL, 0, seconds * 1000, mql2ft_timer_callback);
	
	if(timer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EventSetMillisecondTimer(int milliseconds)
{
	if(timer)
	{
		return false;
	}

	timer = SetTimer(NULL, 0, milliseconds, mql2ft_timer_callback);

	if(timer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EventKillTimer()
{
	if(timer)
	{
		KillTimer(NULL, timer);
		timer = 0;
	}
}

// Helper functions definitions
bool sandboxFnameCheck(const string& name)
{
	size_t result = string::npos;
	result = name.find(':');
	result = name.find("..");
	return result == string::npos;
}

bool createSubDirs(const string& fname)
{
	for(int i = 0; i < fname.size(); ++i)
	{
		const char& c = fname[i];
		if(c == '\\' || c == '/')
		{
			mql4::string tmp = fname.substr(0, i).c_str();
			mql2ft_setFullFileName(tmp);
			CreateDirectoryA(tmp.c_str(), NULL);
		}
	}
	return true;
}

bool ftCheckVersion(float& f1, float& f2, int& ver)
{
	float vf = (float)ver;
	f1 = vf / 2.0f;
	f2 = vf / 2.0f;
	return f1 + f2 > 1.5f + 1.5f; // Min supported major version 4
}