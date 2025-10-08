/*
** CCU PROJECT, 2025
** calculation_functions.c
** File description:
** functions for calculating subarray properties
*/

#include "problem_one.h"

// Calculate prefix sums for the array
void calculate_prefix_sums(SubarrayState_t *state)
{
    state->prefix_sum[0] = 0;
    for (int i = 0; i < state->size; ++i) {
        state->prefix_sum[i + 1] = state->prefix_sum[i] + state->array[i];
    }
}

// Find the maximum remainder and its count for all subarrays
RemainderResult_t find_max_remainder_count(SubarrayState_t *state)
{
    int remainder_count[1001] = {0};
    int max_remainder = 0;
    for (int start = 0; start < state->size; ++start) {
        for (int end = start + 1; end <= state->size; ++end) {
            int sum = state->prefix_sum[end] - state->prefix_sum[start];
            int remainder = sum % state->divisor;
            remainder_count[remainder]++;
            if (remainder > max_remainder) {
                max_remainder = remainder;
            }
        }
    }
    RemainderResult_t result;
    result.max_remainder = max_remainder;
    result.count = remainder_count[max_remainder];
    return result;
}
