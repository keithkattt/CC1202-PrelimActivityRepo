// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Generates random num from 1 - 100, parameter for how many times you use it
int randomNum();


int main(){


    return 0;
}

int randomNum(int n){
    //Lower Boundary    
    int lowerBoundary = 1;
    //Upper Boundary
    int upperBoundary = 100;

    int rounds, num = 1;

    //random seed and time based on current line
    srand(time(NULL));

    for(rounds = 1; rounds <= n; rounds++){
        num = (rand() % (upperBoundary - lowerBoundary + 1));
    }
    
    return num;
}


