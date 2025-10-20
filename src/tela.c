#include <stdio.h>
#include <stdlib.h>

// calcular bomba


typedef struct{
    int Bomba;
    int Aberta;
    Int Vizinhos;
}Celula;

// Variaveis que definem o tamanho do tabuleiro 

celula Tabuleiro[10][10];
int l, c, tamanho = 10;

// Iniciando o tabuleiro definido que todos as celulas estão vazias 

void inicioJogo(){
    for(l = 0; l <tamanho; l = l + 1){
        for(i = 0; i < tamanho; i = i +1){
            jogo [l][c].bomba = 0;
            jogo [l][c].Aberta = 0;
            jogo[l][c].Vizinhos = 0;
        }
    }
}



int mains(){


}