/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#include "Mission1.h"

/****************************************************************************************
* function name: mission1		 														*
* The Input: none																		*
* The output:none, void function														*
* The Function operation: The function checks how many of pairs of strings given by user*
*						are semi-similar, and prints the number.						*
****************************************************************************************/
void mission1() {
	int pairsNum, i, j, count = 0, pairResult;
	char source[MAX_LENGTH], target[MAX_LENGTH];

	printf("Please enter the amount of pairs:\n");
	// Input the number of pairs to be compared
	scanf("%d", &pairsNum);
	if (pairsNum > MAX_PAIRS || pairsNum < MIN_PAIRS)
		return;
	//Loop inputs the pairs of numbers and calls function to check is they are semi-similar
	for (i = 0; i < pairsNum; i++) {
		printf("Please enter the first string of pair %d:\n", i + 1);
		scanf("%s", target);
		//Checks if the input includes only letters
		for (j = 0; j < strlen(target); j++)
			if (target[j] < MIN_LETTER || target[j] > MAX_LETTER)
				return;
		printf("Please enter the second string pair %d:\n", i + 1);
		scanf("%s", source);
		//Checks if the input includes only letters
		for (j = 0; j < strlen(target); j++)
			if (source[j] < MIN_LETTER || source[j] > MAX_LETTER)
				return;

		pairResult = isSemiSimilar(target, source);
		//Checks if there was a ilegal input, if so, breaks the mission and continues the Main loop
		if (pairResult == -1)
			return;
		//Counts how many semi-similar pairs were inputed
		count += pairResult;
	}
	printf("The amount of Semi-Similar strings is %d\n", count);
	return;
}

/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1\0\-1								*
* The Function operation: The function checks if target is 				*
*						   semi-similar to source 						*
*************************************************************************/
int isSemiSimilar(char target[], char source[]){
	int i = 0, lettersCounter[LETTERS_NUM] = { 0 };

	//Loop runs untill the string (target) ends, and "balances" the counters if are semi-similar
	while (target[i] != '\0') {
		//Checks if the first string is shorter than the second
		if (source[i] == '\0')
			return 0;
		//counts how many times each letter appeared in 'target' string
		lettersCounter[target[i] - 'a']++;
		//decreases the previous counter every time the letter appears in the second string
		lettersCounter[source[i] - 'a']--;
		i++;
	}

	//Checks if the second string is shorter than the first
	if (source[i] != '\0')
		return 0;
	//Checks if all the counters are "balanced", means boths string contain excactly the same letters
	else {
		for (i = 0; i < LETTERS_NUM; i++) {
			if (lettersCounter[i] != 0)
				return 0;
		}
		return 1;
	}
}
