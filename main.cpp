#include <iostream>
#include <iomanip>
#include "classCliente.h"
#include "classLibro.h"
#include "classPrestamoLibros.h"
#include <fstream>
#include <string>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//*** PUNTEROS BASE ***//
classCliente *Iclient, *Fclient, *Tclient, *Aclient;
classLibro *Ilib, *Flib, *TLib, *ALib;
classPrestamoLibros *Iprest, *Tprest, *Fprest, *Aprest;
//*** VARIABLES ***//
int _Opc, _Acc;
int _Id, _Existencia, _Codigo, _CantInicial, _CantActual;
string _Nombre, _Categoria, _Direccion, _Telefono, _Libro, _Cliente, _FechaAsignacion, _FechaDevolucion;
double _Precio;
//*** Prototipo Funciones ***//
void ProcSeleccionAcciones();

void ProcGuardarCliente(int, int, string, string, string);
void ProcGuardarClientestxt();
void ProcMostrarCliente();
void ProcBuscarCliente(int);
void ProcBuscarClientestxt();
void ProcEditarCliente(int);
void ProcEliminarCliente(int);
void ProcLimpiarCliente();
/*================================================*/

void ProcGuardarLibro(int, string, string, int, double);
void ProcGuardarLibrostxt();
void ProcMostrarLibros();
void ProcBuscarLibroEsp(int);
void ProcBuscarLibros();
void ProcModificarLibros(int);
void ProcEliminarLibros(int);
void ProcLimpiarLista();
/*==================================================*/

void ProcGuardarPrestamoLibro(int, string, string, int, int, string, string);
void ProcGuardarPrestamosLibrostxt();
void ProcMostrarPrestamoLibros();
void ProcBuscarPrestamoLibros(int);
void ProcEditarPrestamoLibros(int);
void ProcEliminarPrestamoLibros(int);
void ProcLimpiarPrestamoLibros();
void ProcBuscarPrestamoLibrostxt();
/*==================================================*/
int main(int argc, char** argv) {
	do{
		cout << setw(5) << "  \n        <<:::: MENU BIBLIOTECA ::::>>" << setw(5) << endl;
		cout << "1)Cliente     2)Libro     3)Prestamo Libro     0)Salir" << endl;
		cin >> _Opc;
		
		switch(_Opc){
		    case 1: // *** Modulo Cliente *** //	
				do{
					ProcSeleccionAcciones();
					cin >> _Acc;
					
					switch(_Acc){
						case 1:  // *** GUARDAR ***//
							cout << "\n <<<=================== GUARDAR CLIENTE ======================>>>" << endl;;
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
							ProcGuardarCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
							ProcGuardarClientestxt();
							break;
							
						case 2: // *** MOSTRAR ***//
							cout << "\n <<<=================== LISTA DE CLIENTE ======================>>>" << endl;
							ProcMostrarCliente();
							break;
							
						case 3: // *** BUSCAR ***//
							cout << "\n <<<=================== BUESQUEDA DE CLIENTE ======================>>>" << endl;
							int _Id;
							cout << "Ingrese el Id a buscar: ";
							cin >> _Id;
							ProcBuscarCliente(_Id);
							break;
						
						case 4: // *** EDITAR ***//
							cout << "\n <<<=================== EDITAR CLIENTE ======================>>>" << endl;
							cout << "Ingrese el Id a editar: ";
							cin >> _Id;
							ProcEditarCliente(_Id);
							ProcGuardarClientestxt();
							break;
							
						case 5: // *** ELIMINAR ***//
							cout << "\n <<<=================== ELIMINAR CLIENTE ======================>>>" << endl;
							cout << "Ingrese el Id a eliminar: ";
							cin >> _Id;
							ProcEliminarCliente(_Id);
							ProcGuardarClientestxt();
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
							cout << "\n <<<=================== GUARDAR LIBROS ======================>>>" << endl;
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
							cout << "\n <<<=================== LISTA DE LIBROS ======================>>>" << endl;
						    ProcMostrarLibros();
							break;
							
						case 3: // *** BUSCAR ***//
							cout << "\n <<<=================== BUSQUEDA DE LIBROS ======================>>>" << endl;
							cout << "\nIngrese el Id: ";
							cin >> _Id;
							ProcBuscarLibroEsp(_Id);
							break;
						
						case 4: // *** EDITAR ***//
							cout << "\n <<<=================== EDITAR LIBROS ======================>>>" << endl;
						    cout << "\nIngrese el Id: ";
							cin >> _Id;
							ProcModificarLibros(_Id);
							break;
							
						case 5: // *** ELIMINAR ***//
							cout << "\n <<<=================== ELIMINAR LIBROS ======================>>>" << endl;
							cout << "Ingrese el Id a eliminar: ";
							cin >> _Id;
							ProcEliminarLibros(_Id);
							ProcGuardarLibrostxt();
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
							cout << "\n <<<=================== GUARDAR PRESTAMOS DE LIBROS ======================>>>" << endl;;
							cout << "Ingrese el Id: ";
							cin >> _Id;
							cout << "Ingrese el Cliente: ";
							cin >> _Cliente;
							cout << "Ingrese el Libro: ";
							cin >> _Libro;
							cout << "Ingrese la Cant.Inicial: ";
							cin >> _CantInicial;
							cout << "Ingrese la Catn.Actual: ";
							cin >> _CantActual;
							cout << "Ingrese Fecha Asignacion: ";
							cin >> _FechaAsignacion;
							cout << "Ingrese Fecha Devolucion: ";
							cin >> _FechaDevolucion;
							ProcGuardarPrestamoLibro(_Id, _Cliente, _Libro, _CantInicial, _CantActual, _FechaAsignacion, _FechaDevolucion);
							ProcGuardarPrestamosLibrostxt();
							break;
							
						case 2: // *** MOSTRAR ***//
							cout << "\n <<<=================== LISTA PRESTAMOS DE LIBROS ======================>>>" << endl;
							ProcMostrarPrestamoLibros();
							break;
							
						case 3: // *** BUSCAR ***//
							cout << "\n <<<=================== BUESQUEDA PRESTAMOS DE LIBROS ======================>>>" << endl;
							int _Id;
							cout << "Ingrese el Id a buscar: ";
							cin >> _Id;
							ProcBuscarPrestamoLibros(_Id);
							break;
						
						case 4: // *** EDITAR ***//
							cout << "\n <<<=================== EDITAR PRESTAMOS DE LIBROS ======================>>>" << endl;
						    cout << "\nIngrese el Id: ";
							cin >> _Id;
							ProcEditarPrestamoLibros(_Id);
							ProcGuardarPrestamosLibrostxt();
							break;
							
						case 5: // *** ELIMINAR ***//
							cout << "\n <<<=================== ELIMINAR PRESTAMOS DE LIBROS ======================>>>" << endl;
							cout << "Ingrese el Id a eliminar: ";
							cin >> _Id;
							ProcEliminarPrestamoLibros(_Id);
							ProcGuardarPrestamosLibrostxt(); 
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
	cout << "\n        1)Guardar     2)Mostrar     3)Buscar     4)Modificar     5)Eliminar     0)Salir" << endl;
}

/*----------------------------------MODULO DE CLIENTE----------------------------------------------*/
void ProcGuardarCliente(int _Id, int _Codigo, string _Nombre, string _Telefono, string _Direccion)
{
	Tclient = new classCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
	Tclient->Id = _Id;
	Tclient->Codigo = _Codigo;
	Tclient->Nombre = _Nombre;
	Tclient->Telefono = _Telefono;
	Tclient->Direccion = _Direccion;
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

void ProcGuardarClientestxt(){
	ofstream archivo;
    archivo.open("C:/textos/Clientes.txt");
	
	Tclient = Iclient;	
	while(Tclient != NULL){
		archivo << Tclient->Id << endl;
		archivo << Tclient->Codigo << endl;
		archivo << Tclient->Nombre << endl;
		archivo << Tclient->Telefono << endl;
		archivo << Tclient->Direccion << endl;
		Tclient = Tclient->sig;
	}
	archivo.close();
}
/*=========================================================*/
void ProcMostrarCliente(){
	ProcLimpiarCliente();
	ProcBuscarClientestxt();
	Tclient = Iclient;
	while(Tclient != NULL)
	{
		cout << "Id: " << Tclient->Id << endl;
		cout << "Codigo: " << Tclient->Codigo << endl;
		cout << "Nombre: " << Tclient->Nombre << endl;
		cout << "Telefono: " << Tclient->Telefono << endl;
		cout << "Direccion: " << Tclient->Direccion << endl;
		cout << "==============================================" << endl;
		Tclient = Tclient->sig;
	}
}

/*============================================================*/
void ProcBuscarCliente(int _Id){
	ProcLimpiarCliente();
	ProcBuscarClientestxt();
	bool encontrado = false;
	Tclient = Iclient;
	Aclient = Tclient;
	while(Tclient != NULL && !encontrado)
	{
		if(Tclient->Id == _Id)
		{
			cout << "Id: " << Tclient->Id << endl;
			cout << "Codigo: " << Tclient->Codigo << endl;
			cout << "Nombre: " << Tclient->Nombre << endl;
			cout << "Telefono: " << Tclient->Telefono << endl;
			cout << "Direccion: " << Tclient->Direccion << endl;
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

void ProcBuscarClientestxt(){
	char Id[128];
	char Codigo[128];
	char Nombre[128];
	char Telefono[128];
	char Direccion[128];
	ifstream archivo("C:/textos/Clientes.txt");
	
	while(!archivo.eof()){
		archivo >> Id;
		archivo >> Codigo;
		archivo >> Nombre;
		archivo >> Telefono;
		archivo >> Direccion;
		if(!archivo.eof()){
			ProcGuardarCliente(atoi(Id),atoi(Codigo),Nombre,Telefono, Direccion);
		}
	}
	archivo.close();
	
}
/*===================================================================*/
void ProcEditarCliente(int _Id){
	ProcLimpiarCliente();
	ProcBuscarClientestxt();
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
		Tclient->Codigo = _Codigo;
		Tclient->Nombre = _Nombre;
		Tclient->Telefono = _Telefono;
		Tclient->Direccion = _Direccion;
	}
}

/*================================================*/
void ProcEliminarCliente(int _Id){
	ProcLimpiarCliente();
	ProcBuscarClientestxt();
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

void ProcLimpiarCliente()
{
	Iclient = NULL;
	Fclient = NULL;
	Tclient = NULL;
	Aclient = NULL;
}
/*----------------------------------MODULO DE LIBROS----------------------------------------------*/
void ProcGuardarLibro(int id, string nombre, string categoria, int existencia,double precio)
{
	TLib = new classLibro();
	TLib->Id = id;
	TLib->Nombre = nombre;
    TLib->Categoria = categoria;
    TLib->Existencia = existencia;
    TLib->Precio = precio;
	TLib->sig = NULL;
	
	if(Ilib == NULL){
		Ilib = TLib;
	}
	else{
		Flib->sig = TLib;		
	}
	Flib = TLib;
}

void ProcGuardarLibrostxt(){
	ofstream archivo;
    archivo.open("C:/textos/Libros.txt");
	
		TLib = Ilib;	
	while(TLib != NULL){
		archivo << TLib->Id << endl;
		archivo << TLib->Nombre << endl;
		archivo << TLib->Categoria << endl;
		archivo << TLib->Existencia << endl;
		archivo << TLib->Precio << endl;
		TLib = TLib->sig;
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
		archivo >> Id;
		archivo >> Nombre;
		archivo >> Categoria;
		archivo >> Existencia;
		archivo >> Precio;
		if(!archivo.eof()){
			ProcGuardarLibro(atoi(Id),Nombre,Categoria, atoi(Existencia), atoi(Precio));
		}
	}
	archivo.close();
}

void ProcMostrarLibros(){
	ProcLimpiarLista();
	ProcBuscarLibros();
	TLib = Ilib;	
	while(TLib != NULL){
		cout << "Id: " << TLib->Id << endl;
		cout << "Nombre Libro: " << TLib->Nombre << endl;
		cout << "Categoria: " << TLib->Categoria << endl;
		cout << "Cantidades Existentes : " << TLib->Existencia << endl;
		cout << "Precio por unidad: " << TLib->Precio << endl;
		cout << "================================================================================================================="<<endl;
		TLib = TLib->sig;
	}
}
void ProcBuscarLibroEsp(int x){
	ProcBuscarLibros();
	bool encontrado=false;
	TLib = Ilib;	
	ALib = TLib;
	while(TLib != NULL && !encontrado){
		if(TLib->Id == x){
		cout << "Id: " << TLib->Id << endl;
		cout << "Nombre Libro: " << TLib->Nombre << endl;
		cout << "Categoria: " << TLib->Categoria << endl;
		cout << "Cantidades Existentes : " << TLib->Existencia << endl;
		cout << "Precio por unidad: " << TLib->Precio << endl;
		cout << "=================================================================================================================="<<endl;
		encontrado = true;
		}
		else{
			ALib = TLib;
			TLib = TLib->sig;
		}
	}
	
	if(!encontrado){
		cout << "Su libro no fue encontrado" << endl;
	}
}

void ProcModificarLibros(int x){
	ProcBuscarLibroEsp(x);
	if(TLib != NULL){
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
			TLib->Id = _Id;
			TLib->Nombre = _Nombre;
			TLib->Categoria = _Categoria;
			TLib->Existencia = _Existencia;
			TLib->Precio = _Precio;
	}
	ProcGuardarLibrostxt();
}

void ProcEliminarLibros(int _Id)
{
	ProcLimpiarLista();
	ProcBuscarLibros();
	ProcBuscarLibroEsp(_Id);
	if(TLib != NULL){
		if(Ilib = TLib){
			Ilib = Ilib->sig;
			if(TLib == Flib){
				Flib = NULL;
			}
		}
		else if(TLib == Flib){
			Flib = ALib;
			ALib->sig = NULL;
		}
		else{//no esta en el inicio no al final
			ALib->sig = TLib->sig;	
		}
	}
}


void ProcLimpiarLista(){
	Ilib = NULL;
	TLib = NULL;
	Flib = NULL;
	ALib = NULL;
}

/*----------------------------------MODULO DE PRESTAMOS DE LIBROS----------------------------------------------*/
void ProcGuardarPrestamoLibro(int _Idp, string _Clientep, string _Librop, int _CantInicialp, int _CantActualp, string _FechaAsignacionp, string _FechaDevolucionp)
{
	Tprest = new classPrestamoLibros(_Idp, _Clientep, _Librop, _CantInicialp, _CantActualp, _FechaAsignacionp, _FechaDevolucionp);
	Tprest->IdPrestamoLibro = _Idp;
	Tprest->Cliente = _Clientep;
	Tprest->Libro = _Librop;
	Tprest->CantInicial = _CantInicialp;
	Tprest->CantActual = _CantActualp;
	Tprest->FechaAsignacion = _FechaAsignacionp;
	Tprest->FechaDevolucion = _FechaDevolucionp;
	Tprest->sig == NULL;
	
	if(Iprest == NULL)
	{
		Iprest = Tprest;
	}
	else
	{
		Fprest->sig = Tprest;	
	}
	Fprest = Tprest;
}

void ProcGuardarPrestamosLibrostxt(){
	ofstream archivo;
    archivo.open("C:/textos/PrestamosLibros.txt");
	
	Tprest = Iprest;	
	while(Tprest != NULL){
		archivo << Tprest->IdPrestamoLibro << endl;
		archivo << Tprest->Cliente << endl;
		archivo << Tprest->Libro << endl;
		archivo << Tprest->CantInicial << endl;
		archivo << Tprest->CantActual << endl;
		archivo << Tprest->FechaAsignacion << endl;
		archivo << Tprest->FechaDevolucion << endl;
		Tprest = Tprest->sig;
	}
	archivo.close();
}


void ProcMostrarPrestamoLibros(){
	ProcLimpiarPrestamoLibros();
	ProcBuscarPrestamoLibrostxt();
	Tprest = Iprest;
	while(Tprest != NULL)
	{
		cout << "Id: " << Tprest->IdPrestamoLibro << endl;
		cout << "Cliente: " << Tprest->Cliente << endl;
		cout << "Libro: " << Tprest->Libro << endl;
		cout << "Cant Inicial: " << Tprest->CantInicial << endl;
		cout << "Cant Actual: " << Tprest->CantActual << endl;
		cout << "Fecha Asignacion: " << Tprest->FechaAsignacion << endl;
		cout << "Fecha Devolucion: " << Tprest->FechaDevolucion << endl;
		cout << "==============================================" << endl;
		Tprest = Tprest->sig;
	}
}

void ProcLimpiarPrestamoLibros()
{
	Iprest = NULL;
	Fprest = NULL;
	Tprest = NULL;
	Aprest = NULL;
}
void ProcBuscarPrestamoLibrostxt(){
	char IdPrestamoLibro[128];
	char Cliente[128];
	char Libro[128];
	char CantInicial[128];
	char CantActual[128];
	char FechaAsignacion[128];
	char FechaDevolucion[128];
	ifstream archivo("C:/textos/PrestamosLibros.txt");
	
	while(!archivo.eof()){
		archivo >> IdPrestamoLibro;
		archivo >> Cliente;
		archivo >> Libro;
		archivo >> CantInicial;
		archivo >> CantActual;
		archivo >> FechaAsignacion;
		archivo >> FechaDevolucion;
		if(!archivo.eof()){
			ProcGuardarPrestamoLibro(atoi(IdPrestamoLibro),Cliente,Libro,atoi(CantInicial),atoi(CantActual),FechaAsignacion,FechaDevolucion);
		}
	}
	archivo.close();
	
}
/*=========================================================*/
void ProcBuscarPrestamoLibros(int _Id){
	ProcLimpiarPrestamoLibros();
	ProcBuscarPrestamoLibrostxt();
	bool encontrado = false;
	Tprest = Iprest;
	Aprest = Tprest;
	while(Tprest != NULL && !encontrado)
	{
		if(Tprest->IdPrestamoLibro == _Id)
		{
			cout << "Id: " << Tprest->IdPrestamoLibro << endl;
			cout << "Cliente: " << Tprest->Cliente << endl;
			cout << "Libro: " << Tprest->Libro << endl;
			cout << "Cant Inicial: " << Tprest->CantInicial << endl;
			cout << "Cant Actual: " << Tprest->CantActual << endl;
			cout << "Fecha Asignaicon: " << Tprest->FechaAsignacion << endl;
			cout << "Fecha Devolucion: " << Tprest->FechaDevolucion << endl;
			encontrado = true;	
		}
		else
		{
			Aprest = Tprest;
			Tprest = Tprest->sig;	
		}
	}
	
	if(!encontrado){
		cout << "Id no encontrado" << endl;
	}
}

/*===================================================================*/
void ProcEditarPrestamoLibros(int _Id){
	ProcLimpiarPrestamoLibros();
	ProcBuscarPrestamoLibrostxt();
	int _CantInicial, _CantActual;
	string _Cliente, _Libro, _FechaAsignacion, _FechaDevolucion;
	ProcBuscarPrestamoLibros(_Id);

	if(Tprest != NULL){
		cout << "Ingrese el nuevo Cliente: ";
		cin >> _Cliente;
		cout << "Ingrese el nuevo Libro: ";
		cin >> _Libro;
		cout << "Ingrese el nuevo Cant Inicial: ";
		cin >> _CantInicial;
		cout << "Ingrese la nueva Cant Actual: ";
		cin >> _CantActual;
		cout << "Ingrese el nuevo Fecha Asignacion: ";
		cin >> _FechaAsignacion;
		cout << "Ingrese la nueva Fecha Devolucion: ";
		cin >> _FechaDevolucion;
		
		Tprest->Cliente = _Cliente;
		Tprest->Libro = _Libro;
		Tprest->CantInicial = _CantInicial;
		Tprest->CantActual = _CantActual;
		Tprest->FechaAsignacion = _FechaAsignacion;
		Tprest->FechaDevolucion = _FechaDevolucion;
	}
}

/*==============================================*/
void ProcEliminarPrestamoLibros(int _Id){
	ProcLimpiarPrestamoLibros();
	ProcBuscarPrestamoLibrostxt();
	ProcBuscarPrestamoLibros(_Id);
	
	if(Tprest != NULL){
		if(Iprest = Tprest){
			Iprest = Iprest->sig;
			if(Tprest == Fprest){
				Fprest = NULL;
			}
		}
		else if(Tprest == Fprest){
			Fprest = Aprest;
			Aprest->sig = NULL;
		}
		else{//no esta en el inicio no al final
			Aprest->sig = Tprest->sig;	
		}
	}
}
/*----------------------------------FINAL MODULO DE LIBROS----------------------------------------------*/
