//Autor: Laura Garcia
//rut: 26427429-k
//Carrera: ITI
//Paralelo: C2
#include "../include/ListaPaciente.h"
#include <iostream>

ListaPaciente::ListaPaciente()
{
    this->inicio = nullptr;
}

void ListaPaciente::agregarPaciente(Paciente paciente)
{

    Nodo *nuevo = new Nodo(paciente);
    // si la lista esta vacia, el inicio apunta al nuevo nodo
    if (this->inicio == nullptr)
    {
        this->inicio = nuevo;
    }
    else
    {
        Nodo *actual = this->inicio;

        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

bool ListaPaciente::buscarPaciente(std::string id)
{
    // comenzar desde el primer nodo
    Nodo *actual = this->inicio;

    // Recorrer todos los nodos

    while (actual != nullptr)
    {

        // comparar el Id del paciente con el id buscado
        if (actual->paciente.getId() == id)
        {
            return true;
        }

        // avanzar al siguiente nodo
        actual = actual->siguiente;
    }
    return false;
}
bool ListaPaciente::estaVacia()
{
    return this->inicio == nullptr;
}

void ListaPaciente::mostrarPaciente()
{

    Nodo *actual = this->inicio;
    while (actual != nullptr)
    {

        std::cout << "ID: " << actual->paciente.getId() << std::endl;
        std::cout << "Nombre: " << actual->paciente.getNombre() << std::endl;
        std::cout << "Edad: " << actual->paciente.getEdad() << std::endl;
        std::cout << "-------------------------------" << std::endl;
        actual = actual->siguiente;
    }
}
bool ListaPaciente::mostrarPacientePorId(std::string id)
{
    Nodo *actual = this->inicio;

    while (actual != nullptr)
    {
        if (actual->paciente.getId() == id)
        {
            std::cout << "ID: "
                      << actual->paciente.getId()
                      << std::endl;

            std::cout << "Nombre: "
                      << actual->paciente.getNombre()
                      << std::endl;

            std::cout << "Edad: "
                      << actual->paciente.getEdad()
                      << std::endl;

            std::cout << "Servicio: "
                      << actual->paciente.getServicio()
                      << std::endl;

            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

ListaPaciente::~ListaPaciente()
{
    while (this->inicio != nullptr)
    {
        Nodo *auxiliar = this->inicio;
        this->inicio = this->inicio->siguiente;
        delete auxiliar;
    }
}
