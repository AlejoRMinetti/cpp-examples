// C++ program to demonstrate
// Run Time Type Identification(RTTI)
// but without virtual function
// https://www.geeksforgeeks.org/rtti-run-time-type-information-in-cpp/
#include <iostream>
using namespace std;

// initialization of base class
class B {
    //added to make it work:
    virtual void fun() {}
};

// initialization of derived class
class D : public B {};

// Driver Code
int main()
{
	B* b = new D; // Base class pointer
	D* d = dynamic_cast<D*>(b); // Derived class pointer
	if (d != NULL)
		cout << "works";
	else
		cout << "cannot cast B* to D*";
	getchar(); // to get the next character
	return 0;
}
