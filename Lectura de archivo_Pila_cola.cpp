#include <iostream>
#include <fstream>
using namespace std;

// Implementacion de Nodo con Template
template <class T>
class Nodo {
private:
    T dato;
    Nodo<T> *sig;
public:
    Nodo(T v) {
        dato = v;
        sig = NULL;
    }

    Nodo() {}

    Nodo<T> *retSig() {
        return sig;
    }

    T retDato() {
        return dato;
    }

    void unirCon(Nodo<T> *n) {
        sig = n;
    }
};

// Implementacion de Pila con Template
template <class T>
class Pila {
private:
    Nodo<T> *cima;

public:
    Pila() {
        cima = NULL;
    }

    void Push(T v) {
        Nodo<T> *n = new Nodo<T>(v);
        n->unirCon(cima);
        cima = n;
    }

    void Pop() {
        if(cima != NULL) {
            Nodo<T> *temp = cima;
            cima = temp->retSig();
            delete temp;
        }
    }

    void mostrarDatos() {
        Nodo<T> *temp = cima;
        while(temp != NULL) {
            cout << temp->retDato() << endl;
            temp = temp->retSig();
        }
    }

    int Size() {
        Nodo<T> *temp = cima;
        int i = 0;
        while(temp != NULL) {
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};

int main() {
    ifstream arch("entrada.txt");
    int cant, num1, num2;
    string linea;
    
    arch >> cant;

    while(cant >= 0) {
        cant--;
        arch >> num1;
        arch >> num2;
        cout << num1 << " - " << num2 << endl;
    }
    
    return 0;
}
