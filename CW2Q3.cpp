#include <iostream >
void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;	std::cout << "swap1: a: " << a << ", b: " << b << std::endl;
}
void swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	std::cout << "swap2: *a: " << *a << ", *b: " << *b << std::endl;
}
void swap3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "swap3: a: " << a << ", b: " << b << std::endl;
}
int main() {
	int a = 3;
	int b = 5;
	std::cout << "main: a: " << a << ", b: " << b << std::endl;
	swap1(a, b);
	std::cout << "main: a: " << a << ", b: " << b << std::endl;
	swap2(&a, &b);
	std::cout << "main: a: " << a << ", b: " << b << std::endl;
	swap3(a, b);
	std::cout << "main: a: " << a << ", b: " << b << std::endl;
}/*Swap 1 swaps a and b inside the function, but since c++ is call by value by default we are working with copiesof a and b inside the function, so a and b outside the function remain unchangedSwap 2 takes pointers to a and b, so in this case we are accessing the address in memory directly, ie it is pass by referenceso the actual variables a and b are swapped using pointers, so this is also preserved outside of the function so we seethe output of a and b in main have actually been swapped this timeSwap 3 takes references of a and b, in this sense a and b are labels for the address in memory, and the reference of a and b are essentially a second set of labels to the address in memory, so similar to pointers we are accessing directly the addressin memory of a and b so when we swap them inside the function this persists outside of the scope of the function also.*/