#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80

// Function to change the color of text
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to display the menu with cursor navigation
void displayMenu(int option) {
    system("cls"); // Clear the screen

    setColor(10); // Set text color to green
    gotoxy(20, 10);
    printf("*******************************\n");
    printf("      ASCII Menu Design\n");
    printf("*******************************\n\n");

    // Display options
    setColor(15); // Default text color (White)
    if (option == 1) {
        setColor(14); // Yellow color for selected option
        printf("-> Option 1: Option One\n");
        setColor(15); // Reset color for others
    } else {
        printf("   Option 1: Option One\n");
    }
    
    if (option == 2) {
        setColor(14);
        printf("-> Option 2: Option Two\n");
        setColor(15);
    } else {
        printf("   Option 2: Option Two\n");
    }

    if (option == 3) {
        setColor(14);
        printf("-> Option 3: Option Three\n");
        setColor(15);
    } else {
        printf("   Option 3: Option Three\n");
    }

    if (option == 4) {
        setColor(14);
        printf("-> Option 4: Option Four\n");
        setColor(15);
    } else {
        printf("   Option 4: Option Four\n");
    }

    if (option == 5) {
        setColor(14);
        printf("-> Option 5: Exit\n");
        setColor(15);
    } else {
        printf("   Option 5: Exit\n");
    }
}

int main() {
    int option = 1; // Initially highlight the first option
    char key;

    while (1) {
        displayMenu(option);
        
        key = _getch(); // Wait for key press

        if (key == UP_ARROW) {
            if (option > 1)
                option--;
        } else if (key == DOWN_ARROW) {
            if (option < 5)
                option++;
        } else if (key == ENTER_KEY) {
            if (option == 5) {
                printf("\nExiting program...\n");
                break;
            }
            printf("\nYou selected Option %d\n", option);
            _getch(); // Wait for a key press to return to the menu
        }
    }

    return 0;
}
