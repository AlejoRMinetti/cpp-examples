#include<iostream>

using namespace std;

class Temperatura {
    int minima;
    int maxima;
    int actual;
public:
    Temperatura(int min, int max, int act);
    inline int rango() // metodo inline, se puede agregar inline (opcional)
    {
        int valor = maxima - minima;
        return valor;
    }
    void imprimir();
};
// metodos inline: mas rapidos, ahorrar la demora del llamado a funcion,
// pero ocupan mas espacion en memoria de codigo

Temperatura::Temperatura(int min, int max, int act)
{
    minima = min;
    maxima = max;
    actual = act;
}

void Temperatura::imprimir()
{
    cout << "Minima:" << minima << "\n";
    cout << "Maxima:" << maxima << "\n";
    cout << "Actual:" << actual << "\n";
}


int main()
{
    Temperatura temperatura1(5,25,17);
    cout << "Rango de variacion de temperaturas:" << temperatura1.rango()<<"\n\n";
    temperatura1.imprimir();
    return 0;
}