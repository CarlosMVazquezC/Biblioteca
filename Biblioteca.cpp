//
// Created by Admin on 02/04/2024.
//

#include "Biblioteca.h"
#include <iostream>

Biblioteca::Biblioteca() {}
Biblioteca::~Biblioteca() {}

void Biblioteca::agregarLibro(Libro* libro) {
    libros.push_back(libro);
}

void Biblioteca::agregarRevista(Revista* revista) {
    revistas.push_back(revista);
}

void Biblioteca::eliminarLibro(std::string titulo) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if ((*it)->getTitulo() == titulo) {
            delete *it;
            libros.erase(it);
            std::cout << "El libro \"" << titulo << "\" ha sido eliminado" << std::endl;
            return;
        }
    }
    std::cout << "El libro \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::eliminarRevista(std::string titulo) {
    for (auto it = revistas.begin(); it != revistas.end(); ++it) {
        if ((*it)->getTitulo() == titulo) {
            delete *it;
            revistas.erase(it);
            std::cout << "La revista \"" << titulo << "\" ha sido eliminada" << std::endl;
            return;
        }
    }
    std::cout << "La revista \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::mostrarLibros() {
    if (libros.empty()) {
        std::cout << "No hay libros en la biblioteca" << std::endl;
        return;
    }
    std::cout << "Libros disponibles en la biblioteca:" << std::endl;
    for (const auto& libro : libros) {
        std::cout << "- " << libro->getTitulo() << " de " << libro->getAutor() << std::endl;
    }
}

void Biblioteca::mostrarRevistas() {
    if (revistas.empty()) {
        std::cout << "No hay revistas en la biblioteca" << std::endl;
        return;
    }
    std::cout << "Revistas disponibles en la biblioteca:" << std::endl;
    for (const auto& revista : revistas) {
        std::cout << "- " << revista->getTitulo() << " (" << revista->getSaga() << ", " << revista->getEstante() << ")" << std::endl;
    }
}

void Biblioteca::prestarLibro(std::string titulo, Persona* persona) {
    for (auto& libro : libros) {
        if (libro->getTitulo() == titulo) {
            libro->prestar(persona);
            return;
        }
    }
    std::cout << "El libro \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::prestarRevista(std::string titulo) {
    for (auto& revista : revistas) {
        if (revista->getTitulo() == titulo) {
            revista->prestar();
            return;
        }
    }
    std::cout << "La revista \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::devolverLibro(std::string titulo) {
    for (auto& libro : libros) {
        if (libro->getTitulo() == titulo) {
            libro->devolver();
            return;
        }
    }
    std::cout << "El libro \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::devolverRevista(std::string titulo) {
    for (auto& revista : revistas) {
        if (revista->getTitulo() == titulo) {
            revista->devolver();
            return;
        }
    }
    std::cout << "La revista \"" << titulo << "\" no se encuentra en la biblioteca" << std::endl;
}

void Biblioteca::mostrarLibrosPrestados() {
    bool algunPrestado = false;
    for (const auto& libro : libros) {
        if (libro->isPrestado()) {
            if (!algunPrestado) {
                std::cout << "Libros prestados en la biblioteca:" << std::endl;
                algunPrestado = true;
            }
            std::cout << "- " << libro->getTitulo() << " de " << libro->getAutor() << std::endl;
        }
    }
    if (!algunPrestado) {
        std::cout << "No hay libros prestados en la biblioteca" << std::endl;
    }
}

void Biblioteca::mostrarRevistasPrestadas() {
    bool algunaPrestada = false;
    for (const auto& revista : revistas) {
        if (revista->isPrestado()) {
            if (!algunaPrestada) {
                std::cout << "Revistas prestadas en la biblioteca:" << std::endl;
                algunaPrestada = true;
            }
            std::cout << "- " << revista->getTitulo() << " (" << revista->getSaga() << ", " << revista->getEstante() << ")" << std::endl;
        }
    }
    if (!algunaPrestada) {
        std::cout << "No hay revistas prestadas en la biblioteca" << std::endl;
    }
}
