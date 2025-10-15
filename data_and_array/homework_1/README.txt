Homework 1: Problem 1 : Subarray Maximum Remainder Counter

Problem Statement

Given an array $X$ of positive integers, the goal is to find the maximum remainder obtained by dividing the sums of all subarrays of $X$ by a given divisor $d$. For each test case, output the number of subarrays that yield this maximum remainder.

Example:
Array $X = [2, 1, 3, 4]$, divisor $d = 5$
Subarray sums: 2, 3, 6, 10, 1, 4, 8, 3, 7, 4
Remainders: 2, 3, 1, 0, 1, 4, 3, 3, 2, 4
Maximum remainder: 4 (from subarrays [1, 3] and [4])

Input Format:
- First line: number of test cases $n$
- For each test case:
	- Line 1: integer $s$ (size of array $X$)
	- Line 2: $s$ positive integers (elements of $X$)
	- Line 3: integer $d$ (divisor)

Output Format:
- For each test case, output a single integer: the number of subarrays with the maximum remainder value.

Compilation Instructions

To compile the project, use the provided Makefile:

```sh
make
```

if you don't have make on your computer you can still execute : 

gcc problem_1/src/calculation_functions.c problem_1/src/main_loop.c problem_1/src/print_help.c problem_1/problem_one.c -I./problem_1/ -o problem_one

This will build the executables for both problems. For problem 1, the binary will be named `problem_one` and located in the root of `homework_1`.

Running the Program

To run the program, use:

```sh
./problem_one < input.txt
```

Where `input.txt` is a text file containing the input as described above.

Code Structure & Function Documentation

Data Structures

SubarrayState in problem_one.h
```c
typedef struct SubarrayState_s {
	int array[50001];      // Stores the input array
	int prefix_sum[50001]; // Stores prefix sums for efficient subarray sum calculation
	int size;              // Size of the array
	int divisor;           // Divisor for remainder calculation
} SubarrayState_t;
```
Purpose: Holds all relevant data for a single test case, including the array, its prefix sums, size, and divisor.

RemainderResult in problem_one.h
```c
typedef struct RemainderResult_s {
	int max_remainder; // The maximum remainder found
	int count;         // Number of subarrays yielding max_remainder
} RemainderResult_t;
```

Purpose: Stores the result for a test case: the maximum remainder and how many subarrays produce it.

Functions

int main(int argc, char *argv[])  
File: problem_1/problem_one.c

Description: Entry point. Reads the number of test cases, then for each test case, calls run_test_cases(). If arguments are passed or input is invalid, prints help.


int print_help(int return_code)  
File: problem_1/src/print_help.c

Description: Prints usage instructions and input format. Returns the provided code.


void run_test_cases()  
File: problem_1/src/main_loop.c

Description: Reads a single test case (array size, array elements, divisor), computes prefix sums, finds the maximum remainder and its count, and prints the result.


void calculate_prefix_sums(SubarrayState_t *state)  
File: problem_1/src/calculation_functions.c

Description: Computes prefix sums for the input array, enabling efficient subarray sum calculation.


RemainderResult_t find_max_remainder_count(SubarrayState_t *state)  
File: problem_1/src/calculation_functions.c

Description: Iterates over all possible subarrays, calculates their sums and remainders, tracks the maximum remainder, and counts how many subarrays yield it. Returns the result.


File Overview

- problem_1/problem_one.c: Main entry point
- problem_1/problem_one.h: Data structures and function declarations
- problem_1/src/print_help.c: Help/usage output
- problem_1/src/main_loop.c: Test case input and main logic
- problem_1/src/calculation_functions.c: Core calculation functions
- problem_1/tests/: Test scripts and sample inputs
- Makefile: Build instructions


Example Input
```
2
4
2 1 3 4
5
3
1 2 3
4
```

Example Output
```
2
2
```


Notes
- The program is optimized for arrays up to 50,000 elements and divisors up to 1,000.
- Execution time limit: 2 seconds per test case.

--------------------------------------------------------------------------------

Homework 1: Problem 2 : Shadowverse Fairy and Beetle Combo Simulator

Problem Statement

You are given a deck focusing on the Fairy and Beetle combo strategy. For each test case, you must simulate a single turn to maximize the total attack power of all fairies on the field, given the available play points (PP) and initial cards in hand. Cards can be played in any order, as long as the total PP spent does not exceed the available PP. Each card has a type (Fairy or Beetle), a cost, and an effect. The goal is to determine the maximum possible total attack power of all fairies on the field after the turn.

Input Format
First line: number of test cases T
For each test case:
  Line 1: two integers N (number of cards in hand) and P (play points)
  Next N lines: each line contains a character (card type), and two integers (cost and effect)
    Card types: F for Fairy, B for Beetle
    Beetle effects: 1 (add Fairy to hand), 2 (buff all Fairies on field)

Output Format
For each test case, output a single integer: the maximum total attack power of all Fairies on the board within the given PP limit

Compilation Instructions
To compile the project, use the provided Makefile:

make

if you don't have make on your computer you an still execute :

gcc problem_2/src/game_state_manager.c problem_2/src/game_loop.c problem_2/src/print_help.c problem_2/problem_two.c -I./problem_2/ -o problem_two

This will build the executables for both problems. For problem 2, the binary will be named problem_two and located in the root of homework_1.

Running the Program
To run the program, use:

./problem_two < input.txt

Where input.txt is a text file containing the input as described above.

Data Structures

card_t in problem_two.h

typedef struct card_s {
    char type  // F for Fairy, B for Beetle
    int cost
    int effect
} card_t
Purpose: Represents a card in hand, with its type, cost, and effect.

game_state_t in problem_two.h

typedef struct game_state_s {
    card_t hand[20]
    int hand_size
    int play_points
    int fairies_on_field
    int fairy_attack[5]
    int total_attack
} game_state_t
Purpose: Stores the current state of the game, including the hand, play points, fairies on the field, their attack values, and the total attack.

Functions

int main(int argc, char *argv[])
File: problem_2/problem_two.c
Description: Entry point. Reads the number of test cases, then for each test case, calls run_test_cases. If arguments are passed or input is invalid, prints help.

int print_help(int return_code)
File: problem_2/src/print_help.c
Description: Prints usage instructions and input format. Returns the provided code.

void run_test_cases(int *max_total_attack)
File: problem_2/src/game_loop.c
Description: Reads a single test case (number of cards, play points, card details), initializes the game state, and calls maximize_fairy_attack to compute the maximum total attack. Prints the result.

void copy_game_state(game_state_t *dest, const game_state_t *src)
File: problem_2/src/game_state_manager.c
Description: Copies the game state from src to dest. Used for simulating different play sequences.

void play_card_t(game_state_t *state, int card_t_index)
File: problem_2/src/game_state_manager.c
Description: Simulates playing a card from hand, updating the game state according to the card's type and effect.

void maximize_fairy_attack(game_state_t *state, int *max_total_attack)
File: problem_2/src/game_state_manager.c
Description: Recursively explores all possible play sequences to maximize the total attack power of fairies on the field, given the available play points and cards in hand.

File Overview
problem_2/problem_two.c: Main entry point
problem_2/problem_two.h: Data structures and function declarations
problem_2/src/print_help.c: Help and usage output
problem_2/src/game_loop.c: Test case input and main logic
problem_2/src/game_state_manager.c: Game state management and core logic
problem_2/tests/: Test scripts and sample inputs
Makefile: Build instructions

Example Input
2
4 5
F 1 0
F 1 0
B 2 1
B 3 2
3 4
F 1 0
B 2 1
B 3 2

Example Output
4
3

Notes
The program is optimized for up to 10 cards in hand and 10 play points per test case.
Execution time limit: 1 second per test case.






