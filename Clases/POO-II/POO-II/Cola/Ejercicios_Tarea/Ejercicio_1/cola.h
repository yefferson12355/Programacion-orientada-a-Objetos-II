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
            pri = temp->retSig();
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
    void InsertarFrente(int n) {
        Nodo *a = new Nodo(n);
        if (pri == nullptr) {
            pri = ult = a;
        } else {
            a->unirCon(pri);
            pri = a;
        }
    }
    //nuevo metodo
    void EliminarAtras() {
        if (pri != nullptr) {
            if (pri == ult) {
                delete pri;
                pri = ult = nullptr;
            } else {
                Nodo *temp = pri;
                while (temp->retSig() != ult) {
                    temp = temp->retSig();
                }
                delete ult;
                ult = temp;
                ult->unirCon(nullptr);
            }
        }
    }
    //nuevo metodo
    int Devolver_ID(int pos){
        Nodo *temp = pri;
        int contador = 1;
        while(temp != nullptr && contador<pos){
            temp = temp->retSig();
            ++contador;
        }
        if(temp != nullptr){
            return temp->retDato();
        }
    }
    //nuevo metodo
    int Devolver_Position(int ID){
        Nodo *temp = pri;
        int contador = 1;
        while(temp != nullptr && ID!=temp->retDato()){
            temp = temp->retSig();
            ++contador;
        }
        if(temp != nullptr){
            return contador;
        }
    }
};

#endif