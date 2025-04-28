#ifndef PILA_H
#define PILA_H

#include "nodo.h"
#include <iostream>
using namespace std;

class Pila{
private:
    Nodo* cima;
public:
    Pila() {
        cima = nullptr;
    }
    void Push(int v){
        Nodo *n = new Nodo(v);
        n->unirCon(cima);
        cima = n;
    }
    void Pop(){
        if(cima != nullptr){
            Nodo *temp = cima;
            cima = temp->retSig();
            delete temp;
        }
    }
    void mostrarDatos(){
        Nodo *temp = cima;
        while(temp != nullptr){
            cout<<temp->retDato()<<endl;
            temp = temp->retSig();}
    }
    char Top(){
        if(cima != nullptr){
            return cima->retDato();
        }else {
            return '\0';}
    }
    bool isEmpty() {
        return cima == nullptr;
    }
    int Size(){
        Nodo *temp = cima;
        int i=0;
        while(temp != nullptr){
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};

#endif //PILA_H
