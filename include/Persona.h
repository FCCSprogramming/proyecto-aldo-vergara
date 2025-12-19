#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    int id;
    std::string nombre;
    std::string apellido;

public:
    Persona(int id, std::string nombre, std::string apellido);
    virtual ~Persona() = default; // Destructor virtual importante

    // Métodos virtuales puros (3.3)
    virtual void mostrarInfo() const = 0; 
    
    // Método virtual normal
    virtual float calcularDesempeno() const { return 0.0f; }

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
};

#endif
