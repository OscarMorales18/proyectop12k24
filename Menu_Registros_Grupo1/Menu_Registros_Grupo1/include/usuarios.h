#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class usuarios
{
private:
    struct User {
        string username;
        string password;
    };
    vector<User> users;
    void saveToFile();
    void readFromFile();
public:
    usuarios();
    void createUser();
    void readUsers();
    void updateUser();
    void deleteUser();
    void run();
};


#endif // USUARIOS_H
