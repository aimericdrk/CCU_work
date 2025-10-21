Problem 1


queue_operations.c

void initQueue(queue_t q);
 -> Initializes the queue by setting both front and rear indices to 0.

int isEmpty(queue_t q);
 -> Returns 1 if the queue is empty, 0 otherwise.

void enqueue(queue_t q, position_t pos);
 -> Adds a position to the rear of the queue.

position_t dequeue(queue_t q);
 -> Removes and returns the position at the front of the queue.


IO_interactions.c

void read_maze(int rows, int cols, int maze[MAX_SIZE][MAX_SIZE]);
 -> Reads the maze dimensions and the maze matrix from standard input.

void print_path(int rows, int cols, position_t parent[MAX_SIZE][MAX_SIZE]);
 -> Reconstructs and prints the shortest path from the entrance to the exit using the parent array.


print_help.c

int print_help(int return_code);
 -> Prints usage instructions and input/output format for the maze program, then returns the given code.


find_shortest_path.c

int bfs_shortest_path(bfs_context_t ctx);
 -> Performs Breadth-First Search (BFS) to find the shortest path in the maze, updating the parent and visited arrays. Returns 1 if a path is found, 0 otherwise.

void bfs_explore_neighbors(bfs_context_t ctx, queue_t q, position_t curr, const int dx[4], const int dy[4]);
 -> Explores all valid and walkable neighbors of the current position, updates their parent and visited status, and enqueues them for BFS.



Problem 2

stack_operations.c

void init_stack(stack_t s);
 -> Initializes a stack by setting its top index to -1 (empty).

int is_empty(stack_t s);
 -> Returns 1 if the stack is empty, 0 otherwise.

void push_stack(stack_t s, int val);
 -> Pushes a disk (value) onto the stack.

int pop_stack(stack_t s);
 -> Pops and returns the top disk from the stack, or -1 if the stack is empty.


rod_name.c

char rod_name(int idx);
 -> Returns the character name ('A', 'B', or 'C') for a rod index (0, 1, or 2).


print_infos.c

void print_rods(stack_t rods[3]);
 -> Prints the contents of all three rods, showing the disks on each rod in order.

void print_moves(move_t moves, int k);
 -> Prints the first k moves in the format: "Move disk X from Y to Z".


print_help.c

int print_help(int return_code);
 -> Prints usage instructions and input/output format for the Tower of Hanoi program, then returns the given code.


hanoi.c

void hanoi_recursive(hanoi_context_t ctx, int n, int from, int aux, int to);
 -> Recursively solves the Tower of Hanoi problem, recording each move in the context, and stops after k moves.
