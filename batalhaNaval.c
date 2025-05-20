


#include <stdio.h>

#define TAM 10

void iniciarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // Inicializa o tabuleiro com 0 (água)
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("TABULEIRO BATALHA NAVAL\n\n");

    // Exibir números das colunas
    printf("    ");
    for (int col = 0; col < TAM; col++) {
        printf(" %d  ", col);
    }
    printf("\n");

    // Exibir o tabuleiro com linhas e conteúdo
    for (int lin = 0; lin < TAM; lin++) {
        printf("%d |", lin);
        for (int col = 0; col < TAM; col++) {
            printf(" %d  ", tabuleiro[lin][col]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna) {
    //Posicionar navios
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
        tabuleiro[linha][coluna] = 3; // Marca a posição do navio (3)
    }
    exibirTabuleiro(tabuleiro);
}

void usarHabilidadeOcta(int tabuleiro[TAM][TAM], int linha, int coluna) {
    // Verifica se a posição está dentro dos limites do tabuleiro
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
        // Marca a posição como atingida (1)
        tabuleiro[linha][coluna] = 3;
        tabuleiro[linha -1][coluna] = 3;
        tabuleiro[linha +1][coluna] = 3;
        tabuleiro[linha][coluna -1] = 3;
        tabuleiro[linha][coluna +1] = 3;
    }
     exibirTabuleiro(tabuleiro);
}

void usarHabilidadeCone(int tabuleiro[TAM][TAM], int linha, int coluna) {
    // Verifica se a posição está dentro dos limites do tabuleiro
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
        // Marca a posição como atingida (1)
        tabuleiro[linha][coluna] = 2; //meio
        tabuleiro[linha -1][coluna] = 2; //cima
        tabuleiro[linha +1][coluna] = 2; //baixo
        tabuleiro[linha][coluna -1] = 2; //esquerda
        tabuleiro[linha][coluna +1] = 2; //direita
        tabuleiro[linha +1][coluna +1] = 2; //baixo direita
        tabuleiro[linha +1][coluna +2] = 2; //baixo 2+direita
        tabuleiro[linha +1][coluna -1] = 2; //baixo esquerda 
        tabuleiro[linha +1][coluna -2] = 2; //baiixo 2+esquerda

        
    }
     exibirTabuleiro(tabuleiro);
}

void usarHabilidadeCruz(int tabuleiro[TAM][TAM], int linha, int coluna) {
    // Verifica se a posição está dentro dos limites do tabuleiro
    if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
        // Marca a posição como atingida (1)
        tabuleiro[linha][coluna] = 4; //meio
        tabuleiro[linha -1][coluna] = 4; //cima
        tabuleiro[linha -2][coluna] = 4; //cima 2
        tabuleiro[linha +1][coluna] = 4; //baixo
        tabuleiro[linha +2][coluna] = 4; //baixo 2
        tabuleiro[linha][coluna -1] = 4; //esquerda
        tabuleiro[linha][coluna +1] = 4; //direita
        tabuleiro[linha][coluna -2] = 4; //meio esquerda
        tabuleiro[linha][coluna +2] = 4; //meio direita


    }
     exibirTabuleiro(tabuleiro);
}


void digite(int *linha, int *coluna){
    printf("Digite a linha e a coluna: ");
    scanf("%d %d", linha, coluna);
}

void menu(int *opcao){
    printf("Escolha uma opção:\n");
    printf("1. Habilidade Octa\n");
    printf("2. Habilidade Cone\n");
    printf("3. Habilidade Cruz\n");
    printf("4. Sair\n");
    scanf("%d", opcao);
}

int main(){

    int tabuleiro[TAM][TAM];

    iniciarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);
    
    int meusBarquinhos = 0;

    while (meusBarquinhos < 3){
        int linha, coluna; 
        digite(&linha, &coluna);
        posicionarNavio(tabuleiro, linha, coluna);
        meusBarquinhos++;
    }

    int ataque = 0;

    while(ataque != 3){
    int opcao;
    menu(&opcao);

    if (opcao == 1) {
        int linha, coluna;
        digite(&linha, &coluna);
        usarHabilidadeOcta(tabuleiro, linha, coluna);
    } else if (opcao == 2) {
        int linha, coluna;
        digite(&linha, &coluna);
        usarHabilidadeCone(tabuleiro, linha, coluna);
    } else if (opcao == 3) {
        int linha, coluna;
        digite(&linha, &coluna);
        usarHabilidadeCruz(tabuleiro, linha, coluna);
    } else {
        printf("Opção inválida!\n");
    }
    ataque++;
}


    printf("Acabou!\n");

    return 0;
}


/*#include <stdio.h>

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

    
    return 0;
}
*/