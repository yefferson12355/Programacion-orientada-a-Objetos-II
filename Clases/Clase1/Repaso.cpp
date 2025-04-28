#include<iostream>

using namespace std;


//funcion  para imprimir un nombre 
void Minombre (int cantidad,string nombre ){

    for (int  i = 0; i < cantidad; i++)
    {
        cout<<nombre;
    }
    

}

int main(){


    //funcion normal de for 
    for (int i =0 ; i < 5 ; i++)
    {
        cout<<"Hola mundo1"<<endl;

    };
    //Igualdad de bucles

    int i=0;
    while (i<5)
    {
        cout<<"Hola mundo2"<<endl;
        i++;
    }
    //funcion de for vacia, Infinita;
    for ( ; ; )
    {
        /* code */
    }
    //funcion de while vacia, Infinita;
    while (true)
    {
        /* code */
    }
    //Bucle de ambas vacias,con salida
    //while
    while (100)//solo 0 es false
    {
        if (0)
        {
            break;
        }
        
    }
    //for
    for ( ; -1;)
    {
        if (0)
        {
            /* code */
        }
        
    }

    Minombre(7,"Yefferson");
    
    
    
    


    return 0;
}