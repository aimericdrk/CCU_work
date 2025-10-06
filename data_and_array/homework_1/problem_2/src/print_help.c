/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** problem number 2
*/

#include "problem_two.h"


int print_help(int return_code)
{
    printf("Usage: ./problem_two < input_file\n");
    printf("Input format:\n");
    printf("First line: number of test cases\n");
    printf("For each test case:\n");
    printf("  Line 1: two integers N (number of cards) and P (play points)\n");
    printf("  Next N lines: each line contains a character (card type), and two integers (cost and effect)\n");
    printf("Card types: 'F' for Fairy, 'B' for Beetle\n");
    printf("Beetle effects: 1 (add Fairy to hand), 2 (buff all Fairies on field)\n");
    return return_code;
}
