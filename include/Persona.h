//Autor: Laura Garcia
//rut: 26427429-k
//Carrera: ITI
//Paralelo: C2
#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona
{

protected:
    std::string id;
    std::string nombre;
    int edad;

public:
    Persona();

    Persona(std::string id, std::string nombre, int edad);

    std::string getId();

    std::string getNombre();

    int getEdad();

    virtual ~Persona();
};

#endif
