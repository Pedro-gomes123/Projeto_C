#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "board.h"
#include "fleet.h"
#include "io.h"
#include "game.h"
#include "rnd.h"

void play_game(int board_size) {
    Player p1;
    Player cpu;

    printf("\n--- PREPARANDO BATALHA ---\n");
    printf("Informe apelido do Jogador 1: ");
    scanf("%s", p1.nickname);
    strcpy(cpu.nickname, "Computador");

 
    init_fleet(&p1.fleet);
    init_board(&p1.board, board_size, board_size);
    
    init_fleet(&cpu.fleet);
    init_board(&cpu.board, board_size, board_size);

    printf("\nComo deseja posicionar sua frota?\n");
    printf("(A)utomatico ou (M)anual? ");
    char resp[10];
    scanf("%s", resp);

    if (toupper(resp[0]) == 'M') {
        place_ships_manual(&p1.board, &p1.fleet);
    } else {
        printf("Posicionando frota de %s automaticamente...\n", p1.nickname);
        place_ships_auto(&p1.board, &p1.fleet);
    }

    printf("O Inimigo (%s) esta posicionando os navios...\n", cpu.nickname);
    place_ships_auto(&cpu.board, &cpu.fleet);


    int game_running = 1;
    int turnos = 1;

    while (game_running) {
        printf("\n================ TURNO %d ================\n", turnos);
   
        printf("\n--- %s (VISAO DE TIROS) ---\n", cpu.nickname);
        print_board(&cpu.board, 0); 

        printf("\n--- %s (SUA FROTA) ---\n", p1.nickname);
        print_board(&p1.board, 1);  

        printf("\n--> VEZ DE %s! <--\n", p1.nickname);
        int r, c;
        int valid_shot = 0;
        
        while (!valid_shot) {
            read_coordinate(&r, &c);

            if (r >= p1.board.linhas || c >= p1.board.colunas) {
                printf("Coordenada fora dos limites! Tente novamente.\n");
                continue;
            }

            int res = fire_shot(&cpu.board, &cpu.fleet, r, c);
            if (res == -1) {
                printf("Voce ja atirou ai ou local invalido. Tente novamente.\n");
            } else {
                valid_shot = 1;
                if (res == 1) printf("BOOM! ACERTOU UM NAVIO INIMIGO!\n");
                else printf("Agua...\n");
            }
        }

        if (check_victory(&cpu.fleet)) {
            printf("\n\n*** PARABENS %s! VITORIA EM %d TURNOS! ***\n", p1.nickname, turnos);
            break;
        }


        cpu_play(&p1.board, &p1.fleet);

        if (check_victory(&p1.fleet)) {
            printf("\n\n*** GAME OVER! %s VENCEU! ***\n", cpu.nickname);
            break;
        }
        turnos++;
    }


    free_board(&p1.board); free_fleet(&p1.fleet);
    free_board(&cpu.board); free_fleet(&cpu.fleet);
    
    printf("\n DIgitel algo e pressione Enter...");

    char temp; scanf(" %c", &temp); 
}

int main() {
    setup_random();
    int opcao = 0;
    int tamanho_tabuleiro = 10; 

    do {
        printf("\n=== BATALHA NAVAL: SI 2025.2 ===\n");
        printf("1) Novo Jogo\n");
        printf("2) Configuracoes\n");
        printf("3) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                play_game(tamanho_tabuleiro);
                break;
            case 2:
                printf("\n--- CONFIGURACOES ---\n");
                printf("Tamanho atual: %dx%d\n", tamanho_tabuleiro, tamanho_tabuleiro);
                printf("Informe novo tamanho (6 a 26): ");
                int novo_tam;
                scanf("%d", &novo_tam);
                if (novo_tam >= 6 && novo_tam <= 26) {
                    tamanho_tabuleiro = novo_tam;
                    printf("Tamanho atualizado com sucesso!\n");
                } else {
                    printf("ERRO: O tamanho deve ser entre 6 e 26.\n");
                }
                break;
            case 3:
                printf("Saindo do jogo... Ate mais!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}