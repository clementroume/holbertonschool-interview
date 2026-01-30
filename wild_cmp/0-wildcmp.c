#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * wildcmp - Compares two strings and checks if they identical.
 * @s1: The first string (the string to be matched).
 * @s2: The second string (the pattern, which can contain the '*' wildcard).
 *
 * Description: The special character '*' in s2 can replace any string
 * (including an empty string). This function uses recursion and does
 * not use loops.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	/* Base case 1: If both strings are at their end, they match. */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	/* If the characters match, continue with the next characters. */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	/* If the character in s2 is a wildcard '*' */
	if (*s2 == '*')
		/*
		 * The '*' can either:
		 * 1. Match an empty string (wildcmp(s1, s2 + 1))
		 * OR
		 * 2. Match the current character in s1, provided s1 is not empty
		 * (wildcmp(s1 + 1, s2)). We stay on the same '*' in s2 in case
		 * it needs to match multiple characters.
		 */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	/* Base case 2: If none of the above conditions are met, they don't match. */
	return (0);
}
