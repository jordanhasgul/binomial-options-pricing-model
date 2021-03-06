# The Binomial Options Pricing Model
An implementation of the binomial options pricing model, formalized by Cox, Ross and Rubinstein from the paper ["Option pricing: A simplified approach."](https://citeseerx.ist.psu.edu/viewdoc/download;jsessionid=99A50E0DAC1766A693E68CB029ADAE07?doi=10.1.1.379.7582&rep=rep1&type=pdf), for the valuation of American call and put options.

## Description

The binomial options pricing model traces the evolution of an options underlying financial instrument in discrete time, through the use of a binomial lattice. Each node in the lattice represents the value of the option and a possible price of the underlying instrument at a given point in time. The general structure of a binomial lattice is given below:

<p align="center"><img src="https://www.goddardconsulting.ca/image-files/binomial_MultiStepLattice.gif"></p>

Option valuation using this method is described as follows:

1. **Generation of binomial price lattice**\
At each interval, it is assumed that the price of the underlying instrument, ![](images/s0.png), will move up or down by a specific factor, ![](images/uequals.png) or ![](images/dequals.png), respectively. Where ![](images/volatility.png) represents the implied volatility of the underlying instrument and ![](images/dt.png) represents the time duration of an interval.\
\
The spot price, ![](images/sn.png), of the underlying instrument at the ![](images/nth.png) period is dependent on the number of times the price of the underlying instrument has moved up or down, denoted by ![](images/i.png) and ![](images/j.png) respectively. Therefore, ![](images/sn.png) can be calculated directly via ![](images/snequals.png). 

2. **Valuation of option at each final node**\
At each final node of the binomial lattice (i.e. at expiration of the option), the option value is simply its intrinsic value:\
&nbsp;&nbsp;&nbsp;&nbsp;![](images/call.png), for a call option.\
&nbsp;&nbsp;&nbsp;&nbsp;![](images/put.png), for a put option.\
Where ![](images/k.png) is the strike price and ![](images/sn.png) is the spot price of the underlying asset at the the ![](images/nth.png) period.

3. **Sequential valuation of option at each preceding node**\
Starting at the penultimate node and working back to the root node, the option value is computed to be the greater of the expectation and intrinsic values at the node. The expectation value is given by the following formula: <p align="center"><img src="images/vequals.png"></p>\
Where ![](images/vnt.png) is value of the option at the ![](images/nth.png) node at time interval ![](images/t.png), ![](images/r.png) is the risk-free rate and ![](images/p.png) is the probability that the price of the underlying instrument moves up.



