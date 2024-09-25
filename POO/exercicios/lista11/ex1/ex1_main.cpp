#include <iostream>

int main() {
    int numero = 10; // Variável inteira
    int* ponteiro_numero = &numero; // Ponteiro para a variável inteira

    std::cout << "Variável inteira: " << numero << std::endl;
    std::cout << "Valor do ponteiro: " << ponteiro_numero << std::endl; // Endereço de memória armazenado no ponteiro
    std::cout << "Valor apontado pelo ponteiro: " << *ponteiro_numero << std::endl; // Valor apontado pelo ponteiro

    return 0;
}
