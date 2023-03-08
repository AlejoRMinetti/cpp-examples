#include<iostream>

using namespace std;

void strcpy_s(char * vec, int lenght, const char * string){
    for( int i=0; i< lenght; i++){
        vec[i] = string[i];
    }
    return;
}

int main()
{
    char cad[5];
    strcpy_s(cad, 5, "Sol");
    char *pc;
    pc = cad;
    cout << pc;        //imprime Sol
    cout << "\n";
    pc++;
    cout << pc;        //imprime ol
    cout << "\n";
    pc++;
    cout << pc;        //imprime l
    cout << "\n";
    pc--;
    cout << pc;        //imprime ol
    cout << "\n";
    int x[5] = { 10, 50, 100, 99, 33 };
    int *pe;
    pe = &x[3];
    cout << *pe;    //imprime 99
    cout << "\n";
    pe--;
    cout << *pe;    //imprime 100
    return 0;
}