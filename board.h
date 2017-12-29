#ifndef BOARD_H
#define BOARD_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct board_2d BOARD_2D;
typedef struct board_3d BOARD_3D;
typedef struct board_4d BOARD_4D;

BOARD_2D * create2DBoard(int sz);
void destroy2DBoard(BOARD_2D * board);

BOARD_3D * create3DBoard(int sz);
void destroy3DBoard(BOARD_3D * board);

BOARD_4D * create4DBoard(int sz);
void destroy4DBoard(BOARD_4D * board);

int BOARD2D_fill_X(BOARD_2D * board, int x, int y);
int BOARD2D_fill_O(BOARD_2D * board, int x, int y);

int BOARD3D_fill_X(BOARD_3D * board, int x, int y, int z);
int BOARD3D_fill_O(BOARD_3D * board, int x, int y, int z);

int BOARD4D_fill_X(BOARD_4D * board, int x, int y, int z, int w);
int BOARD4D_fill_O(BOARD_4D * board, int x, int y, int z, int w);

void print2DBoard(BOARD_2D * board);
void print3DBoard(BOARD_3D * board);

#endif