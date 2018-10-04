#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#define d4 4
#define d6 6
#define d8 8
#define d10 10
#define d20 20
#define scale_k 0.5

int roll(int high);

bool atck(int mod, int ac)
{
	int attack;

	attack = roll(d20) + mod;
	if (attack >= ac)
	{
		printf("The attack hit!");
		return true;
	}
	else
	{
		printf("The attack missed!\n");
		return false;
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


