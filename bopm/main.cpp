#include <iostream>

#include "BinomialLattice.h"

int main()
{
	OptionType optionType;

	double spotPrice, strikePrice;
	double volatility, riskFreeRate, dividendYield;
	double timeToExpiration;
	uint16_t timeIntervals;

	std::cout << "Enter the type of option ('0' = call option '1' = put option): ";
	optionType = (std::cin.get() == '0') ? OptionType::CALL_OPTION : OptionType::PUT_OPTION;

	std::cout << "Enter spot price: ";
	std::cin >> spotPrice;
	std::cout << "Enter strike price: ";
	std::cin >> strikePrice;
	std::cout << "Enter volatility(%) : ";
	std::cin >> volatility;
	std::cout << "Enter risk free rate(%): ";
	std::cin >> riskFreeRate;
	std::cout << "Enter dividend yield(%): ";
	std::cin >> dividendYield;
	std::cout << "Enter time to expiration(in years): ";
	std::cin >> timeToExpiration;

	std::cout << "Enter number of time intervals: ";
	std::cin >> timeIntervals;

	Option option(optionType, spotPrice, strikePrice, volatility, riskFreeRate, dividendYield, timeToExpiration);
	
	BinomialLattice binomialTree(timeIntervals, option);
	std::cout << binomialTree.computeOptionValue();
	return 0;
}