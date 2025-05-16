#include <stdio.h>

// Nível Novato - Posicionamento dos Navios

int main() {

// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
int tabuleiro[10][10]; // Matriz 10x10 para o tabuleiro

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar navio horizontal (linha 2, colunas 1, 2, 3)
    int linhaHorizontal = 2;
    int colunaInicialH = 1;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaInicialH + i] = 3;
    }

    // Posicionar navio vertical (coluna 6, linhas 5, 6, 7)
    int colunaVertical = 6;
    int linhaInicialV = 5;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaInicialV + i][colunaVertical] = 3;
    }

    // Exibir o título
    printf("TABULEIRO BATALHA NAVAL\n\n");

    // Exibir números das colunas
    printf("    "); 
    for (int col = 0; col < 10; col++) {
        printf(" %d  ", col);
    }
    printf("\n");

    // Exibir o tabuleiro com linhas e conteúdo
    for (int lin = 0; lin < 10; lin++) {
        printf("%d |", lin);
        for (int col = 0; col < 10; col++) {
            printf(" %d  ", tabuleiro[lin][col]);
        }
        printf("\n");
    }

    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
