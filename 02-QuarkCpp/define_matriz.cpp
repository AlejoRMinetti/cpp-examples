#include <iostream>

#define FILAS 4
#define COLUMNAS 2

using namespace std;

class Matriz {
    int mat[FILAS][COLUMNAS];
public:
    void cargar();
    void imprimir();
};

void Matriz::cargar()
{
    for(int f=0;f<FILAS;f++)
    {
        for(int c=0;c<COLUMNAS;c++)
        {
            cout<<"Ingrese elemento de la fila "<< f << " columna:" << c << ":";
            cin >> mat[f][c];
        }
    }
}

void Matriz::imprimir()
{
    for(int f=0;f<FILAS;f++)
    {
        for(int c=0;c<COLUMNAS;c++)
        {
            cout << mat[f][c] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Matriz matriz1;
    matriz1.cargar();
    matriz1.imprimir();
    return 0;
}