using namespace std;

#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#define MAXIMO 5
class PilaEst{
    private:
        int pi[MAXIMO];
        int ind;
    public:
        PilaEst(){
            ind=0;
        }
        void Insertar(int v){
            if(ind < MAXIMO){
                pi[ind] = v;
                ind++;
            }
        }
        void Extraer(){
            if(ind>0)
                ind--;
        }
        int retDato(int i){
            return pi[i];
        }
};



int main()
{
    Pila *pi;
    pi = new Pila();

    pi->Push(3);
    pi->Push(5);
    pi->Push(8);
    pi->Push(7);
    pi->Pop();
    pi->Pop();

    pi->mostrarDatos();
    cout<<endl;
    cout<<pi->Size();

    delete pi;
    return 0;
}
/*
PilaEst pi;
    pi.Insertar(3);
    pi.Insertar(8);
    pi.Extraer();
    pi.Extraer();
    pi.Extraer();

    for(int i=MAXIMO-1;i>=0;i--){
        cout<<pi.retDato(i)<<endl;
    }
*/
