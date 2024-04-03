//
// Created by Admin on 02/04/2024.
//

#ifndef UNTITLED1_LIBRO_H
#define UNTITLED1_LIBRO_H


#include <iostream>
#include <vector>
#include <string>
#include "Persona.h"

class Libro {
protected:
    string titulo;
    string autor;
    bool prestado;

public:
    Libro(string _titulo, string _autor) : titulo(_titulo), autor(_autor), prestado(false) {}

    string getTitulo() const {
        return titulo;
    }

    string getAutor() const {
        return autor;
    }

    bool estaPrestado() const {
        return prestado;
    }

    void prestar() {
        prestado = true;
    }

    void devolver() {
        prestado = false;
    }
};

#endif //UNTITLED1_LIBRO_H
