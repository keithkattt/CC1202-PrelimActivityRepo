#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

int randomNum();//Generates random num from 1 - 3, parameter for how many times you use it 
void gotoxy(int x, int y);//Moves the cursor to the x and y coordinates
void PrintEffect(const char *str, int delay); //Prints in style
void SetColorAndBackground(int ForgC, int BackC); ////color value range 0 up-to 15 
void ResetColor(); //Resets the color and background
void textBubble(const char *message); //text bubble for Merlin the Wizard

int main() {
    printf("             o                            ________________________\n");
    printf("                   O       /`-.__       < Welcome to Number tricks >\n");
    printf("                          /  \\¯'^|       -----------------------\n");
    printf("             o           T    l  *         /          \n");
    printf("                        _|-..-|_          /          \n");
    printf("                 O    (^ '----' `)\n");
    printf("                       `\\-....-/^\n");
    printf("             O       o  ) \"/ \" (\n");
    printf("                       _( (-)  )_\n");
    printf("                   O  /\\ )    (  /\\\n");
    printf("                     /  \\\u00a0(    ) |  \\\n");
    printf("                 o  o    \\\\)  ( /    \\\n");
    printf("                   /     |(  )|      \\\n");
    printf("                  /    o \\\\ \\( /       \\\n");
    printf("            __.--'   O    \\\\_ /   .._   \\\n");
    printf("           //|)\\      ,   (_)   /(((\\^)\'\\\n");
    printf("              |       | O         )  `  |\n");
    printf("              |      / o___      /      /\n");
    printf("             /  _.-''^^__O_^^''-._     /\n");
    printf("           .'  /  -''^^    ^^''-  \\\\--'^\n");
    printf("         .'   .`.  `'''----'''^  .`. \\\n");
    printf("       .'    /   `'--..____..--'^   \\\\ \\\n");
    printf("      /  _.-/                        \\\\ \\\n");
    printf("  .::'/^   |                        |  `.\n");
    printf("         .-'|                        |    `-.\n");
    printf("   _.--'`   \\\\                        /       `-.\n");
    printf("  /          \\\\                      /           `-._\n");
    printf("  `'---..__   `.                  .__.._   __       \\\n");
    printf("           ``'''`.              .'      `'^  `''---'^\n");
    printf("                  `-..______..-'\n");


    return 0;
}

void textBubble(const char *message){
    //x = 43   ________________________
    //x = 41 < Welcome to Number tricks >
    //x = 43   -----------------------
    //x = 44    /    
    //x = 43   /

}

void gotoxy(int x, int y){
    COORD xyPos = {0, 0};
    xyPos.X = x;
    xyPos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
    return;
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