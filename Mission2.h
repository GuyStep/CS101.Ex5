/******************************************
*Student name: Guy Step
*Exercise name: ex5
******************************************/

#ifndef _MISSION2_H_
#define _MISSION2_H_
#include <stdio.h>
#include <string.h>
#define MAX_COOKIES 1000
#define MIN_COOKIES 1
#define MAX_COOKIE_SWEETNESS 100000
#define MIN_COOKIE_SWEETNESS 0
#define MAX_REQUIRED_SWEETNESS 10000
#define MIN_REQUIRED_SWEETNESS 0

int getLeastCookieIndex(int cookies[], int cookiesNum);
int sweetCookies(int cookies[], int cookiesNum, int reqSweet);
void mission2();

#endif