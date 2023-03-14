#include <iostream>

using namespace std;

class Recursividad {
public:
    void repetir();
};

void Recursividad::repetir()
{
    repetir(); // loop infinito
}

int main()
{
    Recursividad *recu = new Recursividad();
    recu->repetir(); 
    delete recu;
    return 0;
}