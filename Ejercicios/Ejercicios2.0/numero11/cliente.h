#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
public:
    Cliente():id(0),nombre(""){} //Constructor predeterminado
    Cliente(int id_, string nombre_):id(id_), nombre(nombre_){}
    int getId(){
        return id;
    }
    string getNombre(){
        return nombre;
    }
    void setId(int id_){
        id=id_;
    }
    void setNombre(string nombre_){
        nombre=nombre_;
    }
};

#endif

