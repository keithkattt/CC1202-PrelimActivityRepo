#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _getch()

// Function to display the menu
void displayMenu(int selected) {
    system("cls"); // Clear the screen
    printf("\033[44;37m"); // Blue background, white text
    printf("===================================\n");
    printf("             GAME MENU             \n");
    printf("===================================\n");
    printf("\033[0m"); // Reset colors

    // Highlight the selected option
    for (int i = 1; i <= 4; i++) {
        if (i == selected) {
            printf("\033[42;30m"); // Green background, black text
        } else {
            printf("\033[40;37m"); // Black background, white text
        }

        switch (i) {
            case 1:
                printf("   1. Guessing Game               \n");
                break;
            case 2:
                printf("   2. Number Tricks               \n");
                break;
            case 3:
                printf("   3. Racing Game                 \n");
                break;
            case 4:
                printf("   4. Exit                        \n");
                break;
        }
        printf("\033[0m"); // Reset colors
    }
    printf("\033[40;37m"); // Black background, white text
    printf("===================================\n");
    printf(" Use 'W' to move up, 'S' to move down. Press ENTER to select.\n");
    printf("===================================\n");
}

int main() {
    int selected = 1; // Current selected option
    char input;

    while (1) {
        displayMenu(selected);

        // Get user input
        input = _getch();
        if (input == 0 || input == 224){
            if (input == 65) {
                selected--; // Move up
                if (selected < 1) {
                    selected = 4; // Wrap to bottom
                }
            } else if (input == 66) {
                selected++; // Move down
                if (selected > 4) {
                    selected = 1; // Wrap to top
                }
            } else if (input == '\r') { // Enter key
                system("cls"); // Clear the screen
                printf("\033[44;37m"); // Blue background, white text
                printf("===================================\n");
                printf("       You selected option %d      \n", selected);
                printf("===================================\n");
                printf("\033[0m"); // Reset colors
                if (selected == 4) {
                    break; // Exit the program
                }
                printf("Press any key to go back to the menu...\n");
                _getch(); // Wait for user input
            }
        }
    }

    printf("\033[0m"); // Reset colors
    return 0;
}