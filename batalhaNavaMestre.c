#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define NAVIO 3
#define TAM_HAB 5
#define ATAQUE 1

void adicionandoNaios(int tabuleiro[LINHAS][COLUNAS]) {
    // Adicionando navios na diagonal
    tabuleiro[0][0] = NAVIO;
    tabuleiro[1][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;

    tabuleiro[2][9] = NAVIO;
    tabuleiro[3][8] = NAVIO;
    tabuleiro[4][7] = NAVIO;

    // Adicionando os navios na vertical
    tabuleiro[7][9] = NAVIO;
    tabuleiro[8][9] = NAVIO;
    tabuleiro[9][9] = NAVIO;

    // Adicionando os navios na horizontal
    tabuleiro[5][1] = NAVIO;
    tabuleiro[5][2] = NAVIO;
    tabuleiro[5][3] = NAVIO;
}

// Marcando as posições de ataque do cone
void cone(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[2][7] = ATAQUE;
            matriz[3][6] = ATAQUE;
            matriz[3][7] = ATAQUE;
            matriz[3][8] = ATAQUE;
            matriz[4][5] = ATAQUE;
            matriz[4][6] = ATAQUE;
            matriz[4][7] = ATAQUE;
            matriz[4][8] = ATAQUE;
            matriz[4][9] = ATAQUE;
        }
    }
}

// Marcando as posições de ataque da cruz
void cruz(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[8][0] = ATAQUE;
            matriz[8][1] = ATAQUE;
            matriz[8][2] = ATAQUE;
            matriz[8][3] = ATAQUE;
            matriz[8][4] = ATAQUE;
            matriz[7][2] = ATAQUE;
            matriz[8][2] = ATAQUE;
            matriz[9][2] = ATAQUE;

        }
    }
}

// Marcando as posições de ataque do octaedro
void octaedro(int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[5][0] = ATAQUE;
            matriz[5][1] = ATAQUE;
            matriz[5][2] = ATAQUE;
            matriz[4][1] = ATAQUE;
            matriz[6][1] = ATAQUE;
        }
    }
}


int main(){

int tabuleiro[LINHAS][COLUNAS] = {0}; //  Declaração da matriz 10x10 é Iniciando ela com tudo 0
int i01 = 0;
char letra;
letra = 'A';

// Inicializando os navios
adicionandoNaios(tabuleiro);

printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
printf("     \033[1;33mBATALHA NAVAL\033[0m\n");
printf("-=-=-=-=-=-=-=-=-=-=-=-\n");

printf("   ");
for (i01 = 1; i01 <= LINHAS; i01++) { // Imprime de (A a J) em cima da matriz
    printf("\033[1;34m%c\033[0m ", letra); // Pinta as letras
    letra++;
}
printf("\n");

for (int i = 0; i < LINHAS; i++) { // Imprime os números da linha
    printf("\033[1;34m%2d\033[0m ", i + 1); // Imprime de (1 a 10) ao lado da matriz é Pinta os números
    for (int j = 0; j < COLUNAS; j++) { // Imprime os números da coluna
        if (tabuleiro[i][j] == NAVIO) { // Pinta os navios
            printf("\033[33m%d\033[0m ", tabuleiro[i][j]);
        } else {
            printf("%d ", tabuleiro[i][j]);
        }
    }
    printf("\n");
}

// Inicializando os ataques

cone(tabuleiro);
cruz(tabuleiro);
octaedro(tabuleiro);

letra = 'A';

printf("\n");
printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
printf(" \033[1;33mTABULEIRO ÀPOS ATAQUE\033[0m\n");
printf("-=-=-=-=-=-=-=-=-=-=-=-\n");


printf("   ");
for (i01 = 1; i01 <= LINHAS; i01++) { // Imprime de (A a J) em cima da matriz
    printf("\033[1;34m%c\033[0m ", letra); // Pinta as letras
    letra++;
}
printf("\n");

for (int i = 0; i < LINHAS; i++) { // Imprime os números da linha
    printf("\033[1;34m%2d\033[0m ", i + 1); // Imprime de (1 a 10) ao lado da matriz é Pinta os números
    for (int j = 0; j < COLUNAS; j++) { // Imprime os números da coluna
        if (tabuleiro[i][j] == NAVIO) { // Pinta os navios
            printf("\033[33m%d\033[0m ", tabuleiro[i][j]);
        } else if (tabuleiro[i][j] == ATAQUE) { // Pinta os ataques
            printf("\033[31m%d\033[0m ", tabuleiro[i][j]);
        } else {
            printf("%d ", tabuleiro[i][j]);
        }
    }
    printf("\n");
}

    
    
    return 0;
}