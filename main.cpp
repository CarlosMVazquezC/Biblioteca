#include <iostream>
#include <vector>
#include <string>
#include "Persona.h"
#include "Libro.h"
#include "Biblioteca.h"
#include <stdexcept>
#include <limits>


int main() {
    Biblioteca biblioteca;

    // Agregar libros
    biblioteca.agregarLibro(new Libro("Don Quijote de la Mancha", "Miguel de Cervantes"));
    biblioteca.agregarLibro(new Libro("Orgullo y prejuicio", "Jane Austen"));
    biblioteca.agregarLibro(new Libro("Crimen y castigo", "Fyodor Dostoevsky"));
    biblioteca.agregarLibro(new Libro("El gran Gatsby", "F. Scott Fitzgerald"));
    biblioteca.agregarLibro(new Libro("Moby Dick", "Herman Melville"));
    biblioteca.agregarLibro(new Libro("1984", "George Orwell"));
    biblioteca.agregarLibro(new Libro("Romeo y Julieta", "William Shakespeare"));
    biblioteca.agregarLibro(new Libro("El señor de los anillos", "J.R.R. Tolkien"));
    biblioteca.agregarLibro(new Libro("Harry Potter y la piedra filosofal", "J.K. Rowling"));
    biblioteca.agregarLibro(new Libro("Cien años de soledad", "Gabriel García Márquez"));
    Revista revista1("National Geographic", "Revista", "Ciencia", "Estante 1");
    Revista revista2("Vogue", "Revista", "Moda", "Estante 2");
    Revista revista3("Time", "Revista", "Actualidad", "Estante 3");

    int opcion;
    string titulo, nombre, apellido, saga, estante;

    bool esAdmin = false; // Variable que indica si el usuario es un administrador

    do {
        cout << "\n*** BIENVENIDO ***" << endl;
        cout << "Seleccione su modo de acceso:" << endl;
        cout << "1. Modo Administrador" << endl;
        cout << "2. Modo Cliente" << endl;
        cout << "Ingrese opción: ";

        // Manejo de excepciones para la entrada del usuario
        try {
            cin >> opcion;

            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                throw invalid_argument("Entrada no válida. Ingrese un número.");
            }

            if (opcion != 1 && opcion != 2) {
                throw invalid_argument("Opción no válida. Inténtelo de nuevo.");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            continue; // Volver al inicio del bucle
        }

        if (opcion == 1) {
            esAdmin = true;
            cout << "Modo Administrador activado." << endl;
        } else {
            cout << "Modo Cliente activado." << endl;
        }

        // Menú de opciones según el modo de acceso seleccionado
        do {
            cout << "\n*** MENÚ ***" << endl;
            cout << "1. Mostrar libros y revistas disponibles" << endl;
            cout << "2. Prestar libro o revista" << endl;
            cout << "3. Devolver libro o revista" << endl;
            if (esAdmin) {
                cout << "4. Añadir libro o revista" << endl;
                cout << "5. Eliminar libro o revista" << endl;
                cout << "6. Cambiar a Modo Cliente" << endl;
            } else {
                cout << "4. Cambiar a Modo Administrador" << endl;
            }
            cout << "7. Salir" << endl;
            cout << "Ingrese opción: ";

            // Manejo de excepciones para la entrada del usuario
            try {
                cin >> opcion;

                if (cin.fail()) {
                    cin.clear(); // Limpiar el estado de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                    throw invalid_argument("Entrada no válida. Ingrese un número.");
                }

                if (opcion < 1 || opcion > 7) {
                    throw invalid_argument("Opción no válida. Inténtelo de nuevo.");
                }
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
                continue; // Volver al inicio del bucle
            }

            switch (opcion) {
                case 1:
                    biblioteca.mostrarItems();
                    break;
                case 2:
                    cout << "Ingrese el título del libro o revista que desea prestar: ";
                    cin.ignore();
                    getline(cin, titulo);
                    try {
                        biblioteca.prestarLibro(titulo);
                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                case 3:
                    cout << "Ingrese el título del libro o revista que desea devolver: ";
                    cin.ignore();
                    getline(cin, titulo);
                    try {
                        biblioteca.devolverLibro(titulo);
                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                case 4:
                    if (esAdmin) {
                        cout << "Ingrese el título del nuevo libro o revista: ";
                        cin.ignore();
                        getline(cin, titulo);
                        cout << "Ingrese el nombre del autor o saga: ";
                        getline(cin, nombre);
                        if (titulo.find("Revista") != string::npos) {
                            cout << "Ingrese la saga de la revista: ";
                            getline(cin, saga);
                            cout << "Ingrese el estante de la revista: ";
                            getline(cin, estante);
                            biblioteca.agregarLibro(new Revista(titulo, nombre, saga, estante));
                            cout << "Revista agregada correctamente." << endl;
                        } else {
                            biblioteca.agregarLibro(new Libro(titulo, nombre));
                            cout << "Libro agregado correctamente." << endl;
                        }
                    } else {
                        esAdmin = true;
                    }
                    break;
                case 5:
                    if (esAdmin) {
                        cout << "Ingrese el título del libro o revista que desea eliminar: ";
                        cin.ignore();
                        getline(cin, titulo);
                        biblioteca.eliminarLibro(titulo);
                    } else {
                        cout << "Opción no válida." << endl;
                    }
                    break;
                case 6:
                    if (esAdmin) {
                        esAdmin = false;
                        cout << "Modo Cliente activado." << endl;
                    } else {
                        cout << "Opción no válida." << endl;
                    }
                    break;
                case 7:
                    cout << "Saliendo del programa." << endl;
                    break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
            }
        } while (opcion != 7);

    } while (true); // Bucle infinito para volver a seleccionar el modo de acceso al salir del programa

    return 0;
}