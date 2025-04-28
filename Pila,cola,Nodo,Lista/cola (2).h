#ifndef TEST_COLA_H
#define TEST_COLA_H
#include "nodo.h"
using namespace std;

class Cola {
private:
    Nodo *pri;
    Nodo *ult;
public:
    Cola() {
        pri = ult = nullptr;
    }
    Nodo *getPri(){
        return pri;
    }
    void setPri(Nodo *arg){
        pri=arg;
    }
    void setUlt(Nodo *arg){
        ult=arg;
    }

    void Insertar(int n) {
        Nodo *a = new Nodo(n);
        if (ult == nullptr){
            pri = ult = a;
        } else {
            ult->unirCon(a);
            ult = a;
        }
    }
    void Eliminar() {
        if (pri != nullptr){
            Nodo *temp = pri;
            pri = pri->retSig();
            delete temp;
            if (pri == nullptr){
                ult = nullptr;
            }
        }
    }
    void MostrarDatos(){
        Nodo *temp = pri;
        while(temp != nullptr){
            cout<<temp->retDato()<<endl;
            temp = temp->retSig();
        }
    }
};

#endif
