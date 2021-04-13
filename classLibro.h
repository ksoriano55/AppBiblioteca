#ifndef CLASSLIBRO_H
#define CLASSLIBRO_H
#include<string>
using namespace std;

class classLibro
{
	public:
		int Id;
		string Nombre;
		string Categoria;
		int Existencia;
		double Precio;
		
	classLibro	*sig;
	protected:
};

#endif
