#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;
//Creando CRUD jose Gallardo 9959-23-106 (menu, insertar, desplegar)
//Creando CRUD Andre Gonzalez 9959-23-3117 (Modificar, Buscar, Borrar)
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
void maestros::menu()
{
    int opcion;
	char continuar;
	do
    {
		system("cls");
		system("color E");

		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE MAESTROS |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Maestro                 |"<<endl;
		cout<<"|            2. Mostrar Maestro                 |"<<endl;
		cout<<"|            3. Modificar Maestro               |"<<endl;
		cout<<"|            4. Buscar Maestro                  |"<<endl;
		cout<<"|            5. Borrar Maestro                  |"<<endl;
		cout<<"|            6. Salir del programa              |"<<endl;
		cout<<"|            7. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/6/7]      |"<<endl;
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
					cout<<" -> ¿Deseas ingresar a otro Maestros? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
				break;
			case 2:
				desplegar();
				break;
			case 3:
                modificar();
			case 4:
                buscar();
			case 5:
                borrar();
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
void maestros::insertar()
{
    system("cls");
    fstream archivo,archivomaestros;
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Maestro              |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    srand(time(NULL));
    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    id = "9959-" + to_string(year) + "-" + to_string(numAleatorio);
    cout<<"       -> Generando carnet del maestros: " << id << endl;

    cout<<"       -> Ingrese el nombre del maestros:  ";
    cin>> nombre;

    cout<<"       -> Ingrese el Genero del maestros: ";
    cin>> Genero;

    cout<<"       -> Ingrese la DPI del maestros: ";
    cin>> DPI;

    cout<<"       -> Ingrese la nacionalidad del maestros: ";
    cin>> nacionalidad;

    cout<<"       -> Ingrese la direccion del maestros: ";
    cin>> direccion;

    cout<<"       -> Ingrese el telefono del maestros: ";
    cin>> telefono;

    cout<<"       -> Ingrese el estado civil del maestros: ";
    cin >> civil;

    cout<<"       -> Ingrese la fecha de nacimiento del maestros: ";
    cin >> fechanaci;

    cout<<"       -> Ingrese el ano de ingreso del maestros: ";
    cin >> anoingre;

    cout<<"+---------------------------------------------------------+"<< endl;

    archivo.open("RegistroMaestros.txt", ios::app | ios::out);
    archivo<<left<<setw(15)<<id<<left<<setw(15)<<nombre<<left<<setw(15)<<Genero<<left<<setw(15)<<DPI<<left<<setw(15)<< nacionalidad<<left<<setw(15)<<direccion<<left<<setw(15)<<telefono<<left<<setw(15)<<civil<<left<<setw(15)<<fechanaci<<left<<setw(15)<<anoingre<<"\n";
    archivo.close();

    //-------------------------------------------------------------------------------------------------------------------
        string usuario = nombre;

        string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*";
        string contrasena;
        for (int i = 0; i < 8; i++) {
            contrasena += caracteres[rand() % caracteres.length()];
        }

        archivomaestros.open("UsuariosMaestros.txt", ios::app | ios::out);
        archivomaestros<<left<<setw(15)<<usuario<<left<<setw(15)<<contrasena<<"\n";
        archivomaestros.close();
    //-------------------------------------------------------------------------------------------------------------------

}
void maestros::desplegar()
{
	system("cls");
	fstream archivo;
	int total=0;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                            Tabla de Detalles del Maestro                        +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	archivo.open("RegistroMaestros.txt",ios::in);
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
    cout<<"                        Mostrando -> ID del Maestro: "<<id <<endl;
    cout<<"                        Mostrando -> Nombre del Maestro: "  << nombre << endl;
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
void maestros::buscar()
{
	system("cls");
	fstream archivo;
	int encontrado=0;
	archivo.open("RegistroMaestros.txt",ios::in);
	if(!archivo)
	{
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		cout<<"+                        Detalles del Maestro Buscado                      +"<<endl;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;

		cout<<"No hay información...";
	}
	else
	{
		string idPersona;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		cout<<"+                        Detalles del Maestro Buscada                      +"<<endl;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;

		cout<<"                Ingrese el ID del Maestro que desea buscar: ";
		cin>>idPersona;
        cout<<"+-----------------------------------------------------------------------------+"<<endl;
		archivo >> id >> nombre >> Genero >> DPI >> nacionalidad >> direccion >> telefono >> civil >> fechanaci >> anoingre;
		while(!archivo.eof())
		{
			if(idPersona==id)
			{
        cout<<"                        Mostrando -> ID del Maestro: "<<id <<endl;
    cout<<"                        Mostrando -> Nombre del Maestro: "  << nombre << endl;
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

