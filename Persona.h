//
// Created by Admin on 02/04/2024.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nombre;
    std::string apellido;

public:
    Persona(const std::string& nombre, const std::string& apellido);
    std::string getNombre() const;
    std::string getApellido() const;
};

#endif // PERSONA_H
