#include <iostream >
int main() {
	int i = 5;
	int j = i++;
	int k = ++i;
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "k: " << k << std::endl;
}/*we start with i=5, when we set j=i++ we assign j=5 then increment i by 1, so now i=6 and j=5,in the final line we increment i before assignment, so i=7 and we then assign k=7*/