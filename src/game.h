#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"

// Estrutura do Jogador
typedef struct {
    Board board;        // O tabuleiro onde estão os meus navios
    Board shots;        // O tabuleiro onde registo os meus tiros (visão do inimigo)
    Fleet fleet;        // A minha frota de navios
    char nickname[32];  // Nome do jogador
} Player;

// Estrutura do Jogo
typedef struct {
    Player p1;
    Player p2;
    int current_player; // 1 ou 2
    int game_over;      // 1 se acabou, 0 se continua
} Game;

// Protótipos
void init_game(Game *game);
void play_game(Game *game); // Loop principal

#endif // GAME_H