#include<iostream>

using namespace std;
//Funcion Suma
int Suma(int a,int b){
    int Respuesta;
    Respuesta=a+b;    
    return Respuesta;
}

//Funcion para que no retorne nada, suma , sin cout sin cin, 
int main(){

    cout<<Suma(5,4);

    return 0;
}