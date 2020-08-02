#pragma once

enum class OptionType : bool
{
	CALL_OPTION = 0,
	PUT_OPTION = 1
};

class Option
{
private:
	OptionType m_type;

	double m_spotPrice, m_strikePrice;
	double m_volatility; 
	double m_riskFreeRate; 
	double m_dividendYield;
	double m_timeToExpiration; 

public:
	Option(const OptionType& p_type, const double& p_spotPrice, const double& p_strikePrice, const double& p_volatility, const double& p_riskFreeRate, const double& p_dividendYield, const double& p_timeToExpiration)
		: m_type(p_type), m_spotPrice(p_spotPrice), m_strikePrice(p_strikePrice), m_volatility(p_volatility), m_riskFreeRate(p_riskFreeRate), m_dividendYield(p_dividendYield), m_timeToExpiration(p_timeToExpiration) {}

	const OptionType& getOptionType() const { return m_type; }

	const double& getSpotPrice() const { return m_spotPrice; }
	const double& getStrikePrice() const { return m_strikePrice; }
	const double& getVolatility() const { return m_volatility; }
	const double& getRiskFreeRate() const { return m_riskFreeRate; }
	const double& getDividendYield() const { return m_dividendYield; }
	const double& getTimeToExpiration() const { return m_timeToExpiration; }
};