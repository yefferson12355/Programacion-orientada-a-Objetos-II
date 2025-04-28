#pragma once
#include <iostream>
#include <queue>
#include "Nodo.h"
#include "Pila.h"
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
    
    void preOrden(){
        preOrden(raiz);
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

    int altura() {
        return altura(raiz);
    }

    int cantidadNodos() {
        return cantidadNodos(raiz);
    }

    int contarHojas() {
        return contarHojas(raiz);
    }

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

    void preOrden(Nodo<T>* r) {
        if (r != NULL) {
            cout << r->retDato() << " ";
            preOrden(r->retHijoIzq());
            preOrden(r->retHijoDer());
            
        }
    }

    void iterativePreorder(Nodo<T>* n) {
        if (n == NULL) return;
        Pila<Nodo<T>*> p;
        p.Push(n);
        while (!p.estaVacia()) {
            n = p.Top();
            p.Pop();
            cout << n->retDato() << " "; 
            if (n->retHijoDer() != NULL) {
                p.Push(n->retHijoDer());
            }
            if (n->retHijoIzq() != NULL) {
                p.Push(n->retHijoIzq());
            }
        }
    }

    void iterativeInorder(Nodo<T>* n) {
        Pila<Nodo<T>*> p;
        while (!p.estaVacia() || n != NULL) {
            if (n != NULL) {
                p.Push(n);
                n = n->retHijoIzq();
            } else {
                n = p.Top();
                p.Pop();
                cout << n->retDato() << " ";
                n = n->retHijoDer();
            }
        }
    }

    void iterativePostorder(Nodo<T>* n) {
    Pila<Nodo<T>*> p;
    Nodo<T>* lastNodeVisited = NULL;
    while (!p.estaVacia() || n != NULL) {
        if (n != NULL) {
            p.Push(n);
            n = n->retHijoIzq();
        } else {
            Nodo<T>* peekNode = p.Top();
            if (peekNode->retHijoDer() != NULL && lastNodeVisited != peekNode->retHijoDer()) {
                n = peekNode->retHijoDer();
            } else {
                cout << peekNode->retDato() << " ";
                lastNodeVisited = peekNode;
                p.Pop();
            }
        }
    }
}

    int altura(Nodo<T>* n) {
        if (n == NULL) return -1;
        int alturaIzq = altura(n->retHijoIzq());
        int alturaDer = altura(n->retHijoDer());
        return 1 + max(alturaIzq, alturaDer);
    }

    int cantidadNodos(Nodo<T>* n) {
        if (n == NULL) return 0;
        return 1 + cantidadNodos(n->retHijoIzq()) + cantidadNodos(n->retHijoDer());
    }

    void imprimirPorNiveles(Nodo<T>* n) {
        if (n == NULL) return;
        queue<Nodo<T>*> q;
        q.push(n);
        while (!q.empty()) {
            Nodo<T>* current = q.front();
            q.pop();
            cout << current->retDato() << " ";
            if (current->retHijoIzq() != NULL) {
                q.push(current->retHijoIzq());
            }
            if (current->retHijoDer() != NULL) {
                q.push(current->retHijoDer());
            }
        }
    }
    int contarHojas(Nodo<T>* n) {
        if (n == NULL) return 0;
        if (n->retHijoIzq() == NULL && n->retHijoDer() == NULL) return 1;
        return contarHojas(n->retHijoIzq()) + contarHojas(n->retHijoDer());
    }
    
};
