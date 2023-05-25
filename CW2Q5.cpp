#include <iostream >
class MyClass {
public:
	MyClass(int x);
	const int* get() const;
	int* get();
private:
	int x;
};
MyClass::MyClass(int x) : x(x) {}
const int* MyClass::get() const {
	std::cout << "I am const , x = " << x << std::endl;
	return &x;
}
int* MyClass::get() {
	std::cout << "I am not const , x = " << x << std::endl;
	return &x;
}
int main()
{
	const MyClass a{ 1 };
	MyClass b{ 2 };
	MyClass* c = new MyClass{ 3 };
	const MyClass* d = new MyClass{ 4 };
	const MyClass& e{ a };
	MyClass& f{ b };
	a.get();
	b.get();
	c->get();
	d->get();
	e.get();
	f.get();
	delete d;
	delete c;
}/*since we initialize the object a as const it the object can not call non-const methods within the class, so it is forced touse the const version of get() as this ensures the class will not be changed.When we initialize b we do not require it to be const, so the compiler will use the non-const version of get()c is a pointer to an object of MyClass initialized with the value 3. We did not specify the object as const so it will use thenon-const methodsd is a pointer to a const object initialize with value 4, so the object is const and must use const methods, the pointercan change but the object cannote is a reference to a const object, that is initialized using the compiler's copy constructor, it then has the same value as aand uses const methods as it was declared constf is a reference to an object initialized using the copy constructor with object b, so it receives the same value as bbut uses the non-const methods as we did not specify it to be const*/