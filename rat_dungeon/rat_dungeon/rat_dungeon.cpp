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
int fight();
int item();

int main()
{
	
	int encounter = 0;
	

	srand(time(0));
	while (encounter >= 0 && encounter <= 3)
	{
		if (encounter == 0)
		{
			encounter = map();
		}

		else if (encounter == 1)
		{
			encounter = fight();
		}

		else if (encounter == 3)
		{
			encounter = item();
		}
	}

}

int map()
{

	int encounter = 0;
	int i = 0;
	int input;
	FILE *map = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/map.txt", "r+");

	while (i != EOF)
	{
		i = fgetc(map);
		putchar(i);
	}

	while(encounter != 1 && encounter != 2)
	{
		printf("\n\nWhich room would you like to explore? (select a number from the map)\n");
		scanf("%d", &input);

		if (input > 0 && input < 7)
		{
			encounter = 1;
		
		}

		else
		{
			printf("\nThere no such room number. Please enter one of the numbers on the map.\n");
		}

	}
	

	return encounter;

}

int fight()
{
	int encounter = 0;
	int input;
	printf("\nYou've encountered an enemy!\n");
	

	for (;encounter != 3;)
	{
		printf("\nPlease enter 1 to attack!\n");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("\nSuccess! You've defeated the enemy!\n");
			encounter = 3;
		}
		else
		{
			printf("\nError, please enter 1 to attack the enemy!\n");
			
		}
	}
	return encounter;

}
 
int item()
{
	int encounter = 1;

	printf("\nYou've got an item!\n");

	for (;encounter != 0;)
	{
		printf("\nPlease enter 0 to return to map.\n");
		scanf("%d", &encounter);
		if (encounter == 0)
		{
			return encounter;
		}
		else
		{
			printf("\nError: please enter 0 to return to map.\n");
		}
	}
	
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
