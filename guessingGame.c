// A guessing game program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <unistd.h>
#include <ctype.h>

#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80


int randomNum();//Generates random num from 1 - 100, parameter for how many times you use it 
int userInput(); //Prompts the user and returns the value
void guessingGameHeader(); //Prints ASCII art
void welcomeMessage(); //Prints welcome message
void GuessingGameRound(); //Main function
void guessingGame(); //Main function
void guessingGameMenu(); //Display keybinded Menu 

void mainGuessingGame(){
    int choice = 1;
    char key;

    while (1){
        guessingGameHeader();
        guessingGameMenu(choice);
        
        key = _getch();

        if (key == UP_ARROW) {
                choice--;
            if (choice < 1){
                choice = 2;
            } 
        } else if (key == DOWN_ARROW) {
            choice++;

            if (choice > 2){
                choice = 1;
            }
        } else if (key == ENTER_KEY) {
            
            switch(choice) {
                case 1:
                    gotoxy(52, 17);
                    PrintEffect("Starting Guessing game...\n", 10);
                    usleep(1000000);  // Delay for 1 second
                    system("cls");

                    guessingGame();
                    break;
                case 2:
                
                    gotoxy(52, 17);
                    PrintEffect("Exiting Guessing game...\n", 10);
                    usleep(1000000);  // Delay for 1 second

                    system("cls");
                    return;

                default:
                    PrintEffect("Invalid choice. Please try again.\n", 5);
            }
        }
    }
}

void guessingGameMenu(int choice){
    
    if (choice == 1){
        gotoxy(50, 13);
        SetColorAndBackground(14, 0);
        printf("-> 1. Start Guessing Game");
        ResetColor();
    } else {
        gotoxy(50, 13);
        printf("   1. Start Guessing Game");
    }

    if (choice == 2){
        gotoxy(50, 14);
        SetColorAndBackground(14, 0);
        printf("-> 2. Exit Guessing Game");
        ResetColor();
    } else {
        gotoxy(50, 14);
        printf("   2. Exit Guessing Game");
    }

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

void guessingGameHeader(){
    
    SetColorAndBackground(14, 0);
    system("cls");
    putchar('\n');
    gotoxy(3, 0); printf(" $$$$$$\\                                          $$\\                            $$$$$$\\                                    ");
    gotoxy(3, 1); printf("$$  __$$\\                                         \\__|                          $$  __$$\\                                   ");
    gotoxy(3, 2); printf("$$ /  \\__|$$\\   $$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\ $$\\ $$$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  ");
    gotoxy(3, 3); printf("$$ |$$$$\\ $$ |  $$ |$$  __$$\\ $$  _____|$$  _____|$$ |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ ");
    gotoxy(3, 4); printf("$$ |\\_$$ |$$ |  $$ |$$$$$$$$ |\\$$$$$$\\  \\$$$$$$\\  $$ |$$ |  $$ |$$ /  $$ |      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |");
    gotoxy(3, 5); printf("$$ |  $$ |$$ |  $$ |$$   ____| \\____$$\\  \\____$$\\ $$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|");
    gotoxy(3, 6); printf("\\$$$$$$  |\\$$$$$$  |\\$$$$$$$\\ $$$$$$$  |$$$$$$$  |$$ |$$ |  $$ |\\$$$$$$$ |      \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ ");
    gotoxy(3, 7); printf(" \\______/  \\______/  \\_______|\\_______/ \\_______/ \\__|\\__|  \\__| \\____$$ |       \\______/  \\_______|\\__| \\__| \\__| \\_______|");
    gotoxy(3, 8); printf("                                                                $$\\   $$ |                                                  ");
    gotoxy(3, 9); printf("                                                                \\$$$$$$  |                                                  ");
    gotoxy(3, 10); printf("                                                                 \\______/                                                   ");
    printf("\n\n");
    ResetColor();
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
    


