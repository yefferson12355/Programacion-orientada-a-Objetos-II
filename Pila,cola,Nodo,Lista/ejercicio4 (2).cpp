
#include "pila.h"

int main(){
    Pila *pila=new Pila();

    pila->Push(623);
    pila->Push(1024);
    pila->Push(3209);
    pila->Push(928);

    cout<<"Pila original:"<<endl;
    pila->mostrarDatos();

    Nodo* anterior=nullptr;
    Nodo* actual=pila->retornarCima();
    Nodo* siguiente=nullptr;

    while (actual != nullptr) {
        siguiente = actual->retSig();  
        actual->unirCon(anterior; 
        anterior = actual;              
        actual = siguiente;             
    }
    pila->setCima(anterior);

    cout<<"Pila invertida:"<<endl;
    pila->mostrarDatos();

    return 0;
}
