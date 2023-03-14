#include <iostream>

using namespace std;

class ListaGenerica {
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };
    Nodo *raiz;
    void imprimir(Nodo *reco);
public:
    ListaGenerica();
    ~ListaGenerica();
    void insertarPrimero(int x);
    void imprimir();
};

ListaGenerica::ListaGenerica()
{
    raiz = NULL;
}

ListaGenerica::~ListaGenerica()
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


void ListaGenerica::insertarPrimero(int x)
{
    Nodo *nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = raiz;
    raiz = nuevo;
}

void ListaGenerica::imprimir()
{
    imprimir(raiz);
}

void ListaGenerica::imprimir(Nodo *reco)
{
    if (reco != NULL) 
    {
        cout<<reco->info << "-";
        imprimir(reco->sig);
    }
}

int main()
{
    ListaGenerica *lg = new ListaGenerica();
    lg->insertarPrimero(10);
    lg->insertarPrimero(7);
    lg->insertarPrimero(4);
    lg->insertarPrimero(9);
    lg->insertarPrimero(5);
    lg->imprimir();
    delete lg;
    return 0;
}