#include "usuarios.h"

usuarios::usuarios() {
    readFromFile();
}

void usuarios::saveToFile() {
    system("cls");
    ofstream file("users.dat", ios::binary);
    if (!file) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (const auto& user : users) {
        file.write(user.username.c_str(), user.username.size() + 1);
        file.write(user.password.c_str(), user.password.size() + 1);
    }

    file.close();
}

void usuarios::readFromFile() {
    system("cls");
    ifstream file("users.dat", ios::binary);
    if (!file) {
        cerr << "El archivo de usuarios no existe todavía." << endl;
        return;
    }

    while (!file.eof()) {
        User user;
        char buffer[256];
        file.read(buffer, sizeof(buffer));
        if (file.gcount() == 0)
            break;
        user.username = buffer;
        file.read(buffer, sizeof(buffer));
        user.password = buffer;
        users.push_back(user);
    }

    file.close();
}

void usuarios::createUser() {
    system("cls");
    User newUser;
    cout << "Ingrese el nombre de usuario: ";
    cin >> newUser.username;
    cout << "Ingrese la contraseña: ";
    cin >> newUser.password;
    users.push_back(newUser);
    saveToFile();
}

void usuarios::readUsers() {
    if (users.empty()) {
        cout << "No hay usuarios registrados." << endl;
        return;
    }
    cout << "Usuarios registrados:" << endl;
    for (const auto& user : users) {
        cout << "Nombre de usuario: " << user.username << ", Contraseña: " << user.password << endl;
    }
}

void usuarios::updateUser() {
    system("cls");
    if (users.empty()) {
        cout << "No hay usuarios para actualizar." << endl;
        return;
    }

    string username;
    cout << "Ingrese el nombre de usuario que desea actualizar: ";
    cin >> username;

    for (auto& user : users) {
        if (user.username == username) {
            cout << "Ingrese la nueva contraseña: ";
            cin >> user.password;
            saveToFile();
            cout << "Usuario actualizado exitosamente." << endl;
            return;
        }
    }

    cout << "No se encontró el usuario especificado." << endl;
}

void usuarios::deleteUser() {
    system("cls");
    if (users.empty()) {
        cout << "No hay usuarios para eliminar." << endl;
        return;
    }

    string username;
    cout << "Ingrese el nombre de usuario que desea eliminar: ";
    cin >> username;

    auto it = users.begin();
    while (it != users.end()) {
        if (it->username == username) {
            it = users.erase(it);
            saveToFile();
            cout << "Usuario eliminado exitosamente." << endl;
            return;
        } else {
            ++it;
        }
    }

    cout << "No se encontró el usuario especificado." << endl;
}

void usuarios::run() {
    system("cls");
    char option;
    do {
        cout << "+-----------------------------------------------+" << endl;
        cout << "|  Bienvenido al sistema de la Univeridad umg   |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|            1. Creacion De Usuario             |" << endl;
        cout << "|            2. Leer Usuario                    |" << endl;
        cout << "|            3. Actulizar Usuario               |" << endl;
        cout << "|            5. Eliminar Usuario                |" << endl;
        cout << "|            6. Salida                          |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|        Ingrese su opcion [1/2/3/4/5/6]        |" << endl;
        cout << "+-----------------------------------------------+" << endl;
        cin >> option;

        switch (option) {
            case '1':
                system("cls");
                createUser();
                break;
            case '2':
                system("cls");
                readUsers();
                break;
            case '3':
                system("cls");
                updateUser();
                break;
            case '4':
                system("cls");
                deleteUser();
                break;
            case '5':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (option != '5');
}
