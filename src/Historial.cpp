#include "../include/Historial.h"
#include <iostream>


Historial::Historial()
{
   this->tope = nullptr; 

}


void Historial::registrarAtencion(Paciente paciente){

    Nodo* nuevo = new Nodo(paciente); 
    nuevo->siguiente = this->tope; 
    this->tope = nuevo; 


}


bool Historial::estaVacio(){
    return this->tope == nullptr;


}

void Historial::mostrarHistorial(){

    Nodo* actual = this->tope; 
    //recorremos la pila 
    while(actual != nullptr){
         std::cout << "Nombre: " <<actual->paciente.getNombre() << std::endl;
         std::cout << "Edad: " <<actual->paciente.getEdad() << std::endl;
         std::cout << "Servicio:" <<actual->paciente.getServicio() << std::endl;
         std::cout << "-------------------------------" << std::endl;
         actual = actual->siguiente; 

        
    }


}

Historial::~Historial() {
   while (this->tope != nullptr){

    Nodo* actual = this->tope;
    this->tope = this->tope->siguiente;
    delete actual; 
   }

}

