#include <stdio.h>

void main(){
    float media;
    float soma = 0;
    float vetor[] = {10, 9.5, 8, 7.2, 5, 6.5, 9.9, 8, 4, 3,2};

    for(int i=0;i<=10;i++){
        soma += vetor[i];
    }
    printf("\nSoma das notas: %.1f", soma);
    media = soma / 10;
    printf("\nMedia dos alunos: ");
    printf("%.1f", media);

    printf("\nNotas abaixo da media:\n");
    for (int i = 0; i < 10; i++) {
        if (vetor[i] < media) {
            printf("%.1f ", vetor[i]);
        }
    }
    printf("\nNotas maiores ou iguais a media:\n");
    for (int i = 0; i < 10; i++) {
        if (vetor[i] >= media) {
            printf("%.1f ", vetor[i]);
        }
    }
    
}