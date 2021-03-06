// rat_dungeon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>
#define MAXROOMS 6
#define MAXFLOORS 6
#define nl 10



int map(int lvl);
int combat(int lvl);
int enc(int lvl);
void stats();



int main()
{
	int lvl = 1;
	int rooms;
	int encounter = 0;
	int dead = 0;
	int input = 0;
	int name;
	int j = 0;
	int i = 0;
	srand(time(0));

	//READS THE INTRO FILE
	FILE*intro = fopen("intro.txt", "r");
	while (j != EOF)
	{
		j = fgetc(intro);
		putchar(j);
	}
	fclose(intro);

	//ASKS PLAYER TO INPUT NAME
	printf("\n\nPlease input your name and press Enter:\n");
	while ((name = getchar()) != nl)
	{
		playerstats.name[i] = name;
		i++;

	}

	//LOOP FOR CALCULATING WHAT LEVEL THE PLAYER IS ON
	for (lvl = 1; lvl <= MAXFLOORS; lvl++)
	{
		//LOOP FOR CALCULATING FOR MANY ROOMS THE PLAYER EXPLORED
		for (rooms = 0; rooms < MAXROOMS; rooms++)
		{
					
			//GAME STARTS AND DISPLAYS THE PLAYER'S STATS AND THE MAP
			if (lvl < MAXFLOORS)
			{
				stats();
				printf("\nFloor %d/%d\n", lvl, MAXFLOORS);
				printf("You've explored %d out of %d rooms on this floor\n", rooms, MAXROOMS);
				encounter = map(lvl);
			}

			//IF PLAYER IS AT THE LAST LEVEL, GAME INITIATES FINAL BOSS FIGHT
			else if (lvl == MAXFLOORS)
			{
				printf("\nYou've cleared the perilous stronghold and are now ready to face The Great Blumpy, ruler of this domain.\n");
				printf("Before entering the Mighty One's chamber, you see a healing fountain\n");
				printf("You drink from and are restored to full health. Good luck, you'll need it\n");
				playerstats.temp_HP = playerstats.max_HP;
				printf("Enter 1 to face Blumpy\n");
				scanf("%d", &input);
				encounter = boss(lvl);
				//EXITS THE LOOP AND SETS "dead" BOOL TO NEGATIVE, INDICATING THAT THE PLAYER BEAT THE GAME
				if (encounter == 3)
				{
					dead = 0;
					rooms = MAXROOMS;
					lvl = MAXFLOORS + 1;
				}

				else if (encounter == 4)
				{
					dead = 1;
					rooms = MAXROOMS;
					lvl = MAXFLOORS + 1;
				}
			}
			//IF map() FUNCTION RETURNS 1, PLAYER ENCOUNTERS AN ENEMY
			if (encounter == 1)
			{
				encounter = enc(lvl);

				//IF enc(int lvl) returns 3, EXITS THE LOOP (AND ENDS THE GAME)
				if (encounter == 4)
				{
					dead = 1;
					rooms = MAXROOMS; 
					lvl = MAXFLOORS + 1;
				}
			}
			
		}
	}

	//DISPLAYS GAME OVER SCREEN IF PLAYER DIED
	if (dead == 1)
	{
		printf("\n\nYou died. Game over.\n");
		printf("Thanks for playing!\n");
		printf("\n\nCreated my Vladimir Moroz\n\n\n\n");
		printf("Enter 1 to exit\n");
		scanf("%d", &input);
	}

	//DISPLAYS "GAME COMPLETED" SCREEN IS PLAYER WINS
	else if (dead == 0)
	{
		printf("\n\nYou beat the game! Congradulations and thanks for playing!\n");
		printf("\n\nCreated my Vladimir Moroz\n\n\n\n");
		printf("Enter 1 to exit\n");
		scanf("%d", &input);
	}

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
