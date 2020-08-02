# The Binomial Options Pricing Model

An implementation of the binomial options pricing model, formalized by Cox, Ross and Rubinstein from the paper ["Option pricing: A simplified approach."](https://citeseerx.ist.psu.edu/viewdoc/download;jsessionid=99A50E0DAC1766A693E68CB029ADAE07?doi=10.1.1.379.7582&rep=rep1&type=pdf), for the valuation of American call and put options.

## Description

The binomial options pricing model traces the evolution of an options underlying financial instrument in discrete time, through the use of a binomial tree. Each node in the tree represents the value of the option and a possible price of the underlying instrument at a given point in time. The general structure of a binomial tree is given below:

<p align="center"><img src="https://www.goddardconsulting.ca/image-files/binomial_MultiStepLattice.gif"></p>

Option valuation using this method is described as follows:

1. **Generation of binomial price tree**\


2. **Valuation of option at each final node**\


3. **Sequential valuation of option at each preceding node**\

