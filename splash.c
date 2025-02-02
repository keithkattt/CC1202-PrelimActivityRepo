#include <stdio.h>
#include <unistd.h> // For usleep function
#include <windows.h>
#include <conio.h>
#include <stdlib.h>


void mainSplash() {
     const char *splash[] = {
        "\t**************************************************************************************************************",
        "\t**                                                                                                          **",
        "\t**         .o.       ooooo        oooo    oooo ooooo   ooooo       .o.       ooooo              .o.         **",
        "\t**        .888.      `888'        `888   .8P'  `888'   `888'      .888.      `888'             .888.        **",
        "\t**       .8\"888.      888          888  d8'     888     888      .8\"888.      888             .8\"888.       **",
        "\t**      .8' `888.     888          88888[       888ooooo888     .8' `888.     888            .8' `888.      **",
        "\t**     .88ooo8888.    888          888`88b.     888     888    .88ooo8888.    888           .88ooo8888.     **",
        "\t**    .8'     `888.   888       o  888  `88b.   888     888   .8'     `888.   888       o  .8'     `888.    **",
        "\t**   o88o     o8888o o888ooooood8 o888o  o888o o888o   o888o o88o     o8888o o888ooooood8 o88o     o8888o   **",
        "\t**                                                                                                          **",
        "\t**************************************************************************************************************"
    };

    int splashSize = sizeof(splash) / sizeof(splash[0]);

    system("cls"); // Clear the screen
    
    SetColorAndBackground(14, 0); // Set text color to yellow and background to black
    

    // Print each line with a small delay
    for (int i = 0; i < splashSize; i++) {
        printf("%s\n", splash[i]); // Print the current line
        fflush(stdout);           // Ensure the output is displayed immediately
        usleep(90000);            // 50 milliseconds delay between lines
    }

    printf("\n\tPress any key to continue...");
    getch(); // Wait for a key press
    system("cls"); // Clear the screen

    for (int i = 0; i < sizeof(splash) / sizeof(splash[0]); i++) {
        printf("%s\n", splash[i]);
    }

    usleep(40000); // Wait for 2 seconds
    for (int i = 0; i < splashSize; i++) {
      
        printf("\033[F\033[K"); // ANSI escape codes to move cursor up and clear line
        fflush(stdout);         // Ensure output is updated immediately
        usleep(90000);          // 50 milliseconds delay between lines
    }

    
    system("cls"); // Clear the screen
    ResetColor(); // Reset text color to white and background to black
}

