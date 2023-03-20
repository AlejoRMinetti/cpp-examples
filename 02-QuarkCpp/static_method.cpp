#include<iostream>

using namespace std;

class Prueba {
    static int x1;
public:
    static int retornarX(); // solo puede acceder a atr statics
};

int Prueba::x1 = 20;

int Prueba::retornarX()
{
    return x1;
}

int main()
{
    cout << Prueba::retornarX(); // 20
    return 0;
}