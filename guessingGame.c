// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int randomNum();//Generates random num from 1 - 100, parameter for how many times you use it 
int userInput(); //Prompts the user and returns the value
void guessingGameHeader(); //Prints ASCII art

int main(){

    guessingGameHeader();
    printf("Welcome to the guessing game!\n");
    printf("I have a number between 1 and 100, can you guess it?\n");
   

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

void guessingGameHeader(){
    printf(" $$$$$$\\                                          $$\\                            $$$$$$\\                                    \n");
    Sleep(500);
    printf("$$  __$$\\                                         \\__|                          $$  __$$\\                                   \n");
    Sleep(500);
    printf("$$ /  \\__|$$\\   $$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  \n");
    Sleep(500);
    printf("$$ |$$$$\\ $$ |  $$ |$$  __$$\\ $$  _____|$$  _____|$$ |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ \n");
    Sleep(500);
    printf("$$ |\\_$$ |$$ |  $$ |$$$$$$$$ |\\$$$$$$\\  \\$$$$$$\\  $$ |$$ |  $$ |$$ /  $$ |      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n");
    Sleep(500);
    printf("$$ |  $$ |$$ |  $$ |$$   ____| \\____$$\\  \\____$$\\ $$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n");
    Sleep(500);
    printf("\\$$$$$$  |\\$$$$$$  |\\$$$$$$$\\ $$$$$$$  |$$$$$$$  |$$ |$$ |  $$ |\\$$$$$$$ |      \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ \n");
    Sleep(500);
    printf(" \\______/  \\______/  \\_______|\\_______/ \\_______/ \\__|\\__|  \\__| \\____$$ |       \\______/  \\_______|\\__| \\__| \\__| \\_______|\n");
    Sleep(500);
    printf("                                                                $$\\   $$ |                                                  \n");
    Sleep(500);
    printf("                                                                \\$$$$$$  |                                                  \n");
    Sleep(500);
    printf("                                                                 \\______/                                                   \n");
}
