#include<iostream>

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
//Clase pila
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
            cima = temp->retSig();
            delete temp;
        }
    }
    int Top() {
        if (cima != NULL) {
            return cima->retDato();
        } else {
            cout << "Error: La pila está vacía." << endl;
            return -1;
        }
    }

    // Muestra todos los datos de la pila desde la cima hasta el fondo
    void mostrarDatos() {
        // Verifica si la pila está vacía
        if (cima == NULL) {
            cout << "Empty" << endl;
            return; // Salir de la función si la pila está vacía
        }

        Nodo* temp = cima;
        // Recorre la pila e imprime los datos
        while (temp != NULL) {
            cout << temp->retDato() << " ";
            temp = temp->retSig();
        }
        cout << endl;
    }


    // Retorna el tamaño de la pila (cantidad de nodos)
    int Size() {
        Nodo *temp = cima;
        int i = 0;
        while (temp != NULL) {
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};

int main () {
    //inicializamos
    Pila *pi = new Pila();

    // Numero de Instrucciones a realizar
    int T;
    cin>>T;
    for (int i=0;i<T;i++) {
        //que instruccion realizara
        int p;
        cin>>p;
        if (p==1) {
            //Numero
            int n;
            cin>>n;pi->Push(n);
        }else if(p==2) {
            pi->Pop();
        }else if (p==3) {
            cout<<pi->Top()<<endl;
            pi->mostrarDatos();

        }
    }



    delete pi;  // Libera la memoria asignada a la pila

    return 0;
}
