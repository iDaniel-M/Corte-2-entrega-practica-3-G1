#include "../include/Biblioteca.h"
#include "../include/Libro.h"
#include <memory>

int main() {
    Biblioteca biblioteca;

    // Agregar algunos libros
    biblioteca.agregarLibro(std::make_shared<Libro>("Cien años de soledad", "Gabriel García Márquez", "ISBN001"));
    biblioteca.agregarLibro(std::make_shared<Libro>("Don Quijote de la Mancha", "Miguel de Cervantes", "ISBN002"));
    biblioteca.agregarLibro(std::make_shared<Libro>("El Principito", "Antoine de Saint-Exupéry", "ISBN003"));

    // Mostrar libros disponibles
    biblioteca.mostrarLibrosDisponibles();

    // Buscar un libro
    biblioteca.buscarPorTitulo("El Principito");

    // Eliminar un libro
    biblioteca.eliminarLibro("ISBN002");

    // Mostrar de nuevo los libros disponibles
    biblioteca.mostrarLibrosDisponibles();

    return 0;
}
