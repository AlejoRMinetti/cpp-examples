#include<iostream>

using namespace std;

const int inicio=1;
const float altura=1.92f;
const char mensaje1[]="Bienvenido al programa";

int main()
{
    cout << "Constante entera: " << inicio << "\n";
    cout << "Constante flotante: " << altura << "\n";
    cout << "Constante de tipo cadena de caracteres: " << mensaje1 << "\n";
    const int fin=10;
    cout << "Constante local: " << fin;
    return 0;    
}