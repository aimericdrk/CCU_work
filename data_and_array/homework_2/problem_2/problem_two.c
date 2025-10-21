/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** Tower of Hanoi problem
*/

#include "problem_two.h"

int main(int argc, char **argv)
{
    (void)argv; // Unused parameter
    hanoi_context_t ctx;
    ctx.move_count = 0;

    if (argc != 1) {
        print_help(1);
        return 1;
    }

    scanf("%d %d", &ctx.k, &ctx.d);
    for (int i = 0; i < 3; i++) {
        init_stack(&ctx.rods[i]);
    }
    for (int i = ctx.d; i >= 1; i--) {
        push_stack(&ctx.rods[0], i);
    }
    hanoi_recursive(&ctx, ctx.d, 0, 1, 2);
    print_moves(ctx.moves, ctx.k < ctx.move_count ? ctx.k : ctx.move_count);
    print_rods(ctx.rods);
    return 0;
}
