//
// Created by Admin on 02/04/2024.
//

#include "Revista.h"
#include <iostream>

Revista::Revista(std::string titulo, std::string saga, std::string estante)
        : titulo(titulo), saga(saga), estante(estante), prestado(false) {}

std::string Revista::getTitulo() {
    return titulo;
}

std::string Revista::getSaga() {
    return saga;
}

std::string Revista::getEstante() {
    return estante;
}

bool Revista::isPrestado() {
    return prestado;
}

void Revista::setPrestado(bool prestado) {
    this->prestado = prestado;
}

void Revista::prestar() {
    if (!prestado) {
        prestado = true;
        std::cout << "La revista \"" << titulo << "\" ha sido prestada" << std::endl;
    } else {
        std::cout << "La revista \"" << titulo << "\" ya está prestada" << std::endl;
    }
}

void Revista::devolver() {
    if (prestado) {
        prestado = false;
        std::cout << "La revista \"" << titulo << "\" ha sido devuelta" << std::endl;
    } else {
        std::cout << "La revista \"" << titulo << "\" no estaba prestada" << std::endl;
    }
}
