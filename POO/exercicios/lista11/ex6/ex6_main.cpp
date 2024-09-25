#include <iostream>

void modificaComPonteiro(int* ptr) {
    *ptr = 20; // Modifica o valor apontado pelo ponteiro
}

void modificaComReferencia(int& ref) {
    ref = 20; // Modifica diretamente o valor referenciado pela referência
}

int main() {
    int valor = 10; // Valor inicial

    modificaComPonteiro(&valor); // Chama a função com ponteiro
    std::cout << "Valor modificado com ponteiro: " << valor << std::endl;

    modificaComReferencia(valor); // Chama a função com referência
    std::cout << "Valor modificado com referência: " << valor << std::endl;

    return 0;
}
