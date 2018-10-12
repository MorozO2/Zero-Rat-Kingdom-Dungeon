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
	int AC = 10;
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

struct blumpy
{
	int max_HP = 120;
	int temp_HP = 120;
	int AC = 18;
	int attack = 5;
	int react = 5;
	int heals = 2;
}blumpy;

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
	int en_HP = 0;
	int en_AC = 0;
	int en_attack = 0;
	int pl_HP = 0;
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

	
	
		//SCALES THAT ENEMY STATS IN ACCORDANCE WITH THE LEVEL
		en_HP = enemystats.HP + HP_scale(lvl);
		en_AC = enemystats.AC + AC_scale(lvl);
		en_attack = enemystats.attack + attack_scale(lvl);
	

	//ASSIGNS ENEMY AND PLAYER STATS TO VARIABLES
	/*en_HP = enemystats.HP;
	en_AC = enemystats.AC;
	attack = enemystats.attack;*/

	pl_HP = playerstats.temp_HP;

	printf("\nHP: %d\n", en_HP);
	printf("AC: %d\n", en_AC);
	printf("Attack: +%d\n", en_attack);



	while (en_HP > 0 && pl_HP > 0)
	{
		printf("\n\nEnemy HP: %d\n", en_HP);
		printf("Your current HP is %d/%d\n", pl_HP, playerstats.max_HP);
		printf("Potions: %d\n", playerstats.potions);

		printf("\n**Enter 1 to attack**\n");
		printf("\n**Enter 2 to drink a health potion**\n");
		

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
				dmg = pl_damage(playerstats.attack);
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
				pl_HP = pl_HP + healing(d8);
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
			hit = atck(en_attack, playerstats.AC);
			if (hit == 1)
			{
				dmg = en_damage(en_attack);
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
		
		return 3;
	}
}

int boss()
{
	int pl_HP = 0;
	int blp_HP = 0;
	int blp_AC = 0;
	int attack = 0;
	int dmg = 0;
	int HP = 0;
	int input = 0;
	int hit = 0;

	HP = playerstats.temp_HP;
	blp_HP = blumpy.temp_HP;

	while (HP > 0 && blp_HP > 0)
	{
		
		printf("\n You face Great Rat Lord Blumpy, Master of Space and Time\n");
		printf("HP: %d/%d\n", blp_HP, blumpy.max_HP);
		printf("AC: %d\n", blumpy.AC);
		printf("Attack: %d\n", blumpy.attack);

		printf("\nYour HP: %d/%d\n", HP, playerstats.max_HP);
		printf("Potions: %d", playerstats.potions);
		printf("\nPress 1 to attack\n");
		printf("Press 2 to drink Rat Potion\n");
		scanf("%d", &input);

		//ATTACK VS BOSS
		if (input == 1)
		{
			//CHECK WHETHER ATTACK HITS OR NOT
			hit = atck(playerstats.attack, blumpy.AC);
			//IF BOSS HP IS LOW, BOSS USES REACTION TO EVADE ATACK
			if (hit == 1 && blp_HP <= 50 && blumpy.react > 0)
			{
				
				hit = 0;
				blumpy.react = blumpy.react - 1;
				printf("\nBlumpy reacted to your attack and teleported a short distance! The attack missed\n");
			}
			//ROLLS DAMAGE IF ATTACK HITS
			else if (hit == 1)
			{
				dmg = pl_damage(playerstats.attack);
				printf("\nYou deal %d damage to the enemy\n", dmg);
				blp_HP = blp_HP - dmg;
			}
			
		}

		else if (input == 2)
		{
			if (playerstats.potions != 0)
			{
				//REMOVES ONE POTION FROM THE INVENTORY AND HEALS THE PLAYER
				playerstats.potions = playerstats.potions - 1;
				pl_HP = pl_HP + healing(d8);
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
			printf("\nError: enter either 1 or 2");
		}

		//ATTACK VERSUS PLAYER
		if (blp_HP < 40 && blumpy.heals > 0)
		{
			healing(d12);
			blumpy.heals = blumpy.heals - 1;
		}
		else if (blp_HP > 0)
		{
			printf("\nThe mighty and handsome Blumpy attacks!\n");
			hit = atck(blumpy.attack, playerstats.AC);
			if (hit == 1)
			{
				dmg = en_damage(blumpy.attack);
				printf("\nThe gross rat dealt %d damage to you!\n", dmg);
				HP = HP - dmg;
				playerstats.temp_HP = HP;

			}
		}

		if (blp_HP <= 0)
		{
			blp_HP = 0;
		}

		else if (HP <= 0)
		{
			HP = 0;
			playerstats.temp_HP = pl_HP;
		}
	}

	if (blp_HP == 0)
	{
		printf("\nYou almost managed to best The Great Blumpy.\nHowever he teleports out of sight at the last moment\n.Blumpy will return....\n");
		return 0;
	}

	else if (HP == 0)
	{
		return 3;
	}

}


