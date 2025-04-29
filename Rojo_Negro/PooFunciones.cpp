#include <iostream> // Librería para usar cout y cin

using namespace std;

// Función xyz que recibe un entero y retorna un entero
int xyz(int y) {
    // Si el valor de y es menor que 10, hacemos una llamada recursiva
    if (y < 10) {
        return xyz(y + 1); // Llamamos otra vez a xyz, pero aumentando y en 1
    }
    // Cuando y ya no es menor que 10, retornamos y
    return y;
}

int main() {
    // Llamamos a xyz con el valor inicial 5 y mostramos el resultado en pantalla
    // Debido a la recursión, xyz(5) -> xyz(6) -> xyz(7) -> xyz(8) -> xyz(9) -> xyz(10)
    // Cuando y == 10, se deja de llamar y se retorna 10
    cout << xyz(5) << endl; // Imprime 10

    return 0; // Finaliza el programa correctamente
}
