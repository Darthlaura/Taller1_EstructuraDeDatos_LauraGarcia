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
