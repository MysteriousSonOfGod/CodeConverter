#include "pch.h"

#include "MqlEnums.h"

#ifdef __INDICATOR
#include "IndicatorInterfaceUnit.h"
#else
#include "StrategyInterfaceUnit.h"
#endif

namespace mql4
{
	void MqlEnum::GenerateExtern(const char* var_name)
	{
		RegOption((char*)var_name, ot_EnumType, &m_val);
		size_t s = m_ep->size();
		for(size_t i = 0; i < s; ++i)
		{
			if((*m_ep)[i].beauty_name == nullptr)
			{
				AddOptionValue((char*)var_name, (char*)(*m_ep)[i].name);
			}
			else
			{
				AddOptionValue((char*)var_name, (char*)(*m_ep)[i].beauty_name);
			}
		}
	}
}