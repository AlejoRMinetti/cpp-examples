#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

//estructura

struct inventario{
	int codigo;
	string descripcion;
	float costo;
	int cantidad;
	char tipo;
};

//declaracion de funciones
void InicializarArreglo(inventario productos[100]);
inventario IngresarProducto();
void AgregarProductoAlArreglo(inventario productos[100],inventario nuevoProducto);
bool Continuar();
void MostrarProductosDeArreglo(inventario productos[100]);
void ModificarProductosDeArreglo(inventario productos[100]);
	
	
	

//main

int main()
{
//variables

inventario productos[100];
char opcion=' ';
inventario nuevoProducto;

bool continuar=true;

//instrucciones y llamados a funciones
setlocale(LC_ALL,"spanish");

InicializarArreglo(productos);

cout<< "Bienvenido al Sistema para la Gestion de Inventario"<<endl<<endl;

while(opcion!='S'){

cout<<"A. Alta de un producto"<<endl;
cout<<"M. Modificar un producto"<<endl;
cout<<"L. Listar todos los productos"<<endl;
cout<<"S. Salir"<<endl<<endl;

cout<<"Indique la opcion deseada:  "<<endl;
cin>>opcion;

switch(opcion){
		case 'A':
		
		while(continuar==true)
				{
					nuevoProducto=IngresarProducto();
					AgregarProductoAlArreglo(productos,nuevoProducto);
					continuar=Continuar();	
				}
			break;
		case 'M':
				ModificarProductosDeArreglo(productos);
			break;
		case 'L': 
				MostrarProductosDeArreglo(productos);
			break;
		case 'S':
				cout<<"Saliendo. Gracias por usar el sistema."<<endl;
		break;
		default : cout<<"No es opcion valida";
		break;
	}
}
return 0;
}


//implementación de funciones

void InicializarArreglo(inventario productos[100]){
	
	inventario productoVacio;
	
	productoVacio.codigo=0;
	productoVacio.descripcion="";
	productoVacio.costo=0;
	productoVacio.cantidad=0;
	productoVacio.tipo=' ';
	
	for(int i=0; i<=99; i++)
	{
		productos[i]=productoVacio;
	}
	
	
	
}





inventario IngresarProducto(){
	inventario nuevoProducto;
	
	cout<<"Ingresar codigo: ";
	cin>>nuevoProducto.codigo;
	cin.ignore();
	cout<<"Ingresar descripcion: ";
	getline(cin,nuevoProducto.descripcion);
	cout<<"Ingresar costo: ";
	cin>>nuevoProducto.costo;
	cin.ignore();
	cout<<"Ingresar cantidad: ";
	cin>>nuevoProducto.cantidad;
	cin.ignore();
	cout<<"Ingresar tipo: ";
	cin>>nuevoProducto.tipo;
	cin.ignore();

	return nuevoProducto;
	
	
}
void AgregarProductoAlArreglo(inventario productos[100],inventario nuevoProducto){
		int i=0;
		bool agregado=false;
	
	while(i<=99) 
	{
		if(productos[i].codigo==0 && productos[i].descripcion=="" && productos[i].costo==0 && productos[i].cantidad==0 && productos[i].tipo==' ')
		{
			productos[i]=nuevoProducto;
			agregado=true;
			i=200;
		}
		else
			i++;
	}
	if(agregado==true)
		cout<< "Producto ingresado correctamente"<<endl;
	else
		cout <<"Sin ingresar. No hay espacio para mas productos"<<endl;
	
	
	
	
	
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

void MostrarProductosDeArreglo(inventario productos[100]){
cout <<"Los productos que se ingresaron al inventario fueron: "<<endl;
	for(int i=0; i<=99; i++)
	{
		if(productos[i].codigo!=0 && productos[i].descripcion!="" && productos[i].costo!=0 && productos[i].cantidad!=0 && productos[i].tipo!=' ')
		{
		cout<<" - Codigo: "<<productos[i].codigo
		<<" - Descripcion: "<<productos[i].descripcion
		<<" - Costo: "<<productos[i].costo
		<<" - Cantidad: "<<productos[i].cantidad
		<<" - Tipo: "<<productos[i].tipo<<endl;
		}
	}	
	
	
}

void ModificarProductosDeArreglo(inventario productos[100]){
	
	int codigoBuscado=0, nuevaCantidad=0; 
	bool encontrado=false;
	string nuevaDescripcion;
	float nuevoCosto;
	char nuevoTipo=' ';
	
	cout<<"Ingrese el codigo del producto que desea modificar: "<<endl;
	cin>>codigoBuscado;
	cin.ignore();
	
	
	for(int i=0; i<=99 && encontrado== false;i++){
		if(productos[i].codigo==codigoBuscado){
			cout<<"el codigo corresponde a: "<<endl;
			cout<<" - Descripcion: "<<productos[i].descripcion<<endl;
			cout<<" - Costo: "<<productos[i].costo<<endl;
			cout<<" - Cantidad: "<<productos[i].cantidad<<endl;
			cout<<" - Tipo: "<<productos[i].tipo<<endl<<endl;
			cout<<"Ingrese  nueva descripcion: "<<endl;
			getline(cin,nuevaDescripcion);
			productos[i].descripcion=nuevaDescripcion;
			cout<<"Ingrese  nuevo costo: "<<endl;
			cin>>nuevoCosto;
			cin.ignore();
			productos[i].costo=nuevoCosto;
			cout<<"Ingrese  nueva cantidad: "<<endl;
			cin>>nuevaCantidad;
			cin.ignore();
			productos[i].cantidad=nuevaCantidad;
			cout<<"Ingrese  nuevo tipo: "<<endl;
			cin>>nuevoTipo;
			cin.ignore();
			productos[i].tipo=nuevoTipo;
			
			encontrado=true;
		}
		
		
	if(encontrado==false){
	cout<<" El codigo no existe"<<endl;		
	}	
	
	}
	
	
	
	
	
}