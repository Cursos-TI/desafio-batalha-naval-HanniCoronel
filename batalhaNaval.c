#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    int tabuleiro[TAM][TAM];

    // Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    // Navio 1 - Horizontal (linha 1, colunas 1,2,3)
    int linhaH = 1, colInicioH = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colInicioH + i] = 3;
    }

    // Navio 2 - Vertical (coluna 6, linhas 5,6,7)
    int colunaV = 4, linhaInicioV = 3;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicioV + i][colunaV] = 3;
    }


    // Navio 3 - Diagonal Principal (posição i = 0, j = 0 até i = 2, j = 2)
    int linhaD1 = 0, colD1 = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica se a posição está livre (não tem navio)
        if (tabuleiro[linhaD1 + i][colD1 + i] == 0) {
            tabuleiro[linhaD1 + i][colD1 + i] = 3;
        }
    }

    // Navio 4 - Diagonal Secundária (posição i = 0, j = 9 até i = 2, j = 7)
    int linhaD2 = 0, colD2 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica se a posição está livre (não tem navio)
        if (tabuleiro[linhaD2 + i][colD2 - i] == 0) {
            tabuleiro[linhaD2 + i][colD2 - i] = 3;
        }
    }

    
    // Exibir cabeçalho do tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");

    printf("    "); // espaço para alinhar os números da coluna
    for (int col = 0; col < TAM; col++) {
        printf(" %d  ", col);
    }
    printf("\n");

    // Exibir o conteúdo do tabuleiro
    for (int lin = 0; lin < TAM; lin++) {
        printf("%d |", lin); // número da linha
        for (int col = 0; col < TAM; col++) {
            printf(" %d  ", tabuleiro[lin][col]);
        }
        printf("\n");
    }

       

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
