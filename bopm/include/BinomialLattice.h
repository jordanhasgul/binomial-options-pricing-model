#pragma once
#include <cstdint>
#include <cmath>
#include <algorithm>

#include "Option.h"

class BinomialLattice
{
	struct BinomialLatticeNode
	{
		double time;
		double assetPrice, optionValue;
	};

private:
	BinomialLatticeNode** m_tree;
	uint16_t m_timeIntervals;

	Option m_option;

	double m_dt;
	double m_up, m_down;
	double m_probability;
	
private:
	const double& calculateIntrinsicValue(const double& p_spotPrice, const double& p_strikePrice) const;
	const double& calculateExpectationValue(const double& p_optionValueUp, const double& p_optionValueDown) const;

	void createPriceTree();
	void createValueTree();

public:
	BinomialLattice(const uint16_t& p_timeIntervals, const Option& p_option);
	~BinomialLattice();

	const double& computeOptionValue();
};