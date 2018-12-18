/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#include "Mission1.h"
#include "Mission2.h"
#include "Mission3.h"
#include "Mission4.h"
#include "Mission5.h"

void main()
{
	int missionNum;			// The mission number
	printf("Please enter the mission number:\n");
	scanf("%d", &missionNum);		// Reading the mission number

	while (missionNum <= 5 && missionNum >= 1)
	{
		switch (missionNum)
		{
		case 1: mission1();		// Run the appropriate mission
			break;
		case 2: mission2();		// Run the appropriate mission
			break;
		case 3: mission3();		// Run the appropriate mission
			break;
		case 4: mission4();		// Run the appropriate mission
			break;
		case 5: mission5();		// Run the appropriate mission
			break;
		default: // do nothing
			break;
		}
		printf("Please enter the mission number:\n");
		scanf("%d", &missionNum);		// Reading the mission number
	}
}