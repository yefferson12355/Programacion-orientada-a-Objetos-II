#include <iostream>
using namespace std;

#define MAX 100

class ColaCircular {
private:
    int elementos[MAX];
    int frente, final;
    int cantidad;

public:
    ColaCircular() {
        frente = -1;
        final = -1;
        cantidad = 0;
    }

    bool estaVacia() {
        return cantidad == 0;
    }

    bool estaLlena() {
        return cantidad == MAX;
    }

    void encolar(int elemento) {
        if (!estaLlena()) {
            if (frente == -1) frente = 0;
            final = (final + 1) % MAX;
            elementos[final] = elemento;
            cantidad++;
        } else {
            cout << "Cola llena" << endl;
        }
    }

    int desencolar() {
        if (!estaVacia()) {
            int elemento = elementos[frente];
            frente = (frente + 1) % MAX;
            cantidad--;
            if (cantidad == 0) {
                frente = -1;
                final = -1;
            }
            return elemento;
        } else {
            cout << "Cola vacía" << endl;
            return -1;
        }
    }

    void mostrarCola() {
        if (!estaVacia()) {
            int i = frente;
            for (int contador = 0; contador < cantidad; contador++) {
                cout << elementos[i] << " ";
                i = (i + 1) % MAX;
            }
            cout << endl;
        } else {
            cout << "Cola vacía" << endl;
        }
    }

    void eliminarRepetidosConsecutivos() {
        if (cantidad <= 1) return;

        ColaCircular aux;

        int anterior = desencolar();
        aux.encolar(anterior);

        while (!estaVacia()) {
            int actual = desencolar();
            if (actual != anterior) {
                aux.encolar(actual);
            }
            anterior = actual;
        }

        while (!aux.estaVacia()) {
            encolar(aux.desencolar());
        }
    }
};

int main() {
    ColaCircular cola;
    int n, elemento;
    cout << "Ingrese el número de elementos que desea encolar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> elemento;
        cola.encolar(elemento);
    }

    cout << "Cola original: ";
    cola.mostrarCola();
    cola.eliminarRepetidosConsecutivos();
    cout << "Cola sin elementos repetidos consecutivos: ";
    cola.mostrarCola();

    return 0;
}
