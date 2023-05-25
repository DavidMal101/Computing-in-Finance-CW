#include "Vector_Header.h";

int main() {


	std::cout << "Test 1: initializing vectors:" << std::endl << std::endl;;
	std::cout << "Initialising an empty vector..." << std::endl;
	Vector vec;
	std::cout << "The size of the initialized vector is: " << vec.size() << std::endl;
	std::cout << "Trying to access the first element of the vector..." << std::endl;
	try {
		vec[0] = 1;
	}
	catch (std::out_of_range& err) {
		std::cerr << err.what() << std::endl;
	}
	
	//do try catch for array with non-int initialization


	std::cout << "Initialising a vector of zeros of size 10..." << std::endl;
	Vector vec1(10);
	std::cout << "The vector has elements: " <<std::endl;
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << std::endl;;
	}
	std::cout << "The size of the vector is: " << vec1.size() << std::endl;

	std::cout << "Trying to set a negative length..." << std::endl;
	try {
		Vector vec_test(-3);
	}
	catch(std::bad_alloc& err){
		std::cerr << err.what() << std::endl;
	}

	std::cout << "Initializing a vector by an array..." << std::endl;
	double arr[4] = { 3,4,5,71 };
	double* arrptr = arr;
	Vector vec2 = Vector(sizeof(arr)/sizeof(double), arrptr);

	std::cout << "The vector has elements: " << std::endl;
	for (int i = 0; i < vec2.size(); i++) {
		std::cout << vec2[i] << std::endl;
	}
	std::cout << "And size: " << vec2.size() <<std::endl;

	std::cout << "Initializing a vector by the copy constructor using the previous vector..." << std::endl;
	//copy constructor
	
	Vector vec3(vec2);
	std::cout << "The vector has elements: " << std::endl;
	for (int i = 0; i < vec3.size(); i++) {
		std::cout << vec3[i] << std::endl;
	}
	std::cout << "And size: " << vec3.size()<<std::endl;
	
	std::cout << "Rewriting the first element of the copy to 20..." << std::endl;
	vec3[0] = 20;
	std::cout << "The copy now has first element: " << vec3[0] << std::endl;
	std::cout << "The original has first element: " << vec2[0] << std::endl;

	std::cout << std::endl;
	std::cout << "Test 2: Operators:" << std::endl;

	//assignment operator
	std::cout << "Assigning vector 2 to vector 1 using =..." << std::endl;
	vec1 = vec2;
	std::cout << "Vector 1 now has elements: " << std::endl;
	for (int i = 0; i < vec2.size(); i++) {
		std::cout << vec2[i] << std::endl;
	}
	std::cout << "And size: " << vec2.size() << std::endl;

	std::cout << "Changing the last element in vector 2 to -3..." << std::endl;
	vec2[vec2.size() - 1] = -3;
	std::cout << "Vector 1's last element is now: " << vec1[vec1.size()-1] << std::endl;
	std::cout << "Vector 2's last element is now: " << vec2[vec2.size() - 1] << std::endl;
	std::cout << "So we are only using a copy of vector 2, not vector 2 directly" << std::endl;

	//i'th element 

	std::cout << "Accessing the i'th element of the vector using []..." << std::endl;
	std::cout << "Printing the first and last element of vector 2" << std::endl;
	std::cout << vec2[0] << " and " << vec2[vec2.size() - 1] << std::endl;

	std::cout << "Testing out of range indices..." << std::endl;
	std::cout << "Negative index..." << std::endl;
	try {
		std::cout << vec1[-2] << std::endl;
	}
	catch (std::out_of_range& err) {
		std::cerr << err.what() << std::endl;
	}
	std::cout << "Index beyond vector size..." << std::endl;
	try {
		vec1[vec1.size()] = 16;
	}
	catch (std::out_of_range& err) {
		std::cerr << err.what() << std::endl;
	}

	//with a const vector
	std::cout << "Testing with a const vector..." << std::endl;
	const Vector constvec = Vector(sizeof(arr) / sizeof(double), arrptr);
	std::cout << "The vector has elements:" << std::endl;

	for (int i = 0; i < constvec.size(); i++) {
		std::cout << constvec[i] << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Test 3: shape methods:" << std::endl;
	//size
	std::cout << "Checking size is correct..." << std::endl;
	std::cout << "Initializing a new vector: of length 10..." << std::endl;
	Vector vec4(10);
	std::cout << "Vector has size: " << vec4.size() << std::endl;

	//resize
	std::cout << "Testing resize..." << std::endl;
	std::cout << "resize vector 1 to 10, the current size is " << vec1.size() << std::endl;
	vec1.resize(10);
	std::cout << "The vector now has elements:" << std::endl;
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << std::endl;
	}
	std::cout <<"And size: "<< vec1.size() << std::endl;

	std::cout << "Try setting the vector length to be negative..." << std::endl;
	try {
		vec1.resize(-2);
	}
	catch(std::invalid_argument& err) {
		std::cerr << err.what() << std::endl;
	}


	//assign

	std::cout << "Testing assign..." << std::endl;
	std::cout << "resize vector 2 to size 5 and assign constant value 5" << std::endl;
	vec2.assign(5, 5);
	std::cout << "The vector now has elements:" << std::endl;
	for (int i = 0; i < vec2.size(); i++) {
		std::cout << vec2[i] << std::endl;
	}
	std::cout << "And size: " << vec2.size() << std::endl;

	std::cout << "Now try assigning with a negative size..." << std::endl;
	try {
		vec2.assign(-4, 5);
	}
	catch (std::invalid_argument& err) {
		std::cerr << err.what() << std::endl;
	}
	return 0;
}