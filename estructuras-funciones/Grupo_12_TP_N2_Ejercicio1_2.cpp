#include <iostream>
#include <cstring>
#include <locale.h>

using namespace std;

//estructura
struct ciclista{
	int DNI;
	string apellido;
	string nombre;
	string localidad;
	int edad;
};

//declaracion de funciones
void InicializarArreglo(ciclista participantes[30]);
ciclista IngresarParticipante();
void AgregarParticipanteAlArreglo(ciclista participantes[30],ciclista nuevoParticipante);
bool Continuar();
void BuscarCiclistaPorDni(ciclista participantes[30]);
void BuscarCiclistaPorPechera(ciclista participantes[30]);

//main

int main()
{
//variables

ciclista participantes[30];
int opcion=0;
ciclista nuevoParticipante;
bool continuar=true;


//instrucciones y llamados a funciones
setlocale(LC_ALL,"spanish");

InicializarArreglo(participantes);

cout<< "Bienvenido al Sistema para la Gestion de Inscriptos"<<endl;


while(opcion!=4)
{
cout<<endl;
cout<<"1. Inscribir un ciclista"<<endl;
cout<<"2. Buscar un ciclista por DNI"<<endl;
cout<<"3. Buscar un ciclista por numero de pechera"<<endl;
cout<<"4. Salir"<<endl<<endl;
cout<<"Indique la opcion deseada:  "<<endl;
cin>>opcion;

cin.ignore();

switch(opcion){
		case 1:
			while(continuar==true)
			{
					nuevoParticipante=IngresarParticipante();
					AgregarParticipanteAlArreglo(participantes,nuevoParticipante);
					continuar=Continuar();	
			}
			break;
		case 2: 
			BuscarCiclistaPorDni(participantes);
			break;
		case 3:
			BuscarCiclistaPorPechera(participantes);
			break;
		case 4:
			cout<<"Saliendo. Gracias por usar el sistema."<<endl;
			break;
		default : 
			cout<<"No es opcion valida";
			break;
	}
}

return 0;
}

// implementacion de funciones
void InicializarArreglo(ciclista participantes[30]){
	
	ciclista participanteVacio;
	participanteVacio.DNI=0;
	participanteVacio.apellido="";
	participanteVacio.nombre="";
	participanteVacio.localidad="";
	participanteVacio.edad=0;
	for(int i=0; i<=29; i++)
	{
		participantes[i]=participanteVacio;
	}	
	
}

ciclista IngresarParticipante(){
	ciclista nuevoParticipante;
	
	cout<<"Ingresar DNI: ";
	cin>>nuevoParticipante.DNI;
	cin.ignore();
	cout<<"Ingresar apellido: ";
	getline(cin,nuevoParticipante.apellido);
	cout<<"Ingresar nombre: ";
	getline(cin,nuevoParticipante.nombre);
	cout<<"Ingresar localidad: ";
	getline(cin,nuevoParticipante.localidad);
	cout<<"Ingresar edad: ";
	cin>>nuevoParticipante.edad;
	cin.ignore();

	return nuevoParticipante;
			
}

void AgregarParticipanteAlArreglo(ciclista participantes[30],ciclista nuevoParticipante){
		int i=0;
		bool agregado=false;
	
	while(i<=29) 
	{
		if(participantes[i].DNI==0 && participantes[i].apellido=="" && participantes[i].nombre=="" && participantes[i].localidad=="" && participantes[i].edad==0)
		{
			participantes[i]=nuevoParticipante;
			agregado=true;
			i=100;
		}
		else
			i++;
	}
	if(agregado==true)
		cout<< "Fue agregado correctamente"<<endl;
	else
		cout <<"Sin agregar. No hay cupo"<<endl;
	
	
	
}

bool Continuar(){
	char respuesta=' ';
	bool condicion=false;
	
	cout<<"Desea continuar? Ingrese S(para si) o N(para no): ";
	cin>>respuesta;
	cin.ignore();
	
	while(respuesta!='S' && respuesta!='N')
	{
		cout<< "Debe ingresar S(para continuar) o N(para terminar): ";
		cin>>respuesta;
		cin.ignore();
	}
	if(respuesta=='S')
		condicion=true;
	else
		condicion=false;

	return condicion;	
}

void BuscarCiclistaPorDni(ciclista participantes[30]){
int DniBuscado=0;
bool encontrado= false;

cout<<"Ingrese el DNI buscado: "<<endl;
cin>>DniBuscado;
cin.ignore();
 for (int i=0; i<=29 && encontrado== false; i++){
 	if (participantes[i].DNI==DniBuscado){
 		cout<<"Fue encontrado un participante"<<endl;
		cout<<"DNI:  "<<participantes[i].DNI<<endl;
 		cout<<"APELLIDO:  "<<participantes[i].apellido<<endl;
 		cout<<"NOMBRE:  "<<participantes[i].nombre<<endl;
 		cout<<"LOCALIDAD:  "<<participantes[i].localidad<<endl;
 		cout<<"EDAD:  "<<participantes[i].edad<<endl;
 		encontrado= true;
	 }

 }

if(encontrado==false)
	cout<<" El DNI no coincide con ningun participante."<<endl;
}

void BuscarCiclistaPorPechera(ciclista participantes[30]){
	
	int PecheraBuscada=0, p=0;


cout<<"Ingrese la pechera buscada: "<<endl;
cin>>PecheraBuscada;
cin.ignore();
p=PecheraBuscada-1;

if(PecheraBuscada<29 && participantes[p].DNI!=0){
cout<<"La pechera "<<PecheraBuscada<<" corresponde al participante: "<<endl;	
cout<<"DNI: "<<participantes[p].DNI<<endl;
cout<<"APELLIDO: "<<participantes[p].apellido<<endl;
cout<<"NOMBRE: "<<participantes[p].nombre<<endl;
cout<<"LOCALIDAD: "<<participantes[p].localidad<<endl;
cout<<"EDAD: "<<participantes[p].edad<<endl;
}
else
cout<<"No existe la pechera buscada"<<endl;
	
	
	
}