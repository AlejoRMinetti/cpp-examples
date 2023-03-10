// C++ program to demonstrate how default arguments
// and virtual function are used together
// https://www.geeksforgeeks.org/default-arguments-and-virtual-function-in-cpp/
#include <iostream>
using namespace std;

// Initialization of base class
class Base {
public:
	// Initialization of virtual function
	virtual void fun(int x = 0)
	{
		cout << "Base::fun(), x = " << x << endl;
	}
};

// Initialization of Derived class
class Derived : public Base {
public:
	// NOTE this virtual function will take an argument
	// But haven't initialized yet
	virtual void fun(int x)
	{
		cout << "Derived::fun(), x = " << x << endl;
	}
};

// Driver Code
int main()
{
	Derived d1; // Constructor

	// Base class pointer which will
	// Edit value in memory location of
	// Derived class constructor
	Base* bp = &d1;

	bp->fun(); // Calling a derived class member function

	return 0; // Returning 0 means the program
			// Executed successfully
}
