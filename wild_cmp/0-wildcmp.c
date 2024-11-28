#include <stdio.h>
#include <string.h>
#include "holberton.h"

/**
 * wildcmp - Compares two strings, considering '*' as a wildcard character.
 * @s1: The first string to compare.
 * @s2: The second string to compare, which may contain '*'.
 *
 * Return: 1 if the strings match, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	/*Base cases*/
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1); /* Both strings are empty*/
	}
	if (*s2 == '*' && *(s2 + 1) == '\0')
	{
		return (1); /*'*' at the end of s2 matches anything */
	}

	/*If the current characters match or s2 has a '*' */
	if (*s1 == *s2 || *s2 == '*')
	{
		/*If s2 has a '*', try matching the current character or skipping it*/
		if (*s2 == '*')
		{
			return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
		}
		else
		{
			/*Move to the next character in both strings*/
			return (wildcmp(s1 + 1, s2 + 1));
		}
	}

	/*If the current characters don't match and s2 doesn't have a '*'*/
	return (0);
}
