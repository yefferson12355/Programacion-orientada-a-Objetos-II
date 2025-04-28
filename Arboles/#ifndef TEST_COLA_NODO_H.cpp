#ifndef TEST_COLA_NODO_H
#define TEST_COLA_NODO_H

class Nodo{
private:
    String v;
    Nodo *izq;
    Nodo *der;
public:
    Nodo(int v){
        dato = v;
        sig = nullptr;
    }
    Nodo(){

    }
    Nodo(Nodo*izq,String V,Nodo *der){
        this-> izq =izq;
        this-> der =der;
    }
    Nodo *retSig(){
        return sig;
    }
    int retDato(){
        return dato;
    }
    void unirCon(Nodo *n){
        sig = n;
    }
};

#endif

