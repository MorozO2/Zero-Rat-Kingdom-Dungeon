#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>
#define MAX 500
#define d4 4
#define d6 6
#define d8 8
#define d10 10
#define d20 20



int map()
{
	int rooms[6];
	int room;
	int encounter = 0;
	int i = 0;
	int j = 0;
	FILE*map = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/map.txt", "r+");

	//DISPLAYS THE MAP FOR TEXT FILE TO SCREEN
	while (i != EOF)
	{
		i = fgetc(map);
		putchar(i);
	}

	while (encounter != 1 && encounter != 2)
	{
		printf("\n\nWhich room would you like to explore? (select a number from the map)\n");
		scanf("%d", &room);

		if (room > 0 && room < 7)
		{
			
			encounter = 2;
			fclose(map);
			
		}

		else
		{
			printf("\nThere no such room number. Please enter one of the numbers on the map.\n");
		}

		rooms[j] = room;
		if (rooms[j] == room)
		{
			printf("You've explored rooms: %d", rooms[j]);
		}
		j++;
	}


	return encounter;

}

void stats()
{
	int i = 0;

	printf("\n");
	FILE*stats = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/stats.txt", "r+");

	while (i != EOF)
	{
		i = fgetc(stats);
		putchar(i);
	}
	fclose(stats);
	printf("\nHP: %d\n", playerstats.HP);
	printf("AC: %d\n\n", playerstats.AC);
}

void inventory()
{

}



