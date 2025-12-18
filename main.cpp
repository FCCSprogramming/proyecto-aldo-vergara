#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected: 
    // Protected permite que 'Estudiante' acceda a estas variables
    int id;
    std::string nombre;
    std::string apellido;

public:
    Persona(int id, std::string nombre, std::string apellido);
    virtual ~Persona() = default; // Destructor virtual es OBLIGATORIO en herencia

    // Método virtual puro: obliga a las clases hijas a implementarlo
    virtual void mostrarInfo() const = 0;

    // Getters
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
};

#endif
