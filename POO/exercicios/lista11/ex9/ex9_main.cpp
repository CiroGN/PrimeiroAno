#include <iostream>

void achar_menor(int* arr, int tamanho) {
    int* ptr = arr;
    int menor = INT_MAX; // Valor inicial do menor como o maior valor possível de um inteiro
    int idx = -1;

    for (int i = 0; i < tamanho; ++i) {
        if (*(ptr + i) < menor) {
            menor = *(ptr + i);
            idx = i;
        }
    }

    std::cout << "Menor valor encontrado: " << menor << std::endl;
    std::cout << "Índice do menor valor: " << idx << std::endl;
}

int main() {
    int meu_array[] = {88, 22, -11, 44, -77, 99};
    achar_menor(meu_array, 6);
    return 0;
}
