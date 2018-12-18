/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#ifndef _MISSION4_H_
#define _MISSION4_H_
#include <stdio.h>
#include <string.h>
#define MAX_BOARD_SIZE 25
#define MIN_BOARD_SIZE 1
#define MAX_ITERATIONS 100000
#define MIN_ITERATIONS 1
void mission4();
void runGame(int rows, int cols, long iterations, char board[][MAX_BOARD_SIZE]);
void loadBoard(char board[][MAX_BOARD_SIZE], int rows, int cols);
void printArr(int rows, int cols, char board[][MAX_BOARD_SIZE]);
int getNeighbors(int rows, int cols, char board[][MAX_BOARD_SIZE], int rowIndex, int j);

#endif
