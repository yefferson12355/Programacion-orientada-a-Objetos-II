#include <iostream>
#include <string>
#include "cola.h"
using namespace std;

int main(){
    Cola *Stack_Controller=new Cola();
    int total;cin>>total;
    int tiempo;
    for(int i=0;i<total;i++){
        cin>>tiempo;
        Stack_Controller->Insertar(tiempo);
    }
    //Ordenamiento: Selection Sort
    for(int i=0;i<total-1;i++) {
        int mintiempo=i;
        for(int j=i+1;j<total;j++){
            if(Stack_Controller->Devolver_Tiempo(j) < Stack_Controller->Devolver_Tiempo(mintiempo)){
                mintiempo=j;
            }
        }
        Stack_Controller->Cambio_Tiempo(i,mintiempo); //<-
    }
    Stack_Controller->MostrarDatos();
    cout<<endl;
    int satisfechos = 0;
    int totalTime = 0;
    for(int i=0;i<total;i++) {
        Nodo *temp=Stack_Controller->Devolver_Direc(i);
        tiempo=temp->retDato();
        if(totalTime<=tiempo){
            satisfechos++;
        }
        totalTime+=tiempo;
    }
    cout<<endl<<satisfechos;
}
