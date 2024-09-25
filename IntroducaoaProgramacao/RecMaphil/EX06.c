#include <stdio.h>

int main() {
    int linhas, colunas;

    // Solicita o número de linhas da matriz
    do {
        printf("Digite o numero de linhas e colunas da matriz (deve ser um valor maior que 0): ");
        scanf("%d", &linhas);
    } while (linhas <= 0);

    // O número de colunas deve ser o mesmo que o número de linhas para que a matriz seja quadrada
    colunas = linhas;

    // Declaração da matriz
    int matriz[linhas][colunas];

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Listagem dos elementos da diagonal principal
    printf("Elementos na diagonal principal: ");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");

    // Listagem dos elementos da diagonal inversa
    printf("Elementos na diagonal inversa: ");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", matriz[i][linhas - i - 1]);
    }
    printf("\n");

    return 0;
}
