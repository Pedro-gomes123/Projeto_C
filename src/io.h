#ifndef IO_H
#define IO_H

#include "board.h"

void print_board(Board *board, int show_ships);
void read_coordinate(int *row, int *col);
int read_orientation(); 

#endif