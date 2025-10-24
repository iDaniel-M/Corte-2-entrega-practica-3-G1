#pragma once

#include <vector>
#include <memory>
#include <string>

class Libro;

class Biblioteca {
private:
    std::vector<std::shared_ptr<Libro>> libros;

public:
    void agregarLibro(const std::shared_ptr<Libro>& libro);
    void eliminarLibro(const std::string& isbn);
    void mostrarLibrosDisponibles() const;
    void buscarPorTitulo(const std::string& titulo) const;
};
