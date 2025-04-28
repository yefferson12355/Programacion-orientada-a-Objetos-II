#include<iostream>

using namespace std;

class vehiculo
{
private:
    int placa;
    int numeroDePuerta;

    /* data */
public:

    vehiculo();//Constructor
    ~vehiculo();//destructor

    void avanzar();
    
};

void vehiculo::avanzar(){

}

vehiculo::vehiculo(/* args */)
{
}

vehiculo::~vehiculo()
{
}
//Como se retorna un Objeto.
vehiculo Mifuncion (int x){
    vehiculo y;
    return y;
}

//Almacenar objetos en arrays


int main(){

    vehiculo ve;
    ve = Mifuncion(5);
    


    return 0;
}