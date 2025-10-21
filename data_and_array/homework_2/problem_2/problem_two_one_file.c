
/*
** CCU PROJECT, 2025
** problem_two_one_file.c
** File description:
** Tower of Hanoi with stack operations and output (coding norm compliant)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISK 100

// Stack structure for rods
typedef struct stack_s{
    int data[MAX_DISK];
    int top;
} stack_t;

typedef struct move_s {
    int disk;
    int from;
    int to;
} move_t;

typedef struct hanoi_context_s {
    int k, d;
    int move_count;
    stack_t rods[3];
    move_t moves[131072];
} hanoi_context_t;

void init_stack(stack_t *s);
int is_empty(stack_t *s);
void push_stack(stack_t *s, int val);
int pop_stack(stack_t *s);
char rod_name(int idx);
void print_rods(stack_t rods[3]);
void print_moves(move_t *moves, int k);
void hanoi_recursive(hanoi_context_t *ctx, int n, int from, int aux, int to);


void init_stack(stack_t *s)
{
    s->top = -1;
}

int is_empty(stack_t *s)
{
    return s->top == -1;
}

void push_stack(stack_t *s, int val)
{
    s->data[++(s->top)] = val;
}

int pop_stack(stack_t *s) {
    if (is_empty(s)) return -1;
    return s->data[(s->top)--];
}

// Rod IDs
char rod_name(int idx)
{
    return "ABC"[idx];
}

void print_rods(stack_t rods[3])
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
        printf("Move disk %d from %c to %c\n", moves[i].disk, rod_name(moves[i].from), moves[i].to);
    }
}

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

int main(int argc, char **argv)
{
    hanoi_context_t ctx;
    scanf("%d %d", &ctx.k, &ctx.d);
    ctx.move_count = 0;
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
