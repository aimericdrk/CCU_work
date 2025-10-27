/*
** CCU PROJECT, 2025
** find_shortest_path.c
** File description:
** where the BFS algorithm is implemented to find the shortest path in the maze
*/

#include "problem_one.h"

int bfs_shortest_path(bfs_context_t *ctx)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue_t q;
    init_queue(&q);
    en_queue(&q, (position_t){0, 0});
    ctx->visited[0][0] = 1;
    ctx->parent[0][0] = (position_t){-1, -1};
    while (!is_empty(&q)) {
        position_t curr = de_queue(&q);
        if (curr.x == ctx->rows - 1 && curr.y == ctx->cols - 1)
            return 1;
        bfs_explore_neighbors(ctx, &q, curr, dx, dy);
    }
    return 0;
}

void bfs_explore_neighbors(bfs_context_t *ctx, queue_t *q, position_t curr, const int dx[4], const int dy[4])
{
    for (int d = 0; d < 4; d++) {
        int nx = curr.x + dx[d];
        int ny = curr.y + dy[d];
        int valid = nx >= 0 && nx < ctx->rows && ny >= 0 && ny < ctx->cols;
        int walkable = valid && ctx->maze[nx][ny] == 1;
        if (!walkable)
            continue;
        if (!ctx->visited[nx][ny]) {
            ctx->visited[nx][ny] = 1;
            ctx->parent[nx][ny] = curr;
            en_queue(q, (position_t){nx, ny});
        }
    }
}
