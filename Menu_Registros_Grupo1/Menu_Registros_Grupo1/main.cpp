//Menu General creado por Oscar Morales 9959-23-3070
// apartado de ingreso a submenu creado por Victo Samayoa Ortiz  9959-23-3424
#include <iostream>
#include "Registro.h"

using namespace std;

int main()
{
    system("color C");
    int opcion;
    char continuar;
    do {
        system("cls");

        cout << "+-----------------------------------------------+" << endl;
        cout << "|  Bienvenido al sistema de la Univeridad umg   |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|            1. Catalogo                        |" << endl;
        cout << "|            2. Procesos                        |" << endl;
        cout << "|            3. Reportes                        |" << endl;
        cout << "|            4. Ayuda                           |" << endl;
        cout << "|            5. Gestion de usuarios             |" << endl;
        cout << "|            6. Salida                          |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|        Ingrese su opcion [1/2/3/4/5/6]        |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cout << "Entrando al area de catalogos....."<< endl;
                Registro Registros;
                Registros.menuR();
                break;
            case 2:
                system("cls");
                cout << "Area de procesos....."<< endl;
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Area de reportes....."<< endl;
                system("pause");
                break;
            case 4:
                system("cls");
                cout << "Area de ayuda....."<< endl;
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "Area de gestion de usuarios....."<< endl;
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "Saliendo del programa..." << endl;
                continuar = 'n';
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                break;
        }
    } while (continuar != 'n');

    return 0;
}
