/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#include "Mission2.h"

/****************************************************************************************
* function name: mission2		 														*
* The Input: none																		*
* The output:none, void function														*
* The Function operation: The function checks how many operations it takes to convert	*
*						 all the cookies to cookies with minimal required sweetness		*
*						 given by the user												*
****************************************************************************************/
void mission2() {
	int cookiesNum, sweet;
	int cookies[MAX_COOKIES];
	int i;
	int result;

	printf("Please enter the amount of cookies:\n");
	scanf("%d", &cookiesNum);
	//Check constraints
	if (cookiesNum<MIN_COOKIES || cookiesNum>MAX_COOKIES)
		return;
	printf("Please enter the minimum required sweetness:\n");
	scanf("%d", &sweet);
	//Check constraints
	if (sweet<MIN_REQUIRED_SWEETNESS || sweet>MAX_REQUIRED_SWEETNESS)
		return;
	//Loop inputs each cookie sweetness
	for (i = 0; i < cookiesNum; i++) {
		printf("Please enter cookie number %d:\n", i + 1);
		scanf("%d", &cookies[i]);
		//Check constraints
		if (cookies[i]<MIN_COOKIE_SWEETNESS || cookies[i]>MAX_COOKIE_SWEETNESS)
			return;
	}
	result = sweetCookies(cookies, cookiesNum, sweet);
	printf("The number of operations that are needed is %d\n", result);
	return;
}

/****************************************************************************************
* function name: getLeastCookieIndex		 											*
* The Input: cookies[] - array of cookies, cookiesNum - number of cookies				*
* The output: index of the smallest cookie found										*
* The Function operation: finds the smallest legit cookie, returns it's index			*
****************************************************************************************/
int getLeastCookieIndex(int cookies[], int cookiesNum) {
	int indexSaver, i, leastCookie = MAX_COOKIE_SWEETNESS;
	//Loop checks which cookie has the smallest sweetness, and stores it's index
	for (i = 0; i < cookiesNum; i++) {
		if (leastCookie > cookies[i] && cookies[i] >= 0) {
			leastCookie = cookies[i];
			indexSaver = i;
		}
	}
	return indexSaver;
}

/****************************************************************************************
* function name: sweetCookies		 													*
* The Input: cookies[] - array of cookies, cookiesNum - number of cookies,				*
*						reqSweet	- required sweetness								*	
* The output: number of operations required to increase the sweetness					*
* The Function operation: The function checks how many operations are needed to increase*
*						  the cookies' sweetness to the required by user				*
****************************************************************************************/
int sweetCookies(int cookies[], int cookiesNum, int reqSweet) {
	int leastCookie = cookies[0], secondLeast, i, badCookies, numOfCookies = cookiesNum, indexSaver = 0;

	//Main loop, runs untill all the cookies have at least "reqSweet" sweetness
	do {
		//Checks if there's one cookie left. then, how sweet it is. if sweetness<"reqSweet", returns -1, otherwise 0
		if (numOfCookies == 1)
			if (cookies[indexSaver] < reqSweet)
				return -1;
			else
				return cookiesNum - numOfCookies;

		//Initialize vairable before the next iteration
		badCookies = 0;

		//Loop counts how many cookies are not sweet enough
		for (i = 0; i < cookiesNum; i++) {
			if (cookies[i] < reqSweet && cookies[i]>0)
				badCookies++;
		}
		//If all the cookies are sweet enough, return the number of the operations needed 
		if (badCookies == 0)
			return cookiesNum - numOfCookies;

		//gets the smallest cookie and replaces it with "-1"
		indexSaver = getLeastCookieIndex(cookies, cookiesNum);
		leastCookie = cookies[indexSaver];
		cookies[indexSaver] = -1;

		//gets the second smallest cookie and replaces it with "-1"
		indexSaver = getLeastCookieIndex(cookies, cookiesNum);
		secondLeast = cookies[indexSaver];
		cookies[indexSaver] = -1;

		//Creates the new combined cookie, places it instead of the second least cookie, prints it
		cookies[indexSaver] = (2 * secondLeast) + leastCookie;
		numOfCookies--;

	} while (badCookies != 0);
}
