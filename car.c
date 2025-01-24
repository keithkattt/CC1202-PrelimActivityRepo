#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep function on Unix-based systems
#include <conio.h>

#define NUM_CARS 5
#define FINISH_LINE 50  // Finish line position
#define TRACK_LENGTH 60  // Total track length

// Function declarations
void printInstructions();
void race();
void displayRaceTrack(int positions[NUM_CARS], char carSymbols[NUM_CARS][10]);
void displayRanking(int positions[NUM_CARS], char cars[NUM_CARS]);

// Main menu to manage operations
void menu() {
    int choice;
    
    while(1) {
        printf("\n=== Racing Game ===\n");
        printf("1. Start Race\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                race();
                break;
            case 2:
                printf("Exiting the game...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }                          
}

// Function to print the instructions
void printInstructions() {
    printf("\nWelcome to the Racing Game!\n");
    printf("Instructions:\n");
    printf("1. The race will feature 5 cars: A, B, C, D, and E.\n");
    printf("2. Each car's movement is determined by random numbers generated during the race.\n");
    printf("3. The first car to reach the finish line wins!\n");
    printf("4. The rankings will be displayed after the race.\n");       
    printf("Let's begin the race!\n");
}

// Function to simulate a race
void race() {
    int positions[NUM_CARS] = {0}; // Array to store the current position of each car
    char cars[NUM_CARS] = {'A', 'B', 'C', 'D', 'E'};
    
    // Multi-character symbols for each car in the desired format
    char carSymbols[NUM_CARS][10] = {
        "=car1>}",   // Car A
        "=car2>}",   // Car B
        "=car3>}",   // Car C
        "=car4>}",   // Car D
        "=car5>}"    // Car E
    };
    int finished = 0;

    printInstructions();
    printf("\nPress any key to start...");
    _getch();  // Wait for user input to start

    printf("\n\nRace starting...\n"); // Display
    sleep(1);  // Sleep for 1 second    

    srand(time(0)); // Seed the random number generator

    // Simulate the race
    while(!finished) {
        system("cls");  // Clear screen to show updated race positions 
        
        // Move each car forward by a random number between 1 and 3
        for(int i = 0; i < NUM_CARS; i++) {
            positions[i] += rand() % 3 + 1;  // Move car by a random distance (1 to 3)
  
            // Ensure no car goes beyond the finish line
            if(positions[i] > FINISH_LINE) {
                positions[i] = FINISH_LINE;
            }
        }

        // Display the race track with current car positions
        displayRaceTrack(positions, carSymbols);
        
        // Check if any car has finished the race
        finished = 1;
        for(int i = 0; i < NUM_CARS; i++) {
            if(positions[i] < FINISH_LINE) {
                finished = 0;
                break;
            }
        }

        // Delay to simulate race timing
        sleep(1);  // Sleep for 1 second
    }

    // Display the ranking after the race
    displayRanking(positions, cars);
}

// Function to display the race track with car positions
void displayRaceTrack(int positions[NUM_CARS], char carSymbols[NUM_CARS][10]) {
    // Display the starting line
    printf("Start Line: |                                                         \n");

    // Display the cars' positions on the track
    for(int i = 0; i < NUM_CARS; i++) {
        printf("Car %c: [", 'A' + i);
        
        // Display the track and the car's position
        for(int j = 0; j < TRACK_LENGTH; j++) {
            if(j == positions[i]) {
                printf("%s", carSymbols[i]);  // Car symbol
            } else {
                printf(" ");
            }
        }
        printf("] %d\n", positions[i]);
    }

    // Display the finish line
    printf("Finish Line: ");
    for(int i = 0; i < TRACK_LENGTH; i++) {
        if(i == FINISH_LINE) printf("|");  // Finish line
        else printf("-");
    }
    printf("\n");
}

// Function to display the ranking results
void displayRanking(int positions[NUM_CARS], char cars[NUM_CARS]) {
    // Sort the positions and track the car identity
    int temp, rank[NUM_CARS];
    for(int i = 0; i < NUM_CARS; i++) {
        rank[i] = i;
    }

    // Simple bubble sort to rank cars based on their positions
    for(int i = 0; i < NUM_CARS - 1; i++) {
        for(int j = i + 1; j < NUM_CARS; j++) {
            if(positions[rank[i]] < positions[rank[j]]) {
                temp = rank[i];
                rank[i] = rank[j];
                rank[j] = temp;
            }
        }
    }

    // Display the final ranking
    printf("\nRace Finished! Here are the rankings:\n");
    for(int i = 0; i < NUM_CARS; i++) {
        printf("Position %d: Car %c - Distance: %d\n", i + 1, cars[rank[i]], positions[rank[i]]);
    }

    // Show the 1st to last place
    printf("\n1st Place: Car %c\n", cars[rank[0]]);
    printf("2nd Place: Car %c\n", cars[rank[1]]);
    printf("3rd Place: Car %c\n", cars[rank[2]]);
    printf("4th Place: Car %c\n", cars[rank[3]]);
    printf("5th Place: Car %c\n", cars[rank[4]]);
}

int main() {
    menu(); // Start the program menu
    return 0;
}
