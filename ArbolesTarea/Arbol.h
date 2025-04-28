//
// Created by YEFER on 27/10/2024.
//
#include "Nodo.h"
#include "Lista.h"
#include "Pila .h"
#include <stack>
#include <queue>
#ifndef ARBOL_H
#define ARBOL_H

using namespace std;

template <class T>
class Arbol {
private:
    Nodo<T> *raiz;
public:
    Arbol() : raiz(NULL) {}

    void Insertar(T v) {
        Nodo<T> *n = new Nodo<T>(v);
        if (raiz == NULL)
            raiz = n;
        else
            Insertar(raiz, n);
    }
    //Insertar iterativo
    void InsertarIte(T v) {
        InsertarIterativo(v); // Llama al metodo de inserción iterativo
    }

    void inOrden() {
        inOrden(raiz);
    }
    void postOrden() {
        postOrden(raiz);
    }

    void iterativeInorden() {
        iterativeInordenHelper(raiz);
    }
    void iterativePostorder() {
        iterativePostorder(raiz);
    }
    void iterativePreorder() {
        iterativePreorder(raiz);
    }




    // Nuevo metodo público para contar nodos
    int cantNodos() {
        int contador = 0;
        cantNodos(raiz, contador); // Llama a la función auxiliar
        return contador;
    }
    int altura() {
        return altura(raiz);
    }

    //ImprimirPorniveles
    void imprimirPorNiveles() {
        if (raiz == NULL) return; // Si el árbol está vacío, no hay nada que imprimir

        Lista<Nodo<T>*> nodos;        // Usamos la lista para almacenar nodos
        nodos.insertFinal(raiz);      // Agregar la raíz

        while (!nodos.estaVacia()) {  // Mientras haya nodos en la lista
            Nodo<T>* current = nodos.obtenerPrimero()->retDato(); // Obtener el nodo actual

            // Visitar el nodo
            cout << current->retDato() << " ";

            // Agregar los hijos a la lista
            if (current->retHijoIzq() != NULL) {
                nodos.insertFinal(current->retHijoIzq());
            }
            if (current->retHijoDer() != NULL) {
                nodos.insertFinal(current->retHijoDer());
            }

            // Eliminar el nodo que hemos visitado
            nodos.eliminarPrimero();
        }
        cout << endl; // Imprimir nueva línea al final
    }



protected:
    void Insertar(Nodo<T> *r, Nodo<T> *n) {
        // lado izquierdo
        if (r->retDato() > n->retDato()) {
            if (r->retHijoIzq() == NULL)
                r->unirConIzq(n);
            else
                Insertar(r->retHijoIzq(), n);
        }
        // lado derecho
        else if (r->retDato() < n->retDato()) {
            if (r->retHijoDer() == NULL)
                r->unirConDer(n);
            else
                Insertar(r->retHijoDer(), n);
        }
    }
    void InsertarIterativo(T v) {
        Nodo<T>* n = new Nodo<T>(v); // Crea un nuevo nodo con el valor proporcionado

        // Si el árbol está vacío, asigna el nuevo nodo como raíz
        if (raiz == NULL) {
            raiz = n;
            return;
        }

        // Puntero para recorrer el árbol a partir de la raíz
        Nodo<T>* current = raiz; //Actual
        Nodo<T>* parent = NULL;  //Padre

        // Bucle para encontrar la posición adecuada
        while (true) {
            parent = current;

            // Si el valor es menor, avanzamos hacia el hijo izquierdo
            if (n->retDato() < current->retDato()) {
                current = current->retHijoIzq();
                if (current == NULL) {//
                    parent->unirConIzq(n); // Insertamos aquí
                    return;
                }
            }
            // Si el valor es mayor o igual, avanzamos hacia el hijo derecho
            else {
                current = current->retHijoDer();
                if (current == NULL) {
                    parent->unirConDer(n); // Insertamos aquí
                    return;
                }
            }
        }
    }

    void inOrden(Nodo<T> *r) {
        if (r != NULL) {
            inOrden(r->retHijoIzq());
            cout << r->retDato() << " ";
            inOrden(r->retHijoDer());
        }
    }

    void postOrden(Nodo<T> *r) {
        if (r != NULL) {
            postOrden(r->retHijoIzq());
            postOrden(r->retHijoDer());
            cout << r->retDato() << " ";
        }
    }

    //Forma iterativa #Recorridos.

    void iterativeInordenHelper(Nodo<T>* n) {
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

    //Función auxiliar para contar nodos
    void cantNodos(Nodo<T>* node, int& contador) {
        if (node == NULL) return;
        contador++; // Aumenta el contador por cada nodo encontrado
        cantNodos(node->retHijoIzq(), contador);
        cantNodos(node->retHijoDer(), contador);
    }

    // Metodo para calcular la altura del árbol
    int altura(Nodo<T>* node) {
        if (node == NULL) return -1; // Se devuelve -1 si el nodo es nulo
        int alturaIzq = altura(node->retHijoIzq());
        int alturaDer = altura(node->retHijoDer());
        return 1 + max(alturaIzq, alturaDer);
    }

};

#endif //ARBOL_H
