#include "pch.h"

#include "MqlObjects.h"

// Helper classes
struct Text
{
	Text() = delete;
	Text(const std::string& n) : name(n), text("Text"), font_name("Arial"), font_size(12), font_color(clrRed), is_arrow(false) {};
	Text(const std::string& n, bool is_arr) : name(n), text("Text"), font_name("Arial"),
		font_size(12), font_color(clrRed), is_arrow(is_arr) {};
	
	std::string name;
	std::string text;
	std::string font_name;
	int font_size;
	long font_color;
	bool is_arrow;
};

// Global variables
std::list<Text> g_mql2ft_texts;

#ifdef __STRATEGY
std::vector<std::string> g_mql2ft_objects;
#endif

extern mql4::ENUM_TIMEFRAMES _Period;

// Helper functions declarations
std::string extAsciiToUtf8(unsigned char c);
Text& getText(const std::string& name);
bool checkObjectExistence(const std::string& name);
void PrintObjectTypeNotSupported(const mql4::string& type);
bool setParameter(const std::string& name, int newidx, double value);
TObjectType CastObjectType(ENUM_OBJECT o);
ENUM_OBJECT CastObjectTypeBack(TObjectType o);
int castPropIndxToFt(int i);

bool ObjectCreate(mqllong chart_id,	const mql4::string& object_name, ENUM_OBJECT object_type, int sub_window,
	datetime time1,	double price1,
	datetime time2,	double price2,
	datetime time3,	double price3)
{
	bool result = true;

	if(ft::ObjectExists(object_name) || object_name.empty())
	{
		return false;
	}

	switch(object_type)
	{
	case OBJ_TREND:
		result = ft::ObjectCreate(object_name, obj_Ray, 0, time1.ToDelphiTime(), price1, time2.ToDelphiTime(), price2);
		break;

	case OBJ_ARROW:
		result = ft::ObjectCreate(object_name, obj_Text, sub_window, time1.ToDelphiTime(), price1);

#ifdef __STRATEGY // Special case for strategies bug - ObjectCreate returns false, even if object was actually created
		result = ft::ObjectExists(object_name);
#endif

		if(result)
		{
			g_mql2ft_texts.push_front(Text(object_name, true));
#ifdef __STRATEGY
			g_mql2ft_objects.push_back(object_name);
#endif
		}
		
		result = result && ObjectSetString(0, object_name, OBJPROP_FONT, "Wingdings");
		result = result && ObjectSetString(0, object_name, OBJPROP_TEXT, extAsciiToUtf8(0xF1)); // 0XF1 - Hollow arrow up
		result = result && ObjectSetInteger(0, object_name, OBJPROP_ANCHOR, ANCHOR_TOP);
		break;

	case OBJ_TEXT:
	case OBJ_LABEL: // This is not a good idea and must be implemented in API
		result = ft::ObjectCreate(object_name, obj_Text, sub_window, time1.ToDelphiTime(), price1);

#ifdef __STRATEGY
		result = ft::ObjectExists(object_name);
#endif

		if(result)
		{
			g_mql2ft_texts.push_front(Text(object_name));
#ifdef __STRATEGY
			g_mql2ft_objects.push_back(object_name);
#endif
		}
		break;

	case OBJ_RECTANGLE:
	case OBJ_TRIANGLE:
	case OBJ_ELLIPSE:
		result = ft::ObjectCreate(object_name, CastObjectType(object_type), sub_window,
			time1.ToDelphiTime(), price1, time2.ToDelphiTime(), price2, time3.ToDelphiTime(), price3);

#ifdef __STRATEGY
		result = ft::ObjectExists(object_name);
#endif

		if(result)
		{
			ft::ObjectSet(object_name, ft::OBJPROP_FILLINSIDE, 1.0);
			ft::ObjectSet(object_name, ft::OBJPROP_COLOR, clrBlue);
			ft::ObjectSet(object_name, ft::OBJPROP_FILLCOLOR, clrBlue);
#ifdef __STRATEGY
			g_mql2ft_objects.push_back(object_name);
#endif
		}

		break;

	case OBJ_FIBO:
		result = ft::ObjectCreate(object_name, CastObjectType(object_type), sub_window,
			time1.ToDelphiTime(), price1, time2.ToDelphiTime(), price2);
		ft::ObjectSet(object_name, ft::OBJPROP_FIBOSHOWPRICE, 0.0);
		break;

	default:
		result = ft::ObjectCreate(object_name, CastObjectType(object_type), sub_window,
			time1.ToDelphiTime(), price1, time2.ToDelphiTime(), price2, time3.ToDelphiTime(), price3);

#ifdef __STRATEGY
		result = ft::ObjectExists(object_name);
		if(result)
		{
			g_mql2ft_objects.push_back(object_name);
		}
#endif
		break;
	}

	return result;
}

bool ObjectCreate(const mql4::string& object_name, ENUM_OBJECT object_type, int sub_window, datetime time1, double price1, datetime time2, double price2, datetime time3, double price3)
{
	return ObjectCreate(-1, object_name, object_type, sub_window, time1, price1, time2, price2, time3, price3);
}

int ObjectType(const mql4::string& object_name)
{
	if(!ft::ObjectExists(object_name))
	{
		return -1;
	}
	
	TObjectType t = ft::ObjectType(object_name);

	switch(t)
	{
	case obj_Ray:
	case obj_TrendLine:
		return (int)OBJ_TREND;
	case obj_Text:
		if(getText(object_name).is_arrow)
		{
			return (int)OBJ_ARROW;
		}
		else
		{
			return (int)OBJ_TEXT;
		}
	case obj_AnyObject:
		return -1;
	default:
		return (int)CastObjectTypeBack(t);
	}
}

bool ObjectSet(const mql4::string& object_name, int index, double value)
{
	if(!ft::ObjectExists(object_name))
	{
		return false;
	}
	
	const int ival = (int)value;

	switch(index)
	{
	case OBJPROP_RAY_RIGHT:
	case OBJPROP_RAY:
	{
		const bool val = (bool)value;
		const TObjectType objtype = ft::ObjectType(object_name);
		if(objtype == obj_Ray && !val)
		{
			double p1 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
			double p2 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
			double t1 = ft::ObjectGet(object_name, ft::OBJPROP_TIME1);
			double t2 = ft::ObjectGet(object_name, ft::OBJPROP_TIME2);

			double cl = ft::ObjectGet(object_name, ft::OBJPROP_COLOR);
			double st = ft::ObjectGet(object_name, ft::OBJPROP_STYLE);
			double wd = ft::ObjectGet(object_name, ft::OBJPROP_WIDTH);
			
			ft::ObjectDelete(object_name); // DHTODO: Extract window too, when FT API will allow creation of objects on diff windows
			bool res = ft::ObjectCreate(object_name, obj_TrendLine, 0, t1, p1, t2, p2);
			ft::ObjectSet(object_name, ft::OBJPROP_COLOR, cl);
			ft::ObjectSet(object_name, ft::OBJPROP_STYLE, st);
			ft::ObjectSet(object_name, ft::OBJPROP_WIDTH, wd);
			return res;
		}
		else if(objtype == obj_TrendLine && val)
		{
			double p1 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
			double p2 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
			double t1 = ft::ObjectGet(object_name, ft::OBJPROP_TIME1);
			double t2 = ft::ObjectGet(object_name, ft::OBJPROP_TIME2);

			double cl = ft::ObjectGet(object_name, ft::OBJPROP_COLOR);
			double st = ft::ObjectGet(object_name, ft::OBJPROP_STYLE);
			double wd = ft::ObjectGet(object_name, ft::OBJPROP_WIDTH);

			ft::ObjectDelete(object_name);
			bool res = ft::ObjectCreate(object_name, obj_Ray, 0, t1, p1, t2, p2);
			ft::ObjectSet(object_name, ft::OBJPROP_COLOR, cl);
			ft::ObjectSet(object_name, ft::OBJPROP_STYLE, st);
			ft::ObjectSet(object_name, ft::OBJPROP_WIDTH, wd);
			return res;
		}

		return false;
		break;
	}
	case OBJPROP_FONTSIZE:
	{
		Text& t = getText(object_name);
		t.font_size = ival;
		return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);
		break;
	}
	case OBJPROP_ARROWCODE:
		if(ival > 0xFF)
		{
			return false;
		}

		return ObjectSetString(0, object_name, OBJPROP_TEXT, extAsciiToUtf8((unsigned char)ival));
		break;

	case OBJPROP_COLOR:
	{
		const TObjectType objtype = ft::ObjectType(object_name);
		if(objtype == obj_Text)
		{
			Text& t = getText(object_name);
			t.font_color = ival;
			return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);
		}
		else
		{
			if(objtype == obj_Rectangle || objtype == obj_Triangle || objtype == obj_Ellipse)
			{
				if(ft::ObjectGet(object_name, ft::OBJPROP_FILLINSIDE) != 0.0)
				{
					ft::ObjectSet(object_name, ft::OBJPROP_FILLCOLOR, value);
					return ft::ObjectSet(object_name, ft::OBJPROP_COLOR, value);
				}
				else
				{
					return ft::ObjectSet(object_name, ft::OBJPROP_COLOR, value);
				}
			}
		}
		break;
	}
	case OBJPROP_WIDTH:
		if(ft::ObjectType(object_name) == obj_Text)
		{
			Text& t = getText(object_name);
			t.font_size = 12 + (ival - 1) * 4;
			return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);
		}
		break;
	case OBJPROP_BACK:
	{
		const TObjectType objtype = ft::ObjectType(object_name);

		if(objtype == obj_Rectangle || objtype == obj_Triangle || objtype == obj_Ellipse)
		{
			if(value != 0.0)
			{
				ft::ObjectSet(object_name, ft::OBJPROP_FILLINSIDE, 1.0);
				double col = ft::ObjectGet(object_name, ft::OBJPROP_COLOR);
				return ft::ObjectSet(object_name, ft::OBJPROP_FILLCOLOR, col);
			}
			else
			{
				ft::ObjectSet(object_name, ft::OBJPROP_FILLINSIDE, 0.0);
				return true;
			}
		}
		break;
	}
	case OBJPROP_ANCHOR:
		ObjectSetInteger(0, object_name, OBJPROP_ANCHOR, (mqllong)value);
		break;
	default:
		return setParameter(object_name, index, value);
	}

	return setParameter(object_name, index, value);
}

bool ObjectSetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, mqllong prop_value)
{
	// DHTODO: Add chart_id check when implemented in FT API

	switch(prop_id)
	{
	case OBJPROP_ANCHOR:
	{
		const Text& t = getText(object_name);

		if(t.is_arrow)
		{
			return ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, prop_value == ANCHOR_BOTTOM ? 2.0 : 0.0);
		}

		// VALIGNMENT: 0 - TOP, 1 - MID, 2 - BOT
		// HALIGNMENT: 0 - LEFT, 1 - RIGHT, 2 - MID

		switch(prop_value)
		{
		case ANCHOR_LEFT_UPPER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 0.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 0.0);
		case ANCHOR_LEFT:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 1.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 0.0);
		case ANCHOR_LEFT_LOWER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 2.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 0.0);
		case ANCHOR_LOWER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 2.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 2.0);
		case ANCHOR_RIGHT_LOWER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 2.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 1.0);
		case ANCHOR_RIGHT:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 1.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 1.0);
		case ANCHOR_RIGHT_UPPER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 0.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 1.0);
		case ANCHOR_UPPER:
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 0.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 2.0);
		default: // ANCHOR_CENTER
			ft::ObjectSet(object_name, ft::OBJPROP_VALIGNMENT, 1.0);
			return ft::ObjectSet(object_name, ft::OBJPROP_HALIGNMENT, 2.0);
		}
	}
	default:
		return ObjectSet(object_name, prop_id, (double)prop_value);
	}
}

bool ObjectSetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mqllong prop_value)
{
	// DHTODO: Add chart_id check when implemented in FT API

	switch(prop_id)
	{
	case OBJPROP_LEVELCOLOR:
	case OBJPROP_LEVELSTYLE:
	case OBJPROP_LEVELWIDTH:
	{
		bool result = false;
		for(int i = 0; i < 32; ++i) // Max 32 levels is possible in MT, set all to same style
		{
			result = ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, (double)i);
			result = ft::ObjectSet(object_name, castPropIndxToFt(prop_id), (double)prop_value);
		}

		return result;
	}

	case OBJPROP_TIME:
	{
		datetime tmp(prop_value);
		switch(prop_modifier)
		{
		case 0:
			return ft::ObjectSet(object_name, ft::OBJPROP_TIME1, tmp.ToDelphiTime());
			break;
		case 1:
			return ft::ObjectSet(object_name, ft::OBJPROP_TIME2, tmp.ToDelphiTime());
			break;
		case 2:
			return ft::ObjectSet(object_name, ft::OBJPROP_TIME3, tmp.ToDelphiTime());
			break;
		default:
			return false;
		}
		break;
	}
	default:
		return ObjectSetInteger(chart_id, object_name, prop_id, prop_value);
	}
}

bool ObjectSetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, double prop_value)
{
	// DHTODO: Add chart_id check when implemented in FT API

	return ObjectSet(object_name, prop_id, prop_value);
}

bool ObjectSetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, double prop_value)
{
	// DHTODO: Add chart_id check when implemented in FT API

	switch(prop_id)
	{
	case OBJPROP_LEVELVALUE:
		return setParameter(object_name, OBJPROP_FIRSTLEVEL + prop_modifier, prop_value);
		break;
	case OBJPROP_PRICE:
		switch(prop_modifier)
		{
		case 0:
			return ft::ObjectSet(object_name, ft::OBJPROP_PRICE1, prop_value);
			break;
		case 1:
			return ft::ObjectSet(object_name, ft::OBJPROP_PRICE2, prop_value);
			break;
		case 2:
			return ft::ObjectSet(object_name, ft::OBJPROP_PRICE3, prop_value);
			break;
		default:
			return false;
		}
		break;
	default:;
	}

	return ObjectSet(object_name, prop_id, prop_value);
}

bool ObjectSetString(mqllong chart_id, const mql4::string& object_name, int prop_id, const mql4::string& prop_value)
{
	// DHTODO: Add chart_id check when implemented in FT API

	if(!ft::ObjectExists(object_name))
	{
		return false;
	}

	Text& t = getText(object_name);

	switch(prop_id)
	{
	case OBJPROP_NAME:
#ifdef ENABLE_DEBUG_PRINTS
	{
		static bool printed = false;
		if(!printed)
		{
			Print("Forex Tester does not support object name change.");
			printed = true;
		}
	}
#endif
		return false;

	case OBJPROP_TEXT:
	{
		TObjectType ot = ft::ObjectType(object_name);
		if(ot != obj_Text && ot != obj_TextLabel)
		{
			return ft::ObjectSetText(object_name, prop_value);
		}

		t.text = prop_value;
		return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);
	}
	case OBJPROP_FONT:
		t.font_name = prop_value;
		return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);

	default:
		return ObjectSet(object_name, prop_id, 0.0);
	}
}

bool ObjectSetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, const mql4::string& prop_value)
{
	if(prop_id == OBJPROP_LEVELTEXT)
	{
		if(!ft::ObjectExists(object_name))
		{
			return false;
		}
		
		ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, (double)prop_modifier);
		return ft::ObjectSetText(object_name, prop_value);
	}
	
	return ObjectSetString(chart_id, object_name, prop_id, prop_value);
}

bool ObjectSetText(mql4::string object_name, mql4::string text, int font_size,
	mql4::string font_name, color text_color)
{
	TObjectType ot = ft::ObjectType(object_name);
	if(ot != obj_Text && ot != obj_TextLabel)
	{
		return ft::ObjectSetText(object_name, text, font_size, font_name, text_color);
	}
	
	Text& t = getText(object_name);
	t.text = text;
	if(font_size > 0)
	{
		t.font_size = font_size;
	}
	if(!font_name.empty())
	{
		t.font_name = font_name;
	}
	if(text_color != clrNONE)
	{
		t.font_color = text_color;
	}

	ft::ObjectSet(object_name, ft::OBJPROP_FONTSIZE, (double)t.font_size);
	return ft::ObjectSetText(object_name, t.text, t.font_size, t.font_name, t.font_color);
}

double ObjectGet(const mql4::string& object_name, int index)
{
	if(!ft::ObjectExists(object_name))
	{
		return 0.0;
	}
	
	switch(index)
	{
	case OBJPROP_WIDTH:
		if(ft::ObjectType(object_name) == obj_Text)
		{
			Text& t = getText(object_name);
			return (double)((t.font_size - 12)/4 + 1);
		}
		break;
	case OBJPROP_ANCHOR:
		return ObjectGet(object_name, ft::OBJPROP_VALIGNMENT);

	case OBJPROP_RAY_RIGHT:
	case OBJPROP_RAY:
	{
		const TObjectType objtype = ft::ObjectType(object_name);
		if(objtype == obj_Ray)
		{
			return 1.0;
		}
		else if(objtype == obj_TrendLine)
		{
			return 0.0;
		}
		
		return 0.0;
	}
	case OBJPROP_TIME1:
	case OBJPROP_TIME2:
	case OBJPROP_TIME3:
		return (double)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, castPropIndxToFt(index)));

	case OBJPROP_COLOR:
	{
		const TObjectType objtype = ft::ObjectType(object_name);
		if(objtype == obj_Text)
		{
			return (double)getText(object_name).font_color;
		}
		break;
	}

	case OBJPROP_LEVELVALUE:
		return ft::ObjectGet(object_name, castPropIndxToFt(index)) / 100.0;
		break;

	default:
		if(index >= OBJPROP_FIRSTLEVEL)
		{
			ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, OBJPROP_FIRSTLEVEL - index);
		}

		return ft::ObjectGet(object_name, castPropIndxToFt(index));
	}

	if(index >= OBJPROP_FIRSTLEVEL)
	{
		ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, OBJPROP_FIRSTLEVEL - index);
	}

	return ft::ObjectGet(object_name, castPropIndxToFt(index));
}

mqllong ObjectGetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier)
{
	// DHTODO: Add chart_id check when implemented in FT API

	if(prop_modifier < 0)
	{
		prop_modifier = 0;
	}

	switch(prop_id)
	{
	case OBJPROP_LEVELCOLOR:
	case OBJPROP_LEVELSTYLE:
	case OBJPROP_LEVELWIDTH:
		if(ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, prop_modifier))
		{
			return (mqllong)ft::ObjectGet(object_name, castPropIndxToFt(prop_id));
		}
		else
		{
			return 0;
		}

	case OBJPROP_TIME:
	{
		switch(prop_modifier)
		{
		case 0:
			return (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME1));
			break;
		case 1:
			return (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME2));
			break;
		case 2:
			return (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME3));
			break;
		default:
			return 0;
		}
		break;
	}

	default:
		return (mqllong)ObjectGet(object_name, prop_id);
	}
}

bool ObjectGetInteger(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mqllong& mqllong_var)
{
	// DHTODO: Add chart_id check when implemented in FT API

	if(prop_modifier < 0)
	{
		prop_modifier = 0;
	}

	switch(prop_id)
	{
	case OBJPROP_LEVELCOLOR:
	case OBJPROP_LEVELSTYLE:
	case OBJPROP_LEVELWIDTH:
		if(ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, prop_modifier))
		{
			mqllong_var = (mqllong)ft::ObjectGet(object_name, castPropIndxToFt(prop_id));
		}
		else
		{
			return false;
		}

	case OBJPROP_TIME:
	{
		switch(prop_modifier)
		{
		case 0:
			mqllong_var = (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME1));
			return true;
			break;
		case 1:
			mqllong_var = (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME2));
			return true;
			break;
		case 2:
			mqllong_var = (mqllong)(time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME3));
			return true;
			break;
		default:
			return false;
		}
		break;
	}

	default:
		mqllong_var = ObjectGet(object_name, prop_id);
		return true;
	}
}

double ObjectGetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier)
{
	// DHTODO: Add chart_id check when implemented in FT API

	switch(prop_id)
	{
	case OBJPROP_LEVELVALUE:
		if(ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, prop_modifier))
		{
			return ft::ObjectGet(object_name, OBJPROP_LEVELVALUE);
		}
		else
		{
			return 0.0;
		}
		break;
	case OBJPROP_PRICE:
		switch(prop_modifier)
		{
		case 0:
			return ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
			break;
		case 1:
			return ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
			break;
		case 2:
			return ft::ObjectGet(object_name, ft::OBJPROP_PRICE3);
			break;
		default:
			return 0.0;
		}
		break;
	default:;
	}

	return ObjectGet(object_name, prop_id);
}

bool ObjectGetDouble(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, double& double_var)
{
	// DHTODO: Add chart_id check when implemented in FT API

	switch(prop_id)
	{
	case OBJPROP_LEVELVALUE:
		if(ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, prop_modifier))
		{
			double_var = ft::ObjectGet(object_name, OBJPROP_LEVELVALUE);
			return true;
		}
		else
		{
			return false;
		}
		break;
	case OBJPROP_PRICE:
		switch(prop_modifier)
		{
		case 0:
			double_var = ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
			return true;
			break;
		case 1:
			double_var = ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
			return true;
			break;
		case 2:
			double_var = ft::ObjectGet(object_name, ft::OBJPROP_PRICE3);
			return true;
			break;
		default:
			return false;
		}
		break;
	default:;
	}

	double_var = ObjectGet(object_name, prop_id);
	return true;
}

mql4::string ObjectGetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier)
{
	// DHTODO: Add chart_id check when implemented in FT API

	if(!ft::ObjectExists(object_name))
	{
		return mql4::string();
	}

	if(prop_id == OBJPROP_LEVELTEXT)
	{
		ft::ObjectSet(object_name, ft::OBJPROP_FIBOLEVELN, (double)prop_modifier);
		return ObjectGetText(object_name);
	}

	Text& t = getText(object_name);

	switch(prop_id)
	{
	case OBJPROP_NAME:
		return t.name;

	case OBJPROP_TEXT:
		return t.text;

	case OBJPROP_FONT:
		return t.font_name;

	default:
		return mql4::string();
	}
}

bool ObjectGetString(mqllong chart_id, const mql4::string& object_name, int prop_id, int prop_modifier, mql4::string& string_var)
{
	// DHTODO: Add chart_id check when implemented in FT API

	if(!ft::ObjectExists(object_name))
	{
		return false;
	}

	Text& t = getText(object_name);

	switch(prop_id)
	{
	case OBJPROP_NAME:
		string_var = t.name;
		return true;

	case OBJPROP_TEXT:
		string_var = t.text;
		return true;

	case OBJPROP_FONT:
		string_var = t.font_name;
		return true;

	default:
		return false;
	}
}

// There is exactly 0.0291 dollars difference between MT and FT (EURUSD, 15). Reason: Possibly datetime convertion bug. Mb fixed.
double ObjectGetValueByShift(const mql4::string& object_name, int shift)
{
	const TObjectType objtype = ft::ObjectType(object_name);
	if(objtype != obj_TrendLine && objtype != obj_Ray)
	{
		return 0.0;
	}

	const double t0 = ft::ObjectGet(object_name, ft::OBJPROP_TIME1);

	const double y1 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
	const double y2 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
	double x1 = double((time_t)datetime::FromVariantTime(t0));
	double x2 = double((time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME2)));

	const int tf = _Period;
	int total_shift;

	if(t0 > ft::Time(0))
	{
		total_shift = int(double(((time_t)datetime::FromVariantTime(ft::Time(0))) - x1)/(tf * 60));
	}
	else
	{
		total_shift = ft::iBarShift(_Symbol, tf, t0, false);
	}

	x2 -= x1;
	x1 = 0.0;

	const double x = double((total_shift - shift) * tf * 60);
	const bool ray_left = x2 < x1;

	if((x > x1 && ray_left) || (x < x1 && !ray_left))
	{
		return 0.0;
	}

	const double m = (y2 - y1)/(x2 - x1);
	const double b = y1 - m * x1;

	return m * x + b;
}

// There is exactly 97 bars difference between MT and FT. Reason: Possibly datetime convertion bug. Mb fixed.
int ObjectGetShiftByValue(const mql4::string& object_name, double value)
{
	const TObjectType objtype = ft::ObjectType(object_name);
	if(objtype != obj_TrendLine && objtype != obj_Ray)
	{
		return 0.0;
	}

	const double t0 = ft::ObjectGet(object_name, ft::OBJPROP_TIME1);

	const double y1 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE1);
	const double y2 = ft::ObjectGet(object_name, ft::OBJPROP_PRICE2);
	double x1 = double((time_t)datetime::FromVariantTime(t0));
	double x2 = double((time_t)datetime::FromVariantTime(ft::ObjectGet(object_name, ft::OBJPROP_TIME2)));

	const int tf = _Period;
	int total_shift;

	if(t0 > ft::Time(0))
	{
		total_shift = int(double(((time_t)datetime::FromVariantTime(ft::Time(0))) - x1)/(tf * 60));
	}
	else
	{
		total_shift = ft::iBarShift(_Symbol, tf, t0, false);
	}

	x2 -= x1;
	x1 = 0.0;

	const double m = (y2 - y1)/(x2 - x1);
	const double b = y1 - m * x1;

	const time_t nix_time = (time_t)round((value - b)/m);

	datetime time_cur = datetime::FromVariantTime(ft::Time(0));
	const time_t time_dif = time_t(total_shift * tf * 60) - nix_time;

	return (int)round((double)time_dif/((double)tf*60.0));
}

bool ObjectMove(mqllong chart_id, const mql4::string& object_name, int point_index, datetime time, double price)
{
	// DHTODO: Add chart_id check when implemented in FT API

	int price_num, time_num;

	switch(point_index)
	{
	case 0:
		price_num = ft::OBJPROP_PRICE1, time_num = ft::OBJPROP_TIME1;
		break;
	case 1:
		price_num = ft::OBJPROP_PRICE2, time_num = ft::OBJPROP_TIME2;
		break;
	case 2:
		price_num = ft::OBJPROP_PRICE3, time_num = ft::OBJPROP_TIME3;
		break;
	default:
		return false;
	}

	const bool r1 = ft::ObjectSet(object_name, time_num, time.ToDelphiTime());
	const bool r2 = ft::ObjectSet(object_name, price_num, price);

	return r1 && r2;
}

bool ObjectMove(const mql4::string& object_name, int point_index, datetime time, double price)
{
	return ObjectMove(0, object_name, point_index, time, price);
}

mql4::string ObjectGetFiboDescription(const mql4::string& object_name, int index)
{
#ifdef ENABLE_DEBUG_PRINTS
	static bool printed = false;
	if(!printed)
	{
		Print("Forex Tester does not support separate text for all Fibonacci levels.");
		printed = true;
	}
#endif
	return ObjectGetString(0, object_name, OBJPROP_TEXT);
}

mql4::string ObjectDescription(const mql4::string& object_name)
{
	return ObjectGetString(0, object_name, OBJPROP_TEXT);
}

int ObjectFind(mqllong chart_id, const mql4::string& object_name)
{
	// DHTODO: Need to add API function when adding objects to different charts will be implemented
	
	if(!ft::ObjectExists(object_name))
	{
		return -1;
	}
	
	return 0;
}

int ObjectFind(const mql4::string& object_name)
{
	return ObjectFind(-1, object_name);
}

#ifdef __STRATEGY
mql4::string ObjectName(int object_index)
{
	const int objs = g_mql2ft_objects.size();
	if(object_index >= objs && object_index < 0)
	{
		SetLastError(ERR_OBJECT_DOES_NOT_EXIST);
		return "";
	}
	
	mql4::string n;
	if(object_index < g_mql2ft_objects.size())
	{
		n = g_mql2ft_objects[object_index];
	}
	else
	{
		SetLastError(ERR_OBJECT_DOES_NOT_EXIST);
		return "";
	}

	if(!checkObjectExistence(n))
	{
		SetLastError(ERR_OBJECT_DOES_NOT_EXIST);
		return "";
	}

	return n;
}
#else
mql4::string ObjectName(int object_index)
{
	return ft::ObjectName(object_index);
}
#endif

#ifdef __STRATEGY
int ObjectsTotal(int type)
{
	int objs = g_mql2ft_objects.size();

	for(int i = 0; i < objs; ++i) // Check if any of stored objecs got deleted manually or programmatically
	{
		checkObjectExistence(g_mql2ft_objects[i]); // WARNING: Potentially huge overhead, may cause significant slowdown
	}

	objs = g_mql2ft_objects.size();

	if(type < 0)
	{
		return objs;
	}
	else
	{
		int count = 0;
		const TObjectType ot = CastObjectType((ENUM_OBJECT)type);
		for(int i = 0; i < objs; ++i)
		{
			if(ft::ObjectType(g_mql2ft_objects[i]) == ot)
			{
				++count;
			}
		}

		return count;
	}
}
#else
int ObjectsTotal(int type)
{
	if(type < 0)
	{
		return ft::ObjectsTotal();
	}
	else
	{
		const int total = ft::ObjectsTotal();
		int count = 0;
		const TObjectType ot = CastObjectType((ENUM_OBJECT)type);
		for(int i = 0; i < total; ++i)
		{
			if(ft::ObjectType(ft::ObjectName(i)) == ot)
			{
				++count;
			}
		}

		return count;
	}
}
#endif

int ObjectsTotal(mqllong chart_id, int sub_window, int type)
{
	// DHTODO: modify this function when adding objects to different charts will be implemented
	
	return ObjectsTotal(type);
}

bool ObjectDelete(const mql4::string& object_name)
{
	ft::ObjectDelete(object_name);

	if(!checkObjectExistence(object_name))
	{
		return true;
	}
	else
	{
#ifdef ENABLE_DEBUG_PRINTS
		Print("Cannot delete the object \"" + object_name + "\"");
#endif
		return false;
	}
}

int ObjectsDeleteAll(mqllong chart_id, const mql4::string& prefix, int sub_window, int object_type)
{
	// DHTODO: modify this function when deleting objects from different charts will be implemented
	
	int count = 0;
	
	if(prefix.empty())
	{
		count = ObjectsTotal(object_type);  // Objects total will update deleted objects
		ft::ObjectsDeleteAll(0, CastObjectType((ENUM_OBJECT)object_type));

		for(std::list<Text>::iterator it = g_mql2ft_texts.begin(); it != g_mql2ft_texts.end(); ++it)
		{
			// Check if any of stored objecs got deleted manually or programmatically
			checkObjectExistence(it->name); // WARNING: Potentially huge overhead, may cause significant slowdown
		}
	}
	else
	{
#ifdef __STRATEGY
		const int total = ObjectsTotal();

		if(object_type < 0)
		{
			for(int i = 0; i < total; ++i)
			{
				std::string n = g_mql2ft_objects[i];

				if(n.find(prefix.c_str(), 0, prefix.size()) != std::string::npos)
				{
					ft::ObjectDelete(n);
					checkObjectExistence(n);
					++count;
				}
			}
		}
		else
		{
			const TObjectType ot = CastObjectType((ENUM_OBJECT)object_type);
			for(int i = 0; i < total; ++i)
			{
				std::string n = g_mql2ft_objects[i];

				if(ft::ObjectType(n) == ot && n.find(prefix.c_str(), 0, prefix.size()) != std::string::npos)
				{
					ft::ObjectDelete(n);
					checkObjectExistence(n);
					++count;
				}
			}
		}
#else		
		const int total = ft::ObjectsTotal();

		if(object_type < 0)
		{
			for(int i = 0; i < total; ++i)
			{
				std::string n = ft::ObjectName(i);

				if(n.find(prefix.c_str(), 0, prefix.size()) != std::string::npos)
				{
					ft::ObjectDelete(n);
					checkObjectExistence(n);
					++count;
				}
			}
		}
		else
		{
			const TObjectType ot = CastObjectType((ENUM_OBJECT)object_type);
			for(int i = 0; i < total; ++i)
			{
				std::string n = ft::ObjectName(i);

				if(ft::ObjectType(n) == ot && n.find(prefix.c_str(), 0, prefix.size()) != std::string::npos)
				{
					ft::ObjectDelete(n);
					checkObjectExistence(n);
					++count;
				}
			}
		}
#endif
	}

	return count;
}

int ObjectsDeleteAll(mqllong chart_id, int sub_window, int object_type)
{
	return ObjectsDeleteAll(chart_id, "", sub_window, object_type);
}

int ObjectsDeleteAll(int sub_window, int object_type)
{
	return ObjectsDeleteAll(-1, sub_window, object_type);
}

// Helper functions definitions
std::string extAsciiToUtf8(unsigned char c)
{
	if(c < 127)
	{
		std::string tmp = "0";
		tmp[0] = c;
		return tmp;
	}

	const unsigned char b1 = 0xC0;
	const unsigned char b2 = 0x80;

	std::string out = "00";
	out[1] = b2 | (c & 0x3F);
	out[0] = b1 | ((c & b1) >> 6);

	return out;
}

Text& getText(const std::string& name)
{

	for(std::list<Text>::iterator it = g_mql2ft_texts.begin(); it != g_mql2ft_texts.end(); ++it)
	{
		if(it->name == name)
		{
			return *it;
		}
	}

	static Text empty_text("mql2ft_text_not_found");
	return empty_text;
}

bool checkObjectExistence(const std::string& name)
{
	bool result = true;
	result = ft::ObjectExists(name);

	if(!result)
	{
#ifdef __STRATEGY
		for(std::vector<std::string>::iterator it = g_mql2ft_objects.begin(); it != g_mql2ft_objects.end(); ++it)
		{
			if(*it == name)
			{
				g_mql2ft_objects.erase(it);
				break;
			}
		}
#endif
		for(std::list<Text>::iterator it = g_mql2ft_texts.begin(); it != g_mql2ft_texts.end(); ++it)
		{
			if(it->name == name)
			{
				g_mql2ft_texts.erase(it);
				break;
			}
		}

	}

	return result;
}

void PrintObjectTypeNotSupported(const mql4::string& type) // DHTODO: MAKE IT ONLY ONE TIME PRINT
{
#ifdef ENABLE_DEBUG_PRINTS
	static std::list<std::string> printed_types;
	if(std::find(printed_types.begin(), printed_types.end(), type) == printed_types.end())
	{
		Print("Cannot create object of " + type + " type, it is not supported in Forex Tester");
		printed_types.push_back(type);
	}
#endif
}

bool setParameter(const std::string& name, int newidx, double value)
{
	if(newidx >= OBJPROP_FIRSTLEVEL)
	{
		if(ft::ObjectSet(name, ft::OBJPROP_FIBOLEVELN, newidx - (int)OBJPROP_FIRSTLEVEL))
		{
			return ft::ObjectSet(name, ft::OBJPROP_LEVELVALUE, value * 100.0);
		}
		else
		{
			return false;
		}
	}
	else
	{
		newidx = castPropIndxToFt(newidx);

		if(newidx < 0)
		{
			return false;
		}

		if(newidx == ft::OBJPROP_TIME1 || newidx == ft::OBJPROP_TIME2 || newidx == ft::OBJPROP_TIME3)
		{
			datetime tmp((time_t)value);
			return ft::ObjectSet(name, newidx, tmp.ToDelphiTime());
		}
		else
		{
			return ft::ObjectSet(name, newidx, value);
		}
	}
}

TObjectType CastObjectType(ENUM_OBJECT o)
{
	switch(o)
	{
	case OBJ_VLINE:
		return obj_VLine;
	case OBJ_HLINE:
		return obj_HLine;
	case OBJ_TREND:
		return obj_TrendLine;

	case OBJ_FIBO:
		return obj_FiboRetracement;
	case OBJ_FIBOTIMES:
		return obj_FiboTimeZones;
	case OBJ_FIBOARC:
		return obj_FiboArc;
	case OBJ_FIBOFAN:
		return obj_FiboFan;
	case OBJ_TEXT:
	case OBJ_LABEL: // This is not a good idea and must be implemented in API
		return obj_Text;
	case OBJ_RECTANGLE:
		return obj_Rectangle;
	case OBJ_TRIANGLE:
		return obj_Triangle;
	case OBJ_ELLIPSE:
		return obj_Ellipse;

	case OBJ_FIBOCHANNEL:
		PrintObjectTypeNotSupported("OBJ_FIBOCHANNEL");
		return obj_FiboChannel;
	case OBJ_PITCHFORK:
		PrintObjectTypeNotSupported("OBJ_PITCHFORK");
		return obj_AndrewsPitchfork;
	case OBJ_TRENDBYANGLE:
		PrintObjectTypeNotSupported("OBJ_TRENDBYANGLE");
		return obj_AnyObject;
	case OBJ_CYCLES:
		PrintObjectTypeNotSupported("OBJ_CYCLES");
		return obj_AnyObject;
	case OBJ_CHANNEL:
		PrintObjectTypeNotSupported("OBJ_CHANNEL");
		return obj_AnyObject;
	case OBJ_STDDEVCHANNEL:
		PrintObjectTypeNotSupported("OBJ_STDDEVCHANNEL");
		return obj_AnyObject;
	case OBJ_REGRESSION:
		PrintObjectTypeNotSupported("OBJ_REGRESSION");
		return obj_AnyObject;
	case OBJ_GANNLINE:
		PrintObjectTypeNotSupported("OBJ_GANNLINE");
		return obj_AnyObject;
	case OBJ_GANNFAN:
		PrintObjectTypeNotSupported("OBJ_GANNFAN");
		return obj_AnyObject;
	case OBJ_GANNGRID:
		PrintObjectTypeNotSupported("OBJ_GANNGRID");
		return obj_AnyObject;
	case OBJ_EXPANSION:
		PrintObjectTypeNotSupported("OBJ_EXPANSION");
		return obj_AnyObject;
	case OBJ_ARROW_THUMB_UP:
		PrintObjectTypeNotSupported("OBJ_ARROW_THUMB_UP");
		return obj_AnyObject;
	case OBJ_ARROW_THUMB_DOWN:
		PrintObjectTypeNotSupported("OBJ_ARROW_THUMB_DOWN");
		return obj_AnyObject;
	case OBJ_ARROW_UP:
		PrintObjectTypeNotSupported("OBJ_ARROW_UP");
		return obj_AnyObject;
	case OBJ_ARROW_DOWN:
		PrintObjectTypeNotSupported("OBJ_ARROW_DOWN");
		return obj_AnyObject;
	case OBJ_ARROW_STOP:
		PrintObjectTypeNotSupported("OBJ_ARROW_STOP");
		return obj_AnyObject;
	case OBJ_ARROW_CHECK:
		PrintObjectTypeNotSupported("OBJ_ARROW_CHECK");
		return obj_AnyObject;
	case OBJ_ARROW_LEFT_PRICE:
		PrintObjectTypeNotSupported("OBJ_ARROW_LEFT_PRICE");
		return obj_AnyObject;
	case OBJ_ARROW_RIGHT_PRICE:
		PrintObjectTypeNotSupported("OBJ_ARROW_RIGHT_PRICE");
		return obj_AnyObject;
	case OBJ_ARROW_BUY:
		PrintObjectTypeNotSupported("OBJ_ARROW_BUY");
		return obj_AnyObject;
	case OBJ_ARROW_SELL:
		PrintObjectTypeNotSupported("OBJ_ARROW_SELL");
		return obj_AnyObject;
	case OBJ_BUTTON:
		PrintObjectTypeNotSupported("OBJ_BUTTON");
		return obj_AnyObject;
	case OBJ_BITMAP_LABEL:
		PrintObjectTypeNotSupported("OBJ_BITMAP_LABEL");
		return obj_AnyObject;
	case OBJ_EDIT:
		PrintObjectTypeNotSupported("OBJ_EDIT");
		return obj_AnyObject;
	case OBJ_EVENT:
		PrintObjectTypeNotSupported("OBJ_EVENT");
		return obj_AnyObject;
	case OBJ_RECTANGLE_LABEL:
		PrintObjectTypeNotSupported("OBJ_RECTANGLE_LABEL");
		return obj_AnyObject;

	default:
		return obj_AnyObject;
	}
}

ENUM_OBJECT CastObjectTypeBack(TObjectType o)
{
	switch(o)
	{
	case obj_VLine:
		return OBJ_VLINE;
	case obj_HLine:
		return OBJ_HLINE;
	case obj_Ray:
	case obj_TrendLine:
		return OBJ_TREND;

	case obj_FiboRetracement:
		return OBJ_FIBO;
	case obj_FiboTimeZones:
		return OBJ_FIBOTIMES;
	case obj_FiboArc:
		return OBJ_FIBOARC;
	case obj_FiboFan:
		return OBJ_FIBOFAN;
	case obj_Text:
		return OBJ_LABEL;
	case obj_Rectangle:
		return OBJ_RECTANGLE;
	case obj_Triangle:
		return OBJ_TRIANGLE;
	case obj_Ellipse:
		return OBJ_ELLIPSE;
	case obj_TextLabel:
		return OBJ_LABEL;

	default:
		return (ENUM_OBJECT)o;
	}
}

int castPropIndxToFt(int i)
{
	switch(i)
	{
	case OBJPROP_LEVELS:
		return ft::OBJPROP_FIBOLEVELS;
	case OBJPROP_TIME1:
		return ft::OBJPROP_TIME1;
	case OBJPROP_PRICE1:
		return ft::OBJPROP_PRICE1;
	case OBJPROP_TIME2:
		return ft::OBJPROP_TIME2;
	case OBJPROP_PRICE2:
		return ft::OBJPROP_PRICE2;
	case OBJPROP_TIME3:
		return ft::OBJPROP_TIME3;
	case OBJPROP_PRICE3:
		return ft::OBJPROP_PRICE3;
	case OBJPROP_COLOR:
		return ft::OBJPROP_COLOR;
	case OBJPROP_STYLE:
		return ft::OBJPROP_STYLE;
	case OBJPROP_WIDTH:
		return ft::OBJPROP_WIDTH;
	case OBJPROP_ELLIPSE:
		return ft::OBJPROP_ELLIPSE;
	case OBJPROP_LEVELCOLOR:
		return ft::OBJPROP_LEVELCOLOR;
	case OBJPROP_LEVELSTYLE:
		return ft::OBJPROP_LEVELSTYLE;
	case OBJPROP_LEVELWIDTH:
		return ft::OBJPROP_LEVELWIDTH;
	case OBJPROP_LEVELVALUE:
		return ft::OBJPROP_LEVELVALUE;
	case OBJPROP_FONTSIZE:
		return ft::OBJPROP_FONTSIZE;
	case OBJPROP_XDISTANCE:
		return ft::OBJPROP_XDISTANCE;
	case OBJPROP_YDISTANCE:
		return ft::OBJPROP_YDISTANCE;
	case OBJPROP_TEXT:
		return ft::OBJPROP_TEXT;
	case OBJPROP_NAME:
		return ft::OBJPROP_NAME;
	default:
		return -1;
	}
}