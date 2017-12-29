#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "board.h"

int main(int argc, char ** argv) {
    // BOARD_2D * newBoard = create2DBoard(3);
    // BOARD2D_fill_O(newBoard, 0, 0);
    // BOARD2D_fill_X(newBoard, 1,1);
    // system("clear");
    // print2DBoard(newBoard);

    BOARD_3D * new3DBoard = create3DBoard(3);

    BOARD3D_fill_O(new3DBoard, 0,2,1);
    system("clear");
    print3DBoard(new3DBoard);
    
}