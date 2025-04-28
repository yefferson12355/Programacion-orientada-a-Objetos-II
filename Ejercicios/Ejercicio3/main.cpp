#include <iostream>

using namespace std;

// Clase Nodo que representa un nodo en la estructura de la cola
class Nodo {
private:
    int valor;  // Valor almacenado en el nodo
    Nodo *siguiente;  // Puntero al siguiente nodo
public:
    Nodo(int v) {
        valor = v;
        siguiente = nullptr;
    }
    // Retorna el siguiente nodo
    Nodo *obtenerSiguiente() {
        return siguiente;
    }
    // Retorna el valor del nodo
    int obtenerValor() {
        return valor;
    }
    // Enlaza este nodo con otro
    void enlazarCon(Nodo *n) {
        siguiente = n;
    }
};

// Clase Cola que representa una cola enlazada
class Cola {
private:
    Nodo *primero;  // Puntero al primer nodo de la cola
    Nodo *ultimo;   // Puntero al último nodo de la cola
public:
    Cola() {
        primero = ultimo = nullptr;
    }

    // Retorna el primer o último nodo dependiendo del valor pasado
    Nodo *obtenerNodo(int opcion) {
        if (opcion == 1) {  // Retorna el primer nodo
            return primero;
        }
        if (opcion == 2) {  // Retorna el último nodo
            return ultimo;
        }
    }

    // Inserta un nuevo nodo al final de la cola
    void insertarFinal(int valor) {
        Nodo *nuevo = new Nodo(valor);
        if (ultimo == nullptr) {
            primero = ultimo = nuevo;
        } else {
            ultimo->enlazarCon(nuevo);
            ultimo = nuevo;
        }
    }

    // Elimina el primer nodo de la cola
    void eliminarFrente() {
        if (primero != nullptr) {
            Nodo *temp = primero;
            primero = temp->obtenerSiguiente();
            delete temp;
            if (primero == nullptr) {
                ultimo = nullptr;
            }
        }
    }

    // Muestra los valores de todos los nodos en la cola
    void mostrarValores() {
        Nodo *temp = primero;
        while (temp != nullptr) {
            cout << temp->obtenerValor() << endl;
            temp = temp->obtenerSiguiente();
        }
    }

    // Inserta un nuevo nodo al frente de la cola
    void insertarFrente(int valor) {
        Nodo *nuevo = new Nodo(valor);
        if (primero == nullptr) {
            primero = ultimo = nuevo;
        } else {
            nuevo->enlazarCon(primero);
            primero = nuevo;
        }
    }

    // Elimina el último nodo de la cola
    void eliminarFinal() {
        if (primero != nullptr) {
            if (primero == ultimo) {
                delete primero;
                primero = ultimo = nullptr;
            } else {
                Nodo *temp = primero;
                while (temp->obtenerSiguiente() != ultimo) {
                    temp = temp->obtenerSiguiente();
                }
                delete ultimo;
                ultimo = temp;
                ultimo->enlazarCon(nullptr);
            }
        }
    }

    // Retorna el valor del nodo en una posición específica
    int obtenerValorPorPosicion(int posicion) {
        Nodo *temp = primero;
        int contador = 1;
        while (temp != nullptr && contador < posicion) {
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        if (temp != nullptr) {
            return temp->obtenerValor();
        }
    }

    // Retorna la posición de un nodo por su valor
    int obtenerPosicionPorValor(int valor) {
        Nodo *temp = primero;
        int contador = 1;
        while (temp != nullptr && valor != temp->obtenerValor()) {
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        if (temp != nullptr) {
            return contador;
        }
    }
};

int main() {
    Cola *gestorCola = new Cola();

    int totalNodos;
    cin >> totalNodos;  // Total de nodos a insertar en la cola

    int k;
    cin >> k;  // Número de saltos para eliminar nodos

    int valorNodo;
    for (int i = 1; i < totalNodos; i++) {
        cin >> valorNodo;
        gestorCola->insertarFinal(valorNodo);  // Inserta valores en la cola
    }

    // Enlaza el último nodo con el primero, formando un ciclo
    Nodo *primero = gestorCola->obtenerNodo(1);
    Nodo *ultimo = gestorCola->obtenerNodo(2);
    primero->enlazarCon(ultimo);

    Nodo *nodoActual = primero;
    Nodo *nodoAnterior = ultimo;

    // Elimina nodos en pasos de 'k' hasta que solo quede uno
    while (nodoActual != nodoActual->obtenerSiguiente()) {
        for (int i = 1; i < k; ++i) {
            nodoAnterior = nodoActual;
            nodoActual = nodoActual->obtenerSiguiente();
        }

        nodoAnterior->enlazarCon(nodoActual->obtenerSiguiente());
        delete nodoActual;
        nodoActual = nodoAnterior->obtenerSiguiente();
    }

    // Muestra el último nodo restante
    cout << "El último nodo es: " << nodoActual->obtenerValor() << endl;
    delete nodoActual;

    return 0;
}
