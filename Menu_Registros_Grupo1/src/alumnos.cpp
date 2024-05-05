#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

// Creado por Andy Garcia 9959-23-1494

class alumnos
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
void alumnos::menu()
{
    int opcion;
	char continuar;
	do
    {
		system("cls");
        system("color B");
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ALUMNOS  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Estudiante              |"<<endl;
		cout<<"|            2. Mostrar Estudiante              |"<<endl;
		cout<<"|            3. Modificar Estudiante            |"<<endl;
		cout<<"|            4. Buscar Estudiante               |"<<endl;
		cout<<"|            5. Borrar Estudiante               |"<<endl;
		cout<<"|            6. Salir del programa              |"<<endl;
		cout<<"|            7. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/6/7]      |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cin>>opcion;

		switch(opcion)
		{
			case 1:
				do
				{
					insertar();
					cout<<" -> ¿Deseas ingresar a otro estudiante? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
				break;
			case 2:
				desplegar();
				break;
			case 3:
				modificar();
				break;
			case 4:
				buscar();
				break;
			case 5:
				borrar();
				break;
			case 6:
				exit(0);
				break;
            case 7:
				break;
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    }while(opcion != 7);
}
void alumnos::insertar()
{
	system("cls");
	fstream archivo,archivousuario;
	cout<<"+---------------------------------------------------------+"<< endl;
	cout<<"|                Agregar detalles del Estudiante          |"<< endl;
	cout<<"+---------------------------------------------------------+"<< endl;
	srand(time(NULL));
    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    id = "9959-" + to_string(year) + "-" + to_string(numAleatorio);
    cout<<"       -> Generando carnet del estudiante: " << id << endl;

	cout<<"       -> Ingrese el nombre del estudiante:  ";
	cin>> nombre;

	cout<<"       -> Ingrese el Genero del estudiante: ";
	cin>> Genero;

	cout<<"       -> Ingrese la DPI del estudiante: ";
	cin>> DPI;

	cout<<"       -> Ingrese la nacionalidad del estudiante: ";
	cin>> nacionalidad;

	cout<<"       -> Ingrese la direccion del estudiante: ";
	cin>> direccion;

    cout<<"       -> Ingrese el telefono del estudiante: ";
	cin>> telefono;

	cout<<"       -> Ingrese el estado civil del estudiante: ";
	cin >> civil;

	cout<<"       -> Ingrese la fecha de nacimiento del estudiante: ";
	cin >> fechanaci;

	cout<<"       -> Ingrese el ano de ingreso del estudiante: ";
	cin >> anoingre;

    cout<<"+---------------------------------------------------------+"<< endl;

	archivo.open("RegistroAlumnos.txt", ios::app | ios::out);
	archivo<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
	archivo.close();

	//-------------------------------------------------------------------------------------------------------------------
        string usuario = nombre;

        string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*";
        string contrasena;
        for (int i = 0; i < 8; i++) {
            contrasena += caracteres[rand() % caracteres.length()];
        }

        archivousuario.open("UsuariosAlumnos.txt", ios::app | ios::out);
        archivousuario<<left<<setw(15)<<usuario<<left<<setw(15)<<contrasena<<"\n";
        archivousuario.close();
    //-------------------------------------------------------------------------------------------------------------------
}
void alumnos::desplegar()
{
	system("cls");
	fstream archivo;
	int total=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                            Tabla de Detalles del Estudiante                     +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	archivo.open("RegistroAlumnos.txt",ios::in);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		while(!archivo.eof())
		{
			total++;
    cout<<"                        Mostrando -> ID del estudiante: "<<id <<endl;
    cout<<"                        Mostrando -> Nombre del estudiante: "  << nombre << endl;
    cout<<"                        Mostrando -> Genero: " << Genero <<endl;
    cout<<"                        Mostrando -> DPI : " << DPI <<endl;
    cout<<"                        Mostrando -> Direccion: " << direccion <<endl;
    cout<<"                        Mostrando -> Nacionalidad: " << nacionalidad << endl;
    cout<<"                        Mostrando -> Telefono:  " << telefono << endl;
    cout<<"                        Mostrando -> Estado Civil:  " << civil << endl;
    cout<<"                        Mostrando -> Fecha de nacimiento:  " << fechanaci << endl;
    cout<<"                        Mostrando -> Ano de ingreso:  " << anoingre << endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

			archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		}
		if(total==0)
		{
			cout<<"Error, no se encuentra informacion...";
			archivo.close();
		}
	}
	archivo.close();
}
void alumnos::modificar()
{
	system("cls");
	fstream archivo, archivoTemporal;
	string idPersona;
	int encontrado=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                       Modificar Detalles del estudiante                         +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

	archivo.open("RegistroAlumnos.txt",ios::in);
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
				cout<<" -> Ingrese el nuevo ID del estudiante: ";
				cin>>id;
				cout<<" -> Ingrese el nuevo nombre del estudiante: ";
				cin>>nombre;
				cout<<" -> Ingrese el nuevo Genero del estudiante: ";
				cin>>Genero;
				cout<<" -> Ingrese la nueva DPI del estudiante: ";
				cin>>DPI;
				cout<<" -> Ingrese la nueva nacionalidad del estudiante: ";
                cin >>nacionalidad;
				cout<<" -> Ingrese la nueva direccion del estudiante: ";
				cin>>direccion;
				cout<<" -> Ingrese el nuevo Telefono del estuantes: ";
				cin>>telefono;
				cout<<" -> Ingrese el nuevo estado civil del estudiante: ";
                cin >> civil;
                cout<<" -> Ingrese la nueva fecha de nacimiento del estudiante: ";
                cin >> fechanaci;
                cout<<" -> Ingrese el nuevo ano de ingreso del estudiante: ";
                cin >> anoingre;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

				archivoTemporal<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
				encontrado++;
			}
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;

		}
		archivoTemporal.close();
		archivo.close();
		remove("RegistroAlumnos.txt");
		rename("Temporal.txt","RegistroAlumnos.txt");
	}
}
void alumnos::buscar()
{
	system("cls");
	fstream archivo;
	int encontrado=0;
	archivo.open("RegistroAlumnos.txt",ios::in);
	if(!archivo)
	{
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		cout<<"+                        Detalles del estudiante Buscado                      +"<<endl;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;

		cout<<"No hay información...";
	}
	else
	{
		string idPersona;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		cout<<"+                        Detalles del estudiante Buscada                      +"<<endl;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;

		cout<<"                Ingrese el ID del estudiante que desea buscar: ";
		cin>>idPersona;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		while(!archivo.eof())
		{
			if(idPersona==id)
			{
        cout<<"                        Mostrando -> ID del estudiante: "<<id <<endl;
    cout<<"                        Mostrando -> Nombre del estudiante: "  << nombre << endl;
    cout<<"                        Mostrando -> Genero: " << Genero <<endl;
    cout<<"                        Mostrando -> DPI : " << DPI <<endl;
    cout<<"                        Mostrando -> Direccion: " << direccion <<endl;
    cout<<"                        Mostrando -> Nacionalidad: " << nacionalidad << endl;
    cout<<"                        Mostrando -> Telefono:  " << telefono << endl;
    cout<<"                        Mostrando -> Estado Civil:  " << civil << endl;
    cout<<"                        Mostrando -> Fecha de nacimiento:  " << fechanaci << endl;
    cout<<"                        Mostrando -> Ano de ingreso:  " << anoingre << endl;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;

				encontrado++;
			}
			archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		}
		if(encontrado==0)
		{
			cout<<"ERROR, ESTUDIANTE NO ENCONTRADO...";
		}
		archivo.close();
	}
}
void alumnos::borrar()
{
	system("cls");
	fstream archivo, archivoTemporal;
	string idPersona;
	int encontrado=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar estudiante                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

	archivo.open("RegistroAlumnos.txt",ios::in);
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
			    cout << "El alumno llamado: " << nombre << "a sido eliminado con exito.";
                encontrado++;
			}
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;

		}
		archivoTemporal.close();
		archivo.close();
		remove("RegistroAlumnos.txt");
		rename("Temporal.txt","RegistroAlumnos.txt");
	}
}
