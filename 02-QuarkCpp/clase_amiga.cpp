#include<iostream>

using namespace std;

class Nodo {
    int info;
    Nodo *ant, *sig;
public:
    Nodo(int x){ info = x; };
    friend class ListaGenerica; //tiene acceso a las var privadas
};


class ListaGenerica {
    Nodo *raiz;
public:
    ListaGenerica() { raiz = NULL; };
    ~ListaGenerica();
    void insertarPrimero(int x);
    void imprimir();
};

ListaGenerica::~ListaGenerica()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        // podemos acceder a sig, info y ant por ser clase amiga
        delete bor;
    }
}

void ListaGenerica::insertarPrimero(int x)
{
    Nodo *nuevo = new Nodo(x);
    nuevo->ant = NULL;
    if (raiz == NULL)
    {
        nuevo->sig = NULL;
        raiz = nuevo;
    }
    else
    {
        nuevo->sig = raiz;
        raiz->ant = raiz;
        raiz = nuevo;
    }
}

void ListaGenerica::imprimir()
{
    Nodo *reco = raiz;
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}


int main()
{
    ListaGenerica *lista1 = new ListaGenerica();
    lista1->insertarPrimero(10);
    lista1->insertarPrimero(20);
    lista1->insertarPrimero(5);
    lista1->imprimir();
    delete lista1;
    return 0;
}

/*
Puede haber situaciones donde la clase Nodo 
convenga declararla fuera de la clase ListaGenerica 
y luego otras clases puedan acceder a los atributos 
privados de la misma mediante el modificador friend class.

Las clases amigas deben utilizarse en situaciones especiales 
ya que deteriora el concepto de encapsulamiento de nuestra aplicación.
*/