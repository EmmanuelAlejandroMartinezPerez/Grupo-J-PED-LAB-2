#include <iostream>
#include <string>
#include <limits>

using namespace std ;

struct Libro
{
    int codigo;
    string nombre;
    string autor;
};

Libro *lista = nullptr

void AgregarLibro();
void borrarInicio();
void imprimir();


int main()
{

    int opcion;
    do{
    std::cout << "Bienvenido al sistema de biblioteca, elige una opcion: " << "\n1. Insertar libro al inicio. \n2. Borrar libro al inicio. \n3. Salir\n";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        AgregarLibro();
        break;

    case 2:
        borrarInicio();
        break;

    case 3:
        std::cout << "Gracias por usar el sistema.\n SALIENDO DEL SISTEMA.......\n";
        return 0;
        break;
    
    default:
        std::cout << "Opcion invalida intenta de nuevo\n";
        break;
    }
    
        
    } while (opcion);
    
}


void AgregarLibro(Libro libro){
    Libro agregar_libro;
    std::cout << "Ingresa el titulo del libro: ";
    std::getline(std::cin >> agregar_libro.titulo);
    std::cout << "Ingresa el autor del libro: ";
    std::getline(std::cin >> agregar_libro.autor);
    std::cout << "Ingresa un codigo para el libro: ";
    std::cin >> agregar_libro.titulo;

    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->libro = libro;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->anterior = nullptr;
    
    if(inicio == nullptr){
        inicio = nuevo_nodo;
        final = nuevo_nodo;
    }
}




