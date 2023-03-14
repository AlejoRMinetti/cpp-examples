#include <iostream>

using namespace std;

class ListaGenericaOrdenada {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;
public:
    ListaGenericaOrdenada();
    ~ListaGenericaOrdenada();    
    void insertar(int x);
    void imprimir();
};

ListaGenericaOrdenada::ListaGenericaOrdenada()
{
    raiz = NULL;
}

ListaGenericaOrdenada::~ListaGenericaOrdenada()
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

void ListaGenericaOrdenada::insertar(int x)
{
    Nodo *nuevo = new Nodo();
    nuevo->info = x;
    if (raiz == NULL) 
    {
        raiz = nuevo;
    }
    else 
    {
        if (x < raiz->info) 
        {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
        else 
        {
            Nodo *reco = raiz;
            Nodo *atras = raiz;
            while (x >= reco->info && reco->sig != NULL) 
            {
                atras = reco;
                reco = reco->sig;
            }
            if (x >= reco->info) 
            {
                reco->sig = nuevo;
            }
            else
            {
                nuevo->sig = reco;
                atras->sig = nuevo;
            }
        }
    }
}

void ListaGenericaOrdenada::imprimir()
{
    Nodo *reco = raiz;
    cout << "Listado completo.\n";
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}


int main()
{
    ListaGenericaOrdenada *lista = new ListaGenericaOrdenada();
    lista->insertar(10);
    lista->insertar(5);
    lista->insertar(7);
    lista->insertar(50);
    lista->imprimir();
    delete lista;
    return 0;
}