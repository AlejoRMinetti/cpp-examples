// C++ Program to demonstrate a pure virtual destructor
#include <iostream>
using namespace std;

// Initialization of base class
class Base {
public:
	virtual ~Base() = 0;
	// Pure virtual destructor
};

// Initialization of derived class
class Derived : public Base {
public:
	~Derived() { cout << "~Derived() is executed"; }
};

// Driver Code
int main()
{
	// base class pointer which is
	// allocating fresh storage
	// for Derived function object's
	Base* b = new Derived();
	delete b;
	return 0;
}
