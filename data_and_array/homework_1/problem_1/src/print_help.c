/*
** CCU PROJECT, 2025
** print_help.c
** File description:
** print help information
*/

#include "problem_one.h"

int print_help(int return_code)
{
    printf("Usage: ./problem_one < input_file\n");
    printf("Input format:\n");
    printf("First line: number of test cases\n");
    printf("For each test case:\n");
    printf("  Line 1: integer N (size of array)\n");
    printf("  Line 2: N integers (array elements)\n");
    printf("  Line 3: integer D (divisor)\n");
    return return_code;
}
