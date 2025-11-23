#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fleet.h"


void init_fleet(Fleet *fleet) {

    fleet-> contador = 6;

    fleet->navios = malloc(6 * sizeof(Navio));

    if (fleet->navios == NULL) {
        exit(1); 
    }

    strcpy(fleet->navios[0].name, "Porta-Avioes");
    fleet->navios[0].tamanho = 5;  
    fleet->navios[0].dano = 0;   
    fleet->navios[0].ativo = 0;  

    strcpy(fleet->navios[1].name, "Encouracado");
    fleet->navios[1].tamanho = 4;  
    fleet->navios[1].dano = 0;   
    fleet->navios[1].ativo = 0;  

    strcpy(fleet->navios[2].name, "Cruzador");
    fleet->navios[2].tamanho = 3;  
    fleet->navios[2].dano = 0;   
    fleet->navios[2].ativo = 0;  

    strcpy(fleet->navios[3].name, "Cruzador");
    fleet->navios[3].tamanho = 3;  
    fleet->navios[3].dano = 0;   
    fleet->navios[3].ativo = 0;  

    strcpy(fleet->navios[4].name, "Destroyer");
    fleet->navios[4].tamanho = 2;  
    fleet->navios[4].dano = 0;   
    fleet->navios[4].ativo = 0; 
    
    strcpy(fleet->navios[5].name, "Destroyer");
    fleet->navios[5].tamanho = 2;  
    fleet->navios[5].dano = 0;   
    fleet->navios[5].ativo = 0;  
}

void free_fleet(Fleet *fleet) {
    if (fleet->navios != NULL) {
        free(fleet->navios);
        fleet->navios = NULL;
    }
}