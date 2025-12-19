#include "../include/Estudiante.h"
#include <iostream>

Estudiante::Estudiante(int id, std::string nombre, std::string apellido)
    : Persona(id, nombre, apellido) {
    
    // ASIGNACIÓN DE MEMORIA MANUAL (Requisito 3.1)
    historial = new RegistroNotas;       // Creamos el struct
    historial->capacidad = 5;            // Capacidad inicial
    historial->cantidad = 0;
    historial->notas = new float[5];     // Creamos el array dentro del struct
}

Estudiante::~Estudiante() {
    // LIBERACIÓN DE MEMORIA MANUAL
    // El orden importa: primero lo de adentro, luego el contenedor
    if (historial) {
        delete[] historial->notas; // Borra el array
        delete historial;          // Borra el struct
    }
}

Estudiante::Estudiante(const Estudiante& other) 
    : Persona(other.id, other.nombre, other.apellido) {
    
    // COPIA PROFUNDA (Deep Copy)
    // No podemos copiar solo el puntero, debemos crear nueva memoria
    historial = new RegistroNotas;
    historial->capacidad = other.historial->capacidad;
    historial->cantidad = other.historial->cantidad;
    historial->notas = new float[historial->capacidad];

    // Copiar los valores uno por uno
    for(int i = 0; i < historial->cantidad; i++) {
        historial->notas[i] = other.historial->notas[i];
    }
}

void Estudiante::agregarNota(float nota) {
    if (historial->cantidad < historial->capacidad) {
        historial->notas[historial->cantidad] = nota;
        historial->cantidad++;
    } else {
        std::cout << "Memoria llena (en este ejemplo simple no redimensionamos)\n";
    }
}

float Estudiante::calcularPromedio() const {
    if (historial->cantidad == 0) return 0.0f;
    float suma = 0;
    for(int i = 0; i < historial->cantidad; i++) {
        suma += historial->notas[i];
    }
    return suma / historial->cantidad;
}

void Estudiante::mostrarInfo() const {
    std::cout << "ID: " << id << " | " << nombre << " " << apellido 
              << " | Promedio: " << calcularPromedio() << "\n";
}
