#include "../include/ColaPaciente.h"
#include <iostream>


// Constructor de la cola
ColaPacientes::ColaPacientes()
{
    // Al crear la cola todavía no hay pacientes
    this->frente = nullptr;
    this->final = nullptr;
}


// Agregra un paciente al final de la cola
void ColaPacientes::agregarPaciente(Paciente paciente)
{
    // Crear un nuevo nodo y almacenar al paciente dentro
    Nodo* nuevo = new Nodo(paciente);

    // Si la cola está vacía
    if (this->frente == nullptr)
    {
        // El nuevo nodo será el primero y también el último
        this->frente = nuevo;
        this->final = nuevo;
    }
    else
    {
        // El último nodo apunta al nuevo nodo
        this->final->siguiente = nuevo;

        // Ahora el nuevo nodo pasa a ser el último
        this->final = nuevo;
    }
}


// Retira al paciente que está al frente de la cola
bool ColaPacientes::retirarPaciente(Paciente& paciente)
{
    // Si la cola está vacía no puedo retirar nada
    if (this->frente == nullptr)
    {
        return false;
    }

    // Guardar temporalmente la dirección del primer nodo
    Nodo* auxiliar = this->frente;

    // Copiar el paciente que voy a retirar
    paciente = auxiliar->paciente;

    // El frente avanza al siguiente nodo
    this->frente = this->frente->siguiente;

    // Si después de retirar el paciente la cola quedó vacía
    if (this->frente == nullptr)
    {
        this->final = nullptr;
    }

    // Libero de memoria el nodo que retiré
    delete auxiliar;

    return true;
}


// Revisa si la cola está vacía
bool ColaPacientes::estaVacia()
{
    return this->frente == nullptr;
}


// Muestra todos los pacientes que están esperando
void ColaPacientes::mostrarPaciente()
{
    // Comienza desde el primer nodo
    Nodo* auxiliar = this->frente;

    // Recorrer la cola hasta llegar al final
    while (auxiliar != nullptr)
    {
        std::cout << "ID: " << auxiliar->paciente.getId() << std::endl;
        std::cout << "Nombre: " << auxiliar->paciente.getNombre() << std::endl;
        std::cout << "Edad: " << auxiliar->paciente.getEdad() << std::endl;
        std::cout << "Servicio: " << auxiliar->paciente.getServicio() << std::endl;
        std::cout << "------------------------" << std::endl;

        // Avanzo al siguiente nodo
        auxiliar = auxiliar->siguiente;
    }
}


// Destructor de la cola
ColaPacientes::~ColaPacientes()
{
    // Recorrer todos los nodos para liberar su memoria
    while (this->frente != nullptr)
    {
        Nodo* auxiliar = this->frente;

        this->frente = this->frente->siguiente;

        delete auxiliar;
    }

    // Al terminar ya no queda ningún nodo
    this->final = nullptr;
}