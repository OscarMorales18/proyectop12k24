#ifndef JORNADA_H
#define JORNADA_H


using namespace std;

struct Jornada{
    int codigo;
    char nombre[50];
};
class JornadaCRUD {
public:
    void Ingresar();
    void Modificar();
    void Borrar();
    void Desplegar();
    void CrudJornada();

};

#endif // JORNADA_H
