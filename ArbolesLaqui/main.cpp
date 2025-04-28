#include <iostream>
#include <stack>
#include <queue> // Se necesita para la impresión por niveles
#include "Nodo"
using namespace std;

template <class T>
class Arbol {
private:
    Nodo<T>* raiz;
public:
    Arbol() {
        raiz = NULL;
    }

    void Insertar(T v) {
        Nodo<T>* n = new Nodo<T>(v);
        if (raiz == NULL)
            raiz = n;
        else
            Insertar(raiz, n);
    }

    void InsertarIterativo(T v) {
        Nodo<T>* n = new Nodo<T>(v);
        if (raiz == NULL) {
            raiz = n;
            return;
        }

        Nodo<T>* current = raiz;
        Nodo<T>* parent = NULL;

        while (true) {
            parent = current;
            if (n->retDato() < current->retDato()) {
                current = current->retHijoIzq();
                if (current == NULL) {
                    parent->unirConIzq(n);
                    return;
                }
            } else {
                current = current->retHijoDer();
                if (current == NULL) {
                    parent->unirConDer(n);
                    return;
                }
            }
        }
    }

    void inOrden() {
        inOrden(raiz);
    }

    void postOrden() {
        postOrden(raiz);
    }

    void iterativePreorder() {
        iterativePreorder(raiz);
    }

    void iterativeInorder() {
        iterativeInorder(raiz);
    }

    void iterativePostorder() {
        iterativePostorder(raiz);
    }

    // Metodo para calcular la altura del árbol
    int altura() {
        return altura(raiz);
    }

    // Metodo para contar la cantidad de nodos en el árbol
    int cantidadNodos() {
        return cantidadNodos(raiz);
    }

    // Metodo para imprimir los nodos por niveles
    void imprimirPorNiveles() {
        imprimirPorNiveles(raiz);
    }

protected:
    void Insertar(Nodo<T>* r, Nodo<T>* n) {
        if (r->retDato() > n->retDato()) {
            if (r->retHijoIzq() == NULL)
                r->unirConIzq(n);
            else
                Insertar(r->retHijoIzq(), n);
        }
        if (r->retDato() < n->retDato()) {
            if (r->retHijoDer() == NULL)
                r->unirConDer(n);
            else
                Insertar(r->retHijoDer(), n);
        }
    }

    void inOrden(Nodo<T>* r) {
        if (r != NULL) {
            inOrden(r->retHijoIzq());
            cout << r->retDato() << " ";
            inOrden(r->retHijoDer());
        }
    }

    void postOrden(Nodo<T>* r) {
        if (r != NULL) {
            postOrden(r->retHijoIzq());
            postOrden(r->retHijoDer());
            cout << r->retDato() << " ";
        }
    }

    void iterativePreorder(Nodo<T>* node) {
        if (node == NULL) return;
        stack<Nodo<T>*> s;
        s.push(node);
        while (!s.empty()) {
            node = s.top();
            s.pop();
            cout << node->retDato() << " "; // Visitar el nodo
            if (node->retHijoDer() != NULL) {
                s.push(node->retHijoDer());
            }
            if (node->retHijoIzq() != NULL) {
                s.push(node->retHijoIzq());
            }
        }
    }

    void iterativeInorder(Nodo<T>* node) {
        stack<Nodo<T>*> s;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->retHijoIzq();
            } else {
                node = s.top();
                s.pop();
                cout << node->retDato() << " "; // Visitar el nodo
                node = node->retHijoDer();
            }
        }
    }

    void iterativePostorder(Nodo<T>* node) {
        stack<Nodo<T>*> s;
        Nodo<T>* lastNodeVisited = NULL;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->retHijoIzq();
            } else {
                Nodo<T>* peekNode = s.top();
                if (peekNode->retHijoDer() != NULL && lastNodeVisited != peekNode->retHijoDer()) {
                    node = peekNode->retHijoDer();
                } else {
                    cout << peekNode->retDato() << " "; // Visitar el nodo
                    lastNodeVisited = s.pop();
                }
            }
        }
    }

    // Metodo para calcular la altura del árbol
    int altura(Nodo<T>* node) {
        if (node == NULL) return -1; // Se devuelve -1 si el nodo es nulo
        int alturaIzq = altura(node->retHijoIzq());
        int alturaDer = altura(node->retHijoDer());
        return 1 + max(alturaIzq, alturaDer);
    }

    // Metodo para contar la cantidad de nodos en el árbol
    int cantidadNodos(Nodo<T>* node) {
        if (node == NULL) return 0; // Se devuelve 0 si el nodo es nulo
        return 1 + cantidadNodos(node->retHijoIzq()) + cantidadNodos(node->retHijoDer());
    }

    // Metodo para imprimir los nodos por niveles
    void imprimirPorNiveles(Nodo<T>* node) {
        if (node == NULL) return; // Si el árbol está vacío, no hay nada que imprimir
        queue<Nodo<T>*> q;
        q.push(node);
        while (!q.empty()) {
            Nodo<T>* current = q.front();
            q.pop();
            cout << current->retDato() << " "; // Visitar el nodo
            if (current->retHijoIzq() != NULL) {
                q.push(current->retHijoIzq());
            }
            if (current->retHijoDer() != NULL) {
                q.push(current->retHijoDer());
            }
        }
    }
};