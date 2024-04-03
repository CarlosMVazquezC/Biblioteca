//
// Created by Admin on 02/04/2024.
//

#ifndef UNTITLED1_PERSONA_H
#define UNTITLED1_PERSONA_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    string apellido;

public:
    Persona(const string& _nombre, const string& _apellido) : nombre(_nombre), apellido(_apellido) {}

    void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Apellido: " << apellido << endl;
    }
};

#endif //UNTITLED1_PERSONA_H
