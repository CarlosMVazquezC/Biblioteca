//
// Created by Admin on 02/04/2024.
//

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "Libro.h"
#include "Revista.h"
#include "Persona.h"

class Biblioteca {
private:
    std::vector<Libro*> libros;
    std::vector<Revista*> revistas;

public:
    Biblioteca();
    ~Biblioteca();

    void agregarLibro(Libro* libro);
    void agregarRevista(Revista* revista);
    void eliminarLibro(std::string titulo);
    void eliminarRevista(std::string titulo);
    void mostrarLibros();
    void mostrarRevistas();
    void prestarLibro(std::string titulo, Persona* persona);
    void prestarRevista(std::string titulo);
    void devolverLibro(std::string titulo);
    void devolverRevista(std::string titulo);
    void mostrarLibrosPrestados();
    void mostrarRevistasPrestadas();
};

#endif // BIBLIOTECA_H
