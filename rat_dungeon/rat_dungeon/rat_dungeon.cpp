// rat_dungeon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#include <time.h>


int roll(int high);
int map();
void item(int lvl);
void stats();
float enemy_scale(int lvl);
void inventory();

int main()
{
	int lvl;
	int rooms;
	int encounter = 0;


	srand(time(0));

	for (lvl = 2; lvl < 6; lvl++)
	{
		printf("Floor %d\n", lvl);
	
		for (rooms = 1; rooms < 7; rooms++)
		{
			
			
			if (encounter == 0)
			{
				stats();
				encounter = map();
			}
			else if (encounter == 2)
			{
				encounter = enemy(lvl);
			}

			else if (encounter == 4) 
			{
				lvl = 8; //EXITS THE LOOP
			}
			else
			{
				printf("%d rooms completed on this floor\n", rooms);
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
