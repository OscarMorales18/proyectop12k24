//Creado por Rocio Guisell Lopez espinoza 9959-23-740

#include "secciones.h"

#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

void SeccionesCrud::CrudSeccion()
{
    int opcion;

    do{


	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|     SISTEMA DE GESTION UMG - Secciones       |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Seccion"<<endl;
	cout<<"\t\t\t 2. Modificar Seccion"<<endl;
	cout<<"\t\t\t 3. Borrar Seccion"<<endl;
	cout<<"\t\t\t 4. Desplegar Seccion"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;


    switch (opcion)
    {
    case 1:
        IngresarSeccion();
        break;
    case 2:
        ModificarSeccion();
        break;
    case 3:
        BorrarSeccion();
        break;
    case 4:
        DesplegarSeccion();
        break;
    case 5:
        break;
    default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
    }
    }while(opcion!= 5);
}

void SeccionesCrud::IngresarSeccion()
{
     system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Seccion--------------------------------------------"<<endl;
    secciones seccion;
    cout << "Ingrese el codigo del Seccion: ";
    cin >> seccion.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del Seccion: ";
    cin.getline(seccion.nombre, 50);

    cout << "Ingrese la estatus de la Seccion: ";
    cin.getline(seccion.estatus, 50);

    ofstream archivo("seccion.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));
    archivo.close();

    cout << "Seccion agregada exitosamente!" << endl;

}


void SeccionesCrud::ModificarSeccion()
{
    int codigo;
    cout << "Ingrese el codigo de la Seccion a modificar: ";
    cin >> codigo;

    fstream archivo("seccion.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay Seccion registradas." << endl;
        return;
    }

    secciones seccion;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        if (seccion.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la Seccion: ";
            cin.ignore();
            cin.getline(seccion.nombre, 50);

            cout << "Ingrese el nuevo estatus de la Seccion: ";
            cin.getline(seccion.estatus, 50);

            archivo.seekp(-static_cast<int>(sizeof(seccion)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la Seccion con el codigo ingresado." << endl;
    } else {
        cout << "Seccion modificada exitosamente!" << endl;
    }


}


void SeccionesCrud::BorrarSeccion()
{
    int codigo;
    cout << "Ingrese el codigo de la Seccion a eliminar: ";
    cin >> codigo;

    ifstream archivo("seccion.dat", ios::binary);
    if (!archivo) {
        cout << "No hay seccion registradas." << endl;

    }

    ofstream archivoTmp("seccion_tmp.dat", ios::binary);
    secciones seccion;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        if (seccion.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&seccion), sizeof(secciones));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("seccion.dat");
    rename("seccion_tmp.dat", "seccion.dat");

    if (eliminada) {
        cout << "seccion eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la seccion con el codigo ingresado." << endl;
    }

}
void SeccionesCrud::DesplegarSeccion()
{
    system("cls");
    cout<<"-----------------Despliegue de seccion registradas---------------------"<<endl;
    ifstream archivo("seccion.dat", ios::binary);
    if (!archivo) {
        cout << "No hay seccion registradas." << endl;
        return;
    }

    secciones seccion;
    while (archivo.read(reinterpret_cast<char*>(&seccion), sizeof(secciones))) {
        cout << "Codigo: " << seccion.codigo << endl;
        cout << "Nombre: " << seccion.nombre << endl;
        cout << "Estatus: " << seccion.estatus << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();

}
