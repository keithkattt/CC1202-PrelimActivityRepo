#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80

void SetColorAndBackground(int ForgC, int BackC);
void gotoxy(int x, int y);
void displayMenu(int option);
void mainMenu();

int main() {
    mainMenu();
    return 0;
}

void SetColorAndBackground(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void gotoxy(int x, int y) {
    COORD xyPos = {0, 0};
    xyPos.X = x;
    xyPos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
    return;
}

void displayMenu(int option) { 
    system("cls");
    
    //ASCII art Main Menu
    SetColorAndBackground(15, 0);
    gotoxy(45, 1);
    printf(" __  __       _         __  __                  ");
    gotoxy(45, 2);
    printf("|  \\/  |     (_)       |  \\/  |                 ");   
    gotoxy(45, 3);
    printf("| \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _ ");
    gotoxy(45, 4);
    printf("| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |");
    gotoxy(45, 5);
    printf("| |  | | (_| | | | | | | |  | |  __/ | | | |_| |");
    gotoxy(45, 6);
    printf("|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|");



    if (option == 1) {
        gotoxy(60, 8);
        SetColorAndBackground(14, 0);
        printf("-> 1. Guessing Game\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(60, 8);
        printf("   1. Guessing Game\n");
    } 
    
    if (option == 2) {
        gotoxy(60, 9);
        SetColorAndBackground(14, 0);
        printf("-> 2. Number Tricks\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(60, 9);
        printf("   2. Number Tricks\n");
    }

    if (option == 3) {
        gotoxy(60, 10);
        SetColorAndBackground(14, 0);
        printf("-> 3. Racing Game\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(60, 10);
        printf("   3. Racing Game\n");
    }

    if (option == 4) {
        gotoxy(60, 11);
        SetColorAndBackground(14, 0);
        printf("-> 4. Exit\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(60, 11);
        printf("   4. Exit\n");
    }

}

void mainMenu() {
    int option = 1; // Initially highlight the first option
    char *game[] = {"Guessing Game", "Number Tricks", "Racing Game", "Exit"};
    char key;

    while (1) {
        displayMenu(option);
        
        key = _getch(); // Wait for key press

        if (key == UP_ARROW) {
                option--;
            if (option < 1){
                option = 4;
            } 
        } else if (key == DOWN_ARROW) {
            option++;

            if (option > 4){
                option = 1;
            }
        } else if (key == ENTER_KEY) {
            if (option == 4) {
                gotoxy(60, 13);
                printf("Exiting program"); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
                usleep(1000000); 
                break;
            }

            gotoxy(60, 13);
            printf("Starting: %s", game[option - 1]); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
            _getch(); // Wait for a key press to return to the menu
        }
    }
}