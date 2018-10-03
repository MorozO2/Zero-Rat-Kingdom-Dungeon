#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)
#define d6 6
#define d8 8
#define d10 10
#define d20 20




int attack(int mod)
{
	int attack;

	attack = roll(d20) + mod;

	return attack;
}
int roll(int high)
{
	int num;
	int low = 1;

	num = (rand() % (high - low + 1)) + low;

	return num;
}

float enemys_scale(int lvl)
{
	float scale;
	scale = lvl * 0.7;
	printf("%f", scale);
}

