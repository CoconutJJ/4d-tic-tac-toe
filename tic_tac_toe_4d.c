#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "board.h"


int main(int argc, char ** argv) {
    system("clear");
    printf("=======================================================\n");
    printf("               WELCOME TO N-D TIC TAC TOE              \n");
    printf("This is a 2-Player Game. There is no AI component to   \n");
    printf("this game as in 4D that would be a mess and a 2D AI    \n");
    printf("would be remarkably difficult. - David                 \n");
    printf("=======================================================\n");
    printf("Would you like to begin? [y/n] \n");
    
    char response[2];
    char * YES = "y";
    char * NO = "n";
    
    fgets(response, 2, stdin);
    if (strcmp(response, YES) == 0) {
            
    } else if (strcmp(response, NO) == 0) {
        system("clear");
        printf("Bye.");
        exit(EXIT_SUCCESS);
    } else {
        printf("Was I not clear enough that your response should be 'y' or 'n' ?! \n");   
    }


}