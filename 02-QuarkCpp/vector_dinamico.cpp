#include<iostream>

using namespace std;

class Vector {
    int *p;
    int tamano;
public:
    Vector();
    void cargar();
    void imprimir();
    ~Vector();
};

Vector::Vector()
{
    cout <<"Cuantos elementos tendra el vector: ";
    cin >>tamano;
    p=new int[tamano];
}

void Vector::cargar()
{
    for(int f=0;f<tamano;f++)
    {
        cout <<"Ingrese elemento: ";
        cin>>p[f];
    }
}

void Vector::imprimir()
{
    cout<<p[0];
    for(int f=1;f<tamano;f++)
    {
        cout<<"-";
        cout<<p[f];
    }
}

Vector::~Vector()
{
    delete []p;
}

int main()
{
    Vector vector1;
    vector1.cargar();
    vector1.imprimir();
    return 0;
}