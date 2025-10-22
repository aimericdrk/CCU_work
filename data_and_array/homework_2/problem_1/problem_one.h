/*
** CCU PROJECT, 2025
** problem_one.h
** File description:
** problem number 1
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Position structure
typedef struct position_s {
    int x;
    int y;
} position_t;

// Queue structure for BFS
typedef struct queue_s{
    position_t data[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} queue_t;

typedef struct bfs_context_s {
        int rows;
        int cols;
        int (*maze)[MAX_SIZE];
        int visited[MAX_SIZE][MAX_SIZE];
        position_t parent[MAX_SIZE][MAX_SIZE];
} bfs_context_t;

void init_queue(queue_t *q);
int is_empty(queue_t *q);
void en_queue(queue_t *q, position_t pos);
position_t de_queue(queue_t *q);

void read_maze(int *rows, int *cols, int maze[MAX_SIZE][MAX_SIZE]);
void print_path(int rows, int cols, position_t parent[MAX_SIZE][MAX_SIZE]);

int print_help(int return_code);

int bfs_shortest_path(bfs_context_t *ctx);
void bfs_explore_neighbors(bfs_context_t *ctx, queue_t *q, position_t curr, const int dx[4], const int dy[4]);

int main(int argc, char **argv);
