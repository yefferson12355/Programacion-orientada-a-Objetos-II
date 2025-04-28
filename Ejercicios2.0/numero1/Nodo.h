#ifndef NODO_H
#define NODO_H
class Nodo{
private:
    char dato;
    Nodo *sig;
public:
    Nodo(int v){
        dato = v;
        sig = nullptr;
    }
    Nodo *retSig(){
        return sig;
    }
    char retDato(){
        return dato;
    }
    void unirCon(Nodo *n){
        sig = n;
    }
};



#endif //NODO_H
