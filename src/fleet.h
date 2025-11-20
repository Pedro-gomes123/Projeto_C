#ifndef FLEET_H
#define FLEET_H

// Orientação do navio
typedef enum {
    ORIENT_H, // Horizontal
    ORIENT_V  // Vertical
} Orientation;

// Estrutura de um Navio
typedef struct {
    char name[20];  // Nome (ex: Porta-aviões)
    int length;     // Tamanho (ex: 5)
    int hits;       // Quantos tiros já levou
    int placed;     // 1 se já foi posicionado, 0 se não
    // Opcional: coordenadas de origem para facilitar lógica
    int start_row;
    int start_col;
    Orientation orientation;
} Ship;

// Estrutura da Frota (conjunto de navios)
typedef struct {
    Ship *ships; // Array dinâmico de navios
    int count;   // Quantidade de navios
} Fleet;

// Protótipos
void init_fleet(Fleet *fleet);
void free_fleet(Fleet *fleet);

#endif // FLEET_H