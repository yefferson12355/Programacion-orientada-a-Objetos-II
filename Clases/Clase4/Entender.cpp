#include <iostream>

#define MAXIMO 5  // Definimos el tamaño máximo para la pila estática

using namespace std;

// Clase Nodo, utilizada por la pila dinámica
class Nodo {
private:
    int dato;  // Almacena el valor del nodo
    Nodo *sig; // Apunta al siguiente nodo en la pila
public:
    // Constructor que inicializa el nodo con un valor y apunta a NULL
    Nodo(int v) {
        dato = v;
        sig = NULL;
    }

    // Constructor por defecto
    Nodo() {}

    // Retorna el puntero al siguiente nodo
    Nodo *retSig() {
        return sig;
    }

    // Retorna el dato almacenado en el nodo
    int retDato() {
        return dato;
    }

    // Une este nodo con otro nodo (establece el siguiente nodo)
    void unirCon(Nodo *n) {
        sig = n;
    }
};

// Clase Pila (implementación dinámica con nodos)
class Pila {
private:
    Nodo *cima; // Apunta al nodo que está en la cima de la pila
public:
    // Constructor que inicializa la pila como vacía
    Pila() {
        cima = NULL;
    }

    // Inserta un nuevo valor en la cima de la pila
    void Push(int v) {
        Nodo *n = new Nodo(v);  // Crea un nuevo nodo con el valor
        n->unirCon(cima);       // Conecta el nuevo nodo con la antigua cima
        cima = n;               // Actualiza la cima para que apunte al nuevo nodo
    }

    // Elimina el nodo en la cima de la pila
    void Pop() {
        if (cima != NULL) {             // Verifica si la pila no está vacía
            Nodo *temp = cima;          // Guarda la referencia de la cima actual
            cima = temp->retSig();      // Actualiza la cima al siguiente nodo
            delete temp;                // Elimina el nodo anterior
        }
    }

    // Muestra todos los datos de la pila desde la cima hasta el fondo
    void mostrarDatos() {
        Nodo *temp = cima;              // Inicia desde la cima
        while (temp != NULL) {          // Recorre la pila hasta que no haya más nodos
            cout << temp->retDato() << endl; // Imprime el dato del nodo actual
            temp = temp->retSig();           // Avanza al siguiente nodo
        }
    }

    // Retorna el tamaño de la pila (cantidad de nodos)
    int Size() {
        Nodo *temp = cima;              // Inicia desde la cima
        int i = 0;                      // Contador de nodos
        while (temp != NULL) {          // Recorre la pila
            i++;                        // Incrementa el contador
            temp = temp->retSig();      // Avanza al siguiente nodo
        }
        return i;                       // Retorna el tamaño de la pila
    }
};

// Clase PilaEst (implementación estática con array)
class PilaEst {
private:
    int pi[MAXIMO];  // Arreglo que almacena los valores de la pila
    int ind;         // Índice que indica la cantidad de elementos en la pila
public:
    // Constructor que inicializa la pila vacía
    PilaEst() {
        ind = 0;  // Inicia el índice en 0 (pila vacía)
    }

    // Inserta un nuevo valor en la pila si no está llena
    void Insertar(int v) {
        if (ind < MAXIMO) {   // Verifica si hay espacio en la pila
            pi[ind] = v;      // Almacena el valor en la posición actual
            ind++;            // Incrementa el índice
        }
    }

    // Elimina el último valor insertado en la pila
    void Extraer() {
        if (ind > 0)          // Verifica si hay elementos para extraer
            ind--;            // Reduce el índice (elimina el último elemento)
    }

    // Retorna el valor en la posición especificada
    int retDato(int i) {
        return pi[i];         // Devuelve el valor almacenado en la posición `i`
    }
};

// Función principal
int main() {
    // Ejemplo con la clase Pila (implementación dinámica)
    Pila *pi = new Pila();
    pi->Push(3);     // Inserta 3 en la pila
    pi->Push(5);     // Inserta 5 en la pila
    pi->Push(8);     // Inserta 8 en la pila
    pi->Push(7);     // Inserta 7 en la pila
    pi->Pop();       // Elimina el elemento en la cima (7)
    pi->Pop();       // Elimina el siguiente elemento en la cima (8)

    cout << "Datos en la Pila dinámica:" << endl;
    pi->mostrarDatos();  // Muestra los elementos restantes de la pila
    cout << "Tamaño de la Pila dinámica: " << pi->Size() << endl;  // Muestra el tamaño de la pila

    delete pi;  // Libera la memoria asignada a la pila

    // Ejemplo con la clase PilaEst (implementación estática)
    PilaEst piEst;
    piEst.Insertar(3);  // Inserta 3 en la pila
    piEst.Insertar(8);  // Inserta 8 en la pila
    piEst.Extraer();    // Elimina el último elemento (8)
    piEst.Extraer();    // Elimina el siguiente elemento (3)
    piEst.Extraer();    // Intenta eliminar otro elemento, pero la pila ya está vacía

    cout << "\nDatos en la Pila estática:" << endl;
    for (int i = MAXIMO - 1; i >= 0; i--) {
        cout << piEst.retDato(i) << endl;  // Muestra los datos almacenados en la pila estática
    }

    return 0;
}
