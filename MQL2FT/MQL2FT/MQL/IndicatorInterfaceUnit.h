#pragma once

#ifdef __INDICATOR

extern std::string _Symbol;

#define EXPORT extern "C" __declspec(dllexport)

#define PChar char*
#define CSTR const char*
#define TDateTime double
#define TColor long
#define PCurrencyInfo TCurrencyInfo*
#define PInterfaceProcRec TInterfaceProcRec*

extern bool attaching_to_chart;

//#ifdef ENABLE_HOOKING
//typedef BOOL(WINAPI *pExtTextOutW)(HDC, int, int, UINT, RECT*, LPCWSTR, UINT, INT*);
//extern HWND ft4_main_wnd;
//extern pExtTextOutW ft4_text_out_orig;
//extern WNDPROC origWndProc;
//extern HWND chart_wnd;
//#endif

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

// Special code for transparent
#define cl_Transparent	0x1FFFFFFFL

// current color of the grid (AddLevel procedure)
#define cl_GridColor	0x01000000L


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
// indicator option record
//-------------------------------------------
struct TIndicatorOption {
  PChar ParamsStr;            // params string
  void* BufferPtr;            // pointer to buffer object
};

//-------------------------------------------
// chart info
//-------------------------------------------
struct TChartInfo {
  int dwSize;
  int FirstIndex;
  int LastIndex;
  RECT PaintRect;
  int BarWidth;
};

#pragma pack(pop)


//-------------------------------------------
// buffer item
//-------------------------------------------
class TIndexBuffer;

class TBufferItem
{
friend class TIndexBuffer;

private:
  TIndexBuffer* ptr;
  int index;

public:
  TBufferItem();

  operator double();
  TBufferItem& operator= (double value);
};

//-------------------------------------------
// index buffer
//-------------------------------------------
class TIndexBuffer
{
private:
  int fBufferIndex;

public:
  TIndexBuffer();
  TIndexBuffer(int index);
  
  int Count() const;
  double GetMax(int index1, int index2);
  double GetMin(int index1, int index2);
  int& GetBufferIndex();

  double GetValue(int index) const;
  void SetValue(int index, const double value);

  TBufferItem& operator[] (int index);
  double operator[] (int index) const;
};


//-------------------------------------------
// Buffers array
//-------------------------------------------
class TBuffersArray
{
private:
  TIndexBuffer* GetBuffer(int index);

public:
  TIndexBuffer* operator[] (int index);

  //property    data[index: int]: TIndexBuffer read GetBuffer; default;
};


//-------------------------------------------
// TObjectList class
//-------------------------------------------
class TObjectList 
{
private:
  std::vector<TIndexBuffer> data;

public:
  int Count();
  void Add(TIndexBuffer buffer);
  TIndexBuffer* Get(int index);
  
  TIndexBuffer* operator[] (int index);
};


// option type
enum TOptionType {
  ot_Longword  = 0,
  ot_Integer   = 1,
  ot_double    = 2, // Obsolete!!!, left here for backwards compat. use ot_Double
  ot_Double    = 2, 
  ot_PChar     = 3,
  ot_Boolean   = 4,
  ot_EnumType  = 5,
  ot_TimeFrame = 6,
  ot_Currency  = 7,
  ot_LineStyle = 8,
  ot_Separator = 9,
  ot_Indicator = 10,
  ot_Color     = 11,
  ot_Reserved0 = 12,
  ot_DateTime  = 13
};

// indicator window
enum TOutputWindow {
  ow_ChartWindow    = 0,
  ow_SeparateWindow = 1
};

// drawing type
enum TDrawStyle {
  ds_Line           = 0,
  ds_Histogram      = 1,
  ds_Fill           = 2,
  ds_Symbol         = 3,
  ds_Section        = 4,
  ds_HistogramFill  = 5,
  ds_ColoredCandles = 6,
  ds_None           = 10
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
  obj_Rectangle        = 13,
  obj_Ellipse          = 14,
  obj_Triangle         = 15,
  obj_FiboChannel      = 16,
  obj_LRChannel        = 17,
  obj_FiboExtension    = 18,
};

// timeframes
enum ENUM_TIMEFRAMES
{
	PERIOD_CURRENT = 0,
	PERIOD_M1      = 1,
	PERIOD_M5      = 5,
	PERIOD_M15     = 15,
	PERIOD_M30     = 30,
	PERIOD_H1      = 60,
	PERIOD_H4      = 240,
	PERIOD_D1      = 1440,
	PERIOD_W1      = 10080,
	PERIOD_MN1     = 43200
};

//#define PERIOD_M1				1
//#define PERIOD_M5				5
//#define PERIOD_M15			15
//#define PERIOD_M30			30    
#define PERIOD_M39				39    // 10 bars on the US Stock Exchange in one day
//#define PERIOD_H1				60*1
#define PERIOD_H2				60*2
#define PERIOD_H3				60*3
//#define PERIOD_H4				60*4
#define PERIOD_H5				60*5
#define PERIOD_H6				60*6
#define PERIOD_H7				60*7
#define PERIOD_H8				60*8
#define PERIOD_H9				60*9
#define PERIOD_H10				60*10
#define PERIOD_H11				60*11
#define PERIOD_H12				60*12
#define PERIOD_H13				60*13
#define PERIOD_H14				60*14
#define PERIOD_H15				60*15
#define PERIOD_H16				60*16
#define PERIOD_H17				60*17
#define PERIOD_H18				60*18
#define PERIOD_H19				60*19
#define PERIOD_H20				60*20
#define PERIOD_H21				60*21
#define PERIOD_H22				60*22
#define PERIOD_H23				60*23
//#define PERIOD_D1				60*24
//#define PERIOD_W1				60*24*7
#define PERIOD_MN				43200
//#define PERIOD_MN1			43200

// object properties constants

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


// Get currency information
// Symbol - currency name
// info - pointer to TCurrencyInfo record
// result: true if success
bool GetCurrencyInfo(const std::string& symbol, PCurrencyInfo& info);

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
void AddOptionValue(PChar OptionName, std::string s);
void AddOptionValue(PChar OptionName, std::stringstream& s);

// Set option range (for int, longword and double types)
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
void Print(PChar s);        // s - PChar
void Print(std::string s);		// s - string
void Print(std::stringstream& s);// s - stringstream 
void Print(int i);          // s - int
void Print(double d);       // s - double

namespace ft
{
	// Set indicator short name
	// name - short name
	void IndicatorShortName(const std::string& name);
}

// Set number of index buffers
// count - number of buffers
void IndicatorBuffers(int count);

// Create index buffer
// result - buffer id
TIndexBuffer CreateIndexBuffer();

// Set index buffer
// index - number of index buffer slot
// buffer - buffer id
void SetIndexBuffer(int index, TIndexBuffer buffer);

namespace ft
{
	// Set index buffer style
	// index - number of index buffer slot
	// _type - paint type
	// style - line style
	// width - line width
	// color - line color
	void SetIndexStyle(int index, TDrawStyle DrawStyle, TPenStyle style, int width, TColor color);
}

// Set index symbol
// index - number of an index buffer slot
// symbol - number of symbol in Wingdings font
// xoffs - x offset from center point of the symbol in pixels
// yoffs - y offset from center point of the symbol in pixels
void SetIndexSymbol(int index, int symbol, int xoffs = 0, int yoffs = 0);

namespace ft
{
	// Set index label
	// index - number of an index buffer slot
	// text - text label
	void SetIndexLabel(int index, const std::string& text);
}

// Set indicator output window
// aWindow - where to paint indicator (ow_ChartWindow, ow_SeparateWindow)
void SetOutputWindow(TOutputWindow aWindow);

// Set fixed maximum/minimum for indicator window
// aMin - minimum value
// aMax - maximum value
void SetFixedMinMaxValues(double aMin, double aMax);

// Add level line to indicator window
// value - level value
// style - line style
// width - line width
// color - line color
void AddLevel(double value, TPenStyle style, int width, TColor color);

// Set empty value that will not be painted
// value - new empty value
void SetEmptyValue(double value);

// Currency name
std::string Symbol();

// Currency digits after point
int Digits();

// Minimal currency point
double Point();

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
	int iBars(const std::string& symbol, int TimeFrame);
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

// Set indicator precision (number of digits after .)
// digits - number of digits after point
void IndicatorDigits(int digits);

// Get indicator timeframe
int Timeframe();

// Get interface version
void GetInterfaceVersion(int& MajorValue, int& MinorValue);

// Set buffer shift in bars
void SetBufferShift(int index, int Shift);

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
	bool ObjectSetText(const std::string& name, const std::string& text, const int FontSize = 12,
		const std::string& FontName = "Arial", const TColor Color = clNone);
}

// get text/description of the object
// name - name of the object
// function returns text or empty string if failed
std::string ObjectGetText(const std::string& name);

// get buffer value
double GetIndicatorBufferValue(TIndicatorOption indicator, int index);

namespace ft
{
	// get number of graphical objects on associated chart
	int  ObjectsTotal();

	// get object's name by its index
	// index - object's index
	std::string ObjectName(int index);
}

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
	int iHighest(const std::string& symbol, int TimeFrame, int _type, int count = 0, int index = 0);

	// get lowest value in array
	// Symbol - requested currency
	// TimeFrame - requested timeframe
	// _type - type of value (see constants MODE_OPEN .. MODE_TIME)
	// count - number of bars to search
	// index - first index to start searching
	// function returns index of the bar if successful, and -1 if failed
	int iLowest(const std::string& symbol, int TimeFrame, int _type, int count = 0, int index = 0);
}

// convert chart index to screen x coordinate
// index - index of a bar
// function returns x coordinate if succesful, and 0 if failed
int ChartToScrX(int index);

// convert chart price to screen y coordinate
// price - price value
// function returns y coordinate if succesful, and 0 if failed
int ChartToScrY(double price);

// convert screen x coordinate to chart bar's index
// x - screen x coordinate
// function returns index if succesful, and -1 if failed
int ScrToChartX(int x);

// convert screen y coordinate to chart price
// y - screen y coordinate
// function returns price value if succesful, and -1 if failed
double ScrToChartY(int y);

// get information about chart
// function returns true and filled ChartInfo structure if succesful, and
// false if faled
bool GetChartInfo(TChartInfo& ChartInfo);

// get current Bid price
double Bid();

// get current Ask price
double Ask();

namespace ft
{
	// get current time
	TDateTime TimeCurrent();
}

void SetCalcModeMT4();
int mql4_IndicatorCounted();

// set empty value for indicator buffer
void SetIndexEmptyValue(int index, double value);

// set first index from which indicator line will be painted
void SetIndexDrawBegin(int index, int DrawBegin );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//implementation
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// indicator interface procedures
typedef bool (__stdcall *TGetCurrencyInfoFunc) (void* ptr, CSTR Symbol, PCurrencyInfo& info);
typedef void (__stdcall *TSetPropertyProc) (void* ptr, int PropertyID, void* value);
typedef void (__stdcall *TRegOptionProc) (void* ptr, PChar OptionName, int OptionType, void* OptionPtr);
typedef void (__stdcall *TAddOptionValueProc) (void* ptr, PChar OptionName, PChar value);
typedef void (__stdcall *TSetOptionRange) (void* ptr, PChar OptionName, double LowValue, double HighValue);
typedef void (__stdcall *TSetOptionDigitsProc) (void* ptr, PChar OptionName, Word digits);
typedef void (__stdcall *TPrintProc) (void* ptr, PChar s);
typedef double (__stdcall *TGetDoubleFunc) (void* ptr);
typedef PChar (__stdcall *TGetPCharFunc) (void* ptr);
typedef int (__stdcall *TGetIntegerFunc) (void* ptr);
typedef double (__stdcall *TGet_iOHLCVFunc) (void* ptr, PChar Symbol, LongWord TimeFrame, int index);
typedef TDateTime (__stdcall *TGet_iTimeFunc) (void* ptr, PChar Symbol, LongWord TimeFrame, int index);
typedef LongWord (__stdcall *TGet_iBarsFunc) (void* ptr, CSTR Symbol, LongWord TimeFrame);
typedef double (__stdcall *TGetOHLCVFunc) (void* ptr, int index);
typedef TDateTime (__stdcall *TGetTimeFunc) (void* ptr, int index);
typedef LongWord (__stdcall *TGetBarsFunc) (void* ptr);
typedef void (__stdcall *TIndicatorShortNameProc) (void* ptr, CSTR name);
typedef void (__stdcall *TIndicatorBuffersProc) (void* ptr, int count);
typedef int (__stdcall *TCreateIndexBufferFunc) (void* ptr);
typedef void (__stdcall *TSetIndexBufferProc) (void* ptr, int index, int buffer);
typedef void (__stdcall *TSetIndexStyleProc) (void* ptr, int index, int _type, int _style, int width, int clr);
typedef double (__stdcall *TGetBufferValueFunc) (void* ptr, int buffer, LongWord index);
typedef void (*TSetBufferValueProc) (void* ptr, int buffer, LongWord index, double value);
typedef void (__stdcall *_TSetBufferValueProc) (void* ptr, int buffer, LongWord index, double value);
typedef LongWord (__stdcall *TGetBufferCountFunc) (void* ptr, int buffer);
typedef double (__stdcall *TGetBufferMaxFunc) (void* ptr, int buffer, LongWord index1, LongWord index2);
typedef double (__stdcall *TGetBufferMinFunc) (void* ptr, int buffer, LongWord index1, LongWord index2);
typedef void (__stdcall *TSetOutputWindowProc) (void* ptr, int aWindow);
typedef void (__stdcall *TSetFixedMinMaxValuesProc) (void* ptr, double aMin, double aMax);
typedef void (__stdcall *TAddLevelProc) (void* ptr, double value, int _style, int width, int clr);
typedef void (__stdcall *TSetEmptyValueProc) (void* ptr, double value);
typedef void (__stdcall *TSetIndexSymbolProc) (void* ptr, int index, int symbol, int xoffs, int yoffs);
typedef void (__stdcall *TIndicatorDigitsProc) (void* ptr, int digits);
typedef void (__stdcall *TSetIndexLabelProc) (void* ptr, int index, CSTR text);
typedef void (__stdcall *TGetInterfaceVersionProc) (void* ptr, int& MajorValue, int& MinorValue);
typedef bool (__stdcall *TObjectCreateFunc) (void* ptr, CSTR name, int ObjType, int window,
  TDateTime time1, double price1, TDateTime time2, double price2, TDateTime time3, double price3);
typedef void (__stdcall *TObjectDeleteProc) (void* ptr, CSTR name);
typedef bool (__stdcall *TObjectExistsFunc) (void* ptr, CSTR name);
typedef int (__stdcall *TObjectTypeFunc) (void* ptr, CSTR name);
typedef bool (__stdcall *TObjectSetFunc) (void* ptr, CSTR name, int index, double value);
typedef double (__stdcall *TObjectGetFunc) (void* ptr, CSTR name, int index);
typedef void (__stdcall *TObjectsDeleteAllProc) (void* ptr, int window, int ObjType);
typedef bool (__stdcall *TObjectSetTextFunc) (void* ptr, CSTR name, CSTR text, int FontSize,
	CSTR FontName, int Color);
typedef void (__stdcall *TSetBufferShift) (void* ptr, int index, int Shift);
typedef double (__stdcall *TGetIndicatorBufferValueFunc) (void* ptr, TIndicatorOption indicator, int index);
typedef PChar (__stdcall *TObjectNameFunc) (void* ptr, int index);
typedef int (__stdcall *TIBarShiftFunc) (void* ptr, CSTR Symbol, int TimeFrame, TDateTime time, bool Exact);
typedef int (__stdcall *TIHighestFunc) (void* ptr, CSTR Symbol, int TimeFrame, int _type, int count, int index);
typedef int (__stdcall *TILowestFunc) (void* ptr, CSTR Symbol, int TimeFrame, int _type, int count, int index);
typedef int (__stdcall *TChartToScrXFunc) (void* ptr, int index);
typedef int (__stdcall *TChartToScrYFunc) (void* ptr, double price);
typedef int (__stdcall *TScrToChartXFunc) (void *ptr, int x);
typedef double (__stdcall *TScrToChartYFunc) (void* ptr, int y);
typedef bool (__stdcall *TGetChartInfoFunc) (void* ptr, TChartInfo& ChartInfo);
typedef int (__stdcall *TCreateLoopbackIndexBufferFunc) (void* ptr, int MaxSize);
typedef void (__stdcall *TAddBufferValueProc) (void* ptr, int buffer, TDateTime DateTime, double value);
typedef int (__stdcall *TGetBufferItemsCountFunc) (void* ptr, int buffer);
typedef PChar (__stdcall *TObjectGetTextFunc) (void* ptr, CSTR name);
typedef void (__stdcall *TSetCalcModeMT4Proc) (void* ptr);
typedef int (__stdcall *Tmql4_IndicatorCountedFunc) (void* ptr);
typedef void(__stdcall *TSetIndexEmptyValueProc) (void* ptr, int index, double value);
typedef void(__stdcall *TSetIndexDrawBeginProc) (void* ptr, int index, int DrawBegin);

#pragma pack(push)

// pointers to interface procedures
struct TInterfaceProcRec {
  LongWord dwSize;

  TGetCurrencyInfoFunc GetCurrencyInfo;
  void* pGetCurrencyInfo;

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

  TIndicatorShortNameProc IndicatorShortName;
  void* pIndicatorShortName;

  TIndicatorBuffersProc IndicatorBuffers;
  void* pIndicatorBuffers;

  TCreateIndexBufferFunc CreateIndexBuffer;
  void* pCreateIndexBuffer;

  TSetIndexBufferProc SetIndexBuffer;
  void* pSetIndexBuffer;

  TSetIndexStyleProc SetIndexStyle;
  void* pSetIndexStyle;

  TSetOutputWindowProc SetOutputWindow;
  void* pSetOutputWindow;

  TSetFixedMinMaxValuesProc SetFixedMinMaxValues;
  void* pSetFixedMinMaxValues;

  TAddLevelProc AddLevel;
  void* pAddLevel;

  TSetEmptyValueProc SetEmptyValue;
  void* pSetEmptyValue;

  TGetBufferValueFunc GetBufferValue;
  void* pGetBufferValue;
  
  TSetBufferValueProc SetBufferValue;
  void* pSetBufferValue;

  TGetBufferCountFunc GetBufferCount;
  void* pGetBufferCount;

  TGetBufferMaxFunc GetBufferMax;
  void* pGetBufferMax;

  TGetBufferMinFunc GetBufferMin;
  void* pGetBufferMin;

  TGetPCharFunc Symbol;
  void* pSymbol;

  TGetIntegerFunc Digits;
  void* pDigits;

  TGetDoubleFunc Point;
  void* pPoint;

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

  // extentions (dwSize > 300)
  TSetIndexSymbolProc SetIndexSymbol;
  void* pSetIndexSymbol;

  // extensions (dwSize > 308)
  TIndicatorDigitsProc IndicatorDigits;
  void* pIndicatorDigits;

  TGetIntegerFunc Timeframe;
  void* pTimeframe;

  // extensions (dwSize > 324)
  TSetIndexLabelProc SetIndexLabel;
  void* pSetIndexLabel;

  // extensions ver 1.4 (dwSize > 332)
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

  // extensions ver 1.5 (dwSize > 404)
  _TSetBufferValueProc _SetBufferValue;
  void* p_SetBufferValue;

  TSetBufferShift SetBufferShift;
  void* pSetBufferShift;

  // extensions ver 1.6 (dwSize > 420)
  TGetIndicatorBufferValueFunc GetIndicatorBufferValue;
  void* pGetIndicatorBufferValue;

  // extensions ver 1.9 (dwSize > 428)
  TGetIntegerFunc ObjectsTotal;
  void* pObjectsTotal;

  TObjectNameFunc ObjectName;
  void* pObjectName;

  TIBarShiftFunc iBarShift;
  void* piBarShift;

  TIHighestFunc iHighest;
  void* piHighest;

  TILowestFunc iLowest;
  void* piLowest;

  
  // extensions ver 1.10 (dwSize > 468)
  TChartToScrXFunc ChartToScrX;
  void* pChartToScrX;

  TChartToScrYFunc ChartToScrY;
  void* pChartToScrY;
  
  TScrToChartXFunc ScrToChartX;
  void* pScrToChartX;

  TScrToChartYFunc ScrToChartY;
  void* pScrToChartY;

  TGetChartInfoFunc GetChartInfo;
  void* pGetChartInfo;


  // extensions ver 1.11 (dwSize > 508)
  TCreateLoopbackIndexBufferFunc CreateLoopbackIndexBuffer;
  void* pCreateLoopbackIndexBuffer;

  TAddBufferValueProc AddBufferValue;
  void* pAddBufferValue;

  TGetBufferItemsCountFunc GetBufferItemsCount;
  void* pGetBufferItemsCount;


  // extensions ver 1.12 (dwSize > 532)
  TGetDoubleFunc Bid;
  void* pBid;

  TGetDoubleFunc Ask;
  void* pAsk;

  TGetDoubleFunc TimeCurrent;
  void* pTimeCurrent;

  // extensions ver 1.13 (dwSize > 556)
  TObjectGetTextFunc ObjectGetText;
  void* pObjectGetText;
  
  // extenstions ver 1.14 (dwSize > 564)
  TSetCalcModeMT4Proc SetCalcModeMT4;
  void* pSetCalcModeMT4;
  
  TGetIntegerFunc mql4_IndicatorCounted;
  void* pmql4_IndicatorCounted;
  
  // extensions ver 1.15 (dwSize > 580)
  TSetIndexEmptyValueProc SetIndexEmptyValue;
  void* pSetIndexEmptyValue;

  TSetIndexDrawBeginProc SetIndexDrawBegin;
  void* pSetIndexDrawBegin;
};

#pragma pack(pop)

#endif

#pragma comment(linker, "/EXPORT:ReplaceStr=_ReplaceStr@8") // for VisualStudio's linker to "solve" __stdcall function name mangling
extern "C" __declspec(dllexport) void __stdcall ReplaceStr(char* &dest, const char* source);
