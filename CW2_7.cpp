#include "Call_header.h"

int main(){
	double t = 1. / 4.;
	double K = 95;
	double S = 100;
	double sigma = 0.5;
	double r = 0.1;

	std::cout << "The call price is: " << call_price(S, K, sigma, t, r) << std::endl;
}