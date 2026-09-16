#ifndef LISTAPACIENTE_H
#define LISTAPACIENTE_H
#include "Paciente.h"

class ListaPaciente
{
private:
    struct Nodo
    {

        Paciente paciente;
        Nodo *siguiente;
        Nodo(Paciente paciente)
        {

            this->paciente = paciente;
            this->siguiente = nullptr;
        }
    };

    Nodo *inicio;

public:

    //constructor de la lista
    ListaPaciente();

    // Agregar un paciente a la lista
    void agregarPaciente(Paciente paciente);
    // Retirar un paciente de la lista
    bool buscarPaciente(std::string id);
    // Revisar si la lista no tiene pacientes
    bool estaVacia();
    // Mostrar los pacientes que están esperando
    void mostrarPaciente();

    // Destructor de la lista
    ~ListaPaciente();
};

#endif
