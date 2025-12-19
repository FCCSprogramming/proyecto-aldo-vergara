#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <memory> // Para smart pointers
#include "Estudiante.h"
#include "Curso.h"

class Sistema {
private:
    // Requerimiento 3.4: Uso de unique_ptr o shared_ptr
    std::vector<std::shared_ptr<Estudiante>> estudiantes;
    std::vector<std::shared_ptr<Curso>> cursos;

public:
    Sistema();
    void registrarEstudiante();
    void registrarCurso();
    void inscribirEstudiante();
    void listarEstudiantes();
    
    // Requerimiento 3.5: Archivos
    void guardarBD(); // Binario
    void cargarBD();  // Binario
    void exportarReporte(); // Texto .txt
    void buscarEstudiantePorID(); // Acceso aleatorio (simulado o directo)
};

#endif
