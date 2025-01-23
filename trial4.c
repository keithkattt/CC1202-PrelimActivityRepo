#include <stdio.h>   // Required for input/output functions
#include <stdlib.h>  // Required for srand, rand, abs
#include <time.h>    // Required for seeding the random number generator
#include <unistd.h>  // Required for usleep (delays)

// Main function: Entry point of the program
int main() {
    // Seed the random number generator using the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int cc = (rand() % 100) + 1; 
    int uc; // Variable to store the user's guess

    // Display the welcome message
    printf("Welcome to the Number Guessing Challenge!\n\n");

    // Define the game instructions as an array of strings
    const char *instructions[] = {
        "The system has chosen a random number between 1 and 100.",
        "You have 10 attempts to guess the correct number.",
        "For each guess, you will receive feedback:",
        "  - 'Too high' if your guess is greater than the number.",
        "  - 'Too low' if your guess is less than the number.",
        "  - 'Almost there' if you are within 5 of the correct number.",
        "Your score will be higher the fewer attempts you take!",
        "Good luck and have fun!\n"
    };

    // Display the instructions with a delay for readability
    for (int i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++) {
        printf("%s\n", instructions[i]);
        usleep(500000); // Delay of 0.5 seconds for better user experience
    }

    int a = 1; // Attempt counter
    int s = 0; // Score variable

    // Game loop: Allow up to 10 attempts
    do {
        // Prompt the user to enter a guess
        printf("Attempt %d: Enter your guess: \n", a);
        scanf("%d", &uc); // Read the user's input

        // Check if the guess is correct
        if (uc == cc) {
            printf("Correct! You've guessed the number!\n");

            // Calculate the score based on the number of attempts used
            s = (11 - a) * 10; // Score calculation: higher for fewer attempts
            printf("Your score: %d/10 = %d%%\n", (11 - a), s);
            break; // Exit the loop since the guess is correct
        } else {
            // Check if the guess is outside the valid range (1-100)
            if (uc < 1 || uc > 100) {
                printf("Invalid number! Please enter a number between 1 and 100.\n");
                continue; // Skip the rest of the loop for invalid input
            }

            // Provide feedback for incorrect guesses
            if (abs(uc - cc) <= 5) { // Check if the guess is within 5 of the correct number
                printf("Almost there! ");
            }
            if (uc < cc) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too high! Try again.\n");
            }
        }

        a++; // Increment the attempt counter

    } while (a <= 10); // Allow up to 10 attempts

    // If the user fails to guess within 10 attempts, end the game
    if (a > 10 && uc != cc) {
        printf("Sorry, you've used all your attempts! The correct number was %d.\n", cc);
        printf("Your score: 0/10 = 0%%\n");
    }

    return 0; // Exit the program
}
