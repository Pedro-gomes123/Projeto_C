#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void BombaAleatoria(int n){
    int b;
    srand(time(NULL));
    for(b = 0; b <= n; b = 1 +b ){
        l = rand() % tamanho;
        c = rand() % tamanho;
        if(jogo[l][c.bomba == 0])
            jogo[l][c].bomba = 1;
        else 
            i--;
        jogo[l][c].bomba = 1;
    }
}


int mains(){

    int inicioJogo();

}