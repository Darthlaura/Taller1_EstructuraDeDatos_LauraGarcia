#include "../include/Servicio.h"

Servicio::Servicio(){

this->nombre =""; 


} 

Servicio::Servicio(std::string nombre){
this->nombre = nombre;  


}

std::string Servicio::getNombre()
{
    return this->nombre;
}



// usa el agregar pacientes de la lista de pacientes
void Servicio::agregarPaciente(Paciente paciente ){
   this->pacientes.agregarPaciente(paciente);


}

bool Servicio::buscarPaciente(std::string id){
   return this->pacientes.buscarPaciente(id); 
   

}

void Servicio::mostrarPacientes(){

  this->pacientes.mostrarPaciente();


}

bool Servicio::mostrarPacientePorId(std::string id)
{
    return this->pacientes.mostrarPacientePorId(id);
}


bool Servicio::estaVacio()
{
    return this->pacientes.estaVacia();
}

Servicio::~Servicio(){

}
