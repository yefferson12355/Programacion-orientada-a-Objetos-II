#include <iostream>
using namespace std;

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedencia(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void invertir(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

string infijaAPrefija(string expresion) {
    string resultado;
    char pila[100];
    int top = -1;  

    invertir(expresion);

    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];

        if (isalpha(c)) {
            resultado += c;
        }
        
        else if (esOperador(c)) {
            while (top != -1 && precedencia(pila[top]) >= precedencia(c)) {
                resultado += pila[top];
                top--;
            }
            top++;
            pila[top] = c;
        }
    }

    while (top != -1) {
        resultado += pila[top];
        top--;
    }

    invertir(resultado);

    return resultado;
}

int main() {
    string expresion;
    cin >> expresion;
    string resultado = infijaAPrefija(expresion);
    return 0;
}
