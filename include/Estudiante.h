#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

// Requerimiento 3.1: Estructura para gestión manual de memoria
struct RegistroNotas {
    float* notas; // Array dinámico
    int cantidad;
    int capacidad;
};

class Estudiante : public Persona {
private:
    RegistroNotas* historial; // Puntero crudo (Raw pointer)

public:
    Estudiante(int id, std::string nombre, std::string apellido);
    
    // Constructor Copia (Regla de los 3/5 por usar memoria dinámica)
    Estudiante(const Estudiante& other);
    
    // Destructor (Para el delete del struct)
    ~Estudiante() override;

    void agregarNota(float nota);
    
    // Sobrescitura de virtuales (3.3)
    void mostrarInfo() const override;
    float calcularDesempeño() const override; // Promedio
};

#endif
