#include "board.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void board2dgame(int board_sz) {}

void board3dgame(int board_sz) {}

void board4dgame(int board_sz) {}

int main(int argc, char **argv) {
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

      char brd_sz[3];

    printf("Please select a board size: [1...10]");

    fgets(brd_sz, 3, stdin);

    int sz = (int) strtol(brd_sz, NULL, 10);

    char brd_dim[2];
    printf("Please select board dimension: [2-4]");

    fgets(brd_dim, 2, stdin);

  } else if (strcmp(response, NO) == 0) {

    system("clear");
    printf("Bye.");
    exit(EXIT_SUCCESS);

  } else {
    printf("Was I not clear enough that your response should be 'y' or 'n' ?! \n");
  }
}