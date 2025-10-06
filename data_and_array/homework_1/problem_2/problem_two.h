/*
** CCU PROJECT, 2025
** Problem 2
** File description:
** problem_two.h
*/

#pragma once

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


// problem_two.c
int main(int argc, char *argv[]);

// src/game_loop.c
void run_test_cases(int *max_total_attack);

// src/print_help.c
int print_help(int return_code);

// src/game_state_manager.c
void copy_game_state(game_state_t *dest, const game_state_t *src);
void play_card_t(game_state_t *state, int card_t_index);
void maximize_fairy_attack(game_state_t *state, int *max_total_attack);
