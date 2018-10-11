#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#define d2 2
#define d4 4
#define d6 6
#define d8 8
#define d10 10
#define d20 20
#define scale_k 0.5

int roll(int high);
int atck(int mod, int ac);
int healing();
int damage(int attack);
float enemy_scale(int lvl);

int atck(int mod, int ac)
{
	int attack;

	attack = roll(d20) + mod;
	if (attack >= ac)
	{
		printf("The attack hit!");
		return 1;
	}
	else
	{
		printf("The attack missed!\n");
		return 0;
	}
	
}

int roll(int high)
{
	int num;
	int low = 1;

	num = (rand() % (high - low + 1)) + low;

	return num;
}

float enemy_scale(int lvl)
{
	float scale;
	scale = lvl * scale_k;
	return scale;
}

int damage(int attack)
{
	int damage;
	damage = attack + roll(d4);

	return damage;
}

int healing()
{
	int heal = 0;
	heal = roll(d8);
	printf("\nYou've used a potion. It tastes like sewage, but you've regained %d HP\n", heal);
	return heal;
	
}

