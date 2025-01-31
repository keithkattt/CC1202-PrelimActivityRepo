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
void wizard(); //Displays Merlin the Wizard
void textBubble(); //text bubbles for Merlin the Wizard

int main() {
    system("cls");
    wizard();
    textBubble();

    

    return 0;
}

void textBubble(){
    //x = 43   ________________________
    //x = 41 < Welcome to Number tricks >
    //x = 43   -----------------------
    //x = 44    /    
    //x = 43   /

    gotoxy(43, 0);
    printf("_________________________");
    gotoxy(41, 1);
    printf("<  Welcome to Number tricks  >");
    gotoxy(43, 2);
    printf("-------------------------");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("________________________ ");
    gotoxy(43, 2);
    printf("------------------------ ");
    gotoxy(41, 1);
    printf("<  I am Merlin the Wizard  >  ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("_______________________________________");
    gotoxy(43, 2);
    printf("---------------------------------------");
    gotoxy(41, 1);
    printf("<  Today I'll show you something "); SetColorAndBackground(11, 0); printf("MAGICAL "); ResetColor(); printf(">");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("___________________________            ");
    gotoxy(43, 2);
    printf("---------------------------             ");
    gotoxy(41, 1);
    printf("<  First think of any number  >            ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("___________________                     ");
    gotoxy(43, 2);
    printf("-------------------                      ");
    gotoxy(41, 1);
    printf("<  Double the number  >                ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("_______________________         ");
    gotoxy(43, 2);
    printf("-----------------------          ");
    gotoxy(41, 1);
    printf("<  Then Subtract it by 6  >        ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("_________________________               ");
    gotoxy(43, 2);
    printf("-------------------------                    ");
    gotoxy(41, 1);
    printf("<  Double the number again  >                 ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("________________                                ");
    gotoxy(43, 2);
    printf("----------------                                 ");
    gotoxy(41, 1);
    printf("<  Divide it by 4  >                       ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("__________________________________________");
    gotoxy(43, 2);
    printf("------------------------------------------");
    gotoxy(41, 1);
    printf("<  Then Subtract it by your original number  >");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");

    getch();

    gotoxy(43, 0);
    printf("_________________________                  ");
    gotoxy(43, 2);
    printf("-------------------------                  ");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");
    gotoxy(41, 1);
    printf("<  The outcome would be     >                 "); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be.    >"); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be..   >"); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be...  >");

    usleep(2000000);

    gotoxy(43, 0);
    printf("_________________________");
    gotoxy(43, 2);
    printf("-------------------------");
    gotoxy(44, 3);
    printf("/");
    gotoxy(43, 4);
    printf("/");
    gotoxy(41, 1);
    printf("<  The outcome would be     >"); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be.    >"); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be..   >"); 
    usleep(1000000); 
    gotoxy(41, 1);
    printf("<  The outcome would be...  >");

    usleep(2000000);
    gotoxy(43, 0);
    printf("_______________                     ");
    gotoxy(41, 1);
    printf("<"); SetColorAndBackground(9, 0); printf("         ____   "); ResetColor(); printf(">             ");
    gotoxy(41, 2);
    printf("<"); SetColorAndBackground(9, 0); printf("  ___   ( __ \\  "); ResetColor(); printf(">             ");
    gotoxy(41, 3);
    printf("<"); SetColorAndBackground(9, 0); printf(" (___)   (__ (  "); ResetColor(); printf(">             ");
    gotoxy(41, 4);
    printf("<"); SetColorAndBackground(9,0); printf("        (____/  "); ResetColor(); printf(">             ");
    gotoxy(43, 5);
    printf("---------------                     ");
    gotoxy(44, 6);
    printf("/");
    gotoxy(43, 7);
    printf("/");

    getch();


}



void wizard(){
    gotoxy(0, 1);
    printf("             o");
    gotoxy(0, 2);
    printf("                   O       /`-.__");
    gotoxy(0, 3);
    printf("                          /  \\¯'^|");
    gotoxy(0, 4);
    printf("             o           T    l  *");
    gotoxy(0, 5);
    printf("                        _|-..-|_");
    gotoxy(0, 6);
    printf("                 O    (^ '----' `)");
    gotoxy(0, 7);
    printf("                       `\\-....-/^");
    gotoxy(0, 8);
    printf("             O       o  ) \"/ \" (");
    gotoxy(0, 9);
    printf("                       _( (-)  )_");
    gotoxy(0, 10);
    printf("                   O  /\\ )    (  /\\");
    gotoxy(0, 11);
    printf("                     /  \\ (    ) |  \\");
    gotoxy(0, 12);
    printf("                 o  o    \\)  ( /    \\");
    gotoxy(0, 13);
    printf("                   /     |(  )|      \\");
    gotoxy(0, 14);
    printf("                  /    o \\ \\( /       \\");
    gotoxy(0, 15);
    printf("            __.--'   O    \\_ /   .._   \\");
    gotoxy(0, 16);
    printf("           //|)\\      ,   (_)   /(((\\^)\'\\");
    gotoxy(0, 17);
    printf("              |       | O         )  `  |");
    gotoxy(0, 18);
    printf("              |      / o___      /      /");
    gotoxy(0, 19);
    printf("             /  _.-''^^__O_^^''-._     /\n");
    gotoxy(0, 20);
    printf("           .'  /  -''^^    ^^''-  \\--'^\n");
    gotoxy(0, 21);
    printf("         .'   .`.  `'''----'''^  .`. \\\n");
    gotoxy(0, 22);
    printf("       .'    /   `'--..____..--'^   \\ \\\n");
    gotoxy(0, 23);
    printf("      /  _.-/                        \\ \\\n");
    gotoxy(0, 24);
    printf("  .::'/^    |                        | `.\n");
    gotoxy(0, 25);
    printf("         .-'|                        |    `-.\n");
    gotoxy(0, 26);
    printf("   _.--'`   \\                        /       `-.\n");
    gotoxy(0, 27);
    printf("  /          \\                      /           `-._\n");
    gotoxy(0, 28);
    printf("  `'---..__   `.                  .__.._   __       \\\n");
    gotoxy(0, 29);
    printf("           ``'''`.              .'      `'^  `''---'^\n");
    gotoxy(0, 30);
    printf("                  `-..______..-'\n");
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