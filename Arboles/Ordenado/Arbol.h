//
// Created by YEFER on 23/10/2024.
//

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

template <class T>
class Arbol {
private:
    Nodo<T> *raiz;
public:
    Arbol() {
        raiz = NULL;
    };
    void insertar(T v) {
        Nodo<T> *n =new Nodo<T>(v);
        if (raiz == NULL)
            raiz = n;
        else
    }
    //tiene que ir a otro otro metodo recursivo.


};
#endif //ARBOL_H
