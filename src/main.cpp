#include "../include/Sistema.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "\n--- GESTION ACADEMICA ---\n";
    std::cout << "1. Registrar Estudiante\n";
    std::cout << "2. Listar Estudiantes\n";
    std::cout << "3. Agregar Nota\n";
    std::cout << "4. Guardar BD (Binario)\n";
    std::cout << "5. Cargar BD (Binario)\n";
    std::cout << "0. Salir\n";
    std::cout << "Opcion: ";
}

int main() {
    Sistema sistema;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                int id; std::string n, a;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Nombre: "; std::cin >> n;
                std::cout << "Apellido: "; std::cin >> a;
                sistema.agregarEstudiante(id, n, a);
                break;
            }
            case 2:
                sistema.listarTodos(); // Implementa este método en Sistema.cpp
                break;
            case 3:
                // Lógica para buscar ID y agregar nota
                break;
            case 4:
                sistema.guardarBinario();
                break;
            case 5:
                sistema.cargarBinario();
                break;
        }
    } while (opcion != 0);

    return 0;
}
