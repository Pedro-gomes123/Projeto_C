#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"

typedef struct {
    Board board;
    Fleet fleet;
    char nickname[32];
} Player;

void place_ships_auto(Board *board, Fleet *fleet);
void place_ships_manual(Board *board, Fleet *fleet);
int fire_shot(Board *board, Fleet *fleet, int row, int col);
int check_victory(Fleet *fleet);
void cpu_play(Board *target_board, Fleet *target_fleet);

#endif