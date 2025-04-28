
#include <stdio.h>
#include <iostream>

void xyz(int y){


    if(y<10){
        xyz(y+1);
    }
}

int main(){

    std::cout <<xyz(5);
    

    return 0;
}
