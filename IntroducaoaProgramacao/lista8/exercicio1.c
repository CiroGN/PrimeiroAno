#include <stdio.h>

float num1;
float num2;
float resultado;
char operador;

void pega_valores() {
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
}

void operacao() {
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador);

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: divisao por zero\n");
            }
            break;
        default:
            printf("Operador invalido\n");
    }

    printf("Resultado: %.2f\n", resultado);
}

int main() {
    pega_valores();
    operacao();
}
