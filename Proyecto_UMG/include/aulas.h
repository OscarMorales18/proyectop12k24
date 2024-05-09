//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#ifndef AULAS_H
#define AULAS_H

#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


struct aulas
{
    int codigo;
    char nombre [45];
    char estatus [1];
};

class AulasCRUD
{
    public:
        void IngresarAula();
        void ModificarAula();
        void BorrarAula();
        void DesplegarAula();
        void CrudAula();


};//fin de la clase aula

#endif // AULAS_H
