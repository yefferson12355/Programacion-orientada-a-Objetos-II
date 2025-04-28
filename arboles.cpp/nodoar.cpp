#include <iostream>
#include <string>
using namespace std;

class nodo {
private:
    string nom;
    nodo* izq;
    nodo* der;

public:
    nodo(nodo* izq, string nom, nodo* der) {
        this->nom = nom;
        this->izq = izq;
        this->der = der;
    }
};

int main() {
    nodo* sof = new nodo(NULL, "Sofía", NULL);
    nodo* tom = new nodo(NULL, "Tomás", NULL);
    nodo* ped = new nodo(sof, "Pedro", tom);
    nodo* fel = new nodo(NULL, "Felisa", NULL);
    nodo* jos = new nodo(fel, "José", ped);
    nodo* car = new nodo(NULL, "Carlos", NULL);
    nodo* ine = new nodo(NULL, "Inés", NULL);
    nodo* jua = new nodo(ine, "Juana", car);
    nodo* mar = new nodo(jua, "María", jos);

    return 0;
}
