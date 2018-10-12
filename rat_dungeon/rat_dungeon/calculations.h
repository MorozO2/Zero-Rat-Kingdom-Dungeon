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

int atck(int mod, int ac);
int roll(int high);
int attack_scale(int lvl);
float HP_scale(int lvl);
int AC_scale(int lvl);
int pl_damage(int attack);
int en_damage(int attack);
int healing(int dice);


//ATTACK FUCNTION THAT DETERMINE WHETHER OR NOT THE PLAYER/ENEMY HIT ITS TARGET
int atck(int mod, int ac)
{
	int attack;
	//ROLLS A 20-SIDED DIE AND COMPARES TO THE OPPONENTS AC(IF ROLL IS HIGHER, ATTACK HITS)
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

//VIRTUAL DICE ROLLING FUNCTION THAT TAKE IN THE SIZE OF THE DICE
int roll(int high)
{
	int num;
	int low = 1;

	num = (rand() % (high - low + 1)) + low;

	return num;
}

//FUNCTION THAT SCALES AN ENEMY'S ATTACK IN ACCORDANCE WITH THE LEVEL
int attack_scale(int lvl)
{
	float scale;
	scale = lvl;
	return scale;
}

//FUCNTION THAT SCALES ENEMY'S AC(ARMOR CLASS) IN ACCORDANCE WITH THE LEVEL
int AC_scale(int lvl)
{
	float scale;
	scale = lvl;
	return scale;
}

//FUNCTION THAT SCALES ENEMY'S HP IN ACCORDANCE WITH THE LEVEL
float HP_scale(int lvl)
{
	float scale;
	scale = roll(d4) + lvl * scale_k;
	return scale;
}

//FUNCTION THAT CALULATES THE DAMAGE THAT THE PLAYER DOES
int pl_damage(int attack)
{
	int damage;
	damage = attack + roll(d6);

	return damage;
}

//FUNCTION THAT CALCULATES THE DAMAGE THAT THE ENEMY DOES TO THE PLAYER
int en_damage(int attack)
{
	int damage;
	damage = attack + roll(d4);

	return damage;
}

//FUCNTION THAT DETERMINES HOW MUCH HP TO HEAL
int healing(int dice)
{
	int heal = 0;

	//HEALS PLAYER (IF 8-SIDED DIE VALUE IS PASSED)
	if (dice == d8)
	{
		heal = roll(d8)+2;
		printf("\nYou've used a Rat Potion. It tastes like sewage, but you've regained %d HP.\n", heal);
		
	}
	//HEALS ENEMY (IF 6-SIDED DIE VALUE IS PASSED)
	if (dice == d6)
	{
		heal = roll(d6)+2;
		printf("\nYou had a small rest and regained %d HP\n", heal);
	}
	//HEALS BOSS (IF 12-SIDED DIE VALUE IS PASSED)
	if (dice == d12)
	{
		heal = 2*roll(d12);
		printf("\nBlumpy focuses his energy to turn back time and restore himself. He regains %d HP", heal);
	}
	
	return heal;
	
}

