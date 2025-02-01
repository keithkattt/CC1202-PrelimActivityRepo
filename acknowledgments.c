#include <stdio.h>
#include <unistd.h> 
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void SetColorAndBackground(int ForgC, int BackC);
void ResetColor();
void acknowledgementHeader();
void acknowledgementText();

int main(){
    acknowledgementHeader();

    return 0;
}

void acknowledgementHeader(){
    system("cls");
    SetColorAndBackground(6, 0);    
    gotoxy(20, 0); printf("     _        _                        _          _                                 _   "); usleep(100000);  
    gotoxy(20, 1); printf("    / \\   ___| | ___ __   _____      _| | ___  __| | __ _  ___ _ __ ___   ___ _ __ | |_ "); usleep(100000);
    gotoxy(20, 2); printf("   / _ \\ / __| |/ / '_ \\ / _ \\ \\ /\\ / / |/ _ \\/ _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|"); usleep(100000);
    gotoxy(20, 3); printf("  / ___ \\ (__|   <| | | | (_) \\ V  V /| |  __/ (_| | (_| |  __/ | | | | |  __/ | | | |_ "); usleep(100000);
    gotoxy(20, 4); printf(" /_/   \\\\_\\___|_\\_\\_| |_|\\___/ \\_/\\_/ |_|\\___|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|"); usleep(100000);
    gotoxy(20, 5); printf("                                                    |___/                                ");
    ResetColor();
}

void acknowledgementText(){
    const char *acknowledgement[] = {
        " ______________________________________________________________________________________"  
        "|  Splash, Menu, Acknowledgement, Debugging:                                           |"
        "|  Keith Arwil Umali || 0961 279 8645 || keith110606@gmail.com || BSCS-DS-1A           |"
        "|______________________________________________________________________________________|"
        "|  Guessing Game by:                                                                   |"
        "|  Lance Aclan || 0967 276 0722 || lancemercadoaclan@gmail.com || BSCS-DS-1A           |"
        "|______________________________________________________________________________________|"
        "|                                                                                      |"
        "|                                                                                      |"
        "|                                                                                      |"
        "|                                                                                      |"
        "|                                                                                      |"
        "|                                                                                      |"
        "|                                                                                      |"
        "|  Racing Game by:                                                                     |"
        "|  Hannah Kim Tominez || 0962 793 0143 || tominezhannah800@gmail.com || BSCS-DS-1A     |"
        "|______________________________________________________________________________________|"
    };
    
    int splashSize = sizeof(acknowledgement) / sizeof(acknowledgement[0]);

}


void gotoxy(int x, int y) {
    
    COORD xyPos = {0, 0};
    xyPos.X = x;
    xyPos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyPos);
    return;
}

void SetColorAndBackground(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void ResetColor() {
    SetColorAndBackground(15, 0); // Reset text color to white and background to black
}

