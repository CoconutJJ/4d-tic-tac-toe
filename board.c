#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * 2 Dimensional Board
 * array of integer arrays.
 * [
 *  [ , , , ]
 *  [ , , , ]
 *  [ , , , ]
 * ]
 * 
 */
typedef struct board_2d {
    int ** rows;
    int sz;
} BOARD_2D;

/**
 * Array of 2D Boards as layers
 */
typedef struct board_3d {
    BOARD_2D ** layers;
    int sz;
} BOARD_3D;

/**
 * Array of 3d Boards as Cubes
 */
typedef struct board_4d {
    BOARD_3D ** cubes;
    int sz;
} BOARD_4D;

/**
 * Allocates space in memory to create a 2D Board
 */
BOARD_2D * create2DBoard(int sz){
    BOARD_2D * new_2d_board = malloc(sizeof(BOARD_2D));
    new_2d_board->rows = malloc(sz * sizeof(int *));
    for (int i = 0; i < sz; i++) {
        new_2d_board->rows[i] = malloc(sz * sizeof(int));
        for (int j = 0; j < sz; j++){
            new_2d_board->rows[i][j] = 0;
        }
    }
    new_2d_board->sz = sz;
    return new_2d_board;
}
/**
 * De-allocates the memory used by the 2D Board
 */
void destroy2DBoard(BOARD_2D * board) {
    for (int i = 0; i < board->sz; i++){
        free(board->rows[i]);
    }
    free(board->rows);
    free(board);
}
/**
 * Allocates space in memory to create a 3D Board
 */
BOARD_3D * create3DBoard(int sz) {
    BOARD_3D * new_3d_board = malloc(sizeof(BOARD_3D));
    new_3d_board->layers = malloc(sz * sizeof(BOARD_2D *));
    for (int i = 0; i < sz; i++) {
        new_3d_board->layers[i] = create2DBoard(sz);
    }
    new_3d_board->sz = sz;
    return new_3d_board;
}
/**
 * De-allocates the memory used by the 3D Board
 */
void destroy3DBoard(BOARD_3D * board) {
    for(int i = 0; i < board->sz; i++){
        destroy2DBoard(board->layers[i]);
    }
    free(board->layers);
    free(board);
}

/**
 * Allocates memory to create a 4D Board
 */
BOARD_4D * create4DBoard(int sz){
    BOARD_4D * new_4d_board = malloc(sizeof(BOARD_4D));
    new_4d_board->cubes = malloc(sz * sizeof(BOARD_3D *));
    for (int i = 0; i < sz; i++){
        new_4d_board->cubes[i] = create3DBoard(sz);
    }
    new_4d_board->sz = sz;
    return new_4d_board;
}
/**
 * De-allocates memory used by 4D Board
 */
void destroy4DBoard(BOARD_4D * board){
    for (int i = 0; i < board->sz; i++) {
        destroy3DBoard(board->cubes[i]);
    }
    free(board->cubes);
    free(board);
}

int BOARD2D_fill_X(BOARD_2D * board, int x, int y){
    if (y < board->sz && x < board->sz) {
        if(board->rows[y][x] == 0) {
            board->rows[y][x] = 1;
            return 1;
        } else {
            return 0;
        }
    } else {
        fprintf(stderr, "error: coord x y > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD2D_fill_O(BOARD_2D * board, int x, int y){
    if (y < board->sz && x < board->sz) {
        if(board->rows[y][x] == 0) {
            board->rows[y][x] = 2;
            return 1;
        } else {
            return 0;
        }
    } else {
        fprintf(stderr, "error: coord x y > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD3D_fill_X(BOARD_3D * board, int x, int y, int z) {
    if (z < board->sz) {
        return BOARD2D_fill_X(board->layers[z], x, y);
    } else {
        fprintf(stderr, "error: coord z > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD3D_fill_O(BOARD_3D * board, int x, int y, int z) {
    if (z < board->sz) {
        return BOARD2D_fill_O(board->layers[z], x, y);
    } else {
        fprintf(stderr, "error: coord z > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD4D_fill_X(BOARD_4D * board, int x, int y, int z, int w) {
    if (w < board->sz) {
        return BOARD3D_fill_X(board->cubes[w], x, y, z);
    } else {
        fprintf(stderr, "error: coord w > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD4D_fill_O(BOARD_4D * board, int x, int y, int z, int w) {
    if (w < board->sz) {
        return BOARD3D_fill_O(board->cubes[w], x, y, z);
    } else {
        fprintf(stderr, "error: coord w > board->sz");
        exit(EXIT_FAILURE);
    }
}

void print2DBoard(BOARD_2D * board) {
    // manages the rows
    for (int k = 0; k < board->sz; k++) {
        printf(" |");
        // manages the columns
        for (int i = 0; i < board->sz; i++) {
            
            for (int j = 0; j < 3; j++) {

                if (j == 2) {
                    if (board->rows[k][i] == 1){
                        printf("X");
                    } else if (board->rows[k][i] == 2) {
                        printf("O");
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("|");
        }
        printf("\n");
        for (int i = 0; i < board->sz; i++) {
            printf("---");
        }
        printf("\n");
    }
}

void print3DBoard(BOARD_3D * board) {
    for (int i = 0; i < board->sz; i++) {
        printf("Layer %d:\n",i);
        print2DBoard(board->layers[i]);
        printf("\n");

    }
}

int BOARD_2D_hasEntry(BOARD_2D * board, int x, int y){
    if (y < board->sz && x < board->sz){
        if (board->rows[y][x] != 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        fprintf(stderr, "error: board_*D_hasEntry: coord x y > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD_3D_hasEntry(BOARD_3D * board, int x, int y, int z){
    if (z < board->sz){
        return BOARD_2D_hasEntry(board->layers[z], x, y);
    } else {
        fprintf(stderr, "error: board_*D_hasEntry: coord z > board->sz");
        exit(EXIT_FAILURE);
    }
}

int BOARD_4D_hasEntry(BOARD_4D * board, int x, int y, int z, int w) {
    if (w < board->sz) {
        return BOARD_3D_hasEntry(board->cubes[w], x, y, z);
    } else {
        fprintf(stderr, "error: board_*D_hasEntry: coord w > board->sz");
        exit(EXIT_FAILURE);
    }
}