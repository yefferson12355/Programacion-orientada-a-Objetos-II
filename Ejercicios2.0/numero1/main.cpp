#include <iostream>
#include "Pila.h"

using namespace std;
int main() {
    Pila* pila=new Pila();
    char op1,op2,oper,prefijo[3];

    cout<<"Ingrese Notacion infija: ";
    char a,b,operador;
    cin>>a>>operador>>b;

    pila->Push(b);
    pila->Push(a);

    op1 = pila->Top();
    pila->Pop();

    op2 = pila->Top();
    pila->Pop();

    oper=operador;

    prefijo[0] = oper;
    prefijo[1] = op2;
    prefijo[2] = op1;

    cout<<"La expresion en notacion prefija es: ";
    for(int i=0;i<3;i++){
        cout<<prefijo[i];
    }
    cout<<endl;
    delete pila;
    return 0;
}
