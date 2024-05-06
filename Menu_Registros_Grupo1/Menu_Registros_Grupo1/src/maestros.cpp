#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
#include "maestros.h"

using namespace std;
//Creando CRUD jose Gallardo 9959-23-106 (menu, insertar, desplegar)
//Creando CRUD Andre Gonzalez 9959-23-3117 (Modificar, Buscar, Borrar)


maestros::maestros(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre)
{//creado por Jose Gallardo 9959-23-106
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
    this->DPI = DPI;
    this->direccion = direccion;
    this->Genero = Genero;
    this->nacionalidad = nacionalidad;
    this->civil = civil;
    this->fechanaci = fechanaci;
    this->anoingre = anoingre;
}

//sets y gets de datos maestros creado por Jose Gallardo 9959-23-106
string maestros::setid(string id)
{
    this->id = id;
    return id;
}

string maestros::getid()
{
    return id;
}

string maestros::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

string maestros::getnombre()
{
    return nombre;
}

string maestros::setTelefono(string telefono)
{
    this->telefono = telefono;
    return telefono;
}

string maestros::getTelefono()
{
    return telefono;
}

string maestros::setDPI(string DPI)
{
    this->DPI = DPI;
    return DPI;
}

string maestros::getDPI()
{
    return DPI;
}

string maestros::setdireccion(string direccion)
{
    this->direccion = direccion;
    return direccion;
}

string maestros::getdireccion()
{
    return direccion;
}

string maestros::setGenero(string Genero)
{
    this->Genero = Genero;
    return Genero;
}

string maestros::getGenero()
{
    return Genero;
}

string maestros::setnacionalidad(string nacionalidad)
{
    this->nacionalidad = nacionalidad;
    return nacionalidad;
}

string maestros::getnacionalidad()
{
    return nacionalidad;
}

string maestros::setcivil(string civil)
{
    this->civil = civil;
    return civil;
}

string maestros::getcivil()
{
    return civil;
}

string maestros::setfechanaci(string fechanaci)
{
    this->fechanaci = fechanaci;
    return fechanaci;
}

string maestros::getfechanaci()
{
    return fechanaci;
}

string maestros::setanoingre(string anoingre)
{
    this->anoingre = anoingre;
    return anoingre;
}

string maestros::getanoingre()
{
    return anoingre;
}

void maestros::menu()
{
    int opcion;
	char continuar;
	do
    {
		system("cls");


		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE MAESTROS |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Maestro                 |"<<endl;
		cout<<"|            2. Mostrar Maestro                 |"<<endl;
		cout<<"|            3. Modificar Maestro               |"<<endl;
		cout<<"|            4. Borrar Maestro                  |"<<endl;
		cout<<"|            5. Salir del programa              |"<<endl;
		cout<<"|            6. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/6]        |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cin>>opcion;

		srand(getpid());
        int year = 24;
        int numAleatorio = rand() % 10000;

		switch(opcion)
		{
			case 1:
				do
				{
					insertar();
					cout<<" -> �Deseas ingresar a otro Maestros? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
				break;
			case 2:
				desplegar();
				break;
			case 3:
                modificar();

			case 4:
                borrar();
			case 5:
				exit(0);
				break;
            case 6:
				break;
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    }while(opcion != 6);
}
void maestros::insertar()//modificado por Jose Gallardo 9959-23-106
{
    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Maestro          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;
    srand(time(NULL));

    Maestro maestro;

    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        maestro.id[i] = idString[i];
    }
    maestro.id[idString.length()] = '\0';

    cout<<"       -> Generando carnet del maestro: " << maestro.id<<endl;
    cin.ignore();
    cout<<"       -> Ingrese el nombre del maestro:  ";
    cin.getline(maestro.nombre, 50);


    cout<<"       -> Ingrese el Genero del maestro: ";
    cin.getline(maestro.Genero, 10);


    cout<<"       -> Ingrese la DPI del maestro: ";
    cin.getline(maestro.DPI, 20);

    cout<<"       -> Ingrese la nacionalidad del maestro: ";
    cin.getline(maestro.nacionalidad, 100);


    cout<<"       -> Ingrese la direccion del maestro: ";
    cin.getline(maestro.direccion, 50);


    cout<<"       -> Ingrese el telefono del maestro: ";
    cin.getline(maestro.telefono, 15);


    cout<<"       -> Ingrese el estado civil del maestro: ";
    cin.getline(maestro.civil, 20);


    cout<<"       -> Ingrese la fecha de nacimiento del maestro: ";
    cin.getline(maestro.fechanaci, 20);


    cout<<"       -> Ingrese el ano de ingreso del maestro: ";
    cin.getline(maestro.anoingre, 10);

    cout<<"+---------------------------------------------------------+"<< endl;

    ofstream archivo("Maestros.bin", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&maestro), sizeof(maestro));
    archivo.close();
    //-------------------------------------------------------------------------------------------------------------------

}
void maestros::desplegar()//modificado por Jose Gallardo 9959-23-106
{
	system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    ifstream archivo("Maestros.bin", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }
    Maestro maestro;
    while (archivo.read(reinterpret_cast<char*>(&maestro), sizeof(Maestro))) {

        cout << "                        Mostrando -> ID del Maestro: " << maestro.id << endl;
        cout << "                        Mostrando -> Nombre del Maestro: " << maestro.nombre << endl;
        cout << "                        Mostrando -> Genero: " << maestro.Genero << endl;
        cout << "                        Mostrando -> DPI : " << maestro.DPI << endl;
        cout << "                        Mostrando -> Direccion: " << maestro.direccion << endl;
        cout << "                        Mostrando -> Nacionalidad: " << maestro.nacionalidad << endl;
        cout << "                        Mostrando -> Telefono: " << maestro.telefono << endl;
        cout << "                        Mostrando -> Estado Civil: " << maestro.civil << endl;
        cout << "                        Mostrando -> Fecha de nacimiento: " << maestro.fechanaci << endl;
        cout << "                        Mostrando -> Ano de ingreso: " << maestro.anoingre << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
void maestros::modificar()
{
	system("cls");
	fstream archivo, archivoTemporal;
	string idPersona;
	int encontrado=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                       Modificar Detalles del Maestro                         +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

	archivo.open("RegistroMaestros.txt",ios::in);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		archivo.close();
	}
	else
	{
		cout<<"-> Ingrese el ID de la persona que desea modificar: ";
		cin>>idPersona;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
		archivoTemporal.open("Temporal.txt",ios::app | ios::out);
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		while(!archivo.eof())
		{
			if(idPersona != id)
			{
				archivoTemporal<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
			}
			else
			{
				cout<<" -> Ingrese el nuevo ID del Maestro: ";
				cin>>id;
				cout<<" -> Ingrese el nuevo nombre del Maestro: ";
				cin>>nombre;
				cout<<" -> Ingrese el nuevo Genero del Maestro: ";
				cin>>Genero;
				cout<<" -> Ingrese la nueva DPI del Maestro: ";
				cin>>DPI;
				cout<<" -> Ingrese la nueva nacionalidad del Maestro: ";
                cin >>nacionalidad;
				cout<<" -> Ingrese la nueva direccion del Maestro: ";
				cin>>direccion;
				cout<<" -> Ingrese el nuevo Telefono del estuantes: ";
				cin>>telefono;
				cout<<" -> Ingrese el nuevo estado civil del Maestro: ";
                cin >> civil;
                cout<<" -> Ingrese la nueva fecha de nacimiento del Maestro: ";
                cin >> fechanaci;
                cout<<" -> Ingrese el nuevo ano de ingreso del Maestro: ";
                cin >> anoingre;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

				archivoTemporal<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
				encontrado++;
			}
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;

		}
		archivoTemporal.close();
		archivo.close();
		remove("RegistroMaestros.txt");
		rename("Temporal.txt","RegistroMaestros.txt");
	}
}

void maestros::borrar()
{
	system("cls");
	fstream archivo, archivoTemporal;
	string idPersona;
	int encontrado=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Maestro                                    +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

	archivo.open("RegistroMaestros.txt",ios::in);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		archivo.close();
	}
	else
	{
		cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
		cin>>idPersona;
        cout<<"+---------------------------------------------------------------------------------+"<<endl;
		archivoTemporal.open("Temporal.txt",ios::app | ios::out);
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		while(!archivo.eof())
		{
			if(idPersona != id)
			{
				archivoTemporal<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
			}
			else
			{
			    cout << "El Maestro llamado: " << nombre << "a sido eliminado con exito.";
                encontrado++;
			}
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;

		}
		archivoTemporal.close();
		archivo.close();
		remove("RegistroMaestros.txt");
		rename("Temporal.txt","RegistroMaestros.txt");
	}
}

