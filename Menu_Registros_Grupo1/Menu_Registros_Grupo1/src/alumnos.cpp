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
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Estudiante          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;
    srand(time(NULL));

    Alumno alumno;

    int year = 24;
    int numAleatorio = (rand() % 9998) + 1;

    // Generar el ID como una cadena de caracteres
    string idString = "9959-" + to_string(year) + "-" + to_string(numAleatorio);

    // Copiar la cadena de caracteres en el campo 'id' de la estructura 'Alumno'
    for (int i = 0; i < idString.length(); ++i) {
        alumno.id[i] = idString[i];
    }
    alumno.id[idString.length()] = '\0';
    cout<<"       -> Generando carnet del estudiante: " << alumno.id << endl;

    cout<<"       -> Ingrese el nombre del estudiante:  ";
    cin>> alumno.nombre;

    cout<<"       -> Ingrese el Genero del estudiante: ";
    cin>> alumno.Genero;

    cout<<"       -> Ingrese la DPI del estudiante: ";
    cin>> alumno.DPI;

    cout<<"       -> Ingrese la nacionalidad del estudiante: ";
    cin>> alumno.nacionalidad;

    cout<<"       -> Ingrese la direccion del estudiante: ";
    cin>> alumno.direccion;

    cout<<"       -> Ingrese el telefono del estudiante: ";
    cin>> alumno.telefono;

    cout<<"       -> Ingrese el estado civil del estudiante: ";
    cin >> alumno.civil;

    cout<<"       -> Ingrese la fecha de nacimiento del estudiante: ";
    cin >> alumno.fechanaci;

    cout<<"       -> Ingrese el ano de ingreso del estudiante: ";
    cin >> alumno.anoingre;

    cout<<"+---------------------------------------------------------+"<< endl;

    ofstream archivo("Personas.bin", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&alumno), sizeof(alumno));
    archivo.close();
}



void alumnos::desplegar() {
    system("cls");

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Estudiante                     +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    ifstream archivo("Personas.bin", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error, no se encuentra informacion...";
        return;
    }
    Alumno alumno;
    while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno)))
    {
        alumno.id[sizeof(alumno.id) - 1] = '\0';
        alumno.nombre[sizeof(alumno.nombre) - 1] = '\0';
        alumno.Genero[sizeof(alumno.Genero) - 1] = '\0';
        alumno.DPI[sizeof(alumno.DPI) - 1] = '\0';
        alumno.direccion[sizeof(alumno.direccion) - 1] = '\0';
        alumno.nacionalidad[sizeof(alumno.nacionalidad) - 1] = '\0';
        alumno.telefono[sizeof(alumno.telefono) - 1] = '\0';
        alumno.civil[sizeof(alumno.civil) - 1] = '\0';
        alumno.fechanaci[sizeof(alumno.fechanaci) - 1] = '\0';
        alumno.anoingre[sizeof(alumno.anoingre) - 1] = '\0';

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
/*void alumnos::imprimirRegistro(fstream &leerDeArchivo) {
    ofstream archivoImprimirSalida("imprimir.txt", ios::out);

    // salir del programa si ofstream no puede crear el archivo
    if (!archivoImprimirSalida) {
        cerr << "No se pudo crear el archivo." << endl;
        exit(1);
    }

    archivoImprimirSalida << left << setw(10) << "Cuenta" << setw(16)
                          << "Apellido" << setw(14) << "Primer nombre" << right
                          << setw(10) << "Saldo" << endl;

    // colocar el apuntador de posición de archivo al principio del archivo de registros
    leerDeArchivo.seekg(0);

    // leer el primer registro del archivo de registros
    alumnos cliente;
    leerDeArchivo.read(reinterpret_cast<char *>(&cliente),
                       sizeof(alumnos));

    // copiar todos los registros del archivo de registros en el archivo de texto
    while (!leerDeArchivo.eof()) {

        // escribir un registro individual en el archivo de texto
        if (cliente.obtenerNumeroCuenta() != 0)
            mostrarLinea(archivoImprimirSalida, cliente);

        // leer siguiente registro del archivo de registros
        leerDeArchivo.read(reinterpret_cast<char *>(&cliente),
                           sizeof(alumnos));
    }
}
*/

