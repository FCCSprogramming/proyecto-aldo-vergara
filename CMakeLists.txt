cmake_minimum_required(VERSION 3.10)
project(SistemaGestionAcademica)

set(CMAKE_CXX_STANDARD 17)

# Incluir la carpeta de headers
include_directories(include)

# Definir los archivos fuente
set(SOURCES
    src/main.cpp
    src/Persona.cpp
    src/Estudiante.cpp
    src/Curso.cpp
    src/Sistema.cpp
)

# Crear el ejecutable
add_executable(GestionAcademica ${SOURCES})
