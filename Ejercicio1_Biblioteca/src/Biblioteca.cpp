#include "../include/Biblioteca.h"
#include "../include/Libro.h"
#include <iostream>

using namespace std;

void Biblioteca::agregarLibro(const shared_ptr<Libro>& libro) {
    libros.push_back(libro);
    cout << "Libro agregado: ";
    libro->mostrarInformacion();
}

void Biblioteca::eliminarLibro(const string& isbn) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if ((*it)->getISBN() == isbn) {
            cout << "Libro eliminado: ";
            (*it)->mostrarInformacion();
            libros.erase(it);
            return;
        }
    }
    cout << "No se encontró un libro con ese ISBN." << endl;
}

void Biblioteca::mostrarLibrosDisponibles() const {
    cout << "\nLibros disponibles:\n";
    bool hayDisponibles = false;
    for (const auto& libro : libros) {
        if (libro->estaDisponible()) {
            libro->mostrarInformacion();
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles)
        cout << "No hay libros disponibles actualmente." << endl;
}

void Biblioteca::buscarPorTitulo(const string& titulo) const {
    cout << "\nResultados de búsqueda para \"" << titulo << "\":\n";
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro->getTitulo() == titulo) {
            libro->mostrarInformacion();
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontró ningún libro con ese título." << endl;
}
