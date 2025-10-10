#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned integer is a palindrome
 * @n: The number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;
	unsigned long remainder;

	while (original != 0)
	{
		remainder = original % 10;
		reversed = reversed * 10 + remainder;
		original /= 10;
	}

	if (n == reversed)
		return (1);
	else
		return (0);
}
