#pragma once

#include "AcceleratorOscillator.h"
#include "AccumulationDistribution.h"
#include "AverageDirectionalIndex.h"
#include "AverageTrueRange.h"
#include "AwesomeOscillator.h"
#include "BearsPower.h"
#include "BollingerBands.h"
#include "BullsPower.h"
#include "CommodityChannelIndex.h"
#include "DeMarker.h"
#include "Envelopes.h"
#include "ExponentialMovingAverage.h"
#include "ForceIndex.h"
#include "Fractals.h"
#include "IchimokuKinkoHyo.h"
#include "LarryWilliamsPercentRange.h"
#include "Macd.h"
#include "MoneyFlowIndex.h"
#include "MovingAverageOscillator.h"
#include "OnBalanceVolume.h"
#include "ParabolicStopAndReverse.h"
#include "RelativeStrengthIndex.h"
#include "RelativeVigorIndex.h"
#include "SimpleMovingAverage.h"
#include "SmoothedMovingAverage.h"
#include "StandardDeviation.h"
#include "Stochastic.h"
#include "UpdatableIndicator.h"
#include "WeightedMovingAverage.h"

#include "..\Enums.h"
#include "..\MqlEnums.h"
#include "..\IndicatorInterfaceUnit.h"

extern mql4::ENUM_TIMEFRAMES _Period;

class IndicatorStorage final
{
public:
	IndicatorStorage() = default;
	~IndicatorStorage() = default;

	void reset();
	void update();

	std::string getValidSymbol(const std::string& symbol) const;
	int getValidTimeframe(int timeframe) const;
	
	double getEmaValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getSmaValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getWmaValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getSmmaValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getMacdValue(const std::string& symbol, const int timeframe,	const int price_type, const int shortPeriod,
		const int longPeriod, const int signalPeriod, const int mode, const int index);

	double getOsmaValue(const std::string& symbol, const int timeframe, const int price_type, const int shortPeriod,
		const int longPeriod, const int signalPeriod, const int index);

	double getRsiValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

    double getCciValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

    double getAtrValue(const std::string& symbol, int timeframe, int period, int index);

	double getAoValue(const std::string& symbol, int timeframe, int index);

	double getBearsPowerValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getBullsPowerValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int index);

	double getForceIndexValue(const std::string& symbol, const int timeframe, const int period,
		const ENUM_MA_METHOD ma_method, const int price_type, const int index);

	double getEnvelopesValue(const std::string& symbol, const int timeframe, const int period,
		const ENUM_MA_METHOD ma_method, const int price_type, const double deviation, int mode, const int index);

	double getAdValue(const std::string& symbol, const int timeframe, const int index);

	double getMfiValue(const std::string& symbol, const int timeframe, const int period, const int index);

	double getOnBalanceVolumeValue(const std::string& symbol, const int timeframe, const int price_type,
		const int index);

	double getStochasticValue(const std::string& symbol, const int timeframe, const int k_period, const int d_period,
		const int slowing, const ENUM_MA_METHOD ma_method, const ENUM_STO_PRICE price_field,
		const int mode, const int index);

	double getStdDevValue(const std::string& symbol, const int timeframe, const int price_type,
		const ENUM_MA_METHOD ma_method, const int period, int index);

	double getSarValue(const std::string& symbol, const int timeframe, const double step,
		const double maximum, int index);

	double getBandsValue(const std::string& symbol, int timeframe, const int period, const double deviation,
		const int price_type, const int mode, int index);

	double getAcValue(const std::string& symbol, int timeframe, int index);

	double getDeMarkerValue(const std::string& symbol, int timeframe, int period, int index);

	double getWprValue(const std::string& symbol, int timeframe, int period, int index);

	double getAdxValue(const std::string& symbol, const int timeframe, const int period, const int price_type,
		const int mode, const int index);

	double getRviValue(const std::string& symbol, const int timeframe, const int period, const int mode,
		const int index);

	double getIchimokuValue(const std::string& symbol, const int timeframe, const int tenkan_sen_period,
		const int kijun_sen_period,	const int senkou_span_b_period, const int mode, const int index);

    double getFractalsValue(const std::string& symbol, const int timeframe, const int mode, const int index);

private:
	std::vector<std::shared_ptr<UpdatableIndicator>> m_updatable_indcators;

	std::vector<std::shared_ptr<ExponentialMovingAverage>> m_ema_indcators;
	std::vector<std::shared_ptr<SimpleMovingAverage>> m_sma_indicators;
	std::vector<std::shared_ptr<WeightedMovingAverage>> m_wma_indicators;
	std::vector<std::shared_ptr<SmoothedMovingAverage>> m_smma_indicators;
	std::vector<std::shared_ptr<Macd>> m_macd_indicators;
	std::vector<std::shared_ptr<MovingAverageOscillator>> m_osma_indicators;
	std::vector<std::shared_ptr<RelativeStrengthIndex>> m_rsi_indicators;
    std::vector<std::shared_ptr<CommodityChannelIndex>> m_cci_indicators;
    std::vector<std::shared_ptr<AverageTrueRange>> m_atr_indicators;
	std::vector<std::shared_ptr<AwesomeOscillator>> m_ao_indicators;
	std::vector<std::shared_ptr<BearsPower>> m_bears_power_indicators;
	std::vector<std::shared_ptr<BullsPower>> m_bulls_power_indicators;
	std::vector<std::shared_ptr<ForceIndex>> m_force_index_indicators;
	std::vector<std::shared_ptr<Envelopes>> m_envelopes_indicators;
	std::vector<std::shared_ptr<AccumulationDistribution>> m_ad_indicators;
	std::vector<std::shared_ptr<MoneyFlowIndex>> m_mfi_indicators;
	std::vector<std::shared_ptr<Stochastic>> m_stochastic_indicators;
	std::vector<std::shared_ptr<StandardDeviation>> m_std_dev_indicators;
	std::vector<std::shared_ptr<OnBalanceVolume>> m_on_balance_volume_indicators;
	std::vector<std::shared_ptr<ParabolicStopAndReverse>> m_sar_indicators;
	std::vector<std::shared_ptr<BollingerBands>> m_bands_indicators;
	std::vector<std::shared_ptr<AcceleratorOscillator>> m_ac_indicators;
	std::vector<std::shared_ptr<DeMarker>> m_de_marker_indicators;
	std::vector<std::shared_ptr<LarryWilliamsPercentRange>> m_wpr_indicators;
	std::vector<std::shared_ptr<AverageDirectionalIndex>> m_adx_indicators;
	std::vector<std::shared_ptr<RelativeVigorIndex>> m_rvi_indicators;
	std::vector<std::shared_ptr<IchimokuKinkoHyo>> m_ichimoku_indicators;
	std::vector<std::shared_ptr<Fractals>> m_fractals_indicators;

	std::weak_ptr<ExponentialMovingAverage>	getEmaData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

	std::weak_ptr<SimpleMovingAverage> getSmaData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

	std::weak_ptr<WeightedMovingAverage> getWmaData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

	std::weak_ptr<SmoothedMovingAverage> getSmmaData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

	std::weak_ptr<Macd> getMacdData(const std::string& symbol, const int timeframe, const int price_type,
		const int shortPeriod, const int longPeriod, const int signalPeriod);

	std::weak_ptr<MovingAverageOscillator> getOsmaData(const std::string& symbol, const int timeframe,
		const int price_type, const int shortPeriod, const int longPeriod, const int signalPeriod);

	std::weak_ptr<RelativeStrengthIndex> getRsiData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

    std::weak_ptr<CommodityChannelIndex> getCciData(const std::string& symbol, const int timeframe,
		const int period, const int price_type);

    std::weak_ptr<AverageTrueRange> getAtrData(const std::string& symbol, const int timeframe, const int period);

	std::weak_ptr<AwesomeOscillator> getAoData(const std::string& symbol, const int timeframe);

	std::weak_ptr<BearsPower> getBearsPowerData(const std::string& symbol, const int timeframe, const int price_type,
		const int period);

	std::weak_ptr<BullsPower> getBullsPowerData(const std::string& symbol, const int timeframe, const int price_type,
		const int period);

	std::weak_ptr<ForceIndex> getForceIndexData(const std::string& symbol, const int timeframe, const int period,
		const ENUM_MA_METHOD ma_method, const int price_type);

	std::weak_ptr<Envelopes> getEnvelopesData(const std::string& symbol, const int timeframe, const int period,
		const ENUM_MA_METHOD ma_method, const int price_type);

	std::weak_ptr<AccumulationDistribution> getAdData(const std::string& symbol, const int timeframe);

	std::weak_ptr<OnBalanceVolume> getOnBalanceVolumeData(const std::string& symbol, const int timeframe, 
		const int price_type);
	std::weak_ptr<MoneyFlowIndex> getMfiData(const std::string& symbol, const int timeframe, const int period);

	std::weak_ptr<Stochastic> getStochasticData(const std::string& symbol, const int timeframe, const int k_period,
		const int d_period, const int slowing, const ENUM_MA_METHOD ma_method, const ENUM_STO_PRICE price_field);

	std::weak_ptr<StandardDeviation> getStdDevData(const std::string& symbol, const int timeframe,
		const int price_type, const ENUM_MA_METHOD ma_method, const int period);

	std::weak_ptr<ParabolicStopAndReverse> getSarData(const std::string& symbol, const int timeframe,
		const double step, const double maximum);

	std::weak_ptr<BollingerBands> getBandsData(const std::string& symbol, int timeframe,
		const int price_type, const int period);

	std::weak_ptr<AcceleratorOscillator> getAcData(const std::string& symbol, int timeframe);

	std::weak_ptr<DeMarker> getDeMarkerData(const std::string& symbol, int timeframe, int period);

	std::weak_ptr<LarryWilliamsPercentRange> getWprData(const std::string& symbol, int timeframe, int period);

	std::weak_ptr<AverageDirectionalIndex> getAdxData(const std::string& symbol, const int timeframe, const int price_type,
		const int period);

	std::weak_ptr<RelativeVigorIndex> getRviData(const std::string& symbol, const int timeframe, const int period);

	std::weak_ptr<IchimokuKinkoHyo> getIchimokuData(const std::string& symbol, const int timeframe,
		const int tenkan_sen_period, const int kijun_sen_period, const int senkou_span_b_period);

	std::weak_ptr<Fractals> getFractalsData(const std::string& symbol, const int timeframe);
};


inline std::string IndicatorStorage::getValidSymbol(const std::string& symbol) const
{
	return symbol.empty() || symbol == "0" ? Symbol() : symbol;
}

inline int IndicatorStorage::getValidTimeframe(int timeframe) const
{
	return timeframe == 0 ? (int)_Period : timeframe;
}
