//Creado por Rocio Guisell Lopez espinoza 9959-23-740
#include "aulas.h"

#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

void AulasCRUD::CrudAula()
{
    int opcion;
    do
    {

	system("cls");
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t|     SISTEMA DE GESTION UMG - Aulas       |"<<endl;
	cout<<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingresar Aula"<<endl;
	cout<<"\t\t\t 2. Modificar Aula"<<endl;
	cout<<"\t\t\t 3. Borrar Aula"<<endl;
	cout<<"\t\t\t 4. Desplegar Aula"<<endl;
	cout<<"\t\t\t 5. Regresar Menu Anterior"<<endl;
    cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\t |   Opcion a escoger:[1|2|3|4|5|]           |"<<endl;
	cout<<"\t\t\t --------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;


     switch(opcion)
    {
	case 1:
        IngresarAula();
		break;
    case 2:
        ModificarAula();
		break;
    case 3:
        BorrarAula();
		break;
    case 4:
        DesplegarAula();
		break;
    case 5:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(opcion!= 5);

}

void AulasCRUD::IngresarAula() {

   system("cls");
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Aula--------------------------------------------"<<endl;
    aulas aula;
    cout << "Ingrese el codigo del aula: ";
    cin >> aula.codigo;
    cin.ignore();

    cout << "Ingrese el nombre del aula: ";
    cin.getline(aula.nombre, 50);

    cout << "Ingrese la estatus de la aula: ";
    cin.getline(aula.estatus, 50);

    ofstream archivo("aulas.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
    archivo.close();

    cout << "aula agregada exitosamente!" << endl;
}

void AulasCRUD::ModificarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a modificar: ";
    cin >> codigo;

    fstream archivo("aulas.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    aulas aula;
    bool encontrada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo == codigo) {
            cout << "Ingrese el nuevo nombre de la aula: ";
            cin.ignore();
            cin.getline(aula.nombre, 50);

            cout << "Ingrese el nuevo estatus de la aula: ";
            cin.getline(aula.estatus, 50);

            archivo.seekp(-static_cast<int>(sizeof(aulas)), ios::cur);
            archivo.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));

            encontrada = true;
            break;
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    } else {
        cout << "aula modificada exitosamente!" << endl;
    }

}

void AulasCRUD::BorrarAula() {
    int codigo;
    cout << "Ingrese el codigo de la aula a eliminar: ";
    cin >> codigo;

    ifstream archivo("aulas.dat", ios::binary);
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;

    }

    ofstream archivoTmp("aulas_tmp.dat", ios::binary);
    aulas aula;
    bool eliminada = false;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        if (aula.codigo != codigo) {
            archivoTmp.write(reinterpret_cast<const char*>(&aula), sizeof(aulas));
        } else {
            eliminada = true;
        }
    }

    archivo.close();
    archivoTmp.close();

    remove("aulas.dat");
    rename("aulas_tmp.dat", "aulas.dat");

    if (eliminada) {
        cout << "aula eliminada exitosamente!" << endl;

    } else {
        cout << "No se encontró la aula con el codigo ingresado." << endl;
    }

}

void AulasCRUD::DesplegarAula() {
    system("cls");
    cout<<"-----------------Despliegue de aulas registradas---------------------"<<endl;
    ifstream archivo("aulas.dat", ios::binary);
    if (!archivo) {
        cout << "No hay aulas registradas." << endl;
        return;
    }

    aulas aula;
    while (archivo.read(reinterpret_cast<char*>(&aula), sizeof(aulas))) {
        cout << "Codigo: " << aula.codigo << endl;
        cout << "Nombre: " << aula.nombre << endl;
        cout << "Estatus: " << aula.estatus << endl;
        cout << "-----------------------------" << endl;
    }

    archivo.close();

    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}



