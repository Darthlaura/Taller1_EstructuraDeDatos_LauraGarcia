//Autor: Laura Garcia
//rut: 26427429-k
//Carrera: ITI
//Paralelo: C2
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