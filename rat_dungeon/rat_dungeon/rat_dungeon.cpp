// rat_dungeon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>
#define d4 4
#define d6 6
#define d8 8
#define d10 10
#define d20 20

int roll(int high);
int map();

int main()
{
	
	int combat = 0;
	

	srand(time(0));

	if (combat == 0)
	{
		map();
	}

	else
	{

	}

}

int map()
{

	int i = 0;
	int input;
	FILE *map = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/map.txt", "r");

	while (i != EOF)
	{
		i = fgetc(map);
		putchar(i);
	}

	for (i = 0; i <= 6; i++)
	{
		printf("\n\nWhich room would you like to explore? (select a number from the map)\n");
	}
	

	return 0;

}





int roll(int high)
{
	int num;
	int low = 1;

	num = (rand() % (high - low + 1)) + low;

	return num;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
