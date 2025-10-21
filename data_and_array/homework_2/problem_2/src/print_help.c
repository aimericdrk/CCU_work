/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** print help information
*/

#include "problem_two.h"

int print_help(int return_code)
{
    printf("Usage: ./problem_two < input_file\n");
    printf("Input format:\n");
    printf("Hanoi Tower Problem\n");
    printf("The Tower of Hanoi consists of three rods (A, B, C) and a number of disks of different sizes.\n");
    printf("All disks start on rod A, stacked from largest (bottom) to smallest (top).\n");
    printf("Your task is to move all disks to rod C, following these rules:\n");
    printf("  - Only one disk can be moved at a time.\n");
    printf("  - Only the top disk of any rod can be moved.\n");
    printf("  - No disk may be placed on top of a smaller disk.\n");
    printf("Input:\n");
    printf("  The first line contains two integers:\n");
    printf("    k: number of moves to output (1 <= k <= 2^d - 1)\n");
    printf("    d: number of disks (1 <= d <= 100)\n");
    printf("Output:\n");
    printf("  - The first k lines: each move in the format:\n");
    printf("      Move disk (disk number) from (rod ID) to (rod ID)\n");
    printf("  - The last three lines: state of each rod after k moves, in the format:\n");
    printf("      rod (rod ID) : (disk number) (disk number) ...\n");
    printf("    (Disk numbers in descending order, from largest to smallest)\n");
    printf("Time Limit: 1 second\n");
    return return_code;
}
