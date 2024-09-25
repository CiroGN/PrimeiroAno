#include <iostream>

void encontrarMaiorValor(int* array, int tamanho) {
    int maiorValor = *array; // Inicializa a variável maiorValor com o primeiro elemento do array
    int indice = 0; // Inicializa o índice do maior valor como 0

    for (int i = 1; i < tamanho; ++i) {
        if (*(array + i) > maiorValor) { // Compara cada elemento do array com o maiorValor atual
            maiorValor = *(array + i); // Se o elemento atual for maior, atualiza o maiorValor
            indice = i; // Atualiza o índice do maior valor
        }
    }

    std::cout << "Maior valor encontrado: " << maiorValor << std::endl;
    std::cout << "Índice do maior valor: " << indice << std::endl;
}

int main() {
    int array[] = {10, 5, 30, 15, 25}; // Exemplo de array de inteiros
    int tamanho = sizeof(array) / sizeof(array[0]); // Calcula o tamanho do array

    encontrarMaiorValor(array, tamanho); // Chama a função para encontrar o maior valor no array

    return 0;
}
