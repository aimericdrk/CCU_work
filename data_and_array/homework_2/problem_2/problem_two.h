/*
** CCU PROJECT, 2025
** problem_two.h
** File description:
** problem number 2
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_DISK 100

// Stack structure for rods
typedef struct stack_rod_s {
    int data[MAX_DISK];
    int top;
} stack_rod_t;

typedef struct move_s {
    int disk;
    int from;
    int to;
} move_t;

typedef struct hanoi_context_s {
    int k, d;
    int move_count;
    stack_rod_t rods[3];
    move_t moves[131072];
} hanoi_context_t;

void init_stack(stack_rod_t *s);
int is_empty(stack_rod_t *s);
void push_stack(stack_rod_t *s, int val);
int pop_stack(stack_rod_t *s);

char rod_name(int idx);

int print_help(int return_code);

void print_rods(stack_rod_t rods[3]);
void print_moves(move_t *moves, int k);

void hanoi_recursive(hanoi_context_t *ctx, int n, int from, int aux, int to);

int main(int argc, char **argv);
