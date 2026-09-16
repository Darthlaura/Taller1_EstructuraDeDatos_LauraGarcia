//Autor: Laura Garcia
//rut: 26427429-k
//Carrera: ITI
//Paralelo: C2
#ifndef HiSTORIAL_H
#define HiSTORIAL_H
#include "Paciente.h"

class Historial
{

private:
    // crear un nodo para formar la pila del historial

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
    // nodo que apunta a la atencion mas reciente del paciente
    Nodo *tope;

public:
    // consultar el historial de atencion del paciente
    Historial();

    // agregar una atencion al historial del paciente
    void registrarAtencion(Paciente paciente);
    // revisar si el historial esta vacio
    bool estaVacio();
    // mostrar el historial de atencion del paciente
    void mostrarHistorial();
    // destructor del historial

    ~Historial();
}; 

#endif 

