#include <iostream >
class MyClass {
public:
	MyClass(int x) : x(x) {
		std::cout << " constructor called , x = " << this->x << std::endl;
	}
	MyClass(const MyClass& other) : x(other.x) {
		std::cout << "copy constructor called , x = " << x << std::endl;
	}
	MyClass& operator=(const MyClass& other) {
		std::cout << " assignment operator called , x was " << x << " and became " <<
			other.x << std::endl;
		x = other.x;
		return *this;
	}
	~MyClass() {
		std::cout << " destructor called , x = " << this->x << std::endl;
	}
private:
	int x;
};
int main() {
	MyClass a{ 3 };
	MyClass b{ 5 };
	MyClass c{ a };
	c = b;
	a = b;
}

/*
We first construct the object a and initialize the int x to 3

then we construct b and initialize it with 5

when we construct c we pass in the object a, this matches the signature of the copy constructor, so this is called
and initializes the integer in c with the integer in a

When the use the assignment operator with c=b this assigns the x value in c to be the same as in b

We do this again using a=b, since c was only a copy of a, a is not changed so its value is still 3, so it is changed to
5 when we assign it to b.

Finally as we exit the scope of main() the destructor is called for a b and c, all the objects we initialized in this scope.
*/