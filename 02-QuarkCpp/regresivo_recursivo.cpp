#include <iostream>

using namespace std;

class Recursividad
{
public:
    void imprimir(int x);
};

void Recursividad::imprimir(int x)
{
    if (x > 0)
    {
        cout << x << "-";
        imprimir(x - 1); // si esta antes del cout, invierte el orden
    }
    else
    {
        cout << ".-.-.. Boom!";
    }
}

int main()
{
    Recursividad *recu = new Recursividad();
    recu->imprimir(10);
    delete recu;
    return 0;
}
