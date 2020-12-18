#pragma once

#include "MqlString.h"
#include <sstream>

#pragma warning(disable : 4996)

inline void padStr(std::string& str, int width, bool left, char symb,
	bool signed_t = 0, bool plus = 0, bool space = 0, bool positive = 0)
{
	size_t size = str.size();

	if(width > size)
	{
		std::string pad(width - size, symb);
		str = left ? pad + str : str + pad;
		if(!left)
		{
			goto add_at_beg;
		}
		else
		{
			if(signed_t && positive)
			{
				if(plus)
				{
					str[0] = '+';
				}
				else if(space)
				{
					str[0] = ' ';;
				}
			}
		}

		return;
	}

add_at_beg:
	if(signed_t && positive)
	{
		if(plus)
		{
			str = std::string("+") + str;
		}
		else if(space)
		{
			str = std::string(" ") + str;
		}
	}
}

inline void toUpper(std::string& str)
{
	for(int i = 0; i < str.size(); ++i) // Convert to upper case
	{
		char c = str[i];
		if(c > 57)
		{
			str[i] = c & ~0x20;
		}
	}
}

inline std::string shortToUtf8(unsigned short c)
{
	if(c < 127)
	{
		std::string tmp = "0";
		tmp[0] = c;
		return tmp;
	}
	else if(c < 2048)
	{
		const unsigned char b1 = 0xC0;
		const unsigned char b2 = 0x80;

		std::string out = "00";
		out[1] = b2 | (c & 0x3F);
		out[0] = b1 | ((c & 0x7C0) >> 6);

		return out;
	}
	else
	{
		const unsigned char b1 = 0xE0;
		const unsigned char b2 = 0x80;
		const unsigned char b3 = 0x80;

		std::string out = "000";
		out[2] = b3 | (c & 0x3F);
		out[1] = b2 | ((c & 0xFC0) >> 6);
		out[0] = b1 | ((c & 0xF000) >> 12);

		return out;
	}
}

inline void format_string_recurv(std::string& format, size_t last_mod)
{
	size_t s = format.size();
	for(size_t i = 0; i < s; ++i)
	{
		if(format[i] != '%')
		{
			continue;
		}

		size_t form_start = i;

		bool flag_min = 0, flag_plus = 0, flag_zero = 0, flag_space = 0, flag_hash = 0;

		while(true)
		{
			switch(format[++i])
			{
			case '-':
				flag_min = true;
				break;
			case '+':
				flag_plus = true;
				break;
			case '0':
				flag_zero = true;
				break;
			case ' ':
				flag_space = true;
				break;
			case '#':
				flag_hash = true;
				break;
			default:
				goto endloop;
			}
		}
	endloop:

		std::string width_str;
		while(true)
		{
			char c = format[i++];
			if(c > 47 && c < 58)
			{
				width_str.push_back(c);
			}
			else
			{
				break;
			}
		}

		int width = 0;

		if(!width_str.empty())
		{
			width = std::stoi(width_str);
		}

		int precision = 0;

		if(format[--i] == '.')
		{
			std::string precision_str;
			while(format[++i] > 47 && format[i] < 58)
			{
				precision_str.push_back(format[i]);
			}
			precision = std::stoi(precision_str);
		}

		bool data_long = 0, data_long_long = 0, data_short = 0;

		switch(format[i])
		{
		case 'l':
			switch(format[i+1])
			{
			case 'l':
				data_long_long = true;
				i += 2;
				break;
			default:
				data_long = true;
				++i;
			}
			break;
		case 'h':
			data_short = true;
			++i;
			break;
		case 'I':
			switch(format[i+1])
			{
			case '6':
				data_long_long = true;
				i += 3;
				break;
			case '3':
				data_long = true;
				i += 3;
				break;
			default:;
			}
		default:;
		}

		std::string out;
		std::stringstream sstr;
		switch(format[i])
		{
		case 'c': // Short (Unicode)
			out.push_back((char)0);
			padStr(out, width + out.size()-1, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			break;
		case 'C': // Char (ASCII)
			out.push_back((char)0);
			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			break;
		case 'd': // Decimal signed integer
		case 'i': // Decimal signed integer
			out = "0";
			if(precision)
			{
				padStr(out, precision, true, 48, true, flag_plus, flag_space, true);
				padStr(out, width, !flag_min, ' ', true, flag_plus, flag_space, true);
			}
			else
			{
				padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, true);
			}
			break;
		case 'o': // Octal unsigned integer
			out = "0";

			if(flag_hash)
			{
				out = std::string("0") + out;
			}

			if(precision)
			{
				padStr(out, precision, true, 48);
				padStr(out, width, !flag_min, ' ');
			}
			else
			{
				padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			}
			break;
		case 'u': // Decimal unsigned integer
			out = "0";

			if(precision)
			{
				padStr(out, precision, true, 48);
				padStr(out, width, !flag_min, ' ');
			}
			else
			{
				padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			}
			break;
		case 'x': // Hexadecimal unsigned integer (lower case)
		case 'X': // Hexadecimal unsigned integer (upper case)
			out = "0";

			if(precision)
			{
				padStr(out, precision, true, 48);
				padStr(out, width, !flag_min, ' ');
			}
			else
			{
				padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			}
			break;
		case 'e': // Double (Scientific notation, lower case e)
		case 'E': // Double (Scientific notation, upper case E)
			if(precision)
			{
				sstr.precision(precision);
			}

			sstr << std::fixed << std::scientific << 0.0;
			out = sstr.str();

			if(format[i] == 'E')
			{
				toUpper(out);
			}

			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, true);
			break;
		case 'f': // Double (Ordinary notation)
			if(precision)
			{
				sstr.precision(precision);
			}

			sstr << std::fixed << 0.0;
			out = sstr.str();

			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, true);
			break;
		case 'g': // Automatic decision between f and e (most compact one is chosen)
		case 'G': // Automatic decision between f and E (most compact one is chosen)
		case 'a': // Double (Hexadecimal, lower case p)
		case 'A': // Double (Hexadecimal, upper case P)
		{
			std::string f;
			if(precision)
			{
				f = "%." + std::to_string(precision);
			}
			else
			{
				f = "%";
			}

			f.push_back(format[i]);

			char buf[1024];
			sprintf(buf, f.c_str(), 0.0);
			out = buf;

			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, true);
			break;
		}
		case 's': // String
			if(precision)
			{
				out = std::string("(missed string parameter)").substr(0, precision);
			}
			else
			{
				out = "(missed string parameter)";
			}

			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
			break;
		case '%': // Percent sign
			out = "%";
			break;
		default:
			out = " ";
			i = form_start;
		}

		format.replace(form_start, i - form_start + 1, out);
		i = form_start + out.size() - 1;
	}
}

template<typename T, typename...Ts>
void format_string_recurv(std::string& format, size_t last_mod, const T& arg, const Ts&... args)
{
	size_t form = format.find('%', last_mod);
	const size_t form_start = form;

	if(form == std::string::npos)
	{
		format_string_recurv(format, last_mod, args...);
		return;
	}

	static int prev_int = 0; // For width passed as argument

	bool flag_min = 0, flag_plus = 0, flag_zero = 0, flag_space = 0, flag_hash = 0;

	while(true)
	{
		switch(format[++form])
		{
		case '-':
			flag_min = true;
			break;
		case '+':
			flag_plus = true;
			break;
		case '0':
			flag_zero = true;
			break;
		case ' ':
			flag_space = true;
			break;
		case '#':
			flag_hash = true;
			break;
		default:
			goto endloop;
		}
	}
endloop:

	std::string width_str;
	bool width_in_arg = false; // Width is stored in PRECEDING int variable
	while(true)
	{
		char c = format[form++];
		if(c > 47 && c < 58)
		{
			width_str.push_back(c);
		}
		else if(c == '*')
		{
			width_in_arg = true;
		}
		else
		{
			break;
		}
	}

	int width = 0;

	if(width_in_arg)
	{
		width = prev_int;
	}
	else if(!width_str.empty())
	{
		width = std::stoi(width_str);
	}

	int precision = 0;

	if(format[--form] == '.')
	{
		std::string precision_str;
		while(format[++form] > 47 && format[form] < 58)
		{
			precision_str.push_back(format[form]);
		}
		precision = std::stoi(precision_str);
	}

	bool data_long = 0, data_long_long = 0, data_short = 0;

	switch(format[form])
	{
	case 'l':
		switch(format[form+1])
		{
		case 'l':
			data_long_long = true;
			form += 2;
			break;
		default:
			data_long = true;
			++form;
		}
		break;
	case 'h':
		data_short = true;
		++form;
		break;
	case 'I':
		switch(format[form+1])
		{
		case '6':
			data_long_long = true;
			form += 3;
			break;
		case '3':
			data_long = true;
			form += 3;
			break;
		default:;
		}
	default:;
	}

	std::string out;
	std::stringstream sstr;
	switch(format[form])
	{
	case 'c': // Short (Unicode)
		out = shortToUtf8((unsigned short)arg);
		padStr(out, width + out.size()-1, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		break;
	case 'C': // Char (ASCII)
		out.push_back((char)arg);
		padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		break;
	case 'd': // Decimal signed integer
	case 'i': // Decimal signed integer
		if(data_long_long)
		{
			out = std::to_string((long long)arg);
		}
		else if(data_short)
		{
			out = std::to_string((short)arg);
		}
		else
		{
			out = std::to_string((int)arg);
		}

		if(precision)
		{
			padStr(out, precision, true, 48, true, flag_plus, flag_space, (int)arg > 0);
			padStr(out, width, !flag_min, ' ', true, flag_plus, flag_space, (int)arg > 0);
		}
		else
		{
			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, (int)arg > 0);
		}
		break;
	case 'o': // Octal unsigned integer
		if(data_long_long)
		{
			sstr << std::oct << (unsigned long long)arg;
		}
		else if(data_short)
		{
			sstr << std::oct << (unsigned short)arg;
		}
		else
		{
			sstr << std::oct << (unsigned int)arg;
		}

		out = sstr.str();

		if(flag_hash)
		{
			out = std::string("0") + out;
		}

		if(precision)
		{
			padStr(out, precision, true, 48);
			padStr(out, width, !flag_min, ' ');
		}
		else
		{
			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		}
		break;
	case 'u': // Decimal unsigned integer
		if(data_long_long)
		{
			out = std::to_string((unsigned long long)arg);
		}
		else if(data_short)
		{
			out = std::to_string((unsigned short)arg);
		}
		else
		{
			out = std::to_string((unsigned int)arg);
		}

		if(precision)
		{
			padStr(out, precision, true, 48);
			padStr(out, width, !flag_min, ' ');
		}
		else
		{
			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		}
		break;
	case 'x': // Hexadecimal unsigned integer (lower case)
	case 'X': // Hexadecimal unsigned integer (upper case)
		if(data_long_long)
		{
			sstr << std::hex << (unsigned long long)arg;
		}
		else if(data_short)
		{
			sstr << std::hex << (unsigned short)arg;
		}
		else
		{
			sstr << std::hex << (unsigned int)arg;
		}

		out = sstr.str();

		if(flag_hash && (bool)arg)
		{
			out = std::string("0x") + out;
		}

		if(format[form] == 'X')
		{
			toUpper(out);
		}

		if(precision)
		{
			padStr(out, precision, true, 48);
			padStr(out, width, !flag_min, ' ');
		}
		else
		{
			padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		}
		break;
	case 'e': // Double (Scientific notation, lower case e)
	case 'E': // Double (Scientific notation, upper case E)
		if(precision)
		{
			sstr.precision(precision);
		}

		sstr << std::fixed << std::scientific << (double)arg;
		out = sstr.str();

		if(format[form] == 'E')
		{
			toUpper(out);
		}

		padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, (double)arg >= 0);
		break;
	case 'f': // Double (Ordinary notation)
		if(precision)
		{
			sstr.precision(precision);
		}

		sstr << std::fixed << (double)arg;
		out = sstr.str();

		padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, (double)arg >= 0);
		break;
	case 'g': // Automatic decision between f and e (most compact one is chosen)
	case 'G': // Automatic decision between f and E (most compact one is chosen)
	case 'a': // Double (Hexadecimal, lower case p)
	case 'A': // Double (Hexadecimal, upper case P)
	{
		std::string f;
		if(precision)
		{
			f = "%." + std::to_string(precision);
		}
		else
		{
			f = "%";
		}

		f.push_back(format[form]);

		char buf[1024];
		sprintf(buf, f.c_str(), (double)arg);
		out = buf;

		padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ', true, flag_plus, flag_space, (double)arg >= 0);
		break;
	}
	case 's': // String
		if(precision)
		{
			out = ((const std::string&)arg).substr(0, precision);
		}
		else
		{
			out = arg;
		}

		padStr(out, width, !flag_min, !flag_min && flag_zero ? '0' : ' ');
		break;
	case '%': // Percent sign
		out = "%";
		break;
	default:
		out = " ";
		form = form_start;
	}

	format.replace(form_start, form - form_start + 1, out);

	prev_int = (int)arg;
	last_mod = form_start + out.size();
	format_string_recurv(format, last_mod, args...);
}

template<typename... Ts>
mql4::string  StringFormat(const mql4::string& format, const Ts&... args)
{
	std::string res = format;
	format_string_recurv(res, 0, args...);
	return res;
}