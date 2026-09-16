#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>

#include "Paciente.h"
#include "Servicio.h"
#include "ColaPacientes.h"
#include "Historial.h"

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

    // Apunta al primer servicio
    NodoServicio *primerServicio;

    // Cola de pacientes esperando atención
    ColaPacientes colaPacientes;

    // Historial de pacientes atendidos
    Historial historialAtenciones;

    // Agregar un servicio a la lista
    void agregarServicio(std::string nombre);

    // Buscar un servicio por nombre
    Servicio *buscarServicio(std::string nombre);

    // Revisar si un paciente ya existe en el hospital
    bool pacienteExiste(std::string id);

public:
    // Constructor
    Hospital();

    // Agregar paciente a la cola
    void agregarPacienteCola(Paciente paciente);

    // Mostrar la cola de pacientes
    void mostrarCola();

    // Atender cierta cantidad de pacientes
    void atenderPacientes(int cantidad);

    // Agregar paciente a su servicio
    bool agregarPacienteServicio(Paciente paciente);

    // Mostrar servicios del hospital
    void mostrarServicios();

    // Mostrar pacientes de un servicio
    void mostrarPacientesServicio(std::string nombre);

    // Mostrar historial de atenciones
    void mostrarHistorial();

    // Cargar pacientes desde un archivo
    bool cargarPacientesArchivo(std::string rutaArchivo);
    // Buscar y mostrar un paciente por su ID
    void buscarPacientePorId(std::string id);

    // Mostrar el estado de todos los servicios
    void mostrarEstadoServicios();
    // Destructor
    ~Hospital();
};

#endif