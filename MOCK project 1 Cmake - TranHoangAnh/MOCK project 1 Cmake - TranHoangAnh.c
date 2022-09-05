// MOCK project 1 Cmake - TranHoangAnh.cpp : Defines the entry point for the application.
//

#include "MOCK project 1 Cmake - TranHoangAnh.h"

#define ANSI_COLOR_GREEN "\x1b[32m"

int numbOfDay;

matrix_position rotApplePosArray[] = {
	{2, 2},
	{1, 1},
	{3, 3},
	{4, 4},
	{5, 5}};
uint32_t numberOfRotten = 5;

int main()
{
	printf("\n");
	numbOfDay = rotAllAppleMainFunction(5, 5, rotApplePosArray, numberOfRotten);
	printf("===============================================");
	printf("\n");
	printf(ANSI_COLOR_GREEN "[All apple have been rotten in %d days]     ", numbOfDay);
	printf("\n");
	printf("\n");
	printf("===============================================");

	return 0;
}
