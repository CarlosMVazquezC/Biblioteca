#include <iostream>
#include <limits>
#include "Biblioteca.h"
#include "Libro.h"
#include "Revista.h"
#include "Persona.h"

using namespace std;

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

    // Agregar revistas
    biblioteca.agregarRevista(new Revista("National Geographic", "Naturaleza", "Estante 1"));
    biblioteca.agregarRevista(new Revista("Time", "Actualidad", "Estante 2"));
    biblioteca.agregarRevista(new Revista("Scientific American", "Ciencia", "Estante 3"));

    int opcion;
    string titulo, nombre, apellido;

    bool esAdmin = false; // Variable que indica si el usuario es un administrador

    do {
        cout << "\n=============================" << endl;
        cout << "|          BIENVENIDO        |" << endl;
        cout << "=============================" << endl;
        cout << "|     Seleccione su modo     |" << endl;
        cout << "|          de acceso:        |" << endl;
        cout << "| 1. Modo Administrador      |" << endl;
        cout << "| 2. Modo Cliente            |" << endl;
        cout << "| 3. Salir                   |" << endl;
        cout << "=============================" << endl;
        cout << "Ingrese opción: ";

        // Manejo de excepciones para la entrada del usuario
        try {
            cin >> opcion;

            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                throw invalid_argument("Entrada no válida. Ingrese un número.");
            }

            if (opcion != 1 && opcion != 2 && opcion != 3) {
                throw invalid_argument("Opción no válida. Inténtelo de nuevo.");
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            continue; // Volver al inicio del bucle
        }

        if (opcion == 1) {
            esAdmin = true;
            cout << "\nModo Administrador activado." << endl;
        } else if (opcion == 2) {
            cout << "\nModo Cliente activado." << endl;
        } else if (opcion == 3) {
            cout << "\nSaliendo del programa." << endl;
            return 0; // Terminar el programa
        }

        // Menú de opciones según el modo de acceso seleccionado
        do {
            cout << "\n=============================" << endl;
            cout << "|            MENÚ           |" << endl;
            cout << "=============================" << endl;
            cout << "| 1. Mostrar todos los      |" << endl;
            cout << "|    libros y revistas      |" << endl;
            cout << "|    disponibles            |" << endl;
            cout << "| 2. Mostrar libros y       |" << endl;
            cout << "|    revistas prestados     |" << endl;
            cout << "| 3. Prestar libro o        |" << endl;
            cout << "|    revista                |" << endl;
            cout << "| 4. Devolver libro o       |" << endl;
            cout << "|    revista                |" << endl;
            if (esAdmin) {
                cout << "| 5. Añadir libro o         |" << endl;
                cout << "|    revista                |" << endl;
                cout << "| 6. Eliminar libro o       |" << endl;
                cout << "|    revista                |" << endl;
                cout << "| 7. Cambiar a Modo Cliente |" << endl;
            } else {
                cout << "| 5. Cambiar a Modo         |" << endl;
                cout << "|    Administrador          |" << endl;
            }
            cout << "| 8. Salir                   |" << endl;
            cout << "=============================" << endl;
            cout << "Ingrese opción: ";

            // Manejo de excepciones para la entrada del usuario
            try {
                cin >> opcion;

                if (cin.fail()) {
                    cin.clear(); // Limpiar el estado de error
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada inválida
                    throw invalid_argument("Entrada no válida. Ingrese un número.");
                }

                if (opcion < 1 || opcion > 8) {
                    throw invalid_argument("Opción no válida. Inténtelo de nuevo.");
                }
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
                continue; // Volver al inicio del bucle
            }

            switch (opcion) {
                case 1:
                    cout << "\n=============================" << endl;
                    cout << "|  Libros disponibles en la  |" << endl;
                    cout << "|          biblioteca        |" << endl;
                    cout << "=============================" << endl;
                    biblioteca.mostrarLibros();
                    cout << "\n=============================" << endl;
                    cout << "|  Revistas disponibles en   |" << endl;
                    cout << "|          la biblioteca     |" << endl;
                    cout << "=============================" << endl;
                    biblioteca.mostrarRevistas();
                    break;
                case 2:
                    cout << "\n=============================" << endl;
                    cout << "|  Libros prestados en la    |" << endl;
                    cout << "|          biblioteca        |" << endl;
                    cout << "=============================" << endl;
                    biblioteca.mostrarLibrosPrestados();
                    cout << "\n=============================" << endl;
                    cout << "|  Revistas prestadas en la  |" << endl;
                    cout << "|          biblioteca        |" << endl;
                    cout << "=============================" << endl;
                    biblioteca.mostrarRevistasPrestadas();
                    break;
                case 3:
                    cout << "Ingrese el título del libro o revista que desea prestar: ";
                    cin.ignore();
                    getline(cin, titulo);
                    try {
                        Persona persona(nombre, apellido);
                        biblioteca.prestarLibro(titulo, &persona);
                        cout << "Libro o revista prestado exitosamente." << endl;
                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                case 4:
                    cout << "Ingrese el título del libro o revista que desea devolver: ";
                    cin.ignore();
                    getline(cin, titulo);
                    try {
                        biblioteca.devolverLibro(titulo);
                        cout << "Libro o revista devuelto exitosamente." << endl;
                    } catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                case 5:
                    if (esAdmin) {
                        cout << "Función de añadir libro o revista aún no implementada." << endl;
                    } else {
                        esAdmin = true;
                    }
                    break;
                case 6:
                    if (esAdmin) {
                        cout << "Función de eliminar libro o revista aún no implementada." << endl;
                    } else {
                        cout << "Opción no válida." << endl;
                    }
                    break;
                case 7:
                    if (esAdmin) {
                        esAdmin = false;
                        cout << "Modo Cliente activado." << endl;
                    } else {
                        cout << "Opción no válida." << endl;
                    }
                    break;
                case 8:
                    cout << "Saliendo del programa." << endl;
                    break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
            }
        } while (opcion != 8);

    } while (true); // Bucle infinito para volver a seleccionar el modo de acceso al salir del programa

    return 0;
}



