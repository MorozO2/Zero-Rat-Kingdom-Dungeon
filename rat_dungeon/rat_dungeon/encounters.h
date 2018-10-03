#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>

#define lv1 1
#define lv2 2
#define lv3 3
#define lv4 4
#define lv5 5

struct
{
	int HP = 10;
	int attack = 1;
	int AC = 12;
}enemystats[4];

int enemy(int lvl)
{
	int encounter = 0;
	int input;
	bool hit = false;
	printf("\nYou've encountered an enemy!\n");

	
	printf("HP: %d", enemystats[0].HP);


	for (;encounter != 3;)
	{
		printf("\nEnter 1 to attack!\n");
		printf("\nEnter 2 to use item!\n");

		scanf("%d", &input);
		if (input == 1)
		{

			printf("\nSuccess! You've defeated the enemy!\n");

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