#include<iostream>
#include "pila.h"
using namespace std;

int main(){
    short option,command;
    int whole;
    Pila *Stack_Controller=new Pila();
    cout<<"<->welcome to the Stack<->\n";
    cout<<"Insert number of Steps:\n\n";
    cin>>option;
    for(int i=0;i<option;i++){
        cout<<"Insert command: ";cin>>command;
        switch(command){
            case 1:
                cout<<"Write the int number:";cin>>whole;
                Stack_Controller->Push(whole);
                break;
            case 2:
                cout<<"Removing int the last node: \n";
                Stack_Controller->Pop();
                break;
            case 3:
                Stack_Controller->mostrarDatos();
                break;
        }
    }
    delete Stack_Controller;
    return 0;
}