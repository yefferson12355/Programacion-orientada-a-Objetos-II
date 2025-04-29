#ifndef NODO_H
#define NODO_H

//Nodo para  Arboles.
template <class T>
class Nodo{
private:
    T dato;
    Nodo<T> *hijoDer;
    Nodo<T> *hijoIzq;
    // para ordenar en lista
    Nodo<T>* siguiente; // Puntero al siguiente nodo
public:
    Nodo(T v){
        dato = v;
        hijoDer = NULL;
        hijoIzq = NULL;
    }

    Nodo<T> *retHijoDer(){
        return hijoDer;
    }
    Nodo<T> *retHijoIzq(){
        return hijoIzq;
    }
    // Métodos para obtener datos
    T retDato() const { return dato; }
    Nodo<T>* retSig() const { return siguiente; }

    void unirConIzq(Nodo<T> *n){
        hijoIzq = n;
    }
    // Método para unir un nodo con otro
    void unirCon(Nodo<T>* nodo) {
        siguiente = nodo; // Une el nodo actual con el siguiente
    }
    void unirConDer(Nodo<T> *n){
        hijoDer = n;
    }
};

#endif //NODO_H
