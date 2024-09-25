#include <iostream>

int* criarArray() {
    int* array = new int[5]{33, 55, 77, 99, 11}; // Aloca dinamicamente um array de inteiros
    return array;
}

int main() {
    int* ponteiro = criarArray(); // Recebe o ponteiro para o array criado dinamicamente

    for (int i = 0; i < 5; ++i) {
        std::cout << "Valor " << i + 1 << " do array: " << ponteiro[i] << std::endl;
        std::cout << "Endereço do valor " << i + 1 << ": " << &ponteiro[i] << std::endl;
    }

    delete[] ponteiro; // Libera a memória alocada dinamicamente

    return 0;
}
