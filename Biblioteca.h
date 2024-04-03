//
// Created by Admin on 02/04/2024.
//

#ifndef UNTITLED1_BIBLIOTECA_H
#define UNTITLED1_BIBLIOTECA_H
#include <iostream>
#include <vector>
#include <string>
#include "Libro.h"
#include "Revista.h"
class Biblioteca {
private:
    vector<Libro*> items;

public:
    void agregarLibro(Libro* libro) {
        items.push_back(libro);
    }

    void eliminarLibro(const string& titulo) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getTitulo() == titulo) {
                delete *it;
                items.erase(it);
                cout << "Libro '" << titulo << "' eliminado correctamente." << endl;
                return;
            }
        }
        cout << "El libro '" << titulo << "' no se encontró en la biblioteca." << endl;
    }

    void prestarLibro(const string& titulo) {
        for (auto& item : items) {
            if (item->getTitulo() == titulo) {
                if (!item->estaPrestado()) {
                    item->prestar();
                    cout << "Libro prestado correctamente." << endl;
                } else {
                    cout << "El libro ya está prestado." << endl;
                }
                return;
            }
        }
        cout << "El libro no se encontró en la biblioteca." << endl;
    }

    void devolverLibro(const string& titulo) {
        for (auto& item : items) {
            if (item->getTitulo() == titulo) {
                if (item->estaPrestado()) {
                    item->devolver();
                    cout << "Libro devuelto correctamente." << endl;
                } else {
                    cout << "El libro no estaba prestado." << endl;
                }
                return;
            }
        }
        cout << "El libro no se encontró en la biblioteca." << endl;
    }

    void mostrarItems() const {
        cout << "Libros y Revistas disponibles en la biblioteca:" << endl;
        for (const auto& item : items) {
            cout << "Título: " << item->getTitulo() << ", Autor: " << item->getAutor();
            if (dynamic_cast<Revista*>(item)) {
                Revista* revista = dynamic_cast<Revista*>(item);
                cout << ", Saga: " << revista->getSaga() << ", Estante: " << revista->getEstante();
            }
            cout << ", Estado: " << (item->estaPrestado() ? "Prestado" : "Disponible") << endl;
        }
    }
};


#endif //UNTITLED1_BIBLIOTECA_H
