#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

struct RegistroNotas {
    float* notas;     
    int cantidad;      
    int capacidad;     
};

class Estudiante : public Persona {
private:
    RegistroNotas* historial; 
public:
    Estudiante(int id, std::string nombre, std::string apellido);
    
    ~Estudiante() override;                  
    Estudiante(const Estudiante& other);     
    
    void agregarNota(float nota);
    float calcularPromedio() const;

    void mostrarInfo() const override;
};

#endif
