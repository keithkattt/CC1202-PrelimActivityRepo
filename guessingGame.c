// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Generates random num from 1 - 100
int randomNum();


int main(){
    //call randomNum function
    randomNum();

    return 0;
}

int randomNum(){
    //Lower Boundary    
    int lowerBoundary = 1;
    //Upper Boundary
    int upperBoundary = 100;

    //random seed and time based on current line
    srand(time(NULL));

    //loop random generated number up to 5 times
    for (int i = 1; i <=5; i++){
        printf("%d\n", rand() % (upperBoundary - lowerBoundary + 1));
    }
}


