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
	int HP = 10;
	int attack = 1;
	int AC = 12;
}enemystats[4];

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
	int HP = enemystats->HP;
	int AC = enemystats->AC;
	int attack = enemystats->attack;
	int dmg= 0;
	int input;
	bool hit = false;


	printf("\nYou've encountered an enemy!\n");
	if (lvl > 1)
	{
		enemystats[lvl - 1].HP = enemystats[lvl - 1].HP * enemy_scale(lvl);
		enemystats[lvl - 1].AC = enemystats[lvl - 1].AC * enemy_scale(lvl);
		enemystats[lvl - 1].attack = enemystats[lvl - 1].attack * enemy_scale(lvl);

		HP = enemystats[lvl - 1].HP;
		AC = enemystats[lvl - 1].AC;
		attack = enemystats[lvl - 1].attack;
		
		printf("HP: %d\n", HP);
		printf("AC: %d\n", AC);
		printf("Attack: %d\n", attack);

	}
	else
	{
		printf("HP: %d\n", HP);
	}

	

	while (HP > 0 || playerstats.HP > 0)
	{
		printf("\nEnter 1 to attack!\n");
		printf("Enter 2 to use potion!\n");
		printf("\nEnemy HP: %d\n", HP);

		scanf("%d", &input);
		if (input == 1)
		{
			//ATTACK VS ENEMY
			hit = atck(1, AC);
			if (hit == true)
			{
				dmg = damage(1);
				HP = HP - dmg;
				printf("You deal %d damage to the enemy\n", dmg);
			}
							
		}
		else if (input == 2)
		{
			printf("You've used a potion");

		}

		else
		{
			printf("\nError, please enter 1 to attack the enemy!\n");
		}
		 //Attack VS PLAYER
		if (HP > 0)
		{
			printf("The level %d Rat Grunt attacks!\n", lvl);
			hit = atck(1, playerstats.AC);
			if (hit == true)
			{
				dmg = damage(1);
				playerstats.HP = playerstats.HP - dmg;
				printf("Your current HP is %d\n", playerstats.HP);
			}
		}

	
	}

	if (HP <= 0 || HP <= (-1))
	{
		printf("You defeated the enemy!\n");
		return 0;
	}

	else if (playerstats.HP <= 0 || playerstats.HP <= (-1))
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

