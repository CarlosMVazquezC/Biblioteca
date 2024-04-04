//
// Created by Admin on 02/04/2024.
//


#ifndef REVISTA_H
#define REVISTA_H

#include <string>

class Revista {
private:
    std::string titulo;
    std::string saga;
    std::string estante;
    bool prestado;

public:
    Revista(std::string titulo, std::string saga, std::string estante);
    std::string getTitulo();
    std::string getSaga();
    std::string getEstante();
    bool isPrestado();
    void setPrestado(bool prestado);
    void prestar();
    void devolver();
};

#endif // REVISTA_H

