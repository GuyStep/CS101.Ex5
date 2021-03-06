/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/
#include "Mission4.h"

/****************************************************************************************
* function name: mission4								*
* The Input: none									*
* The output:none, void function							*
* The Function operation: The function plays the "Game of life", gets number of rows and*
*			columns for the board from the user, number of iterations to be *
*			played, and prints the board state after the given number	*
*			of iterations.							*
****************************************************************************************/
void mission4(){
	int rowsNum, colsNum;
	long iterations;
	char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

	printf("Please enter the number of rows (n):\n");
	scanf("%d", &rowsNum);

	//Check if rows number is within the constraints
	if (rowsNum > MAX_BOARD_SIZE || rowsNum < MIN_BOARD_SIZE)
		return;
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &colsNum);

	//Check if rows number is within the constraints
	if (colsNum > MAX_BOARD_SIZE || colsNum < MIN_BOARD_SIZE)
		return;
	printf("Please enter the number of iterations (c):\n");
	scanf("%ld", &iterations);

	//Check if number of iterations is within the constraints
	if (iterations > MAX_ITERATIONS || iterations < MIN_ITERATIONS)
		return;
	printf("Please enter the board:\n");
	loadBoard(board, rowsNum, colsNum);
	runGame(rowsNum, colsNum, iterations, board);
}

/************************************************************************
* function name: runGame 						*
* The Input: rows - number of rows board has				*
*	cols - number of columns board has				*
*	board[][] - the board state at the beggining			*
*	iterations - number if iterations to be played			*
* The output: None, void function					*
* The Function operation: The function gets number of rows and columns  *
*			for the boardas parameters, number of iterations*
*			to be played, and prints the board state after  *
*			the given number of iterations.			*
************************************************************************/
void runGame(int rows, int cols, long iterations, char board[][MAX_BOARD_SIZE]) {
	int gen, i, j, neighbors, tempCellHolder, neigCounter, aliveCounter;
	char tempBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

	//Main loop that "plays" the game for the number of times was inputed by user ("c")
	for (gen = 1; gen <= iterations; gen++) {
		//Initialize variables before next iteration
		aliveCounter = 0;
		//Copies the board to another array, so that the original one can be changed for the next iteration
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++) {
				tempCellHolder = board[i][j];
				tempBoard[i][j] = tempCellHolder;
			}

		//Loop checks how many live neighbors each cell has, and changes it in the original board
		for (i = 0; i < rows; i++)
			for (j = 0; j < cols; j++) {
				neigCounter = 0;
				neigCounter = getNeighbors(rows, cols, tempBoard, i, j);

				//Block changes the cell for the next iteration according to the number of neighbors it has
				{
					if (tempBoard[i][j] == '-')
						if (neigCounter == 3) {
							board[i][j] = '*';
							aliveCounter++;
						}
					if (tempBoard[i][j] == '*') {
						if (neigCounter < 2)
							board[i][j] = '-';
						if (neigCounter == 2 || neigCounter == 3) {
							board[i][j] = '*';
							aliveCounter++;
						}
						if (neigCounter > 3)
							board[i][j] = '-';
					}
				}
			}
	//If all cells are dead, loop will stop with current number of iterations
	if (aliveCounter == 0) {
		gen++;
		break;
		}
	}

	printf("The board after %d iterations is:\n", gen - 1);
	printArr(rows, cols, board);
	return;

}

/************************************************************************
* function name: loadBoard 						*
* The Input: board[][] - the board state				*
*			rows - number of rows board has			*
*			cols - number of columns board has		*
* The output: None, void function					*
* The Function operation: The function gets the board from user		*
************************************************************************/
void loadBoard(char board[][MAX_BOARD_SIZE], int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {
			scanf(" %c", &board[i][j]);
		}
	return;
}

/************************************************************************
* function name: printArr 				 		*
* The Input: rows - number of rows board has				*
*			cols - number of columns board has		*
*			board[][] - the board state			*
* The output: None, void function					*
* The Function operation: The function prints the board			*
************************************************************************/
void printArr(int rows, int cols, char board[][MAX_BOARD_SIZE]) {
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {
			printf("%c", board[i][j]);
			if (j == cols - 1)
				printf("\n");
		}
	return;
}

/************************************************************************
* function name: getNeighbors 						*
* The Input: rows - number of rows board has				*
*	cols - number of columns board has				*
*	board[][] - the board state					*
*	rowIndex - the row index of the cell who's neigbors we check	*
*	colIndex - the column index of the cell				*
* The output: number of living neighbors the cell has 			*
* The Function operation: The function counts and return how many living*
*			neighbors given cell has			*
************************************************************************/
int getNeighbors(int rows, int cols, char board[][MAX_BOARD_SIZE], int rowIndex, int colIndex) {
	int neigCounter = 0;
	//Cell above
	if(board[getCell(rowIndex - 1,rows)][colIndex]=='*')
		neigCounter++;
	//Cell below
	if (board[getCell(rowIndex + 1, rows)][colIndex] == '*')
		neigCounter++;
	//Cell to the left
	if (board[rowIndex][getCell(colIndex-1,cols)] == '*')
		neigCounter++;
	//Cell to the right
	if (board[rowIndex][getCell(colIndex + 1, cols)] == '*')
		neigCounter++;
	//Cell in the right lower corner
	if (board[getCell(rowIndex + 1, rows)][getCell(colIndex + 1, cols)] == '*')
		neigCounter++;
	//Cell in the right upper corner
	if (board[getCell(rowIndex - 1, rows)][getCell(colIndex + 1, cols)] == '*')
		neigCounter++;
	//Cell in the left upper corner
	if (board[getCell(rowIndex - 1, rows)][getCell(colIndex - 1, cols)] == '*')
		neigCounter++;
	//Cell in the left lower corner
	if (board[getCell(rowIndex + 1, rows)][getCell(colIndex - 1, cols)] == '*')
		neigCounter++;

	//Return the number of "living" neighbors
	return neigCounter;
}

/************************************************************************
* function name: getCell 						*
* The Input: cellNumber - number of rows board has			*
*			boardSize - number of columns\rows		*				
* The output: Updated cell index					*
* The Function operation: The function treats special cases of		*
*						cell positions.		*
************************************************************************/
int getCell(int cellNumber, int boardSize) {
	if (cellNumber < boardSize && cellNumber>0)
		return cellNumber;
	else if (cellNumber < 0) 
		return (boardSize + cellNumber);
	else return cellNumber % (boardSize);
}
