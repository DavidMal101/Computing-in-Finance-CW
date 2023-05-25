#include "Q8Header.h"

BlackScholesFunctor::BlackScholesFunctor(double T, double K, double S, double r) :T(T), K(K), S(S), r(r) {}

double BlackScholesFunctor::operator()(double sigma) const { //returns the call option price for given sigma
	double d1 = (log(S / K) + (r + pow(sigma, 2.) / 2.) * T) / (sigma * sqrt(T));
	double d2 = d1 - sigma * sqrt(T);

	return S * gauss_cdf(d1) - K * exp(-r * T) * gauss_cdf(d2);

}

double gauss_cdf(double x) {
	/*
	The normal cdf evaludated at point x can be shown to be equal to (1+Erf(x/sqrt(2))/2,
	where Erf is the error function
	*/
	return (1. + erf(x / sqrt(2.))) / 2.;
}
