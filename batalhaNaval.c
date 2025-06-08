#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10

// Função para aplicar a habilidade Cone
void aplicarCone(int tabuleiro[][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i * 2; j++) {
            int offsetX = j - i;
            int newX = x + offsetX;
            int newY = y + i;
            if (newX >= 0 && newX < TAMANHO_TABULEIRO && newY >= 0 && newY < TAMANHO_TABULEIRO) {
                tabuleiro[newY][newX] = 1;
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarCruz(int tabuleiro[][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = -1; i <= 1; i++) {
        if (y + i >= 0 && y + i < TAMANHO_TABULEIRO) {
            tabuleiro[y + i][x] = 1;
        }
        if (x + i >= 0 && x + i < TAMANHO_TABULEIRO) {
            tabuleiro[y][x + i] = 1;
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarOctaedro(int tabuleiro[][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) == 1) {
                int newX = x + j;
                int newY = y + i;
                if (newX >= 0 && newX < TAMANHO_TABULEIRO && newY >= 0 && newY < TAMANHO_TABULEIRO) {
                    tabuleiro[newY][newX] = 1;
                }
            }
        }
    }
    tabuleiro[y][x] = 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posições das habilidades (exemplo)
    int coneX = 5;
    int coneY = 2;
    int cruzX = 2;
    int cruzY = 7;
    int octaedroX = 8;
    int octaedroY = 4;

    // Aplicar habilidades
    aplicarCone(tabuleiro, coneX, coneY);
    aplicarCruz(tabuleiro, cruzX, cruzY);
    aplicarOctaedro(tabuleiro, octaedroX, octaedroY);

    // Exibição do Tabuleiro
    printf("Tabuleiro com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
