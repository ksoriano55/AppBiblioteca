#include <iostream>
#include <iomanip>
#include "classCliente.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//*** PUNTEROS BASE ***//
classCliente *I, *F, *T;
//*** VARIABLES ***//
int _Opc, _Acc;

//*** Prototipo Funciones ***//
void ProcSeleccionAcciones();

void ProcGuardarCliente();
void ProcMostrarCliente();
void ProcBuscarCliente(int _Id);

int main(int argc, char** argv) {
	do{
		cout << setw(5) << "  \n                     <<:::: MENU ::::>>" << setw(5) << endl;
		cout << "1)Cliente     2)Libro     3)Categoria     4)Prestamo Libro     0)Salir" << endl;
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
				
			case 3: // *** Modulo Categoria *** //
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
				
			case 4: // *** Modulo Prestamo Libro *** //
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
void ProcSeleccionAcciones(){
	cout << "        1)Guardar     2)Mostrar     3)Buscar     4)Modificar     5)Eliminar     0)Salir" << endl;
}

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
	
	T = new classCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
	T->SetId(_Id);
	T->SetCodigo(_Codigo);
	T->SetNombre(_Nombre);
	T->SetTelefono(_Telefono);
	T->SetDireccion(_Direccion);
	
	if(I == NULL)
	{
		I = T;
	}
	else
	{
		F->sig = T;	
	}
	F = T;
}

void ProcMostrarCliente(){
	T = I;
	while(T != NULL)
	{
		cout << "Id: " << T->GetId()<< endl;
		cout << "Codigo: " << T->GetCodigo()<< endl;
		cout << "Nombre: " << T->GetNombre()<< endl;
		cout << "Telefono: " << T->GetTelefono()<< endl;
		cout << "Direccion: " << T->GetDireccion()<< endl;
		cout << "==============================================" << endl;
		T = T->sig;
	}
}

void ProcBuscarCliente(int _Id){
	bool encontrado = false;
	T = I;
	while(T != NULL && !encontrado)
	{
		if(T->GetId() == _Id)
		{
			cout << "Id: " << T->GetId()<< endl;
			cout << "Codigo: " << T->GetCodigo()<< endl;
			cout << "Nombre: " << T->GetNombre()<< endl;
			cout << "Telefono: " << T->GetTelefono()<< endl;
			cout << "Direccion: " << T->GetDireccion()<< endl;
			encontrado = true;	
		}
		else
		{
			T = T->sig;	
		}
	}
	
	if(!encontrado){
		cout << "Id no encontrado" << endl;
	}
}
