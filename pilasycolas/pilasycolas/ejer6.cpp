#include <iostream>
using namespace std;

class Cola {
private:
    int elementos[100];
    int frente, final;

public:
    Cola() {
        frente = -1;
        final = -1;
    }

    bool estaVacia() {
        return frente == -1;
    }

    void encolar(int elemento) {
        if (final < 99) {
            if (frente == -1) frente = 0;
            final++;
            elementos[final] = elemento;
        } else {
            cout << "Cola llena" << endl;
        }
    }

    int desencolar() {
        if (!estaVacia()) {
            int elemento = elementos[frente];
            if (frente == final) {
                frente = final = -1;
            } else {
                frente++;
            }
            return elemento;
        } else {
            cout << "Cola vacía" << endl;
            return -1;
        }
    }

    void mostrarCola() {
        if (!estaVacia()) {
            for (int i = frente; i <= final; i++) {
                cout << elementos[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Cola vacía" << endl;
        }
    }
};

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
};

void invertirCola(Cola& cola) {
    Pila pilaAux;

    while (!cola.estaVacia()) {
        pilaAux.push(cola.desencolar());
    }

    while (!pilaAux.estaVacia()) {
        cola.encolar(pilaAux.pop());
    }
}

int main() {
    Cola cola;
    int n, elemento;
    cout << "Ingrese el número de datos que desea encolar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> elemento;
        cola.encolar(elemento);
    }
    
    cout << "Cola original: ";
    cola.mostrarCola();
    invertirCola(cola);
    cout << "Cola invertida: ";
    cola.mostrarCola();

    return 0;
}
