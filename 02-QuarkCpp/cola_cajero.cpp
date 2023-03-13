#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Cola {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;
    Nodo *fondo;
public:
    Cola();
    ~Cola();
    void insertar(int x);
    int extraer();
    bool vacia();
    int cantidad();
};


Cola::Cola()
{
    raiz = NULL;
    fondo = NULL;
}

Cola::~Cola()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }
}

void Cola::insertar(int x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia()) 
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else 
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int Cola::extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
        Nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else 
        {
            raiz = raiz->sig;
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}

bool Cola::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}

int Cola::cantidad()
{
    Nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}


class CajeroAutomatico {
public:
    void simulacion();
};

void CajeroAutomatico::simulacion()
{
    srand(time(NULL));
    int estado = 0;
    int llegada = rand() % 2 + 2; 
    int salida = -1;
    int cantAtendidas = 0;
    Cola *cola = new Cola();
    for (int minuto = 0; minuto < 600; minuto++) 
    {
        if (llegada == minuto)
        {
            if (estado == 0) 
            {
                estado = 1;
                salida = minuto + 2 + rand() % 3;
            }
            else 
            {
                cola->insertar(minuto);
            }
            llegada = minuto + 2 + rand() % 2;
        }
        if (salida == minuto)
        {
            estado = 0;
            cantAtendidas++;
            if (!cola->vacia()) 
            {
                cola->extraer();
                estado = 1;
                salida = minuto + 2 + rand() % 3;
            }
        }
    }
    cout <<"Atendidos:" <<cantAtendidas <<"\n";
    cout <<"En cola:" <<cola->cantidad() <<"\n";
    cout <<"Minuto llegada:" <<cola->extraer();
    delete cola;
}


int main()
{
    CajeroAutomatico *cajero1 = new CajeroAutomatico();
    cajero1->simulacion();
    delete cajero1;
    return 0;
}