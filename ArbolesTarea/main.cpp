#include <iostream>
#include "Arbol.h"
#include <stdio.h>

using namespace std;

int main()
{
    Arbol<int> *ar = new Arbol<int>();

    //Insert Recursivamente
    ar->InsertarIte(15);

    //Insertar iterativamente
    ar->Insertar(5);
    ar->Insertar(23);
    ar->Insertar(31);
    ar->Insertar(37);
    ar->Insertar(27);
    ar->Insertar(14);
    ar->Insertar(7);

    cout<<"Metodo Inorden : ";ar->inOrden();
    cout<<endl;
    cout<<"Metodo Postorden : ";ar->postOrden();
    cout<<endl;
    cout<<"Metodo Inorden Iterativo : ";ar->iterativeInorden();
    cout<<endl;
    cout<<"Metodo Postorden Iterativo : ";ar->iterativePostorder();
    cout<<endl;
    cout<<"Metodo PreOrde Iterativo : ";ar->iterativePreorder();
    cout<<endl;
    cout<<"La cantidad de Nodos es : "<<ar->cantNodos();
    cout<<endl;
    cout<<"La Altura es : "<<ar->altura();
    cout<<endl;
    cout<<"Imprimar por Niveles :";ar->imprimirPorNiveles();
    return 0;

}
