#ifndef MYHEADER2_H_INCLUDED
#define MYHEADER2_H_INCLUDED


//add on functions for screen console management

#include <windows.h>
#include<time.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>



/*================================================*/

//#include <stdlib.h>
void clrscr()
    {
        system("cls");
        return;
    }

/*================================================*/

//#include<time.h>
void delay(unsigned int mseconds)
    {
        clock_t goal = mseconds + clock();
        while (goal > clock());
        return;
    }

	
/*================================================*/

//#include <windows.h>
void gotoxy(int x, int y) //function definition
     {
            COORD xyPos = {0, 0};   //initialization cursor position
            xyPos.X = x;   xyPos.Y =  y;  //assign coordinates

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xyPos);
            return;
    }
	


/*================================================*/

/*================================================*/
//#include <windows.h>         //header file for windows
//#include <stdio.h>           //C standard library

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}


/*================================================*/

void textBG(int bg)
{
	printf("\033[%dm", bg);  //  set background color 

	//set to default color and background
	//printf("\033[7;0m", 7);  // set to default color 

	return;
}

/*================================================*/


void BLINK(int bi)
{

	printf("\033[%dm", bi);  //  5 and 6 blinks

	//set to default color and background
	//printf("\033[7;0m", 7);  // set to default color 

	return;
}


/*================================================*/
void colorDefault()
{
	//set to default color and background
	printf("\033[7;0m", 7);  // set to default color 

	return;
}


/*================================================*/

/*================================================*/

//blink text

void blink(){
    int i;
    clrscr();
    for(i=0; i<=5; i++)
    {
     gotoxy(50, 10);
      printf("==<<< LAGUNA UNIVERSITY >>>==");
      gotoxy(52, 8);
      printf("WELCOME");
      gotoxy(0,0);
      Sleep(200);
      getch();
     // Sleep(200);
    }
    clrscr();
    return;
}

/*================================================*/

/*================================================*/	

//#include <stdio.h>
void wait(int x)
    {
    	char msg[35] = "Loading...please wait for a while";
        for(int i = 0; i < x; i++)
        {
            gotoxy(40,20);  printf("%c", 47);  gotoxy(60,20); delay(80);
            gotoxy(40,20);  printf("%c", 196); gotoxy(60,20); delay(80);
            gotoxy(40,20);  printf("%c", 92);  gotoxy(60,20); delay(80);
            gotoxy(40,20);  printf("%c", 47);  gotoxy(60,20); delay(80);

	    gotoxy((120-strlen(msg))/ 2 + 1, 20);
            printf("%s", msg);
        }
        
        clrscr();
        return;
    }


/*================================================*/


#endif // MYHEADER2_H_INCLUDED
