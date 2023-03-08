// https://www.geeksforgeeks.org/references-in-c/
#include <iostream>
// for vectors:
#include <bits/stdc++.h>
using namespace std;

void swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

struct Student {
	string name;
	string address;
	int rollNo;
};
// If we remove & in below function, a new
// copy of the student object is created.
// We use const to avoid accidental updates
// in the function as the purpose of the function
// is to print s only.
void print(const Student &s)
{
	cout << s.name << " " << s.address << " " << s.rollNo
		<< '\n';
}

int main()
{
    //// References basics:
	int x = 10;

	// ref is a reference to x.
	int& ref = x;

	// Value of x is now changed to 20
	ref = 20;
	cout << "x = " << x << '\n';

	// Value of x is now changed to 30
	x = 30;
	cout << "ref = " << ref << '\n';

    //// Modify the passed parameters in a function
	int a = 2, b = 3;
    swap(a, b);
    cout << a << " " << b;
	cout << '\n';

    //// Avoiding a copy of large structures
    Student me;
    me.name = "Alejo";
    me.address = "Home";
    me.rollNo = 123123;
    print(me);

    //// In For Each Loop to modify all objects
	vector<int> vectNum{ 10, 20, 30, 40 };

	// We can modify elements if we
    // use reference
	for (int& x : vectNum) {
		x = x + 5;
	}

	// Printing elements
	for (int x : vectNum) {
		cout << x << " ";
	}
	cout << '\n';

    //// For Each Loop to avoid the copy of objects
    vector<string> vectStr{ "geeksforgeeks practice",
                         "geeksforgeeks write",
                         "geeksforgeeks ide" };
 
    // We avoid copy of the whole string
    // object by using reference.
    for (const auto& x : vectStr) {
        cout << x << '\n';
    }

    return 0;
}
