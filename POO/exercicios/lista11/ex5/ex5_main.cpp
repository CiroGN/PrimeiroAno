#include <iostream>
using namespace std;

int* capture_array() {
    int* array = new int[5]{33, 55, 77, 99, 11}; // Aloca dinamicamente um array de inteiros
    return array;
}

void imprime_array(int* ptr, int tamanho) {
    std::cout << "Valores do array:" << std::endl;
    for (int i = 0; i < tamanho; ++i) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

void trocar_valores(int* ptr, int index1, int index2) {
    int temp = ptr[index1];
    ptr[index1] = ptr[index2];
    ptr[index2] = temp;
}

int main() {
    int* ptr = capture_array();

    imprime_array(ptr, 5);
    trocar_valores(ptr, 1, 3);
    imprime_array(ptr, 5);

    delete[] ptr; // Libera a memória alocada dinamicamente

    return 0;
}
