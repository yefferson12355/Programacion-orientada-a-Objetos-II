#include <iostream>
using namespace std;

class Pila {
private:
    int elementos[100];  
    int tope;           

public:

    Pila() {
        tope = -1; 
    }

    bool estaVacia() {
        return tope == -1;
    }

    void push(int elemento) {
        if (tope < 99) {
            tope++;
            elementos[tope] = elemento;
        } else {
            cout << "Pila llena" << endl;
        }
    }

    int pop() {
        if (!estaVacia()) {
            int elemento = elementos[tope];
            tope--;
            return elemento;
        } else {
            cout << "Pila vacía" << endl;
            return -1; 
        }
    }

    void mostrarPila() {
        for (int i = tope; i >= 0; i--) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }

    int topElemento() {
        if (!estaVacia()) {
            return elementos[tope];
        } else {
            return -1; 
        }
    }
};

void invertirPila(Pila& pilaOriginal) {
    Pila pilaAux; 

    while (!pilaOriginal.estaVacia()) {
        pilaAux.push(pilaOriginal.pop());
    }

    while (!pilaAux.estaVacia()) {
        pilaOriginal.push(pilaAux.pop());
    }
}

int main() {
    Pila pila;

    pila.push(928);
    pila.push(3209);
    pila.push(1024);
    pila.push(623);

    cout << "Pila original: ";
    pila.mostrarPila();
    invertirPila(pila);
    cout << "Pila invertida: ";
    pila.mostrarPila();

    return 0;
}
