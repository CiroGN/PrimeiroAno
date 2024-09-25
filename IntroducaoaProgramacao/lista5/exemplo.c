#include<stdio.h>

void main(){
    char vetor[] = {'a', 'b', 'c', 'd', 'e'};

    for (int indice = 0; indice < 5; indice++){
        printf("\nO valor no indice %d eh: %c", indice, vetor[indice]);
    }

    //ALTERANDO VALORES
    printf("\n\nALTERANDO VALORES\n\n");
    vetor[3] = 'w';
    for (int indice = 0; indice < 5; indice++){
        printf("\nO valor no indice %d eh: %c", indice, vetor[indice]);
    }

    //MATRIZES
    printf("\n\nMATRIZES!\n\n");
    int matriz[2][3] = {{1, 2, 3},
                        {4, 5, 6}};

    printf("O primeiro valor armazenado na matriz eh: %d", matriz[0][0]);

    for(int i = 0; i < 2; i++){
        printf("\n");
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
    }

    matriz[1][2] = 30;

    for(int i = 0; i < 2; i++){
        printf("\n");
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
    }
}