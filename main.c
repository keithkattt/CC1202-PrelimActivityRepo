#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

#include "functions.h"
#include "splash.c"
#include "acknowledgments.c"
#include "guessingGame.c"
#include "numberTricks.c"
#include "racingGame.c"

#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80

void displayMenu(int option);
void mainMenu();

int main() {
    mainSplash();
    mainMenu();
    mainAcknowledgement();
    return 0;
}

void displayMenu(int option) { 
    system("cls");
    
    //ASCII art Main Menu
    SetColorAndBackground(6, 0);
    gotoxy(40, 1);
    printf("  __  __       _         __  __                  ");
    gotoxy(40, 2);
    printf(" |  \\/  |     (_)       |  \\/  |                 ");
    gotoxy(40, 3);
    printf(" | \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _ ");
    gotoxy(40, 4);
    printf(" | |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |");
    gotoxy(40, 5);
    printf(" | |  | | (_| | | | | | | |  | |  __/ | | | |_| |");
    gotoxy(40, 6);
    printf(" |_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|");
    gotoxy(40, 7);
    printf("                                                 ");
    gotoxy(40, 8);
    printf("                                                 ");
    SetColorAndBackground(15, 0);

    if (option == 1) {
        gotoxy(52, 9);
        SetColorAndBackground(14, 0);
        printf("-> 1. Guessing Game\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(52, 9);
        printf("   1. Guessing Game\n");
    } 
    
    if (option == 2) {
        gotoxy(52, 10);
        SetColorAndBackground(14, 0);
        printf("-> 2. Number Tricks\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(52, 10);
        printf("   2. Number Tricks\n");
    }

    if (option == 3) {
        gotoxy(52, 11);
        SetColorAndBackground(14, 0);
        printf("-> 3. Racing Game\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(52, 11);
        printf("   3. Racing Game\n");
    }

    if (option == 4) {
        gotoxy(52, 12);
        SetColorAndBackground(14, 0);
        printf("-> 4. Exit\n");
        SetColorAndBackground(15, 0);
    } else {
        gotoxy(52, 12);
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
                gotoxy(55, 14);
                printf("Exiting program"); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
                usleep(1000000); 
                system("cls");
                break;
            }

            if (option == 1){
                gotoxy(52, 14);
                printf("Starting: %s", game[option - 1]); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
                mainGuessingGame();
            }

            if (option == 2){
                gotoxy(52, 14);
                printf("Starting: %s", game[option - 1]); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
                mainNumberTricks();
            }

            if (option == 3){
                gotoxy(52, 14);
                printf("Starting: %s", game[option - 1]); usleep(300000); printf(".");  usleep(300000); printf("."); usleep(300000); printf(".");   
                mainRacingGame();
            }
        }
    }
}