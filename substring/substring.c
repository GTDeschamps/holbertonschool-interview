#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * find_substring - Finds all starting indices of substrings that are a concatenation
 *                  of a list of words in a given string.
 * @s: The string to scan.
 * @words: The array of words all substrings must be a concatenation of.
 * @nb_words: The number of elements in the array words.
 * @n: A pointer to an integer where the function will store the number of results.
 *
 * Return: An allocated array containing each index in `s` where a valid substring starts.
 *         If no valid substring is found, NULL is returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int word_len, s_len, substr_len, *indices = NULL, count = 0;
    int *word_count = NULL, *current_count = NULL;

    if (!s || !words || nb_words == 0 || !n)
        return NULL;

    word_len = strlen(words[0]);
    s_len = strlen(s);
    substr_len = word_len * nb_words;

    if (substr_len > s_len)
        return NULL;

    word_count = calloc(nb_words, sizeof(int));
    current_count = calloc(nb_words, sizeof(int));
    indices = malloc(s_len * sizeof(int));

    if (!word_count || !current_count || !indices)
    {
        free(word_count);
        free(current_count);
        free(indices);
        return NULL;
    }

    // Count occurrences of each word in the array `words`
    for (int i = 0; i < nb_words; i++)
    {
        for (int j = 0; j < nb_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
                word_count[i]++;
        }
    }

    // Iterate through `s` to find all valid substrings
    for (int i = 0; i <= s_len - substr_len; i++)
    {
        memset(current_count, 0, nb_words * sizeof(int));
        int j;

        for (j = 0; j < nb_words; j++)
        {
            int word_start = i + j * word_len;
            int k;

            for (k = 0; k < nb_words; k++)
            {
                if (strncmp(s + word_start, words[k], word_len) == 0)
                {
                    current_count[k]++;
                    if (current_count[k] > word_count[k])
                        break;
                    else
                        break;
                }
            }

            if (k == nb_words || current_count[k] > word_count[k])
                break;
        }

        if (j == nb_words)
            indices[count++] = i;
    }

    free(word_count);
    free(current_count);

    if (count == 0)
    {
        free(indices);
        *n = 0;
        return NULL;
    }

    *n = count;
    return realloc(indices, count * sizeof(int));
}
