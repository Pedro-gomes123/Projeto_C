#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "fleet.h"
#include "rnd.h"
#include "io.h" 

int can_place_ship(Board *board, int tamanho, int row, int col, int orient) {
    if (orient == ORIENT_H) {
        if (col + tamanho > board->colunas) return 0; 
    } else {
        if (row + tamanho > board->linhas) return 0; 
    }

    for (int i = 0; i < tamanho; i++) {
        int r = row + (orient == ORIENT_V ? i : 0);
        int c = col + (orient == ORIENT_H ? i : 0);
        Cell *cell = get_cell(board, r, c);
        if (cell->state != CELL_agua) return 0; 
    }
    return 1; 
}

void place_ships_auto(Board *board, Fleet *fleet) {
    for (int i = 0; i < fleet->contador; i++) {
        Navio *navio_atual = &fleet->navios[i];
        int colocado = 0; 
        while (colocado == 0) {
            int r = roll_dice(board->linhas);
            int c = roll_dice(board->colunas);
            int orient = roll_dice(2); 

            if (can_place_ship(board, navio_atual->tamanho, r, c, orient)) {
                for (int k = 0; k < navio_atual->tamanho; k++) {
                    int fr = r + (orient == ORIENT_V ? k : 0);
                    int fc = c + (orient == ORIENT_H ? k : 0);
                    Cell *cell = get_cell(board, fr, fc);
                    cell->state = CELL_navio; 
                    cell->navio_id = i; 
                }
                navio_atual->start_linha = r;
                navio_atual->start_coluna = c;
                navio_atual->orientation = orient;
                navio_atual->ativo = 1;
                colocado = 1; 
            }
        }
    }
}


void place_ships_manual(Board *board, Fleet *fleet) {
    printf("\n--- MODO DE POSICIONAMENTO MANUAL ---\n");
    for (int i = 0; i < fleet->contador; i++) {
        Navio *navio = &fleet->navios[i];
        int colocado = 0;

        while (!colocado) {
            printf("\nPosicionando: %s (Tamanho: %d)\n", navio->name, navio->tamanho);
            print_board(board, 1); 

            int r, c;
            read_coordinate(&r, &c);
            int orient = read_orientation();

            if (can_place_ship(board, navio->tamanho, r, c, orient)) {
                for (int k = 0; k < navio->tamanho; k++) {
                    int fr = r + (orient == ORIENT_V ? k : 0);
                    int fc = c + (orient == ORIENT_H ? k : 0);
                    Cell *cell = get_cell(board, fr, fc);
                    cell->state = CELL_navio;
                    cell->navio_id = i;
                }
                navio->start_linha = r;
                navio->start_coluna = c;
                navio->orientation = orient;
                navio->ativo = 1;
                colocado = 1;
                printf("Navio posicionado!\n");
            } else {
                printf(">>> ERRO: Posicao invalida ou ocupada! Tente novamente.\n");
            }
        }
    }
}

int fire_shot(Board *board, Fleet *fleet, int row, int col) {
    if (row < 0 || row >= board->linhas || col < 0 || col >= board->colunas) return -1; 
    Cell *alvo = get_cell(board, row, col);
    if (alvo->state == CELL_dano || alvo->state == CELL_erro) return -1; 

    if (alvo->state == CELL_agua) {
        alvo->state = CELL_erro; 
        return 0; 
    }
    if (alvo->state == CELL_navio) {
        alvo->state = CELL_dano; 
        int id = alvo->navio_id;
        if (id >= 0) fleet->navios[id].dano++; 
        return 1; 
    }
    return 0;
}

int check_victory(Fleet *fleet) {
    for (int i = 0; i < fleet->contador; i++) {
        if (fleet->navios[i].dano < fleet->navios[i].tamanho) return 0; 
    }
    return 1; 
}

void cpu_play(Board *target_board, Fleet *target_fleet) {
    int valido = 0;
    printf("\n[Computador esta pensando...]\n");
    while (valido == 0) {
        int r = roll_dice(target_board->linhas);
        int c = roll_dice(target_board->colunas);
        int resultado = fire_shot(target_board, target_fleet, r, c);

        if (resultado != -1) {
            valido = 1; 
            printf(">>> Computador atirou em %c%d: ", 'A' + c, r+1);
            if (resultado == 1) printf("ACERTOU O TEU NAVIO! <<<\n");
            else printf("AGUA. <<<\n");
        }
    }
}