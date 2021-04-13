#include <iostream>
#include <iomanip>
#include "classCliente.h"
#include "classLibro.h"
#include <fstream>
#include <string>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//*** PUNTEROS BASE ***//
classCliente *Iclient, *Fclient, *Tclient, *Aclient;
classLibro *Ilib, *Flib, *TLib, *ALib;
//*** VARIABLES ***//
int _Opc, _Acc;
int _Id, _Existencia;
string _Nombre, _Categoria;
double _Precio;
//*** Prototipo Funciones ***//
void ProcSeleccionAcciones();

void ProcGuardarCliente();
void ProcMostrarCliente();
void ProcBuscarCliente(int);
void ProcEditarCliente(int);
void ProcEliminarCliente(int);
void ProcBuscarLibroEsp(int);
void ProcModificarLibros(int);
/*================================================*/

void ProcGuardarLibro(int, string, string, int, double);
void ProcGuardarLibrostxt();
void ProcBuscarLibros();
void ProcMostrarLibros();
void ProcLimpiarLista();

int main(int argc, char** argv) {
	do{
		cout << setw(5) << "  \n    <<:::: MENU ::::>>" << setw(5) << endl;
		cout << "1)Cliente     2)Libro     3)Prestamo Libro     0)Salir" << endl;
		cin >> _Opc;
		
		switch(_Opc){
		    case 1: // *** Modulo Cliente *** //	
				do{
					ProcSeleccionAcciones();
					cin >> _Acc;
					
					switch(_Acc){
						case 1:  // *** GUARDAR ***//
							ProcGuardarCliente();
							break;
							
						case 2: // *** MOSTRAR ***//
							ProcMostrarCliente();
							break;
							
						case 3: // *** BUSCAR ***//
							int _Id;
							cout << "Ingrese el Id a buscar: ";
							cin >> _Id;
							ProcBuscarCliente(_Id);
							break;
						
						case 4: // *** EDITAR ***//
							cout << "Ingrese el Id a editar: ";
							cin >> _Id;
							ProcEditarCliente(_Id);
							break;
							
						case 5: // *** ELIMINAR ***//
							cout << "Ingrese el Id a eliminar: ";
							cin >> _Id;
							ProcEliminarCliente(_Id);
							break;
							
						case 0: // *** SALIR MODULO *** //
							break;
						
						default :
							cout << "Accion no Valida" << endl;
					}
				}while(_Acc != 0);
				
				break;
				
			case 2: // *** Modulo Libro *** //
				do{
					ProcSeleccionAcciones();
					cin >> _Acc;
				
					switch(_Acc){
						case 1: // *** GUARDAR ***//
							
							cout << "Ingrese el Id: ";
							cin >> _Id;
							cout << "Ingrese el Nombre: ";
							cin >> _Nombre;
							cout << "Ingrese la Categoria: ";
							cin >> _Categoria;
							cout << "Ingrese la cantidad existente: ";
							cin >> _Existencia;
							cout << "Ingrese el precio: ";
							cin >> _Precio;
							ProcGuardarLibro(_Id,_Nombre,_Categoria,_Existencia,_Precio);
							ProcGuardarLibrostxt();
							break;
							
						case 2: // *** MOSTRAR ***//
						   ProcMostrarLibros();
							break;
							
						case 3: // *** BUSCAR ***//
							cout << "<<<=================== BUSQUEDA DE LIBROS ======================>>>";
							cout << "\nIngrese el Id: ";
							cin >> _Id;
							ProcBuscarLibroEsp(_Id);
							break;
						
						case 4: // *** EDITAR ***//
						cout << "<<<=================== EDITAR REGISTRO DE LIBROS ======================>>>";
						cout << "\nIngrese el Id: ";
							cin >> _Id;
							ProcModificarLibros(_Id);
							break;
							
						case 5: // *** ELIMINAR ***//
							break;
							
						case 0: // *** SALIR MODULO *** //
							break;
						
						default :
							cout << "Accion no Valida" << endl;
					}
				}while(_Acc != 0);
				
				break;
				
			case 3: // *** Modulo Prestamo Libro *** //
				do{
					ProcSeleccionAcciones();
					cin >> _Acc;
				
					switch(_Acc){
						case 1: // *** GUARDAR ***//
							break;
							
						case 2: // *** MOSTRAR ***//
							break;
							
						case 3: // *** BUSCAR ***//
							break;
						
						case 4: // *** EDITAR ***//
							break;
							
						case 5: // *** ELIMINAR ***//
							break;
							
						case 0: // *** SALIR MODULO *** //
							break;
						
						default :
							cout << "Accion no Valida" << endl;
					}
				}while(_Acc != 0);
				
				break;
				
			case 0:
				cout << " \n ¡ Cerro Seccion !" << endl;
				break;
				
			default:
				cout << "Opcion no valida";
		}
	}while(_Opc != 0);
	
	
	system("pause");
	return 0;
}
/*========================================================*/
void ProcSeleccionAcciones(){
	cout << "        1)Guardar     2)Mostrar     3)Buscar     4)Modificar     5)Eliminar     0)Salir" << endl;
}

/*=============================================================*/
void ProcGuardarCliente()
{
	int _Id, _Codigo;
	string _Nombre, _Telefono, _Direccion;
	classCliente C1();
	
	cout << "Ingrese el Id: ";
	cin >> _Id;
	cout << "Ingrese el Codigo: ";
	cin >> _Codigo;
	cout << "Ingrese el Nombre: ";
	cin >> _Nombre;
	cout << "Ingrese el Telefono: ";
	cin >> _Telefono;
	cout << "Ingrese la Direccion: ";
	cin >> _Direccion;
	
	Tclient = new classCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
	Tclient->SetId(_Id);
	Tclient->SetCodigo(_Codigo);
	Tclient->SetNombre(_Nombre);
	Tclient->SetTelefono(_Telefono);
	Tclient->SetDireccion(_Direccion);
	Tclient->sig == NULL;
	
	if(Iclient == NULL)
	{
		Iclient = Tclient;
	}
	else
	{
		Fclient->sig = Tclient;	
	}
	Fclient = Tclient;
}

/*=========================================================*/
void ProcMostrarCliente(){
	Tclient = Iclient;
	while(Tclient != NULL)
	{
		cout << "Id: " << Tclient->GetId()<< endl;
		cout << "Codigo: " << Tclient->GetCodigo()<< endl;
		cout << "Nombre: " << Tclient->GetNombre()<< endl;
		cout << "Telefono: " << Tclient->GetTelefono()<< endl;
		cout << "Direccion: " << Tclient->GetDireccion()<< endl;
		cout << "==============================================" << endl;
		Tclient = Tclient->sig;
	}
}

/*============================================================*/
void ProcBuscarCliente(int _Id){
	bool encontrado = false;
	Tclient = Iclient;
	Aclient = Tclient;
	while(Tclient != NULL && !encontrado)
	{
		if(Tclient->GetId() == _Id)
		{
			cout << "Id: " << Tclient->GetId()<< endl;
			cout << "Codigo: " << Tclient->GetCodigo()<< endl;
			cout << "Nombre: " << Tclient->GetNombre()<< endl;
			cout << "Telefono: " << Tclient->GetTelefono()<< endl;
			cout << "Direccion: " << Tclient->GetDireccion()<< endl;
			encontrado = true;	
		}
		else
		{
			Aclient = Tclient;
			Tclient = Tclient->sig;	
		}
	}
	
	if(!encontrado){
		cout << "Id no encontrado" << endl;
	}
}

/*===================================================================*/
void ProcEditarCliente(int _Id){
	int _Codigo;
	string _Nombre, _Telefono, _Direccion;
	ProcBuscarCliente(_Id);

	if(Tclient != NULL){
		cout << "Ingrese el nuevo Codigo: ";
		cin >> _Codigo;
		cout << "Ingrese el nuevo Nombre: ";
		cin >> _Nombre;
		cout << "Ingrese el nuevo Telefono: ";
		cin >> _Telefono;
		cout << "Ingrese la nueva Direccion: ";
		cin >> _Direccion;
		Tclient->SetCodigo(_Codigo);
		Tclient->SetNombre(_Nombre);
		Tclient->SetTelefono(_Telefono);
		Tclient->SetDireccion(_Direccion);
	}
}

/*================================================*/
void ProcEliminarCliente(int _Id){
	ProcBuscarCliente(_Id);
	if(Tclient != NULL){
		if(Iclient = Tclient){
			Iclient = Iclient->sig;
			if(Tclient == Fclient){
				Fclient = NULL;
			}
		}
		else if(Tclient == Fclient){
			Fclient = Aclient;
			Aclient->sig = NULL;
		}
		else{//no esta en el inicio no al final
			Aclient->sig = Tclient->sig;	
		}
	}
}
/*----------------------------------MODULO DE LIBROS----------------------------------------------*/
void ProcGuardarLibro(int id, string nombre, string categoria, int existencia,double precio)
{
	TLib=new classLibro();
	TLib->Id= id;
	TLib->Nombre= nombre;
    TLib->Categoria= categoria;
    TLib->Existencia= existencia;
    TLib->Precio= precio;
	TLib->sig=NULL;
	
	if(Ilib==NULL){
		Ilib=TLib;
	}
	else{
		Flib->sig=TLib;		
	}
	Flib=TLib;
}

void ProcGuardarLibrostxt(){
	ofstream archivo;
    archivo.open("C:/textos/Libros.txt");
	
		TLib=Ilib;	
	while(TLib!=NULL){
		archivo<<TLib->Id<<endl;
		archivo<<TLib->Nombre<<endl;
		archivo<<TLib->Categoria<<endl;
		archivo<<TLib->Existencia<<endl;
		archivo<<TLib->Precio<<endl;
		TLib=TLib->sig;
	}
	archivo.close();
}

void ProcBuscarLibros(){
	char Id[128];
	char Nombre[128];
	char Categoria[128];
	char Existencia[128];
	char Precio[128];
	ifstream archivo("C:/textos/libros.txt");
	
	while(!archivo.eof()){
		archivo>>Id;
		archivo>>Nombre;
		archivo>>Categoria;
		archivo>>Existencia;
		archivo>>Precio;
		
		if(!archivo.eof()){
			ProcGuardarLibro(atoi(Id),Nombre,Categoria, atoi(Existencia), atoi(Precio));
		}
	}
	archivo.close();	
}

void ProcMostrarLibros(){
	ProcLimpiarLista();
	ProcBuscarLibros();
	TLib=Ilib;	
	while(TLib!=NULL){
		cout<<"Id: "<<TLib->Id<<endl;
		cout<<"Nombre Libro: "<<TLib->Nombre<<endl;
		cout<<"Categoria: "<<TLib->Categoria<<endl;
		cout<<"Cantidades Existentes : "<<TLib->Existencia<<endl;
		cout<<"Precio por unidad: "<<TLib->Precio<<endl;
		cout<<"================================================================================================================="<<endl;
		TLib=TLib->sig;
	}
}

void ProcBuscarLibroEsp(int x){
	ProcBuscarLibros();
	bool encontrado=false;
	TLib=Ilib;	
	ALib=TLib;
	while(TLib!=NULL && !encontrado){
		if(TLib->Id == x){
		cout<<"Id: "<<TLib->Id<<endl;
		cout<<"Nombre Libro: "<<TLib->Nombre<<endl;
		cout<<"Categoria: "<<TLib->Categoria<<endl;
		cout<<"Cantidades Existentes : "<<TLib->Existencia<<endl;
		cout<<"Precio por unidad: "<<TLib->Precio<<endl;
		cout<<"=================================================================================================================="<<endl;
		encontrado=true;
		}
		else{
			ALib=TLib;
			TLib=TLib->sig;
		}
	}
	
	if(!encontrado){
		cout<<"Su libro no fue encontrado"<<endl;
	}
}

void ProcModificarLibros(int x){
	ProcBuscarLibroEsp(x);
	if(TLib!=NULL){
			cout << "Ingrese el Id: ";
			cin >> _Id;
			cout << "Ingrese el Nombre: ";
			cin >> _Nombre;
			cout << "Ingrese la Categoria: ";
			cin >> _Categoria;
			cout << "Ingrese la cantidad existente: ";
			cin >> _Existencia;
			cout << "Ingrese el precio: ";
			cin >> _Precio;
			TLib->Id= _Id;
			TLib->Nombre= _Nombre;
			TLib->Categoria = _Categoria;
			TLib->Existencia = _Existencia;
			TLib->Precio = _Precio;
	}
	ProcGuardarLibrostxt();
}

void ProcLimpiarLista(){
	Ilib=NULL;
	TLib=NULL;
	Flib=NULL;
	ALib=NULL;
}
/*----------------------------------FINAL MODULO DE LIBROS----------------------------------------------*/
