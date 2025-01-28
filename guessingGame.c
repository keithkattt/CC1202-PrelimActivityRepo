// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <unistd.h>
#include <ctype.h>

int randomNum();//Generates random num from 1 - 100, parameter for how many times you use it 
int userInput(); //Prompts the user and returns the value
void guessingGameHeader(); //Prints ASCII art
void welcomeMessage(); //Prints welcome message
void PrintEffect(const char *str, int delay); //Prints in style
void SetColorAndBackground(int ForgC, int BackC); ////color value range 0 up-to 256
void ResetColor(); //Resets the color and background
void GuessingGameRound(); //Main function
void PlayAgain(); //Asks the user if they want to play again
void guessingGame(); //Main function
void gotoxy(int x, int y); //Moves the cursor to the x and y coordinates

int main(){
    int choice;

    while (1)
    {
    guessingGameHeader();

    gotoxy(60, 13);
    printf("1. Start Game\n");
    gotoxy(60, 14);
    printf("2. Exit\n");
    gotoxy(60, 15);
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch(choice) {
            case 1:
                guessingGame();
                break;
            case 2:
                gotoxy(60, 16);
                PrintEffect("Exiting the game...\n", 5);
                usleep(1000);  // Sleep for 1 second

                system("cls");
                exit(0);
                
            default:
                PrintEffect("Invalid choice. Please try again.\n", 5);
        }
    }
    return 0;
}

void gotoxy(int x, int y){
    COORD xyPos = {0, 0};
    xyPos.X = x;
    xyPos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
    return;
}

void guessingGame(){
    guessingGameHeader();
    welcomeMessage();

    int computerNum = randomNum();
    int userGuess;
    
    GuessingGameRound(userGuess, computerNum);
}

void GuessingGameRound(int uc, int cc) {
    int a = 1; // Attempt counter
    int s = 0; // Score variable
    
    // Game loop: Allow up to 10 attempts
   do {
    // Prompt the user to enter a guess
    char prompt[100];
    snprintf(prompt, sizeof(prompt), "Attempt %d: Enter your guess: ", a);
    PrintEffect(prompt, 10);

    // Validate input
    if (scanf("%d", &uc) != 1) { // If input is not an integer
        SetColorAndBackground(4, 0);
        const char *invalidInput = {"Invalid input! Please enter a number between 1 and 100.\n"};
        PrintEffect(invalidInput, 10);
        ResetColor();

        // Clear the input buffer to handle any extra characters
        while (getchar() != '\n'); 
        continue; // Continue the loop without incrementing the attempt counter
    }

    // Check if the guess is correct
    if (uc == cc) {
        const char *correct = {"Correct! You've guessed the number!\n"};
        PrintEffect(correct, 10);

        // Calculate the score based on the number of attempts used
        s = (11 - a) * 10; // Score calculation: higher for fewer attempts
        char calcScore[100];
        snprintf(calcScore, sizeof(calcScore), "Your score: %d/10 = %d%%\n", (11 - a), s);
        PrintEffect(calcScore, 10);
        break; // Exit the loop since the guess is correct
    } else {
        // Check if the guess is outside the valid range (1-100)
        if (uc < 1 || uc > 100) {
            SetColorAndBackground(4, 0);
            const char *invalid = {"Invalid number! Please enter a number between 1 and 100.\n"};
            PrintEffect(invalid, 10);
            ResetColor();
            continue; // Skip the rest of the loop for invalid input
        } else {
            // Check if the guess is within 5 of the correct number
            if (abs(uc - cc) <= 5) {
                const char *almstThere = {"Almost there! "};
                PrintEffect(almstThere, 10);
            }
            if (uc < cc) {
                const char *tooLow = {"Too low! Try again.\n"};
                PrintEffect(tooLow, 10);
            } else {
                const char *tooHigh = {"Too high! Try again.\n"};
                PrintEffect(tooHigh, 10);
            }
        }
    }
    a++; // Increment the attempt counter

} while (a <= 10); // Allow up to 10 attempts


    // If the user fails to guess within 10 attempts, end the game
    if (a > 10 && uc != cc) {
        char gameOver[100];
        SetColorAndBackground(12, 0);
        snprintf(gameOver, sizeof(gameOver),"\t\tSorry, you've used all your attempts! The correct number was %d.\n", cc);
            PrintEffect(gameOver, 10);
        char gameOverScore[100];
        snprintf(gameOverScore, sizeof(gameOverScore),"\t\tYour score: 0/10 = 0%%\n");
            PrintEffect(gameOverScore, 10);
        ResetColor();
    }

    SetColorAndBackground(11, 0);
    PrintEffect("\nPress any key to return...", 10);
    getch(); // Wait for a key press

    ResetColor();
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
    PrintEffect(userInput, 20);
    scanf("%d", &numInput);
    return numInput;
}

void PlayAgain(){
    char playAgain;
    const char *playAgainPrompt = {"Would you like to play again? (Y/N): "};
    PrintEffect(playAgainPrompt, 20);
    scanf(" %c", &playAgain);
    if(playAgain == 'Y' || playAgain == 'y'){
        main();
    } else {
        const char *goodbye = {"Goodbye!"};
        PrintEffect(goodbye, 20);
        exit(0);
    }
}

void guessingGameHeader(){
    
    SetColorAndBackground(14, 0);
    system("cls");
    putchar('\n');
    printf("\t $$$$$$\\                                          $$\\                            $$$$$$\\                                    \n");
    printf("\t$$  __$$\\                                         \\__|                          $$  __$$\\                                   \n");
    printf("\t$$ /  \\__|$$\\   $$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  \n");
    printf("\t$$ |$$$$\\ $$ |  $$ |$$  __$$\\ $$  _____|$$  _____|$$ |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ \n");
    printf("\t$$ |\\_$$ |$$ |  $$ |$$$$$$$$ |\\$$$$$$\\  \\$$$$$$\\  $$ |$$ |  $$ |$$ /  $$ |      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n");
    printf("\t$$ |  $$ |$$ |  $$ |$$   ____| \\____$$\\  \\____$$\\ $$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n");
    printf("\t\\$$$$$$  |\\$$$$$$  |\\$$$$$$$\\ $$$$$$$  |$$$$$$$  |$$ |$$ |  $$ |\\$$$$$$$ |      \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ \n");
    printf("\t \\______/  \\______/  \\_______|\\_______/ \\_______/ \\__|\\__|  \\__| \\____$$ |       \\______/  \\_______|\\__| \\__| \\__| \\_______|\n");
    printf("\t                                                                $$\\   $$ |                                                  \n");
    printf("\t                                                                \\$$$$$$  |                                                  \n");
    printf("\t                                                                 \\______/                                                   \n\n");
}

void welcomeMessage(){
    SetColorAndBackground(11, 0);

    const char *welcome[] = {
        "\t\tThe system has chosen a random number between 1 and 100.",
        "\t\tYou have 10 attempts to guess the correct number.",
        "\t\tFor each guess, you will receive feedback:",
        "\t\t  - 'Too high' if your guess is greater than the number.",
        "\t\t  - 'Too low' if your guess is less than the number.",
        "\t\t  - 'Almost there' if you are within 5 of the correct number.",
        "\t\tYour score will be higher the fewer attempts you take!",
        "\t\tGood luck and have fun!\n"
    };

    for(int i = 0; i < 8; i++){
        PrintEffect(welcome[i], 10);
        printf("\n");
    }
        ResetColor();
}
    
void PrintEffect(const char *str, int delay){
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


