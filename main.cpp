#include <iostream>
#include <iomanip>
#include "classCliente.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//*** PUNTEROS BASE ***//
classCliente *Inicio, *Fin, *Terminal;
//*** VARIABLES ***//
int _Opc, _Acc;

//*** Prototipo Funciones ***//
void ProcGuardar(int Opc);
void ProcMostrar(int Opc);
void ProcBuscar(int Opc);
void ProcSeleccionAcciones();

void ProcGuardarCliente(int _Id, int _Codigo, string _Nombre, string _Telefono, string _Direccion);
void ProcMostrarCliente();
void ProcBuscarCliente(int _Id);

int main(int argc, char** argv) {
	do{
		cout << setw(5) << "MENU" << setw(5) << endl;
		cout << "1)Cliente     2)Libro     3)Categoria     4)Prestamo Libro     0)Salir" << endl;
		cin >> _Opc;
		
		switch(_Opc){
			case 1:
				ProcSeleccionAcciones();
				cin >> _Acc;
				switch(_Acc){
					case 1:
						ProcGuardar(_Opc);
						break;
					case 2:
						ProcMostrar(_Opc);
						break;
					case 3:
						ProcBuscar(_Opc);
						break;
				}
				break;
				
			case 2:
				ProcSeleccionAcciones();
				cin >> _Acc;
				break;
				
			case 3:
				ProcSeleccionAcciones();
				cin >> _Acc;
				break;
				
			case 4:
				ProcSeleccionAcciones();
				cin >> _Acc;
				break;
				
			case 0:
				break;
				
			default:
				cout << "Opcion no válida";
		}
	}while(_Opc != 0);
	
	
	system("pause");
	return 0;
}
void ProcSeleccionAcciones(){
	cout << "        1)Guardar     2)Mostrar     3)Buscar     4)Modificar     5)Eliminar     0)Salir" << endl;
}
void ProcGuardarCliente(int _Id, int _Codigo, string _Nombre, string _Telefono, string _Direccion)
{
	Terminal = new classCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
	Terminal->SetId(_Id);
	Terminal->SetCodigo(_Codigo);
	Terminal->SetNombre(_Nombre);
	Terminal->SetTelefono(_Telefono);
	Terminal->SetDireccion(_Direccion);
	
	if(Inicio == NULL)
	{
		Inicio = Terminal;
	}
	else
	{
		Fin->sig = Terminal;	
	}
	Fin = Terminal;
}

void ProcMostrarCliente(){
	Terminal = Inicio;
	while(Terminal != NULL)
	{
		cout << "Id: " << Terminal->GetId()<< endl;
		cout << "Codigo: " << Terminal->GetCodigo()<< endl;
		cout << "Nombre: " << Terminal->GetNombre()<< endl;
		cout << "Telefono: " << Terminal->GetTelefono()<< endl;
		cout << "Direccion: " << Terminal->GetDireccion()<< endl;
		cout << "==============================================" << endl;
		Terminal = Terminal->sig;
	}
}

void ProcBuscarCliente(int _Id){
	bool encontrado = false;
	Terminal = Inicio;
	while(Terminal != NULL && !encontrado)
	{
		if(Terminal->GetId() == _Id)
		{
			cout << "Id: " << Terminal->GetId()<< endl;
			cout << "Codigo: " << Terminal->GetCodigo()<< endl;
			cout << "Nombre: " << Terminal->GetNombre()<< endl;
			cout << "Telefono: " << Terminal->GetTelefono()<< endl;
			cout << "Direccion: " << Terminal->GetDireccion()<< endl;
			encontrado = true;	
		}
		else
		{
			Terminal = Terminal->sig;	
		}
	}
	
	if(!encontrado){
		cout << "Id no encontrado" << endl;
	}
}

void ProcGuardar(int Opc){
	int _Id, _Codigo;
	string _Nombre, _Telefono, _Direccion; 
	
	switch(Opc){
		case 1:  /// *** guardar Cliete;
			classCliente Cliente();
			cout << "Ingrese Id: ";
			cin >> _Id;
			cout << "Ingrese Codigo: ";
			cin >> _Codigo;
			cout << "Ingrese Nombre: ";
			cin >> _Nombre;
			cout << "Ingrese Telefono: ";
			cin >> _Telefono;
			cout << "Ingrese Direccion: ";
			cin >> _Direccion;
			ProcGuardarCliente(_Id, _Codigo, _Nombre, _Telefono, _Direccion);
			
			break;
		case 2:
			break;
		case 0:
			break;
			
		default:
			cout << "Accion Incorrecta";
			break;		
	}
}

void ProcMostrar(int _Opc)
{
	switch(_Opc){
		case 1:  //Mostrar Cliente
			ProcMostrarCliente();
			break;
		
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 5:
			break;
			
		case 0:
			break;
			
		default:
			cout << "Opcion Incorrecta" << endl;
	}
}

void ProcBuscar(int _Opc)
{
	int _Id;
	switch(_Opc){
		case 1:  //Buscar Cliente
			cout << "Ingrese el Id del cliente a buscar: ";
			cin >> _Id;
			ProcBuscarCliente(_Id);
			break;
		
		case 2:
			break;
			
		case 3:
			break;
			
		case 4:
			break;
			
		case 5:
			break;
			
		case 0:
			break;
			
		default:
			cout << "Opcion Incorrecta" << endl;
	}
}
