#include "../include/Sistema.h"
#include <fstream>
#include <cstring> // Para strncpy

void Sistema::agregarEstudiante(int id, std::string nombre, std::string apellido) {
    // make_shared es la forma moderna y segura de crear punteros
    auto nuevo = std::make_shared<Estudiante>(id, nombre, apellido);
    listaEstudiantes.push_back(nuevo);
}

void Sistema::guardarBinario() {
    std::ofstream archivo("data/datos.bin", std::ios::binary);
    if (!archivo) return;

    for (const auto& est : listaEstudiantes) {
        EstudianteRecord record;
        record.id = est->getId();
        // Convertimos string a char[] de forma segura
        strncpy(record.nombre, est->getNombre().c_str(), 49);
        strncpy(record.apellido, est->getApellido().c_str(), 49);
        record.promedio = est->calcularPromedio();

        // Escribimos el bloque de bytes
        archivo.write(reinterpret_cast<char*>(&record), sizeof(EstudianteRecord));
    }
    archivo.close();
    std::cout << "Base de datos guardada.\n";
}

void Sistema::cargarBinario() {
    std::ifstream archivo("data/datos.bin", std::ios::binary);
    if (!archivo) return;

    EstudianteRecord record;
    // Leemos registro por registro
    while (archivo.read(reinterpret_cast<char*>(&record), sizeof(EstudianteRecord))) {
        agregarEstudiante(record.id, record.nombre, record.apellido);
        // Nota: En este ejemplo simple no guardamos las notas individuales en el binario,
        // solo el estudiante base. Para guardar notas necesitarías lógica extra.
    }
    archivo.close();
}
