#include <stdio.h>

float obterNota(int numeroNota);
float calcularMediaSimples(float nota1, float nota2, float nota3, float nota4);
float calcularMediaPonderada(float nota1, float nota2, float nota3, float nota4);

float obterNota(int numeroNota) {
    float nota;
    do {
        printf("Digite a nota %d (entre 1 e 10): ", numeroNota);
        scanf("%f", &nota);

        if (nota < 1 || nota > 10) {
            printf("Digite uma nota entre 1 e 10.\n");
        }
    } while (nota < 1 || nota > 10);

    return nota;
}

float calcularMediaSimples(float nota1, float nota2, float nota3, float nota4) {
    return (nota1 + nota2 + nota3 + nota4) / 4.0;
}

float calcularMediaPonderada(float nota1, float nota2, float nota3, float nota4) {
    return (nota1 * 0.2) + (nota2 * 0.3) + (nota3 * 0.2) + (nota4 * 0.3);
}

int main() {
    float nota1 = obterNota(1);
    float nota2 = obterNota(2);
    float nota3 = obterNota(3);
    float nota4 = obterNota(4);

    int opcao;
    printf("Escolha a opcao de calculo:\n");
    printf("1. Media Simples\n");
    printf("2. Media Ponderada\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Media Simples: %.1f\n", calcularMediaSimples(nota1, nota2, nota3, nota4));
            break;
        case 2:
            printf("Media Ponderada: %.1f\n", calcularMediaPonderada(nota1, nota2, nota3, nota4));
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

}