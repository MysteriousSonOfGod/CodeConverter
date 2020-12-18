#include "pch.h"

#include "IndicatorInterfaceUnit.h"
#include "Hook.h"

#pragma warning(disable : 4996)  

#ifdef __INDICATOR

bool attaching_to_chart;

//#ifdef ENABLE_HOOKING
//HWND ft4_main_wnd;
//pExtTextOutW ft4_text_out_orig;
//WNDPROC origWndProc;
//#endif

// Helper functions
inline std::string pcharToStr(PChar cstr)
{
	return cstr ? std::string(cstr) : std::string();
}

extern "C" {
	__declspec(dllexport) TInterfaceProcRec IntrfProcsRec;
}

TBufferItem ft_api_buff_item;
//TBuffersArray buff;
TObjectList ft_api_buffers;

using namespace std;

string ft_api_indicator_short_name = "";
int ft_api_indicator_window = 0;

//-------------------------------------------
// buffer item
//-------------------------------------------

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) 
{
	switch (dwReason) 
	{
	case DLL_PROCESS_ATTACH:
	{			
		memset(&IntrfProcsRec, 0, sizeof(TInterfaceProcRec));
		IntrfProcsRec.dwSize = sizeof(TInterfaceProcRec);

		// Determine if indicator is beeing installed into Tester or applied to chart
		char path[MAX_PATH];
		GetModuleFileNameA((HMODULE)hModule, path, sizeof(path));

		std::string fp(path);
		fp = fp.substr(0, fp.find_last_of('\\'));
		fp = fp.substr(fp.find_last_of('\\') + 1);
			
		attaching_to_chart = fp == "Indicators" ? false : true;

		/*#ifdef ENABLE_HOOKING
			if(attaching_to_chart)
			{
				DWORD pid = GetCurrentProcessId();
				ft4_main_wnd = ft::findMainWindow(pid);

				ft4_text_out_orig = (pExtTextOutW)GetProcAddress(GetModuleHandleW(L"gdi32.dll"), "ExtTextOutW");
				ft::prepareJumps();
			}
		#endif*/

		break;
	}

	case DLL_THREAD_ATTACH:
	break;

	case DLL_THREAD_DETACH:
	break;

	case DLL_PROCESS_DETACH:
	//#ifdef ENABLE_HOOKING
	//	if(attaching_to_chart)
	//	{
	//		scmd << "ChartWTD: " << (unsigned int)chart_wnd <<  "ORIGWNDPROC RESTORED: " << (unsigned int)origWndProc << sp;
	//		scmd << (unsigned int)(WNDPROC)SetWindowLongA(chart_wnd, GWLP_WNDPROC, (LONG)origWndProc) << nl; // For FT messages hooking
	//	}
	//#endif
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


///////////////////
// TIndexBuffer //
///////////////////

TIndexBuffer::TIndexBuffer()
{
  fBufferIndex = -1;
}
  
TIndexBuffer::TIndexBuffer(int index)
{
  fBufferIndex = index;
}

int GetBufferCount(int ind)
{
  return IntrfProcsRec.GetBufferCount(IntrfProcsRec.pGetBufferCount, ind); 
}

//-----Get count---------------------------------------------------------------
int TIndexBuffer::Count() const
{ 
  return IntrfProcsRec.GetBufferCount(IntrfProcsRec.pGetBufferCount, fBufferIndex); 
}

//-----Get max value in range--------------------------------------------------
double TIndexBuffer::GetMax(int index1, int index2) 
{
  int cnt = Count() - 1;
  index1 = cnt - index1;
  index2 = cnt - index2;
  if (index1 < 0) index1 = 0;
  if (index2 < 0) index2 = 0;
  
  return IntrfProcsRec.GetBufferMax(IntrfProcsRec.pGetBufferMax, fBufferIndex, index1, index2);
}

//-----Get min value in range--------------------------------------------------
double TIndexBuffer::GetMin(int index1, int index2) 
{
  int cnt = Count() - 1;
  index1 = cnt - index1;
  index2 = cnt - index2;
  if (index1 < 0) index1 = 0;
  if (index2 < 0) index2 = 0;
  
  return IntrfProcsRec.GetBufferMin(IntrfProcsRec.pGetBufferMin, fBufferIndex, index1, index2);
}

//-----Get fBufferIndex value--------------------------------------------------
int& TIndexBuffer::GetBufferIndex()
{
  return fBufferIndex;
}

//-----Get value by index------------------------------------------------------
double TIndexBuffer::GetValue(int index) const
{
  index = Count() - 1 - index;
  if (index < 0) index = 0;

  return IntrfProcsRec.GetBufferValue(IntrfProcsRec.pGetBufferValue, fBufferIndex, index);
}

//-----Set value by index------------------------------------------------------
void TIndexBuffer::SetValue(int index, const double value)
{
  index = Count() - 1 - index;
  if (index < 0) index = 0;

  IntrfProcsRec._SetBufferValue(IntrfProcsRec.p_SetBufferValue, fBufferIndex, index, value);
}

TBufferItem& TIndexBuffer::operator[] (int index)
{
  ft_api_buff_item.ptr = this;
  ft_api_buff_item.index = index;
  return ft_api_buff_item;
}

double TIndexBuffer::operator[] (int index) const
{
	return GetValue(index);
}


///////////////////
// TBufferItem   //
///////////////////

TBufferItem::TBufferItem()
{ 
  ptr = NULL;
  index = -1;
}

TBufferItem::operator double() 
{ 
  return ptr->GetValue(index);
}

TBufferItem& TBufferItem::operator= (double value) 
{ 
  ptr->SetValue(index, value);
  return *this;
}


///////////////////
// TBuffersArray //
///////////////////

//-----Get buffer--------------------------------------------------------------
TIndexBuffer* TBuffersArray::GetBuffer(int index)
{
  for (int i=0; i < ft_api_buffers.Count(); i++)
  {
    if (ft_api_buffers[i]->GetBufferIndex() == index) return ft_api_buffers[i];
  }

  return NULL;
}

TIndexBuffer* TBuffersArray::operator[] (int index)
{
  return GetBuffer(index);
}


/////////////////
// TObjectList //
/////////////////

int TObjectList::Count()
{
  return data.size();
}

void TObjectList::Add(TIndexBuffer buffer)
{
  data.push_back(buffer);
}

TIndexBuffer* TObjectList::Get(int index)
{
  if (index < 0 || LongWord(index) >= data.size()) return NULL;
  return &data[index];
}

TIndexBuffer* TObjectList::operator[] (int index)
{
  return Get(index);
}


//-----Get currency information------------------------------------------------
bool GetCurrencyInfo(const std::string& symbol, PCurrencyInfo& info)
{
	return IntrfProcsRec.GetCurrencyInfo(
		IntrfProcsRec.pGetCurrencyInfo,
		symbol.empty() ? _Symbol.c_str() : symbol.c_str(),
		info);
}

//-----Register option---------------------------------------------------------
void RegOption(PChar OptionName, TOptionType OptionType, void* option)
{
  IntrfProcsRec.RegOption(IntrfProcsRec.pRegOption, OptionName, OptionType, option);
}

//-----Add separator-----------------------------------------------------------
void AddSeparator(PChar text)
{
  IntrfProcsRec.RegOption(IntrfProcsRec.pRegOption, text, ot_Separator, NULL);
}

//-----Add option value (for drop down box options)----------------------------
void AddOptionValue(PChar OptionName, PChar value)
{
  IntrfProcsRec.AddOptionValue(IntrfProcsRec.pAddOptionValue, OptionName, value);
}

void AddOptionValue(PChar OptionName, string s)
{
	char* value;
	value = new char[ s.length()+1 ];
	//strcpy_s(value, s.length()+1, s.c_str());
	strcpy(value, s.c_str());
	AddOptionValue( OptionName, value);
	delete[] value;
}

void AddOptionValue(PChar OptionName, stringstream& s)
{
	AddOptionValue(OptionName, s.str() );
}
//-----Set option range (for int, longword and double types)---------------
void SetOptionRange(PChar OptionName, double LowValue, double HighValue)
{
  IntrfProcsRec.SetOptionRange(IntrfProcsRec.pSetOptionRange, OptionName, LowValue, HighValue);
}

//-----Set option digits-------------------------------------------------------
void SetOptionDigits(PChar OptionName, Word digits)
{
  IntrfProcsRec.SetOptionDigits(IntrfProcsRec.pSetOptionDigits, OptionName, digits);
}

//-----Print text in "Journal" window in ForexTester---------------------------
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

namespace ft
{
	//-----Set indicator short name------------------------------------------------
	void IndicatorShortName(const string& name)
	{
		ft_api_indicator_short_name = name;
		IntrfProcsRec.IndicatorShortName(IntrfProcsRec.pIndicatorShortName, name.c_str());
	}
}

//-----Set number of index buffers---------------------------------------------
void IndicatorBuffers(int count)
{
  IntrfProcsRec.IndicatorBuffers(IntrfProcsRec.pIndicatorBuffers, count);
}

//-----Create index buffer-----------------------------------------------------
TIndexBuffer CreateIndexBuffer()
{
  TIndexBuffer buffer = IntrfProcsRec.CreateIndexBuffer(IntrfProcsRec.pCreateIndexBuffer);
  ft_api_buffers.Add(buffer);

  return buffer;
}

//-----Set index buffer--------------------------------------------------------
void SetIndexBuffer(int index, TIndexBuffer buffer)
{
  IntrfProcsRec.SetIndexBuffer(IntrfProcsRec.pSetIndexBuffer, index, buffer.GetBufferIndex());
}

namespace ft
{
	//-----Set index buffer style--------------------------------------------------
	void SetIndexStyle(int index, TDrawStyle DrawStyle, TPenStyle style, int width, TColor color)
	{
		IntrfProcsRec.SetIndexStyle(IntrfProcsRec.pSetIndexStyle, index, DrawStyle, style, width, color);
	}
}

//-----Set index buffer symbol-------------------------------------------------
void SetIndexSymbol(int index, int symbol, int xoffs, int yoffs)
{
  if (IntrfProcsRec.pSetIndexSymbol != NULL)
    IntrfProcsRec.SetIndexSymbol(IntrfProcsRec.pSetIndexSymbol, index, symbol, xoffs, yoffs);
}

//-----Currency name-----------------------------------------------------------
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

//-----Currency digits after point---------------------------------------------
int Digits()
{
  return IntrfProcsRec.Digits(IntrfProcsRec.pDigits);
}

//-----Minimal currency point--------------------------------------------------
double Point()
{
  return IntrfProcsRec.Point(IntrfProcsRec.pPoint);
}

namespace ft
{
	//-----Get open value----------------------------------------------------------
	double iOpen(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0.0;
		}

		return IntrfProcsRec.iOpen(IntrfProcsRec.p_iOpen, symbol, TimeFrame, index);
	}

	//-----Get close value---------------------------------------------------------
	double iClose(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0.0;
		}

		return IntrfProcsRec.iClose(IntrfProcsRec.p_iClose, symbol, TimeFrame, index);
	}

	//-----Get high value----------------------------------------------------------
	double iHigh(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0.0;
		}

		return IntrfProcsRec.iHigh(IntrfProcsRec.p_iHigh, symbol, TimeFrame, index);
	}

	//-----Get low value-----------------------------------------------------------
	double iLow(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0.0;
		}

		return IntrfProcsRec.iLow(IntrfProcsRec.p_iLow, symbol, TimeFrame, index);
	}

	//-----Get volume--------------------------------------------------------------
	int iVolume(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0;
		}

		return (int)IntrfProcsRec.iVolume(IntrfProcsRec.p_iVolume, symbol, TimeFrame, index);
	}

	//-----Get time of bar---------------------------------------------------------
	TDateTime iTime(PChar symbol, int TimeFrame, int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol, TimeFrame))
		{
			return 0.0;
		}

		return IntrfProcsRec.iTime(IntrfProcsRec.p_iTime, symbol, TimeFrame, index);
	}

	//-----Get number of bars------------------------------------------------------
	int iBars(const std::string& symbol, int TimeFrame)
	{
		return IntrfProcsRec.iBars(IntrfProcsRec.p_iBars, symbol.c_str(), TimeFrame);
	}

}

//-----Get open value in default currency and timeframe------------------------
double Open(int index)
{
	// Reason: MQ4 always return 0.0 when out of bound
	if(index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
	{
		return 0.0;
	}

	return IntrfProcsRec.Open(IntrfProcsRec.pOpen, index);
}

//-----Get close value in default currency and timeframe-----------------------
double Close(int index)
{
	// Reason: MQ4 always return 0.0 when out of bound
	if(index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
	{
		return 0.0;
	}
	
	return IntrfProcsRec.Close(IntrfProcsRec.pClose, index);
}

//-----Get high value in default currency and timeframe------------------------
double High(int index)
{
	// Reason: MQ4 always return 0.0 when out of bound
	if(index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
	{
		return 0.0;
	}

	return IntrfProcsRec.High(IntrfProcsRec.pHigh, index);
}

//-----Get low value in default currency and timeframe-------------------------
double Low(int index)
{
	// Reason: MQ4 always return 0.0 when out of bound
	if(index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
	{
		return 0.0;
	}
	
	return IntrfProcsRec.Low(IntrfProcsRec.pLow, index);
}

//-----Get volume in default currency and timeframe----------------------------
int Volume(int index)
{
	// Reason: MQ4 always return 0.0 when out of bound
	if (index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
	{
		return 0;
	}

	return (int)IntrfProcsRec.Volume(IntrfProcsRec.pVolume, index);
}

namespace ft
{
	//-----Get time of bar in default currency and timeframe-----------------------
	TDateTime Time(int index)
	{
		// Reason: MQ4 always return 0.0 when out of bound
		if(index >= IntrfProcsRec.Bars(IntrfProcsRec.pBars))
		{
			return 0.0;
		}

		return IntrfProcsRec.Time(IntrfProcsRec.pTime, index);
	}
}

//-----Get number of bars in default currency and timeframe--------------------
int Bars()
{
  return IntrfProcsRec.Bars(IntrfProcsRec.pBars);
}

//-----Set indicator output window---------------------------------------------
void SetOutputWindow(TOutputWindow aWindow)
{
	ft_api_indicator_window = aWindow;
	IntrfProcsRec.SetOutputWindow(IntrfProcsRec.pSetOutputWindow, aWindow);
}

//-----Set fixed maximum/minimum for indicator window--------------------------
void SetFixedMinMaxValues(double aMin, double aMax)
{
  IntrfProcsRec.SetFixedMinMaxValues(IntrfProcsRec.pSetFixedMinMaxValues, aMin, aMax);
}

//-----Add level line to indicator window--------------------------------------
void AddLevel(double value, TPenStyle style, int width, TColor color)
{
  IntrfProcsRec.AddLevel(IntrfProcsRec.pAddLevel, value, style, width, color);
}

//-----Set empty value that will not be painted--------------------------------
void SetEmptyValue(double value)
{
  IntrfProcsRec.SetEmptyValue(IntrfProcsRec.pSetEmptyValue, value);
}

//-----Set indicator precision-------------------------------------------------
void IndicatorDigits(int digits)
{
  if (IntrfProcsRec.pIndicatorDigits != NULL)
	IntrfProcsRec.IndicatorDigits(IntrfProcsRec.pIndicatorDigits, digits);
}

//-----Get indicator timeframe-------------------------------------------------
int Timeframe()
{
  if (IntrfProcsRec.pTimeframe != NULL)
	return int(IntrfProcsRec.Timeframe(IntrfProcsRec.pTimeframe));
  else
	return PERIOD_M1;
}

namespace ft
{
	//-----Set index label---------------------------------------------------------
	void SetIndexLabel(int index, const string& text)
	{
		if(IntrfProcsRec.SetIndexLabel != NULL)
		{
			IntrfProcsRec.SetIndexLabel(IntrfProcsRec.pSetIndexLabel, index, text.c_str());
		}
	}


	//-----Create object-----------------------------------------------------------
	bool ObjectCreate(const string& name, TObjectType ObjType, int window,
	  TDateTime time1, double price1, TDateTime time2, double price2, 
	  TDateTime time3, double price3)
	{
	  if (IntrfProcsRec.pObjectCreate != NULL) 
		return IntrfProcsRec.ObjectCreate(IntrfProcsRec.pObjectCreate, name.c_str(), ObjType, window, 
		  time1, price1, time2, price2, time3, price3);
  
	  return false;
	}

	//-----Delete object by name---------------------------------------------------
	void ObjectDelete(const string& name)
	{
	  if (IntrfProcsRec.pObjectDelete != NULL)
		IntrfProcsRec.ObjectDelete(IntrfProcsRec.pObjectDelete, name.c_str());
	}

	//-----Check if object already exists------------------------------------------
	bool ObjectExists(const string& name)
	{
	  if (IntrfProcsRec.pObjectExists != NULL)
		return IntrfProcsRec.ObjectExists(IntrfProcsRec.pObjectExists, name.c_str());
	  else
		return false;
	}

	//-----Get object type---------------------------------------------------------
	TObjectType ObjectType(const string& name)
	{
	  if (IntrfProcsRec.pObjectType != NULL)
		return TObjectType(IntrfProcsRec.ObjectType(IntrfProcsRec.pObjectType, name.c_str()));
	  else
		return obj_Text;
	}

	bool ObjectSet(const string& name, int index, double value)
	{
	  if (IntrfProcsRec.pObjectSet != NULL)
		return IntrfProcsRec.ObjectSet(IntrfProcsRec.pObjectSet, name.c_str(), index, value);
	  else 
		return false;
	}

	//-----Get object property-----------------------------------------------------
	double ObjectGet(const string& name, int index)
	{
	  if (IntrfProcsRec.pObjectGet != NULL)
		return IntrfProcsRec.ObjectGet(IntrfProcsRec.pObjectGet, name.c_str(), index);
	  else
		return 0;
	}


	//-----Delete all objects------------------------------------------------------
	void ObjectsDeleteAll(int window, TObjectType ObjType)
	{
		if(IntrfProcsRec.pObjectsDeleteAll != NULL)
			IntrfProcsRec.ObjectsDeleteAll(IntrfProcsRec.pObjectsDeleteAll, window, ObjType);
	}

	//-----Set text----------------------------------------------------------------
	bool ObjectSetText(const string& name, const string& text, const int FontSize, const string& FontName,
		const TColor Color)
	{
		if(IntrfProcsRec.pObjectSetText != NULL)
			return IntrfProcsRec.ObjectSetText(IntrfProcsRec.pObjectSetText, name.c_str(), text.c_str(),
				FontSize, FontName.c_str(), Color);
		else
			return false;
	}
}

//-----Get interface version---------------------------------------------------
void GetInterfaceVersion(int& MajorValue, int& MinorValue)
{
  if (IntrfProcsRec.pGetInterfaceVersion != NULL)
    IntrfProcsRec.GetInterfaceVersion(IntrfProcsRec.pGetInterfaceVersion, MajorValue, MinorValue);
  else
    {
      MajorValue = 1;
      MinorValue = 3;
    }
}

//-----Get text---------------------------------------------------------------
string ObjectGetText(const string& name)
{
  if (IntrfProcsRec.ObjectGetText != NULL)
    return pcharToStr(IntrfProcsRec.ObjectGetText(IntrfProcsRec.pObjectGetText, name.c_str()));
  else
    return string();
}

//-----Set buffer shift--------------------------------------------------------
void SetBufferShift(int index, int Shift)
{
  if (IntrfProcsRec.SetBufferShift != NULL)
	IntrfProcsRec.SetBufferShift(IntrfProcsRec.pSetBufferShift, index, Shift);
}

//-----Get buffer value-------------------------------------------------------
double GetIndicatorBufferValue(TIndicatorOption indicator, int index)
{
  if ((IntrfProcsRec.GetIndicatorBufferValue != NULL) &&
      (indicator.BufferPtr != NULL))
	  return IntrfProcsRec.GetIndicatorBufferValue(IntrfProcsRec.pGetIndicatorBufferValue, indicator, index);
  else
    return(0);
}

namespace ft
{
	//-----Get number of graphical objects on associated chart--------------------
	int ObjectsTotal()
	{
		if(IntrfProcsRec.ObjectsTotal != NULL)
			return IntrfProcsRec.ObjectsTotal(IntrfProcsRec.pObjectsTotal);
		else
			return(0);
	}


	//-----Get object's name by its index-----------------------------------------
	std::string ObjectName(int index)
	{
	  if (IntrfProcsRec.ObjectName != NULL) 
		return pcharToStr(IntrfProcsRec.ObjectName(IntrfProcsRec.pObjectName, index));
	  else
		return std::string();
	}
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

		return IntrfProcsRec.iHighest(IntrfProcsRec.piHighest,
			symbol.c_str(),
			TimeFrame,
			_type,
			count == 0 ? bars : count,
			index);
	}

	//-----Get lowest value in array----------------------------------------------
	int iLowest(const std::string& symbol, int TimeFrame, int _type, int count, int index)
	{
		if(IntrfProcsRec.iLowest == nullptr) return -1;

		const int bars = iBars(symbol, TimeFrame);
		if(index >= bars) return -1; // MQL4 emulation

		return IntrfProcsRec.iLowest(IntrfProcsRec.piLowest,
			symbol.c_str(),
			TimeFrame,
			_type,
			count == 0 ? bars : count,
			index);
	}
}

//-----Convert chart index to screen x coordinate-----------------------------
int ChartToScrX(int index)
{
  if (IntrfProcsRec.ChartToScrX == nullptr) return 0;
  return IntrfProcsRec.ChartToScrX(IntrfProcsRec.pChartToScrX, index);
}

//-----Convert chart price to screen y coordinate-----------------------------
int ChartToScrY(double price)
{
  if (IntrfProcsRec.ChartToScrY == nullptr) return 0;
  return IntrfProcsRec.ChartToScrY(IntrfProcsRec.pChartToScrY, price);
}

//-----Convert screen x coordinate to chart bar's index-----------------------
int ScrToChartX(int x)
{
  if (IntrfProcsRec.ScrToChartX == nullptr) return 0;
  return IntrfProcsRec.ScrToChartX(IntrfProcsRec.pScrToChartX, x);
}

//-----Convert screen y coordinate to chart price-----------------------------
double ScrToChartY(int y)
{
  if (IntrfProcsRec.ScrToChartY == nullptr) return 0.0;
  return IntrfProcsRec.ScrToChartY(IntrfProcsRec.pScrToChartY, y);
}

//-----Get information about chart--------------------------------------------
bool  GetChartInfo(TChartInfo& ChartInfo)
{
  if (IntrfProcsRec.GetChartInfo == nullptr) return false;
  
  ChartInfo.dwSize = sizeof(ChartInfo);
  return IntrfProcsRec.GetChartInfo(IntrfProcsRec.pGetChartInfo, ChartInfo);
}

//-----Get current bid price--------------------------------------------------
double Bid()
{
  if (IntrfProcsRec.Bid == nullptr) return 0;
  return IntrfProcsRec.Bid(IntrfProcsRec.pBid);
}

//-----Get current bid price--------------------------------------------------
double Ask()
{
  if (IntrfProcsRec.Ask == nullptr) return 0;
  return IntrfProcsRec.Ask(IntrfProcsRec.pAsk);
}

namespace ft
{
	//-----Get current time-------------------------------------------------------
	TDateTime TimeCurrent()
	{
		if(IntrfProcsRec.TimeCurrent == nullptr) return 0;
		return IntrfProcsRec.TimeCurrent(IntrfProcsRec.pTimeCurrent);
	}
}

void SetCalcModeMT4()
{
  if (IntrfProcsRec.SetCalcModeMT4 == nullptr) return;
  IntrfProcsRec.SetCalcModeMT4(IntrfProcsRec.pSetCalcModeMT4);
}

int mql4_IndicatorCounted()
{
	if (IntrfProcsRec.mql4_IndicatorCounted == nullptr) return 0;
	return IntrfProcsRec.mql4_IndicatorCounted(IntrfProcsRec.pmql4_IndicatorCounted);
}

// set empty value for indicator buffer
void SetIndexEmptyValue(int index, double value)
{
	if(IntrfProcsRec.SetIndexEmptyValue == nullptr) return;
	IntrfProcsRec.SetIndexEmptyValue(IntrfProcsRec.pSetIndexEmptyValue, index, value);
}

// set first index from which indicator line will be painted
void SetIndexDrawBegin(int index, int DrawBegin)
{
	if(IntrfProcsRec.SetIndexDrawBegin == nullptr) return;
	IntrfProcsRec.SetIndexDrawBegin(IntrfProcsRec.pSetIndexDrawBegin, index, DrawBegin);
}

#endif