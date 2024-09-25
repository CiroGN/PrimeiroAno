#include <stdio.h>

void main() {

    int matriz[5][5];
    int vetorColuna[5] = {0};  
    int vetorLinha[5] = {0};   

    printf("Digite os elementos da matriz 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vetorColuna[j] += matriz[i][j];
            vetorLinha[i] += matriz[i][j];
        }
    }

    printf("\nMatriz 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor de soma das colunas:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t", vetorColuna[i]);
    }

    printf("\nVetor de soma das linhas:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t", vetorLinha[i]);
    }

}
