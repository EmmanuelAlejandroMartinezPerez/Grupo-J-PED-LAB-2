#include <iostream>
#include <string>
#include <limits>

struct Libro
{
    int codigo;
    std::string titulo;
    std::string autor;
    Libro* anterior;
    Libro* siguiente;
};

Libro* lista = nullptr;

void AgregarLibro();
void borrarInicio();
void imprimir();

int main()
{
    int opcion;

    do {
        std::cout << "Bienvenido al sistema de biblioteca, elige una opcion:\n"
                  << "1. Insertar libro al inicio.\n"
                  << "2. Borrar libro al inicio.\n"
                  << "3. Mostrar libros.\n"
                  << "4. Salir\n";

        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = 0;
        }

        switch (opcion)
        {
        case 1:
            AgregarLibro();
            break;

        case 2:
            borrarInicio();
            break;

        case 3:
            imprimir();
            break;

        case 4:
            std::cout << "Gracias por usar el sistema.\nSALIENDO DEL SISTEMA.......\n";
            return 0;

        default:
            std::cout << "Opcion invalida intenta de nuevo\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}


void AgregarLibro()
{
    Libro* nuevoLibro = new Libro();
    nuevoLibro->codigo = 0;
    nuevoLibro->titulo = "";
    nuevoLibro->autor = "";
    nuevoLibro->anterior = nullptr;
    nuevoLibro->siguiente = nullptr;

    std::cout << "Ingresa el titulo del libro: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nuevoLibro->titulo);

    std::cout << "Ingresa el autor del libro: ";
    std::getline(std::cin, nuevoLibro->autor);

    std::cout << "Ingresa un codigo para el libro: ";
    std::cin >> nuevoLibro->codigo;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Codigo invalido. Se usara 0.\n";
        nuevoLibro->codigo = 0;
    }

    nuevoLibro->siguiente = lista;
    if (lista != nullptr) {
        lista->anterior = nuevoLibro;
    }
    lista = nuevoLibro;

    std::cout << "Libro agregado correctamente.\n";
}

void borrarInicio()
{
    if (lista == nullptr) {
        std::cout << "\nLa lista esta vacia.\n";
        return;
    }

    Libro* temporal = lista;
    lista = lista->siguiente;

    if (lista != nullptr) {
        lista->anterior = nullptr;
    }

    std::cout << "\nLibro eliminado: " << temporal->titulo << '\n';

    delete temporal;
}

void imprimir()
{
    if (lista == nullptr) {
        std::cout << "\nLa biblioteca esta vacia.\n";
        return;
    }

    Libro* actual = lista;

    std::cout << "\n===== BIBLIOTECA DE LIBROS =====\n";

    while (actual != nullptr) {
        std::cout << "\nCodigo: " << actual->codigo << '\n';
        std::cout << "Titulo: " << actual->titulo << '\n';
        std::cout << "Autor: " << actual->autor << '\n';
        actual = actual->siguiente;
    }
}
