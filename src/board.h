#ifndef BOARD_H
#define BOARD_H

// Define os estados possíveis de uma célula no tabuleiro
typedef enum {
    CELL_agua, // Água (~)
    CELL_navio,  // Navio (S) - escondido do oponente
    CELL_dano,   // Acertou navio (X)
    CELL_erro   // Errou, acertou água (.)
} CellState;

// Estrutura de uma célula individual
typedef struct {
    CellState state;
    int navio_id; // ID do navio presente (-1 se não houver navio)
} Cell;

// Estrutura do Tabuleiro
typedef struct {
    int linha;       // Número de linhas
    int coluna;       // Número de colunas
    Cell *cells;    // Ponteiro para alocação dinâmica (malloc)
} Board;

// Protótipos das funções (o que vamos implementar depois)
void init_board(Board *board, int linhas, int ccolunas);
void free_board(Board *board);
Cell* get_cell(Board *board, int linha, int coluna);

#endif // BOARD_H