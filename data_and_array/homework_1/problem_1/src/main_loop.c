/*
** CCU PROJECT, 2025
** main_loop.c
** File description:
** main loop for processing input and running test cases
*/

#include "problem_one.h"

void run_test_cases()
{
    SubarrayState_t state;
    
    if (scanf("%d", &state.size) == EOF) return;
    for (int i = 0; i < state.size; ++i) {
        if (scanf("%d", &state.array[i]) == EOF) break;
    }
    if (scanf("%d", &state.divisor) == EOF) return;

    // Calculate prefix sums for the current test case
    calculate_prefix_sums(&state);

    // Find the maximum remainder and its count
    RemainderResult_t result = find_max_remainder_count(&state);

    // Output the count of subarrays with the maximum remainder
    printf("%d\n", result.count);
}
