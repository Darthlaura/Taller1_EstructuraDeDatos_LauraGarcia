#include <iostream>
#include "ColaPacientes.h"
#include "Paciente.h"
#include "ListaPaciente.h"
#include "Servicio.h"



int main()
{

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

    if (cola.retirarPaciente(pacienteAtendido))
    {
        std::cout << "\nPaciente atendido: " << std::endl;
        std::cout << pacienteAtendido.getNombre() << std::endl;
    }

    std::cout << "\n ====== COLA DESPUES DE RETIRAR ======" << std::endl;
    cola.mostrarPaciente();

    // Crear la lista
    ListaPaciente lista;

    // Agregar pacientes
    lista.agregarPaciente(paciente1);
    lista.agregarPaciente(paciente2);
    lista.agregarPaciente(paciente3);

    std::cout << "===== LISTA DE PACIENTES =====" << std::endl;

    lista.mostrarPaciente();

    // Buscar un paciente
    std::cout << std::endl;
    std::cout << "===== BUSQUEDA =====" << std::endl;

    if (lista.buscarPaciente("002"))
    {
        std::cout << "Paciente encontrado" << std::endl;
    }
    else
    {
        std::cout << "Paciente no encontrado" << std::endl;
    }

    Servicio cardiologia("Cardiologia");

    cardiologia.agregarPaciente(paciente1);
    cardiologia.agregarPaciente(paciente2);

    std::cout << "\n===== SERVICIO =====" << std::endl;

    std::cout << "Servicio: "
              << cardiologia.getNombre()
              << std::endl;

    cardiologia.mostrarPacientes();

    return 0;
}
