#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include "Servicio.h"
#include "Paciente.h"

class Hospital
{
private:

    // Nodo para formar la lista enlazada de servicios
    struct NodoServicio
    {
        // Cada nodo guarda un servicio
        Servicio servicio;

        // Apunta al siguiente servicio
        NodoServicio *siguiente;

        // Constructor del nodo
        NodoServicio(std::string nombreServicio)
            : servicio(nombreServicio)
        {
            this->siguiente = nullptr;
        }
    };

    // Apunta al primer servicio de la lista
    NodoServicio *primerServicio;

    // Agrega un servicio a la lista enlazada
    void agregarServicio(std::string nombre);

    // Busca un servicio por su nombre
    Servicio *buscarServicio(std::string nombre);

public:

    // Constructor del hospital
    Hospital();

    // Muestra todos los servicios
    void mostrarServicios();

    // Agrega un paciente al servicio correspondiente
    bool agregarPacienteServicio(Paciente paciente);

    // Muestra los pacientes de un servicio
    void mostrarPacientesServicio(std::string nombre);

    // Destructor
    ~Hospital();
};

#endif