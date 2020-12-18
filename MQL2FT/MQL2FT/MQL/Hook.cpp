#include "pch.h"

#include "Hook.h"

#if defined ENABLE_HOOKING && __STRATEGY

bool chart_mmove;
bool chart_mmove_timeprice;

struct HandleData
{
	unsigned long process_id;
	HWND window_handle;
};

struct ChildInfo
{
	const char* name; // In
	HWND handle;      // Out
};

struct Price
{
	Price() = default;
	Price(LPCWSTR v, unsigned short yy) : val(v), y(yy) {}

	LPCWSTR val;
	unsigned short y;
};

#define SIZE 6

HWND chart_wnd;
unsigned short chart_w, chart_h;

BYTE old_bytes[SIZE];
BYTE jmp[SIZE];
DWORD old_protect, my_protect = PAGE_EXECUTE_READWRITE;

Price maxp, minp, curp;
LPCWSTR year, date1, date2;
LPCWSTR prev_string;
int prev_string_size;
LPCWSTR mouse_date, mouse_price;

// Helper functions definitions
std::string genChartWndName();
double strToTime(LPCWSTR str);
long strToTimeFull(LPCWSTR str);
int strToMon(LPCWSTR s);
bool isLeapY(int y);

BOOL isMainWindow(HWND handle)
{
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK enumWindowsCallback(HWND handle, LPARAM lParam)
{
	HandleData& data = *(HandleData*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);
	if(data.process_id != process_id || !isMainWindow(handle))
		return TRUE;
	data.window_handle = handle;
	return FALSE;
}

namespace ft
{
	HWND findMainWindow(const unsigned long process_id)
	{
		HandleData data;
		data.process_id = process_id;
		data.window_handle = 0;
		EnumWindows(enumWindowsCallback, (LPARAM)& data);
		return data.window_handle;
	}
}

BOOL CALLBACK enumChildCb(HWND hWnd, LPARAM lParam)
{
	ChildInfo* cinf = (ChildInfo*)lParam;
	char wname[200];
	GetWindowTextA(hWnd, wname, 200);

	if(strcmp(cinf->name, wname))
	{
		return TRUE;
	}
	else
	{
		cinf->handle = hWnd;
		return FALSE;
	}
}

HWND findChartWnd(HWND mw, const char* name)
{
	ChildInfo cinf;
	cinf.name = name;
	cinf.handle = NULL;

	EnumChildWindows(mw, enumChildCb, (LPARAM)&cinf);

	return cinf.handle;
}

namespace ft
{
	double getMinChartPrice()
	{
		int bars = Bars();
		if(!bars || !maxp.val || !minp.val)
		{
			return 0.0;
		}
		
		double max_val = wcstod(maxp.val, nullptr);
		double min_val = wcstod(minp.val, nullptr);

		double one_pix = (max_val - min_val)/(double)(minp.y - maxp.y); // Price of one pixel
		//double min_price = min_val - (double)(chart_h - minp.y - 21) * one_pix;

		double t1 = strToTime(date1);
		double t2 = strToTime(date2);
		double last_bar_t = t1 - (t2 - t1) + (int)_Period/1440.0; // Time of the CURRENT last chart bar

		int i = 0;
		double min_price = 1e+300;
		while(Time(i) > last_bar_t || std::fabs(Time(i) - last_bar_t) < 1e-5)
		{
			if(i >= bars)
			{
				break;
			}
			
			double low = Low(i);
			if(low < min_price)
			{
				min_price = low;
			}
			++i;
		}
			
		return  min_price - 29.0 * one_pix;
	}

	double getMaxChartPrice()
	{
		int bars = Bars();
		if(!bars || !maxp.val || !minp.val)
		{
			return 0.0;
		}

		double max_val = wcstod(maxp.val, nullptr);
		double min_val = wcstod(minp.val, nullptr);
		
		double one_pix = (max_val - min_val)/(double)(minp.y - maxp.y); // Price of one pixel
		//double max_price = max_val + (double)(maxp.y - 5) * one_pix;

		double t1 = strToTime(date1);
		double t2 = strToTime(date2);

		double last_bar_t = t1 - (t2 - t1) + (int)_Period/1440.0; // Time of the CURRENT last chart bar

		int i = 0;
		double max_price = 1e-300;

		while(Time(i) > last_bar_t || std::fabs(Time(i) - last_bar_t) < 1e-5)
		{
			if(i >= bars)
			{
				break;
			}
			
			double high = High(i);
			if(high > max_price)
			{
				max_price = high;
			}
			++i;
		}
			
		return 30.0 * one_pix + max_price;
	}

	int getBarsPerChart()
	{
		int bars = Bars();
		if(!bars)
		{
			return 0.0;
		}

		double t1 = strToTime(date1);
		double t2 = strToTime(date2);

		double last_bar_t = t1 - (t2 - t1) + (int)_Period/1440.0; // Time of the CURRENT last chart bar

		int i = 0;
		double max_price = 1e-300;
		while(Time(i) > last_bar_t || std::fabs(Time(i) - last_bar_t) < 1e-5)
		{
			if(i >= bars)
			{
				return 0;
			}
			
			++i;
		}

		return i;
	}
}

BOOL WINAPI HookedExtTextOutW(HDC hdc, int x, int y, UINT options, CONST RECT* lprect, LPCWSTR lpString, UINT c, CONST INT* lpDx)
{
	VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, my_protect, &old_protect);
	memcpy((void*)ft4_text_out_orig, (const void*)old_bytes, SIZE); // Remove hook, restore original function prologue

	BOOL ret = ExtTextOutW(hdc, x, y, options, lprect, lpString, c, lpDx);

	if(!lpString)
	{
		goto lhook_restore;
	}

	static bool prices_started;
	static bool first_price = true;
	static bool dates_started;
	static bool date_set[3];

	if(dates_started)
	{
		if(!date_set[0])
		{
			delete[] year;
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			year = tmp;
			date_set[0] = true;
		}
		else if(!date_set[1])
		{
			delete[] date1;
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			date1 = tmp;
			date_set[1] = true;
		}
		else if(!date_set[2])
		{
			delete[] date2;
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			date2 = tmp;
			date_set[2] = true;
		}
		else
		{
			if(lpString && lpString[0] == 'P' && lpString[1] == ':' && lpString[2] == ' ')
			{
				delete[] mouse_price;
				LPCWSTR tmp = new WCHAR[c+1];
				memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
				mouse_price = tmp;

				delete[] mouse_date;
				tmp = new WCHAR[prev_string_size+1];
				memcpy((void*)tmp, (const void*)prev_string, (prev_string_size+1) * sizeof(WCHAR));
				mouse_date = tmp;

				dates_started = false;
				date_set[0] = false;
				date_set[1] = false;
				date_set[2] = false;
				goto lreturn; // Return without hooking
			}

			delete[] prev_string;
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			prev_string = tmp;
			prev_string_size = c;
		}
	}

	if(lpString[0] > 57) // Its not a number
	{
		if(prices_started)
		{
			first_price = true;
			prices_started = false;
			dates_started = true;
			memcpy((void*)ft4_text_out_orig, (const void*)jmp, SIZE); // Resotre hook
			goto lreturn;
		}
		else // Resotre hook
		{
			memcpy((void*)ft4_text_out_orig, (const void*)jmp, SIZE);
			goto lreturn;
		}
	}
	else if(x > chart_w - 48) // 48 pixels - constant size of price lables in right side of the chart
	{
		prices_started = true;

		if(first_price)
		{
			first_price = false;
			
			delete[] minp.val;
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			minp.val = tmp;
			minp.y = y + 7; // Account for text y coordinate location in top left corner of text lable
		}
		else
		{
			delete[] maxp.val;
			maxp.val = curp.val;
			maxp.y = curp.y;
			
			LPCWSTR tmp = new WCHAR[c+1];
			memcpy((void*)tmp, (const void*)lpString, (c+1) * sizeof(WCHAR));
			curp.val = tmp;
			curp.y = y + 7;
		}
	}

lhook_restore:
	memcpy((void*)ft4_text_out_orig, (const void*)jmp, SIZE); // Resotre hook

lreturn:
	VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, old_protect, &my_protect);
	return ret;
}

LRESULT CALLBACK chartWinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{
	case WM_MOUSEMOVE:
		if(chart_mmove)
		{
			mql4::OnChartEvent(CHARTEVENT_MOUSE_MOVE, (long)(short)lp, (double)(short)(lp >> 16), std::to_string((unsigned int)wp));
		}
		else if(chart_mmove_timeprice)
		{
			mql4::OnChartEvent(CHARTEVENT_MOUSE_MOVE, strToTimeFull(mouse_date), wcstod(mouse_price+3, nullptr), std::to_string((unsigned int)wp));
		}
		break;
	case WM_KEYDOWN:
		mql4::OnChartEvent(CHARTEVENT_KEYDOWN, (long)wp, 1.0, mql4::string()); // Sparam for keydown has no sense in mql
		break;
	case WM_LBUTTONDOWN:
		mql4::OnChartEvent(CHARTEVENT_CLICK, (long)(short)lp, (double)(short)(lp >> 16), mql4::string());
		break;
	case WM_SIZE:
		chart_w = (unsigned short)lp;
		chart_h = (unsigned short)(lp >> 16);
		break;

	case WM_PAINT:
	{
		VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, PAGE_EXECUTE_READWRITE, &old_protect); // Gain full access to page of memory
		memcpy((void*)ft4_text_out_orig, (const void*)jmp, SIZE); // Rewrite original API function prologue
		VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, old_protect, &my_protect); // Restore old memory protecton rights
	}
	break;
	default:;
	}

	return CallWindowProcA(origWndProc, hwnd, msg, wp, lp);
}

namespace ft
{
	void prepareJumps()
	{
		BYTE tmp_jmp[SIZE] = { 0xE9, 0x42, 0x42, 0x42, 0x42, 0xC3 }; // Jump stub (0xC3 -> RETN (return near))
		memcpy((void*)jmp, (const void*)tmp_jmp, SIZE);
		DWORD jmp_size = ((DWORD)HookedExtTextOutW - (DWORD)ft4_text_out_orig - 5); // 0xE9 - relative JMP, calc displacement
		// Note: -5 because 0xE9 JMP operand is displacement relative to NEXT instruction, not JMP instruction itself!

		VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, PAGE_EXECUTE_READWRITE, &old_protect); // Gain full access to page of memory
		memcpy((void*)old_bytes, (const void*)ft4_text_out_orig, SIZE); // Remember old function prologue
		memcpy((void*)&jmp[1], (const void*)&jmp_size, 4); // Write valid displacement value to jump stub
		VirtualProtect((LPVOID)ft4_text_out_orig, SIZE, old_protect, &my_protect); // Restore old memory protecton rights
	}
	
	void setChartDimensions()
	{		
#ifdef __STRATEGY		
		chart_wnd = findChartWnd(ft4_main_wnd, genChartWndName().c_str());

		if(chart_wnd)
		{
			WNDPROC result = (WNDPROC)SetWindowLongPtrA(chart_wnd, GWLP_WNDPROC, (LONG_PTR)chartWinProc); // For FT messages hooking

			if(result != chartWinProc)
			{
				origWndProc = result;
			}
			
			RECT r;
			if(GetClientRect(chart_wnd, &r))
			{
				chart_w = r.right + 1;
				chart_h = r.bottom + 1;
			}
		}
#else		
		if(!attaching_to_chart)
		{
			return;
		}
		
		chart_wnd = findChartWnd(ft4_main_wnd, genChartWndName().c_str());

		if(chart_wnd)
		{
			if(!origWndProc)
			{
				origWndProc = (WNDPROC)SetWindowLongA(chart_wnd, GWLP_WNDPROC, (LONG)chartWinProc); // For FT messages hooking
			}

			RECT r;
			if(GetClientRect(chart_wnd, &r))
			{
				chart_w = r.right + 1;
				chart_h = r.bottom + 1;
			}
		}
#endif
	}
}

// Helper functions definitions
std::string genChartWndName()
{
	std::string tf;
	switch(_Period)
	{
	case PERIOD_M1:
		tf = "M1";
		break;
	case PERIOD_M5:
		tf = "M5";
		break;
	case PERIOD_M15:
		tf = "M15";
		break;
	case PERIOD_M30:
		tf = "M30";
		break;
	case PERIOD_H1:
		tf = "H1";
		break;
	case PERIOD_H4:
		tf = "H4";
		break;
	case PERIOD_D1:
		tf = "Daily";
		break;
	case PERIOD_W1:
		tf = "Weekly";
		break;
	case PERIOD_MN1:
		tf = "Monthly";
		break;
	default:;
	}

	return _Symbol + ", " + tf;
}

double strToTime(LPCWSTR str)
{
	if(!year)
	{
		return 0.0;
	}
	
	int y, mday, mon, h, m;

	if(year[1] == 32)
	{
		y = (year[6] & 0xF) * 1000 + (year[7] & 0xF) * 100 + (year[8] & 0xF) * 10 + (year[9] & 0xF);
	}
	else
	{
		y = (year[7] & 0xF) * 1000 + (year[8] & 0xF) * 100 + (year[9] & 0xF) * 10 + (year[10] & 0xF);
	}

	if(str[1] == 32)
	{
		mday = str[0] & 0xF;
		mon = strToMon(str+2) - 1;
		h = (str[6] & 0xF) * 10 + (str[7] & 0xF);
		m = (str[9] & 0xF) * 10 + (str[10] & 0xF);
	}
	else
	{
		mday = (str[0] & 0xF) * 10 + (str[1] & 0xF);
		mon = strToMon(str+3) - 1;
		h = (str[7] & 0xF) * 10 + (str[8] & 0xF);
		m = (str[10] & 0xF) * 10 + (str[11] & 0xF);
	}

	int tot_days = 0;
	for(int i = 1970; i < y; ++i)
	{
		int days = isLeapY(i) ? 366 : 365;
		tot_days += days;
	}

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if(isLeapY(y))
	{
		days[1] = 29;
	}

	for(int i = 0; i < mon; ++i)
	{
		tot_days += days[i];
	}

	tot_days += mday - 1;

	return (double)tot_days + (double)(h * 60 + m)/1440.0 + 25569.0;
}

long strToTimeFull(LPCWSTR str)
{
	int y, mday, mon, h, m;

	y = (str[0] & 0xF) * 1000 + (str[1] & 0xF) * 100 + (str[2] & 0xF) * 10 + (str[3] & 0xF);

	mday = (str[8] & 0xF) * 10 + (str[9] & 0xF);
	mon = (str[5] & 0xF) * 10 + (str[6] & 0xF) - 1;
	h = (str[11] & 0xF) * 10 + (str[12] & 0xF);
	m = (str[14] & 0xF) * 10 + (str[15] & 0xF);

	int tot_days = 0;
	for(int i = 1970; i < y; ++i)
	{
		int days = isLeapY(i) ? 366 : 365;
		tot_days += days;
	}

	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if(isLeapY(y))
	{
		days[1] = 29;
	}

	for(int i = 0; i < mon; ++i)
	{
		tot_days += days[i];
	}

	tot_days += mday - 1;

	return tot_days * 86400 + h * 3600 + m * 60;
}

bool isLeapY(int y)
{
	if(y % 4)
	{
		return false;
	}
	else if(y % 100)
	{
		return true;
	}
	else if(y % 400)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int strToMon(LPCWSTR s)
{
	switch(s[0])
	{
	case 'J':
		switch(s[1])
		{
		case 'a':
			return 1;
		case 'u':
			switch(s[2])
			{
			case 'l':
				return 7;
			case 'n':
				return 6;
			}
			break;
		}
		break;
	case 'M':
		switch(s[2])
		{
		case 'r':
			return 3;
		case 'y':
			return 5;
		}
		break;
	case 'S':
		return 9;
	case 'N':
		return 11;
	case 'F':
		return 2;
	case 'A':
		switch(s[1])
		{
		case 'p':
			return 4;
		case 'u':
			return 8;
		}
		break;
	case 'O':
		return 10;
	case 'D':
		return 12;
	default:
		return -1;
	}
}

#endif