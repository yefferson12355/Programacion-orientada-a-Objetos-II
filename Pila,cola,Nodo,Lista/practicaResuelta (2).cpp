#include <iostream>
#include <fstream>
using namespace std;

// Clase Nodo para almacenar los coches en la cola
class Nodo {
public:
    int valor;  // Longitud del coche
    Nodo* sig;  // Puntero al siguiente nodo

    // Constructor del nodo
    Nodo(int v) : valor(v), sig(NULL) {}
};

// Clase Cola para manejar la lista de coches
class Cola {
private:
    Nodo* prim;  // Puntero al primer nodo (cabeza de la cola)
    Nodo* ult;   // Puntero al último nodo (cola)
public:
    // Constructor de la cola
    Cola() {
        prim = NULL;
        ult = NULL;
    }

    // Insertar un coche en la cola
    void Insertar(int v) {
        Nodo* n = new Nodo(v);
        if (ult == NULL) {  // Si la cola está vacía
            prim = ult = n;
        } else {
            ult->sig = n;  // Unir el nuevo nodo al final
            ult = n;  // Actualizar el último nodo
        }
    }

    // Eliminar el primer coche de la cola
    void eliminar() {
        if (prim != NULL) {
            Nodo* temp = prim;
            prim = prim->sig;
            if (prim == NULL) {
                ult = NULL;  // Si la cola está vacía
            }
            delete temp;
        }
    }

    // Obtener la longitud del primer coche en la cola
    int Top() {
        if (prim != NULL) {
            return prim->valor;
        }
        return 0;
    }

    // Verificar cuántos coches hay en la cola
    int Size() {
        int contador = 0;
        Nodo* temp = prim;
        while (temp != NULL) {
            contador++;
            temp = temp->sig;
        }
        return contador;
    }
};

// Función que simula los viajes del transbordador
int trans(Cola* cola_izq, Cola* cola_der, int L) {
    int viajes = 0, tamaño;

    // Mientras haya coches en ambas orillas
    while (cola_izq->Size() > 0 || cola_der->Size() > 0) {
        // **Cargar coches desde la orilla izquierda**
        tamaño = 0;
        while (cola_izq->Size() > 0 && tamaño + cola_izq->Top() <= L) {
            tamaño += cola_izq->Top();  // Subir coche al transbordador
            cola_izq->eliminar();  // Eliminar el coche de la cola
        }
        viajes++;  // Viaje hacia la orilla derecha

        // Si no quedan coches por transportar, terminamos
        if (cola_izq->Size() == 0 && cola_der->Size() == 0) {
            break;
        }

        // **Cargar coches desde la orilla derecha**
        tamaño = 0;
        while (cola_der->Size() > 0 && tamaño + cola_der->Top() <= L) {
            tamaño += cola_der->Top();  // Subir coche al transbordador
            cola_der->eliminar();  // Eliminar el coche de la cola
        }
        viajes++;  // Viaje hacia la orilla izquierda
    }

    return viajes;  // Devolver el número total de viajes
}

int main() {
    Cola* cola_izq = new Cola();  // Cola para los coches en la orilla izquierda
    Cola* cola_der = new Cola();  // Cola para los coches en la orilla derecha
    ifstream archivo("Entrada");  // Abrir el archivo de entrada

    int C, L, M, coche;  // Variables: C (número de casos), L (longitud del transbordador), M (número de coches)
    string lado;  // Variable para el lado (izquierda o derecha)

    archivo >> C;  // Leer el número de casos
    for (int i = 0; i < C; i++) {
        archivo >> L >> M;  // Leer la longitud del transbordador y el número de coches
        L = L * 100;  // Convertir la longitud del transbordador a centímetros

        // Leer los coches y añadirlos a la cola correspondiente
        for (int j = 0; j < M; j++) {
            archivo >> coche >> lado;
            if (lado == "izquierda") {
                cola_izq->Insertar(coche);  // Añadir el coche a la cola izquierda
            } else {
                cola_der->Insertar(coche);  // Añadir el coche a la cola derecha
            }
        }

        // Llamar a la función que calcula el número de viajes
        cout << trans(cola_izq, cola_der, L) << endl;
    }

    return 0;
}
