#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo {
private:
    T dato;
    Nodo<T>* sig;
    Nodo<T>* hijoDer;
    Nodo<T>* hijoIzq;

public:
    Nodo(T v) {
        dato = v;
        hijoDer = NULL;
        hijoIzq = NULL;
    }


    Nodo<T>* retHijoDer() {
        return hijoDer;
    }

    Nodo<T>* retHijoIzq() {
        return hijoIzq;
    }

    T retDato() {
        return dato;
    }

    Nodo<T>* retSig(){
        return sig;
    }

    void unirConIzq(Nodo<T>* n) {
        hijoIzq = n;
    }

    void unirConDer(Nodo<T>* n) {
        hijoDer = n;
    }
    void unirCon(Nodo<T>* n) {
        sig = n;
    }
};

#endif
