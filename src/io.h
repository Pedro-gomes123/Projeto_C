#ifndef IO_H
#define IO_H

#include "game.h"

void print_welcome();
int read_menu_option();
void read_player_name(char *buffer, int player_num);
int read_board_size();
void print_board(Board *board, int show_ships); // show_ships = 1 mostra navios, 0 esconde
void read_coordinate(int *row, int *col); // Lê "A5" e converte para índices

#endif // IO_H