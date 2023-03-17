#include<iostream>

using namespace std;

class Temperatura {
    int minima, maxima, actual;
public:
    Temperatura(int min, int max, int act){ minima = min; maxima = max; actual = act; }
    friend int temperaturaMedia(Temperatura t1, Temperatura t2);
    // puede acceder a los atributos privados, pero es como una funcion aparte
};

int temperaturaMedia(Temperatura t1, Temperatura t2)
{
    int pro =(t1.actual + t2.actual)/2;
    return pro;
}

int main()
{
    Temperatura temperatura1(10, 20, 15);
    Temperatura temperatura2(12, 25, 17);
    cout << "La temperatura promedio de las temperaturas actuales es: ";
    cout << temperaturaMedia(temperatura1, temperatura2);
    // lo puede usar como funcion global
    return 0;
}