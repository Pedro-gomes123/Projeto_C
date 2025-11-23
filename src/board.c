#include <stdio.h>
#include <stdlib.h>
#include "board.h" 


void init_board(Board *board, int linhas, int colunas) {
    
    board->linhas = linhas;
    board->colunas = colunas;
    
    int total_cells = linhas * colunas;

    board->cells = malloc(total_cells * sizeof(Cell)); 
    

    if (board->cells == NULL) {
        printf("\n Erro de Memoria");
        exit(1);
    }

    for (int i = 0; i < total_cells; i++) {
  
        board->cells[i].state = CELL_agua;
        board->cells[i].navio_id = -1;
    }
}

void free_board(Board *board) {

    if (board->cells != NULL) {
        free(board->cells); 
        board->cells = NULL; 
    }
}

Cell* get_cell(Board *board, int linha, int coluna) {

    if (linha < 0 || linha >= board->linhas || coluna < 0 || coluna >= board->colunas) { 
        return NULL; 
    }


    int index = (linha * board->colunas) + coluna; 

    return &board->cells[index];
}