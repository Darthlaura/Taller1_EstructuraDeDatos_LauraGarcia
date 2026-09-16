#ifndef SERVICIO_H
#define SERVICIO_H
#include <string>
#include "Paciente.h"
#include "ListaPaciente.h"

class Servicio 
{ 
  private: 

  std::string nombre; 
  ListaPaciente pacientes; 

    public:

    //constructor vacio
    Servicio(); 

    // constructor con nombre
    Servicio(std::string nombre);
    
    // obtener el nombre del servicio
    std::string getNombre(); 
    // obtener la lista de pacientes
    void agregarPaciente(Paciente paciente);
    // buscar un paciente por su id
    bool buscarPaciente(std::string id); 
    // Mostrar los pacientes del servicio
    void mostrarPacientes(); 

    ~Servicio();

    


};




#endif 



