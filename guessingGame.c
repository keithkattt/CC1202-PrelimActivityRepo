// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <unistd.h>

int randomNum();//Generates random num from 1 - 100, parameter for how many times you use it 
int userInput(); //Prompts the user and returns the value
void guessingGameHeader(); //Prints ASCII art
void welcomeMessage(); //Prints welcome message
void print_in_style(const char *str, int delay); //Prints in style
void SetColorAndBackground(int ForgC, int BackC); ////color value range 0 up-to 256
void ResetColor(); //Resets the color and background
void GuessingGamePlay(); //Main function
void PlayAgain(); //Asks the user if they want to play again
void MainGuessingGame(); //Main function

int main(){
    
    SetColorAndBackground(6, 0);
    guessingGameHeader();
    ResetColor();
    welcomeMessage();

    int computerNum = randomNum();
    int userGuess;
    
    GuessingGamePlay(userGuess, computerNum);
    
   

    return 0;
}

void GuessingGamePlay(int uc, int cc) {
    int a = 1; // Attempt counter
    int s = 0; // Score variable
    
    // Game loop: Allow up to 10 attempts
    do {
        // Prompt the user to enter a guess
        char prompt[100];
        snprintf(prompt, sizeof(prompt),"Attempt %d: Enter your guess: ", a);
        print_in_style(prompt, 10);
        scanf("%d", &uc); // Read the user's input

        // Check if the guess is correct
        if (uc == cc) {
            const char *correct = {"Correct! You've guessed the number!\n"};
            print_in_style(correct, 10);

            // Calculate the score based on the number of attempts used
            s = (11 - a) * 10; // Score calculation: higher for fewer attempts
            char calcScore[100];
            snprintf(calcScore, sizeof(calcScore),"Your score: %d/10 = %d%%\n", (11 - a), s);
            print_in_style(calcScore, 10);
            break; // Exit the loop since the guess is correct
        } else {
            // Check if the guess is outside the valid range (1-100)
            if (uc < 1 || uc > 100) {
                SetColorAndBackground(4, 0);
                const char *invalid = {"Invalid number! Please enter a number between 1 and 100.\n"};
                print_in_style(invalid, 10);
                ResetColor();
                continue; // Skip the rest of the loop for invalid input
            }

            // Provide feedback for incorrect guesses
            if (abs(uc - cc) <= 5) { // Check if the guess is within 5 of the correct number
                const char *almstThere = {"Almost there! "};
                print_in_style(almstThere, 10);
            }
            if (uc < cc) {
                const char *tooLow = {"Too low! Try again.\n"};
                print_in_style(tooLow, 10);
            } else {
                const char *tooHigh = {"Too high! Try again.\n"};
                print_in_style(tooHigh, 10);
            }
        }

        a++; // Increment the attempt counter

    } while (a <= 10); // Allow up to 10 attempts

    // If the user fails to guess within 10 attempts, end the game
    if (a > 10 && uc != cc) {
        char gameOver[100];
        SetColorAndBackground(12, 0);
        snprintf(gameOver, sizeof(gameOver),"Sorry, you've used all your attempts! The correct number was %d.\n", cc);
        print_in_style(gameOver, 10);
        char gameOverScore[100];
        snprintf(gameOverScore, sizeof(gameOverScore),"Your score: 0/10 = 0%%\n");
        print_in_style(gameOverScore, 10);
        ResetColor();
    }

    return; // Exit the program
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

void PlayAgain(){
    char playAgain;
    const char *playAgainPrompt = {"Would you like to play again? (Y/N): "};
    print_in_style(playAgainPrompt, 20);
    scanf(" %c", &playAgain);
    if(playAgain == 'Y' || playAgain == 'y'){
        main();
    } else {
        const char *goodbye = {"Goodbye!"};
        print_in_style(goodbye, 20);
        exit(0);
    }
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
        "The system has chosen a random number between 1 and 100.",
        "You have 10 attempts to guess the correct number.",
        "For each guess, you will receive feedback:",
        "  - 'Too high' if your guess is greater than the number.",
        "  - 'Too low' if your guess is less than the number.",
        "  - 'Almost there' if you are within 5 of the correct number.",
        "Your score will be higher the fewer attempts you take!",
        "Good luck and have fun!\n"
    };

    for(int i = 0; i < 8; i++){
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


