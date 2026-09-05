#include "../include/Persona.h"

Persona::Persona()
{

    this->id = "";
    this->nombre = "";
    this->edad = 0;
}
Persona::Persona(std::string id, std::string nombre, int edad)
{
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
}

std::string Persona::getId()
{
    return this->id;
}

std::string Persona::getNombre()
{
    return this->nombre;
}
int Persona::getEdad()
{
    return this->edad;
}

Persona::~Persona()
{
}
