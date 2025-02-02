#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

#define ENTER_KEY 13
#define UP_ARROW 72
#define DOWN_ARROW 80


void wizard(); //Displays Merlin the Wizard
void numberTricksMenu(); //Main menu algorithm for number trick
void inputMenuChoice(int choice); //Displays and updates main menu
void textBubble(); //text bubbles for Merlin the Wizard
void numberTricksHeader();
void numberTricksRound ();

void mainNumberTricks(){
    numberTricksMenu();
}

void numberTricksRound() {
    system("cls");
    wizard();
    textBubble();
    system("cls");
}

void numberTricksMenu(){
    system("cls");
    int choice = 1;
    char key;

    while (1){
        numberTricksHeader();
        inputMenuChoice(choice);
        
        key = _getch();

        if (key == UP_ARROW) {
                choice--;
            if (choice < 1){
                choice = 2;
            } 
        } else if (key == DOWN_ARROW) {
            choice++;

            if (choice > 2){
                choice = 1;
            }
        } else if (key == ENTER_KEY) {
            
            switch(choice) {
                case 1:
                    gotoxy(52, 17);
                    PrintEffect("Starting Number Tricks...\n", 10);
                    usleep(1000000);  // Delay for 1 second
                    system("cls");

                    numberTricksRound();
                    break;
                case 2:
                
                    gotoxy(52, 17);
                    PrintEffect("Exiting Number Tricks...\n", 10);
                    usleep(1000000);  // Delay for 1 second

                    system("cls");
                    return;

                default:
                    PrintEffect("Invalid choice. Please try again.\n", 5);
            }
        }
    }
}

void inputMenuChoice(int choice){
    if (choice == 1){
        gotoxy(50, 13);
        SetColorAndBackground(9, 0);
        printf("-> 1. Start Number Tricks");
        ResetColor();
    } else {
        gotoxy(50, 13);
        printf("   1. Start Number Tricks");
    }

    if (choice == 2){
        gotoxy(50, 14);
        SetColorAndBackground(9, 0);
        printf("-> 2. Exit Number Tricks");
        ResetColor();
    } else {
        gotoxy(50, 14);
        printf("   2. Exit Number Tricks");
    }
}

void numberTricksHeader(){
    
    SetColorAndBackground(9, 0);
    gotoxy(5, 0); printf(" /$$   /$$                         /$$                                   /$$               /$$           /$$                ");
    gotoxy(5, 1); printf("| $$$ | $$                        | $$                                  | $$              |__/          | $$                ");
    gotoxy(5, 2); printf("| $$$$| $$ /$$   /$$ /$$$$$$/$$$$ | $$$$$$$   /$$$$$$   /$$$$$$        /$$$$$$    /$$$$$$  /$$  /$$$$$$$| $$   /$$  /$$$$$$$");
    gotoxy(5, 3); printf("| $$ $$ $$| $$  | $$| $$_  $$_  $$| $$__  $$ /$$__  $$ /$$__  $$      |_  $$_/   /$$__  $$| $$ /$$_____/| $$  /$$/ /$$_____/");
    gotoxy(5, 4); printf("| $$  $$$$| $$  | $$| $$ \\ $$ \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/        | $$    | $$  \\__/| $$| $$      | $$$$$$/ |  $$$$$$ ");
    gotoxy(5, 5); printf("| $$\\  $$$| $$  | $$| $$ | $$ | $$| $$  | $$| $$_____/| $$              | $$ /$$| $$      | $$| $$      | $$_  $$  \\____  $$");
    gotoxy(5, 6); printf("| $$ \\  $$|  $$$$$$/| $$ | $$ | $$| $$$$$$$/|  $$$$$$$| $$              |  $$$$/| $$      | $$|  $$$$$$$| $$ \\  $$ /$$$$$$$/");
    gotoxy(5, 7); printf("|__/  \\__/ \\______/ |__/ |__/ |__/|_______/  \\_______/|__/               \\___/  |__/      |__/ \\_______/|__/  \\__/|_______/ ");
    gotoxy(5, 8); printf("                                                                                                                            ");
    gotoxy(5, 9); printf("                                                                                                                            ");
    gotoxy(5, 10); printf("                                                                                                                            ");
    ResetColor();

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
    usleep(800000); 
    gotoxy(41, 1);
    printf("<  The outcome would be.    >"); 
    usleep(800000); 
    gotoxy(41, 1);
    printf("<  The outcome would be..   >"); 
    usleep(800000); 
    gotoxy(41, 1);
    printf("<  The outcome would be...  >");

    getch();

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

    _getch();
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
