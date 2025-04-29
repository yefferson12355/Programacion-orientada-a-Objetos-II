#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

template <class T>
class Pila{
    private:
        Nodo<T> *cima;

    public:

    Pila(){
        cima = NULL;
    }

    void Push(T v){
        Nodo<T> *n = new Nodo<T>(v);
        /*
        if(cima == NULL){
            cima = n;
        }else{
            n->unirCon(cima);
            cima = n;
        }
        */
        n->unirCon(cima);
        cima = n;
    }
    void Pop(){
        if(cima != NULL){
            Nodo<T> *temp = cima;
            cima = temp->retSig();
            delete temp;
        }
    }
    T Top() {
        if (cima != nullptr)
            return cima->retDato();
        return 0; 
    }
    void mostrarDatos(){
        Nodo<T> *temp = cima;
        while(temp != NULL){
            cout<<temp->retDato()<<endl;
            temp = temp->retSig();
        }
    }
    bool estaVacia() {
        return cima == nullptr;
    }
    int Size(){
        Nodo<T> *temp = cima;
        int i=0;
        while(temp != NULL){
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};
