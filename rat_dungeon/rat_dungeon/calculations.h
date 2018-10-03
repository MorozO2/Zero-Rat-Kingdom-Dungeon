#pragma once
#include "pch.h"
#include "modes.h"
#include "encounters.h"
#include "calculations.h"
#include <iostream>
#pragma warning(disable:4996)

int roll(int high)
{
	int num;
	int low = 1;

	num = (rand() % (high - low + 1)) + low;

	return num;
}

