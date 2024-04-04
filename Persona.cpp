#include "Persona.h"

Persona::Persona(const std::string& nombre, const std::string& apellido)
        : nombre(nombre), apellido(apellido) {}

std::string Persona::getNombre() const {
    return nombre;
}

std::string Persona::getApellido() const {
    return apellido;
}
