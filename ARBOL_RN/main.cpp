#include <iostream>
using namespace std;

enum Color { ROJO, NEGRO };

struct Nodo {
    int dato;
    Color color;
    Nodo *izq, *der, *padre;

    Nodo(int dato) : dato(dato), color(ROJO), izq(nullptr), der(nullptr), padre(nullptr) {}
};

class ArbolRojoNegro {
private:
    Nodo* raiz;

    void rotarIzquierda(Nodo* &raiz, Nodo* &x) {
        Nodo* y = x->der;
        x->der = y->izq;
        if (y->izq) y->izq->padre = x;
        y->padre = x->padre;
        if (!x->padre) raiz = y;
        else if (x == x->padre->izq) x->padre->izq = y;
        else x->padre->der = y;
        y->izq = x;
        x->padre = y;
    }

    void rotarDerecha(Nodo* &raiz, Nodo* &x) {
        Nodo* y = x->izq;
        x->izq = y->der;
        if (y->der) y->der->padre = x;
        y->padre = x->padre;
        if (!x->padre) raiz = y;
        else if (x == x->padre->der) x->padre->der = y;
        else x->padre->izq = y;
        y->der = x;
        x->padre = y;
    }

    void balancear(Nodo* &raiz, Nodo* &x) {
        while (x != raiz && x->padre->color == ROJO) {
            Nodo* abuelo = x->padre->padre;
            if (x->padre == abuelo->izq) {
                Nodo* tio = abuelo->der;
                if (tio && tio->color == ROJO) {
                    x->padre->color = NEGRO;
                    tio->color = NEGRO;
                    abuelo->color = ROJO;
                    x = abuelo;
                } else {
                    if (x == x->padre->der) {
                        x = x->padre;
                        rotarIzquierda(raiz, x);
                    }
                    x->padre->color = NEGRO;
                    abuelo->color = ROJO;
                    rotarDerecha(raiz, abuelo);
                }
            } else {
                Nodo* tio = abuelo->izq;
                if (tio && tio->color == ROJO) {
                    x->padre->color = NEGRO;
                    tio->color = NEGRO;
                    abuelo->color = ROJO;
                    x = abuelo;
                } else {
                    if (x == x->padre->izq) {
                        x = x->padre;
                        rotarDerecha(raiz, x);
                    }
                    x->padre->color = NEGRO;
                    abuelo->color = ROJO;
                    rotarIzquierda(raiz, abuelo);
                }
            }
        }
        raiz->color = NEGRO;
    }

public:
    ArbolRojoNegro() : raiz(nullptr) {}

    void insertar(int dato) {
        Nodo* nuevo = new Nodo(dato);
        Nodo* padre = nullptr;
        Nodo* actual = raiz;

        while (actual) {
            padre = actual;
            if (dato < actual->dato) actual = actual->izq;
            else actual = actual->der;
        }

        nuevo->padre = padre;
        if (!padre) raiz = nuevo;
        else if (dato < padre->dato) padre->izq = nuevo;
        else padre->der = nuevo;

        balancear(raiz, nuevo);
    }

    void imprimir(Nodo* nodo, string indent = "", bool ultimo = true) {
        if (nodo) {
            cout << indent;
            if (ultimo) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            cout << nodo->dato << "(" << (nodo->color == ROJO ? "R" : "N") << ")" << endl;
            imprimir(nodo->izq, indent, false);
            imprimir(nodo->der, indent, true);
        }
    }

    void mostrar() { imprimir(raiz); }
};

int main() {
    ArbolRojoNegro arbol;
    arbol.insertar(10);
    arbol.insertar(20);
    arbol.insertar(30);
    arbol.insertar(15);

    arbol.mostrar();
    return 0;
}
