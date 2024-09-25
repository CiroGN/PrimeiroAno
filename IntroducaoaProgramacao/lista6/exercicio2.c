#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    char string[] = "Instituto Federal do Paraná Câmpus Pinhais. Endereço: R. Humberto de A. C. Branco, 1575 - Jardim Amélia, Pinhais - PR, 83330-200";

    int tamanho = 0;
    //conta as posicoes (indices) dos valores 
    while (string[tamanho] != '\0') {//ira ler até chegar no \0
        tamanho++;
    }

    printf("O tamanho da string eh: %d\n", tamanho);

    printf("A string eh: ");
    for (int i = 0; string[i] != '\0'; i++) {//vai ler cada char ate o \0
        printf("%c", string[i]);
    }
}
