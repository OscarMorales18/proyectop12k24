#include <iostream>
#include "persona.h"
#include "maestros.h"

using namespace std;

int main()
{
    system("color 9");
    int elec;

    cout<<"         +---------------------------------------------+"<< endl;
    cout << "                |Registro de Alumnos y Maestros|"<< endl;
    cout<<"         +---------------------------------------------+"<< endl;

    cout << "      > Indique si quiere agregar a un alumno o a un maestro" << endl;
    cout<<"       +-----------------------------------------------------+"<< endl;
    do
    {
        cout << "         ->Ingrese su respuesta (alumno=1|maestros=2): ";
        cin >> elec;
    } while ((elec!=1) && (elec!=2));

    if (elec==1)
    {
        persona persona;
    persona.menu();
    }
    else if (elec==2)
    {
        maestros maestro;
        maestro.menu();
    }


    return 0;
}
