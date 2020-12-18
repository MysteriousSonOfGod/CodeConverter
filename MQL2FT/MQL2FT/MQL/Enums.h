#pragma once

constexpr const int	SHORT_MIN		= -32768;
constexpr const int	SHORT_MAX		= 32767;
constexpr const int	USHORT_MAX		= 65535;

#undef OBJ_BITMAP

// Indicator Lines
constexpr int MODE_MAIN = 0;
constexpr int MODE_SIGNAL = 1;
constexpr int MODE_PLUSDI = 1;
constexpr int MODE_MINUSDI = 2;
constexpr int MODE_UPPER = 1;
constexpr int MODE_LOWER = 2;
constexpr int MODE_GATORJAW = 1;
constexpr int MODE_GATORTEETH = 2;
constexpr int MODE_GATORLIPS = 3;

struct MqlEnumLight
{
	MqlEnumLight() : val(0) {}
	MqlEnumLight(int v) : val(v) {}
	operator int() const { return val; }
	int val;
};

struct ENUM_OBJECT : public MqlEnumLight
{
	ENUM_OBJECT() = default;
	ENUM_OBJECT(int v) : MqlEnumLight(v) {}
};

constexpr const int OBJ_VLINE = 0;
constexpr const int OBJ_HLINE = 1;
constexpr const int OBJ_TREND = 2;
constexpr const int OBJ_TRENDBYANGLE = 3;
constexpr const int OBJ_CYCLES = 20;
constexpr const int OBJ_CHANNEL = 5;
constexpr const int OBJ_STDDEVCHANNEL = 6;
constexpr const int OBJ_REGRESSION = 4;
constexpr const int OBJ_PITCHFORK = 19;
constexpr const int OBJ_GANNLINE = 7;
constexpr const int OBJ_GANNFAN = 8;
constexpr const int OBJ_GANNGRID = 9;
constexpr const int OBJ_FIBO = 10;
constexpr const int OBJ_FIBOTIMES = 11;
constexpr const int OBJ_FIBOFAN = 12;
constexpr const int OBJ_FIBOARC = 13;
constexpr const int OBJ_FIBOCHANNEL = 15;
constexpr const int OBJ_EXPANSION = 14;
constexpr const int OBJ_RECTANGLE = 16;
constexpr const int OBJ_TRIANGLE = 17;
constexpr const int OBJ_ELLIPSE = 18;
constexpr const int OBJ_ARROW_THUMB_UP = 29;
constexpr const int OBJ_ARROW_THUMB_DOWN = 30;
constexpr const int OBJ_ARROW_UP = 31;
constexpr const int OBJ_ARROW_DOWN = 32;
constexpr const int OBJ_ARROW_STOP = 33;
constexpr const int OBJ_ARROW_CHECK = 34;
constexpr const int OBJ_ARROW_LEFT_PRICE = 35;
constexpr const int OBJ_ARROW_RIGHT_PRICE = 36;
constexpr const int OBJ_ARROW_BUY = 37;
constexpr const int OBJ_ARROW_SELL = 38;
constexpr const int OBJ_ARROW = 22;
constexpr const int OBJ_TEXT = 21;
constexpr const int OBJ_LABEL = 23;
constexpr const int OBJ_BUTTON = 25;
constexpr const int OBJ_BITMAP = 26;
constexpr const int OBJ_BITMAP_LABEL = 24;
constexpr const int OBJ_EDIT = 27;
constexpr const int OBJ_CHART = 41;
constexpr const int OBJ_EVENT = 42;
constexpr const int OBJ_RECTANGLE_LABEL = 28;

// Object Properties

struct ENUM_OBJPROP : public MqlEnumLight
{
	ENUM_OBJPROP() = default;
	ENUM_OBJPROP(int v) : MqlEnumLight(v) {}
};

constexpr const int OBJPROP_TIME1 = 0;
constexpr const int OBJPROP_PRICE1 = 1;
constexpr const int OBJPROP_TIME2 = 2;
constexpr const int OBJPROP_PRICE2 = 3;
constexpr const int OBJPROP_TIME3 = 4;
constexpr const int OBJPROP_PRICE3 = 5;
constexpr const int OBJPROP_COLOR = 6;
constexpr const int OBJPROP_STYLE = 7;
constexpr const int OBJPROP_WIDTH = 8;
constexpr const int OBJPROP_BACK = 9;
constexpr const int OBJPROP_RAY = 10;
constexpr const int OBJPROP_ELLIPSE = 11;
constexpr const int OBJPROP_SCALE = 12;
constexpr const int OBJPROP_ANGLE = 13;
constexpr const int OBJPROP_ARROWCODE = 14;
constexpr const int OBJPROP_TIMEFRAMES = 15;
constexpr const int OBJPROP_DEVIATION = 16;
constexpr const int OBJPROP_FONTSIZE = 100;
constexpr const int OBJPROP_CORNER = 101;
constexpr const int OBJPROP_XDISTANCE = 102;
constexpr const int OBJPROP_YDISTANCE = 103;
constexpr const int OBJPROP_FIBOLEVELS = 200;
constexpr const int OBJPROP_LEVELCOLOR = 201;
constexpr const int OBJPROP_LEVELSTYLE = 202;
constexpr const int OBJPROP_LEVELWIDTH = 203;
constexpr const int OBJPROP_FIRSTLEVEL = 210;

struct ENUM_OBJECT_PROPERTY_INTEGER : public MqlEnumLight
{
	ENUM_OBJECT_PROPERTY_INTEGER() = default;
	ENUM_OBJECT_PROPERTY_INTEGER(int v) : MqlEnumLight(v) {}
};

//OBJPROP_COLOR = 6;
//OBJPROP_STYLE = 7;
//OBJPROP_WIDTH = 8;
//OBJPROP_BACK = 9;
constexpr const int OBJPROP_ZORDER = 207;
constexpr const int OBJPROP_HIDDEN = 208;
constexpr const int OBJPROP_SELECTED = 17;
constexpr const int OBJPROP_READONLY = 1028;
constexpr const int OBJPROP_TYPE = 18;
constexpr const int OBJPROP_TIME = 19;
constexpr const int OBJPROP_SELECTABLE = 1000;
constexpr const int OBJPROP_CREATETIME = 998;
constexpr const int OBJPROP_LEVELS = 200;
//OBJPROP_LEVELCOLOR = 201;
//OBJPROP_LEVELSTYLE = 202;
//OBJPROP_LEVELWIDTH = 203;
constexpr const int OBJPROP_ALIGN = 1036;
//OBJPROP_FONTSIZE = 100;
constexpr const int OBJPROP_RAY_RIGHT = 1004;
//OBJPROP_ELLIPSE = 11;
//OBJPROP_ARROWCODE = 14;
//OBJPROP_TIMEFRAMES = 15;
constexpr const int OBJPROP_ANCHOR = 1011;
//OBJPROP_XDISTANCE = 102;
//OBJPROP_YDISTANCE = 103;
constexpr const int OBJPROP_STATE = 1018;
constexpr const int OBJPROP_XSIZE = 1019;
constexpr const int OBJPROP_YSIZE = 1020;
constexpr const int OBJPROP_XOFFSET = 1033;
constexpr const int OBJPROP_YOFFSET = 1034;
constexpr const int OBJPROP_BGCOLOR = 1025;
//OBJPROP_CORNER = 101;
constexpr const int OBJPROP_BORDER_TYPE = 1029;
constexpr const int OBJPROP_BORDER_COLOR = 1035;

struct ENUM_OBJECT_PROPERTY_DOUBLE : public MqlEnumLight
{
	ENUM_OBJECT_PROPERTY_DOUBLE() = default;
	ENUM_OBJECT_PROPERTY_DOUBLE(int v) : MqlEnumLight(v) {}
};

constexpr const int OBJPROP_PRICE = 20;
constexpr const int OBJPROP_LEVELVALUE = 204;
//OBJPROP_SCALE 12
//OBJPROP_ANGLE 13
//OBJPROP_DEVIATION 16

struct ENUM_OBJECT_PROPERTY_STRING : public MqlEnumLight
{
	ENUM_OBJECT_PROPERTY_STRING() = default;
	ENUM_OBJECT_PROPERTY_STRING(int v) : MqlEnumLight(v) {}
};

constexpr const int OBJPROP_NAME = 1037;
constexpr const int OBJPROP_TEXT = 999;
constexpr const int OBJPROP_TOOLTIP = 206;
constexpr const int OBJPROP_LEVELTEXT = 205;
constexpr const int OBJPROP_FONT = 1001;
constexpr const int OBJPROP_BMPFILE = 1017;
constexpr const int OBJPROP_SYMBOL = 1021;

// End of Object Properties

struct ENUM_INDEXBUFFER_TYPE : public MqlEnumLight
{
	ENUM_INDEXBUFFER_TYPE() = default;
	ENUM_INDEXBUFFER_TYPE(int v) : MqlEnumLight(v) {}
};

constexpr const int INDICATOR_DATA = 0;
constexpr const int INDICATOR_COLOR_INDEX = 1;
constexpr const int INDICATOR_CALCULATIONS = 2;

struct ENUM_INIT_RETCODE : public MqlEnumLight
{
	ENUM_INIT_RETCODE() = default;
	ENUM_INIT_RETCODE(int v) : MqlEnumLight(v) {}
};

constexpr const int INIT_SUCCEEDED = 0;
constexpr const int INIT_FAILED = -1;
constexpr const int INIT_PARAMETERS_INCORRECT = -2;

struct ENUM_ALIGN_MODE : public MqlEnumLight
{
	ENUM_ALIGN_MODE() = default;
	ENUM_ALIGN_MODE(int v) : MqlEnumLight(v) {}
};

constexpr const int ALIGN_LEFT = 1;
constexpr const int ALIGN_CENTER = 2;
constexpr const int ALIGN_RIGHT = 0;

enum ENUM_DRAW_STYLE
{
	DRAW_LINE = 0,
	DRAW_SECTION = 1,
	DRAW_HISTOGRAM = 2,
	DRAW_ARROW = 3,
	DRAW_ZIGZAG = 4,
	DRAW_NONE = 12
};

enum ENUM_LINE_STYLE
{
	STYLE_SOLID = 0,
	STYLE_DASH = 1,
	STYLE_DOT = 2,
	STYLE_DASHDOT = 3,
	STYLE_DASHDOTDOT = 4
};

enum ENUM_MA_METHOD
{
	MODE_SMA = 0,
	MODE_EMA = 1,
	MODE_SMMA = 2,
	MODE_LWMA = 3,
};

enum ENUM_APPLIED_PRICE
{
	PRICE_CLOSE = 0,
	PRICE_OPEN = 1,
	PRICE_HIGH = 2,
	PRICE_LOW = 3,
	PRICE_MEDIAN = 4,
	PRICE_TYPICAL = 5,
	PRICE_WEIGHTED = 6
};

struct TimeOutputMode : public MqlEnumLight
{
	TimeOutputMode() = default;
	TimeOutputMode(int v) : MqlEnumLight(v) {}
};

constexpr const int TIME_DATE = 1;
constexpr const int TIME_MINUTES = 2;
constexpr const int TIME_SECONDS = 4;

struct TradeOperations : public MqlEnumLight
{
	TradeOperations() = default;
	TradeOperations(int v) : MqlEnumLight(v) {}
};

constexpr const int OP_BUY = 0;
constexpr const int OP_SELL = 1;
constexpr const int OP_BUYLIMIT = 2;
constexpr const int OP_SELLLIMIT = 3;
constexpr const int OP_BUYSTOP = 4;
constexpr const int OP_SELLSTOP = 5;

struct EnumMarketIdentifiers : public MqlEnumLight
{
	EnumMarketIdentifiers() = default;
	EnumMarketIdentifiers(int v) : MqlEnumLight(v) {}
};

// Commented because of conflict with InterfaceUnit defines... BID and ASK different values with MQL
//MODE_LOW = 1, 
//MODE_HIGH = 2,
//MODE_TIME = 5,
//MODE_BID = 9,
//MODE_ASK = 10,
constexpr const int MODE_POINT = 11;
constexpr const int MODE_DIGITS = 12;
constexpr const int MODE_SPREAD = 13;
constexpr const int MODE_STOPLEVEL = 14;
constexpr const int MODE_LOTSIZE = 15;
constexpr const int MODE_TICKVALUE = 16;
constexpr const int MODE_TICKSIZE = 17;
constexpr const int MODE_SWAPLONG = 18;
constexpr const int MODE_SWAPSHORT = 19;
constexpr const int MODE_STARTING = 20;
constexpr const int MODE_EXPIRATION = 21;
constexpr const int MODE_TRADEALLOWED = 22;
constexpr const int MODE_MINLOT = 23;
constexpr const int MODE_LOTSTEP = 24;
constexpr const int MODE_MAXLOT = 25;
constexpr const int MODE_SWAPTYPE = 26;
constexpr const int MODE_PROFITCALCMODE = 27;
constexpr const int MODE_MARGINCALCMODE = 28;
constexpr const int MODE_MARGININIT = 29;
constexpr const int MODE_MARGINMAINTENANCE = 30;
constexpr const int MODE_MARGINHEDGED = 31;
constexpr const int MODE_MARGINREQUIRED = 32;
constexpr const int MODE_FREEZELEVEL = 33;
constexpr const int MODE_CLOSEBY_ALLOWED = 34;

struct ENUM_TERMINAL_INFO_STRING : public MqlEnumLight
{
	ENUM_TERMINAL_INFO_STRING() = default;
	ENUM_TERMINAL_INFO_STRING(int v) : MqlEnumLight(v) {}
};

constexpr const int TERMINAL_LANGUAGE = 13;
constexpr const int TERMINAL_COMPANY = 0;
constexpr const int TERMINAL_NAME = 1;
constexpr const int TERMINAL_PATH = 2;
constexpr const int TERMINAL_DATA_PATH = 3;
constexpr const int TERMINAL_COMMONDATA_PATH = 4;

struct ENUM_ACCOUNT_INFO_STRING : public MqlEnumLight
{
	ENUM_ACCOUNT_INFO_STRING() = default;
	ENUM_ACCOUNT_INFO_STRING(int v) : MqlEnumLight(v) {}
};

constexpr const int ACCOUNT_NAME = 1;
constexpr const int ACCOUNT_SERVER = 3;
constexpr const int ACCOUNT_CURRENCY = 36;
constexpr const int ACCOUNT_COMPANY = 2;

struct ENUM_ACCOUNT_INFO_INTEGER : public MqlEnumLight
{
	ENUM_ACCOUNT_INFO_INTEGER() = default;
	ENUM_ACCOUNT_INFO_INTEGER(int v) : MqlEnumLight(v) {}
};

constexpr const int ACCOUNT_LOGIN = 0;
constexpr const int ACCOUNT_TRADE_MODE = 32;
constexpr const int ACCOUNT_LEVERAGE = 35;
constexpr const int ACCOUNT_LIMIT_ORDERS = 47;
constexpr const int ACCOUNT_MARGIN_SO_MODE = 44;
constexpr const int ACCOUNT_TRADE_ALLOWED = 33;
constexpr const int ACCOUNT_TRADE_EXPERT = 34;

struct ENUM_ACCOUNT_INFO_DOUBLE : public MqlEnumLight
{
	ENUM_ACCOUNT_INFO_DOUBLE() = default;
	ENUM_ACCOUNT_INFO_DOUBLE(int v) : MqlEnumLight(v) {}
};

constexpr const int ACCOUNT_BALANCE = 37;
constexpr const int ACCOUNT_CREDIT = 38;
constexpr const int ACCOUNT_PROFIT = 39;
constexpr const int ACCOUNT_EQUITY = 40;
constexpr const int ACCOUNT_MARGIN = 41;
constexpr const int ACCOUNT_MARGIN_FREE = 42;
constexpr const int ACCOUNT_MARGIN_LEVEL = 43;
constexpr const int ACCOUNT_MARGIN_SO_CALL = 45;
constexpr const int ACCOUNT_MARGIN_SO_SO = 46;
constexpr const int ACCOUNT_MARGIN_INITIAL = 48;
constexpr const int ACCOUNT_MARGIN_MAINTENANCE = 49;
constexpr const int ACCOUNT_ASSETS = 50;
constexpr const int ACCOUNT_LIABILITIES = 51;
constexpr const int ACCOUNT_COMMISSION_BLOCKED = 52;

struct ENUM_ACCOUNT_TRADE_MODE : public MqlEnumLight
{
	ENUM_ACCOUNT_TRADE_MODE() = default;
	ENUM_ACCOUNT_TRADE_MODE(int v) : MqlEnumLight(v) {}
};

constexpr const int ACCOUNT_TRADE_MODE_DEMO = 0;
constexpr const int ACCOUNT_TRADE_MODE_CONTEST = 1;
constexpr const int ACCOUNT_TRADE_MODE_REAL = 2;

struct ENUM_TERMINAL_INFO_INTEGER : public MqlEnumLight
{
	ENUM_TERMINAL_INFO_INTEGER() = default;
	ENUM_TERMINAL_INFO_INTEGER(int v) : MqlEnumLight(v) {}
};

constexpr const int TERMINAL_BUILD = 5;
constexpr const int TERMINAL_COMMUNITY_ACCOUNT = 23;
constexpr const int TERMINAL_COMMUNITY_CONNECTION = 24;
constexpr const int TERMINAL_CONNECTED = 6;
constexpr const int TERMINAL_DLLS_ALLOWED = 7;
constexpr const int TERMINAL_TRADE_ALLOWED = 8;
constexpr const int TERMINAL_EMAIL_ENABLED = 9;
constexpr const int TERMINAL_FTP_ENABLED = 10;
constexpr const int TERMINAL_NOTIFICATIONS_ENABLED = 26;
constexpr const int TERMINAL_MAXBARS = 11;
constexpr const int TERMINAL_MQID = 22;
constexpr const int TERMINAL_CODEPAGE = 12;
constexpr const int TERMINAL_CPU_CORES = 21;
constexpr const int TERMINAL_DISK_SPACE = 20;
constexpr const int TERMINAL_MEMORY_PHYSICAL = 14;
constexpr const int TERMINAL_MEMORY_TOTAL = 15;
constexpr const int TERMINAL_MEMORY_AVAILABLE = 16;
constexpr const int TERMINAL_MEMORY_USED = 17;
constexpr const int TERMINAL_SCREEN_DPI = 27;
constexpr const int TERMINAL_PING_LAST = 28;

struct ENUM_OBJ_PERIODS : public MqlEnumLight
{
	ENUM_OBJ_PERIODS() = default;
	ENUM_OBJ_PERIODS(int v) : MqlEnumLight(v) {}
};

constexpr const int OBJ_NO_PERIODS = -1;
constexpr const int OBJ_PERIOD_M1 = 0x0001;
constexpr const int OBJ_PERIOD_M5 = 0x0002;
constexpr const int OBJ_PERIOD_M15 = 0x0004;
constexpr const int OBJ_PERIOD_M30 = 0x0008;
constexpr const int OBJ_PERIOD_H1 = 0x0010;
constexpr const int OBJ_PERIOD_H4 = 0x0020;
constexpr const int OBJ_PERIOD_D1 = 0x0040;
constexpr const int OBJ_PERIOD_W1 = 0x0080;
constexpr const int OBJ_PERIOD_MN1 = 0x0100;
constexpr const int OBJ_ALL_PERIODS = 0x01ff;

struct ENUM_ANCHOR_POINT : public MqlEnumLight
{
	ENUM_ANCHOR_POINT() = default;
	ENUM_ANCHOR_POINT(int v) : MqlEnumLight(v) {}
};

constexpr const int ANCHOR_LEFT_UPPER = 0;
constexpr const int ANCHOR_LEFT = 1;
constexpr const int ANCHOR_LEFT_LOWER = 2;
constexpr const int ANCHOR_LOWER = 3;
constexpr const int ANCHOR_RIGHT_LOWER = 4;
constexpr const int ANCHOR_RIGHT = 5;
constexpr const int ANCHOR_RIGHT_UPPER = 6;
constexpr const int ANCHOR_UPPER = 7;
constexpr const int ANCHOR_CENTER = 8;

struct ENUM_ARROW_ANCHOR : public MqlEnumLight
{
	ENUM_ARROW_ANCHOR() = default;
	ENUM_ARROW_ANCHOR(int v) : MqlEnumLight(v) {}
};

constexpr const int ANCHOR_TOP = 0;
constexpr const int ANCHOR_BOTTOM = 1;

struct ENUM_BASE_CORNER : public MqlEnumLight
{
	ENUM_BASE_CORNER() = default;
	ENUM_BASE_CORNER(int v) : MqlEnumLight(v) {}
};

constexpr const int CORNER_LEFT_UPPER = 0;
constexpr const int CORNER_RIGHT_UPPER = 1;
constexpr const int CORNER_LEFT_LOWER = 2;
constexpr const int CORNER_RIGHT_LOWER = 3;

struct ENUM_SYMBOL_TRADE_EXECUTION : public MqlEnumLight
{
	ENUM_SYMBOL_TRADE_EXECUTION() = default;
	ENUM_SYMBOL_TRADE_EXECUTION(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_TRADE_EXECUTION_REQUEST = 0;
constexpr const int SYMBOL_TRADE_EXECUTION_INSTANT = 1;
constexpr const int SYMBOL_TRADE_EXECUTION_MARKET = 2;
constexpr const int SYMBOL_TRADE_EXECUTION_EXCHANGE = 3;

struct ENUM_ORDER_TYPE : public MqlEnumLight
{
	ENUM_ORDER_TYPE() = default;
	ENUM_ORDER_TYPE(int v) : MqlEnumLight(v) {}
};

// Enum from mql5 that works in mql4
constexpr const int ORDER_TYPE_BUY = 0;
constexpr const int ORDER_TYPE_SELL = 1;
constexpr const int ORDER_TYPE_BUY_LIMIT = 2;
constexpr const int ORDER_TYPE_SELL_LIMIT = 3;
constexpr const int ORDER_TYPE_BUY_STOP = 4;
constexpr const int ORDER_TYPE_SELL_STOP = 5;
//ORDER_TYPE_BUY_STOP_LIMIT,
//ORDER_TYPE_SELL_STOP_LIMIT,
//ORDER_TYPE_CLOSE_BY

struct ENUM_BORDER_TYPE : public MqlEnumLight
{
	ENUM_BORDER_TYPE() = default;
	ENUM_BORDER_TYPE(int v) : MqlEnumLight(v) {}
};

constexpr const int BORDER_FLAT = 0;
constexpr const int BORDER_RAISED = 1;
constexpr const int BORDER_SUNKEN = 2;

struct ENUM_STO_PRICE : public MqlEnumLight
{
	ENUM_STO_PRICE() = default;
	ENUM_STO_PRICE(int v) : MqlEnumLight(v) {}
};

constexpr const int STO_LOWHIGH = 0;
constexpr const int STO_CLOSECLOSE = 1;

struct ENUM_SYMBOL_INFO_INTEGER : public MqlEnumLight
{
	ENUM_SYMBOL_INFO_INTEGER() = default;
	ENUM_SYMBOL_INFO_INTEGER(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_SELECT = 0;
constexpr const int SYMBOL_VISIBLE = 76;
constexpr const int SYMBOL_SESSION_DEALS = 56;
constexpr const int SYMBOL_SESSION_BUY_ORDERS = 60;
constexpr const int SYMBOL_SESSION_SELL_ORDERS = 62;
constexpr const int SYMBOL_VOLUME = 10;
constexpr const int SYMBOL_VOLUMEHIGH = 11;
constexpr const int SYMBOL_VOLUMELOW = 12;
constexpr const int SYMBOL_TIME = 15;
constexpr const int SYMBOL_DIGITS = 17;
constexpr const int SYMBOL_SPREAD_FLOAT = 41;
constexpr const int SYMBOL_SPREAD = 18;
constexpr const int SYMBOL_TRADE_CALC_MODE = 29;
constexpr const int SYMBOL_TRADE_MODE = 30;
constexpr const int SYMBOL_START_TIME = 51;
constexpr const int SYMBOL_EXPIRATION_TIME = 52;
constexpr const int SYMBOL_TRADE_STOPS_LEVEL = 31;
constexpr const int SYMBOL_TRADE_FREEZE_LEVEL = 32;
constexpr const int SYMBOL_TRADE_EXEMODE = 33;
constexpr const int SYMBOL_SWAP_MODE = 37;
constexpr const int SYMBOL_SWAP_ROLLOVER3DAYS = 40;
constexpr const int SYMBOL_EXPIRATION_MODE = 49;
constexpr const int SYMBOL_FILLING_MODE = 50;
constexpr const int SYMBOL_ORDER_MODE = 71;

struct ENUM_SYMBOL_INFO_DOUBLE : public MqlEnumLight
{
	ENUM_SYMBOL_INFO_DOUBLE() = default;
	ENUM_SYMBOL_INFO_DOUBLE(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_BID = 1;
constexpr const int SYMBOL_BIDHIGH = 2;
constexpr const int SYMBOL_BIDLOW = 3;
constexpr const int SYMBOL_ASK = 4;
constexpr const int SYMBOL_ASKHIGH = 5;
constexpr const int SYMBOL_ASKLOW = 6;
constexpr const int SYMBOL_LAST = 7;
constexpr const int SYMBOL_LASTHIGH = 8;
constexpr const int SYMBOL_LASTLOW = 9;
constexpr const int SYMBOL_POINT = 16;
constexpr const int SYMBOL_TRADE_TICK_VALUE = 26;
constexpr const int SYMBOL_TRADE_TICK_VALUE_PROFIT = 53;
constexpr const int SYMBOL_TRADE_TICK_VALUE_LOSS = 54;
constexpr const int SYMBOL_TRADE_TICK_SIZE = 27;
constexpr const int SYMBOL_TRADE_CONTRACT_SIZE = 28;
constexpr const int SYMBOL_VOLUME_MIN = 34;
constexpr const int SYMBOL_VOLUME_MAX = 35;
constexpr const int SYMBOL_VOLUME_STEP = 36;
constexpr const int SYMBOL_VOLUME_LIMIT = 55;
constexpr const int SYMBOL_SWAP_LONG = 38;
constexpr const int SYMBOL_SWAP_SHORT = 39;
constexpr const int SYMBOL_MARGIN_INITIAL = 42;
constexpr const int SYMBOL_MARGIN_MAINTENANCE = 43;
constexpr const int SYMBOL_MARGIN_LONG = 44;
constexpr const int SYMBOL_MARGIN_SHORT = 45;
constexpr const int SYMBOL_MARGIN_LIMIT = 46;
constexpr const int SYMBOL_MARGIN_STOP = 47;
constexpr const int SYMBOL_MARGIN_STOPLIMIT = 48;
constexpr const int SYMBOL_SESSION_VOLUME = 57;
constexpr const int SYMBOL_SESSION_TURNOVER = 58;
constexpr const int SYMBOL_SESSION_INTEREST = 59;
constexpr const int SYMBOL_SESSION_BUY_ORDERS_VOLUME = 61;
constexpr const int SYMBOL_SESSION_SELL_ORDERS_VOLUME = 63;
constexpr const int SYMBOL_SESSION_OPEN = 64;
constexpr const int SYMBOL_SESSION_CLOSE = 65;
constexpr const int SYMBOL_SESSION_AW = 66;
constexpr const int SYMBOL_SESSION_PRICE_SETTLEMENT = 67;
constexpr const int SYMBOL_SESSION_PRICE_LIMIT_MIN = 68;
constexpr const int SYMBOL_SESSION_PRICE_LIMIT_MAX = 69;

struct ENUM_SYMBOL_INFO_STRING : public MqlEnumLight
{
	ENUM_SYMBOL_INFO_STRING() = default;
	ENUM_SYMBOL_INFO_STRING(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_CURRENCY_BASE = 22;
constexpr const int SYMBOL_CURRENCY_PROFIT = 23;
constexpr const int SYMBOL_CURRENCY_MARGIN = 24;
constexpr const int SYMBOL_DESCRIPTION = 20;
constexpr const int SYMBOL_PATH = 21;

struct ENUM_SYMBOL_TRADE_MODE : public MqlEnumLight
{
	ENUM_SYMBOL_TRADE_MODE() = default;
	ENUM_SYMBOL_TRADE_MODE(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_TRADE_MODE_DISABLED = 0;
constexpr const int SYMBOL_TRADE_MODE_CLOSEONLY = 1;
constexpr const int SYMBOL_TRADE_MODE_FULL = 2;
constexpr const int SYMBOL_TRADE_MODE_LONGONLY = 3;
constexpr const int SYMBOL_TRADE_MODE_SHORTONLY = 4;

enum ENUM_DAY_OF_WEEK
{
	SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

struct ENUM_ARROW_CODE : public MqlEnumLight
{
	ENUM_ARROW_CODE() = default;
	ENUM_ARROW_CODE(int v) : MqlEnumLight(v) {}
};

constexpr const int SYMBOL_THUMBSUP = 67;
constexpr const int SYMBOL_THUMBSDOWN = 68;
constexpr const int SYMBOL_ARROWUP = 241;
constexpr const int SYMBOL_ARROWDOWN = 242;
constexpr const int SYMBOL_STOPSIGN = 251;
constexpr const int SYMBOL_CHECKSIGN = 252;
constexpr const int SYMBOL_LEFTPRICE = 5;
constexpr const int SYMBOL_RIGHTPRICE = 6;

struct ENUM_CHART_PROPERTY_INTEGER : public MqlEnumLight
{
	ENUM_CHART_PROPERTY_INTEGER() = default;
	ENUM_CHART_PROPERTY_INTEGER(int v) : MqlEnumLight(v) {}
};

// Custom FT chartevent for mouse move return of time/price instead of coords
constexpr const int CHART_EVENT_MOUSE_MOVE_TIMEPRICE = 0x7FFFFFFF;
// --------------------------------------------------------------------------
constexpr const int CHART_BRING_TO_TOP = 35;
constexpr const int CHART_MOUSE_SCROLL = 42;
constexpr const int CHART_EVENT_MOUSE_MOVE = 40;
constexpr const int CHART_EVENT_OBJECT_CREATE = 38;
constexpr const int CHART_EVENT_OBJECT_DELETE = 39;
constexpr const int CHART_MODE = 0;
constexpr const int CHART_FOREGROUND = 1;
constexpr const int CHART_SHIFT = 2;
constexpr const int CHART_AUTOSCROLL = 4;
constexpr const int CHART_QUICK_NAVIGATION = 45;
constexpr const int CHART_SCALE = 5;
constexpr const int CHART_SCALEFIX = 6;
constexpr const int CHART_SCALEFIX_11 = 7;
constexpr const int CHART_SCALE_PT_PER_BAR = 10;
constexpr const int CHART_SHOW_OHLC = 12;
constexpr const int CHART_SHOW_BID_LINE = 13;
constexpr const int CHART_SHOW_ASK_LINE = 14;
constexpr const int CHART_SHOW_LAST_LINE = 15;
constexpr const int CHART_SHOW_PERIOD_SEP = 16;
constexpr const int CHART_SHOW_GRID = 17;
constexpr const int CHART_SHOW_VOLUMES = 18;
constexpr const int CHART_SHOW_OBJECT_DESCR = 19;
constexpr const int CHART_VISIBLE_BARS = 100;
constexpr const int CHART_WINDOWS_TOTAL = 101;
constexpr const int CHART_WINDOW_IS_VISIBLE = 102;
constexpr const int CHART_WINDOW_HANDLE = 103;
constexpr const int CHART_WINDOW_YDISTANCE = 110;
constexpr const int CHART_FIRST_VISIBLE_BAR = 104;
constexpr const int CHART_WIDTH_IN_BARS = 105;
constexpr const int CHART_WIDTH_IN_PIXELS = 106;
constexpr const int CHART_HEIGHT_IN_PIXELS = 107;
constexpr const int CHART_COLOR_BACKGROUND = 21;
constexpr const int CHART_COLOR_FOREGROUND = 22;
constexpr const int CHART_COLOR_GRID = 23;
constexpr const int CHART_COLOR_VOLUME = 24;
constexpr const int CHART_COLOR_CHART_UP = 25;
constexpr const int CHART_COLOR_CHART_DOWN = 26;
constexpr const int CHART_COLOR_CHART_LINE = 27;
constexpr const int CHART_COLOR_CANDLE_BULL = 28;
constexpr const int CHART_COLOR_CANDLE_BEAR = 29;
constexpr const int CHART_COLOR_BID = 30;
constexpr const int CHART_COLOR_ASK = 31;
constexpr const int CHART_COLOR_LAST = 32;
constexpr const int CHART_COLOR_STOP_LEVEL = 33;
constexpr const int CHART_SHOW_TRADE_LEVELS = 34;
constexpr const int CHART_DRAG_TRADE_LEVELS = 43;
constexpr const int CHART_SHOW_DATE_SCALE = 36;
constexpr const int CHART_SHOW_PRICE_SCALE = 37;
constexpr const int CHART_IS_OFFLINE = 112;

struct ENUM_CHART_PROPERTY_DOUBLE : public MqlEnumLight
{
	ENUM_CHART_PROPERTY_DOUBLE() = default;
	ENUM_CHART_PROPERTY_DOUBLE(int v) : MqlEnumLight(v) {}
};

constexpr const int CHART_SHIFT_SIZE = 3;
constexpr const int CHART_FIXED_POSITION = 41;
constexpr const int CHART_FIXED_MAX = 8;
constexpr const int CHART_FIXED_MIN = 9;
constexpr const int CHART_POINTS_PER_BAR = 11;
constexpr const int CHART_PRICE_MIN = 108;
constexpr const int CHART_PRICE_MAX = 109;

struct ENUM_CHART_PROPERTY_STRING : public MqlEnumLight
{
	ENUM_CHART_PROPERTY_STRING() = default;
	ENUM_CHART_PROPERTY_STRING(int v) : MqlEnumLight(v) {}
};

constexpr const int CHART_COMMENT = 20;

struct ENUM_ICHIMOKU_MODE : public MqlEnumLight
{
	ENUM_ICHIMOKU_MODE() = default;
	ENUM_ICHIMOKU_MODE(int v) : MqlEnumLight(v) {}
};

constexpr const int MODE_TENKANSEN = 1;
constexpr const int MODE_KIJUNSEN = 2;
constexpr const int MODE_SENKOUSPANA = 3;
constexpr const int MODE_SENKOUSPANB = 4;
constexpr const int MODE_CHIKOUSPAN = 5;
constexpr const int MODE_CHINKOUSPAN = 5;

// Supported chartevents
struct ENUM_CHART_EVENT : public MqlEnumLight
{
	ENUM_CHART_EVENT() = default;
	ENUM_CHART_EVENT(int v) : MqlEnumLight(v) {}
};

constexpr const int CHARTEVENT_KEYDOWN = 0;
constexpr const int CHARTEVENT_MOUSE_MOVE = 10;
constexpr const int CHARTEVENT_CLICK = 4;

// Errors returned from trade server
constexpr const int	ERR_NO_ERROR = 0;;
constexpr const int	ERR_NO_RESULT = 1;;
constexpr const int	ERR_COMMON_ERROR = 2;;
constexpr const int	ERR_INVALID_TRADE_PARAMETERS = 3;
constexpr const int	ERR_SERVER_BUSY = 4;
constexpr const int	ERR_OLD_VERSION = 5;
constexpr const int	ERR_NO_CONNECTION = 6;
constexpr const int	ERR_NOT_ENOUGH_RIGHTS = 7;
constexpr const int	ERR_TOO_FREQUENT_REQUESTS = 8;
constexpr const int	ERR_MALFUNCTIONAL_TRADE = 9;
constexpr const int	ERR_ACCOUNT_DISABLED = 64;
constexpr const int	ERR_INVALID_ACCOUNT = 65;
constexpr const int	ERR_TRADE_TIMEOUT = 128;
constexpr const int	ERR_INVALID_PRICE = 129;
constexpr const int	ERR_INVALID_STOPS = 130;
constexpr const int	ERR_INVALID_TRADE_VOLUME = 131;
constexpr const int	ERR_MARKET_CLOSED = 132;
constexpr const int	ERR_TRADE_DISABLED = 133;
constexpr const int	ERR_NOT_ENOUGH_MONEY = 134;
constexpr const int	ERR_PRICE_CHANGED = 135;
constexpr const int	ERR_OFF_QUOTES = 136;
constexpr const int	ERR_BROKER_BUSY = 137;
constexpr const int	ERR_REQUOTE = 138;
constexpr const int	ERR_ORDER_LOCKED = 139;
constexpr const int	ERR_LONG_POSITIONS_ONLY_ALLOWED = 140;
constexpr const int	ERR_TOO_MANY_REQUESTS = 141;
constexpr const int	ERR_TRADE_MODIFY_DENIED = 145;
constexpr const int	ERR_TRADE_CONTEXT_BUSY = 146;
constexpr const int	ERR_TRADE_EXPIRATION_DENIED = 147;
constexpr const int	ERR_TRADE_TOO_MANY_ORDERS = 148;
constexpr const int	ERR_TRADE_HEDGE_PROHIBITED = 149;
constexpr const int	ERR_TRADE_PROHIBITED_BY_FIFO = 150;

constexpr const int	ERR_NO_MQLERROR = 4000;
constexpr const int	ERR_WRONG_FUNCTION_POINTER = 4001;
constexpr const int	ERR_ARRAY_INDEX_OUT_OF_RANGE = 4002;
constexpr const int	ERR_NO_MEMORY_FOR_CALL_STACK = 4003;
constexpr const int	ERR_RECURSIVE_STACK_OVERFLOW = 4004;
constexpr const int	ERR_NOT_ENOUGH_STACK_FOR_PARAM = 4005;
constexpr const int	ERR_NO_MEMORY_FOR_PARAM_STRING = 4006;
constexpr const int	ERR_NO_MEMORY_FOR_TEMP_STRING = 4007;
constexpr const int	ERR_NOT_INITIALIZED_STRING = 4008;
constexpr const int	ERR_NOT_INITIALIZED_ARRAYSTRING = 4009;
constexpr const int	ERR_NO_MEMORY_FOR_ARRAYSTRING = 4010;
constexpr const int	ERR_TOO_LONG_STRING = 4011;
constexpr const int	ERR_REMAINDER_FROM_ZERO_DIVIDE = 4012;
constexpr const int	ERR_ZERO_DIVIDE = 4013;
constexpr const int	ERR_UNKNOWN_COMMAND = 4014;
constexpr const int	ERR_WRONG_JUMP = 4015;
constexpr const int	ERR_NOT_INITIALIZED_ARRAY = 4016;
constexpr const int	ERR_DLL_CALLS_NOT_ALLOWED = 4017;
constexpr const int	ERR_CANNOT_LOAD_LIBRARY = 4018;
constexpr const int	ERR_CANNOT_CALL_FUNCTION = 4019;
constexpr const int	ERR_EXTERNAL_CALLS_NOT_ALLOWED = 4020;
constexpr const int	ERR_NO_MEMORY_FOR_RETURNED_STR = 4021;
constexpr const int	ERR_SYSTEM_BUSY = 4022;
constexpr const int	ERR_DLLFUNC_CRITICALERROR = 4023;
constexpr const int	ERR_INTERNAL_ERROR = 4024;
constexpr const int	ERR_OUT_OF_MEMORY = 4025;
constexpr const int	ERR_INVALID_POINTER = 4026;
constexpr const int	ERR_FORMAT_TOO_MANY_FORMATTERS = 4027;
constexpr const int	ERR_FORMAT_TOO_MANY_PARAMETERS = 4028;
constexpr const int	ERR_ARRAY_INVALID = 4029;
constexpr const int	ERR_CHART_NOREPLY = 4030;
constexpr const int	ERR_INVALID_FUNCTION_PARAMSCNT = 4050;
constexpr const int	ERR_INVALID_FUNCTION_PARAMVALUE = 4051;
constexpr const int	ERR_STRING_FUNCTION_INTERNAL = 4052;
constexpr const int	ERR_SOME_ARRAY_ERROR = 4053;
constexpr const int	ERR_INCORRECT_SERIESARRAY_USING = 4054;
constexpr const int	ERR_CUSTOM_INDICATOR_ERROR = 4055;
constexpr const int	ERR_INCOMPATIBLE_ARRAYS = 4056;
constexpr const int	ERR_GLOBAL_VARIABLES_PROCESSING = 4057;
constexpr const int	ERR_GLOBAL_VARIABLE_NOT_FOUND = 4058;
constexpr const int	ERR_FUNC_NOT_ALLOWED_IN_TESTING = 4059;
constexpr const int	ERR_FUNCTION_NOT_CONFIRMED = 4060;
constexpr const int	ERR_SEND_MAIL_ERROR = 4061;
constexpr const int	ERR_STRING_PARAMETER_EXPECTED = 4062;
constexpr const int	ERR_INTEGER_PARAMETER_EXPECTED = 4063;
constexpr const int	ERR_DOUBLE_PARAMETER_EXPECTED = 4064;
constexpr const int	ERR_ARRAY_AS_PARAMETER_EXPECTED = 4065;
constexpr const int	ERR_HISTORY_WILL_UPDATED = 4066;
constexpr const int	ERR_TRADE_ERROR = 4067;
constexpr const int	ERR_RESOURCE_NOT_FOUND = 4068;
constexpr const int	ERR_RESOURCE_NOT_SUPPORTED = 4069;
constexpr const int	ERR_RESOURCE_DUPLICATED = 4070;
constexpr const int	ERR_INDICATOR_CANNOT_INIT = 4071;
constexpr const int	ERR_INDICATOR_CANNOT_LOAD = 4072;
constexpr const int	ERR_NO_HISTORY_DATA = 4073;
constexpr const int	ERR_NO_MEMORY_FOR_HISTORY = 4074;
constexpr const int	ERR_NO_MEMORY_FOR_INDICATOR = 4075;
constexpr const int	ERR_END_OF_FILE = 4099;
constexpr const int	ERR_SOME_FILE_ERROR = 4100;
constexpr const int	ERR_WRONG_FILE_NAME = 4101;
constexpr const int	ERR_TOO_MANY_OPENED_FILES = 4102;
constexpr const int	ERR_CANNOT_OPEN_FILE = 4103;
constexpr const int	ERR_INCOMPATIBLE_FILEACCESS = 4104;
constexpr const int	ERR_NO_ORDER_SELECTED = 4105;
constexpr const int	ERR_UNKNOWN_SYMBOL = 4106;
constexpr const int	ERR_INVALID_PRICE_PARAM = 4107;
constexpr const int	ERR_INVALID_TICKET = 4108;
constexpr const int	ERR_TRADE_NOT_ALLOWED = 4109;
constexpr const int	ERR_LONGS_NOT_ALLOWED = 4110;
constexpr const int	ERR_SHORTS_NOT_ALLOWED = 4111;
constexpr const int	ERR_TRADE_EXPERT_DISABLED_BY_SERVER = 4112;
constexpr const int	ERR_OBJECT_ALREADY_EXISTS = 4200;
constexpr const int	ERR_UNKNOWN_OBJECT_PROPERTY = 4201;
constexpr const int	ERR_OBJECT_DOES_NOT_EXIST = 4202;
constexpr const int	ERR_UNKNOWN_OBJECT_TYPE = 4203;
constexpr const int	ERR_NO_OBJECT_NAME = 4204;
constexpr const int	ERR_OBJECT_COORDINATES_ERROR = 4205;
constexpr const int	ERR_NO_SPECIFIED_SUBWINDOW = 4206;
constexpr const int	ERR_SOME_OBJECT_ERROR = 4207;
constexpr const int	ERR_CHART_PROP_INVALID = 4210;
constexpr const int	ERR_CHART_NOT_FOUND = 4211;
constexpr const int	ERR_CHARTWINDOW_NOT_FOUND = 4212;
constexpr const int	ERR_CHARTINDICATOR_NOT_FOUND = 4213;
constexpr const int	ERR_SYMBOL_SELECT = 4220;
constexpr const int	ERR_NOTIFICATION_ERROR = 4250;
constexpr const int	ERR_NOTIFICATION_PARAMETER = 4251;
constexpr const int	ERR_NOTIFICATION_SETTINGS = 4252;
constexpr const int	ERR_NOTIFICATION_TOO_FREQUENT = 4253;
constexpr const int	ERR_FTP_NOSERVER = 4260;
constexpr const int	ERR_FTP_NOLOGIN = 4261;
constexpr const int	ERR_FTP_CONNECT_FAILED = 4262;
constexpr const int	ERR_FTP_CLOSED = 4263;
constexpr const int	ERR_FTP_CHANGEDIR = 4264;
constexpr const int	ERR_FTP_FILE_ERROR = 4265;
constexpr const int	ERR_FTP_ERROR = 4266;
constexpr const int	ERR_FILE_TOO_MANY_OPENED = 5001;
constexpr const int	ERR_FILE_WRONG_FILENAME = 5002;
constexpr const int	ERR_FILE_TOO_LONG_FILENAME = 5003;
constexpr const int	ERR_FILE_CANNOT_OPEN = 5004;
constexpr const int	ERR_FILE_BUFFER_ALLOCATION_ERROR = 5005;
constexpr const int	ERR_FILE_CANNOT_DELETE = 5006;
constexpr const int	ERR_FILE_INVALID_HANDLE = 5007;
constexpr const int	ERR_FILE_WRONG_HANDLE = 5008;
constexpr const int	ERR_FILE_NOT_TOWRITE = 5009;
constexpr const int	ERR_FILE_NOT_TOREAD = 5010;
constexpr const int	ERR_FILE_NOT_BIN = 5011;
constexpr const int	ERR_FILE_NOT_TXT = 5012;
constexpr const int	ERR_FILE_NOT_TXTORCSV = 5013;
constexpr const int	ERR_FILE_NOT_CSV = 5014;
constexpr const int	ERR_FILE_READ_ERROR = 5015;
constexpr const int	ERR_FILE_WRITE_ERROR = 5016;
constexpr const int	ERR_FILE_BIN_STRINGSIZE = 5017;
constexpr const int	ERR_FILE_INCOMPATIBLE = 5018;
constexpr const int	ERR_FILE_IS_DIRECTORY = 5019;
constexpr const int	ERR_FILE_NOT_EXIST = 5020;
constexpr const int	ERR_FILE_CANNOT_REWRITE = 5021;
constexpr const int	ERR_FILE_WRONG_DIRECTORYNAME = 5022;
constexpr const int	ERR_FILE_DIRECTORY_NOT_EXIST = 5023;
constexpr const int	ERR_FILE_NOT_DIRECTORY = 5024;
constexpr const int	ERR_FILE_CANNOT_DELETE_DIRECTORY = 5025;
constexpr const int	ERR_FILE_CANNOT_CLEAN_DIRECTORY = 5026;
constexpr const int	ERR_FILE_ARRAYRESIZE_ERROR = 5027;
constexpr const int	ERR_FILE_STRINGRESIZE_ERROR = 5028;
constexpr const int	ERR_FILE_STRUCT_WITH_OBJECTS = 5029;
constexpr const int	ERR_WEBREQUEST_INVALID_ADDRESS = 5200;
constexpr const int	ERR_WEBREQUEST_CONNECT_FAILED = 5201;
constexpr const int	ERR_WEBREQUEST_TIMEOUT = 5202;
constexpr const int	ERR_WEBREQUEST_REQUEST_FAILED = 5203;
constexpr const int	ERR_USER_ERROR_FIRST = 65536;