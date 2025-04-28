
#include <iostream>
using namespace std;

class Nodo{
private:
    int valor;  // Dato almacenado en el nodo
    Nodo *siguiente;  // Apuntador al siguiente nodo
public:
    Nodo(int v){
        valor = v;
        siguiente = nullptr;
    }
    Nodo *obtenerSiguiente(){
        return siguiente;
    }
    int obtenerValor(){
        return valor;
    }
    void enlazarCon(Nodo *n){
        siguiente = n;
    }
};



class Cola {
private:
    Nodo *frente;  // Primer nodo de la cola
    Nodo *final;   // Último nodo de la cola
public:
    Cola() {
        frente = final = nullptr;
    }
    // Inserta un valor al final de la cola
    void agregarFinal(int valor) {
        Nodo *nuevo = new Nodo(valor);
        if (final == nullptr){
            frente = final = nuevo;
        } else {
            final->enlazarCon(nuevo);
            final = nuevo;
        }
    }
    // Elimina el valor del frente de la cola
    void eliminarFrente() {
        if (frente != nullptr){
            Nodo *temp = frente;
            frente = temp->obtenerSiguiente();
            delete temp;
            if (frente == nullptr){
                final = nullptr;
            }
        }
    }
    // Muestra todos los valores en la cola
    void mostrarValores(){
        Nodo *temp = frente;
        while(temp != nullptr){
            cout << temp->obtenerValor() << endl;
            temp = temp->obtenerSiguiente();
        }
    }
    // Inserta un valor al frente de la cola
    void agregarFrente(int valor) {
        Nodo *nuevo = new Nodo(valor);
        if (frente == nullptr) {
            frente = final = nuevo;
        } else {
            nuevo->enlazarCon(frente);
            frente = nuevo;
        }
    }
    // Elimina el valor del final de la cola
    void eliminarFinal() {
        if (frente != nullptr) {
            if (frente == final) {
                delete frente;
                frente = final = nullptr;
            } else {
                Nodo *temp = frente;
                while (temp->obtenerSiguiente() != final) {
                    temp = temp->obtenerSiguiente();
                }
                delete final;
                final = temp;
                final->enlazarCon(nullptr);
            }
        }
    }
    // Devuelve el valor en una posición específica
    int obtenerValorPorPosicion(int posicion){
        Nodo *temp = frente;
        int contador = 1;
        while(temp != nullptr && contador < posicion){
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        if(temp != nullptr){
            return temp->obtenerValor();
        }
    }
    // Devuelve la posición de un valor específico
    int obtenerPosicionPorValor(int valor){
        Nodo *temp = frente;
        int contador = 1;
        while(temp != nullptr && valor != temp->obtenerValor()){
            temp = temp->obtenerSiguiente();
            ++contador;
        }
        if(temp != nullptr){
            return contador;
        }
    }
};



int main() {
    short opcion,comando;
    int numero;

    Cola *gestorCola = new Cola();
    int totalIDs = 1, totalPruebas, contadorPruebas = 0, totalOperaciones, contadorOperaciones = 0;
    cin >> totalPruebas;
    cin >> totalOperaciones;
    string caso;
    do {
        do {
            cin >> caso;
            switch(caso[0]) {
                case '1':
                    if (caso[1] == 'F') {
                        gestorCola->agregarFrente(caso[2] - '0');
                    }
                    if (caso[1] == 'B') {
                        gestorCola->agregarFinal(caso[2] - '0');
                    }
                    break;
                case '2':
                    if (caso[1] == 'F') {
                        gestorCola->eliminarFrente();
                    }
                    if (caso[1] == 'B') {
                        gestorCola->eliminarFinal();
                    }
                    break;
                case '3':
                    // Devuelve el valor en una posición dada
                    if (caso[1] == 'D') {
                        cout << endl << gestorCola->obtenerValorPorPosicion(caso[2] - '0');
                    }
                    // Devuelve la posición de un valor dado
                    if (caso[1] == 'P') {
                        cout << endl << gestorCola->obtenerPosicionPorValor(caso[2] - '0');
                    }
                    break;
                default:
                    break;
            }
            contadorOperaciones++;
        } while (contadorOperaciones < totalOperaciones);
        contadorPruebas++;
    } while (contadorPruebas < totalPruebas);

    return 0;
}
