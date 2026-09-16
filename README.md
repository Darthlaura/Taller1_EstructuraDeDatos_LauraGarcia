# Taller 1 - Estructura de Datos
## Gestión de Pacientes - Hospital Marmaja

Proyecto desarrollado para la asignatura **Estructura de Datos**, correspondiente al **II Semestre 2026**.

El objetivo del proyecto es desarrollar un sistema básico de gestión de pacientes de un hospital utilizando **C++**, programación orientada a objetos, herencia, punteros, aritmética de punteros, memoria dinámica, listas enlazadas, cola y pila implementadas manualmente.

---

## Integrante

- **Nombre:** Laura García Pérez
- **RUT:** 26427429-k
- **GitHub:** Darthlaura
- **Carrera:** ITI
- **Paralelo:** C2

---

## Descripción del sistema

El sistema permite cargar pacientes desde un archivo de texto y almacenarlos en una cola de espera respetando el orden en que aparecen en el archivo.

Cada paciente posee:

- ID.
- Nombre.
- Edad.
- Servicio al que debe ser derivado.

El flujo principal implementado es:

```text
Archivo
   ↓
Queue de pacientes
   ↓
Atención
   ↓
Servicio correspondiente
   ↓
Lista enlazada de pacientes
```

Al mismo tiempo, cada paciente atendido es registrado en el historial:

```text
Paciente atendido
       ↓
Historial de atenciones
       ↓
Stack / Pila
```

Cuando un paciente es atendido:

1. Se retira de la cola de pacientes pendientes.
2. Se identifica el servicio correspondiente.
3. Se incorpora a la lista enlazada de pacientes de ese servicio.
4. Se registra la atención en el historial.

---

# Estructuras de datos implementadas

## Queue - ColaPacientes

La cola de pacientes pendientes fue implementada manualmente mediante nodos y punteros, sin utilizar `std::queue`.

La estructura utiliza el comportamiento **FIFO**:

```text
First In, First Out
```

Esto significa que el primer paciente que ingresa es el primero en ser atendido.

Ejemplo:

```text
frente
   ↓
Juan → Maria → Pedro → nullptr
```

Juan será el primer paciente en salir de la cola.

La clase encargada de esta estructura es:

```text
ColaPacientes
```

---

## Linked List - Lista principal de servicios

El hospital se representa mediante una lista enlazada principal implementada manualmente.

Cada nodo de esta lista contiene un objeto de tipo `Servicio`.

Los servicios disponibles son:

1. Urgencias
2. Medicina General
3. Cardiologia
4. Neurologia
5. Traumatologia
6. Cirugia
7. Pediatria
8. Hospitalizacion

La estructura general es:

```text
Hospital
   ↓
Urgencias
   ↓
Medicina General
   ↓
Cardiologia
   ↓
Neurologia
   ↓
Traumatologia
   ↓
Cirugia
   ↓
Pediatria
   ↓
Hospitalizacion
   ↓
nullptr
```

---

## Linked List - Pacientes por servicio

Cada objeto `Servicio` contiene su propia lista enlazada de pacientes.

Ejemplo:

```text
Cardiologia
     ↓
Juan → Pedro → nullptr
```

La clase encargada de administrar esta estructura es:

```text
ListaPaciente
```

La lista permite:

- Insertar pacientes.
- Buscar pacientes por ID.
- Recorrer sus nodos.
- Mostrar la información de los pacientes.
- Liberar correctamente la memoria utilizada.

---

## Stack - Historial

El historial de atenciones fue implementado manualmente mediante una pila utilizando nodos y punteros, sin utilizar `std::stack`.

La estructura utiliza el comportamiento **LIFO**:

```text
Last In, First Out
```

La última atención registrada es la primera que aparece al consultar el historial.

Ejemplo:

```text
tope
 ↓
Pedro
 ↓
Maria
 ↓
Juan
 ↓
nullptr
```

La clase encargada de esta estructura es:

```text
Historial
```

---

# Programación Orientada a Objetos

El programa utiliza diferentes clases con responsabilidades separadas.

Las principales clases son:

```text
Persona
Paciente
ColaPacientes
ListaPaciente
Servicio
Historial
Hospital
```

---

## Herencia

Se implementó una jerarquía de clases mediante:

```text
Persona
   ↑
Paciente
```

`Persona` corresponde a la clase base y contiene los datos generales:

- ID.
- Nombre.
- Edad.

`Paciente` corresponde a la clase derivada y hereda los atributos de `Persona`, agregando el servicio hospitalario al que debe ser derivado.

---

## Composición

El sistema también utiliza composición entre distintas clases.

El objeto `Hospital` contiene:

```text
Hospital
├── ColaPacientes
├── Historial
└── Lista enlazada de Servicios
```

Cada objeto `Servicio` contiene:

```text
Servicio
└── ListaPaciente
```

De esta forma, cada clase mantiene una responsabilidad específica dentro del sistema.

---

# Clase Hospital

La clase `Hospital` coordina las principales operaciones del programa.

Entre sus responsabilidades se encuentran:

- Crear y administrar los servicios.
- Cargar pacientes desde archivo.
- Administrar la cola de pacientes.
- Atender pacientes.
- Derivar pacientes a su servicio.
- Registrar las atenciones.
- Buscar pacientes.
- Consultar los servicios.
- Mostrar el estado general del hospital.
- Consultar el historial.

Esto permite mantener el archivo `main.cpp` enfocado principalmente en la interfaz de consola y el menú del sistema.

---

# Punteros y memoria dinámica

Las estructuras de datos solicitadas fueron implementadas utilizando punteros y memoria dinámica.

Se utiliza:

```cpp
new
```

para crear nodos dinámicamente.

También se utiliza:

```cpp
delete
```

y:

```cpp
delete[]
```

para liberar correctamente la memoria.

Las clases que administran estructuras dinámicas poseen destructores encargados de eliminar los nodos almacenados.

---

# Aritmética de punteros

El programa utiliza aritmética de punteros durante la creación de los servicios del hospital.

Los nombres de los servicios se almacenan temporalmente en un arreglo dinámico:

```cpp
std::string *servicios = new std::string[8];
```

Se utiliza un puntero para recorrer las posiciones del arreglo:

```cpp
std::string *actual = servicios;

while (actual < servicios + 8)
{
    agregarServicio(*actual);
    actual++;
}
```

En esta operación:

```text
*actual
```

permite acceder al elemento almacenado en la posición apuntada.

Mientras que:

```text
actual++
```

permite avanzar hacia la siguiente posición del arreglo.

Al terminar el proceso, la memoria se libera utilizando:

```cpp
delete[] servicios;
```

---

# Archivo de entrada

Los pacientes son cargados desde:

```text
data/pacientes.txt
```

El formato utilizado es:

```text
ID;Nombre;Edad;Servicio
```

Ejemplo:

```text
001;Juan Perez;25;Cardiologia
002;Maria Soto;65;Urgencias
003;Pedro Rojas;43;Cirugia
004;Ana Lopez;8;Pediatria
005;Carlos Diaz;51;Neurologia
```

Los pacientes se incorporan a la Queue en el mismo orden en que aparecen en el archivo.

---

# Validaciones implementadas

El programa controla diferentes errores y casos borde.

Entre ellos:

- Archivo inexistente.
- Líneas inválidas.
- Líneas incompletas.
- Campos vacíos.
- Edad inválida.
- Servicio inexistente.
- IDs de pacientes duplicados.
- Cola de pacientes vacía.
- Historial vacío.
- Servicios sin pacientes.
- Cantidad de pacientes a atender inválida.
- Búsqueda de pacientes inexistentes.

La detección de IDs duplicados considera tanto:

```text
Pacientes pendientes en la Queue
                +
Pacientes que ya fueron derivados a servicios
```

De esta forma, un paciente no puede volver a ser ingresado únicamente porque ya haya salido de la cola.

---

# Búsqueda de pacientes

El sistema permite buscar un paciente utilizando su ID.

La búsqueda considera primero la cola de pacientes pendientes y luego las listas enlazadas de todos los servicios.

El sistema informa si el paciente se encuentra:

```text
Estado: En espera
```

o:

```text
Estado: Atendido
```

También muestra:

- ID.
- Nombre.
- Edad.
- Servicio.

---

# Estado general de los servicios

El programa permite recorrer la lista enlazada principal de servicios y mostrar el estado de cada uno.

Para cada servicio se muestran sus pacientes asociados.

Cuando un servicio no posee pacientes, el sistema informa:

```text
Sin pacientes
```

---

# Menú principal

Al ejecutar el programa se muestra el siguiente menú:

```text
==============================
     SISTEMA DEL HOSPITAL
==============================
1. Cargar pacientes desde archivo
2. Mostrar pacientes en espera
3. Atender pacientes
4. Mostrar pacientes de un servicio
5. Mostrar historial de atenciones
6. Mostrar servicios del hospital
7. Buscar paciente por ID
8. Mostrar estado general de servicios
0. Salir
```

---

# Organización del proyecto

```text
Taller1_EstructuraDeDatos_LauraGarcia/
│
├── data/
│   └── pacientes.txt
│
├── include/
│   ├── Persona.h
│   ├── Paciente.h
│   ├── ColaPacientes.h
│   ├── ListaPaciente.h
│   ├── Servicio.h
│   ├── Historial.h
│   └── Hospital.h
│
├── src/
│   ├── Persona.cpp
│   ├── Paciente.cpp
│   ├── ColaPacientes.cpp
│   ├── ListaPaciente.cpp
│   ├── Servicio.cpp
│   ├── Historial.cpp
│   └── Hospital.cpp
│
├── main.cpp
└── README.md
```

---

# Compilación

Para compilar el proyecto, posicionarse en la carpeta raíz del repositorio y ejecutar:

```bash
g++ -Iinclude main.cpp src/Persona.cpp src/Paciente.cpp src/ColaPacientes.cpp src/ListaPaciente.cpp src/Servicio.cpp src/Historial.cpp src/Hospital.cpp -o taller
```

Si la compilación finaliza correctamente, se generará el ejecutable:

```text
taller
```

---

# Ejecución

Para ejecutar el programa:

```bash
./taller
```

---

# Ejemplo de flujo de ejecución

Una ejecución típica puede seguir el siguiente orden:

```text
1. Cargar pacientes desde archivo

2. Mostrar pacientes en espera

3. Atender una cantidad determinada de pacientes

4. Consultar pacientes de un servicio

5. Revisar historial

7. Buscar paciente por ID

8. Mostrar estado general de servicios

0. Salir
```

El flujo interno de un paciente atendido es:

```text
pacientes.txt
     ↓
ColaPacientes
     ↓
Paciente retirado mediante FIFO
     ↓
Servicio correspondiente
     ↓
ListaPaciente

Paciente atendido
     ↓
Historial
     ↓
Stack LIFO
```

---

# Liberación de memoria

Las estructuras dinámicas cuentan con destructores para liberar la memoria utilizada.

Los nodos pertenecientes a:

- ColaPacientes.
- ListaPaciente.
- Historial.
- Lista enlazada de servicios.

son eliminados correctamente al finalizar la ejecución.

Esto permite evitar dejar nodos dinámicos almacenados después de que las estructuras dejan de utilizarse.

---

# Tecnologías utilizadas

- C++
- g++
- Git
- GitHub
- GitHub Codespaces
- Visual Studio Code

---


El programa utiliza programación orientada a objetos, herencia, composición, memoria dinámica, punteros y aritmética de punteros para desarrollar el sistema de gestión de pacientes solicitado.
