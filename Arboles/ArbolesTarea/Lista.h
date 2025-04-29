// En Lista.h
#include <iostream>
#include "Nodo.h"
using namespace std;
template <class T>
class Lista {
private:
    Nodo<T>* pri; // Puntero al primer nodo
    Nodo<T>* ult; // Puntero al último nodo
public:
    Lista() {
        pri = ult = NULL;
    }

    void insertInicio(T v) {
        Nodo<T>* n = new Nodo<T>(v);
        if (pri == NULL) {
            pri = ult = n; // Lista vacía
        } else {
            n->unirCon(pri); // Unir con el primer nodo
            pri = n; // Actualizar pri
        }
    }

    void insertFinal(T v) {
        Nodo<T>* n = new Nodo<T>(v);
        if (pri == NULL) {
            pri = ult = n; // Lista vacía
        } else {
            ult->unirCon(n); // Unir el último nodo con el nuevo
            ult = n; // Actualizar el puntero ult
        }
    }

    void eliminarPrimero() {
        if (pri != NULL) {
            Nodo<T>* temp = pri;
            pri = temp->retSig(); // Actualizar pri al siguiente nodo
            delete temp; // Eliminar el nodo anterior
            if (pri == NULL) {
                ult = NULL; // Si la lista queda vacía, actualizar ult
            }
        }
    }

    bool estaVacia() const {
        return pri == NULL; // Retorna si la lista está vacía
    }

    Nodo<T>* obtenerPrimero() const {
        return pri; // Retorna el primer nodo
    }

    void mostrarDatos() {
        Nodo<T>* temp = pri;
        while (temp != NULL) {
            cout << temp->retDato() << endl; // Mostrar datos del nodo
            temp = temp->retSig(); // Avanzar al siguiente nodo
        }
    }
};
