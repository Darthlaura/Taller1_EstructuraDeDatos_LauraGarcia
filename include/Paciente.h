#ifndef PACIENTE_H
#define PACIENTE_H
#include "Persona.h"
#include <string>

class Paciente : public Persona
{
include
private:
    std::string servicio;

public:
    Paciente();

    Paciente(std::string id, std::string nombre, int edad, std::string servicio);

    std::string getServicio();

    ~Paciente() override;
};

#endif
