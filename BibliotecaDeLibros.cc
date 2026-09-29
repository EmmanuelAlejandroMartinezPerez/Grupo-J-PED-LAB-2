#include <iostream>
#include <string>
#include <limits>

struct Libro
{
    int codigo;
    string nombre;
    string autor;
};

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




