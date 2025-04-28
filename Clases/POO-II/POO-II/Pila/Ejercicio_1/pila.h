#ifndef TYPE_STACK
#define TYPE_STACK
#include "node.h"
#include <iostream>
using namespace std;

class Pila{
private:
    Nodo* cima;
public:
    Pila(){
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
            temp = temp->retSig();
        }
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

#endif
