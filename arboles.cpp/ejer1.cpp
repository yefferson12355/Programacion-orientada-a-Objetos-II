#include <iostream>
#include <stdio.h>
#include <vector>
#include "Nodo.h"
#include "Pila.h"
#include "Lista.h"
using namespace std;
template <class T>
class NodoMultiple {
public:
    T dato;
    vector<NodoMultiple<T>*> hijos;

    NodoMultiple(T valor)  {
        dato = valor;
        }
    void agregarHijo(NodoMultiple<T>* hijo) {
        hijos.push_back(hijo); }
};

template <class T>
class ArbolMultiple {
private:
    NodoMultiple<T>* raiz;

public:
    ArbolMultiple(){
        raiz = NULL;
        }
    void setRaiz(T valor) { 
        raiz = new NodoMultiple<T>(valor); 
}
};

int main() {
    ArbolMultiple<int>* arbmul = new ArbolMultiple<int>();
    return 0;
}