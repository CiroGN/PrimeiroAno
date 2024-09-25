#include <stdio.h>

int main() {
    char input[100];
    int i;

    printf("Digite uma string: ");
    fgets(input, sizeof(input), stdin);

    printf("Caracteres digitados: ");
    for (i = 0; input[i] != '\0'; i++) {
        printf("%c ", input[i]);
    }
    //string ao contrário
    printf("String ao contrario: ");
    for (i = i - 1; i >= 0; i--) {//aproveita o i do for anterior e le de tras para frente
        printf("%c ", input[i]);
    }
}
