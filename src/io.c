#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"
#include "io.h"

void print_board(Board *board, int show_ships) {
    printf("   "); 
    for (int j = 0; j < board->colunas; j++) {
        printf("%c ", 'A' + j); 
    }
    printf("\n");

    for (int i = 0; i < board->linhas; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < board->colunas; j++) {
            Cell *cell = get_cell(board, i, j);
            switch (cell->state) {
                case CELL_agua: printf("~ "); break;
                case CELL_dano: printf("X "); break;
                case CELL_erro: printf(". "); break;
                case CELL_navio: 
                    if (show_ships == 1) printf("S "); 
                    else printf("~ "); 
                    break;
            }
        }
        printf("\n");
    }
}

void read_coordinate(int *row, int *col) {
    char input[10]; 
    printf("Digite coordenada (ex.: A5): ");
    scanf("%s", input); 
    char letra = toupper(input[0]); 
    *col = letra - 'A'; 
    int numero = atoi(&input[1]);
    *row = numero - 1; 
}


int read_orientation() {
    char input[10];
    while (1) {
        printf("Orientacao (H = Horizontal, V = Vertical): ");
        scanf("%s", input);
        char c = toupper(input[0]);
        
        if (c == 'H') return 0; 
        if (c == 'V') return 1; 
        
        printf("Opcao invalida! Tente H ou V.\n");
    }
}