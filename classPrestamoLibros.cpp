#include "classPrestamoLibros.h"

classPrestamoLibros::classPrestamoLibros(int _Id, string _Cliente, string _Libro, int _CantInicial, int _CantActual, string _FechaAsignacion, string _FechaDevolucion)
{
	IdPrestamoLibro = _Id;
	Cliente = _Cliente;
	Libro = _Libro;
	CantInicial = _CantInicial;
	CantActual = _CantActual;
	FechaAsignacion = _FechaAsignacion;
	FechaDevolucion = _FechaDevolucion;
}
