/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#include "Mission5.h"

/************************************************************************
* function name: mission5 												*
* The Input: none, void function										*
* The output: none, void function										*
* The Function operation: The function loads a board from user, finds 	*
*						and returns the	minimal number of steps to reach*
*						the goal cell from origin cell,					*
*						while avoiding obstacles						*
*************************************************************************/
void mission5(){
	int boardSize;
	char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
	int startX, startY, goalX, goalY, result;

	printf("Please enter the number of rows and columns (n):\n");
	scanf("%d", &boardSize);
	if (boardSize > MAX_BOARD_SIZE || boardSize < MIN_BOARD_SIZE)
		return;
	printf("Please enter the X of the starting position:\n");
	scanf("%d", &startX);
	if (startX >= boardSize || startX < MIN_COORDINATE)
		return;
	printf("Please enter the Y of the starting position:\n");
	scanf("%d", &startY);
	if (startY >= boardSize || startY < MIN_COORDINATE)
		return;
	printf("Please enter the X of the goal position:\n");
	scanf("%d", &goalX);
	if (goalX >= boardSize || goalX < MIN_COORDINATE)
		return;
	printf("Please enter the Y of the goal position:\n");
	scanf("%d", &goalY);
	if (goalY >= boardSize || goalY < MIN_COORDINATE)
		return;
	printf("Please enter the grid:\n");
	// Reading the Board
	loadCastleBoard(boardSize, boardSize, board);		
	
	// Getting the minimum steps to the goal
	result = getMinLength(startX, startY, goalX, goalY, boardSize, board);	
	if (result != -1) {
		printf("The minimum number of steps is %d\n", result);
	}
	else {
		printf("No path was found from (%d,%d) to (%d,%d)\n", startX, startY, goalX, goalY);
	}
}

/************************************************************************
* function name: getMinLength 											*
* The Input: row - the current row we are on							*
*			col - the current column we are on							*
*			goalR - the goal row										*
*			goalC - the goal column										*
*			boardSize - rows and columns in the board					*
*			board[][] - the board we are working on						*
* The output: minimal number of steps									*
* The Function operation: The recursive function finds and returns the	*
*						minimal number of steps to reach the goal cell	*
*						from origin cell, while avoiding obstacles		*	
************************************************************************/
int getMinLength(int row, int col, int goalR, int goalC, int boardSize, char board[][MAX_BOARD_SIZE]) {
	int movesUp = 0, movesDown = 0, movesRight = 0, movesLeft = 0, blockedDirection = 0, minMoves = 0;
	
	//Stopping condition
	if (row == goalR && col == goalC) 
		return 0;
	else
		//Mark current cell as blocked (because visited, to not have a infinte recursion)
		board[row][col] = 'x';
	//Check moves to each direction
	{
		//Go Right
		if (col < boardSize - 1 && board[row][col + 1] == '-') 
			movesRight = 1 + getMinLength(row, col + 1, goalR, goalC, boardSize, board);
		else
			blockedDirection++;

		//Go up
		if (row > 0 && board[row - 1][col] == '-')
			movesUp = 1 + getMinLength(row - 1, col, goalR, goalC, boardSize, board);
		else
			blockedDirection++;

		//Go Down
		if (row < boardSize - 1 && board[row + 1][col] == '-')
			movesDown = 1 + getMinLength(row + 1, col, goalR, goalC, boardSize, board);
		else
			blockedDirection++;

		//Go Left
		if (col > 0 && board[row][col - 1] == '-') 
			movesLeft = 1 + getMinLength(row, col - 1, goalR, goalC, boardSize, board);
		else
			blockedDirection++;

		//Un-Mark the visited cells, to let the next direction run freely and check all the available options
		board[row][col] = '-';

		//If there are no options left - all directions are blocked
		if (blockedDirection == 4 && row != goalR && col != goalC)
			return -1;
	}
	minMoves = getMin(movesUp, movesDown, movesLeft, movesRight);

	return minMoves;
}

/************************************************************************
* function name: getMin 												*
* The Input: num1 - number of steps (Up direction)						*
*			num1 - number of steps (Down direction)						*
*			num1 - number of steps (Left direction)						*
*			num1 - number of steps (Right direction)					*
* The output: minimal number of all 4									*
* The Function operation: The function finds and returns the minimal num*
************************************************************************/
int getMin(int num1, int num2, int num3, int num4) {
	//Just a random high number that can't be the steps number
	int minimum = 999999;
	if (num1 + num2 + num3 + num4 == 0)
		return -1;
	if (num1 < minimum && num1 != 0)
		minimum = num1;
	if (num2 < minimum && num2 != 0)
		minimum = num2;
	if (num3 < minimum && num3 != 0)
		minimum = num3;
	if (num4 < minimum && num4 != 0)
		minimum = num4;
	return minimum;
}

/************************************************************************
* function name: loadCastleBoard 										*
* The Input: board[][] - the board state								*
*			rows - number of rows board has								*
*			cols - number of columns board has							*
* The output: None, void function										*
* The Function operation: The function gets the board from user	as input*
************************************************************************/
void loadCastleBoard(int rows, int cols, char board[][MAX_BOARD_SIZE]) {
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {
			scanf(" %c", &board[i][j]);
		}
	return;
}
