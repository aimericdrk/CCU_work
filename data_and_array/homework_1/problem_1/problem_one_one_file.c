/*
** CCU PROJECT, 2025
** problem_one.c
** File description:
** problem number 1
*/

#include <stdio.h>
#include <string.h>

// Structure to hold the state for each test case
typedef struct SubarrayState_s {
    int array[50001];
    int prefix_sum[50001];
    int size;
    int divisor;
} SubarrayState_t;

// Structure to hold the result for each test case
typedef struct RemainderResult_s {
    int max_remainder;
    int count;
} RemainderResult_t;

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
