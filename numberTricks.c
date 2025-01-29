#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y);//Moves the cursor to the x and y coordinates
void PrintEffect(const char *str, int delay); //Prints in style
void SetColorAndBackground(int ForgC, int BackC); ////color value range 0 up-to 15 
void ResetColor(); //Resets the color and background

int main(){
    printf(" /$$   /$$                         /$$                                 /$$$$$$$$        /$$           /$$                \n");
    printf("| $$$ | $$                        | $$                                |__  $$__/       |__/          | $$                \n");
    printf("| $$$$| $$ /$$   /$$ /$$$$$$/$$$$ | $$$$$$$   /$$$$$$   /$$$$$$          | $$  /$$$$$$  /$$  /$$$$$$$| $$   /$$  /$$$$$$$\n");
    printf("| $$ $$ $$| $$  | $$| $$_  $$_  $$| $$__  $$ /$$__  $$ /$$__  $$         | $$ /$$__  $$| $$ /$$_____/| $$  /$$/ /$$_____/\n");
    printf("| $$  $$$$| $$  | $$| $$ \\ $$ \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/         | $$| $$  \\__/| $$| $$      | $$$$$$/ |  $$$$$$ \n");
    printf("| $$\\  $$$| $$  | $$| $$ | $$ | $$| $$  | $$| $$_____/| $$               | $$| $$      | $$| $$      | $$_  $$  \\____  $$\n");
    printf("| $$ \\  $$|  $$$$$$/| $$ | $$ | $$| $$$$$$$/|  $$$$$$$| $$               | $$| $$      | $$|  $$$$$$$| $$ \\  $$ /$$$$$$$/\n");
    printf("|__/  \\__/ \\______/ |__/ |__/ |__/|_______/  \\_______/|__/               |__/|__/      |__/ \\_______/|__/  \\__/|_______/ \n");

    return 0;
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

