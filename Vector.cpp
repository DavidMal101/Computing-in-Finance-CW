#include "Vector_Header.h"

Vector::Vector() : nn(0), v(nullptr) {} //empty constructor

Vector::Vector(int n) : nn(n), v(new double[nn]{0}) {
}

Vector::Vector(int n, double a) : nn(n), v(new double[nn]) {
	for (int i = 0; i < nn; i++) {
		v[i] = a;
	}
}

Vector::Vector(int n, const double* a) :nn(n), v(new double[nn]) {

	for (int i = 0; i < n; i++) {
		v[i] = a[i];
	}
}

Vector::Vector(const Vector& rhs) :nn(rhs.nn), v(new double[nn]) { //Copy Constructor
	for (int i = 0; i < rhs.nn; i++) {
		v[i] = rhs.v[i];
	}
}

Vector& Vector::operator=(const Vector& rhs) { //copy assignment
	
	
	nn = rhs.nn;
	delete[] v;
	v = new double[rhs.nn];
	for (int i = 0; i < rhs.nn; i++) {
		v[i] = rhs.v[i];
	}
	return *this;
	
}

void Vector::resize(int newn) {//resize contents not preserved
	if (newn < 0) {
		throw std::invalid_argument("The vector length cannot be negative");
	}
	else {
		delete[] v;
		nn = newn;
		v = new double[nn] {0};
	}
}

void Vector::assign(int newn, double a) {
	
	this->resize(newn);
	
	for (int i = 0; i < nn; i++) {
		v[i] = a;
	}
}

Vector::~Vector() {
	std::cout << "desctructor called" << std::endl;
	delete[] v;
}