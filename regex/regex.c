#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

/**
 * regex_match - Checks if a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
*/

int regex_match(char const *str, char const *pattern)
{
    if (*pattern == '\0')
        return (*str == '\0');

    /* Check if the first character of the string matches */
    /* the first character of the pattern. */
    int first_match = (*str && (*str == *pattern || *pattern == '.'));

    /* Handle the '*' in the pattern. */
    if (*(pattern + 1) == '*')
    {
        /* Two cases:
        * 1. Ignore the '*' and the preceding character (move pattern by 2).
        * 2. If the first character matches, advance the string (move str by 1).
        */
        return (regex_match(str, pattern + 2) ||
                (first_match && regex_match(str + 1, pattern)));
    }
    else
    {
        /* If no '*', simply move both str and pattern by 1. */
        return (first_match && regex_match(str + 1, pattern + 1));
    }
}
