/*
** CCU PROJECT, 2025
** print_help.c
** File description:
** print help information
*/

#include "problem_one.h"

int print_help(int return_code)
{
    printf("Usage: ./problem_one < input_file\n");
    printf("Input format:\n");
    printf("First line: number of rows in the maze\n");
    printf("Second line: number of columns in the maze\n");
    printf("Next <number of rows> lines: each line contains <number of columns> digits (0 or 1),\n");
    printf("    where '1' is a walkable path and '0' is a wall\n");
    printf("\n");
    printf("Maze entrance is always at (0,0), exit is at (rows-1, columns-1)\n");
    printf("Output:\n");
    printf("  - If a path exists, print the number of steps in the shortest path (first line)\n");
    printf("  - Then print the coordinates of the path from entrance to exit, one per line\n");
    printf("  - If no path exists, print: Cannot reach the exit\n");
    printf("\n");
    printf("Note:\n");
    printf("  - Use BFS (Breadth-First Search) with direction priority: Up -> Down -> Left -> Right\n");
    printf("  - Read maze input with: scanf(\"%%1d\", &maze[i][j])\n");
    printf("  - Do NOT use scanf(\"%%d\", &maze[i][j]) for reading the maze\n");
    printf("  - Time limit: 1 second\n");
    return return_code;
}
