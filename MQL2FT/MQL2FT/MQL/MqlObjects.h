#pragma once

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#else
#include "StrategyInterfaceUnit.h"
#endif
#include "MqlString.h"
#include "datetime.h"
#include "Enums.h"
#include "MqlEnums.h"

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulong;
typedef unsigned char uchar;
typedef long long mqllong;

constexpr const int MQL2FT_EMPTY = -1;

bool ObjectCreate(mqllong chart_id, const mql4::string& object_name, ENUM_OBJECT object_type, int sub_window,    
	datetime time1,       double price1,        
	datetime time2 = 0ul, double price2 = 0,
	datetime timeN = 0ul, double priceN = 0);

bool ObjectCreate(const mql4::string& object_name, ENUM_OBJECT object_type, int sub_window,
	datetime time1, double price1,        
	datetime time2 = 0ul, double price2 = 0,      
	datetime time3 = 0ul, double price3 = 0ul);

int ObjectType(const mql4::string& object_name);

bool ObjectSet(const mql4::string& object_name,	int index, double value);

bool ObjectSetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, mqllong prop_value);
bool ObjectSetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mqllong prop_value);
bool ObjectSetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, double prop_value);
bool ObjectSetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, double prop_value);
bool ObjectSetString(mqllong chart_id, const mql4::string& object_name, int prop_id, const mql4::string& prop_value);
bool ObjectSetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, const mql4::string& prop_value);

bool ObjectSetText(mql4::string object_name, mql4::string text, int font_size = 0,
	mql4::string font_name = "", color text_color = clrNONE);

double ObjectGet(const mql4::string& object_name, int index);

mqllong ObjectGetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier = 0);
bool ObjectGetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mqllong& mqllong_var);
double ObjectGetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier = 0);
bool ObjectGetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, double& mqllong_var);
mql4::string ObjectGetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier = 0);
bool ObjectGetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mql4::string& mqllong_var);

double ObjectGetValueByShift(const mql4::string& object_name, int shift);
int ObjectGetShiftByValue(const mql4::string& object_name, double value);

bool ObjectMove(mqllong chart_id, const mql4::string& object_name, int point_index, datetime time, double price);
bool ObjectMove(const mql4::string& object_name, int point_index, datetime time, double price);

mql4::string ObjectGetFiboDescription(const mql4::string& object_name, int index);
mql4::string ObjectDescription(const mql4::string& object_name);

int ObjectFind(mqllong chart_id, const mql4::string& object_name);
int ObjectFind(const mql4::string& object_name);

mql4::string ObjectName(int object_index);

inline mql4::string ObjectName(int chart_id, int object_index) { return ObjectName(object_index); }

int ObjectsTotal(int type = MQL2FT_EMPTY);
int ObjectsTotal(mqllong chart_id, int sub_window = MQL2FT_EMPTY, int type = MQL2FT_EMPTY);

bool ObjectDelete(const mql4::string& object_name);
inline bool ObjectDelete(mqllong chart_id, const mql4::string& object_name) { return ObjectDelete(object_name); }

int ObjectsDeleteAll(mqllong chart_id, const mql4::string& prefix = "", int sub_window = MQL2FT_EMPTY, int object_type = MQL2FT_EMPTY);
int ObjectsDeleteAll(mqllong chart_id, int sub_window = MQL2FT_EMPTY, int object_type = MQL2FT_EMPTY);
int ObjectsDeleteAll(int sub_window = MQL2FT_EMPTY, int object_type = MQL2FT_EMPTY);