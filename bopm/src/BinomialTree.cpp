#include "BinomialTree.h"

BinomialTree::BinomialTree(const uint16_t& p_timeIntervals, const Option& p_option)
	: m_timeIntervals(p_timeIntervals), m_option(p_option)
{
	m_dt = p_option.getTimeToExpiration() / p_timeIntervals;
	m_up = std::exp(p_option.getVolatility() * std::sqrt(m_dt));
	m_down = std::exp(-p_option.getVolatility() * std::sqrt(m_dt));
	m_probability = (std::exp((p_option.getRiskFreeRate() - p_option.getDividendYield()) * m_dt) - m_down) / (m_up - m_down);

	m_tree = new BinomialTreeNode*[m_timeIntervals];
	for (int i = 0; i < m_timeIntervals; ++i)
	{ 
		m_tree[i] = new BinomialTreeNode[i + 1];
	}
}
BinomialTree::~BinomialTree()
{
	for (int i = 0; i < m_timeIntervals; ++i)
	{
		delete[] m_tree[i];
	}

	delete[] m_tree;
}

const double& BinomialTree::calculateIntrinsicValue(const double& p_spotPrice, const double& p_strikePrice) const
{
	return (m_option.getOptionType() == OptionType::CALL_OPTION) ? std::max(p_spotPrice - p_strikePrice, 0.0) : std::max(p_strikePrice - p_spotPrice, 0.0);
}
const double& BinomialTree::calculateExpectationValue(const double& p_optionValueUp, const double& p_optionValueDown) const
{
	return std::exp(-m_option.getRiskFreeRate() * m_dt) * (m_probability * p_optionValueUp + (1 - m_probability) * p_optionValueDown);
}

void BinomialTree::createPriceTree()
{
	double time = 0.0;

	m_tree[0][0] = { time, m_option.getSpotPrice(), 0.0 };
	for (int i = 1; i < m_timeIntervals; ++i)
	{
		time += m_dt;
		for (int j = 0; j <= i; ++j)
		{
			m_tree[i][j] = { time, m_option.getSpotPrice() * std::pow(m_up, j) * std::pow(m_down, i - j), 0.0 };
		}
	}
}
void BinomialTree::createValueTree()
{
	BinomialTreeNode* node;
	for (int j = 0; j < m_timeIntervals; ++j)
	{
		node = &m_tree[m_timeIntervals - 1][j];
		node->optionValue = calculateIntrinsicValue(node->assetPrice, m_option.getStrikePrice());
	}

	for (int i = m_timeIntervals - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			node = &m_tree[i][j];

			double intrinsicValue = calculateIntrinsicValue(node->assetPrice, m_option.getStrikePrice());
			double expectationValue = calculateExpectationValue(m_tree[i + 1][j].optionValue, m_tree[i + 1][j + 1].optionValue);

			node->optionValue = std::max(expectationValue, intrinsicValue);
		}
	}
}

const double& BinomialTree::computeOptionValue()
{
	createPriceTree();
	createValueTree();

	return m_tree[0][0].optionValue;
}
