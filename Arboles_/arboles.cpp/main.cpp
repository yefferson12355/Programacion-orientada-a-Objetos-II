#include <iostream>
#include <stdio.h>
#include "Nodo.h"
#include "Pila.h"
#include "Lista.h"
#include "Arbol.h"
using namespace std;

int main() {
    Arbol<int>* ar = new Arbol<int>();

    ar->Insertar(23);
    ar->Insertar(14);
    ar->Insertar(7);
    ar->Insertar(5);
    ar->Insertar(31);
    ar->Insertar(37);
    ar->Insertar(27);

    /*ar->InsertarIterativo(23);
    ar->InsertarIterativo(14);
    ar->InsertarIterativo(7);
    ar->InsertarIterativo(5);
    ar->InsertarIterativo(31);
    ar->InsertarIterativo(37);
    ar->InsertarIterativo(27);
    */
    cout << "InOrden: ";
    ar->inOrden();
    cout << endl;

    cout << "PostOrden: ";
    ar->postOrden();
    cout << endl;

    cout << "PreOrden: ";
    ar->preOrden();
    cout << endl;
    
    cout << "itepreOrden: ";
    ar->iterativePreorder();
    cout << endl;

    cout << "itepostOrden: ";
    ar->iterativePostorder();
    cout << endl;

    cout << "iteinOrden: ";
    ar->iterativeInorder();
    cout << endl;
    
    cout << "Numero de hojas: ";
    cout << ar->contarHojas(); 
    cout << endl;
    
    
cout << "Altura: ";
    cout << ar->altura();
    cout << endl;
    
    system("pause");
    

    return 0;
}