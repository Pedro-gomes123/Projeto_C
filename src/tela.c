#include <stdio.h>



// Função para limpar a tela usando códigos ANSI
void limpar_tela() {
    printf("\033[2J\033[H]");
}

// Função para criar uma pausa (delay) fazendo o processador contar
void delay() {
   
    for (long i = 0; i < 50000000L; i++);
}

// Função para desenhar o mapa (continua a mesma lógica)
void desenhar_mapa() {
    int largura = 3000; // Aumentei para ficar mais visível
    int altura = 10;

    // Laço para cada linha
    for (int y = 0; y < altura; y++) {
      
        for (int x = 0; x < largura; x++) {
            
            if (y == 0 || y == altura - 1 || x == 0 || x == largura - 1) {
                printf("#"); 
            } else {
                printf(" "); 
            }
        }

        printf("\n");
    }

}



// --- A Função Principal (O Gerente) ---

int main() {
    // O laço principal do jogo
    while (1) {
        limpar_tela();
        desenhar_mapa();
        
        fflush(stdout);
        
        delay();
    }

    return 0;
}