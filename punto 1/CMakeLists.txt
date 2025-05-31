#Version de CMake 
cmake_minimum_required(VERSION 3.10)

#Nombre del Poryecto
project(PodekexProject)

#Estandar de C++
set(CMAKE_CXX_STANDARD 17)

#Archivos fuente 
file(GLOB SOURCES "src/*.cpp" "example/*.cpp")

#Creacion del ejecutable
add_executable(pokedexProject ${SOURCES})

#Directorio de los Headers
target_include_directories(pokedexProject PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Carpeta de creacion del ejecutable
set_target_properties(pokedexProject PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)