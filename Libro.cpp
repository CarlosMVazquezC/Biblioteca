#include "Libro.h"
#include "Persona.h"

Libro::Libro(std::string _titulo, std::string _autor)
        : titulo(_titulo), autor(_autor), prestado(false) {}

std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

bool Libro::isPrestado() const {
    return prestado;
}

void Libro::setPrestado(bool _prestado) {
    prestado = _prestado;
}

void Libro::prestar(Persona* persona) {
    if (!prestado) {
        prestado = true;
        std::cout << "El libro \"" << titulo << "\" ha sido prestado a " << persona->getNombre() << " " << persona->getApellido() << std::endl;
    } else {
        std::cout << "El libro \"" << titulo << "\" ya está prestado" << std::endl;
    }
}

void Libro::devolver() {
    if (prestado) {
        prestado = false;
        std::cout << "El libro \"" << titulo << "\" ha sido devuelto" << std::endl;
    } else {
        std::cout << "El libro \"" << titulo << "\" no estaba prestado" << std::endl;
    }
}

