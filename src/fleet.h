#ifndef FLEET_H
#define FLEET_H

typedef enum {
    ORIENT_H, 
    ORIENT_V  
} Orientation;

typedef struct {
    char name[20];  
    int tamanho;     
    int dano;       
    int ativo;     
    int start_linha;
    int start_coluna;
    Orientation orientation;
} Navio; 

typedef struct {
    Navio *navios;
    int contador;   
} Fleet;

void init_fleet(Fleet *fleet);
void free_fleet(Fleet *fleet);

#endif 