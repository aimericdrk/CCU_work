/*
** CCU PROJECT, 2025
** queue_operations.c
** File description:
** queue operations for BFS ( coding norm compliant )
** Implementation of a simple queue using an array
*/

#include "problem_one.h"


void init_queue(queue_t *q)
{
    q->front = q->rear = 0;
}

int is_empty(queue_t *q)
{
    return q->front == q->rear;
}

void en_queue(queue_t *q, position_t pos)
{
    q->data[q->rear++] = pos;
}

position_t de_queue(queue_t *q)
{
    return q->data[q->front++];
}
