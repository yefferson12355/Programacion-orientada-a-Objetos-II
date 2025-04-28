#include <iostream>
#include "cola.h"
using namespace std;

int main() {
    short option,command;
    int whole;
    Cola *Stack_Controller=new Cola();
    cout<<"<->welcome to the Cola<->\n";
    cout<<"Insert number of Steps:\n\n";
    cin>>option;
    for(int i=0;i<option;i++){
        cout<<"Insert command: ";cin>>command;
        switch(command){
            case 1:
                cout<<"Write the int number:";cin>>whole;
                Stack_Controller->Insertar(whole);
                break;
            case 2:
                cout<<"Removing int the last node: \n";
                Stack_Controller->Eliminar();
                break;
            case 3:
                Stack_Controller->MostrarDatos();
                break;
        }
    }
    delete Stack_Controller;

    return 0;
}
