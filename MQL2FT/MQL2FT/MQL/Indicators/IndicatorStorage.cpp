#include "../pch.h"

#include "IndicatorStorage.h"


void IndicatorStorage::reset()
{
	m_ema_indcators.resize(0);
	m_sma_indicators.resize(0);
	m_smma_indicators.resize(0);
	m_wma_indicators.resize(0);
	m_macd_indicators.resize(0);
	m_osma_indicators.resize(0);
	m_rsi_indicators.resize(0);
    m_cci_indicators.resize(0);
    m_atr_indicators.resize(0);
	m_ao_indicators.resize(0);
	m_bears_power_indicators.resize(0);
	m_bulls_power_indicators.resize(0);
	m_force_index_indicators.resize(0);
	m_envelopes_indicators.resize(0);
	m_ad_indicators.resize(0);
	m_mfi_indicators.resize(0);
	m_stochastic_indicators.resize(0);
	m_std_dev_indicators.resize(0);
	m_on_balance_volume_indicators.resize(0);
	m_sar_indicators.resize(0);
	m_bands_indicators.resize(0);
	m_ac_indicators.resize(0);
	m_de_marker_indicators.resize(0);
	m_wpr_indicators.resize(0);
	m_adx_indicators.resize(0);
	m_rvi_indicators.resize(0);
	m_ichimoku_indicators.resize(0);
    m_fractals_indicators.resize(0);
}

void IndicatorStorage::update()
{
	for (auto updatable_indicator : m_updatable_indcators)
	{
		updatable_indicator->update();
	}
}

std::weak_ptr<ExponentialMovingAverage> IndicatorStorage::getEmaData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<ExponentialMovingAverage> ema)
	{
		return ema.get()->getSymbol() == current_symbol &&
			   ema.get()->getTimeframe() == current_timeframe &&
		       ema.get()->getPriceType() == price_type &&
			   ema.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_ema_indcators.cbegin(), m_ema_indcators.cend(), lambda);

	if (indicator == m_ema_indcators.cend())
	{
		std::shared_ptr<ExponentialMovingAverage> new_indicator{
			new ExponentialMovingAverage{ current_symbol, current_timeframe, period, price_type }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_ema_indcators.push_back(new_indicator);
		indicator = (m_ema_indcators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getEmaValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<ExponentialMovingAverage> indicator = getEmaData(symbol, timeframe, period, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<SimpleMovingAverage> IndicatorStorage::getSmaData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<SimpleMovingAverage> sma) 
	{
        return sma.get()->getSymbol() == current_symbol &&
			   sma.get()->getTimeframe() == current_timeframe &&
			   sma.get()->getPriceType() == price_type &&
			   sma.get()->getPeriod() == period; 
    };

	auto indicator = std::find_if(m_sma_indicators.cbegin(), m_sma_indicators.cend(), lambda);

	if (indicator == m_sma_indicators.cend())
	{
		std::shared_ptr<SimpleMovingAverage> new_indicator{
			new SimpleMovingAverage{ current_symbol, current_timeframe, period, price_type }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_sma_indicators.push_back(new_indicator);
		indicator = (m_sma_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getSmaValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<SimpleMovingAverage> indicator = getSmaData(symbol, timeframe, period, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<WeightedMovingAverage> IndicatorStorage::getWmaData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<WeightedMovingAverage> wma) 
    {
        return wma.get()->getSymbol() == current_symbol &&																				
               wma.get()->getTimeframe() == current_timeframe &&																				
               wma.get()->getPriceType() == price_type &&																				
               wma.get()->getPeriod() == period; 
    };

	auto indicator = std::find_if(m_wma_indicators.cbegin(), m_wma_indicators.cend(), lambda);
	if (indicator == m_wma_indicators.cend())
	{
		std::shared_ptr<WeightedMovingAverage> new_indicator{
			new WeightedMovingAverage{ current_symbol, current_timeframe, period, price_type }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_wma_indicators.push_back(new_indicator);
		indicator = (m_wma_indicators.cend() - 1);
	}
	return *indicator;
}

double IndicatorStorage::getWmaValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<WeightedMovingAverage> indicator = getWmaData(symbol, timeframe, period, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<SmoothedMovingAverage> IndicatorStorage::getSmmaData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<SmoothedMovingAverage> smma) 
    {
        return smma.get()->getSymbol() == current_symbol &&
		       smma.get()->getTimeframe() == current_timeframe &&
		       smma.get()->getPriceType() == price_type &&
		       smma.get()->getPeriod() == period; 
    };

	auto indicator = std::find_if(m_smma_indicators.cbegin(), m_smma_indicators.cend(), lambda);
	if (indicator == m_smma_indicators.cend())
	{
		std::shared_ptr<SmoothedMovingAverage> new_indicator{
			new SmoothedMovingAverage{ current_symbol, current_timeframe, period, price_type }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_smma_indicators.push_back(new_indicator);
		indicator = (m_smma_indicators.cend() - 1);
	}
	return *indicator;
}

double IndicatorStorage::getSmmaValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<SmoothedMovingAverage> indicator = getSmmaData(symbol, timeframe, period, price_type);
	return indicator.lock()->getValue(index);
}

double IndicatorStorage::getMacdValue(const std::string& symbol, const int timeframe, const int price_type,
	const int shortPeriod, const int longPeriod, const int signalPeriod, const int mode, const int index)
{
	std::weak_ptr<Macd> indicator = getMacdData(symbol, timeframe, price_type, shortPeriod, longPeriod, signalPeriod);
	switch (mode)
	{
		case 0:
			return indicator.lock()->getMacd(index);

		case 1:
			return indicator.lock()->getSignal(index);

		default: 
			return 0.0;
	}
}

std::weak_ptr<Macd> IndicatorStorage::getMacdData(const std::string& symbol, const int timeframe, const int price_type,
	const int short_period, const int long_period, const int signal_period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<Macd> macd)
    {
        return macd.get()->getSymbol() == current_symbol &&																
               macd.get()->getTimeframe() == current_timeframe &&																
               macd.get()->getPriceType() == price_type &&																
               macd.get()->getShortPeriod() == short_period &&																
               macd.get()->getLongPeriod() == long_period &&																
               macd.get()->getSignalPeriod() == signal_period;
    };

	auto indicator = std::find_if(m_macd_indicators.cbegin(), m_macd_indicators.cend(), lambda);

	if (indicator == m_macd_indicators.cend())
	{
		auto shortEmaData = getEmaData(current_symbol, current_timeframe, short_period, price_type);
		auto longEmaData = getEmaData(current_symbol, current_timeframe, long_period, price_type);
		std::shared_ptr<Macd> new_indicator{
			new Macd{
				current_symbol, current_timeframe, price_type,
				short_period, long_period, signal_period, shortEmaData, longEmaData
			}
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_macd_indicators.push_back(new_indicator);
		indicator = (m_macd_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getOsmaValue(const std::string& symbol, const int timeframe, const int price_type,
	const int shortPeriod, const int longPeriod, const int signalPeriod, const int index)
{
	std::weak_ptr<MovingAverageOscillator> indicator = getOsmaData(symbol, timeframe, price_type, shortPeriod, longPeriod, signalPeriod);
	return indicator.lock()->getValue(index);
}


std::weak_ptr<MovingAverageOscillator> IndicatorStorage::getOsmaData(const std::string& symbol, const int timeframe,
	const int price_type, const int shortPeriod, const int longPeriod, const int signalPeriod)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<MovingAverageOscillator> osma)
	{
		return osma.get()->getSymbol() == current_symbol &&
			   osma.get()->getTimeframe() == current_timeframe &&
			   osma.get()->getPriceType() == price_type &&
			   osma.get()->getShortPeriod() == shortPeriod &&
			   osma.get()->getLongPeriod() == longPeriod &&
			   osma.get()->getSignalPeriod() == signalPeriod;
	};

	auto indicator = std::find_if(m_osma_indicators.cbegin(), m_osma_indicators.cend(), lambda);

	if (indicator == m_osma_indicators.cend())
	{
		auto macdData = getMacdData(current_symbol, current_timeframe, price_type, shortPeriod, longPeriod, signalPeriod);
		std::shared_ptr<MovingAverageOscillator> new_indicator{
			new MovingAverageOscillator{
				current_symbol, current_timeframe, price_type,
				shortPeriod, longPeriod, signalPeriod,macdData
			}
		};

		m_osma_indicators.push_back(new_indicator);
		indicator = (m_osma_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getRsiValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<RelativeStrengthIndex> indicator = getRsiData(symbol, timeframe, period, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<RelativeStrengthIndex> IndicatorStorage::getRsiData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<RelativeStrengthIndex> rsi) 
    {
        return rsi.get()->getSymbol() == current_symbol &&																				
               rsi.get()->getTimeframe() == current_timeframe &&																				
               rsi.get()->getPriceType() == price_type &&																				
               rsi.get()->getPeriod() == period; 
    };

	auto indicator = std::find_if(m_rsi_indicators.cbegin(), m_rsi_indicators.cend(), lambda);
	if (indicator == m_rsi_indicators.cend())
	{
		std::shared_ptr<RelativeStrengthIndex> new_indicator{
			new RelativeStrengthIndex{ current_symbol, current_timeframe, price_type, period  }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_rsi_indicators.push_back(new_indicator);
		indicator = (m_rsi_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getCciValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
    std::weak_ptr<CommodityChannelIndex> indicator = getCciData(symbol, timeframe, period, price_type);
    return indicator.lock()->getValue(index);
}

std::weak_ptr<CommodityChannelIndex> IndicatorStorage::getCciData(const std::string& symbol, const int timeframe,
	const int period, const int price_type)
{
    std::string current_symbol = getValidSymbol(symbol);
    int current_timeframe = getValidTimeframe(timeframe);

    const auto lambda = [&](std::shared_ptr<CommodityChannelIndex> cci) 
    {
        return cci.get()->getSymbol() == current_symbol &&                                                                               
               cci.get()->getTimeframe() == current_timeframe &&                                                                                
               cci.get()->getPriceType() == price_type &&                                                                                
               cci.get()->getPeriod() == period; 
    };

    auto indicator = std::find_if(m_cci_indicators.cbegin(), m_cci_indicators.cend(), lambda);

    if (indicator == m_cci_indicators.cend())
	{
        auto sma_data = getSmaData(current_symbol, current_timeframe, period, price_type);
        std::shared_ptr<CommodityChannelIndex > new_indicator{
			new CommodityChannelIndex{ current_symbol, current_timeframe, price_type, period, sma_data }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_cci_indicators.push_back(new_indicator);
        indicator = (m_cci_indicators.cend() - 1);
    }

    return *indicator;
}


double IndicatorStorage::getAtrValue(const std::string& symbol, int timeframe, int period, int index)
{
    std::weak_ptr<AverageTrueRange> indicator = getAtrData(symbol, timeframe, period);
    return indicator.lock()->getValue(index);
}

std::weak_ptr<AverageTrueRange> IndicatorStorage::getAtrData(const std::string& symbol, const int timeframe,
	const int period)
{
    std::string current_symbol = getValidSymbol(symbol);
    int current_timeframe = getValidTimeframe(timeframe);

    const auto lambda = [&](std::shared_ptr<AverageTrueRange> atr) 
    {
        return atr.get()->getSymbol() == current_symbol &&                                                                     
               atr.get()->getTimeframe() == current_timeframe &&                                                                            
               atr.get()->getPeriod() == period; 
    };

    auto indicator = std::find_if(m_atr_indicators.cbegin(), m_atr_indicators.cend(), lambda);

    if (indicator == m_atr_indicators.cend())
	{
        std::shared_ptr<AverageTrueRange> new_indicator{
			new AverageTrueRange{ current_symbol, current_timeframe, period }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_atr_indicators.push_back(new_indicator);
        indicator = (m_atr_indicators.cend() - 1);
    }

    return *indicator;
}


double IndicatorStorage::getAoValue(const std::string& symbol, int timeframe, int index)
{
	std::weak_ptr<AwesomeOscillator> indicator = getAoData(symbol, timeframe);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<AwesomeOscillator> IndicatorStorage::getAoData(const std::string& symbol, const int timeframe)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<AwesomeOscillator> ao)
	{
		return ao.get()->getSymbol() == current_symbol &&
			   ao.get()->getTimeframe() == current_timeframe;
	};

	auto indicator = std::find_if(m_ao_indicators.cbegin(), m_ao_indicators.cend(), lambda);

	if (indicator == m_ao_indicators.cend())
	{
		auto sma_data_5 = getSmaData(current_symbol, current_timeframe, 5, PRICE_MEDIAN);
		auto sma_data_34 = getSmaData(current_symbol, current_timeframe, 34, PRICE_MEDIAN);
		std::shared_ptr<AwesomeOscillator> new_indicator{
			new AwesomeOscillator{ current_symbol, current_timeframe, sma_data_5, sma_data_34 }
		};

		m_ao_indicators.push_back(new_indicator);
		indicator = (m_ao_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getBearsPowerValue(const std::string& symbol, const int timeframe, const int period, 
	const int price_type, const int index)
{
	std::weak_ptr<BearsPower> indicator = getBearsPowerData(symbol, timeframe, price_type, period);
	return indicator.lock()->getValue(index);
}


std::weak_ptr<BearsPower> IndicatorStorage::getBearsPowerData(const std::string& symbol, const int timeframe,
	const int price_type, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<BearsPower> bp)
	{
		return bp.get()->getSymbol() == current_symbol &&
			   bp.get()->getTimeframe() == current_timeframe &&
			   bp.get()->getPriceType() == price_type &&
			   bp.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_bears_power_indicators.cbegin(), m_bears_power_indicators.cend(), lambda);

	if (indicator == m_bears_power_indicators.cend())
	{
		auto ema_data_ = getEmaData(current_symbol, current_timeframe, period, price_type);
		std::shared_ptr<BearsPower> new_indicator{
			new BearsPower{ current_symbol, current_timeframe, period, price_type, ema_data_ }
		};

		m_bears_power_indicators.push_back(new_indicator);
		indicator = (m_bears_power_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getBullsPowerValue(const std::string& symbol, const int timeframe, const int period,
	const int price_type, const int index)
{
	std::weak_ptr<BullsPower> indicator = getBullsPowerData(symbol, timeframe, price_type, period);
	return indicator.lock()->getValue(index);
}


std::weak_ptr<BullsPower> IndicatorStorage::getBullsPowerData(const std::string& symbol, const int timeframe,
	const int price_type, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<BullsPower> bp)
	{
		return bp.get()->getSymbol() == current_symbol &&
			   bp.get()->getTimeframe() == current_timeframe &&
			   bp.get()->getPriceType() == price_type &&
			   bp.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_bulls_power_indicators.cbegin(), m_bulls_power_indicators.cend(), lambda);

	if (indicator == m_bulls_power_indicators.cend())
	{
		auto ema_data_ = getEmaData(current_symbol, current_timeframe, period, price_type);
		std::shared_ptr<BullsPower> new_indicator{
			new BullsPower{ current_symbol, current_timeframe, period, price_type, ema_data_ }
		};

		m_bulls_power_indicators.push_back(new_indicator);
		indicator = (m_bulls_power_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getForceIndexValue(const std::string& symbol, const int timeframe, const int period,
	const ENUM_MA_METHOD ma_method, const int price_type, const int index)
{
	std::weak_ptr<ForceIndex> indicator = getForceIndexData(symbol, timeframe, period, ma_method, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<ForceIndex> IndicatorStorage::getForceIndexData(const std::string& symbol, const int timeframe,
	const int period, const ENUM_MA_METHOD ma_method, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<ForceIndex> force_index)
	{
		return force_index.get()->getSymbol() == current_symbol &&
			   force_index.get()->getTimeframe() == current_timeframe &&
			   force_index.get()->getPriceType() == price_type &&
			   force_index.get()->getPeriod() == period &&
		       force_index.get()->getMaMethod() == ma_method;
	};

	auto indicator = std::find_if(m_force_index_indicators.cbegin(), m_force_index_indicators.cend(), lambda);

	if (indicator == m_force_index_indicators.cend())
	{
		std::weak_ptr<MovingAverage> moving_average_indicator;
		switch (ma_method)
		{

		case MODE_EMA:
			moving_average_indicator = getEmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMA:
			moving_average_indicator = getSmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_LWMA:
			moving_average_indicator = getWmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMMA:
			moving_average_indicator = getSmmaData(current_symbol, current_timeframe, period, price_type);
			break;

		default:
			break;
		}

		std::shared_ptr<ForceIndex> new_indicator{
			new ForceIndex{ current_symbol, current_timeframe, price_type, ma_method, period, moving_average_indicator }
		};

		m_force_index_indicators.push_back(new_indicator);
		indicator = (m_force_index_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getEnvelopesValue(const std::string& symbol, const int timeframe, const int period,
	const ENUM_MA_METHOD ma_method, const int price_type, const double deviation, int mode, const int index)
{
	std::weak_ptr<Envelopes> indicator = getEnvelopesData(symbol, timeframe, period, ma_method, price_type);

	double result{};

	switch (mode)
	{
		case 0:
			result = 0.0;
			break;

		case 1:
			result = indicator.lock()->getUpperBand(index, deviation);
			break;

		case 2:
			result = indicator.lock()->getLowerBand(index, deviation);
			break;

		default:
			result = 0.0;
			break;
	}

	return result;
}


std::weak_ptr<Envelopes> IndicatorStorage::getEnvelopesData(const std::string& symbol, const int timeframe,
	const int period, const ENUM_MA_METHOD ma_method, const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<Envelopes> env)
	{
		return env.get()->getSymbol() == current_symbol &&
			   env.get()->getTimeframe() == current_timeframe &&
			   env.get()->getPriceType() == price_type &&
			   env.get()->getPeriod() == period &&
			   env.get()->getMaMethod() == ma_method;
	};

	auto indicator = std::find_if(m_envelopes_indicators.cbegin(), m_envelopes_indicators.cend(), lambda);

	if (indicator == m_envelopes_indicators.cend())
	{
		std::weak_ptr<MovingAverage> moving_average_indicator;
		switch (ma_method)
		{

		case MODE_EMA:
			moving_average_indicator = getEmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMA:
			moving_average_indicator = getSmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_LWMA:
			moving_average_indicator = getWmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMMA:
			moving_average_indicator = getSmmaData(current_symbol, current_timeframe, period, price_type);
			break;

		default:
			break;
		}

		std::shared_ptr<Envelopes> new_indicator{
			new Envelopes{ current_symbol, current_timeframe, price_type, ma_method, period, moving_average_indicator }
		};

		m_envelopes_indicators.push_back(new_indicator);
		indicator = (m_envelopes_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getAdValue(const std::string& symbol, const int timeframe, const int index)
{
	std::weak_ptr<AccumulationDistribution> indicator = getAdData(symbol, timeframe);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<AccumulationDistribution> IndicatorStorage::getAdData(const std::string& symbol, const int timeframe)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<AccumulationDistribution> iAD)
	{
		return iAD.get()->getSymbol() == current_symbol &&
			   iAD.get()->getTimeframe() == current_timeframe;
	};

	auto indicator = std::find_if(m_ad_indicators.cbegin(), m_ad_indicators.cend(), lambda);

	if (indicator == m_ad_indicators.cend())
	{
		std::shared_ptr<AccumulationDistribution> new_indicator{
			new AccumulationDistribution{ current_symbol, current_timeframe }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_ad_indicators.push_back(new_indicator);
		indicator = (m_ad_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getMfiValue(const std::string& symbol, const int timeframe, const int period, const int index)
{
	std::weak_ptr<MoneyFlowIndex> indicator = getMfiData(symbol, timeframe, period);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<MoneyFlowIndex> IndicatorStorage::getMfiData(const std::string& symbol, const int timeframe,
	const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<MoneyFlowIndex> iMFI)
	{
		return iMFI.get()->getSymbol() == current_symbol &&
			iMFI.get()->getTimeframe() == current_timeframe &&
			iMFI.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_mfi_indicators.cbegin(), m_mfi_indicators.cend(), lambda);

	if (indicator == m_mfi_indicators.cend())
	{
		std::shared_ptr<MoneyFlowIndex> new_indicator{
			new MoneyFlowIndex{ current_symbol, current_timeframe, period }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_mfi_indicators.push_back(new_indicator);
		indicator = (m_mfi_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getStochasticValue(const std::string& symbol, const int timeframe, const int k_period,
	const int d_period,	const int slowing, const ENUM_MA_METHOD ma_method, const ENUM_STO_PRICE price_field,
	const int mode,	const int index)
{
	std::weak_ptr<Stochastic> indicator = getStochasticData(symbol, timeframe, k_period, d_period, slowing, ma_method,
		price_field);

	double result{};

	switch (mode)
	{
	case 0: // MODE_MAIN
		result = indicator.lock()->getMainValue(index);
		break;

	case 1: // MODE_SIGNAL
		result = indicator.lock()->getSignalValue(index);
		break;

	default:
		result = 0.0;
		break;
	}

	return result;
}

std::weak_ptr<Stochastic> IndicatorStorage::getStochasticData(const std::string& symbol, const int timeframe,
	const int k_period,	const int d_period, const int slowing, const ENUM_MA_METHOD ma_method,
	const ENUM_STO_PRICE price_field)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<Stochastic> iStochastic)
	{
		return iStochastic.get()->getSymbol() == current_symbol &&
			iStochastic.get()->getTimeframe() == current_timeframe &&
			iStochastic.get()->getKPeriod() == k_period &&
			iStochastic.get()->getDPeriod() == d_period &&
			iStochastic.get()->getSlowing() == slowing &&
			iStochastic.get()->getMaMethod() == ma_method &&
			iStochastic.get()->getPriceField() == price_field;
	};

	auto indicator = std::find_if(m_stochastic_indicators.cbegin(), m_stochastic_indicators.cend(), lambda);

	if (indicator == m_stochastic_indicators.cend())
	{
		std::shared_ptr<Stochastic> new_indicator{
			new Stochastic{ current_symbol, current_timeframe, k_period, d_period, slowing, ma_method, price_field }
		};

		m_stochastic_indicators.push_back(new_indicator);
		indicator = (m_stochastic_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getStdDevValue(const std::string& symbol, const int timeframe, const int price_type,
	const ENUM_MA_METHOD ma_method, const int period, int index)
{
	std::weak_ptr<StandardDeviation> indicator = getStdDevData(symbol, timeframe, price_type, ma_method, period);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<StandardDeviation> IndicatorStorage::getStdDevData(const std::string& symbol, const int timeframe,
	const int price_type, const ENUM_MA_METHOD ma_method, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<StandardDeviation> std_dev)
	{
		return std_dev.get()->getSymbol() == current_symbol &&
			   std_dev.get()->getTimeframe() == current_timeframe &&
			   std_dev.get()->getPriceType() == price_type &&
			   std_dev.get()->getPeriod() == period &&
			   std_dev.get()->getMaMethod() == ma_method;
	};

	auto indicator = std::find_if(m_std_dev_indicators.cbegin(), m_std_dev_indicators.cend(), lambda);

	if (indicator == m_std_dev_indicators.cend())
	{
		std::weak_ptr<MovingAverage> moving_average_indicator;
		switch (ma_method)
		{

		case MODE_EMA:
			moving_average_indicator = getEmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMA:
			moving_average_indicator = getSmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_LWMA:
			moving_average_indicator = getWmaData(current_symbol, current_timeframe, period, price_type);
			break;

		case MODE_SMMA:
			moving_average_indicator = getSmmaData(current_symbol, current_timeframe, period, price_type);
			break;

		default:
			break;
		}

		std::shared_ptr<StandardDeviation> new_indicator{
			new StandardDeviation{ current_symbol, current_timeframe, price_type, ma_method, moving_average_indicator }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_std_dev_indicators.push_back(new_indicator);
		indicator = (m_std_dev_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getOnBalanceVolumeValue(const std::string& symbol, const int timeframe, const int price_type,
	const int index)
{
	std::weak_ptr<OnBalanceVolume> indicator = getOnBalanceVolumeData(symbol, timeframe, price_type);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<OnBalanceVolume> IndicatorStorage::getOnBalanceVolumeData(const std::string& symbol, const int timeframe,
	const int price_type)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<OnBalanceVolume> obv)
	{
		return obv.get()->getSymbol() == current_symbol &&
			   obv.get()->getTimeframe() == current_timeframe &&
			   obv.get()->getPriceType() == price_type;
	};

	auto indicator = std::find_if(m_on_balance_volume_indicators.cbegin(), m_on_balance_volume_indicators.cend(), lambda);

	if (indicator == m_on_balance_volume_indicators.cend())
	{
		std::shared_ptr<OnBalanceVolume> new_indicator{
			new OnBalanceVolume{ current_symbol, current_timeframe, price_type }
		};

		m_on_balance_volume_indicators.push_back(new_indicator);
		indicator = (m_on_balance_volume_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getSarValue(const std::string& symbol, const int timeframe, const double step,
	const double maximum, const int index)
{
	std::weak_ptr<ParabolicStopAndReverse> indicator = getSarData(symbol, timeframe, step, maximum);
	return indicator.lock()->getValue(index);
}

std::weak_ptr<ParabolicStopAndReverse> IndicatorStorage::getSarData(const std::string& symbol, const int timeframe,
	const double step, const double maximum)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<ParabolicStopAndReverse> sar)
	{
		return sar.get()->getSymbol() == current_symbol &&
			sar.get()->getTimeframe() == current_timeframe &&
			sar.get()->getStep() == step &&
			sar.get()->getMaximum() == maximum;
	};

	auto indicator = std::find_if(m_sar_indicators.cbegin(), m_sar_indicators.cend(), lambda);

	if (indicator == m_sar_indicators.cend())
	{
		std::shared_ptr<ParabolicStopAndReverse> new_indicator{
			new ParabolicStopAndReverse{ current_symbol, current_timeframe, step, maximum }
		};

		m_sar_indicators.push_back(new_indicator);
		indicator = (m_sar_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getBandsValue(const std::string& symbol, int timeframe, const int period, const double deviation,
	const int price_type, const int mode, int index)
{
	std::weak_ptr<BollingerBands> indicator = getBandsData(symbol, timeframe, price_type, period);

	switch (mode)
	{
	case 0:
		return indicator.lock()->getMainValue(index);

	case 1:
		return indicator.lock()->getDeviationValue(deviation, 1, index);

	case 2:
		return indicator.lock()->getDeviationValue(deviation, 2, index);

	default:
		return 0.0;
	}
}

std::weak_ptr<BollingerBands> IndicatorStorage::getBandsData(const std::string& symbol, int timeframe,
	const int price_type, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<BollingerBands> bands)
	{
		return bands.get()->getSymbol() == current_symbol &&
			bands.get()->getTimeframe() == current_timeframe &&
			bands.get()->getPriceType() == price_type &&
			bands.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_bands_indicators.cbegin(), m_bands_indicators.cend(), lambda);

	if (indicator == m_bands_indicators.cend())
	{
		auto sma_data = getSmaData(current_symbol, current_timeframe, period, price_type);
		auto std_deviation_data = getStdDevData(current_symbol, current_timeframe, price_type, MODE_SMA, period);
		std::shared_ptr<BollingerBands> new_indicator{
			new BollingerBands{ current_symbol, current_timeframe, price_type, sma_data, std_deviation_data }
		};

		m_bands_indicators.push_back(new_indicator);
		indicator = (m_bands_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getAcValue(const std::string& symbol, int timeframe, int index)
{
	std::weak_ptr<AcceleratorOscillator> indicator = getAcData(symbol, timeframe);

	return indicator.lock()->getValue(index);
}

std::weak_ptr<AcceleratorOscillator> IndicatorStorage::getAcData(const std::string& symbol, int timeframe)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<AcceleratorOscillator> ac)
	{
		return ac.get()->getSymbol() == current_symbol &&
			ac.get()->getTimeframe() == current_timeframe;
	};

	auto indicator = std::find_if(m_ac_indicators.cbegin(), m_ac_indicators.cend(), lambda);

	if(indicator == m_ac_indicators.cend())
	{
		auto ao_data = getAoData(current_symbol, current_timeframe);
		std::shared_ptr<AcceleratorOscillator> new_indicator{
			new AcceleratorOscillator{ current_symbol, current_timeframe, ao_data }
		};

		m_ac_indicators.push_back(new_indicator);
		indicator = (m_ac_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getDeMarkerValue(const std::string& symbol, int timeframe, int period, int index)
{
	std::weak_ptr<DeMarker> indicator = getDeMarkerData(symbol, timeframe, period);

	return indicator.lock()->getValue(index);
}

std::weak_ptr<DeMarker> IndicatorStorage::getDeMarkerData(const std::string& symbol, int timeframe, int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<DeMarker> dema)
	{
		return dema.get()->getSymbol() == current_symbol &&
			dema.get()->getTimeframe() == current_timeframe &&
			dema.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_de_marker_indicators.cbegin(), m_de_marker_indicators.cend(), lambda);

	if(indicator == m_de_marker_indicators.cend())
	{
		std::shared_ptr<DeMarker> new_indicator{
			new DeMarker{ current_symbol, current_timeframe, period }
		};

		m_de_marker_indicators.push_back(new_indicator);
		indicator = (m_de_marker_indicators.cend() - 1);
	}

	return *indicator;
}


double IndicatorStorage::getWprValue(const std::string& symbol, int timeframe, int period, int index)
{
	std::weak_ptr<LarryWilliamsPercentRange> indicator = getWprData(symbol, timeframe, period);

	return indicator.lock()->getValue(index);
}

std::weak_ptr<LarryWilliamsPercentRange> IndicatorStorage::getWprData(const std::string& symbol, int timeframe, int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<LarryWilliamsPercentRange> wpr)
	{
		return wpr.get()->getSymbol() == current_symbol &&
			   wpr.get()->getTimeframe() == current_timeframe &&
			   wpr.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_wpr_indicators.cbegin(), m_wpr_indicators.cend(), lambda);

	if (indicator == m_wpr_indicators.cend())
	{
		std::shared_ptr<LarryWilliamsPercentRange> new_indicator{
			new LarryWilliamsPercentRange{ current_symbol, current_timeframe, period }
		};

		m_wpr_indicators.push_back(new_indicator);
		indicator = (m_wpr_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getAdxValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
	const int mode, const int index)
{
	std::weak_ptr<AverageDirectionalIndex> indicator = getAdxData(symbol, timeframe, price_type, period);

	switch (mode)
	{
	case 0:
		return indicator.lock()->getMainValue(index);

	case 1:
		return indicator.lock()->getPlusDiValue(index);

	case 2:
		return indicator.lock()->getMinusDiValue(index);

	default:
		return 0.0;
	}
}

std::weak_ptr<AverageDirectionalIndex> IndicatorStorage::getAdxData(const std::string& symbol,
	const int timeframe, const int price_type, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<AverageDirectionalIndex> adx)
	{
		return adx.get()->getSymbol() == current_symbol &&
			adx.get()->getTimeframe() == current_timeframe &&
			adx.get()->getPriceType() == price_type &&
			adx.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_adx_indicators.cbegin(), m_adx_indicators.cend(), lambda);

	if (indicator == m_adx_indicators.cend())
	{
		std::shared_ptr<AverageDirectionalIndex> new_indicator{
			new AverageDirectionalIndex{ current_symbol, current_timeframe, price_type, period }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_adx_indicators.push_back(new_indicator);
		indicator = (m_adx_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getRviValue(const std::string& symbol, const int timeframe, const int period,
	const int mode, const int index)
{
	std::weak_ptr<RelativeVigorIndex> indicator = getRviData(symbol, timeframe, period);

	switch (mode)
	{
	case 0:
		return indicator.lock()->getMainValue(index);

	case 1:
		return indicator.lock()->getSignalValue(index);

	default:
		return 0.0;
	}
}

std::weak_ptr<RelativeVigorIndex> IndicatorStorage::getRviData(const std::string& symbol, const int timeframe, const int period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<RelativeVigorIndex> rvi)
	{
		return rvi.get()->getSymbol() == current_symbol &&
			rvi.get()->getTimeframe() == current_timeframe &&
			rvi.get()->getPeriod() == period;
	};

	auto indicator = std::find_if(m_rvi_indicators.cbegin(), m_rvi_indicators.cend(), lambda);

	if (indicator == m_rvi_indicators.cend())
	{
		std::shared_ptr<RelativeVigorIndex> new_indicator{
			new RelativeVigorIndex{ current_symbol, current_timeframe, period }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_rvi_indicators.push_back(new_indicator);
		indicator = (m_rvi_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getIchimokuValue(const std::string& symbol, const int timeframe,
	const int tenkan_sen_period, const int kijun_sen_period, const int senkou_span_b_period, const int mode,
	const int index)
{
	std::weak_ptr<IchimokuKinkoHyo> indicator = getIchimokuData(symbol, timeframe, tenkan_sen_period,
		kijun_sen_period, senkou_span_b_period);

	switch (mode)
	{
	case MODE_TENKANSEN:
		return indicator.lock()->getTenkanSenValue(index);

	case MODE_KIJUNSEN:
		return indicator.lock()->getKijunSenValue(index);

	case MODE_CHIKOUSPAN:
		return indicator.lock()->getChinkouSpanValue(index);

	case MODE_SENKOUSPANA:
		return indicator.lock()->getSenkouSpanAValue(index);

	case MODE_SENKOUSPANB:
		return indicator.lock()->getSenkouSpanBValue(index);

	default:
		return 0.0;
	}
}

std::weak_ptr<IchimokuKinkoHyo> IndicatorStorage::getIchimokuData(const std::string& symbol,
	const int timeframe, const int tenkan_sen_period, const int kijun_sen_period, const int senkou_span_b_period)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<IchimokuKinkoHyo> ichimoku)
	{
		return ichimoku.get()->getSymbol() == current_symbol &&
			ichimoku.get()->getTimeframe() == current_timeframe &&
			ichimoku.get()->getTenkanSenPeriod() == tenkan_sen_period &&
			ichimoku.get()->getKijunSenPeriod() == kijun_sen_period &&
			ichimoku.get()->getSenkouSpanPeriod() == senkou_span_b_period;
	};

	auto indicator = std::find_if(m_ichimoku_indicators.cbegin(), m_ichimoku_indicators.cend(),
		lambda);

	if (indicator == m_ichimoku_indicators.cend())
	{
		std::shared_ptr<IchimokuKinkoHyo> new_indicator{
			new IchimokuKinkoHyo{ current_symbol, current_timeframe, tenkan_sen_period, kijun_sen_period,
			    senkou_span_b_period }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_ichimoku_indicators.push_back(new_indicator);
		indicator = (m_ichimoku_indicators.cend() - 1);
	}

	return *indicator;
}

double IndicatorStorage::getFractalsValue(const std::string& symbol, const int timeframe, const int mode,
	const int index)
{
	std::weak_ptr<Fractals> indicator = getFractalsData(symbol, timeframe);

	switch (mode)
	{
	case MODE_UPPER:
		return indicator.lock()->getUpperValue(index);

	case MODE_LOWER:
		return indicator.lock()->getLowerValue(index);

	default:
		return 0.0;
	}
}

std::weak_ptr<Fractals> IndicatorStorage::getFractalsData(const std::string& symbol, const int timeframe)
{
	std::string current_symbol = getValidSymbol(symbol);
	int current_timeframe = getValidTimeframe(timeframe);

	const auto lambda = [&](std::shared_ptr<Fractals> fractals)
	{
		return fractals.get()->getSymbol() == current_symbol &&
			fractals.get()->getTimeframe() == current_timeframe;
	};

	auto indicator = std::find_if(m_fractals_indicators.cbegin(), m_fractals_indicators.cend(), lambda);

	if (indicator == m_fractals_indicators.cend())
	{
		std::shared_ptr<Fractals> new_indicator{
			new Fractals{ current_symbol, current_timeframe }
		};

		new_indicator->update();
		m_updatable_indcators.push_back(new_indicator);

		m_fractals_indicators.push_back(new_indicator);
		indicator = (m_fractals_indicators.cend() - 1);
	}

	return *indicator;
}
