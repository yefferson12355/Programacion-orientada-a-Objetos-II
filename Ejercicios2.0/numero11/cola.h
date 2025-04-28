#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class Cola {
private:
    Nodo *pri;
    Nodo *ult;
public:
    Cola() : pri(nullptr), ult(nullptr) {}
    Nodo *getFrente() {
        return pri;
    }
    void Insertar(Cliente n) {
        Nodo *a = new Nodo(n);
        if (ult == nullptr) {
            pri = ult = a;
        } else {
            ult->unirCon(a);
            ult = a;
        }
    }
    void Eliminar() {
        if (pri != nullptr) {
            Nodo *temp = pri;
            pri = temp->retSig();
            delete temp;
            if (pri == nullptr) {
                ult = nullptr;
            }
        }
    }
    void MostrarDatos() {
        Nodo *temp = pri;
        while (temp != nullptr) {
            Cliente c = temp->retDato();
            cout << "ID: " << c.getId() << ", Nombre: " << c.getNombre() << endl;
            temp = temp->retSig();
        }
    }
};

#endif

