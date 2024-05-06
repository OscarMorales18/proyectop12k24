#include "Registro.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <maestros.h>
#include <alumnos.h>

using namespace std;

// Creado por Victo Samayoa Ortiz  9959-23-3424

void Registro::menuR()
{
    int elec;

    std::cout << "+-----------------------------------------------------------+" << std::endl;
    std::cout << "+             Registro de Alumnos y Maestros                +" << std::endl;
    std::cout << "+-----------------------------------------------------------+" << std::endl;
    std::cout << "    Indique si quiere agregar a un alumno o a un maestro    +" << std::endl;
    std::cout << "+-----------------------------------------------------------+" << std::endl;
    do
    {
        std::cout << "       ->Ingrese su respuesta (alumno=1|maestros=2): ";
        std::cin >> elec;
        std::cout << "+-----------------------------------------------------------+" << std::endl;

    } while ((elec != 1) && (elec != 2));

    if (elec == 1)
    {
        alumnos Ralumnos;
        Ralumnos.menu();
    }
    else if (elec == 2)
    {
        maestros maestro;
        maestro.menu();
    }
}
