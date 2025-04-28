#include <iostream>
#include <string>

using namespace std;

int main() {
    string diamante = "";
    int aperturas = 0; // Contador para el número de '<' encontrados
    int total = 0;     // Contador para el número de diamantes encontrados

    cout << "Ingrese la cadena de diamantes: ";
    cin >> diamante;

    // Recorremos cada carácter en la cadena
    for (char encontrado : diamante) {
        if (encontrado == '<') {
            // Si encontramos una apertura, incrementamos el contador de aperturas
            aperturas++;
        } else if (encontrado == '>') {
            // Si encontramos un cierre, verificamos si hay aperturas disponibles
            if (aperturas > 0) {
                total++;    // Contamos un diamante
                aperturas--; // Reducimos el contador de aperturas disponibles
            }
        }
    }

    cout << "Diamantes encontrados: " << total << endl;

    return 0;
}
