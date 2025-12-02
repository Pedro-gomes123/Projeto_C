# Projeto_C

Batalha Naval - PIF SI 2025.2

1. Sobre o Projeto
Este projeto consiste na implementação do clássico jogo de tabuleiro Batalha Naval utilizando a linguagem C. O objetivo principal é demonstrar o domínio de conceitos fundamentais da programação estruturada, com ênfase em:

Uso de Structs para modelagem de dados.

Manipulação de Ponteiros.

Alocação Dinâmica de Memória (malloc e free).

Modularização e separação de responsabilidades.

O jogo permite que um jogador humano enfrente o computador (CPU) num tabuleiro padrão de 10x10, com posicionamento de navios manual ou automático.

2. Estrutura de Arquivos
O projeto foi organizado em módulos para garantir a coesão e o baixo acoplamento, conforme sugerido na especificação:

Plaintext

/
├── Makefile           # Script de compilação automatizada
├── README.md          # Este documento
└── src/               # Código-fonte
    ├── main.c         # Ponto de entrada (Loop principal e menus)
    ├── board.c/.h     # Lógica do Tabuleiro (Alocação e Células)
    ├── fleet.c/.h     # Definição dos Navios e da Frota
    ├── game.c/.h      # Regras de Negócio (Posicionamento, Tiros, Vitória)
    ├── io.c/.h        # Interface com o Usuário (Input/Output)
    └── rnd.c/.h       # Gerador de números aleatórios

3. Decisões de Design e Implementação
Para cumprir os requisitos técnicos e garantir a performance, tomamos as seguintes decisões de arquitetura:

- Alocação de Memória (Linearização de Matriz)
Embora o tabuleiro seja visualmente uma matriz 2D (linhas e colunas), optamos por alocá-lo na memória como um vetor unidimensional (1D).

Motivo: Facilita o uso de um único malloc e free, reduzindo a fragmentação de memória e simplificando a passagem de ponteiros.

Acesso: O acesso à coordenada (linha, coluna) é feito pela fórmula matemática:

índice = (linha * total_colunas) + coluna

- Separação de IO e Lógica
Isolamos todas as funções de printf e scanf no módulo io.c.

Motivo: Seguir o princípio de responsabilidade única. O módulo game.c apenas processa regras (se acertou, se ganhou), sem se preocupar em como isso é mostrado na tela. Isso facilita a leitura e manutenção do código.

- Representação dos Navios
A frota é gerida como um array dinâmico de structs Navio. Cada navio mantém o seu próprio estado (dano, tamanho, coordenadas).

Controle de Vitória: A função check_victory não precisa percorrer o tabuleiro inteiro (100 células). Ela apenas percorre a lista de 6 navios, verificando se dano == tamanho. Isso torna a verificação extremamente rápida e eficiente.

3.4. Input e Validação
Utilizamos a biblioteca ctype.h para tratar as entradas do usuário, permitindo coordenadas como "a5", "A5" ou "b10" indiferentemente, melhorando a experiência de uso.

4. Como Compilar e Executar
Pré-requisitos
Compilador GCC instalado.

(Opcional) Make.

Opção A: Usando Makefile (Recomendado)
No terminal, na raiz do projeto, execute:

Bash

make
Em seguida, execute o jogo:

Linux/Mac: ./batalha_naval

Windows: batalha_naval.exe

Opção B: Compilação Manual
Caso não tenha o make instalado, pode compilar manualmente:

Bash

gcc src/main.c src/board.c src/fleet.c src/io.c src/rnd.c src/game.c -o batalha_naval
5. Instruções de Jogo
Ao iniciar, escolha o modo de posicionamento da sua frota:

(A)utomático: O computador distribui seus navios aleatoriamente.

(M)anual: Você digita a coordenada e orientação (H/V) para cada navio.

O jogo funciona em turnos.

No seu turno, digite a coordenada do alvo (ex: B5).

X indica acerto no navio inimigo.

. indica tiro na água.

Vence quem afundar toda a frota adversária primeiro.

6. Autores
Grupo de Sistemas de Informação:
Pedro Gomes
Ravi Almeida
Eduardo Rocha
