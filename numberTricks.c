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
void numberTricksHeader();//Header for Number Tricks
void numberTricksMenu();//Menu for Number Tricks
void numberTricksMain();//Main Game loop


int main(){
    numberTricksMain();
    return 0;
}

void numberTricksMain(){
    system("cls");
    numberTricksHeader();

    gotoxy(20, 10);
    PrintEffect("Think of any number",  5); usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    gotoxy(20, 11);
    PrintEffect("Double the Number", 5); usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    gotoxy(20, 12);
    PrintEffect("Subtract it by 6", 5);  usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    gotoxy(20, 13);
    PrintEffect("Double the number you have right now", 5);  usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    gotoxy(20, 14);
    PrintEffect("Divide it by 4", 5);  usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    gotoxy(20, 15);
    PrintEffect("Subtract your original number\n", 5); usleep(500000); printf("."); usleep(500000); printf("."); usleep(500000); printf(".\n");
    SetColorAndBackground(14, 0); 
    gotoxy(20, 16);
    PrintEffect("The number you've got right now is \"-3\"", 5);
    ResetColor();
}

void numberTricksHeader(){
    SetColorAndBackground(9, 0);
    gotoxy(5,1);
    printf(" /$$   /$$                         /$$                                 /$$$$$$$$        /$$           /$$                \n");
    gotoxy(5,2);
    printf("| $$$ | $$                        | $$                                |__  $$__/       |__/          | $$                \n");
    gotoxy(5,3);
    printf("| $$$$| $$ /$$   /$$ /$$$$$$/$$$$ | $$$$$$$   /$$$$$$   /$$$$$$          | $$  /$$$$$$  /$$  /$$$$$$$| $$   /$$  /$$$$$$$\n");
    gotoxy(5,4);
    printf("| $$ $$ $$| $$  | $$| $$_  $$_  $$| $$__  $$ /$$__  $$ /$$__  $$         | $$ /$$__  $$| $$ /$$_____/| $$  /$$/ /$$_____/\n");
    gotoxy(5,5);
    printf("| $$  $$$$| $$  | $$| $$ \\ $$ \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/         | $$| $$  \\__/| $$| $$      | $$$$$$/ |  $$$$$$ \n");
    gotoxy(5,6);
    printf("| $$\\  $$$| $$  | $$| $$ | $$ | $$| $$  | $$| $$_____/| $$               | $$| $$      | $$| $$      | $$_  $$  \\____  $$\n");
    gotoxy(5,7);
    printf("| $$ \\  $$|  $$$$$$/| $$ | $$ | $$| $$$$$$$/|  $$$$$$$| $$               | $$| $$      | $$|  $$$$$$$| $$ \\  $$ /$$$$$$$/\n");
    gotoxy(5,8);
    printf("|__/  \\__/ \\______/ |__/ |__/ |__/|_______/  \\_______/|__/               |__/|__/      |__/ \\_______/|__/  \\__/|_______/ \n");
    printf("\n\n");
    ResetColor();
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

void SetColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

int randomNum(){
    //Lower Boundary    
    int lowerBoundary = 1;
    //Upper Boundary
    int upperBoundary = 3;

    //random seed and time based on current line
    srand(time(NULL));

    return (rand() % (upperBoundary - lowerBoundary + 1) + lowerBoundary);
}

void ResetColor(){
    SetColorAndBackground(7, 0);
}

