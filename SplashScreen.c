#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>
#include<process.h>

void SplashScreen();
void print_in_style(const char *str, int delay);
void SetColorAndBackground(int ForgC, int BackC);
void ResetColor();
void gotoxy(int x, int y);

int main(){
    SplashScreen();
    return 0;
}

void SplashScreen() {
    // Print each line of the splash screen with a typewriter effect
    const char *splash[] = {
    "***********************************************************************************************************",
    "*         .o.       ooooo        oooo    oooo ooooo   ooooo       .o.       ooooo              .o.        *",
    "*        .888.      `888'        `888   .8P'  `888'   `888'      .888.      `888'             .888.       *",
    "*       .8\"888.      888          888  d8'     888     888      .8\"888.      888             .8\"888.      *",
    "*      .8' `888.     888          88888[       888ooooo888     .8' `888.     888            .8' `888.     *",
    "*     .88ooo8888.    888          888`88b.     888     888    .88ooo8888.    888           .88ooo8888.    *",
    "*    .8'     `888.   888       o  888  `88b.   888     888   .8'     `888.   888       o  .8'     `888.   *",
    "*   o88o     o8888o o888ooooood8 o888o  o888o o888o   o888o o88o     o8888o o888ooooood8 o88o     o8888o  *",
    "***********************************************************************************************************",
    };

    int y = 5;  // Initial y-coordinate for the splash screen
    system("cls");  // Clear the screen

    // Loop through each line of the splash screen
    for (int i = 0; i < 9; i++) {
        gotoxy(15, y);  // Set the cursor position
        y++;  // Increment y-coordinate for the next line
        SetColorAndBackground(6, 0);
        print_in_style(splash[i], 5);
        putchar('\n');  // Newline after each line is printed
    }
    ResetColor();  // Reset the text color and background

    // Wait for a key press before continuing
    gotoxy(15, 15);
    print_in_style("Press any key to continue...", 20);
    _getch();
    system("cls");  // Clear the screen
    return;
}

void print_in_style(const char *str, int delay){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(delay);
    }
}

void gotoxy(int x, int y) //function definition
     {
            COORD xyPos = {0, 0};   //initialization cursor position
            xyPos.X = x;   xyPos.Y =  y;  //assign coordinates

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xyPos);
            return;
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