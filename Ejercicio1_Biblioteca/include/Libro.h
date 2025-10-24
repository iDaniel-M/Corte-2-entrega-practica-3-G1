#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

public:
    explicit Libro(const std::string& titulo, const std::string& autor, const std::string& isbn);
    ~Libro() = default;

    void mostrarInformacion() const;
    bool estaDisponible() const noexcept;
    void prestar() noexcept;
    void devolver() noexcept;

    const std::string& getTitulo() const noexcept;
    const std::string& getAutor() const noexcept;
    const std::string& getISBN() const noexcept;
};

#endif // LIBRO_H
