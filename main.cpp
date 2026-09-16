#include <iostream>
#include <string>

#include "Hospital.h"


int main()
{
    // Crear el hospital
    Hospital hospital;

    int opcion = -1;


    while (opcion != 0)
    {
        std::cout << "\n==============================" << std::endl;
        std::cout << "     SISTEMA DEL HOSPITAL" << std::endl;
        std::cout << "==============================" << std::endl;

        std::cout << "1. Cargar pacientes desde archivo" << std::endl;
        std::cout << "2. Mostrar pacientes en espera" << std::endl;
        std::cout << "3. Atender pacientes" << std::endl;
        std::cout << "4. Mostrar pacientes de un servicio" << std::endl;
        std::cout << "5. Mostrar historial de atenciones" << std::endl;
        std::cout << "6. Mostrar servicios del hospital" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "\nIngrese una opcion: ";
        std::cin >> opcion;


        if (opcion == 1)
        {
            std::cout << "\n===== CARGAR PACIENTES ====="
                      << std::endl;

            if (hospital.cargarPacientesArchivo(
                    "data/pacientes.txt"))
            {
                std::cout
                    << "Archivo procesado correctamente"
                    << std::endl;
            }
        }


        else if (opcion == 2)
        {
            std::cout << "\n===== PACIENTES EN ESPERA ====="
                      << std::endl;

            hospital.mostrarCola();
        }


        else if (opcion == 3)
        {
            int cantidad;

            std::cout << "\nCantidad de pacientes a atender: ";
            std::cin >> cantidad;


            if (cantidad <= 0)
            {
                std::cout << "Cantidad invalida"
                          << std::endl;
            }
            else
            {
                hospital.atenderPacientes(cantidad);
            }
        }


        else if (opcion == 4)
        {
            std::string servicio;

            // Limpiar el salto de linea que dejo cin
            std::cin.ignore();

            std::cout << "\nIngrese el nombre del servicio: ";

            std::getline(std::cin, servicio);


            hospital.mostrarPacientesServicio(servicio);
        }


        else if (opcion == 5)
        {
            std::cout << "\n===== HISTORIAL ====="
                      << std::endl;

            hospital.mostrarHistorial();
        }


        else if (opcion == 6)
        {
            std::cout << "\n===== SERVICIOS ====="
                      << std::endl;

            hospital.mostrarServicios();
        }


        else if (opcion == 0)
        {
            std::cout << "\nCerrando sistema..."
                      << std::endl;
        }


        else
        {
            std::cout << "\nOpcion invalida"
                      << std::endl;
        }
    }


    return 0;
}