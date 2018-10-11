#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>

void item(int lvl);
int combat(int lvl);

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
	int max_HP = 20;
	int temp_HP = 20;
	int AC = 14;
	int attack = 1;
}playerstats;

struct items
{
	int	c_level = 1;
	int shirt = 0; 
	int shield = 0;
	int stick = 0;
}items;



//FUNCTION FOR DETERMINING THE ENCOUNTER
int enc(int lvl)
{
	int encounter = 0;

	encounter = roll(10);
	if (encounter >= 1 && encounter <= 8)
	{
		encounter = combat(lvl);
	}
	else if (encounter >= 9)
	{
		printf("\nThere is no enemy in this room, however you do find some rat treasure!\n");
		item(lvl);
		encounter = 1;
	}

	return encounter;
}
	

int combat(int lvl)
{
	int en_HP;
	int pl_HP;
	int en_AC;
	int attack;
	int dmg = 0;
	int input;
	int i = 0;
	int hit = 0;

	FILE*cmenu = fopen("c:/users/vovan/desktop/zero-rat/zero-rat-kingdom-dungeon/combat.txt", "r");

	while (i != EOF)
	{
		i = fgetc(cmenu);
		putchar(i);
	}
	i = 0;

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

	pl_HP = playerstats.temp_HP;

	printf("\nHP: %d\n", en_HP);
	printf("AC: %d\n", en_AC);
	printf("Attack: %d\n", attack);



	while (en_HP > 0 && pl_HP > 0)
	{
		printf("\n\nEnemy HP: %d/%d\n", en_HP, enemystats.HP);
		printf("Your current HP is %d/%d\n", pl_HP, playerstats.max_HP);
		printf("Potions\n", playerstats.potions);

		printf("\n**Enter 1 to attack**\n", pl_HP);
		printf("\n**Enter 2 to drink a health potion**\n", pl_HP);
		

		printf("\n");
		scanf("%d", &input);
		printf("\n");

		//ATTACK VS ENEMY
		if (input == 1)
		{

			//CHECK WHETHER ATTACK HITS OR NOT
			hit = atck(playerstats.attack, en_AC);
			//IF ATTACK HITS, ROLLS DAMAGE
			if (hit == 1)
			{
				dmg = damage(10);
				printf("\nYou deal %d damage to the enemy\n", dmg);
				en_HP = en_HP - dmg;	
			}

		}
		//DRINK POTION
		else if (input == 2)
		{
			if (playerstats.potions != 0)
			{
				//REMOVES ONE POTION FROM THE INVENTORY AND HEALS THE PLAYER
				playerstats.potions = playerstats.potions - 1;
				pl_HP = pl_HP + healing();
				playerstats.temp_HP = pl_HP;
				
				//CHECK THAT THE HP VALUE DOESN'T GO OVER MAXIMUM
				if (pl_HP > playerstats.max_HP)
				{
					pl_HP = playerstats.max_HP;
				}

			}
			else
			{
				printf("You don't have any potions!");
			}

		}

		else
		{
			printf("\nError, please enter 1 to attack the enemy!\n");
		}

		//ATTACK VS PLAYER
		if (en_HP > 0)
		{
			printf("\nThe level %d Rat Grunt attacks!\n", lvl);
			hit = atck(1, playerstats.AC);
			if (hit == true)
			{
				dmg = damage(1);
				printf("\nThe gross rat dealt %d damage to you!\n", dmg);
				pl_HP = pl_HP - dmg;
				playerstats.temp_HP = pl_HP;
				
				
			}
		}

		if (en_HP <= 0)
		{
			en_HP = 0;
		}

		else if (pl_HP <= 0)
		{
			pl_HP = 0;
			playerstats.temp_HP = pl_HP;
		}
		
	}


	if (en_HP == 0)
	{
		printf("\nYou defeated the enemy!\n");
		item(lvl);
		return 0;
	}

	else if (pl_HP == 0)
	{
		
		return 2;
	}
}

