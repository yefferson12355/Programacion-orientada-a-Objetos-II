#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Implementación del Nodo con template
template <class T>
class Nodo {
public:
    T dato;
    Nodo<T> *sig;

    Nodo(T v) {
        dato = v;
        sig = NULL;
    }
};

// Implementación de la Pila con métodos insertar, eliminar, esVacio, MenorValor
template <class T>
class Pila {
private:
    Nodo<T> *cima;

public:
    Pila() {
        cima = NULL;
    }

    bool esVacio() {
        return cima == NULL;
    }

    void insertar(T v) { // PUSH
        Nodo<T> *nuevo = new Nodo<T>(v);
        nuevo->sig = cima;
        cima = nuevo;
    }

    void eliminar() { // POP
        if(!esVacio()) {
            Nodo<T> *temp = cima;
            cima = cima->sig;
            delete temp;
        }
    }

    T MenorValor() { // MIN
        if(esVacio()) {
            throw runtime_error("Pila vacía");
        }

        Nodo<T> *temp = cima;
        T menor = temp->dato;
        while(temp != NULL) {
            if(temp->dato < menor) {
                menor = temp->dato;
            }
            temp = temp->sig;
        }
        return menor;
    }

    ~Pila() {
        while(!esVacio()) {
            eliminar();
        }
    }
};

int main() {
    Pila<int> *p = new Pila<int>();
    ifstream arch("entrada.txt");
    int cant;
    string linea;

    arch >> cant;
    getline(arch, linea); // Consumir salto de línea pendiente después de leer 'cant'

    while(cant >= 0) {
        cant--;
        getline(arch, linea);
        istringstream ss(linea);
        string palab1;
        int valor;
        
        while(ss >> palab1) {
            if(palab1 == "PUSH") {
                ss >> valor;
                p->insertar(valor);
            } else if(palab1 == "POP") {
                if(!p->esVacio())
                    p->eliminar();
                else
                    cout << "Empty" << endl;
            } else if(palab1 == "MIN") {
                if(!p->esVacio())
                    cout << p->MenorValor() << endl;
                else
                    cout << "Empty" << endl;
            }
        }
    }

    delete p; // Liberar memoria

    return 0;
}
/*  #include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Se supone que ya tienes implementada la clase Pila
// Aquí deberías asegurarte que existan los métodos: insertar, eliminar, esVacio, MenorValor

int main() {
    Pila<int> *p = new Pila<int>();
    ifstream arch("entrada.txt");
    int cant;
    string linea;

    arch >> cant;

    while(cant >= 0) {
        cant--;
        getline(arch, linea);
        istringstream ss(linea);
        string palab1;
        int valor;
        
        while(ss >> palab1) {
            if(palab1 == "PUSH") {
                ss >> valor;
                p->insertar(valor);
            } else if(!p->esVacio() && palab1 == "POP") {
                p->eliminar();
            } else if(!p->esVacio() && palab1 == "MIN") {
                cout << p->MenorValor() << endl;
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}
*/