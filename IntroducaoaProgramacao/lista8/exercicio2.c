#include <stdio.h>

int calcularPotencia(int base, int expoente);
int obterEntrada(char numero[]);

int calcularPotencia(int base, int expoente) {
    int resultado = 1;
    
    for (int i = 0; i < expoente; ++i) {
        resultado *= base;
    }

    return resultado;
}

int obterEntrada(char numero[]) {
    int valor;

    do {
        printf("%s", numero);
        scanf("%d", &valor);

        if (valor <= 0) {
            printf("Digite um valor inteiro positivo.\n");
        }

    } while (valor <= 0);

    return valor;
}

int main() {
    int base = obterEntrada("Digite a base: ");
    int expoente = obterEntrada("Digite o expoente: ");

    int resultado = calcularPotencia(base, expoente);
    printf("%d^%d = %d\n", base, expoente, resultado);

}