#include <iostream>

int main() {
    int array[] = {33, 55, 77, 99, 11}; // Array de inteiros
    int* ponteiro = array; // Ponteiro para o primeiro elemento do array

    for (int i = 0; i < 5; ++i) {
        std::cout << "Valor " << i + 1 << " do array (usando ponteiro): " << *ponteiro << std::endl;
        ponteiro++; // Avança para o próximo elemento do array
    }

    return 0;
}
