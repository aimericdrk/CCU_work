/*
** CCU PROJECT, 2025
** IO_interactions.c
** File description:
** every function relative to the input and output
*/

#include "problem_one.h"

void read_maze(int *rows, int *cols, int maze[MAX_SIZE][MAX_SIZE])
{
    scanf("%d", rows);
    scanf("%d", cols);
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            scanf("%1d", &maze[i][j]);
}

void print_path(int rows, int cols, position_t parent[MAX_SIZE][MAX_SIZE])
{
    position_t path[MAX_SIZE * MAX_SIZE];
    int path_len = 0;
    position_t curr = (position_t){rows - 1, cols - 1};
    while (curr.x != -1 && curr.y != -1) {
        path[path_len++] = curr;
        curr = parent[curr.x][curr.y];
    }
    printf("%d\n", path_len);
    for (int i = path_len - 1; i >= 0; i--)
        printf("(%d,%d)\n", path[i].x, path[i].y);
}
