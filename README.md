# The Binomial Options Pricing Model

An implementation of the binomial options pricing model, formalized by Cox, Ross and Rubinstein from the paper ["Option pricing: A simplified approach."](https://citeseerx.ist.psu.edu/viewdoc/download;jsessionid=99A50E0DAC1766A693E68CB029ADAE07?doi=10.1.1.379.7582&rep=rep1&type=pdf), for the valuation of American call and put options.

## Description

The binomial options pricing model traces the evolution of an options underlying financial instrument in discrete time, through the use of a binomial tree. Each node in the tree represents the value of the option and a possible price of the underlying instrument at a given point in time. The general structure of a binomial tree is given below:

<p align="center"><img src="https://www.goddardconsulting.ca/image-files/binomial_MultiStepLattice.gif"></p>

Option valuation using this method is described as follows:

1. **Generation of binomial price tree**\
At each interval, it is assumed that the price of the underlying instrument, ![](images/s0.png), will move up or down by a specific factor, ![](images/uequals.png) or ![](images/dequals.png), respectively. Therefore, the spot price, ![](images/sn.png), of the underlying instrument at the ![](images/nth.png) period can be calculated directly via ![](images/snequals.png). Where ![](images/volatility.png) represents the implied volatility of the underlying instrument, ![](images/dt.png) represents the time duration of a step and ![](images/i.png) and ![](images/j.png) denote the number of times the price of the underlying instrument has moved up or down, respectively.


2. **Valuation of option at each final node**\
At each final node of the binomial tree (i.e. at expiration of the option), the option value is simply its intrinsic value:
- ![](images/call.png), for a call option.
- ![](images/put.png), for a put option.\
Where ![](images/k.png) is the strike price and ![](images/sn.png) is the spot price of the underlying asset at the the ![](images/nth.png) period.

3. **Sequential valuation of option at each preceding node**\

