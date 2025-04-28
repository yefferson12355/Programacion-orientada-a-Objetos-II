#include <iostream>
#include <ostream>

using namespace std;

class Nodo {
private:
    int dato;      // Valor almacenado en el nodo
    Nodo *siguiente;  // Apuntador al siguiente nodo
public:
    Nodo(int v) {
        dato = v;
        siguiente = nullptr;
    }
    // Devuelve el siguiente nodo
    Nodo *obtenerSiguiente() {
        return siguiente;
    }
    // Devuelve el valor almacenado en el nodo
    int obtenerDato() {
        return dato;
    }
    // Enlaza este nodo con otro
    void enlazar(Nodo *n) {
        siguiente = n;
    }
    // Asigna un nuevo valor al nodo
    void asignarDato(int valor) {
        dato = valor;
    }
};

class Cola {
private:
    Nodo *inicio;  // Primer nodo de la cola
    Nodo *fin;     // Último nodo de la cola
public:
    Cola() {
        inicio = fin = nullptr;
    }

    // Inserta un nuevo nodo al final de la cola
    void agregar(int valor) {
        Nodo *nuevo = new Nodo(valor);
        if (fin == nullptr) {
            inicio = fin = nuevo;
        } else {
            fin->enlazar(nuevo);
            fin = nuevo;
        }
    }

    // Elimina el nodo al frente de la cola
    void eliminarFrente() {
        if (inicio != nullptr) {
            Nodo *temp = inicio;
            inicio = inicio->obtenerSiguiente();
            delete temp;
            if (inicio == nullptr) {
                fin = nullptr;
            }
        }
    }

    // Muestra todos los datos de la cola
    void mostrarDatos() {
        Nodo *temp = inicio;
        while (temp != nullptr) {
            cout << temp->obtenerDato() << endl;
            temp = temp->obtenerSiguiente();
        }
    }

    // Devuelve el valor en una posición específica
    int obtenerPorPosicion(int posicion) {
        Nodo *temp = inicio;
        int contador = 0;
        while (temp != nullptr && contador < posicion) {
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        if (temp != nullptr) {
            return temp->obtenerDato();
        }
        return -1;  // Valor por defecto en caso de que la posición no exista
    }

    // Devuelve la dirección de un nodo en una posición específica
    Nodo *obtenerNodoPorPosicion(int posicion) {
        Nodo *temp = inicio;
        int contador = 0;
        while (temp != nullptr && contador < posicion) {
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        return temp;  // Retorna nullptr si la posición no existe
    }

    // Intercambia los valores de dos nodos en posiciones dadas
    void intercambiar(int pos1, int pos2) {
        Nodo *nodo1 = obtenerNodoPorPosicion(pos1);
        Nodo *nodo2 = obtenerNodoPorPosicion(pos2);
        if (nodo1 != nullptr && nodo2 != nullptr) {  // Asegura que ambos nodos existan
            int temp = nodo1->obtenerDato();
            nodo1->asignarDato(nodo2->obtenerDato());
            nodo2->asignarDato(temp);
        }
    }
};

int main() {
    Cola *gestorCola = new Cola();
    int total;
    cin >> total;  // Lee el número total de nodos a insertar
    int tiempo;

    // Inserción de tiempos en la cola
    for (int i = 0; i < total; i++) {
        cin >> tiempo;
        gestorCola->agregar(tiempo);
    }

    // Ordenamiento por selección (Selection Sort)
    for (int i = 0; i < total - 1; i++) {
        int minTiempo = i;
        for (int j = i + 1; j < total; j++) {
            if (gestorCola->obtenerPorPosicion(j) < gestorCola->obtenerPorPosicion(minTiempo)) {
                minTiempo = j;
            }
        }
        gestorCola->intercambiar(i, minTiempo);
    }

    // Muestra los tiempos ordenados
    gestorCola->mostrarDatos();
    cout << endl;

    // Cálculo de clientes satisfechos
    int satisfechos = 0;
    int tiempoTotal = 0;
    for (int i = 0; i < total; i++) {
        Nodo *temp = gestorCola->obtenerNodoPorPosicion(i);
        tiempo = temp->obtenerDato();
        if (tiempoTotal <= tiempo) {
            satisfechos++;
        }
        tiempoTotal += tiempo;
    }

    cout << endl << satisfechos;
    return 0;
}
