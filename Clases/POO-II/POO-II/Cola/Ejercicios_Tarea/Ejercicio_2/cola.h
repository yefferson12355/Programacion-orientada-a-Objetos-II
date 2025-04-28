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
    //nuevo metodo
    int Devolver_Tiempo(int pos){
        Nodo *temp = pri;
        int contador = 0;
        while(temp != nullptr && contador<pos){
            temp = temp->retSig();
            ++contador;
        }
        if(temp != nullptr){
            return temp->retDato();
        }
    }
    Nodo *Devolver_Direc(int pos){
        Nodo *temp = pri;
        int contador = 0;
        while(temp != nullptr && contador<pos){
            temp = temp->retSig();
            ++contador;
        }
        if(temp != nullptr){
            return temp;
        }
    }
    void Cambio_Tiempo(int original,int valor){
        int temp;
        Nodo *Modificador=Devolver_Direc(valor);
        Nodo *Modificado=Devolver_Direc(original);
        temp=Modificado->retDato();
        Modificado->Seter(Modificador->retDato());
        Modificador->Seter(temp);
    }
};

#endif
