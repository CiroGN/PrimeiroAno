#include <stdio.h>

void tabuada() {
    int numero, inicio, fim, passo;
    char ordem[20], tipo_laco[20];

    printf("Digite o numero que deseja ver a tabuada: ");
    scanf("%d", &numero);

    printf("Digite 'crescente' ou 'decrescente' ");
    scanf("%s", ordem);

    printf("Escolha o tipo de laco desejado:'for', 'while' ou 'do...while' ");
    scanf("%s", tipo_laco);

    if (strcmp(ordem, "crescente") == 0) {
        inicio = 1;
        fim = 11;
        passo = 1;
    } else if (strcmp(ordem, "decrescente") == 0) {
        inicio = 10;
        fim = 0;
        passo = -1;
    } else {
        printf("Ordem invalida. Escolha 'crescente' ou 'decrescente'.\n");
        return;
    }

    int i = inicio;

    if (strcmp(tipo_laco, "for") == 0) {
        for (; (passo > 0 && i < fim)  (passo < 0 && i > fim); i += passo) {
            printf("%d x %d = %d\n", numero, i, numero * i);
        }
    } else if (strcmp(tipo_laco, "while") == 0) {
        while ((passo > 0 && i < fim)  (passo < 0 && i > fim)) {
            printf("%d x %d = %d\n", numero, i, numero * i);
            i += passo;
        }
    } else if (strcmp(tipo_laco, "do...while") == 0) {
        do {
            printf("%d x %d = %d\n", numero, i, numero * i);
            i += passo;
        } while ((passo > 0 && i < fim) || (passo < 0 && i > fim));
    } else {
        printf("Tipo de laco invalido. Escolha 'for', 'while' ou 'do...while'.\n");
        return;
    }
}

int main() {
    tabuada();
    return 0;
}