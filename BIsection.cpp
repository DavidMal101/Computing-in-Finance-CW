
template<typename T>
double interval_bisection(double y_target, double left, double right, double epsilon, T functor) {


	if (left >= right) {
		throw std::invalid_argument("Left end point must be strictly less than right endpoint");
	}


	//define a new function for root finding method
	auto g = [](double y, double x, T functor) {
		return y - functor(x);
	};

	if (g(y_target, left, functor) * g(y_target, right, functor) > 0) {
		std::cout << "Require points above and below the target value when evaluated" << std::endl;
		return EXIT_FAILURE;
	}

	int N = 1;
	while (N < 5000) {
		double c = (left + right) / 2.; //new midpoint
		if (g(y_target, c, functor) == 0 || (right - left) / 2 < epsilon) {
			return c;
		}
		N++;
		//update left or right end points
		if (g(y_target, c, functor) * g(y_target, left, functor) > 0) {
			left = c;
		}
		else { right = c; }
	}
	std::cout << "Method failed" << std::endl;
	return EXIT_FAILURE;
}