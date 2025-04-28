#include<iostream>

using namespace std;

class Pila
{
private:
    //la variable debe de ser de tipo no do
    //int cima;
    Nodo* cima;
public:
    Pila();

    //crear un nodo
    void Push(int v){
        Nodo* n= new Nodo(v);
        //n va ser el nodito.
        //Tienes que apuntar, a otro, poner una condicion, en todos los casos cima es igual a null cuadno esta vacio.
        if (cima !=null)
        {
            /* code */
        }else{
            Nodo* n= new Nodo(v);
            n->unircon
        
        }

        
        cima = n;
    }
    void push(int v){
        Nodo* n= new Nodo(v);
    }

    //metodo delete

    void pop(){
        Nodo* temp=cima;
        cima=temp ->retSig();
        delete temp;
 
    }
 
};

Pila::Pila()
{
}



int  main(){
    Pila *pi;
    pi = new Pila();
    pi-> Push(5);
    delete pi;
  
    return 0;
}
