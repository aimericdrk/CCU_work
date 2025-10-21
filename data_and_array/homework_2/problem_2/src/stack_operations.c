/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** print help information
*/

#include "problem_two.h"

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

int pop_stack(stack_t *s)
{
    if (is_empty(s)) return -1;
    return s->data[(s->top)--];
}
