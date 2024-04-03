//
// Created by Admin on 02/04/2024.
//

#ifndef UNTITLED1_REVISTA_H
#define UNTITLED1_REVISTA_H
#include <iostream>
#include <vector>
#include <string>
#include "Libro.h"

class Revista : public Libro {
private:
    string saga;
    string estante;

public:
    Revista(string _titulo, string _autor, string _saga, string _estante)
            : Libro(_titulo, _autor), saga(_saga), estante(_estante) {}

    string getSaga() const {
        return saga;
    }

    string getEstante() const {
        return estante;
    }

    void setSaga(string _saga) {
        saga = _saga;
    }

    void setEstante(string _estante) {
        estante = _estante;
    }
};


#endif //UNTITLED1_REVISTA_H
