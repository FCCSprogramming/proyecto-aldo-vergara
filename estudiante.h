#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

// 1. Definimos la estructura que vivirá en memoria dinámica
struct RegistroNotas {
    float* notas;      // Array dinámico de floats
    int cantidad;      // Cuántas notas tiene actualmente
    int capacidad;     // Cuántas notas caben antes de redimensionar
};

class Estudiante : public Persona {
private:
    RegistroNotas* historial; // Puntero "crudo" (Raw pointer)

public:
    Estudiante(int id, std::string nombre, std::string apellido);
    
    // REGLA DE LOS TRES (Necesaria cuando usas new/delete manual)
    ~Estudiante() override;                  // 1. Destructor
    Estudiante(const Estudiante& other);     // 2. Constructor Copia
    
    void agregarNota(float nota);
    float calcularPromedio() const;

    // Sobrescribimos el método del padre
    void mostrarInfo() const override;
};

#endif
