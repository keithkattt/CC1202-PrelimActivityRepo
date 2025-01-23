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

int main(){
    SplashScreen();
    return 0;
}

void SplashScreen() {
    // Print each line of the splash screen with a typewriter effect
    const char *splash[] = {
    "***********************************************************************************************************\n"
    "*         .o.       ooooo        oooo    oooo ooooo   ooooo       .o.       ooooo              .o.        *",
    "*        .888.      `888'        `888   .8P'  `888'   `888'      .888.      `888'             .888.       *",
    "*       .8\"888.      888          888  d8'     888     888      .8\"888.      888             .8\"888.      *",
    "*      .8' `888.     888          88888[       888ooooo888     .8' `888.     888            .8' `888.     *",
    "*     .88ooo8888.    888          888`88b.     888     888    .88ooo8888.    888           .88ooo8888.    *",
    "*    .8'     `888.   888       o  888  `88b.   888     888   .8'     `888.   888       o  .8'     `888.   *",
    "*   o88o     o8888o o888ooooood8 o888o  o888o o888o   o888o o88o     o8888o o888ooooood8 o88o     o8888o  *",
    "***********************************************************************************************************"
    };

    for (int i = 0; i < 8; i++) {
         SetColorAndBackground(6, 0);
        print_in_style(splash[i], 1);
        putchar('\n');  // Newline after each line is printed
    }
    ResetColor();

    Sleep(10);  // Sleep for  milliseconds before the next loop 
}

void print_in_style(const char *str, int delay){
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