/* 
 * File:   clases_example.cpp
 * Author: diego
 *
 * Created on 21 de junio de 2022, 14:16
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/**
 * Una clase tiene propiedades (valores) y metodos
 */
class Person {
    // por lo general, las propiedades son privadas (encapsulamiento)
private:
    string name;
    int age;

public:
    // para acceder a las propiedades, se debe utilizar métodos publicos

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    void sayHi() {
        // aquí vamos a mostrar un saludo con los valores que se ingresaron
        cout << "Hola, mi nombre es " << name << " y tengo " << age << " años";
    }

    /**
     * Este es un constructor, parece una funcion pero no tiene tipo, 
     * y tiene el mismo nombre de la clase
     */
    Person() {
        cout << "(Siempre se ejecuta al crear una instancia)\n";
    }
};

/**
 * Esta es una clase Employee que hereda los atributos accesibles
 */
class Employee : public Person {
private:
    string jobTitle; //se pueden agregar otras propiedades
public:

    void setJobTitle(string jobTitle) {
        this->jobTitle = jobTitle;
    }

    string getJobTitle() {
        return jobTitle;
    }
    
    /**
     * Se pueden crear métodos con el mismo nombre que el que está en el ancestro.
     * Esto se llama "override"
     */
    void sayHi(){
        //y se puede invocar al método del ancestro así:
        Person::sayHi(); //aun así es opcional llamar al ancestro
        //... y luego puedo continuar con la logica de este método
        cout << " y trabajo como " << jobTitle;        
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    Person aPerson; // aquí se instancia un objeto
    //colocamos valores
    aPerson.setAge(15);
    aPerson.setName("Juan Perez");
    aPerson.sayHi(); //aqui invoco al saludo
    
    //Una de las magias de la herencia en objetos es esta (polimorfismo):
    Employee aEmployee;
    aEmployee.setName("Ruberto"); //puedo invocar a métodos que están heredados
    aEmployee.setAge(40);
    aEmployee.setJobTitle("Administrador");
    aEmployee.sayHi(); //aqui está invocando al método de Employee
    return 0;
}