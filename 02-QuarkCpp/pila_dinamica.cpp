#include<iostream>

using namespace std;

int main ()
{
  int *p;
  p=new int[5]; // solicitado a la pila dinamica
  // vector en la pila estatica: int p[5]
  for(int f=0;f<5;f++)
  {
    cout <<"Ingrese elemento:";
    cin >>p[f];
  }
  cout <<"contenido del vector:";
  for(int f=0;f<5;f++)
  {
    cout<<p[f]<<"-";
  }
  delete []p; // liberar de la pila dinamica
  // la no devolución del espacio solicitado hará 
  // que nuestra computadora en algún momento se bloquee 
  // por falta de espacio en la memoria ram
  return 0;
}