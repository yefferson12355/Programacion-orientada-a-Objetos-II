#ifndef TEST_COLA_NODO_H
#define TEST_COLA_NODO_H

class Nodo{
private:
    int dato;
    Nodo *sig;
public:
    Nodo(int v){
        dato = v;
        sig = nullptr;
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

