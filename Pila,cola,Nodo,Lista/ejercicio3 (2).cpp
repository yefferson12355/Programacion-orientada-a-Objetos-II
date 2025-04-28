#include "pila.h"
#include <iostream>
using namespace std;

int main() {
    Pila pilaOriginal;  // Pila original que contiene duplicados
    Pila pilaAuxiliar;  // Pila auxiliar para almacenar elementos únicos

    // Insertar valores en la pila original
    pilaOriginal.Push(450);
    pilaOriginal.Push(450);
    pilaOriginal.Push(1500);
    pilaOriginal.Push(1285);
    pilaOriginal.Push(1285);
    pilaOriginal.Push(1285);
    pilaOriginal.Push(879);

    cout << "Pila original:" << endl;
    pilaOriginal.mostrarDatos();  // Mostrar la pila original

    // Proceso de eliminar duplicados
    while (!pilaOriginal.estaVacia()) {  // Mientras la pila original no esté vacía
        int valorActual = pilaOriginal.Top();  // Obtener el valor en la cima de la pila
        pilaOriginal.Pop();  // Eliminar el valor de la pila original

        // Comprobar si la pila auxiliar está vacía o si el valor actual es diferente del tope de la pila auxiliar
        if (pilaAuxiliar.estaVacia() || pilaAuxiliar.Top() != valorActual) {
            pilaAuxiliar.Push(valorActual);  // Agregar el valor a la pila auxiliar si no es un duplicado
        }
    }

    Pila pilaResultado;  // Pila para los resultados sin duplicados
    while (!pilaAuxiliar.estaVacia()) {  // Transferir elementos de la pila auxiliar a la pila de resultado
        pilaResultado.Push(pilaAuxiliar.Top());  // Agregar el valor a la pila de resultados
        pilaAuxiliar.Pop();  // Eliminar el valor de la pila auxiliar
    }

    cout << "Pila sin duplicados:" << endl;
    pilaResultado.mostrarDatos();  // Mostrar la pila sin duplicados

    return 0;  // Fin del programa
}
