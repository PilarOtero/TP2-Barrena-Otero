#Versión de CMake 
cmake_minimum_required(VERSION 3.10)

#Nombre del Proyecto
project(project2)

#Estandar de C++
set(CMAKE_CXX_STANDARD 17)

#Archivos fuente 
file(GLOB SOURCES "src/*.cpp" "example/*.cpp")

#Creación del ejecutable
add_executable(project2 ${SOURCES})

#Directorio de los Headers (.h)
target_include_directories(project2 PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Carpeta de creación del ejecutable
set_target_properties(project2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)