#include <iostream>
#include "cola.h"
using namespace std;

int main() {
    short option,command;
    int whole;

    Cola *Stack_Controller=new Cola();
    int IDs=1,n_tests,count=0,n_operations,count2=0;
    cin>>n_tests;
    cin>>n_operations;
    string tipo_caso;
    do{
        do{
            cin>>tipo_caso;
            switch(tipo_caso[0]){
                case '1':
                    if(tipo_caso[1]=='F'){
                        Stack_Controller->InsertarFrente(tipo_caso[2]- '0');
                    }
                    if(tipo_caso[1]=='B'){
                        Stack_Controller->Insertar(tipo_caso[2]- '0');
                    }
                    break;
                case '2':
                    if(tipo_caso[1]=='F'){
                        Stack_Controller->Eliminar();
                    }
                    if(tipo_caso[1]=='B'){
                        Stack_Controller->EliminarAtras();
                    }
                    break;
                case '3':
                    //mandas position y devuelve ID
                    if(tipo_caso[1]=='D'){
                        cout<<endl<<Stack_Controller->Devolver_ID(tipo_caso[2]- '0');
                    }
                    //mandas el ID y te devuelve la position
                    if(tipo_caso[1]=='P'){
                        cout<<endl<<Stack_Controller->Devolver_Position(tipo_caso[2]- '0');
                    }
                    break;
                default:
                    break;
            }
            count2++;
        }while(count2<n_operations);
        count++;
    }while(count<n_tests);


    return 0;
}
