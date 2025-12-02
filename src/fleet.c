#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fleet.h"

void add_ship_dynamic(Fleet *fleet, const char *nome, int tamanho) {
    fleet->contador++;

    Navio *temp = realloc(fleet->navios, fleet->contador * sizeof(Navio));
    
    if (temp == NULL) {
        printf("Erro fatal: Falha ao realocar memoria para a frota.\n");
        exit(1);
    }
    
    fleet->navios = temp;

 
    Navio *n = &fleet->navios[fleet->contador - 1];
    strcpy(n->name, nome);
    n->tamanho = tamanho;
    n->dano = 0;
    n->ativo = 0;
}

void init_fleet(Fleet *fleet) {
    fleet->contador = 0;
    fleet->navios = NULL; 
    add_ship_dynamic(fleet, "Porta-Avioes", 5);
    add_ship_dynamic(fleet, "Encouracado", 4);
    add_ship_dynamic(fleet, "Cruzador", 3);
    add_ship_dynamic(fleet, "Cruzador", 3);
    add_ship_dynamic(fleet, "Destroyer", 2);
    add_ship_dynamic(fleet, "Destroyer", 2);
}

void free_fleet(Fleet *fleet) {
    if (fleet->navios != NULL) {
        free(fleet->navios);
        fleet->navios = NULL;
        fleet->contador = 0;
    }
}