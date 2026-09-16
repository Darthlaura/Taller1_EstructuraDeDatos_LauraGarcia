#include "../include/Hospital.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor del hospital
Hospital::Hospital()
{
    this->primerServicio = nullptr;

    // Arreglo dinámico con los servicios del hospital
    std::string *servicios = new std::string[8]{
        "Urgencias",
        "Medicina General",
        "Cardiologia",
        "Neurologia",
        "Traumatologia",
        "Cirugia",
        "Pediatria",
        "Hospitalizacion"};

    // Puntero que comienza en el primer servicio
    std::string *actual = servicios;

    // Recorrer los 8 servicios usando aritmetica de punteros
    while (actual < servicios + 8)
    {
        agregarServicio(*actual);

        // Avanzar a la siguiente posicion de memoria
        actual++;
    }

    // Liberar el arreglo dinamico
    delete[] servicios;
}

// Agregar un servicio a la lista enlazada
void Hospital::agregarServicio(std::string nombre)
{
    // Crear un nuevo nodo que contiene un servicio
    NodoServicio *nuevo = new NodoServicio(nombre);

    // Si todavía no existen servicios
    if (this->primerServicio == nullptr)
    {
        this->primerServicio = nuevo;
    }
    else
    {
        // Comenzamos desde el primer servicio
        NodoServicio *actual = this->primerServicio;

        // Avanzar hasta llegar al último servicio
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }

        // Conectar el último servicio con el nuevo
        actual->siguiente = nuevo;
    }
}

// Buscar un servicio por su nombre
Servicio *Hospital::buscarServicio(std::string nombre)
{
    NodoServicio *actual = this->primerServicio;

    // Recorrer toda la lista de servicios
    while (actual != nullptr)
    {
        // Si encontramos el servicio
        if (actual->servicio.getNombre() == nombre)
        {
            // Devolver la dirección del servicio encontrado
            return &(actual->servicio);
        }

        // Avanzar al siguiente servicio
        actual = actual->siguiente;
    }

    // Si no encontramos el servicio
    return nullptr;
}

// Agregar paciente a la cola de espera
void Hospital::agregarPacienteCola(Paciente paciente)
{
    this->colaPacientes.agregarPaciente(paciente);
}

// Mostrar los pacientes que están esperando
void Hospital::mostrarCola()
{
    // Revisar si la cola está vacía
    if (this->colaPacientes.estaVacia())
    {
        std::cout << "No hay pacientes en espera"
                  << std::endl;

        return;
    }

    // Mostrar los pacientes de la cola
    this->colaPacientes.mostrarPaciente();
}

// Agregar paciente al servicio correspondiente
bool Hospital::agregarPacienteServicio(Paciente paciente)
{
    // Buscar el servicio indicado en el paciente
    Servicio *servicioEncontrado =
        buscarServicio(paciente.getServicio());

    // Si el servicio no existe
    if (servicioEncontrado == nullptr)
    {
        return false;
    }

    // Agregar al paciente a la lista del servicio
    servicioEncontrado->agregarPaciente(paciente);

    return true;
}

// Atender cierta cantidad de pacientes
void Hospital::atenderPacientes(int cantidad)
{
    // Repetir según la cantidad solicitada
    for (int i = 0; i < cantidad; i++)
    {
        // Aquí guardaremos temporalmente al paciente retirado
        Paciente pacienteAtendido;

        // Intentar retirar al primero de la cola
        bool pacienteRetirado =
            this->colaPacientes.retirarPaciente(pacienteAtendido);

        // Si no quedan pacientes
        if (pacienteRetirado == false)
        {
            std::cout << "No quedan pacientes en espera"
                      << std::endl;

            break;
        }

        // Intentar agregar al paciente a su servicio
        bool servicioEncontrado =
            this->agregarPacienteServicio(pacienteAtendido);

        // Si el servicio existe
        if (servicioEncontrado == true)
        {
            // Registrar al paciente en el historial
            this->historialAtenciones.registrarAtencion(
                pacienteAtendido);

            std::cout << "Paciente atendido: "
                      << pacienteAtendido.getNombre()
                      << std::endl;
        }
        else
        {
            std::cout << "Servicio no encontrado para el paciente: "
                      << pacienteAtendido.getNombre()
                      << std::endl;
        }
    }
}

// Mostrar todos los servicios
void Hospital::mostrarServicios()
{
    NodoServicio *actual = this->primerServicio;

    while (actual != nullptr)
    {
        std::cout << actual->servicio.getNombre()
                  << std::endl;

        actual = actual->siguiente;
    }
}

// Mostrar los pacientes de un servicio específico
void Hospital::mostrarPacientesServicio(std::string nombre)
{
    // Buscar el servicio
    Servicio *servicioEncontrado =
        buscarServicio(nombre);

    // Si el servicio no existe
    if (servicioEncontrado == nullptr)
    {
        std::cout << "Servicio no encontrado"
                  << std::endl;

        return;
    }

    std::cout << "\nServicio: "
              << servicioEncontrado->getNombre()
              << std::endl;

    // Mostrar la lista de pacientes del servicio
    servicioEncontrado->mostrarPacientes();
}

// Mostrar historial de atenciones
void Hospital::mostrarHistorial()
{
    // Revisar si el historial está vacío
    if (this->historialAtenciones.estaVacio())
    {
        std::cout << "El historial esta vacio"
                  << std::endl;

        return;
    }

    // Mostrar historial
    this->historialAtenciones.mostrarHistorial();
}
bool Hospital::cargarPacientesArchivo(std::string rutaArchivo)
{
    std::ifstream archivo(rutaArchivo);

    // Verificar que el archivo exista
    if (!archivo.is_open())
    {
        std::cout << "No se pudo abrir el archivo"
                  << std::endl;

        return false;
    }

    std::string linea;

    while (std::getline(archivo, linea))
    {
        // Ignorar lineas vacias
        if (linea.empty())
        {
            continue;
        }

        std::stringstream datos(linea);

        std::string id;
        std::string nombre;
        std::string edadTexto;
        std::string servicio;

        // Intentar separar los cuatro datos
        if (!std::getline(datos, id, ';') ||
            !std::getline(datos, nombre, ';') ||
            !std::getline(datos, edadTexto, ';') ||
            !std::getline(datos, servicio, ';'))
        {
            std::cout << "Linea invalida: "
                      << linea
                      << std::endl;

            continue;
        }

        // Revisar campos vacios
        if (id.empty() ||
            nombre.empty() ||
            edadTexto.empty() ||
            servicio.empty())
        {
            std::cout << "Linea incompleta: "
                      << linea
                      << std::endl;

            continue;
        }

        // Convertir edad
        int edad;

        std::stringstream convertirEdad(edadTexto);

        if (!(convertirEdad >> edad) || edad < 0)
        {
            std::cout << "Edad invalida: "
                      << linea
                      << std::endl;

            continue;
        }

        // Verificar que el servicio exista
        if (buscarServicio(servicio) == nullptr)
        {
            std::cout << "Servicio invalido: "
                      << servicio
                      << std::endl;

            continue;
        }

        // Verificar ID duplicado
        if (this->pacienteExiste(id))
        {
            std::cout << "ID duplicado: "
                      << id
                      << std::endl;

            continue;
        }

        // Crear paciente
        Paciente paciente(
            id,
            nombre,
            edad,
            servicio);

        // Agregarlo a la cola
        this->colaPacientes.agregarPaciente(paciente);
    }

    archivo.close();

    return true;
}
bool Hospital::pacienteExiste(std::string id)
{
    // Buscar primero en la cola
    if (this->colaPacientes.buscarPaciente(id))
    {
        return true;
    }

    // Buscar en todos los servicios
    NodoServicio *actual = this->primerServicio;

    while (actual != nullptr)
    {
        if (actual->servicio.buscarPaciente(id))
        {
            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}
// Destructor del hospital
Hospital::~Hospital()
{
    // Eliminar todos los nodos de servicios
    while (this->primerServicio != nullptr)
    {
        NodoServicio *actual =
            this->primerServicio;

        // Avanzar primerServicio
        this->primerServicio =
            this->primerServicio->siguiente;

        // Liberar el nodo anterior
        delete actual;
    }
}