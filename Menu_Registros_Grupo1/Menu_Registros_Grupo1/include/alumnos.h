#ifndef ALUMNOS_H
#define ALUMNOS_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

// Creado por Andy Garcia 9959-23-1494

class alumnos
{
    private:
    string id, nombre, telefono, DPI, direccion, Genero, nacionalidad, civil, fechanaci, anoingre;

    public:
        alumnos() {}

        alumnos(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre);
        string setid(string id);
        string getid();

        string setnombre(string nombre);
        string getnombre();

        string setTelefono(string telefono);
        string getTelefono();

        string setDPI(string DPI);
        string getDPI();

        string setdireccion(string direccion);
        string getdireccion();

        string setGenero(string Genero);
        string getGenero();

        string setnacionalidad(string nacionalidad);
        string getnacionalidad();

        string setcivil(string civil);
        string getcivil();

        string setfechanaci(string fechanaci);
        string getfechanaci();

        string setanoingre(string anoingre);
        string getanoingre();

    void menu();
    void insertar();
    void desplegar();
    void modificar();
    void buscar();
    void borrar();

    struct Alumno {
    char id[20];
    char nombre[50];
    char Genero[10];
    char DPI[20];
    char direccion[100];
    char nacionalidad[50];
    char telefono[15];
    char civil[20];
    char fechanaci[20];
    char anoingre[10];
};
};

#endif // ALUMNOS_H
