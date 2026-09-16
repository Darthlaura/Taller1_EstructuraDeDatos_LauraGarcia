#include <iostream>
#include "ColaPacientes.h"
#include "Paciente.h"


int main (){

   Paciente paciente1("001", "Juan Perez", 25, "Cardiología");
   Paciente paciente2("002", "Maria Soto", 65, "Urgencias"); 
   Paciente paciente3("003", "Pedro Rojas", 43, "Cirugia"); 


   ColaPacientes cola;

   cola.agregarPaciente(paciente1);
   cola.agregarPaciente(paciente2);
   cola.agregarPaciente(paciente3);


   std::cout << "===== COLA INICIAL =====" << std::endl;
   cola.mostrarPaciente();

   Paciente pacienteAtendido;
   
   
   if (cola.retirarPaciente(pacienteAtendido)) {
       std::cout << "\nPaciente atendido: " << std::endl; 
       std::cout << pacienteAtendido.getNombre() << std::endl;
   } 


   std::cout <<"\n ====== COLA DESPUES DE RETIRAR ======" << std::endl; 
   cola.mostrarPaciente(); 

   return 0; 

   

   
   





}

