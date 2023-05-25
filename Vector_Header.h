#pragma once
#include <iostream>
#include <stdexcept>

class Vector {
private:
	int nn; //size of array; upper index is nn-1
	double* v;

public:
	Vector(); //empty
	explicit Vector(int n); //zero based array
	Vector(int n, double a); //initialize to constant value
	Vector(int n, const double* a); //initialize to array
	Vector(const Vector& rhs);//copy constructor
	Vector& operator=(const Vector& rhs); //assignment
	inline double& operator[](const int i); //i'th element
	inline const double& operator[](const int i) const;
	inline int size() const;
	void resize(int newn); //resize contents not preserved
	void assign(int newn, double a); //resize and assign a constant value
	~Vector();

};

inline double& Vector::operator[](const int i) { //i'th element
	if (i < 0 || i >= this->size()) {
		throw std::out_of_range("Outside the range of the vector");
	}
	else return v[i];
}

inline const double& Vector::operator[](const int i) const {
	std::cout << "const operator called" << std::endl;
	if (i < 0 || i >= this->size()) {
		throw std::out_of_range("Outside the range of the vector");
	}
	else return v[i];

}

inline int Vector::size() const {
	return nn;
}