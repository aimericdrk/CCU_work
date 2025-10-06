/*
** CCU PROJECT, 2025
** problem_two.c
** File description:
** game loop
*/

#include "problem_two.h"

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

