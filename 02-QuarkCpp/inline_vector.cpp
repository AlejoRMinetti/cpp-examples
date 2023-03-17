#include<iostream>

using namespace std;

class Vector {
    int vec[5];
public:
    void cargar();
    void imprimir();
    int sumaPrimeroUltimo() { return vec[0] + vec[4]; }
};

void Vector::cargar()
{
    for (int f = 0; f < 5; f++)
    {
        cout << "Ingrese elemento:";
        cin >> vec[f];
    }
}

void Vector::imprimir()
{
    for (int f = 0; f < 5; f++)
    {
        cout << vec[f] << "-";
    }
    cout << "\n";
}


int main()
{
    Vector vec1;
    vec1.cargar();
    vec1.imprimir();
    cout <<"Suma de la primer y ultima componente: "<<vec1.sumaPrimeroUltimo();
    return 0;
}