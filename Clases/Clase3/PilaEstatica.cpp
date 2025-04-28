#include<iostream>

using namespace std;



class PilaESt
{
private:
    int  pi[MAXIMO];
    int ind;
public:
    PilaESt(){
        ind = 0;
    }

    void Insertar(int v){
        if (ind < MAXIMO)
        {
            pi[ind] =  v;
        }
        
        
        
    }
//el indice deve disminuir 
    void Extraer(){
        //contralar
        if (ind>0)
        {
            ind--;
        }
    }

    int retDato(int i){

        return pi[i];
    }
};

PilaESt::PilaESt(/* args */)
{
}

PilaESt::~PilaESt()
{
}


int  main(){

    //como es estatico no necesita incrementar
    for (int  i = 0; i <MAXIMO;i++)
    {
        cout<<pi.retDato(i)<<endl;
    }
    
    return p;
}
