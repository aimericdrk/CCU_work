/*
** CCU PROJECT, 2025
** problem_one.c
** File description:
** problem number 1
*/

#include "problem_one.h"

// Entry point: reads input, processes each test case, and prints result
int main(int argc, char *argv[])
{
    int test_cases;

    (void)argv;

    if (argc >= 2) {
        return print_help(0);
    }
    if (scanf("%d", &test_cases) == EOF) {
        return print_help(1);
    }
    while (test_cases--) {
        run_test_cases();
    }
    return 0;
}
