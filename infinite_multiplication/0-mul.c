#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mul.h"

/* Function to check if a string is composed of only digits */
int is_valid_number(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to multiply two large numbers represented as strings */
char *multiply(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total_len = len1 + len2;
    int *result = calloc(total_len, sizeof(int));
    char *final_result = malloc(total_len + 1);

    // Perform multiplication in reverse order
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Convert result to string
    int index = 0;
    int i = 0;
    while (i < total_len && result[i] == 0) {
        i++;
    }

    while (i < total_len) {
        final_result[index++] = result[i++] + '0';
    }

    final_result[index] = '\0';

    // If the result is empty, it means the result is 0
    if (index == 0) {
        strcpy(final_result, "0");
    }

    free(result);
    return final_result;
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Error\n");
        exit(98);
    }

    // Validate the arguments
    if (!is_valid_number(argv[1]) || !is_valid_number(argv[2])) {
        printf("Error\n");
        exit(98);
    }

    // Multiply the numbers
    char *result = multiply(argv[1], argv[2]);
    printf("%s\n", result);

    free(result);
    return 0;
}
