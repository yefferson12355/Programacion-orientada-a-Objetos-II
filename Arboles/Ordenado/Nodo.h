//
// Created by YEFER on 23/10/2024.
//

#ifndef NODO_H
#define NODO_H
#include <stddef.h>

class Nodo {
private:
    String v;
    Nodo *Izquierdo;
    Nodo *Derecho;
public:
    //Constructor
    template<class T>
    Nodo(Nodo*Izquierda,String v,Nodo*Derecha) {
        this ->Izquierdo = Izquierda;
        this->Derecho = Derecha;
    }
    Nodo(T v) {
        izquierdo=NULL;

    }

    //Retorna Izquierdo
    Nodo *retIzquierdo() {
        return Izquierdo;
    }
    //Retornar Derecho
    Nodo *retDerecho() {
        return Derecho;
    }
    T retDato() {
        return dato;
    }

    void uniCon (Nodo<T>) {

    }

};
#endif //NODO_H
