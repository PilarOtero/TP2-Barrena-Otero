#Versión de CMake 
cmake_minimum_required(VERSION 3.10)

#Nombre del Proyecto
project(project1)

#Estandar de C++
set(CMAKE_CXX_STANDARD 17)

#Archivos fuente 
file(GLOB SOURCES "src/*.cpp" "example/*.cpp")

#Creación del ejecutable
add_executable(project1 ${SOURCES})

#Directorio de los Headers (.h)
target_include_directories(project1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

#Carpeta de creación del ejecutable
set_target_properties(project1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Mostrar warnings al compilar (según compilador)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project1 PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(project1 PRIVATE /W4 /permissive-)
endif()