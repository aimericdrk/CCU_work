Assignment 2 ─ Stack & Queue
TA: Max (max.t7401@gmail.com)
Deadline:11:59 p.m., October 23, 2023

Problem 1

Maze Game
This is a maze game in which you must implement a queue to find the
shortest path out of the maze, using a breadth-frist search. The maze is
represented as a matrix composed of 0s and 1s. As shown in the Figure 1 below,
the entrance of the maze is fixed at the first element of the matrix, and the exit
is fixed at the last element. During movement, an element with a value of 1
represents a walkable path, while an element with a value of 0 is considered an
impassable wall.
Unlike the DFS (Depth-First Search) approach introduced in the class, BFS
(Breadth-First Search) on a maze explores the maze level by level. The visiting
order is to take some vertex as the starting point, then visit all vertices adjacent
to the start, and then visit the vertices adjacent to those vertices. That is,
gradually moving outward layer by layer. This continues until all connected
vertices have been visited.
Hint: When multiple shortest paths exist (shown as Figure 2), your BFS search
must follow the fixed direction priority in the order of Up → Down → Left → Right.

Input:
• In the test data, the first line of input represents the number of rows in
the maze, and the second line represents the number of columns.
• The following lines (equal to the number of rows) describe the layout of
the maze matrix. It consists of the following characters:
- “0” represents the wall.
- “1” represents the path.
Output:
• If the maze has a path from the entrance to the exit, you must find the
shortest path among all possible paths and output the result using the
format as shown in Figure 2.
- The first line shows the number of steps in the shortest path.
- The second line shows the fixed coordinates of the entrance (0,0).
- The last line shows the fixed coordinates of the exit. That is,the exit of
the cordiates is ( number of rows − 1,number of columns − 1).
- From the third line up to the line before the last, list all the coordinates
in the path.
• If no path exists to leave the maze, output "Cannot reach the exit".


Compilation Instructions

To compile the project, use the provided Makefile:

```sh
make
```

if you don't have make on your computer you can still execute : 

gcc problem_1/src/find_shortest_path.c problem_1/src/IO_interactions.c problem_1/src/queue_operations.c problem_1/src/print_help.c problem_1/problem_one.c -I./problem_1/ -o problem_one

This will build the executables for both problems. For problem 1, the binary will be named `problem_one` and located in the root of `homework_1`.

Running the Program

To run the program, use:

```sh
./problem_one < input.txt
```

Where `input.txt` is a text file containing the input as described above.

Code Structure & Function Documentation

Data Structures


typedef struct position_s {
    int x;
    int y;
} position_t;
-> Stores the coordinates of a cell in the maze.

typedef struct queue_s{
    position_t data[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} queue_t;
-> Implements a queue for BFS traversal, storing positions to visit.
Fields

typedef struct bfs_context_s {
        int rows;
        int cols;
        int (*maze)[MAX_SIZE];
        int visited[MAX_SIZE][MAX_SIZE];
        position_t parent[MAX_SIZE][MAX_SIZE];
} bfs_context_t;
-> Stores all state needed for a BFS search in the maze. ( used to reduce the numbers of args of a functions )

Functions 

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

File Overview

problem_1/problem_one.c: Main entry point
problem_1/problem_one.h: Data structures and function declarations
problem_1/src/print_help.c: Help/usage output
problem_1/src/IO_interactions.c: Input/output functions
problem_1/src/queue_operations.c: Queue implementation for BFS
problem_1/src/find_shortest_path.c: BFS algorithm and neighbor exploration

example input :

```
5
6
101111
101010
111011
000010
111111
```

example output :

```
14
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(1,2)
(0,2)
(0,3)
(0,4)
(1,4)
(2,4)
(3,4)
(4,4)
(4,5)
```


Problem 2

Hanoi Tower
The Tower of Hanoi is a classic puzzle consisting of three rods and a
number of disks of different sizes, which can slide onto any rod. The puzzle
starts with all the disks stacked in ascending order of size on one rod, with the
largest disk at the bottom and the smallest at the top. The objective is to move
the entire stack to another rod, following these rules below:
1. Only one disk can be moved at a time.
2. Each move consists of taking the top disk from one rod and placing it on
top of another rod.
3. No disk may be placed on top of a smaller disk.
You must implement a stack for each rod to solve the problem. As shown in
Figure 3 below, all the disks are initially stacked on rod A. The disks are
numbered sequentially from 1 to d, where a larger number indicates a larger
disk.You must move all the disks to rod C using the minimum number of moves,
which is 2𝑛 − 1 . In the input data, you will receive a number k, which indicates
that you must output the first k moves and the state of the rods after completing
these k moves.
Input:
• The first line contains two integers, first number is k (1 ≤ 𝑘 ≤ 2𝑑 − 1 ),
second number is d (1≤ 𝑑 ≤ 100 ).
Output: (Figure 4)
• For the first k lines, you must output each move in the format:
"Move disk (disk number) from (rod ID) to (rod ID)".
• For the last three lines, you must output the state of the three rods after
performing the k moves, in order. The output format is as follows:
"rod (rod ID) : (disk number) (disk number) ….".
The disk numbers should be output in descending order, from largest to
smallest.

Compilation Instructions

To compile the project, use the provided Makefile:

```sh
make
```

if you don't have make on your computer you can still execute : 

gcc problem_2/src/stack_operations.c problem_2/src/rod_name.c problem_2/src/hanoi.c problem_2/src/print_infos.c problem_2/src/print_help.c problem_2/problem_two.c -I./problem_2/ -o problem_two

This will build the executables for both problems. For problem 1, the binary will be named `problem_two` and located in the root of `homework_2`.

Running the Program

To run the program, use:

```sh
./problem_two < input.txt
```

Where `input.txt` is a text file containing the input as described above.

Code Structure & Function Documentation

Data Structures

typedef struct stack_s{
    int data[MAX_DISK];
    int top;
} stack_rod_t;
-> Represents a stack (rod) holding disks for the Tower of Hanoi.

typedef struct move_s {
    int disk;
    int from;
    int to;
} move_t;
-> Stores a single move in the Tower of Hanoi.

typedef struct hanoi_context_s {
    int k, d;
    int move_count;
    stack_rod_t rods[3];
    move_t moves[131072];
} hanoi_context_t;
-> Stores the entire state for a Tower of Hanoi run. ( used to reduce the numbers of args of a functions )

Functions

stack_operations.c

void init_stack(stack_rod_t s);
 -> Initializes a stack by setting its top index to -1 (empty).

int is_empty(stack_rod_t s);
 -> Returns 1 if the stack is empty, 0 otherwise.

void push_stack(stack_rod_t s, int val);
 -> Pushes a disk (value) onto the stack.

int pop_stack(stack_rod_t s);
 -> Pops and returns the top disk from the stack, or -1 if the stack is empty.


rod_name.c

char rod_name(int idx);
 -> Returns the character name ('A', 'B', or 'C') for a rod index (0, 1, or 2).


print_infos.c

void print_rods(stack_rod_t rods[3]);
 -> Prints the contents of all three rods, showing the disks on each rod in order.

void print_moves(move_t moves, int k);
 -> Prints the first k moves in the format: "Move disk X from Y to Z".


print_help.c

int print_help(int return_code);
 -> Prints usage instructions and input/output format for the Tower of Hanoi program, then returns the given code.


hanoi.c

void hanoi_recursive(hanoi_context_t ctx, int n, int from, int aux, int to);
 -> Recursively solves the Tower of Hanoi problem, recording each move in the context, and stops after k moves.

File Overview :

problem_2/problem_two.c: Main entry point
problem_2/problem_two.h: Data structures and function declarations
problem_2/src/print_help.c: Help/usage output
problem_2/src/stack_operations.c: Stack (rod) operations
problem_2/src/rod_name.c: Rod name utility
problem_2/src/print_infos.c: Output for rods and moves
problem_2/src/hanoi.c: Recursive Hanoi algorithm

example input :

```
10 5
```

example output :

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Move disk 4 from A to B
Move disk 1 from C to B
Move disk 2 from C to A
rod A : 5 2
rod B : 4 1
rod C : 3
```