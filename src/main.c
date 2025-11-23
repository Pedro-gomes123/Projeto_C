#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include "fleet.h"
#include "io.h"
#include "game.h"
#include "rnd.h"

int main() {
    setup_random();
    printf("\n=== BATALHA NAVAL: DUELO FINAL ===\n");


    Fleet frota_player; init_fleet(&frota_player);
    Board tab_player;   init_board(&tab_player, 10, 10);
    
    Fleet frota_cpu;    init_fleet(&frota_cpu);
    Board tab_cpu;      init_board(&tab_cpu, 10, 10);

    printf("Como deseja posicionar sua frota?\n");
    printf("(A)utomatico ou (M)anual? ");
    char resp[10];
    scanf("%s", resp);

    if (toupper(resp[0]) == 'M') {
        place_ships_manual(&tab_player, &frota_player);
    } else {
        printf("Posicionando sua frota aleatoriamente...\n");
        place_ships_auto(&tab_player, &frota_player);
    }

    printf("O Inimigo esta posicionando os navios...\n");
    place_ships_auto(&tab_cpu, &frota_cpu);


    int game_running = 1;
    int turnos = 1;

    while (game_running) {
        printf("\n================ TURNO %d ================\n", turnos);
        
        printf("\n--- AREA INIMIGA ---\n");
        print_board(&tab_cpu, 0);

        printf("\n--- TUA FROTA ---\n");
        print_board(&tab_player, 1);


        printf("\n--> TUA VEZ! <--\n");
        int r, c;
        read_coordinate(&r, &c);
        int res = fire_shot(&tab_cpu, &frota_cpu, r, c);
        
        if (res == 1) printf("BOOM! ACERTASTE!\n");
        else if (res == 0) printf("Agua...\n");
        else printf("Tiro invalido! Perdeste a vez.\n");

        if (check_victory(&frota_cpu)) {
            printf("\n\nVITORIA! DESTRUISTE A FROTA INIMIGA EM %d TURNOS!\n", turnos);
            break;
        }

        cpu_play(&tab_player, &frota_player);
        
        if (check_victory(&frota_player)) {
            printf("\n\nDERROTA! A TUA FROTA FOI DESTRUIDA!\n");
            break;
        }
        turnos++;
    }

    free_board(&tab_player); free_fleet(&frota_player);
    free_board(&tab_cpu);    free_fleet(&frota_cpu);
    return 0;
}