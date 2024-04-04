//
// Created by Admin on 02/04/2024.
//

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream> // Para la salida estándar

class Persona; // Declaración adelantada de Persona para evitar un ciclo de inclusión

class Libro {
private:
    std::string titulo;
    std::string autor;
    bool prestado;

public:
    Libro(std::string _titulo, std::string _autor); // Constructor

    std::string getTitulo() const;
    std::string getAutor() const;
    bool isPrestado() const;
    void setPrestado(bool _prestado);

    void prestar(Persona* persona);
    void devolver();
};

#endif // LIBRO_H

