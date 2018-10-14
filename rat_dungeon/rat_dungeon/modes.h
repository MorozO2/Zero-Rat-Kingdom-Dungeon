#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#include <time.h>
#pragma warning(disable:4996)

int map(int lvl);
void stats();
void item(int lvl);

//FUNCTION DISPLAYS MAP AND ASK PLAYER WHAT HE WANTS TO DO
int map(int lvl)
{
	int rested = 0;
	int input;
	int encounter = 0;
	int i = 0;
	FILE*map = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/map.txt", "r");

	//DISPLAYS THE MAP FOR TEXT FILE TO SCREEN
	while (i != EOF)
	{
		i = fgetc(map);
		putchar(i);
	}

	//MAKES SURE THAT THE PLAYER CAN REST MORE THAN ONCE PER ROOM CLEAR
	if (lvl > items.c_level)
	{
		rested = 0;
	}

	//ASKS PLAYER TO INPUT EITHER 1 OR 2 TO DETERMINE NEXT ACTION
	while (encounter != 1 && encounter != 2)
	{

		
		printf("\n\nEnter 1 to explore a room\n");

		printf("\nEnter 2 to take a short rest\n");

		scanf("%d", &input);
		
		if (input == 1)
		{
			encounter = input;
			return encounter;
		}
		//PLAYER CAN TAKE A REST IF rested BOOLEAN IS 0 (ENSURING ONLY ONE REST PER ROOM)
		else if (input == 2 && rested == 0)
		{
			//CALLS HEALING FUNCTION TO RESTORE PLAYER'S HEALTH
			playerstats.temp_HP = playerstats.temp_HP + healing(d6, lvl);
			//CHECK THAT HP DOESN'T GO OVER MAXIMUM
			if (playerstats.temp_HP > playerstats.max_HP)
			{
				playerstats.temp_HP = playerstats.max_HP;
			}

			printf("\nYour current HP is %d/%d\n", playerstats.temp_HP, playerstats.max_HP);
			rested = 1;
		}
		else if(rested == 1)
		{
			printf("\nYou've already rested.\n");
		}

	}
	fclose(map);
}

//FUCNTION PRINTS CHARATER STATS TO THE SCREEN
void stats()
{
	int i = 0;

	printf("\n");
	//PRINTS OUT PLAYER STATS
	FILE*stats = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/stats.txt", "r+");
	while (i != EOF)
	{
		i = fgetc(stats);
		putchar(i);
	}
	fclose(stats);
	printf("\n%s\n", playerstats.name);
	printf("HP: %d/%d\n", playerstats.temp_HP, playerstats.max_HP);
	printf("AC: %d\n", playerstats.AC);
	printf("Attack: +%d\n", playerstats.attack);
	printf("Rat Potions: %d\n", playerstats.potions);
	
	//IF PLAYER HAS 1 OR MORE ITEMS, DISPLAY THOSE ON THE STATS SCREEN
	if (playerstats.stick > 0)
	{
		printf("\nWeapon: +%d Twatting Stick\n", playerstats.stick);
	}
	
	if (playerstats.shirt > 0)
	{
		printf("Armor: +%d Rat Shirt\n", playerstats.shirt);
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
	//CHECK IF PLAYER MOVED ONTO THE NEXT FLOOR. IF SO, RESETS BOOLEANS SO THAT NEW ITEMS WOULD DROP
	if (lvl > items.c_level)
	{
		items.stick = 0;
		items.shirt = 0;
		items.shield = 0;
		items.c_level = lvl;
	}
	

	//ROLLS TO SEE IF PLAYER GETS A POTION
	potion = roll(2);
	if (potion == 1)
	{
		playerstats.potions = playerstats.potions + 1;
		printf("\nYou've got a disgusting-looking Rat Potion!\n");
	}

	//ROLLS TO SEE IF PLAYER GETS 1 OF 3 ITEMS
	item = roll(3);
	//CHECK THE ITEM BOOLEANS TO ENSURE THAT PLAYER GETS MAX 1 OF EACH ITEM PER FLOOR
	if (item == 1 && items.stick == 0)
	{
		playerstats.stick = playerstats.stick + 1;
		printf("\nYou received a +%d Twatting Stick\n\n", lvl);
		playerstats.attack = playerstats.attack + 1;
		items.stick = 1;
	}

	else if (item == 2 && items.shirt == 0)
	{
		playerstats.shirt = playerstats.shirt + 1;
		printf("\nYou received a +%d Rat Shirt", lvl);
		playerstats.max_HP = playerstats.max_HP + 4;
		items.shirt = 1;
	}

	else if (item == 3 && items.shield == 0)
	{

		playerstats.shield = playerstats.shield + 1;
		printf("\nYou received a +%d Rat Shield", lvl);
		playerstats.AC = playerstats.AC + 1;
		items.shield = 1;
	}

	printf("\nPlease enter 1 to exit the room.\n");
	scanf("%d",&input);
}



