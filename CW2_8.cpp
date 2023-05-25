#include "Q8Header.h"

int main() {

	BlackScholesFunctor call(0.25, 95., 100., 0.1);
	double callPrice = 13.6953;
	double epsilon = 1e-10;
	double implied_volatility=interval_bisection(callPrice, 0, 1, epsilon, call);
	std::cout << "The implied volatility is :" << implied_volatility << std::endl;
}