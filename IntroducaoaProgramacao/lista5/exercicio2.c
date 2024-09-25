#include <stdio.h>

void main() {
    int vetor[10];
    int valoresUnicos[10];
    int tamanhoUnico = 0;
    int repetido = 0;

    printf("Digite 10 valores nao repetidos:\n");
    for (int i = 0; i < 10; i++) {
        int valor;
        do {
            scanf("%d", &valor);

            for (int j = 0; j < tamanhoUnico; j++) {
                if (valoresUnicos[j] == valor) {
                    repetido = 1;
                    printf("Valor repetido. Digite novamente: ");
                    break;
                }
            }

            if (!repetido) {
                vetor[i] = valor;
                valoresUnicos[tamanhoUnico] = valor;
                tamanhoUnico++;
            }

        } while (repetido);
    }

    printf("\nValores digitados e suas posicoes:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao %d: Valor %d\n", i, vetor[i]);
    }

    int menorValor = vetor[0];
    int posicaoMenor = 0;
    for (int i = 1; i < 10; i++) {
        if (vetor[i] < menorValor) {
            menorValor = vetor[i];
            posicaoMenor = i;
        }
    }
    printf("\nMenor valor armazenado: %d\n", menorValor);
    printf("Posicao do menor valor: %d\n", posicaoMenor);

    int maiorValor = vetor[0];
    int posicaoMaior = 0;
    for (int i = 1; i < 10; i++) {
        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
            posicaoMaior = i;
        }
    }
    printf("\nMaior valor armazenado: %d\n", maiorValor);
    printf("Posicao do maior valor: %d\n", posicaoMaior);

    int temp = vetor[0];
    vetor[0] = vetor[9];
    vetor[9] = temp;

    printf("\nApos inverter a primeira e ultima posicao:\n  Vetor: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nPosicoes: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", i);
    }

    return 0;
}
