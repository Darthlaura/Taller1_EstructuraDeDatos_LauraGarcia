//Autor: Laura Garcia
//rut: 26427429-k
//Carrera: ITI
//Paralelo: C2
#ifndef PACIENTE_H
#define PACIENTE_H
#include "Persona.h"
#include <string>

class Paciente : public Persona
{
private:
    std::string servicio;

public:
    Paciente();

    Paciente(std::string id, std::string nombre, int edad, std::string servicio);

    std::string getServicio();

    ~Paciente() override;
};

#endif
