#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <vector>

class Curso {
private:
    int idCurso;
    std::string nombre;
    int creditos;

public:
    Curso(int id, std::string n, int c);
    std::string getNombre() const;
    int getId() const;
    void mostrarCurso() const;
};

#endif
