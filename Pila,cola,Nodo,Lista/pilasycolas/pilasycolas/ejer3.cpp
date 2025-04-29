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

    int peek() {
        if (!estaVacia()) {
            return elementos[tope];
        } else {
            return -1;
        }
    }

    void mostrarPila() {
        if (!estaVacia()) {
            for (int i = tope; i >= 0; i--) {
                cout << elementos[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Pila vacía" << endl;
        }
    }
};

void eliminarRepetidosConsecutivos(Pila& pila) {
    Pila pilaAux;

    if (!pila.estaVacia()) {
        pilaAux.push(pila.pop());
    }

    while (!pila.estaVacia()) {
        int actual = pila.pop();
        if (actual != pilaAux.peek()) {
            pilaAux.push(actual);
        }
    }

    while (!pilaAux.estaVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {
    Pila pila;
    int n, elemento;

    cout << "Ingrese el número de elementos que desea apilar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> elemento;
        pila.push(elemento);
    }
    pila.mostrarPila();
    eliminarRepetidosConsecutivos(pila);
    pila.mostrarPila();

    return 0;
}
