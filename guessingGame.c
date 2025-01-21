// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int randomNum();//Generates random num from 1 - 100, parameter for how many times you use it 
int userInput(); //Prompts the user and returns the value
void guessingGameHeader(); //Prints ASCII art
void welcomeMessage(); //Prints welcome message
void print_in_style(const char *str, int delay); //Prints in style

int main(){

    guessingGameHeader();
    welcomeMessage();

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
    const char *userInput = {"What is your guess?: "};
    print_in_style(userInput, 50);
    scanf("%d", &numInput);
    return numInput;
}

void guessingGameHeader(){
    printf(" $$$$$$\\                                          $$\\                            $$$$$$\\                                    \n");
    printf("$$  __$$\\                                         \\__|                          $$  __$$\\                                   \n");
    Sleep(500);
    printf("$$ /  \\__|$$\\   $$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  \n");
    printf("$$ |$$$$\\ $$ |  $$ |$$  __$$\\ $$  _____|$$  _____|$$ |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ \n");
    Sleep(500);
    printf("$$ |\\_$$ |$$ |  $$ |$$$$$$$$ |\\$$$$$$\\  \\$$$$$$\\  $$ |$$ |  $$ |$$ /  $$ |      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n");
    printf("$$ |  $$ |$$ |  $$ |$$   ____| \\____$$\\  \\____$$\\ $$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n");
    Sleep(500);
    printf("\\$$$$$$  |\\$$$$$$  |\\$$$$$$$\\ $$$$$$$  |$$$$$$$  |$$ |$$ |  $$ |\\$$$$$$$ |      \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ \n");
    printf(" \\______/  \\______/  \\_______|\\_______/ \\_______/ \\__|\\__|  \\__| \\____$$ |       \\______/  \\_______|\\__| \\__| \\__| \\_______|\n");
    Sleep(500);
    printf("                                                                $$\\   $$ |                                                  \n");
    printf("                                                                \\$$$$$$  |                                                  \n");
    printf("                                                                 \\______/                                                   \n");
}

void welcomeMessage(){
    const char *welcome[] = {
        "Welcome to the guessing game!",
        "The computer will generate a random number between 1 and 100.",
        "You will have to guess the number.",
        "You have 10 treis to guess the number.",
    };        

    for(int i = 0; i < 4; i++){
        print_in_style(welcome[i], 50);
        printf("\n");
    }

}
    
void print_in_style(const char *str, int delay){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(delay);
    }
}