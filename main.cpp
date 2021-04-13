#include <iostream>
#include <iomanip>
#include "classCliente.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//*** PUNTEROS BASE ***//
classCliente *Iclient, *Fclient, *Tclient, *Aclient;
//*** VARIABLES ***//
int _Opc, _Acc;

//*** Prototipo Funciones ***//
void ProcSeleccionAcciones();
void ProcGuardarCliente();
void ProcMostrarCliente();
void ProcBuscarCliente(int);
void ProcEditarCliente(int);
void ProcEliminarCliente(int);
/*================================================*/

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
