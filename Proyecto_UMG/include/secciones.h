//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#ifndef SECCIONES_H
#define SECCIONES_H

#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

struct secciones
{
    int codigo;
    char nombre[45];
    char estatus[1];
};

class SeccionesCrud
{
    public:
        void IngresarSeccion();
        void ModificarSeccion();
        void BorrarSeccion();
        void DesplegarSeccion();
        void CrudSeccion();

};//fin de la clase aula

#endif // SECCIONES_H
