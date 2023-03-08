#include<iostream>
#include<string.h>

using namespace std;

void strcopiando(char * vec, int lenght, const char * string){
    for( int i=0; i< lenght; i++){
        vec[i] = string[i];
    }
    return;
}

int main()
{
    int vec[3]; // int y float son de 4 bytes, char 1 byte
    vec[0]=10;
    vec[1]=50;
    vec[2]=100;

/*
        Dir. de Mem.	Contenido	Nombre de variable
        1000		    1004		vec
        1004		    10		    [0]
        1008		    50		    [1]
        1012		    100		    [2]
*/

    char cadena[10];
    // no hay que pasarle &cadena ya que es una direccion de memoria cadena
    strcopiando(cadena, 10, "Hola");
    cout << cadena;	// imprime Hola
    return 0;
}