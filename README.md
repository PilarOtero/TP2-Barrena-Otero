# Trabajo Práctico 2

**Integrantes**: Agustina Barrena, Pilar Otero  
**Emails**: abarrena@udesa.edu.ar, potero@udesa.edu.ar  
**Universidad**: Universidad de San Andrés – Departamento de Ingeniería

---

## Introducción

Este trabajo práctico tiene como objetivo implementar y analizar diferentes simulaciones que permiten aplicar conceptos clave de programación en C++, tales como el uso de clases, archivos binarios, estructuras de datos, concurrencia y sincronización con threads.

Se desarrollaron tres ejercicios, cada uno abordando un problema distinto, utilizando una arquitectura modular con archivos fuente separados, headers y un sistema de compilación unificado mediante CMake. 
---

## Estructura del Proyecto

Cada ejercicio se encuentra organizado en subcarpetas con la siguiente estructura:

- `example/`: Contiene el archivo `main.cpp` con las pruebas correspondientes.
- `src/`: Implementación de las funcionalidades principales (clases y lógica).
- `include/`: Archivos `.h` con definiciones de clases y métodos.
- `build/`: Carpeta generada durante la compilación.
- `CMakeLists.txt`: Script de compilación para cada ejercicio.

---

## Ejercicio 1 – Pokedex

### Descripción

Se desarrolla una enciclopedia de Pokemones utilizando un `unordered_map` que relaciona un objeto `Pokemon` con su información (`PokemonInfo`). Esta información es persistente y se guarda en un archivo binario.

---

## Ejercicio 2 – Hangar Automatizado

### Descripción

Simulación del despegue sincronizado de 5 drones ubicados en un círculo dentro de un hangar. Se evita que despeguen al mismo tiempo dos drones adyacentes.

---

## Ejercicio 3 – Sistema de Robots Autónomos

### Descripción

Simula una planta industrial automatizada donde sensores generan tareas que son procesadas por robots autónomos.

---

## Compilación

Para compilar cualquier ejercicio:

1. Instalar CMake:
   - macOS: `brew install cmake`
   - Ubuntu:  
     ```bash
     sudo apt update
     sudo apt install cmake
     ```

2. Crear la carpeta de compilación y entrar:
   ```bash
   mkdir build
   cd build


3. Crear la carpeta de compilación
    mkdir build
    cd build

4. Generar los archivos de compilación
    cmake ..

5. Compilar el proyecto
    make

6. Ejecutar el programa (reemplaza X por el número del ejercicio: 1, 2 o 3)
    ./bin/projectX
