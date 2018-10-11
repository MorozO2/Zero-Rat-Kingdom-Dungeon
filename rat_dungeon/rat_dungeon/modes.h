#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#include <time.h>
#pragma warning(disable:4996)

int map();
void stats();
void item(int lvl);


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
			
			encounter = 1;
			fclose(map);
			
		}

		else
		{
			printf("\nThere no such room number. Please enter one of the numbers on the map.\n");
		}

		/*rooms[j] = room;
		if (rooms[j] == room)
		{
			printf("You've explored rooms: %d", rooms[j]);
		}
		j++;*/
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
	printf("\nHP: %d/%d\n", playerstats.temp_HP, playerstats.max_HP);
	printf("AC: %d\n", playerstats.AC);
	printf("Attack: +%d\n", playerstats.attack);
	printf("Healing Potions: %d\n", playerstats.potions);
	printf("stick: %d\n", items.stick);
	printf("shield: %d\n", items.shield);
	printf("shirt: %d\n", items.shirt);
	printf("current level: %d\n", items.c_level);


	if (playerstats.stick > 0)
	{
		printf("Weapon: +%d Twatting Stick\n", playerstats.stick);
	}
	
	if (playerstats.shirt > 0)
	{
		printf("Armor: +%d Shirt\n", playerstats.shirt);
	}
	
	if (playerstats.shield > 0)
	{
		printf("Shield: +%d Rat Shield\n\n", playerstats.shield);
	}

	
}

//FUNCTION FOR GIVING PLAYER ITEMS
void item(int lvl)
{
	int potion = 0;
	int item = 0;
	int input = 0;
	if (lvl > items.c_level)
	{
		items.stick = 0;
		items.shirt = 0;
		items.shield = 0;
	}
	items.c_level = lvl;

	//ROLLS TO SEE IF PLAYER GETS A POTION
	potion = roll(2);
	if (potion == 1)
	{
		playerstats.potions = playerstats.potions + 1;
		printf("\nYou've got a potion!\n");
	}

	//ROLLS TO SEE IF PLAYER GETS 1 OF 3 ITEMS
	item = roll(3);
	if (item == 1 && items.stick == 0)
	{
		playerstats.stick = playerstats.stick + 1;
		printf("\nYou received a +%d Twatting Stick\n\n", lvl);
		playerstats.attack = playerstats.attack + playerstats.stick;
		items.stick = 1;
	}

	else if (item == 2 && items.shirt == 0)
	{
		playerstats.shirt = playerstats.shirt + 1;
		printf("\nYou received a +%d Shirt", lvl);
		playerstats.max_HP = playerstats.max_HP + playerstats.shirt * 2;
		items.shirt = 1;
	}

	else if (item == 3 && items.shield == 0)
	{

		playerstats.shield = playerstats.shield + 1;
		printf("\nYou received a +%d Rat Shield", lvl);
		playerstats.AC = playerstats.AC + playerstats.shield;
		items.shield = 1;
	}

	printf("\nPlease enter 1 to exit the room.\n");
	scanf("%d",&input);
}



