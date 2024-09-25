#include <stdio.h>

// Definição da struct para representar um contribuinte
struct Contribuinte {
    int codigo;
    int numDependentes;
    float rendaMensal;
    float descontoPorDependente;
    float imposto;
};

// Função para calcular o imposto de renda com base nas regras fornecidas
float calcularImposto(struct Contribuinte contribuinte, float salarioMinimo) {
    float desconto = contribuinte.numDependentes * contribuinte.descontoPorDependente;
    desconto = desconto > 9.0 ? 9.0 : desconto;  // Limitar o desconto a 9%
    float imposto = (contribuinte.rendaMensal * salarioMinimo) * (1.0 - desconto / 100.0);
    return imposto;
}

int main() {
    // Constantes
    int NUM_CONTRIBUINTES = 10;

    // Variáveis
    float salarioMinimo;
    struct Contribuinte contribuintes[NUM_CONTRIBUINTES];

    // Entrada do valor do salário mínimo
    printf("Informe o valor do salário mínimo: ");
    scanf("%f", &salarioMinimo);

    // Leitura dos dados dos contribuintes
    for (int i = 0; i < NUM_CONTRIBUINTES; i++) {
        // Leitura dos dados do contribuinte
        printf("\nInforme os dados para o Contribuinte %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &contribuintes[i].codigo);

        // Garantir que a renda mensal seja maior que zero
        do {
            printf("Número de Dependentes: ");
            scanf("%d", &contribuintes[i].numDependentes);
            printf("Renda Mensal: ");
            scanf("%f", &contribuintes[i].rendaMensal);

            if (contribuintes[i].rendaMensal <= 0) {
                printf("A renda mensal deve ser maior que zero. Tente novamente.\n");
            }
        } while (contribuintes[i].rendaMensal <= 0);

        // Definir o desconto por dependente e calcular o imposto
        contribuintes[i].descontoPorDependente = 1.5;
        contribuintes[i].imposto = calcularImposto(contribuintes[i], salarioMinimo);
    }

    // Exibir os resultados e exportar para um arquivo .txt
    printf("Resultados dos Contribuintes:\n");

    for (int i = 0; i < NUM_CONTRIBUINTES; i++) {
        printf("\nContribuinte %d:\n", i + 1);
        printf("Código: %d\n", contribuintes[i].codigo);
        printf("Número de Dependentes: %d\n", contribuintes[i].numDependentes);
        printf("Renda Mensal: %.2f\n", contribuintes[i].rendaMensal);
        printf("Imposto a ser pago: %.2f\n", contribuintes[i].imposto);
    }

    return 0;
}
