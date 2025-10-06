/*
** CCU PROJECT, 2025
** problem_one.h
** File description:
** problem number 1
*/

#pragma once

#include <stdio.h>
#include <string.h>

// Structure to hold the state for each test case
typedef struct {
    int array[50001];
    int prefix_sum[50001];
    int size;
    int divisor;
} SubarrayState;

// Structure to hold the result for each test case
typedef struct {
    int max_remainder;
    int count;
} RemainderResult;

// problem_one.c
int main(int argc, char *argv[]);

// src/print_help.c
int print_help(int return_code);

// src/main_loop.c
void run_test_cases();

// src/calculation_functions.c
void calculate_prefix_sums(SubarrayState *state);
RemainderResult find_max_remainder_count(SubarrayState *state);
