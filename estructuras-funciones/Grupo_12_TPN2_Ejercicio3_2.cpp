

#include <iostream>
#include <cstring>
#include <locale.h>


using namespace std;

//estructura
struct encuesta{
char estacion;
string destino;
int pago;
string contacto;	
};


//declaracion de funciones
void InicializarArreglo(encuesta respuestas[500]);
encuesta IngresarRespuesta();
void AgregarRespuestaAlArreglo(encuesta respuestas[500],encuesta nuevaRespuesta);
bool Continuar();
void AnalizarEncuestas(encuesta respuestas[500]);

//main

int main()
{
//variables
encuesta respuestas[500];
int opcion=0;
encuesta nuevaRespuesta;
bool continuar=true;

//instrucciones y llamados a funciones
setlocale(LC_ALL,"spanish");
InicializarArreglo(respuestas);

cout<< "Bienvenido al Sistema Carga y Analisis de Encuestas"<<endl<<endl;
while(opcion!=3)
{
cout<<endl;
cout<<"1. Cargar una Encuesta"<<endl;
cout<<"2. Analizar Encuestas"<<endl;
cout<<"3. Salir"<<endl<<endl;
cout<<"Indique la opcion deseada:  "<<endl;
cin>>opcion;
cin.ignore();

switch(opcion){
		case 1:
			while(continuar==true)
			{
					nuevaRespuesta=IngresarRespuesta();
					AgregarRespuestaAlArreglo(respuestas,nuevaRespuesta);
					continuar=Continuar();	
			}
			break;
		case 2: 
				AnalizarEncuestas(respuestas);
			
			break;
		case 3:
			cout<<"Saliendo. Gracias por usar el sistema."<<endl;
			break;
		default : 
			cout<<"No es opcion valida";
			break;
	}



}
return 0;
}


//implementación de funciones

void InicializarArreglo(encuesta respuestas[500]){
	
	encuesta respuestaVacia;
	
	respuestaVacia.estacion=' ';
	respuestaVacia.destino="";
	respuestaVacia.pago=0;
	respuestaVacia.contacto="";
	
	for(int i=0; i<=499; i++)
	{
		respuestas[i]=respuestaVacia;
	}		
}

encuesta IngresarRespuesta(){
	encuesta nuevaRespuesta;
	
	cout<<"Que estacion es su preferida para vacacionar? Ingresar V (si es verano), I (si es invierno), P (si es primavera) u O (si es otonio) "<<endl;
	cin>>nuevaRespuesta.estacion;
	cin.ignore();
	cout<<"Que destino elegiria para vacacionar? Ingresar en mayuscula y sin abreviaturas "<<endl;
	getline(cin,nuevaRespuesta.destino);
	cout<<"Cuanto pagaria por un paquete completo (viaje, alojamiento y excursiones) por 15 dias al destino elegido anteriormente por persona?"<<endl;
	cin>>nuevaRespuesta.pago;
	cin.ignore();
	cout<<"Tiene un mail o telefono de contacto? "<<endl;
	getline(cin,nuevaRespuesta.contacto);
	
	
	return nuevaRespuesta;
		
}

void AgregarRespuestaAlArreglo(encuesta respuestas[500],encuesta nuevaRespuesta){
	int i=0;
	bool agregada=false;
	
	while(i<=499) 
	{
		if(respuestas[i].estacion==' ' && respuestas[i].destino=="" && respuestas[i].pago==0 && respuestas[i].contacto=="")
		{
			respuestas[i]=nuevaRespuesta;
			agregada=true;
			i=1000;
		}
		else
			i++;
	}
	if(agregada==true)
		cout<< "La encuesta fue agregada correctamente"<<endl;
	else
		cout <<"Sin agregar. No hay cupo"<<endl;
	
		
}

bool Continuar(){
	char respuesta=' ';
	bool condicion=false;
	
	cout<<"Desea iniciar otra encuesta? Ingrese S(para si) o N(para no): ";
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

void AnalizarEncuestas(encuesta respuestas[500]){
	char estacionBuscada;
	string destinoBuscado;
	bool encontrado= false;
	int contadorEncuestasRealizadas=0, contadorEncuestasFiltradas=0;
	float porcentajeFiltro=0.0, mayorPago=0;
	
	
	
	cout<<"Ingrese la estacion que desea: "<<endl;
	cin>>estacionBuscada;
	cin.ignore();
	cout<<"Ingrese el destino deseado (mayusculas sin abreviaturas): "<<endl;
	getline(cin, destinoBuscado);
	
for (int i=0; i<=499 ; i++){
	if(respuestas[i].estacion!=' '&& respuestas[i].destino!=" " && respuestas[i].pago!=0 && respuestas[i].contacto!=" ")
	{
		contadorEncuestasRealizadas=contadorEncuestasRealizadas+1;
		
		if(respuestas[i].estacion==estacionBuscada && respuestas[i].destino==destinoBuscado)
		{
			contadorEncuestasFiltradas=contadorEncuestasFiltradas+1;
			
			if(respuestas[i].pago>mayorPago){
			mayorPago=respuestas[i].pago;	
			}
			
		} 
		
	}
		
		
}
if(contadorEncuestasFiltradas==0){
cout<<"No hay encuestas que hayan seleccionado ir en "<<estacionBuscada<<" a  "<<destinoBuscado<<endl;	
}
	
porcentajeFiltro=(contadorEncuestasFiltradas*100)/contadorEncuestasRealizadas;	
cout<<"El porcentaje de personas que prefiere ir en "<<estacionBuscada<<" a "<<destinoBuscado<<" es: "<<porcentajeFiltro<<" % "<<endl<<endl;

for (int i=0; i<=499 ; i++){
	if(respuestas[i].estacion!=' '&& respuestas[i].destino!=" " && respuestas[i].pago!=0 && respuestas[i].contacto!=" ")
	{
		if(respuestas[i].estacion==estacionBuscada && respuestas[i].destino==destinoBuscado && respuestas[i].pago==mayorPago)
		{
		
		cout<<"Mayor Oferta de Pago por un paquete en "<<estacionBuscada<<" a "<<destinoBuscado<<" es de: "<<endl<<endl;
		cout<<"ESTACION PREFERIDA:  "<<respuestas[i].estacion<<endl;
 		cout<<"DESTINO ELEGIDO:  "<<respuestas[i].destino<<endl;
 		cout<<"PAGARIA POR EL PAQUETE:  "<<respuestas[i].pago<<endl;
 		cout<<"DATOS DE CONTACTO:  "<<respuestas[i].contacto<<endl;
		}	
	}
	
}
	
}