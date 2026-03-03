#include "main.h"

void swap_int(int *a, int *b)
{

	int temporaire = 0;

	temporaire = *b;
	*b = *a;
	*a = temporaire;
}

