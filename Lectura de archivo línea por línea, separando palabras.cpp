#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream arch("entrada.txt");
    int cant;
    string linea;

    arch >> cant;

    while(cant >= 0) {
        cant--;
        getline(arch, linea);

        istringstream ss(linea);
        string palab1;
        while(ss >> palab1) {
            cout << palab1 << " - ";
        }
        cout << endl;
    }
    return 0;
}
