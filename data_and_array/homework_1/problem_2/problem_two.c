/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** problem number 2
*/

#include "problem_two.h"

// Entry point: reads input, initializes game state, and prints result for each test case
int main(int argc, char *argv[])
{
    int test_cases;
    int max_total_attack = 0;

    (void)argv;

    if (argc >= 2) {
        return print_help(0);
    }
    if (scanf("%d", &test_cases) == EOF) {
        return print_help(1);
    }
    while (test_cases--) {
        run_test_cases(&max_total_attack);
    }
    return 0;
}