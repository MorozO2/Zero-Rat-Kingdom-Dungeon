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
#define MAXFLOORS 5


int roll(int high);
int map();
int combat(int lvl);
int enc(int lvl);
void item(int lvl);
void stats();
float enemy_scale(int lvl);



int main()
{
	int lvl = 1;
	int rooms;
	int encounter = 0;


	srand(time(0));

	for (lvl = 1; lvl < MAXFLOORS; lvl++)
	{
		for (rooms = 0; rooms < MAXROOMS; rooms++)
		{
					
			//GAME STARTS AND DISPLAYS THE PLAYER'S STATS AND THE MAP
			stats();
			printf("\nFloor %d\n", lvl);
			printf("You've explored %d out of %d rooms on this floor\n", rooms, MAXROOMS);
			encounter = map();
		
			if (encounter == 1)
			{
				encounter = enc(lvl);
				if (encounter == 2)
				{
					rooms = MAXROOMS; 
					lvl = MAXFLOORS;	//EXITS THE LOOP (AND ENDS THE GAME)
				}
			}
		}
	}

	printf("\n\nYou died. Game over.\n");
	printf("Thanks for playing!\n");

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
