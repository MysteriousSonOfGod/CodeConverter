#pragma once

//---------------------------------------------------------------------------
// Support library, additional useful functions
//
// Ver 1.0.1
//---------------------------------------------------------------------------
#ifdef __STRATEGY

#include "StrategyInterfaceUnit.h"

enum TPriceType {pt_Close, pt_Open, pt_High, pt_Low, pt_HL2, pt_HLC3, pt_HLCC4};
enum TMAType {ma_SMA, ma_EMA, ma_SSMA, ma_WMA};


double GetPrice(int index, TPriceType PriceType);
void LRCChannelParams(int Offset, int period, TPriceType PriceType,
  double& StartValue, double& EndValue, double&Height, double& Top, double& Bottom);

// close all opened positions (except pending orders)
void CloseAllOpenPos();

// delete all pending orders
void DeleteAllPendingOrders();

// close all open positions and delete all pending orders
void CloseAndDeleteAll();

// Get number of open positions
int GetNumberOfOpenPositions();

// Get number of pending orders
int GetNumberOfPendingOrders();

// Get profit for open positions
double GetOpenPosProfit();

// Convert price type to string
PChar StrPriceType(TPriceType ptype);

// Convert moving average type to string
PChar StrMAType(TMAType matype);

//-----Get price--------------------------------------------------------------
double GetPrice(int index, TPriceType PriceType);

// Get price by index and type on a specific time frame
// Symbol - requested currency
// TimeFrame - requested timeframe
// index - index in bar array
// PriceType - type of price or combination
double iGetPrice(PChar Symbol, int TimeFrame, int index, TPriceType PriceType);

//-----Get channel params-----------------------------------------------------
void LRCChannelParams(int Offset, int period, TPriceType PriceType,
	double& StartValue, double& EndValue, double& Height, double& Top, double& Bottom);


// Get moving average value
// index - index in bars array
// shift - shift value
// maType - moving average type (SMA, EMA, WMA)
// ApplyTo - price type
// prev - previous value for EMA
double GetMA(int index, int shift, int period, TMAType maType, TPriceType ApplyTo, double prev = 0);

/*
// Get moving average value based on a TIndexBuffer 
// priceBars - Source price bars for calculation
// index - index in bars array
// shift - shift value
// maType - moving average type (SMA, EMA, WMA)
// prev - previous value for MA
double GetMA(TIndexBuffer priceBars, int index, int shift, int period, TMAType maType, double prev = 0);
*/

// Get price by index and type on a specific time frame
// index - index in bar array
// PriceType - type of price or combination
// double iGetPrice(PChar Symbol, int TimeFrame, int index, TPriceType PriceType);
// Get moving average value
// Symbol - requested currency
// TimeFrame - requested timeframe
// index - index in bars array
// shift - shift value
// period - MA period
// maType - moving average type (SMA, EMA, WMA)
// ApplyTo - price type
// prev - previous value for MA
double iGetMA(PChar Symbol, int TimeFrame, int index,
	int shift, int period, TMAType maType,
	TPriceType ApplyTo, double prev = 0);

//-----Close all open positions-----------------------------------------------
void CloseAllOpenPos();

//-----Delete all pending orders----------------------------------------------
void DeleteAllPendingOrders();

//-----Close all open positions and delete all orders-------------------------
void CloseAndDeleteAll();

//-----Get number of open positions-------------------------------------------
int GetNumberOfOpenPositions();

//-----Get number of pending orders-------------------------------------------
int GetNumberOfPendingOrders();

//-----Get profit for open positions------------------------------------------
double GetOpenPosProfit();

//-----Convert price type to string-------------------------------------------
PChar StrPriceType(TPriceType ptype);

//-----Convert moving average type to string----------------------------------
PChar StrMAType(TMAType matype);

//-----Create "MA type" option-------------------------------------------------
void RegMATypeOption(int& option, PChar name);

//-----Create "Apply to price" option------------------------------------------
void RegApplyToPriceOption(int& option, PChar name);

#endif

#ifdef __INDICATOR

#include "IndicatorInterfaceUnit.h"

//---------------------------------------------------------------------------
// Technical functions v1.10 feb 2011
//---------------------------------------------------------------------------
//
// What's new:
// ver 1.10 (feb 2011 update by Wessel de Roode)
//
// 1. Added function iGetPrice(PChar Symbol, int TimeFrame, int index, TPriceType PriceType)
//    Get price by index and type on a specific time frame
// 2. Added function iGetMA(PChar Symbol, int TimeFrame, int index,int shift, int period, TMAType maType, TPriceType ApplyTo,double prev = 0)
//    Get price by index and type on a specific time frame
// 3. Added GetMA(TIndexBuffer priceBars, int index, int shift, int period, TMAType maType, double prev)
//    GetMA Implementation based on TIndexBuffer
// 4. Add GetATR(int index, TPriceType ApplyToPrice,  int atrPeriod, TIndexBuffer ATRTempBuffer)
//    Get Average True Range

#define MaxInt (int)(2147483647)

enum TPriceType { pt_Close, pt_Open, pt_High, pt_Low, pt_HL2, pt_HLC3, pt_HLCC4 };
enum TMAType { ma_SMA, ma_EMA, ma_SSMA, ma_WMA };
enum TValueType { vt_Open, vt_High, vt_Low, vt_Close, vt_Volume };


// Get Average True Range
// index - index in bars array
// ApplyTo - price type
// atrPeriod - period for ATR
// ATRTempBuffer - historic value's of ATR
double GetATR(int index, TPriceType ApplyToPrice, int atrPeriod, TIndexBuffer ATRTempBuffer);

// Get price by index and type
// index - index in bar array
// PriceType - type of price or combination
double GetPrice(int index, TPriceType PriceType);

// Get price by index and type on a specific time frame
// Symbol - requested currency
// TimeFrame - requested timeframe
// index - index in bar array
// PriceType - type of price or combination
double iGetPrice(PChar Symbol, int TimeFrame, int index, TPriceType PriceType);

// Register option "Apply to price" and fill array of its
// text values
void RegApplyToPriceOption(int& option, PChar name = "");

// Register option "MA type" and fill array of its text values
void RegMATypeOption(int& option, PChar name = "");

// Get linear regression channel parameters
// shift - shift value
// period - channel period
// PriceType - type of price
// StartValue - start price of center line
// EndValue - end price of center line
// Height - channel height
// top - channel top
// bottom - channel bottom
void LRCChannelParams(int shift, int period, TPriceType PriceType,
	double& StartValue, double& EndValue, double& Height, double& Top, double& Bottom);

// Get moving average value
// index - index in bars array
// shift - shift value
// maType - moving average type (SMA, EMA, WMA)
// ApplyTo - price type
// prev - previous value for EMA
double GetMA(int index, int shift, int period, TMAType maType, TPriceType ApplyTo, double prev = 0);

// Get moving average value based on a TIndexBuffer 
// priceBars - Source price bars for calculation
// index - index in bars array
// shift - shift value
// maType - moving average type (SMA, EMA, WMA)
// prev - previous value for MA
double GetMA(TIndexBuffer priceBars, int index, int shift, int period, TMAType maType, double prev = 0);

// Get price by index and type on a specific time frame
// index - index in bar array
// PriceType - type of price or combination
// double iGetPrice(PChar Symbol, int TimeFrame, int index, TPriceType PriceType);
// Get moving average value
// Symbol - requested currency
// TimeFrame - requested timeframe
// index - index in bars array
// shift - shift value
// period - MA period
// maType - moving average type (SMA, EMA, WMA)
// ApplyTo - price type
// prev - previous value for MA
double iGetMA(PChar Symbol, int TimeFrame, int index,
	int shift, int period, TMAType maType,
	TPriceType ApplyTo, double prev = 0);

// Get highest value in array
// ValueType - type of the value (vt_Open..vt_Volume)
// StartIndex - index from which we start search
// count - number of bars to search
double GetHighestValue(TValueType ValueType, int StartIndex, int count);

// Get lovest value in array
// ValueType - type of the value (vt_Open..vt_Volume)
// StartIndex - index from which we start search
// count - number of bars to search
double GetLowestValue(TValueType ValueType, int StartIndex, int count);

#endif // __INDICATOR

// Common functions

inline void NotImplementedMessage(const std::string& func_name)
{
#ifdef ENABLE_DEBUG_PRINTS
	Print(func_name + std::string(" function is not implemented!"));
#endif
}