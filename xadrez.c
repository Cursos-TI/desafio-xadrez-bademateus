#include <stdio.h>

// Função que verifica a posição dentro do tabuleiro
int dentroDoTabuleiro(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// NÍVEL NOVATO - Movimentos do Bispo
void moverBispo(int linha, int coluna) {
    printf("Movimentos do Bispo a partir de (%d, %d):\n", linha, coluna);
    for (int i = 1; i < 8; i++) {
        if (dentroDoTabuleiro(linha + i, coluna + i)) printf("-> (%d, %d)\n", linha + i, coluna + i);
        if (dentroDoTabuleiro(linha - i, coluna - i)) printf("-> (%d, %d)\n", linha - i, coluna - i);
        if (dentroDoTabuleiro(linha + i, coluna - i)) printf("-> (%d, %d)\n", linha + i, coluna - i);
        if (dentroDoTabuleiro(linha - i, coluna + i)) printf("-> (%d, %d)\n", linha - i, coluna + i);
    }
}

// NÍVEL NOVATO - Movimentos da Torre
void moverTorre(int linha, int coluna) {
    printf("\nMovimentos da Torre a partir de (%d, %d):\n", linha, coluna);
    for (int i = 0; i < 8; i++) {
        if (i != coluna) printf("-> (%d, %d)\n", linha, i);
    }
    for (int i = 0; i < 8; i++) {
        if (i != linha) printf("-> (%d, %d)\n", i, coluna);
    }
}

// NÍVEL NOVATO - Movimentos da Rainha
void moverRainha(int linha, int coluna) {
    printf("\nMovimentos da Rainha a partir de (%d, %d):\n", linha, coluna);
    moverBispo(linha, coluna);
    moverTorre(linha, coluna);
}

// NÍVEL AVENTUREIRO - Cavalo
void moverCavalo(int linha, int coluna) {
    printf("\nMovimentos do Cavalo a partir de (%d, %d):\n", linha, coluna);
    int movimentos[8][2] = {
        {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
        {+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}
    };
    for (int i = 0; i < 8; i++) {
        int x = linha + movimentos[i][0];
        int y = coluna + movimentos[i][1];
        if (dentroDoTabuleiro(x, y)) {
            printf("-> (%d, %d)\n", x, y);
        }
    }
}

// NÍVEL MESTRE - Bispo com recursão
void moverBispoRecursivo(int linha, int coluna, int dx, int dy) {
    int novaLinha = linha + dx;
    int novaColuna = coluna + dy;
    if (dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("-> (%d, %d)\n", novaLinha, novaColuna);
        moverBispoRecursivo(novaLinha, novaColuna, dx, dy);
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    int linha = 3, coluna = 3;

    // Nível Novato
    moverBispo(linha, coluna);
    moverTorre(linha, coluna);
    moverRainha(linha, coluna);

    // Nível Aventureiro
    moverCavalo(linha, coluna);

    // Nível Mestre
    printf("\nMovimentos recursivos do Bispo a partir de (%d, %d):\n", linha, coluna);
    moverBispoRecursivo(linha, coluna, +1, +1);
    moverBispoRecursivo(linha, coluna, -1, -1);
    moverBispoRecursivo(linha, coluna, +1, -1);
    moverBispoRecursivo(linha, coluna, -1, +1);

    return 0;
}
