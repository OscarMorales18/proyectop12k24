#ifndef MAESTROS_H
#define MAESTROS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
//creando clase maestros por jose Gallardo 9959-23-106 (menu, insertar, desplegar)
//Creando clase maestros por Andre Gonzalez 9959-23-3117 (Modificar, buscar, borrar)
class maestros
{
	private:
		string id, nombre, telefono, DPI, direccion, Genero, nacionalidad, civil, fechanaci, anoingre;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();

};

#endif // MAESTROS_H
