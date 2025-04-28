#include<iostream>
#include "Pila.h"
using namespace std;
//Escriba un programa en C++ que, apoyándose en un objeto tipo pila, traduzca una expresión dada en
//notación infija a notación prefija. Por ejemplo, si la expresión dada es a + b
//, su programa debe generar como salida + a b.

int main() {

    Pila* pila = new Pila();  // Creamos una nueva pila dinámica para almacenar los operandos
    char a, b, operador;  // Variables para los operandos (a y b) y el operador (+, -, *, etc.)
    char op1, op2, oper;  // Variables auxiliares para extraer los operandos y el operador
    char prefijo[3];  // Arreglo de 3 posiciones para almacenar la expresión prefija (operador y dos operandos)

    // Solicitar al usuario que ingrese una expresión en notación infija (por ejemplo, a + b)
    cout << "Ingrese Notacion infija: ";
    cin >> a >> operador >> b;  // Leer los operandos y el operador de la entrada del usuario

    // Insertar los operandos en la pila (primero se inserta 'b', luego 'a')
    pila->Push(b);
    pila->Push(a);

    // Extraer los operandos de la pila (LIFO: primero sale 'a', luego 'b')
    op1 = pila->Top();  // Obtener el primer operando (a) de la cima de la pila
    pila->Pop();  // Eliminar el operando 'a' de la pila
    op2 = pila->Top();  // Obtener el segundo operando (b) de la cima de la pila
    pila->Pop();  // Eliminar el operando 'b' de la pila

    oper = operador;  // Asignar el operador ingresado por el usuario a la variable 'oper'

    // Construir la expresión prefija, primero el operador y luego los operandos en orden inverso
    prefijo[0] = oper;  // El operador va primero en la notación prefija
    prefijo[1] = op2;   // Luego va el segundo operando 'b'
    prefijo[2] = op1;   // Finalmente, el primer operando 'a'

    // Mostrar la expresión en notación prefija
    cout << "La expresion en notacion prefija es: ";
    for (int i = 0; i < 3; i++) {  // Recorremos el arreglo prefijo[] e imprimimos cada elemento
        cout << prefijo[i];
    }
    cout << endl;  // Salto de línea para finalizar la salida

    delete pila;  // Liberamos la memoria asignada a la pila dinámica
    return 0;  // Fin del programa
}

