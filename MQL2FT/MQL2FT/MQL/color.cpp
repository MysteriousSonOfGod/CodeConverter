#include "pch.h"

#include "color.h"

using namespace std;

color::color(byte red, byte green, byte blue)
{
	_value = (long)red | (long)green << 8 | (long)blue << 16;
}

ostream& operator<<(std::ostream& os, const color& clr)
{
#ifdef MQL2FT_STRICT_MODE
	os << (byte)clr._value << "," << byte(clr._value >> 8) << "," << byte(clr._value >> 16);
#else
	os << (long)clr;
#endif
	return os;
}
