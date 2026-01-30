#include "menger.h"

/**
 * menger - Prints a 2D Menger sponge of a given level
 * @level: The level of the Menger sponge to print
 */
void menger(int level)
{
	int size, i, j, x, y;

	if (level < 0)
		return;

	size = 1;
	for (i = 0; i < level; i++)
		size *= 3;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			int is_hole = 0;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					is_hole = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}

			if (is_hole)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
