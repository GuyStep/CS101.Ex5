/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#include "Mission3.h"

/****************************************************************************************
* function name: mission3		 														*
* The Input: none																		*
* The output:none, void function														*
* The Function operation: The function checks if the string inputed by user can be		*
*						rearranged to be a palindrome, and prints it if it is possible.	*
****************************************************************************************/
void mission3() {
	char str[MAX_STR_LENGTH];
	printf("Please enter the string:\n");
	scanf("%s", str);
	canAnagram(str);
}

/************************************************************************
* function name: canAnagram 											*
* The Input: str - string containing a-z letters 						*
* The output: None														*
* The Function operation: The function prints if str can be changed to 	*
							be a polindrom								*
*************************************************************************/
void canAnagram(char str[]) {
	int letterAppearances[LETTERS_NUM] = { 0 }, i, j, k = 0, unEvenCount = 0, strLength, unEvenIndex;
	char palStr[MAX_STR_LENGTH] = { NULL };
	strLength = strlen(str);
	//Loop counts and stores how many times each letter appeared in the string, and checks if all the chars are legit
	for (i = 0; i < strLength; i++) {
		//Checks if the input includes only letters, if so breaks the mission and returns to main loop
		if (str[i] < MIN_LETTER || str[i] > MAX_LETTER)
			return;
		letterAppearances[str[i] - 'a']++;
	}

	//The loop checks how many of the letters appeared uneven number of times in the string, and stores its index
	for (i = 0; i < LETTERS_NUM; i++) {
		if (letterAppearances[i] % 2 == 1) {
			unEvenCount++;
			unEvenIndex = i;
		}
	}

	/***********************************************************************************************
	Condition checks if the string can be rearranged to a palindrome, using the algorithm:
	The maximal number of letters, who appeared uneven number of times in the string, can be 1.
	If there is one letter who appeared uneven number of times, the rest of the letters MUST appear
	even number of times.
	Example: aaaabbccc: a - 4 times, b - 2 times, c - 3 times. Can be a palindrome (aabcccbaa).
			 aaaabbbc:  a - 4 times, b - 3 times, c - 1 time. CANNOT be a palindrome (b,c uneven).
	************************************************************************************************/
	if (unEvenCount > 1) {
		printf("The string %s does not have a palindrome\n", str);
		return;
	}

	//Loop creates the new palindrome - first part
	for (i = 0; i < LETTERS_NUM; i++) {
		if (letterAppearances[i] != 0) {
			//Assigns the letter half of the times it appeared in str (other half will be assigned in the second half)
			for (j = 0; j < letterAppearances[i] / 2; j++) {
				palStr[k] = 'a' + i;
				k++;
			}
		}
	}
	//If there is a letter who appeares uneven number of times, it has to be assigned directly in the middle
	if (unEvenCount == 1) {
		palStr[k] = 'a' + unEvenIndex;
		k++;
	}
	//Loop creates the new palindrome - second part (same as first part, but the opposite order)
	for (i = LETTERS_NUM - 1; i >= 0; i--) {
		if (letterAppearances[i] != 0) {
			//Assigns the letter the other half of the times it appeared
			for (j = 0; j < letterAppearances[i] / 2; j++) {
				palStr[k] = 'a' + i;
				k++;
			}
		}
	}

	printf("The string %s has the palindrome %s\n", str, palStr);
	return;
}