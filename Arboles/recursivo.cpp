#include<iostream>

using namespace std;

void xyz(int y){

    if(y<10){
        xyz(y+1);
    }
}

int main(){

    
    cout<<xyz(5);

    return 0;
}