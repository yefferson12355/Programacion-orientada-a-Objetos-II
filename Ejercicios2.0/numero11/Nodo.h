#ifndef NODO_H
#define NODO_H

#include "Cliente.h"

class Nodo {
private:
    Cliente dato;
    Nodo *sig;
public:
    Nodo(Cliente v) : dato(v), sig(nullptr) {}
    Nodo *retSig() { return sig; }
    Cliente retDato() { return dato; }
    void unirCon(Nodo *n) { sig = n; }
};

#endif

