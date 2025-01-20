// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Generates random num from 1 - 100, parameter for how many times you use it
int randomNum();

//Prompts the user and returns the value 
int userInput();

int main(){
    
    int userGuess = userInput();
    int computerNum = randomNum(0);

    printf("%d", computerNum);


    return 0;
}


int randomNum(){
    //Lower Boundary    
    int lowerBoundary = 1;
    //Upper Boundary
    int upperBoundary = 100;

    //random seed and time based on current line
    srand(time(NULL));

    return (rand() % (upperBoundary - lowerBoundary + 1) + lowerBoundary);
}

int userInput(){
    int numInput;
    printf("What is your guess?: ");
    scanf("%d", &numInput);
    return numInput;
}
