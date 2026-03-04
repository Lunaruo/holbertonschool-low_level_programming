#include "main.h"

/**
  * swap_int - Swaps the values of two integers together
  * @a: pointer to first integer
  * @b: pointer to seconde integer
  */

void swap_int(int *a, int *b)
{

	int temporaire = 0;

	temporaire = *b;
	*b = *a;
	*a = temporaire;
}

