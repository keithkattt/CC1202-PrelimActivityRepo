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
void SetColorAndBackground(int ForgC, int BackC); ////color value range 0 up-to 256
void ResetColor(); //Resets the color and background
void gameRound(); //Loop 10 times, if the user guess is wrong, prompt the user to guess again, if the user guess is correct, break the loop

int main(){

    
    SetColorAndBackground(6, 0);
    guessingGameHeader();
    ResetColor();
    welcomeMessage();

    int computerNum = randomNum();
    int userGuess;
    
    gameRound(userGuess, computerNum);
    
   

    return 0;
}

void gameRound(int inputGuess, int compNum){
   for(int i = 1; i <= 11; i++){
        if (i == 11){
            SetColorAndBackground(12, 0);
            const char *gameOver ={"You have guessed 10 times: GAME OVER!!!\n"};
            print_in_style(gameOver, 10);
            ResetColor();
            break;
        }
        inputGuess = userInput();

        if(inputGuess == compNum){
            SetColorAndBackground(6, 0);
            const char *congrats = {"Congratulations! You guessed the number correctly!\n"};
            print_in_style(congrats, 10);
            ResetColor();
            break;
        }else if(inputGuess < 1 || inputGuess > 100){
            SetColorAndBackground(4, 0);
            const char *wrongInput={"Please enter a number between 1 and 100\n"};
            print_in_style(wrongInput, 10);
            ResetColor();
            i--;
        }else if(inputGuess < compNum){
            char higher[100]; 
            snprintf(higher, sizeof(higher),"The number is higher than %d\n", inputGuess);
            print_in_style(higher, 10);
        }else if(inputGuess > compNum){
            char lower[100]; 
            snprintf(lower, sizeof(lower),"The number is lower than %d\n", inputGuess);
            print_in_style(lower, 10);
        }else{
            printf("Invalid input\n");
        }
    }   
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
    print_in_style(userInput, 20);
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
        "You have 10 tries to guess the number.",
    };        

    for(int i = 0; i < 4; i++){
        print_in_style(welcome[i], 20);
        printf("\n");
    }

}
    
void print_in_style(const char *str, int delay){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(delay);
    }
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void ResetColor(){
    SetColorAndBackground(7, 0);
}