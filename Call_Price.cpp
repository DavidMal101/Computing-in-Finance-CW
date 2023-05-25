#include "Call_header.h"

double call_price(double S, double K, double sigma, double t, double r) {

	double d1 = (log(S / K) + (r + pow(sigma, 2.) / 2.) * t) / (sigma * sqrt(t));
	double d2 = d1 - sigma * sqrt(t);

	return S * gauss_cdf(d1) - K * exp(-r * t) * gauss_cdf(d2);
}

double gauss_cdf(double x) {
	/*
	The normal cdf evaludated at point x can be shown to be equal to (1+Erf(x/sqrt(2))/2,
	where Erf is the error function
	*/
	return (1. + erf(x / sqrt(2.))) / 2.;
} 