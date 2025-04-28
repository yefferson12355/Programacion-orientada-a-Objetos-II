//RESOLUCION DE LA PRATICA NUMERO 1.

#include <iostream>
#include <fstream>
using namespace std;
//Implementacion de Nodo con Template
template <class T>
class Nodo{
private:
    T dato;
    Nodo<T> *sig;
public:
    Nodo(T v){
        dato = v;
        sig = NULL;
    }

    Nodo(){}

    Nodo<T> *retSig(){
        return sig;
    }
    T retDato(){
        return dato;
    }
    void unirCon(Nodo<T> *n){
        sig = n;
    }
};


//Implementacion de Pila con Template
template <class T>
class Pila{
private:
    Nodo<T> *cima;

public:

    Pila(){
        cima = NULL;
    }

    void Push(T v){
        Nodo<T> *n = new Nodo<T>(v);
        /*
        if(cima == NULL){
            cima = n;
        }else{
            n->unirCon(cima);
            cima = n;
        }
        */
        n->unirCon(cima);
        cima = n;
    }
    void Pop(){
        if(cima != NULL){
            Nodo<T> *temp = cima;
            cima = temp->retSig();
            delete temp;
        }
    }
    void mostrarDatos(){
        Nodo<T> *temp = cima;
        while(temp != NULL){
            cout<<temp->retDato()<<endl;
            temp = temp->retSig();
        }
    }
    int Size(){
        Nodo<T> *temp = cima;
        int i=0;
        while(temp != NULL){
            i++;
            temp = temp->retSig();
        }
        return i;
    }
};

int main()
{

    ifstream arch("entrada.txt");
    int cant, num1, num2;
    string linea;
    //! leyendo la primera linea
    arch>>cant;
    //! procesando, cualquier de sig linea es igual
    //while(!arch.eof()){
    //while(getline(arch, linea)){

    while(cant>=0){
        cant--;
        arch>>num1;
        arch>>num2;

        cout<<num1<<" - "<<num2<<endl;

        //! lee toda la linea y almacena en variable "linea"
        //getline(arch, linea);
        //cout<<linea<<endl;

    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{

    ifstream arch("entrada.txt");
    int cant, num1, num2;
    string linea;
    //! leyendo la primera linea
    arch>>cant;
    //! procesando, cualquier de sig linea es igual
    //while(!arch.eof()){
    //while(getline(arch, linea)){

    while(cant>=0){
        cant--;
        //!arch>>num1;       arch>>num2;
        //!cout<<num1<<" - "<<num2<<endl;

        //! lee toda la linea y almacena en variable "linea"
        getline(arch, linea);

        //! lee la linea y la divide en palabras
        istringstream ss(linea);
        string palab1;
        while(ss>>palab1){
            cout<<palab1<<" - ";
        }
        cout<<endl;
        //cout<<linea<<endl;

    }
    return 0;
}
int main()
{
    Pila<int> *p = new Pila<int>();
    ifstream arch("entrada.txt");
    int cant, num;
    string linea;
    //! leyendo la primera linea
    arch>>cant;
    //! procesando, cualquier de sig linea es igual
    //while(!arch.eof()){
    //while(getline(arch, linea)){
    while(cant>=0){
        cant--;
        //! lee toda la linea y almacena en variable "linea"
        getline(arch, linea);
        //! lee la linea y la divide en palabras
        istringstream ss(linea);
        //! 'palab1' donde se almacenara cada palabra de la linea
        string palab1;
        int valor;
        while(ss >> palab1){
            if(palab1 == "PUSH"){
                //! alamacena en valor el numero
                ss >> valor;
                //!cout<<palab1<<" "<<valor<<endl;
                p->insertar(valor);
            }else if(!p->esVacio() && palab1=="POP")
                p->eliminar();
            else if(!p->esVacio() && palab1=="MIN")
                cout<<p->MenorValor()<<endl;
            else
                cout<<"Empty"<<endl;
        }
    }


    return 0;
}