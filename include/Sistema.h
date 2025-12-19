#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <memory> // Para shared_ptr
#include "Estudiante.h"

// Estructura auxiliar SOLO para guardar en archivo
struct EstudianteRecord {
    int id;
    char nombre[50];   // Tamaño fijo
    char apellido[50]; // Tamaño fijo
    float promedio;
};

class Sistema {
private:
    // Punteros Inteligentes (Requisito 3.4)
    std::vector<std::shared_ptr<Estudiante>> listaEstudiantes;

public:
    void agregarEstudiante(int id, std::string nombre, std::string apellido);
    void listarTodos();
    void agregarNotaAEstudiante(int id, float nota);

    // Archivos (Requisito 3.5)
    void guardarBinario();
    void cargarBinario();
    void exportarReporteTexto(); // .txt
};

#endif
