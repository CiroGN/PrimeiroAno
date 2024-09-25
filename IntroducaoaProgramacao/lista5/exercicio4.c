#include <stdio.h>

void somarMatrizes(float m1[3][3], float m2[3][3]) {
    float resultado[3][3];

    printf("\nSoma das Matrizes:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = m1[i][j] + m2[i][j];
            printf("%.1f\t", resultado[i][j]); 
        }
        printf("\n");
    }
}

void subtrairMatrizes(float m1[3][3], float m2[3][3]) {
    float resultado[3][3];

    printf("\nSubtracao das Matrizes:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = m1[i][j] - m2[i][j];
            printf("%.1f\t", resultado[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrizes(float m1[3][3], float m2[3][3]) {
    float resultado[3][3];

    printf("\nMultiplicacao das Matrizes:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%.1f\t", resultado[i][j]);
        }
        printf("\n");
    }
}

void main() {
    float matriz1[3][3] = {{1, 5, 9}, {2, 4, 2}, {2, 3, 5}};
    float matriz2[3][3] = {{1.5, 2.5, 7.8}, {3.6, 2, 2}, {8, 7, 9}};

    printf("Matriz 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f\t", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f\t", matriz2[i][j]);
        }
        printf("\n");
    }

    somarMatrizes(matriz1, matriz2);
    subtrairMatrizes(matriz1, matriz2);
    multiplicarMatrizes(matriz1, matriz2);

}
