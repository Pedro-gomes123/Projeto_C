#include <stdio.h>
#include <stdlib.h>
#include <board.h>


void init_board(Board *board, int linha, int coluna){
    board ->linhas = linhas;
    board ->colunas = colunas;
    int total_cells = linhas * colunas;
    board -> cells = malloc(total_cells * sizeof(cell))   
    
    if borad -> cell == NULL{
        printf("\n Erro de Memoria")
        exite(1)
    }

    for (int i = 0; i < total_cells; i++){
        board->cells[i]
        board->cells[i].state = CELL_agua;
        board->cells[i].navio_id = -1;
    }
}