/*****************************************************
 * Algoritmo: DFS (Búsqueda en Profundidad) con Backtracking
 * Descripción: Implementa DFS con:
 * - Recorrido completo del grafo
 * - Búsqueda de todos los caminos posibles entre dos nodos
 * - Backtracking para exploración exhaustiva
 * Complejidad: O(V + E) para DFS simple, O(V!) para todos los caminos
 *****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BusquedaProfundidad {
private:
    // Estructuras principales
    vector<vector<int>> listaAdyacencia;  // Grafo
    vector<bool> visitado;                // Nodos visitados
    vector<int> camino;                   // Almacena el camino actual
    int numVertices;                      // Número de vértices
    int numAristas;                       // Número de aristas
    bool primerElemento;                  // Control de formato de impresión

    // Verifica si un nodo es válido
    bool esNodoValido(int nodo) const {
        return nodo >= 0 && nodo < numVertices;
    }

public:
    // Constructor
    BusquedaProfundidad(int vertices, int aristas) : 
        numVertices(vertices),
        numAristas(aristas),
        listaAdyacencia(vertices),
        visitado(vertices, false),
        primerElemento(true) {}

    // Agrega una arista al grafo
    bool agregarArista(int origen, int destino, bool bidireccional = true) {
        if (!esNodoValido(origen) || !esNodoValido(destino)) {
            cout << "Error: Nodo fuera del rango [0," << numVertices-1 << "]\n";
            return false;
        }
        
        listaAdyacencia[origen].push_back(destino);
        if (bidireccional) {
            listaAdyacencia[destino].push_back(origen);
        }
        return true;
    }

    // DFS básico - recorre todo el grafo
    void dfs(int nodo) {
        // Impresión con formato
        if (primerElemento) {
            cout << nodo;
            primerElemento = false;
        } else {
            cout << " -> " << nodo;
        }

        visitado[nodo] = true;

        // Ordenamos los vecinos para consistencia
        sort(listaAdyacencia[nodo].begin(), listaAdyacencia[nodo].end());

        // Exploramos cada vecino no visitado
        for (int vecino : listaAdyacencia[nodo]) {
            if (!visitado[vecino]) {
                dfs(vecino);
            }
        }
    }

    // DFS con backtracking - encuentra todos los caminos posibles
    void dfsAllPaths(int actual, int destino, int longitud) {
        visitado[actual] = true;
        camino.push_back(actual);  // Agregamos el nodo actual al camino

        // Si llegamos al destino, imprimimos el camino
        if (actual == destino) {
            cout << "Camino " << longitud << ": ";
            for (size_t i = 0; i < camino.size(); i++) {
                if (i > 0) cout << " -> ";
                cout << camino[i];
            }
            cout << "\n";
        } else {
            // Exploramos todos los vecinos posibles
            for (int vecino : listaAdyacencia[actual]) {
                if (!visitado[vecino]) {
                    dfsAllPaths(vecino, destino, longitud + 1);
                }
            }
        }

        // Backtracking: deshacemos los cambios
        visitado[actual] = false;
        camino.pop_back();
    }

    // Ejecuta el recorrido DFS completo
    void ejecutarDFS() {
        int inicial;
        cout << "Ingrese nodo inicial: ";
        cin >> inicial;

        if (!esNodoValido(inicial)) {
            cout << "Error: Nodo inicial inválido\n";
            return;
        }

        // Reiniciamos estado
        fill(visitado.begin(), visitado.end(), false);
        primerElemento = true;

        cout << "\nRecorrido DFS completo:\n";
        dfs(inicial);
        cout << "\n";
    }

    // Encuentra todos los caminos entre dos nodos
    void encontrarTodosCaminos() {
        int inicial, final;
        cout << "\nBúsqueda de todos los caminos posibles\n";
        cout << "Ingrese nodo inicial: ";
        cin >> inicial;
        cout << "Ingrese nodo final: ";
        cin >> final;

        if (!esNodoValido(inicial) || !esNodoValido(final)) {
            cout << "Error: Nodos inválidos\n";
            return;
        }

        // Reiniciamos estado
        fill(visitado.begin(), visitado.end(), false);
        camino.clear();

        cout << "\nTodos los caminos posibles de " << inicial << " a " << final << ":\n";
        dfsAllPaths(inicial, final, 1);
    }
};

int main() {
    cout << "*** DFS con Backtracking ***\n\n";
    
    int V, E;
    cout << "Ingrese número de vértices y aristas (V E): ";
    cin >> V >> E;

    if (V <= 0 || E < 0) {
        cout << "Error: Valores inválidos\n";
        return 1;
    }

    BusquedaProfundidad grafo(V, E);

    cout << "\nIngrese las " << E << " aristas (origen destino):\n";
    for (int i = 0; i < E; i++) {
        int origen, destino;
        cin >> origen >> destino;
        if (!grafo.agregarArista(origen, destino)) {
            cout << "Error en arista " << i+1 << ". Intente de nuevo.\n";
            i--;
        }
    }

    // Ejecutamos ambos tipos de búsqueda
    grafo.ejecutarDFS();
    grafo.encontrarTodosCaminos();

    return 0;
}