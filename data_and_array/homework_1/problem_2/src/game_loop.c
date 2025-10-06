/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** game loop
*/

#include "problem_two.h"

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
