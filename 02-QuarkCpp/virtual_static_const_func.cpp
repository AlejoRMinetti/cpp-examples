// CPP Program to demonstrate Virtual member functions
// cannot be static
// https://www.geeksforgeeks.org/can-static-functions-be-virtual-in-cpp/
#include <iostream>

using namespace std;

class Test {
public:
	/*virtual */static void fun() {} //error: member ‘fun’ cannot be declared both virtual and static
	/*static */void fun2() const {} //error: static member function ‘static void Test::fun()’ cannot have cv-qualifier
};
