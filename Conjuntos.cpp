#include <iostream>

using namespace std;

/*Programa(s) de unión, intersección,
diferencia y diferencia simétrica de 2 conjuntos cuyos
elementos son los números enteros positivos.*/


//utilize buenas practicas...videos de youtube para conceptos mas claros de conjuntos, y
//ver como hacerlo en codigo, reultizacion de funciones, paso por parametros me ayude con chatgpt
const int TAMANO_MAX = 100;  // Definir el tamaño máximo para los conjuntos

void leerConjunto(int conjunto[], int& n, const string& nombre) {
    cout << "Ingrese el numero de elementos para el conjunto " << nombre << ": ";
    cin >> n;

    cout << "Ingrese los elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < n; ++i) {
        cin >> conjunto[i];

        if(conjunto[i] < 0){
            cout << "El numero es negativo" << endl;
            --i;  // Decrementar el í para volver a pedir el número
        }
    }
}

// Función para imprimir un conjunto
void imprimirConjunto(const int conjunto[], int n, const string& nombre) {
    cout << endl;
    cout << "Elementos del conjunto " << nombre << ": ";
    for (int i = 0; i < n; ++i) {
        cout << conjunto[i] << " ";
    }
    cout << endl;
}

// Función para realizar la unión de dos conjuntos
void unionConjuntos(const int A[], int nA, const int B[], int nB, int unionSet[], int& nUnion) {
    nUnion = 0;

    // Copiar todos los elementos de A a unionSet
    for (int i = 0; i < nA; ++i) {
        //idea de chatgpt...para buena practica..buen truco nUnion para ponerlo en orden,
        //y haci ayudar al siguiente conjunto..
        unionSet[nUnion++] = A[i];
    }

    // Copiar los elementos de B que no están en A
    for (int i = 0; i < nB; ++i) {
        bool duplicado = false;
        for (int j = 0; j < nA; ++j) {
            if (B[i] == A[j]) {
                duplicado = true;
                break;
            }
        }
        if (!duplicado) {
            unionSet[nUnion++] = B[i];
        }
    }
}

// Función para realizar la intersección de dos conjuntos
void interseccionConjuntos(const int A[], int nA, const int B[], int nB, int interseccionSet[], int& nInterseccion) {
    nInterseccion = 0;

    // Buscar elementos de A que tambien están en B
    //dobles bucles comprobar en Conjunto a y b , guardar en interseccion,y comparar nuevamente en
    //conjunto A para estar seguro, y no halla duplicados
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) {
                // Verificar si ya está en el conjunto de intersección
                bool duplicado = false;
                for (int k = 0; k < nInterseccion; ++k) {
                    if (interseccionSet[k] == A[i]) {
                        duplicado = true;
                        break;
                    }
                }
                if (!duplicado) {
                    interseccionSet[nInterseccion++] = A[i];
                }
            }
        }
    }
}

// Función para realizar la diferencia de dos conjuntos
void diferenciaConjuntos(const int A[], int nA, const int B[], int nB, int diferenciaSet[], int& nDiferencia) {
    nDiferencia = 0;
    // Buscar elementos de A que no están en B
    for (int i = 0; i < nA; ++i) {
        bool encontrado = false;
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            diferenciaSet[nDiferencia++] = A[i];
        }
    }
}

// Función para realizar la diferencia inversa de dos conjuntos
void diferenciaConjuntosInverso(const int A[], int nA, const int B[], int nB, int diferenciaSet[], int& nDiferenciaInverso) {
    nDiferenciaInverso = 0;
    // Buscar elementos de B que no están en A
    for (int i = 0; i < nB; ++i) {
        bool encontrado = false;
        for (int j = 0; j < nA; ++j) {
            if (B[i] == A[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            diferenciaSet[nDiferenciaInverso++] = B[i];
        }
    }
}

// Función para realizar la diferencia simétrica de dos conjuntos
void diferenciaSimetrica(const int A[], int nA, const int B[], int nB, int diferenciaSimetricaSet[], int& nDiferenciaSimetrica) {
    //Diferencia Simetrica es (A-B)U(B-A)
    int diferenciaSetA[TAMANO_MAX], diferenciaSetB[TAMANO_MAX];
    int nDiferenciaA = 0, nDiferenciaB = 0;
    //reutilizamos la  funcion diferencia
    diferenciaConjuntos(A, nA, B, nB, diferenciaSetA, nDiferenciaA);
    diferenciaConjuntosInverso(A, nA, B, nB, diferenciaSetB, nDiferenciaB);

    nDiferenciaSimetrica = 0;
    for (int i = 0; i < nDiferenciaA; ++i) {
        diferenciaSimetricaSet[nDiferenciaSimetrica++] = diferenciaSetA[i];
    }
    for (int i = 0; i < nDiferenciaB; ++i) {
        diferenciaSimetricaSet[nDiferenciaSimetrica++] = diferenciaSetB[i];
    }
}

int main() {
    // Tamaño máximo para los conjuntos
    const int TAMANO_MAX = 100;

    // Arrays de conjuntos
    int conjuntoA[TAMANO_MAX], conjuntoB[TAMANO_MAX], unionSet[TAMANO_MAX],
    interseccionSet[TAMANO_MAX], diferenciaSet[TAMANO_MAX],
    diferenciaSetInverso[TAMANO_MAX], diferenciaSimetricaSet[TAMANO_MAX];

    // Números de elementos de A, B... operados en función
    int nA, nB, nUnion, nInterseccion, nDiferencia, nDiferenciaInverso, nDiferenciaSimetrica;

    // Entrada de datos A y B
    leerConjunto(conjuntoA, nA, "A");
    leerConjunto(conjuntoB, nB, "B");

    // Imprimir datos A y B
    imprimirConjunto(conjuntoA, nA, "A");
    imprimirConjunto(conjuntoB, nB, "B");

    // Unión
    unionConjuntos(conjuntoA, nA, conjuntoB, nB, unionSet, nUnion);
    imprimirConjunto(unionSet, nUnion, "Union");

    // Intersección
    interseccionConjuntos(conjuntoA, nA, conjuntoB, nB, interseccionSet, nInterseccion);
    imprimirConjunto(interseccionSet, nInterseccion, "Interseccion");

    // Diferencia A-B
    diferenciaConjuntos(conjuntoA, nA, conjuntoB, nB, diferenciaSet, nDiferencia);
    imprimirConjunto(diferenciaSet, nDiferencia, "Diferencia de A-B");

    // Diferencia B-A
    diferenciaConjuntosInverso(conjuntoA, nA, conjuntoB, nB, diferenciaSetInverso, nDiferenciaInverso);
    imprimirConjunto(diferenciaSetInverso, nDiferenciaInverso, "Diferencia de B-A");

    // Diferencia simétrica
    diferenciaSimetrica(conjuntoA, nA, conjuntoB, nB, diferenciaSimetricaSet, nDiferenciaSimetrica);
    imprimirConjunto(diferenciaSimetricaSet, nDiferenciaSimetrica, "Diferencia simetrica");

    return 0;
}
