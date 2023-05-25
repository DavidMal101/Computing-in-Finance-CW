#include <iostream >
int main() {
	std::cout << 25u-50;
}/*By writing u after the int it becomes an unsigned integer, but by subtracting 50 it becomes negative and so is no longeran unsigned int, in other words we get an integer overflow, so that once it becomes negative it starts again at the largestavailable number and works down from there. Max_int=25*/