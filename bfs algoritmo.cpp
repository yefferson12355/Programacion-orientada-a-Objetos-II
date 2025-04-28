/**************************************************
 * Algoritmo: BFS (Búsqueda por Anchura en un Grafo)
 * Descripción: Encuentra el camino más corto entre dos nodos usando BFS
 * Complejidad: O(V + E) donde V es número de vértices y E es número de aristas
 **************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500;

class BusquedaGrafo {
private:
    vector<vector<int>> listaAdyacencia;
    vector<bool> visitado;
    vector<int> padre;
    vector<int> distancia;
    int numVertices;
    int numAristas;

    // Validar si un nodo está dentro del rango válido
    bool esNodoValido(int nodo) const {
        return nodo >= 0 && nodo < numVertices;
    }

public:
    BusquedaGrafo(int vertices, int aristas) : 
        numVertices(vertices), 
        numAristas(aristas),
        listaAdyacencia(vertices), // Ahora usamos el número real de vértices
        visitado(vertices, false),
        padre(vertices, -1),
        distancia(vertices, -1) {}

    bool agregarArista(int origen, int destino) {
        // Validación de nodos
        if (!esNodoValido(origen) || !esNodoValido(destino)) {
            cout << "Error: Nodo fuera del rango válido [0," << numVertices-1 << "]\n";
            return false;
        }
        
        listaAdyacencia[origen].push_back(destino);
        return true;
    }

    void limpiarEstado() {
        visitado.assign(numVertices, false);
        padre.assign(numVertices, -1);
        distancia.assign(numVertices, -1);
    }

    void imprimirCamino(int inicio, int fin) {
        if (distancia[fin] == -1) {
            cout << "No existe camino entre " << inicio << " y " << fin << "\n";
            return;
        }

        vector<int> camino;
        for (int actual = fin; actual != -1; actual = padre[actual]) {
            camino.push_back(actual);
        }

        cout << "\nCamino más corto encontrado (distancia = " << distancia[fin] << "):\n";
        for (int i = camino.size() - 1; i >= 0; i--) {
            cout << camino[i];
            if (i > 0) cout << " -> ";
        }
        cout << "\n";
    }

    bool bfs() {
        int nodoInicial, nodoFinal;
        cout << "Ingrese nodo inicial: ";
        cin >> nodoInicial;
        cout << "Ingrese nodo final: ";
        cin >> nodoFinal;

        if (!esNodoValido(nodoInicial) || !esNodoValido(nodoFinal)) {
            cout << "Error: Nodos deben estar en el rango [0," << numVertices-1 << "]\n";
            return false;
        }

        limpiarEstado();
        queue<int> cola;
        cola.push(nodoInicial);
        visitado[nodoInicial] = true;
        distancia[nodoInicial] = 0;

        int pasos = 0;
        int tamañoMaxCola = 0;
        bool caminoEncontrado = false;

        cout << "\nIniciando BFS desde nodo " << nodoInicial << "...\n";

        while (!cola.empty()) {
            tamañoMaxCola = max(tamañoMaxCola, (int)cola.size());
            int nodoActual = cola.front();
            cola.pop();
            pasos++;

            if (nodoActual == nodoFinal) {
                caminoEncontrado = true;
                break;
            }

            // Ordenamos los vecinos para obtener el camino lexicográfico más corto
            sort(listaAdyacencia[nodoActual].begin(), listaAdyacencia[nodoActual].end());

            for (int vecino : listaAdyacencia[nodoActual]) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    cola.push(vecino);
                    padre[vecino] = nodoActual;
                    distancia[vecino] = distancia[nodoActual] + 1;
                    cout << "Explorando: " << nodoActual << " --> " << vecino;
                    cout << " (distancia: " << distancia[vecino] << ")\n";
                }
            }
        }

        cout << "\n--- Resultados de la búsqueda ---\n";
        cout << "Nodos explorados: " << pasos << "\n";
        cout << "Tamaño máximo de cola: " << tamañoMaxCola << "\n";
        cout << "Estado: " << (caminoEncontrado ? "¡Camino encontrado!" : "Camino no encontrado") << "\n";

        if (caminoEncontrado) {
            imprimirCamino(nodoInicial, nodoFinal);
        }

        return caminoEncontrado;
    }
};

int main() {
    cout << "*** Búsqueda por Anchura (BFS) ***\n\n";
    
    int V, E;
    cout << "Ingrese número de vértices y aristas (V E): ";
    cin >> V >> E;

    if (V <= 0 || V > MAX || E < 0 || E > V * (V-1)) {
        cout << "Error: Valores inválidos\n";
        cout << "- Número de vértices debe estar entre 1 y " << MAX << "\n";
        cout << "- Número de aristas debe estar entre 0 y " << V * (V-1) << "\n";
        return 1;
    }

    BusquedaGrafo grafo(V, E);

    cout << "\nIngrese las " << E << " aristas (origen destino):\n";
    cout << "Los nodos deben estar en el rango [0," << V-1 << "]\n";
    
    for (int i = 0; i < E; ++i) {
        int origen, destino;
        cin >> origen >> destino;
        if (!grafo.agregarArista(origen, destino)) {
            cout << "Error al agregar arista " << i+1 << ". Por favor, intente de nuevo.\n";
            i--; // Repetir esta iteración
        }
    }

    grafo.bfs();
    return 0;
}