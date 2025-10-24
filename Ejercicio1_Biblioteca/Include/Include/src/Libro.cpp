#include "../include/Libro.h"
#include <iostream>

// Constructor
Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(true) {}

// Métodos
void Libro::mostrarInformacion() const {
    std::cout << "Título: " << titulo
              << " | Autor: " << autor
              << " | ISBN: " << isbn
              << " | Estado: " << (disponible ? "Disponible" : "Prestado") << std::endl;
}

bool Libro::estaDisponible() const noexcept {
    return disponible;
}

void Libro::prestar() noexcept {
    if (disponible) {
        disponible = false;
    } else {
        std::cout << "Aviso: el libro ya está prestado." << std::endl;
    }
}

void Libro::devolver() noexcept {
    if (!disponible) {
        disponible = true;
    } else {
        std::cout << "Aviso: el libro ya estaba disponible." << std::endl;
    }
}

// Getters
const std::string& Libro::getTitulo() const noexcept { return titulo; }
const std::string& Libro::getAutor() const noexcept { return autor; }
const std::string& Libro::getISBN() const noexcept { return isbn; }
