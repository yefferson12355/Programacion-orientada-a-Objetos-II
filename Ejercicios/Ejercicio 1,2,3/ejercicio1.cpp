
#include <iostream>
using namespace std;

class Nodo{
private:
    int dato;
    Nodo *sig;
public:
    Nodo(int v){
        dato = v;
        sig = nullptr;
    }
    Nodo *retSig(){
        return sig;
    }
    int retDato(){
        return dato;
    }
    void unirCon(Nodo *n){
        sig = n;
    }
};







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
