#include<iostream>

using namespace std;

class Vector {
    static const int tamano=5;
    int vec[tamano];
public:
    void cargar();
    void imprimir();
};

void Vector::cargar()
{
    for(int f=0;f<tamano;f++)
    {
        cout << "Ingrese elemento: ";
        cin >> vec[f];
    }
}

void Vector::imprimir()
{
    for(int f=0;f<tamano;f++)
    {
        cout << vec[f] << "-";
    }
}

int main()
{
    Vector vec1;
    vec1.cargar();
    vec1.imprimir();
    return 0;
}