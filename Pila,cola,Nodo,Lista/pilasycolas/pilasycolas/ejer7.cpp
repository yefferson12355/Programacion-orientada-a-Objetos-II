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

void invertirCola(Cola& cola) {
    if (!cola.estaVacia()) {
        int elemento = cola.desencolar();
        invertirCola(cola);
        cola.encolar(elemento);
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
