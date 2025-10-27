/*
** CCU PROJECT, 2025
** problem_one.c
** File description:
** Maze shortest path finder
*/

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
        int enqueued[MAX_SIZE][MAX_SIZE];
        position_t parent[MAX_SIZE][MAX_SIZE];
} bfs_context_t;

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
    printf("  - Time limit: 1 second\n");
    return return_code;
}

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

void bfs_explore_neighbors(bfs_context_t *ctx, queue_t *q, position_t curr, const int dx[4], const int dy[4])
{
    for (int d = 0; d < 4; d++) {
        int nx = curr.x + dx[d];
        int ny = curr.y + dy[d];
        if (nx >= 0 && nx < ctx->rows && ny >= 0 && ny < ctx->cols && ctx->maze[nx][ny] == 1) {
            if (!ctx->visited[nx][ny] && !ctx->enqueued[nx][ny]) {
                ctx->parent[nx][ny] = curr;
                en_queue(q, (position_t){nx, ny});
                ctx->enqueued[nx][ny] = 1;
            } else if (!ctx->visited[nx][ny] && ctx->enqueued[nx][ny]) {
                ctx->parent[nx][ny] = curr;
            }
        }
    }
}

int bfs_shortest_path(bfs_context_t *ctx)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue_t q;
    init_queue(&q);

     for (int i = 0; i < ctx->rows; i++)
        for (int j = 0; j < ctx->cols; j++) {
            ctx->visited[i][j] = 0;
            ctx->enqueued[i][j] = 0;
            ctx->parent[i][j] = (position_t){-1, -1};
        }

    if (ctx->maze[0][0] == 0 || ctx->maze[ctx->rows-1][ctx->cols-1] == 0)
        return 0;

    en_queue(&q, (position_t){0, 0});
    ctx->visited[0][0] = 1;

    while (!is_empty(&q)) {
        position_t curr = de_queue(&q);
        ctx->visited[curr.x][curr.y] = 1;
        if (curr.x == ctx->rows - 1 && curr.y == ctx->cols - 1)
            return 1;
        bfs_explore_neighbors(ctx, &q, curr, dx, dy);
    }
    return 0;
}




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
