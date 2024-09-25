#include <stdio.h>
int main() {
    int inicio, fim;
    printf("Informe o tempo inicial (em minutos): ");
    scanf("%d", &inicio);

    printf("Informe o tempo final (em minutos, maior que o inicial): ");
    scanf("%d", &fim);

    if (inicio >= fim) {
        printf("Erro: O tempo inicial deve ser menor que o final.\n");
        return 1;
    }

    int duracao = (fim - inicio) * 60 * 1000;

    for (int tempoAtual = 0; tempoAtual <= duracao; tempoAtual += 100){
        int minutos = (tempoAtual / 60000) % 60;
        int segundos = (tempoAtual / 1000) % 60;
        int milissegundos = tempoAtual % 1000;

        printf("Tempo: %2d:%2d:%2d\n", minutos, segundos, milissegundos);
    }

    return 0;
}
