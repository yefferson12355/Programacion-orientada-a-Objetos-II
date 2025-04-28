#include<iostream>

using namespace std;

int main(){

    string terreno = "";
    cin >> terreno;

    int left = 0;
    int total = 0;


    for ( char parte: terreno ){
        if ( parte == '<' ){
            left++;

        }
        else if ( parte == '>' && left > 0 ){
            total++;
            left--;

        }



    }

    cout << "Diamantes encontrados = " << total;






    return 0;
}
