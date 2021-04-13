#ifndef CLASSCLIENTE_H
#define CLASSCLIENTE_H
#include<string>
using namespace std;
class classCliente
{
	public:
		classCliente(int, int, string, string, string);
		// *** Set *** //
		void SetId(int);
		void SetCodigo(int);
		void SetNombre(string);
		void SetTelefono(string);
		void SetDireccion(string);
		
		// *** Get *** //
		int GetId();
		int GetCodigo();
		string GetNombre();
		string GetTelefono();
		string GetDireccion();
		
		classCliente *sig;
		
	private:
		int Id;
		int Codigo;
		string Nombre;
		string Telefono;
		string Direccion;
};

#endif
