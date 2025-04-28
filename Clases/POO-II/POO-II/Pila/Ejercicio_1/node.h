#ifndef NODE_TYPE
#define NODE_TYPE

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