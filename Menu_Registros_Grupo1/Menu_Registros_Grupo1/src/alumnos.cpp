#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

class alumnos
{
    private:
    string id, nombre, telefono, DPI, direccion, Genero, nacionalidad, civil, fechanaci, anoingre;

    public:
        alumnos() {}

        alumnos(string id,string nombre,string telefono,string DPI,string direccion,string Genero,string nacionalidad,string civil,string fechanaci,string anoingre);

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

alumnos::alumnos(string id, string nombre, string telefono, string DPI, string direccion, string Genero, string nacionalidad, string civil, string fechanaci, string anoingre)
{
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


string alumnos::setid(string id)
{
    this->id = id;
    return id;
}

string alumnos::getid()
{
    return id;
}

string alumnos::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

string alumnos::getnombre()
{
    return nombre;
}

string alumnos::setTelefono(string telefono)
{
    this->telefono = telefono;
    return telefono;
}

string alumnos::getTelefono()
{
    return telefono;
}

string alumnos::setDPI(string DPI)
{
    this->DPI = DPI;
    return DPI;
}

string alumnos::getDPI()
{
    return DPI;
}

string alumnos::setdireccion(string direccion)
{
    this->direccion = direccion;
    return direccion;
}

string alumnos::getdireccion()
{
    return direccion;
}

string alumnos::setGenero(string Genero)
{
    this->Genero = Genero;
    return Genero;
}

string alumnos::getGenero()
{
    return Genero;
}

string alumnos::setnacionalidad(string nacionalidad)
{
    this->nacionalidad = nacionalidad;
    return nacionalidad;
}

string alumnos::getnacionalidad()
{
    return nacionalidad;
}

string alumnos::setcivil(string civil)
{
    this->civil = civil;
    return civil;
}

string alumnos::getcivil()
{
    return civil;
}

string alumnos::setfechanaci(string fechanaci)
{
    this->fechanaci = fechanaci;
    return fechanaci;
}

string alumnos::getfechanaci()
{
    return fechanaci;
}

string alumnos::setanoingre(string anoingre)
{
    this->anoingre = anoingre;
    return anoingre;
}

string alumnos::getanoingre()
{
    return anoingre;
}
void alumnos::menu()
{
    int opcion;
	char continuar;
	do
    {
		system("cls");
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE ALUMNOS  |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Estudiante              |"<<endl;
		cout<<"|            2. Mostrar Estudiante              |"<<endl;
		cout<<"|            3. Modificar Estudiante            |"<<endl;
		cout<<"|            4. Borrar Estudiante               |"<<endl;
		cout<<"|            5. Salir del programa              |"<<endl;
		cout<<"|            6. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|         Ingrese su opcion [1/2/3/4/5/6]       |"<<endl;
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
			    borrar();
				break;
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
void alumnos::insertar()
{
    system("cls");
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Estudiante          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;
    srand(time(NULL));

    Alumno alumno;

    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        alumno.id[i] = idString[i];
    }
    alumno.id[idString.length()] = '\0';

    cout<<"       -> Generando carnet del estudiante: " << alumno.id<<endl;
    cin.ignore();
    cout<<"       -> Ingrese el nombre del estudiante:  ";
    cin.getline(alumno.nombre, 50);


    cout<<"       -> Ingrese el Genero del estudiante: ";
    cin.getline(alumno.Genero, 10);


    cout<<"       -> Ingrese la DPI del estudiante: ";
    cin.getline(alumno.DPI, 20);

    cout<<"       -> Ingrese la nacionalidad del estudiante: ";
    cin.getline(alumno.nacionalidad, 100);


    cout<<"       -> Ingrese la direccion del estudiante: ";
    cin.getline(alumno.direccion, 50);


    cout<<"       -> Ingrese el telefono del estudiante: ";
    cin.getline(alumno.telefono, 15);


    cout<<"       -> Ingrese el estado civil del estudiante: ";
    cin.getline(alumno.civil, 20);


    cout<<"       -> Ingrese la fecha de nacimiento del estudiante: ";
    cin.getline(alumno.fechanaci, 20);


    cout<<"       -> Ingrese el ano de ingreso del estudiante: ";
    cin.getline(alumno.anoingre, 10);

    cout<<"+---------------------------------------------------------+"<< endl;

    ofstream archivo("Alumnos.bin", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&alumno), sizeof(alumno));
    archivo.close();
}

void alumnos::desplegar() {
    system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    ifstream archivo("Alumnos.bin", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }
    Alumno alumno;
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {

        cout << "                        Mostrando -> ID del estudiante: " << alumno.id << endl;
        cout << "                        Mostrando -> Nombre del estudiante: " << alumno.nombre << endl;
        cout << "                        Mostrando -> Genero: " << alumno.Genero << endl;
        cout << "                        Mostrando -> DPI : " << alumno.DPI << endl;
        cout << "                        Mostrando -> Direccion: " << alumno.direccion << endl;
        cout << "                        Mostrando -> Nacionalidad: " << alumno.nacionalidad << endl;
        cout << "                        Mostrando -> Telefono: " << alumno.telefono << endl;
        cout << "                        Mostrando -> Estado Civil: " << alumno.civil << endl;
        cout << "                        Mostrando -> Fecha de nacimiento: " << alumno.fechanaci << endl;
        cout << "                        Mostrando -> Ano de ingreso: " << alumno.anoingre << endl;
        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void alumnos::modificar()
{
	system("cls");
    fstream archivo;
    string idPersona;
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del estudiante                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    archivo.open("Alumnos.bin", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }

    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    Alumno alumno;
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        if (alumno.id == idPersona) {
            encontrado = true;
            cout << "Ingrese el nuevo ID del estudiante: ";
            cin >> alumno.id;
            cout << "Ingrese el nuevo nombre del estudiante: ";
            cin >> alumno.nombre;
            cout << "Ingrese el nuevo Genero del estudiante: ";
            cin >> alumno.Genero;
            cout << "Ingrese la nueva DPI del estudiante: ";
            cin >> alumno.DPI;
            cout << "Ingrese la nueva nacionalidad del estudiante: ";
            cin >> alumno.nacionalidad;
            cout << "Ingrese la nueva direccion del estudiante: ";
            cin >> alumno.direccion;
            cout << "Ingrese el nuevo Telefono del estuantes: ";
            cin >> alumno.telefono;
            cout << "Ingrese el nuevo estado civil del estudiante: ";
            cin >> alumno.civil;
            cout << "Ingrese la nueva fecha de nacimiento del estudiante: ";
            cin >> alumno.fechanaci;
            cout << "Ingrese el nuevo ano de ingreso del estudiante: ";
            cin >> alumno.anoingre;


            archivo.seekp(-static_cast<int>(sizeof(Alumno)), ios::cur);


            archivo.write(reinterpret_cast<char*>(&alumno), sizeof(Alumno));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "No se encontró un estudiante con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void alumnos::borrar()
{
	system("cls");
	string idPersona;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar estudiante                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;

    ifstream archivo("Alumnos.bin", ios::binary);
	if(!archivo)
	{
		cout<<"Error, no se encuentra informacion...";
		return;
	}
	ofstream archivo2("Alumnos2.bin", ios::binary);
	Alumno alumno;

    cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
    cin>>idPersona;
    bool resta = false;
    //cout<<"+---------------------------------------------------------------------------------+"<<endl;
		while(archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno)))
		{
			if(alumno.id != idPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&alumno), sizeof(Alumno));
			}
			else
			{
			    resta = true;
			}

		}

		archivo.close();
		archivo2.close();
		remove("Alumnos.bin");
		rename("Alumnos2.bin","Alumnos.bin");

		if (resta)
        {
        cout << "Alumno eliminado con exito." << endl;
        }
        else
        {
        cout << "No se a podido encontrar el codigo del alumno" << endl;
        }
}
