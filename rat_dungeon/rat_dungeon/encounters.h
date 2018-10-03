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
	int HP = 20;
	int AC = 14;
	int attack = 1;
	int potions = 0;
	int shirt = 0;
	int stick = 0;
}playerstats;


int enemy(int lvl)
{
	int encounter = 0;
	int en_HP;
	int pl_HP;
	int en_AC;
	int attack;
	int dmg = 0;
	int input;
	bool hit = false;


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

	pl_HP = enemystats.HP;

	printf("HP: %d\n", en_HP);
	printf("AC: %d\n", en_AC);
	printf("Attack: %d\n", attack);

	

	while (en_HP != 0 && pl_HP != 0)
	{
		printf("\n\nEnemy HP: %d\n",en_HP);
		printf("Your current HP is %d\n", pl_HP);

		printf("\nEnter 1 to attack!\n");
		printf("Enter 2 to use potion!\n");
		

		scanf("%d", &input);
		if (input == 1)
		{
			//ATTACK VS ENEMY
			hit = atck(1, en_AC);
			if (hit == true)
			{
				dmg = damage(1);
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
		printf("You defeated the enemy!\n");
		return 0;
	}

	else if (pl_HP <= 0)
	{
		return 4;
	}

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

