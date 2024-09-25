#include <iostream>

int main() {
    int numero = 10; // Variável inteira
    int& referencia_numero = numero; // Referência para a variável inteira

    std::cout << "Variável inteira: " << numero << std::endl;
    std::cout << "Referência para a variável: " << &referencia_numero << std::endl; // Endereço de memória da referência
    std::cout << "Valor da referência: " << referencia_numero << std::endl; // Valor da variável referenciada

    return 0;
}
