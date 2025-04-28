#include <iostream>

#include "Arbol.h"

using namespace std;
int main()
{
    Arbol<int> *ar =new Arbol<int>();
    ar->insertar(5);
    ar->insertar(5);
    ar->insertar(29);
    ar->insertar(5);

    return 0;
}
