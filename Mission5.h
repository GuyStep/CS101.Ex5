/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#ifndef _MISSION5_H_
#define _MISSION5_H_
#include <stdio.h>
#include <string.h>
#define MAX_BOARD_SIZE 25
#define MIN_BOARD_SIZE 1
#define MIN_COORDINATE 0
void loadCastleBoard(int rows, int cols, char board[][MAX_BOARD_SIZE]);
int getMin(int num1, int num2, int num3, int num4);
int getMinLength(int row, int col, int goalR, int goalC, int boardSize, char board[][MAX_BOARD_SIZE]);
void mission5();

#endif