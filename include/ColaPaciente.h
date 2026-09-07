#ifndef COLAPACIENTES_H
#define COLAPACIENTES_H

#include "Paciente.h"


class ColaPacientes
{
private:

    // creacion del Nodo para formar la cola 
    struct Nodo
    {
        // guardar objeto paciente dentro del nodo 
        Paciente paciente;

        // puntero que guarda la dirección del siguiente nodo
        Nodo* siguiente;


        // Constructor del nodo
        // Recibe un paciente para guardarlo dentro del nodo
        Nodo(Paciente paciente)
        {
            // Guardo el paciente que recibí en este nodo
            this->paciente = paciente;

            // Al crear el nodo todavía no tiene otro nodo después
            this->siguiente = nullptr;
        }
    };


    // Apuntar al primer paciente de la cola
    // Este será el primer paciente que se atiende
    Nodo* frente;

    // Apuntar al último paciente de la cola
    // se irán agregando los pacientes nuevos
    Nodo* final;


public:

    // Constructor de la cola
    ColaPacientes();


    // Agrega un paciente al final de la cola
    void agregarPaciente(Paciente paciente);


    // Retira al paciente que está al frente de la cola
    bool retirarPaciente(Paciente& paciente);


    // Revisa si la cola no tiene pacientes
    bool estaVacia();


    // Muestra los pacientes que están esperando
    void mostrarPaciente();


    // Destructor de la clase ColaPacientes
    // Servirá para liberar los nodos de la memoria
    ~ColaPacientes();
};

#endif