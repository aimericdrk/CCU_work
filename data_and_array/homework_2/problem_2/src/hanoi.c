/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** main function for Tower of Hanoi problem
*/

#include "problem_two.h"

void hanoi_recursive(hanoi_context_t *ctx, int n, int from, int aux, int to)
{
    if (n == 0 || ctx->move_count >= ctx->k) {
        return;
    }
    hanoi_recursive(ctx, n-1, from, to, aux);
    if (ctx->move_count < ctx->k) {
        int disk = pop_stack(&ctx->rods[from]);
        push_stack(&ctx->rods[to], disk);
        ctx->moves[ctx->move_count++] = (move_t){disk, from, to};
    }
    hanoi_recursive(ctx, n-1, aux, from, to);
}
