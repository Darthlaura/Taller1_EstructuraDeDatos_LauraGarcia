#include "../include/Paciente.h"

Paciente::Paciente()
    : Persona()
{
    this->servicio = "";
}

Paciente::Paciente(std::string id,std::string nombre,int edad,std::string servicio): 

Persona(id, nombre, edad){
    this->servicio = servicio;
}

std::string Paciente::getServicio(){
    return this->servicio;
}

Paciente::~Paciente(){

    
}