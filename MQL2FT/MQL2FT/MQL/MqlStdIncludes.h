#pragma once

#include <string>
#include "FTCore.h"

// Stdlib
string ErrorDescription(int error_code);
bool CompareDoubles(double number1, double number2);
string DoubleToStrMorePrecision(double number, int precision);
string IntegerToHexString(int integer_number);

// MovingAverages
//+------------------------------------------------------------------+
//| Simple Moving Average                                            |
//+------------------------------------------------------------------+
double SimpleMA(const int position, const int period, const Array<double> &price);

//+------------------------------------------------------------------+
//| Exponential Moving Average                                       |
//+------------------------------------------------------------------+
double ExponentialMA(const int position, const int period, const double prev_value, const Array<double> &price);

//+------------------------------------------------------------------+
//| Smoothed Moving Average                                          |
//+------------------------------------------------------------------+
double SmoothedMA(const int position, const int period, const double prev_value, const Array<double> &price);

//+------------------------------------------------------------------+
//| Linear Weighted Moving Average                                   |
//+------------------------------------------------------------------+
double LinearWeightedMA(const int position, const int period, const Array<double> &price);

//+------------------------------------------------------------------+
//| Simple moving average on price array                             |
//+------------------------------------------------------------------+
int SimpleMAOnBuffer(const int rates_total, const int prev_calculated, const int begin,
	const int period, const Array<double>& price, Array<double>& buffer);

//+------------------------------------------------------------------+
//|  Exponential moving average on price array                       |
//+------------------------------------------------------------------+
int ExponentialMAOnBuffer(const int rates_total, const int prev_calculated, const int begin,
	const int period, const Array<double>& price, Array<double>& buffer);

//+------------------------------------------------------------------+
//|  Linear weighted moving average on price array                   |
//+------------------------------------------------------------------+
int LinearWeightedMAOnBuffer(const int rates_total, const int prev_calculated, const int begin,
	const int period, const Array<double>& price, Array<double>& buffer, int &weightsum);

//+------------------------------------------------------------------+
//|  Smoothed moving average on price array                          |
//+------------------------------------------------------------------+
int SmoothedMAOnBuffer(const int rates_total, const int prev_calculated, const int begin,
	const int period, const Array<double>& price, Array<double>& buffer);

//+------------------------------------------------------------------+

// WinAPI wrappers
//---- messages
int SendMessageA(int hWnd, int Msg, int wParam, int lParam);
int SendMessageW(int hWnd, int Msg, int wParam, int lParam);
int SendNotifyMessageA(int hWnd, int Msg, int wParam, int lParam);
int SendNotifyMessageW(int hWnd, int Msg, int wParam, int lParam);
int PostMessageA(int hWnd, int Msg, int wParam, int lParam);
int PostMessageW(int hWnd, int Msg, int wParam, int lParam);
//---- windows
int SetWindowTextA(int hWnd, Array<char>& lpString);
int SetWindowTextW(int hWnd, string lpString);
int GetWindowTextA(int hWnd, Array<char>& lpString, int nMaxCount);
int GetWindowTextW(int hWnd, string lpString, int nMaxCount);
int GetWindowTextLengthA(int hWnd);
int GetWindowTextLengthW(int hWnd);
int GetWindow(int hWnd, int uCmd);
int GetParent(int hWnd);

int UpdateWindow(int hWnd);
int EnableWindow(int hWnd, int bEnable);
int DestroyWindow(int hWnd);
int ShowWindow(int hWnd, int nCmdShow);
int SetActiveWindow(int hWnd);
int AnimateWindow(int hWnd, int dwTime, int dwFlags);
int FlashWindow(int hWnd, int dwFlags /*bInvert*/);
int CloseWindow(int hWnd);
int MoveWindow(int hWnd, int X, int Y, int nWidth, int nHeight, int bRepaint);
int SetWindowPos(int hWnd, int hWndInsertAfter, int X, int Y, int cx, int cy, int uFlags);
int IsWindowVisible(int hWnd);
int IsIconic(int hWnd);
int IsZoomed(int hWnd);
int SetFocus(int hWnd);
int IsWindowEnabled(int hWnd);
//---- miscelaneouse
int MessageBoxA(int hWnd, Array<char>& lpText, Array<char>& lpCaption, int uType);
int MessageBoxW(int hWnd, string lpText, string lpCaption, int uType);
int MessageBoxExA(int hWnd, Array<char>& lpText, Array<char>& lpCaption, int uType, int wLanguageId);
int MessageBoxExW(int hWnd, string lpText, string lpCaption, int uType, int wLanguageId);