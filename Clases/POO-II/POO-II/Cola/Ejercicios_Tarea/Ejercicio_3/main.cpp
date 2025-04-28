#include <iostream>
#include "cola.h"
using namespace std;

int main(){
    Cola *Stack_Controller=new Cola();

    int n;cin>>n;
    int k;cin>>k;
    int numero;
    for(int i=1;i<n;i++){
        cin>>numero;
        Stack_Controller->Insertar(numero);
    }
    Nodo *pri=Stack_Controller->Getter(1);
    Nodo *ult=Stack_Controller->Getter(2);
    pri->unirCon(ult);

    Nodo *actual=pri;
    Nodo *anterior=ult;

    while(actual!=actual->retSig()){
        for(int i=1;i<k;++i) {
            anterior = actual;
            actual = actual->retSig();
        }

        anterior->unirCon(actual->retSig());
        delete actual;
        actual = anterior->retSig();
    }

    cout<<"El último: "<< actual->retDato()<< endl;
    delete actual;
    return 0;
}

