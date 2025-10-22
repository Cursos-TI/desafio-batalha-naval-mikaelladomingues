#include <stdio.h>
int main(){

int tabuleiro[10][10] = { //  Declaração da matriz 10x10 é Iniciando ela
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 3, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3}
};

int i01 = 0;
char letra;
letra = 'A';

int linhas = 10;
int colunas = 10;

printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
printf("     \033[1;33mBATALHA NAVAL\033[0m\n");
printf("-=-=-=-=-=-=-=-=-=-=-=-\n");

printf("   ");
for (i01 = 1; i01 <= 10; i01++) { // Imprime de (A a J) em cima da matriz
    printf("\033[1;34m%c\033[0m ", letra); // Pinta as letras
    letra++;
}
printf("\n");

for (int i = 0; i < linhas; i++) { // Imprime os números da linha
    printf("\033[1;34m%2d\033[0m ", i + 1); // Imprime de (1 a 10) ao lado da matriz é Pinta os números
    for (int j = 0; j < colunas; j++) { // Imprime os números da coluna
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}



    
    return 0;
}