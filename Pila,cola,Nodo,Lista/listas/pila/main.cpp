using namespace std;

#include <iostream>
#include "Nodo.h"
#include "Pila.h"

#include "Lista.h"

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

// PLANTILLAS ---> OBJETOS GENERICOS



int main()
{
  Lista<int> *lis;
  lis = new Lista<int>();

  lis->insertInicio(45);
  lis->insertInicio(30);
  lis->insertInicio(27);
  lis->insertFinal(74);
  lis->insertFinal(17);

  //lis->mostrarDatos();

  lis->eliminarUltimo();

  lis->mostrarDatos();
  /*
    Pila<int> *pi;
    pi = new Pila<int>();

    pi->Push(23);
    pi->Push(56);
    pi->Push(12);
    pi->Push(78);
    pi->Pop();
    pi->Pop();

    pi->mostrarDatos();
    cout<<endl;
    cout<<pi->Size();

    delete pi;
*/
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
