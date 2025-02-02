#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>  // For sleep function 
#include <conio.h>



#define NUM_CARS 5
#define FINISH_LINE 100  // Finish line position
#define TRACK_LENGTH 110  // Total track length
#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80


// Function declarations
void printInstructions();
void race();
void menu(int choice);
void displayRaceTrack(int positions[NUM_CARS], char carSymbols[NUM_CARS][10]);
void displayRanking(int positions[NUM_CARS], char cars[NUM_CARS]);
void gotoxy();
void SetColorAndBackground();
void PrintEffect(const char *str, int delay);
void resetColor(); 
void racingGameHeader();
void racingGameRound();


void mainRacingGame() {
    int choice = 1;
    char key;

    while (1){
        menu(choice);
        
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
                    gotoxy(57, 17);
                    PrintEffect("Starting Racing Game...\n", 10);
                    usleep(1000000);  // Delay for 1 second
                    system("cls");

                    race();
                    break;
                case 2:
                
                    gotoxy(57, 17);
                    PrintEffect("Exiting Racing Game...\n", 10);
                    usleep(1000000);  // Delay for 1 second

                    system("cls");
                    return;

                default:
                    PrintEffect("Invalid choice. Please try again.\n", 5);
                }
        }
    }

    resetColor();  // Reset text color to default   
}

// Main menu to manage operations
void menu(int choice) {

    	system("cls");
        racingGameHeader();

        if (choice == 1){
            gotoxy(55, 13);
            SetColorAndBackground(11, 0);
            printf("-> 1. Start Racing Game");
            resetColor();
        } else {
            gotoxy(55, 13);
            printf("   1. Start Racing Game");
        }

        if (choice == 2){
            gotoxy(55, 14);
            SetColorAndBackground(11, 0);
            printf("-> 2. Exit Racing Game");
            resetColor();
        } else {
            gotoxy(55, 14);
            printf("   2. Exit Racing Game");
        }
                  
}

// Function to print the instructions
void printInstructions() {
    PrintEffect("\nWelcome to the Racing Game!\n", 10);
    PrintEffect("Instructions:\n", 10);
    PrintEffect("1. The race will feature 5 cars: A, B, C, D, and E.\n", 10);
    PrintEffect("2. Each car's movement is determined by random numbers generated during the race.\n", 10);
    PrintEffect("3. The first car to reach the finish line wins!\n", 10);
    PrintEffect("4. The rankings will be displayed after the race.\n", 10);       
    PrintEffect("Let's begin the race!\n", 10);
}

// Function to simulate a race
void race() {
    int positions[NUM_CARS] = {0}; // Array to store the current position of each car
    char cars[NUM_CARS] = {'A', 'B', 'C', 'D', 'E'};
    
    // Multi-character symbols for each car in the desired format
    char carSymbols[NUM_CARS][10] = {
        "[=CarA>}",   // Car A
        "[=CarB>}",   // Car B
        "[=CarC>}",   // Car C
        "[=CarD>}",   // Car D
        "[=CarE>}"    // Car E
    };
    
    int finished = 0;
      
    racingGameHeader();

    printInstructions(); //prints the instructions
    PrintEffect("\nPress any key to start...", 10);
    _getch();  // Wait for user input to start

    PrintEffect("\n\nRace starting...\n", 10); // Display
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
          for(int i = 0; i < NUM_CARS; i++) {
            if(positions[i] != FINISH_LINE) {
                finished = 0;
                
            }else {
                finished = 1;
                break;
            }
        }
       
        // Delay to simulate race timing
        usleep(90000);  // delay 90 milliseconds or 0.09 seconds
    }

    // Display the ranking after the race
    SetColorAndBackground(14, 0);  // Set text color to bright yellow
    displayRanking(positions, cars);
}

// Function to display the race track with car positions
void displayRaceTrack(int positions[NUM_CARS], char carSymbols[NUM_CARS][10]) {
    
    //display header for racing game
       
    
    
    SetColorAndBackground(3, 0);  // Set text color to cyan
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
        usleep(500000);  // Sleep for 0.5 seconds
    }


    SetColorAndBackground(10, 0);  // Set text color to bright green
    // Show the 1st to last place
    printf("\n1st Place: Car %c\n", cars[rank[0]]);
    usleep(500000);  // Sleep for 0.5 seconds
    printf("2nd Place: Car %c\n", cars[rank[1]]);
    usleep(500000);  // Sleep for 0.5 seconds
    printf("3rd Place: Car %c\n", cars[rank[2]]);
    usleep(500000);  // Sleep for 0.5 seconds
    printf("4th Place: Car %c\n", cars[rank[3]]);
    usleep(500000);  // Sleep for 0.5 seconds
    printf("5th Place: Car %c\n\n", cars[rank[4]]);
	
	printf("Press any key to continue... ");
	_getch();
    usleep(500000);  // Sleep for 0.5 seconds

}

void racingGameHeader(){
     SetColorAndBackground(11, 0);  // Set text color to bright cyan
        gotoxy(10, 0);
        printf(" /$$$$$$$                      /$$                            /$$$$$$                                   \n");
        gotoxy(10, 1);
        printf("| $$__  $$                    |__/                           /$$__  $$                                  \n");
        gotoxy(10, 2);
        printf("| $$  \\ $$  /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ \n");
        gotoxy(10, 3);
        printf("| $$$$$$$/ |____  $$ /$$_____/| $$| $$__  $$ /$$__  $$      | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$\n");
        gotoxy(10, 4);
        printf("| $$__  $$  /$$$$$$$| $$      | $$| $$  \\ $$| $$  \\ $$      | $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$\n");
        gotoxy(10, 5);
        printf("| $$  \\ $$ /$$__  $$| $$      | $$| $$  | $$| $$  | $$      | $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/\n");
        gotoxy(10, 6);
        printf("| $$  | $$|  $$$$$$$|  $$$$$$$| $$| $$  | $$|  $$$$$$$      |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$\n");
        gotoxy(10, 7);
        printf("|__/  |__/ \\_______/ \\_______/|__/|__/  |__/ \\____  $$       \\______/  \\_______/|__/ |__/ |__/ \\_______/\n");
        gotoxy(10, 8);
        printf("                                             /$$  \\ $$                                                  \n");
        gotoxy(10, 9);
        printf("                                            |  $$$$$$/                                                  \n");
        gotoxy(10, 10);
        printf("                                             \\______/                                                   \n");
        ResetColor();
}


