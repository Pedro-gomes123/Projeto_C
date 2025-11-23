#ifndef BOARD_H
#define BOARD_H

typedef enum {
    CELL_agua, 
    CELL_navio,  
    CELL_dano,   
    CELL_erro   
} CellState;

typedef struct {
    CellState state;
    int navio_id; 
} Cell;

typedef struct {
    int linhas;   
    int colunas; 
    Cell *cells;    
} Board;


void init_board(Board *board, int linhas, int colunas);
void free_board(Board *board);
Cell* get_cell(Board *board, int linha, int coluna);

#endif