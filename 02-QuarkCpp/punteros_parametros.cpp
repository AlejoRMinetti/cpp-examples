#include<iostream>

using namespace std;

class Vector {
    int vec[5];
public:
    void cargar();
    void retornarMayorMenor(int *pmay, int *pmen);
};

void Vector::cargar()
{
    for (int f = 0; f < 5; f++)
    {
        cout << "Ingrese componente " << f+1 << " : ";
        cin >> vec[f];
    }
}

void Vector::retornarMayorMenor(int *pmay, int *pmen)
{
    *pmay = vec[0];
    *pmen = vec[0];
    for (int f = 1; f < 5; f++)
    {
        if (vec[f]>*pmay)
        {
            *pmay = vec[f];
        }
        else
        {
            if (vec[f]<*pmen)
            {
                *pmen = vec[f];
            }
        }
    }
}


int main()
{
    Vector vector1;
    vector1.cargar();
    int ma, me;
    vector1.retornarMayorMenor(&ma, &me);
    cout << "El elemento mayor del vector es:" << ma << "\n";
    cout << "El elemento menor del vector es:" << me << "\n";
    return 0;
}