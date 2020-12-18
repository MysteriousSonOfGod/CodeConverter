#pragma once

#include <vector>

namespace mql4
{
	// Base Enum class	
	class MqlEnum
	{
	public:
		struct Element
		{
			Element() = delete;
			Element(int v, const char* n) : val(v), name(n), beauty_name(nullptr) {}
			Element(int v, const char* n, const char* bn) : val(v), name(n), beauty_name(bn) {}

			int val;
			const char* name;
			const char* beauty_name;
		};

		MqlEnum() : m_val(0) {}

		std::string ToStr() const { return m_val < m_ep->size() ? (*m_ep)[m_val].name : ""; }
		operator int() const { return m_val < m_ep->size() ? (*m_ep)[m_val].val : m_val; }
		int* operator&() { return &m_val; }

		void GenerateExtern(const char* var_name);

	protected:
		void SetVal(int v);
		// Data
		std::vector<Element>* m_ep;
		int m_val;
	};

	inline void MqlEnum::SetVal(int v)
	{
		size_t s = m_ep->size();
		for(size_t i = 0; i < s; ++i)
		{
			if((*m_ep)[i].val == v)
			{
				m_val = (int)i;
				return;
			}
		}

		m_val = v;
	}

	// Concrete Enum Classes
	class ENUM_APPLIED_PRICE : public MqlEnum
	{
	public:
		ENUM_APPLIED_PRICE() : MqlEnum() { m_ep = &m_elems; }
		ENUM_APPLIED_PRICE(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_APPLIED_PRICE& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int PRICE_CLOSE = 0;
	constexpr const int PRICE_OPEN = 1;
	constexpr const int PRICE_HIGH = 2;
	constexpr const int PRICE_LOW = 3;
	constexpr const int PRICE_MEDIAN = 4;
	constexpr const int PRICE_TYPICAL = 5;
	constexpr const int PRICE_WEIGHTED = 6;

	class ENUM_MA_METHOD : public MqlEnum
	{
	public:
		ENUM_MA_METHOD() : MqlEnum() { m_ep = &m_elems; }
		ENUM_MA_METHOD(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_MA_METHOD& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int MODE_SMA = 0;
	constexpr const int MODE_EMA = 1;
	constexpr const int MODE_SMMA = 2;
	constexpr const int MODE_LWMA = 3;

	class ENUM_LINE_STYLE : public MqlEnum
	{
	public:
		ENUM_LINE_STYLE() : MqlEnum() { m_ep = &m_elems; }
		ENUM_LINE_STYLE(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_LINE_STYLE& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int STYLE_SOLID = 0;
	constexpr const int STYLE_DASH = 1;
	constexpr const int STYLE_DOT = 2;
	constexpr const int STYLE_DASHDOT = 3;
	constexpr const int STYLE_DASHDOTDOT = 4;

	class ENUM_TIMEFRAMES : public MqlEnum
	{
	public:
		ENUM_TIMEFRAMES() : MqlEnum() { m_ep = &m_elems; }
		ENUM_TIMEFRAMES(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_TIMEFRAMES& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int PERIOD_CURRENT = 0;
	constexpr const int PERIOD_M1 = 1;
	constexpr const int PERIOD_M5 = 5;
	constexpr const int PERIOD_M15 = 15;
	constexpr const int PERIOD_M30 = 30;
	constexpr const int PERIOD_H1 = 60;
	constexpr const int PERIOD_H4 = 240;
	constexpr const int PERIOD_D1 = 1440;
	constexpr const int PERIOD_W1 = 10080;
	constexpr const int PERIOD_MN1 = 43200;

	class ENUM_DRAW_STYLE : public MqlEnum
	{
	public:
		ENUM_DRAW_STYLE() : MqlEnum() { m_ep = &m_elems; }
		ENUM_DRAW_STYLE(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_DRAW_STYLE& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int DRAW_LINE = 0;
	constexpr const int DRAW_SECTION = 1;
	constexpr const int DRAW_HISTOGRAM = 2;
	constexpr const int DRAW_ARROW = 3;
	constexpr const int DRAW_ZIGZAG = 4;
	constexpr const int DRAW_NONE = 12;

	class ENUM_DAY_OF_WEEK : public MqlEnum
	{
	public:
		ENUM_DAY_OF_WEEK() : MqlEnum() { m_ep = &m_elems; }
		ENUM_DAY_OF_WEEK(int v) { m_ep = &m_elems; SetVal(v); }

		ENUM_DAY_OF_WEEK& operator=(int v) { SetVal(v); return *this; }
		static std::vector<Element> m_elems;
	};

	constexpr const int SUNDAY = 0;
	constexpr const int MONDAY = 1;
	constexpr const int TUESDAY = 2;
	constexpr const int WEDNESDAY = 3;
	constexpr const int THURSDAY = 4;
	constexpr const int FRIDAY = 5;
	constexpr const int SATURDAY = 6;
}