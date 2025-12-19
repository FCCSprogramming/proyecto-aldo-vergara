// src/Estudiante.cpp
#include "../include/Estudiante.h"
#include <iostream>

Estudiante::Estudiante(int id, std::string nombre, std::string apellido) 
    : Persona(id, nombre, apellido) {
    
    // 3.1: Asignación dinámica manual (new)
    historial = new RegistroNotas;
    historial->capacidad = 10;
    historial->cantidad = 0;
    historial->notas = new float[historial->capacidad];
}

Estudiante::~Estudiante() {
    // 3.1: Liberación manual (delete)
    delete[] historial->notas;
    delete historial;
    std::cout << "Memoria de notas liberada para estudiante " << id << "\n";
}

void Estudiante::agregarNota(float nota) {
    if (historial->cantidad < historial->capacidad) {
        historial->notas[historial->cantidad] = nota;
        historial->cantidad++;
    } else {
        std::cout << "Capacidad de notas llena (Implementar resize si deseas)\n";
    }
}

float Estudiante::calcularDesempeño() const {
    if (historial->cantidad == 0) return 0.0f;
    float suma = 0;
    for(int i = 0; i < historial->cantidad; i++) {
        suma += historial->notas[i];
    }
    return suma / historial->cantidad;
}

// ... Implementar constructor copia es OBLIGATORIO si usas punteros crudos ...
