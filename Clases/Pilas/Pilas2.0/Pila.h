
#ifndef PILA_H
#define PILA_H

#include "Nodo.h"
class pila {
private:
    Nodo* primero;

public:

    pila();
    ~pila();
    void agregar(Nodo* nodo);
    };
#endif //PILA_H
