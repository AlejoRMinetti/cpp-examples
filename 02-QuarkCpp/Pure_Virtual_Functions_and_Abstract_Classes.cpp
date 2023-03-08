// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
#include<iostream>
using namespace std;

// An abstract class
class Base
{
int x;
public:
	virtual void fun() = 0;
	int getX() { return x; }
};
//A class is abstract if it has at least one pure virtual function. 

// This class inherits from Base and implements fun()
class Derived: public Base
{
	int y;
public:
	void fun() { cout << "fun() called"; }
};

int main(void)
{
	Derived d;
	d.fun();
    cout << "\n" << d.getX();
	return 0;
}
