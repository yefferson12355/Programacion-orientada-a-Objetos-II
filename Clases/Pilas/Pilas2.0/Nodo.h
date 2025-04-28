//
// Created by YEFER on 18/09/2024.
//
#ifndef NODO_H
#define NODO_H
class Nodo {
private:
    int dato; //Entero
    Nodo *siguiente;//un puntero de tipo Nodo
public:
    //constructor definido
    Nodo(int numero) {
        dato = numero;
        siguiente=nullptr;
    }
    Nodo *getSig() {
        return siguiente;
    }
    int getDato() {
        return dato;
    }
    void UnirCon(Nodo *nuevo_nodo) {
        siguiente=nuevo_nodo;
    }

};
#endif //NODO_H
