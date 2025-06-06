#Versión de CMake 
cmake_minimum_required(VERSION 3.10)

#Nombre del Proyecto
project(podekexProject1)

#Estandar de C++
set(CMAKE_CXX_STANDARD 17)

#Archivos fuente 
file(GLOB SOURCES "src/*.cpp" "example/*.cpp")

#Creación del ejecutable
add_executable(pokedexProject1 ${SOURCES})

#Directorio de los Headers (.h)
target_include_directories(pokedexProject1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Carpeta de creación del ejecutable
set_target_properties(pokedexProject1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)