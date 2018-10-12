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
#define d12 12
#define d20 20
#define scale_k 0.5

int roll(int high);
int atck(int mod, int ac);
int healing(int dice);
int en_damage(int attack);
int pl_damage(int attack);
float HP_scale(int lvl);
float attack_scale(int lvl);
float AC_scale(int lvl);

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

float attack_scale(int lvl)
{
	float scale;
	scale = lvl;
	return scale;
}

float AC_scale(int lvl)
{
	float scale;
	scale = 1 + lvl;
	return scale;
}

float HP_scale(int lvl)
{
	float scale;
	scale = roll(d4) + lvl * scale_k;
	return scale;
}


int pl_damage(int attack)
{
	int damage;
	damage = attack + roll(d6);

	return damage;
}

int en_damage(int attack)
{
	int damage;
	damage = attack + roll(d4);

	return damage;
}

int healing(int dice)
{
	int heal = 0;

	if (dice == d8)
	{
		heal = roll(d8)+2;
		printf("\nYou've used a Rat Potion. It tastes like sewage, but you've regained %d HP.\n", heal);
		
	}

	if (dice == d6)
	{
		heal = roll(d6)+2;
		printf("\nYou had a small rest and regained %d HP\n", heal);
	}

	if (dice == d12)
	{
		heal = 2*roll(d12);
		printf("\nBlumpy focuses his energy to turn back time and restore himself. He regains %d HP", heal);
	}
	
	return heal;
	
}

