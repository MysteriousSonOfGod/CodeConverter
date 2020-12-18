#pragma once

typedef unsigned char byte;

class color
{
public:
	color() = default;
	color(long value) : _value{value} {}
	color(byte red, byte green, byte blue);

	friend std::ostream& operator<<(std::ostream& os, const color& clr);

	operator long() const { return _value; }
	long* operator&() { return &_value; }

private:
	long _value;
};

inline bool operator==(const color& lhs, const color& rhs) { return (long)lhs == (long)rhs; }
inline bool operator!=(const color& lhs, const color& rhs) { return (long)lhs != (long)rhs; }
inline bool operator<(const color& lhs, const color& rhs) { return (long)lhs < (long)rhs; }
inline bool operator>(const color& lhs, const color& rhs) { return (long)lhs > (long)rhs; }
inline bool operator<=(const color& lhs, const color& rhs) { return (long)lhs <= (long)rhs; }
inline bool operator>=(const color& lhs, const color& rhs) { return (long)lhs >= (long)rhs; }

inline bool operator==(const color& lhs, long rhs) { return (long)lhs == rhs; }
inline bool operator!=(const color& lhs, long rhs) { return (long)lhs != rhs; }
inline bool operator<(const color& lhs, long rhs) { return (long)lhs < rhs; }
inline bool operator>(const color& lhs, long rhs) { return (long)lhs > rhs; }
inline bool operator<=(const color& lhs, long rhs) { return (long)lhs <= rhs; }
inline bool operator>=(const color& lhs, long rhs) { return (long)lhs >= rhs; }

inline bool operator==(long lhs, const color& rhs) { return lhs == (long)rhs; }
inline bool operator!=(long lhs, const color& rhs) { return lhs != (long)rhs; }
inline bool operator<(long lhs, const color& rhs) { return lhs < (long)rhs; }
inline bool operator>(long lhs, const color& rhs) { return lhs > (long)rhs; }
inline bool operator<=(long lhs, const color& rhs) { return lhs <= (long)rhs; }
inline bool operator>=(long lhs, const color& rhs) { return lhs >= (long)rhs; }

constexpr const long	clrEMPTY				= 0x1FFFFFFF;
constexpr const long	clrNONE					= 0x1FFFFFFF;
constexpr const long	CLR_NONE				= 0x1FFFFFFF;
constexpr const long	clrCLR_NONE				= 0x1FFFFFFF;
constexpr const long	AliceBlue				= 0xFFF8F0;
constexpr const long	clrAliceBlue			= 0xFFF8F0;
constexpr const long	AntiqueWhite			= 0xD7EBFA;
constexpr const long	clrAntiqueWhite			= 0xD7EBFA;
constexpr const long	Aqua					= 0xFFFF00;
constexpr const long	clrAqua					= 0xFFFF00;
constexpr const long	Aquamarine				= 0xD4FF7F;
constexpr const long	clrAquamarine			= 0xD4FF7F;
constexpr const long	Azure					= 0xFFFFF0;
constexpr const long	clrAzure				= 0xFFFFF0;
constexpr const long	Beige					= 0xDCF5F5;
constexpr const long	clrBeige				= 0xDCF5F5;
constexpr const long	Bisque					= 0xC4E4FF;
constexpr const long	clrBisque				= 0xC4E4FF;
constexpr const long	Black					= 0x000000;
constexpr const long	clrBlack				= 0x000000;
constexpr const long	BlanchedAlmond			= 0xCDEBFF;
constexpr const long	clrBlanchedAlmond		= 0xCDEBFF;
constexpr const long	Blue					= 0xFF0000;
constexpr const long	clrBlue					= 0xFF0000;
constexpr const long	BlueViolet				= 0xE22B8A;
constexpr const long	clrBlueViolet			= 0xE22B8A;
constexpr const long	Brown					= 0x2A2AA5;
constexpr const long	clrBrown				= 0x2A2AA5;
constexpr const long	BurlyWood				= 0x87B8DE;
constexpr const long	clrBurlyWood			= 0x87B8DE;
constexpr const long	CadetBlue				= 0xA09E5F;
constexpr const long	clrCadetBlue			= 0xA09E5F;
constexpr const long	Chartreuse				= 0x00FF7F;
constexpr const long	clrChartreuse			= 0x00FF7F;
constexpr const long	Chocolate				= 0x1E69D2;
constexpr const long	clrChocolate			= 0x1E69D2;
constexpr const long	Coral					= 0x507FFF;
constexpr const long	clrCoral				= 0x507FFF;
constexpr const long	CornflowerBlue			= 0xED9564;
constexpr const long	clrCornflowerBlue		= 0xED9564;
constexpr const long	Cornsilk				= 0xDCF8FF;
constexpr const long	clrCornsilk				= 0xDCF8FF;
constexpr const long	Crimson					= 0x3C14DC;
constexpr const long	clrCrimson				= 0x3C14DC;
constexpr const long	Cyan					= 0xFFFF00;
constexpr const long	clrCyan					= 0xFFFF00;
constexpr const long	DarkBlue				= 0x8B0000;
constexpr const long	clrDarkBlue				= 0x8B0000;
constexpr const long	DarkCyan				= 0x8B8B00;
constexpr const long	clrDarkCyan				= 0x8B8B00;
constexpr const long	DarkGoldenrod			= 0x0B86B8;
constexpr const long	clrDarkGoldenrod		= 0x0B86B8;
constexpr const long	DarkGray				= 0xA9A9A9;
constexpr const long	clrDarkGray				= 0xA9A9A9;
constexpr const long	DarkGreen				= 0x006400;
constexpr const long	clrDarkGreen			= 0x006400;
constexpr const long	DarkKhaki				= 0x6BB7BD;
constexpr const long	clrDarkKhaki			= 0x6BB7BD;
constexpr const long	DarkMagenta				= 0x8B008B;
constexpr const long	clrDarkMagenta			= 0x8B008B;
constexpr const long	DarkOliveGreen			= 0x2F6B55;
constexpr const long	clrDarkOliveGreen		= 0x2F6B55;
constexpr const long	DarkOrange				= 0x008CFF;
constexpr const long	clrDarkOrange			= 0x008CFF;
constexpr const long	DarkOrchid				= 0xCC3299;
constexpr const long	clrDarkOrchid			= 0xCC3299;
constexpr const long	DarkRed					= 0x00008B;
constexpr const long	clrDarkRed				= 0x00008B;
constexpr const long	DarkSalmon				= 0x7A96E9;
constexpr const long	clrDarkSalmon			= 0x7A96E9;
constexpr const long	DarkSeaGreen			= 0x8FBC8F;
constexpr const long	clrDarkSeaGreen			= 0x8FBC8F;
constexpr const long	DarkSlateBlue			= 0x8B3D48;
constexpr const long	clrDarkSlateBlue		= 0x8B3D48;
constexpr const long	DarkSlateGray			= 0x4F4F2F;
constexpr const long	clrDarkSlateGray		= 0x4F4F2F;
constexpr const long	DarkTurquoise			= 0xD1CE00;
constexpr const long	clrDarkTurquoise		= 0xD1CE00;
constexpr const long	DarkViolet				= 0xD30094;
constexpr const long	clrDarkViolet			= 0xD30094;
constexpr const long	DeepPink				= 0x9314FF;
constexpr const long	clrDeepPink				= 0x9314FF;
constexpr const long	DeepSkyBlue				= 0xFFBF00;
constexpr const long	clrDeepSkyBlue			= 0xFFBF00;
constexpr const long	DimGray					= 0x696969;
constexpr const long	clrDimGray				= 0x696969;
constexpr const long	DodgerBlue				= 0xFF901E;
constexpr const long	clrDodgerBlue			= 0xFF901E;
constexpr const long	FireBrick				= 0x2222B2;
constexpr const long	clrFireBrick			= 0x2222B2;
constexpr const long	ForestGreen				= 0x228B22;
constexpr const long	clrForestGreen			= 0x228B22;
constexpr const long	Fuchsia					= 0xFF00FF;
constexpr const long	clrFuchsia				= 0xFF00FF;
constexpr const long	Gainsboro				= 0xDCDCDC;
constexpr const long	clrGainsboro			= 0xDCDCDC;
constexpr const long	GhostWhite				= 0xFFF8F8;
constexpr const long	clrGhostWhite			= 0xFFF8F8;
constexpr const long	Gold					= 0x00D7FF;
constexpr const long	clrGold					= 0x00D7FF;
constexpr const long	Goldenrod				= 0x20A5DA;
constexpr const long	clrGoldenrod			= 0x20A5DA;
constexpr const long	Gray					= 0x808080;
constexpr const long	clrGray					= 0x808080;
constexpr const long	Green					= 0x008000;
constexpr const long	clrGreen				= 0x008000;
constexpr const long	GreenYellow				= 0x2FFFAD;
constexpr const long	clrGreenYellow			= 0x2FFFAD;
constexpr const long	Honeydew				= 0xF0FFF0;
constexpr const long	clrHoneydew				= 0xF0FFF0;
constexpr const long	HotPink					= 0xB469FF;
constexpr const long	clrHotPink				= 0xB469FF;
constexpr const long	IndianRed				= 0x5C5CCD;
constexpr const long	clrIndianRed			= 0x5C5CCD;
constexpr const long	Indigo					= 0x82004B;
constexpr const long	clrIndigo				= 0x82004B;
constexpr const long	Ivory					= 0xF0FFFF;
constexpr const long	clrIvory				= 0xF0FFFF;
constexpr const long	Khaki					= 0x8CE6F0;
constexpr const long	clrKhaki				= 0x8CE6F0;
constexpr const long	Lavender				= 0xFAE6E6;
constexpr const long	clrLavender				= 0xFAE6E6;
constexpr const long	LavenderBlush			= 0xF5F0FF;
constexpr const long	clrLavenderBlush		= 0xF5F0FF;
constexpr const long	LawnGreen				= 0x00FC7C;
constexpr const long	clrLawnGreen			= 0x00FC7C;
constexpr const long	LemonChiffon			= 0xCDFAFF;
constexpr const long	clrLemonChiffon			= 0xCDFAFF;
constexpr const long	LightBlue				= 0xE6D8AD;
constexpr const long	clrLightBlue			= 0xE6D8AD;
constexpr const long	LightCoral				= 0x8080F0;
constexpr const long	clrLightCoral			= 0x8080F0;
constexpr const long	LightCyan				= 0xFFFFE0;
constexpr const long	clrLightCyan			= 0xFFFFE0;
constexpr const long	LightGoldenrod			= 0xD2FAFA;
constexpr const long	clrLightGoldenrod		= 0xD2FAFA;
constexpr const long	LightGray				= 0xD3D3D3;
constexpr const long	clrLightGray			= 0xD3D3D3;
constexpr const long	LightGreen				= 0x90EE90;
constexpr const long	clrLightGreen			= 0x90EE90;
constexpr const long	LightPink				= 0xC1B6FF;
constexpr const long	clrLightPink			= 0xC1B6FF;
constexpr const long	LightSalmon				= 0x7AA0FF;
constexpr const long	clrLightSalmon			= 0x7AA0FF;
constexpr const long	LightSeaGreen			= 0xAAB220;
constexpr const long	clrLightSeaGreen		= 0xAAB220;
constexpr const long	LightSkyBlue			= 0xFACE87;
constexpr const long	clrLightSkyBlue			= 0xFACE87;
constexpr const long	LightSlateGray			= 0x998877;
constexpr const long	clrLightSlateGray		= 0x998877;
constexpr const long	LightSteelBlue			= 0xDEC4B0;
constexpr const long	clrLightSteelBlue		= 0xDEC4B0;
constexpr const long	LightYellow				= 0xE0FFFF;
constexpr const long	clrLightYellow			= 0xE0FFFF;
constexpr const long	Lime					= 0x00FF00;
constexpr const long	clrLime					= 0x00FF00;
constexpr const long	LimeGreen				= 0x32CD32;
constexpr const long	clrLimeGreen			= 0x32CD32;
constexpr const long	Linen					= 0xE6F0FA;
constexpr const long	clrLinen				= 0xE6F0FA;
constexpr const long	Magenta					= 0xFF00FF;
constexpr const long	clrMagenta				= 0xFF00FF;
constexpr const long	Maroon					= 0x000080;
constexpr const long	clrMaroon				= 0x000080;
constexpr const long	MediumAquamarine		= 0xAACD66;
constexpr const long	clrMediumAquamarine		= 0xAACD66;
constexpr const long	MediumBlue				= 0xCD0000;
constexpr const long	clrMediumBlue			= 0xCD0000;
constexpr const long	MediumOrchid			= 0xD355BA;
constexpr const long	clrMediumOrchid			= 0xD355BA;
constexpr const long	MediumPurple			= 0xDB7093;
constexpr const long	clrMediumPurple			= 0xDB7093;
constexpr const long	MediumSeaGreen			= 0x71B33C;
constexpr const long	clrMediumSeaGreen		= 0x71B33C;
constexpr const long	MediumSlateBlue			= 0xEE687B;
constexpr const long	clrMediumSlateBlue		= 0xEE687B;
constexpr const long	MediumSpringGreen		= 0x9AFA00;
constexpr const long	clrMediumSpringGreen	= 0x9AFA00;
constexpr const long	MediumTurquoise			= 0xCCD148;
constexpr const long	clrMediumTurquoise		= 0xCCD148;
constexpr const long	MediumVioletRed			= 0x8515C7;
constexpr const long	clrMediumVioletRed		= 0x8515C7;
constexpr const long	MidnightBlue			= 0x701919;
constexpr const long	clrMidnightBlue			= 0x701919;
constexpr const long	MintCream				= 0xFAFFF5;
constexpr const long	clrMintCream			= 0xFAFFF5;
constexpr const long	MistyRose				= 0xE1E4FF;
constexpr const long	clrMistyRose			= 0xE1E4FF;
constexpr const long	Moccasin				= 0xB5E4FF;
constexpr const long	clrMoccasin				= 0xB5E4FF;
constexpr const long	NavajoWhite				= 0xADDEFF;
constexpr const long	clrNavajoWhite			= 0xADDEFF;
constexpr const long	Navy					= 0x800000;
constexpr const long	clrNavy					= 0x800000;
constexpr const long	OldLace					= 0xE6F5FD;
constexpr const long	clrOldLace				= 0xE6F5FD;
constexpr const long	Olive					= 0x008080;
constexpr const long	clrOlive				= 0x008080;
constexpr const long	OliveDrab				= 0x238E6B;
constexpr const long	clrOliveDrab			= 0x238E6B;
constexpr const long	Orange					= 0x00A5FF;
constexpr const long	clrOrange				= 0x00A5FF;
constexpr const long	OrangeRed				= 0x0045FF;
constexpr const long	clrOrangeRed			= 0x0045FF;
constexpr const long	Orchid					= 0xD670DA;
constexpr const long	clrOrchid				= 0xD670DA;
constexpr const long	PaleGoldenrod			= 0xAAE8EE;
constexpr const long	clrPaleGoldenrod		= 0xAAE8EE;
constexpr const long	PaleGreen				= 0x98FB98;
constexpr const long	clrPaleGreen			= 0x98FB98;
constexpr const long	PaleTurquoise			= 0xEEEEAF;
constexpr const long	clrPaleTurquoise		= 0xEEEEAF;
constexpr const long	PaleVioletRed			= 0x9370DB;
constexpr const long	clrPaleVioletRed		= 0x9370DB;
constexpr const long	PapayaWhip				= 0xD5EFFF;
constexpr const long	clrPapayaWhip			= 0xD5EFFF;
constexpr const long	PeachPuff				= 0xB9DAFF;
constexpr const long	clrPeachPuff			= 0xB9DAFF;
constexpr const long	Peru					= 0x3F85CD;
constexpr const long	clrPeru					= 0x3F85CD;
constexpr const long	Pink					= 0xCBC0FF;
constexpr const long	clrPink					= 0xCBC0FF;
constexpr const long	Plum					= 0xDDA0DD;
constexpr const long	clrPlum					= 0xDDA0DD;
constexpr const long	PowderBlue				= 0xE6E0B0;
constexpr const long	clrPowderBlue			= 0xE6E0B0;
constexpr const long	Purple					= 0x800080;
constexpr const long	clrPurple				= 0x800080;
constexpr const long	Red						= 0x0000FF;
constexpr const long	clrRed					= 0x0000FF;
constexpr const long	RosyBrown				= 0x8F8FBC;
constexpr const long	clrRosyBrown			= 0x8F8FBC;
constexpr const long	RoyalBlue				= 0xE16941;
constexpr const long	clrRoyalBlue			= 0xE16941;
constexpr const long	SaddleBrown				= 0x13458B;
constexpr const long	clrSaddleBrown			= 0x13458B;
constexpr const long	Salmon					= 0x7280FA;
constexpr const long	clrSalmon				= 0x7280FA;
constexpr const long	SandyBrown				= 0x60A4F4;
constexpr const long	clrSandyBrown			= 0x60A4F4;
constexpr const long	SeaGreen				= 0x578B2E;
constexpr const long	clrSeaGreen				= 0x578B2E;
constexpr const long	Seashell				= 0xEEF5FF;
constexpr const long	clrSeashell				= 0xEEF5FF;
constexpr const long	Sienna					= 0x2D52A0;
constexpr const long	clrSienna				= 0x2D52A0;
constexpr const long	Silver					= 0xC0C0C0;
constexpr const long	clrSilver				= 0xC0C0C0;
constexpr const long	SkyBlue					= 0xEBCE87;
constexpr const long	clrSkyBlue				= 0xEBCE87;
constexpr const long	SlateBlue				= 0xCD5A6A;
constexpr const long	clrSlateBlue			= 0xCD5A6A;
constexpr const long	SlateGray				= 0x908070;
constexpr const long	clrSlateGray			= 0x908070;
constexpr const long	Snow					= 0xFAFAFF;
constexpr const long	clrSnow					= 0xFAFAFF;
constexpr const long	SpringGreen				= 0x7FFF00;
constexpr const long	clrSpringGreen			= 0x7FFF00;
constexpr const long	SteelBlue				= 0xB48246;
constexpr const long	clrSteelBlue			= 0xB48246;
constexpr const long	Tan						= 0x8CB4D2;
constexpr const long	clrTan					= 0x8CB4D2;
constexpr const long	Teal					= 0x808000;
constexpr const long	clrTeal					= 0x808000;
constexpr const long	Thistle					= 0xD8BFD8;
constexpr const long	clrThistle				= 0xD8BFD8;
constexpr const long	Tomato					= 0x4763FF;
constexpr const long	clrTomato				= 0x4763FF;
constexpr const long	Turquoise				= 0xD0E040;
constexpr const long	clrTurquoise			= 0xD0E040;
constexpr const long	Violet					= 0xEE82EE;
constexpr const long	clrViolet				= 0xEE82EE;
constexpr const long	Wheat					= 0xB3DEF5;
constexpr const long	clrWheat				= 0xB3DEF5;
constexpr const long	White					= 0xFFFFFF;
constexpr const long	clrWhite				= 0xFFFFFF;
constexpr const long	WhiteSmoke				= 0xF5F5F5;
constexpr const long	clrWhiteSmoke			= 0xF5F5F5;
constexpr const long	Yellow					= 0x00FFFF;
constexpr const long	clrYellow				= 0x00FFFF;
constexpr const long	YellowGreen				= 0x32CD9A;
constexpr const long	clrYellowGreen			= 0x32CD9A;