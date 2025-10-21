/*
** CCU PROJECT, 2025
** problem_one.c
** File description:
** Maze shortest path using BFS and queue (coding norm compliant)
*/

#include "problem_one.h"


int main(int argc, char **argv)
{
    bfs_context_t ctx;
        int maze[MAX_SIZE][MAX_SIZE] = {0};

    int found;

    (void)argv; // Unused parameter

    if (argc != 1) {
        print_help(1);
        return 1;
    }

    ctx.maze = maze;

    read_maze(&ctx.rows, &ctx.cols, ctx.maze);
    found = bfs_shortest_path(&ctx);

    if (found) {
        print_path(ctx.rows, ctx.cols, ctx.parent);
    } else {
        printf("Cannot reach the exit\n");
    }
    return 0;
}
