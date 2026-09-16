#include "../include/Hospital.h"
#include <iostream>


// Constructor del hospital
Hospital::Hospital()
{
    // Al inicio no hay servicios creados
    this->primerServicio = nullptr;

    // Servicios fijos del hospital
    agregarServicio("Urgencias");
    agregarServicio("Medicina General");
    agregarServicio("Cardiologia");
    agregarServicio("Neurologia");
    agregarServicio("Traumatologia");
    agregarServicio("Cirugia");
    agregarServicio("Pediatria");
    agregarServicio("Hospitalizacion");
}


// Agregar un servicio a la lista enlazada
void Hospital::agregarServicio(std::string nombre)
{
    // Crear un nuevo nodo que contiene un servicio
    NodoServicio *nuevo = new NodoServicio(nombre);

    // Si todavía no existen servicios
    if (this->primerServicio == nullptr)
    {
        this->primerServicio = nuevo;
    }
    else
    {
        // Comenzamos desde el primer servicio
        NodoServicio *actual = this->primerServicio;

        // Avanzamos hasta llegar al último nodo
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }

        // Conectamos el último nodo con el nuevo
        actual->siguiente = nuevo;
    }
}


// Buscar un servicio por su nombre
Servicio *Hospital::buscarServicio(std::string nombre)
{
    NodoServicio *actual = this->primerServicio;

    while (actual != nullptr)
    {
        // Si encontramos el servicio
        if (actual->servicio.getNombre() == nombre)
        {
            // Devolvemos la dirección del servicio encontrado
            return &(actual->servicio);
        }

        // Avanzamos al siguiente nodo
        actual = actual->siguiente;
    }

    // Si no encontramos el servicio
    return nullptr;
}


// Agregar un paciente al servicio correspondiente
bool Hospital::agregarPacienteServicio(Paciente paciente)
{
    // Buscar el servicio indicado en el paciente
    Servicio *servicioEncontrado =
        buscarServicio(paciente.getServicio());

    // Si el servicio no existe
    if (servicioEncontrado == nullptr)
    {
        return false;
    }

    // Agregar paciente al servicio
    servicioEncontrado->agregarPaciente(paciente);

    return true;
}


// Mostrar todos los servicios
void Hospital::mostrarServicios()
{
    NodoServicio *actual = this->primerServicio;

    while (actual != nullptr)
    {
        std::cout << actual->servicio.getNombre()
                  << std::endl;

        actual = actual->siguiente;
    }
}


// Mostrar los pacientes de un servicio específico
void Hospital::mostrarPacientesServicio(std::string nombre)
{
    Servicio *servicioEncontrado =
        buscarServicio(nombre);

    // Si el servicio no existe
    if (servicioEncontrado == nullptr)
    {
        std::cout << "Servicio no encontrado"
                  << std::endl;

        return;
    }

    std::cout << "\nServicio: "
              << servicioEncontrado->getNombre()
              << std::endl;

    // Mostrar pacientes del servicio
    servicioEncontrado->mostrarPacientes();
}


// Destructor del hospital
Hospital::~Hospital()
{
    // Eliminar todos los nodos de servicios
    while (this->primerServicio != nullptr)
    {
        NodoServicio *actual =
            this->primerServicio;

        // Avanzar primerServicio
        this->primerServicio =
            this->primerServicio->siguiente;

        // Liberar el nodo anterior
        delete actual;
    }
}