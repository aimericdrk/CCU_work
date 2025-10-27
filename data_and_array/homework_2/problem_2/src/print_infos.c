/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** print rods and moves information
*/

#include "problem_two.h"

void print_rods(stack_rod_t rods[3])
{
    for (int r = 0; r < 3; r++) {
        printf("rod %c :", rod_name(r));
        for (int i = 0; i <= rods[r].top; i++) {
            printf(" %d", rods[r].data[i]);
        }
        printf("\n");
    }
}

void print_moves(move_t *moves, int k)
{
    for (int i = 0; i < k; i++) {
        printf("Move disk %d from %c to %c\n", moves[i].disk, rod_name(moves[i].from), rod_name(moves[i].to));
    }
}
