#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>

struct enemy
{
	int HP = 15;
	int AC = 12;
	int attack = 1;
}enemystats;

struct player
{
	
	int potions = 0;
	int shirt = 0;
	int stick = 0;
	int shield = 0;
	int HP = 20 + shirt;
	int AC = 14 + shield;
	int attack = 1 + stick;
}playerstats;

struct items
{
	int	c_level = 0;
	int shirt = 0; 
	int shield = 0;
	int stick = 0;
}items;

void item(int lvl);

//MAIN COMBAT FUNCTION
int enemy(int lvl)
{
	int encounter = 0;
	int en_HP;
	int pl_HP;
	int en_AC;
	int attack;
	int dmg = 0;
	int input;
	int i = 0;
	bool hit = false;

	FILE*cmenu = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/combat.txt", "r");

	printf("\nYou've encountered an enemy!\n");
	if (lvl > 1)
	{
		//SCALES THAT ENEMY STATS IN ACCORDANCE WITH THE LEVEL
		enemystats.HP = enemystats.HP * enemy_scale(lvl);
		enemystats.AC = enemystats.AC * enemy_scale(lvl);
		enemystats.attack = enemystats.attack * enemy_scale(lvl);
	}

	//ASSIGNS ENEMY AND PLAYER STATS TO VARIABLES
	en_HP = enemystats.HP;
	en_AC = enemystats.AC;
	attack = enemystats.attack;

	pl_HP = playerstats.HP;

	printf("HP: %d\n", en_HP);
	printf("AC: %d\n", en_AC);
	printf("Attack: %d\n", attack);

	

	while (en_HP != 0 && pl_HP != 0)
	{
		printf("\n\nEnemy HP: %d\n",en_HP);
		printf("Your current HP is %d\n", pl_HP);

		while (i != EOF)
		{
			i = fgetc(cmenu);
			putchar(i);
		}

		

		printf("\n");
		scanf("%d", &input);
		printf("\n");

		i = 0;
		if (input == 1)
		{
			//ATTACK VS ENEMY
			hit = atck(1, en_AC);
			if (hit == true)
			{
				dmg = damage(10);
				en_HP = en_HP - dmg;
				printf("\nYou deal %d damage to the enemy\n", dmg);
			}
							
		}
		else if (input == 2)
		{
			printf("You've used a potion\n");

		}

		else
		{
			printf("\nError, please enter 1 to attack the enemy!\n");
		}
		 //Attack VS PLAYER
		if (en_HP > 0)
		{
			printf("\nThe level %d Rat Grunt attacks!\n", lvl);
			hit = atck(1, playerstats.AC);
			if (hit == true)
			{
				dmg = damage(1);
				pl_HP = pl_HP - dmg;
				playerstats.HP = pl_HP;
				
			}
		}
	
		if (en_HP < 0)
		{
			en_HP = 0;
		}

		if (pl_HP < 0)
		{
			pl_HP = 0;
		}
	
	}
	

	if (en_HP <= 0)
	{
		en_HP = 0;
		printf("\nYou defeated the enemy!\n");
		item(lvl);
		return 0;
	}

	else if (pl_HP <= 0)
	{
		return 4;
	}

}
	



void item(int lvl)
{
	int potion = 0;
	int item = 0;
	
	if (lvl > items.c_level)
	{
		items.stick = 0;
		items.shirt = 0;
		items.shield = 0;
	}
	items.c_level = lvl;
		
	potion = roll(2);
	if (potion == 1)
	{
		playerstats.potions = playerstats.potions + 1;
		printf("\nYou've got a potion!\n");		
	}

	if (roll(2) == 1)
	{
		item = roll(3);

		if (item == 1 && items.stick == 0)
		{
			playerstats.stick = playerstats.stick + 1;
			printf("\nYou received a +%d Twatting Stick\n\n", lvl);
			items.stick = 1;
		}

		else if (item == 2 && items.shirt == 0)
		{

			playerstats.shirt = playerstats.shirt + 1;
			printf("\nYou received a +%d Shirt", lvl);
			items.shirt = 1;

		}

		else if (item == 3 && items.shield == 0)
		{

			playerstats.shield = playerstats.shield + 1;
			printf("\nYou received a +%d Rat Shield", lvl);
			items.shield = 1;
		}
	}
}

