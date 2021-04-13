#ifndef CLASSPRESTAMOLIBROS_H
#define CLASSPRESTAMOLIBROS_H
#include<string>
using namespace std;

class classPrestamoLibros
{
	public:
		classPrestamoLibros(int, string, string, int, int, string, string);
		int IdPrestamoLibro;
		string Cliente;
		string Libro;
		int CantInicial;
		int CantActual;
		string FechaAsignacion;
		string FechaDevolucion;
		
	classPrestamoLibros *sig;
	protected:
};

#endif
