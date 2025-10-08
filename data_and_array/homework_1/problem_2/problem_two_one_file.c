/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** problem number 2
*/

#include <stdio.h>
#include <string.h>

// Structure to represent a card
typedef struct card_s {
    char type; // 'F' for Fairy, 'B' for Beetle
    int cost;
    int effect;
} card_t;

// Structure to represent the current game state
typedef struct game_state_s {
    card_t hand[20];
    int hand_size;
    int play_points;
    int fairies_on_field;
    int fairy_attack[5];
    int total_attack;
} game_state_t;

int print_help(int return_code)
{
    printf("Usage: ./problem_two < input_file\n");
    printf("Input format:\n");
    printf("First line: number of test cases\n");
    printf("For each test case:\n");
    printf("  Line 1: two integers N (number of cards) and P (play points)\n");
    printf("  Next N lines: each line contains a character (card type), and two integers (cost and effect)\n");
    printf("Card types: 'F' for Fairy, 'B' for Beetle\n");
    printf("Beetle effects: 1 (add Fairy to hand), 2 (buff all Fairies on field)\n");
    return return_code;
}

// Copy the game state for recursion
void copy_game_state(game_state_t *dest, const game_state_t *src)
{
    memcpy(dest, src, sizeof(game_state_t));
}

// Play a card_t and update the game state accordingly
void play_card_t(game_state_t *state, int card_t_index)
{
    card_t card_t = state->hand[card_t_index];
    state->play_points -= card_t.cost;
    if (card_t.type == 'F') {
        if (state->fairies_on_field < 5) {
            state->fairy_attack[state->fairies_on_field] = 1;
            state->fairies_on_field++;
            state->total_attack++;
        }
    } else if (card_t.type == 'B') {
        if (card_t.effect == 1) {
            // Add a Fairy to hand (cost=1, effect=0)
            state->hand[state->hand_size].type = 'F';
            state->hand[state->hand_size].cost = 1;
            state->hand[state->hand_size].effect = 0;
            state->hand_size++;
        } else if (card_t.effect == 2) {
            // Buff all Fairies on field
            for (int j = 0; j < state->fairies_on_field; ++j) {
                state->fairy_attack[j]++;
                state->total_attack++;
            }
        }
    }
    // Remove played card_t from hand
    for (int j = card_t_index; j < state->hand_size - 1; ++j) {
        state->hand[j] = state->hand[j + 1];
    }
    state->hand_size--;
}

// Recursive function to explore all play sequences and maximize Fairy attack
void maximize_fairy_attack(game_state_t *state, int *max_total_attack)
{
    if (state->total_attack > *max_total_attack) {
        *max_total_attack = state->total_attack;
    }
    for (int i = 0; i < state->hand_size; ++i) {
        if (state->hand[i].cost > state->play_points)
            continue; // Not enough PP
        game_state_t next_state;
        copy_game_state(&next_state, state);
        play_card_t(&next_state, i);
        maximize_fairy_attack(&next_state, max_total_attack);
    }
}

void run_test_cases(int *max_total_attack)
{
    int num_card_ts, play_points;
    while (scanf("%d %d", &num_card_ts, &play_points) != EOF) {
        game_state_t state;
        state.hand_size = num_card_ts;
        state.play_points = play_points;
        state.fairies_on_field = 0;
        state.total_attack = 0;
        memset(state.fairy_attack, 0, sizeof(state.fairy_attack));
        for (int i = 0; i < num_card_ts; ++i) {
            char type;
            int cost, effect;
            scanf(" %c %d %d", &type, &cost, &effect);
            state.hand[i].type = type;
            state.hand[i].cost = cost;
            state.hand[i].effect = effect;
        }
        *max_total_attack = 0;
        maximize_fairy_attack(&state, max_total_attack);
        printf("%d\n", *max_total_attack);
    }
}

// Entry point: reads input, initializes game state, and prints result for each test case
int main(int argc, char *argv[])
{
    int test_cases;
    int max_total_attack = 0;

    (void)argv;
    if (argc >= 2)
        return print_help(0);
    if (scanf("%d", &test_cases) == EOF)
        return print_help(1);
    while (test_cases--) {
        run_test_cases(&max_total_attack);
    }
    return 0;
}
