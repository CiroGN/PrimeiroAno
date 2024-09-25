#include <iostream>

bool check_vogais(char myc) {
    return myc == 'a' ||
           myc == 'e' ||
           myc == 'i' ||
           myc == 'o' ||
           myc == 'u';
}

int contar_vogais(char* txt) {
    int count = 0;
    while (*txt != '\0') { // Enquanto não chegarmos ao final da string ('\0')
        if (check_vogais(*txt)) { // Verifica se o caractere atual é uma vogal
            count++; // Se sim, incrementa o contador de vogais
        }
        txt++; // Move para o próximo caractere na string
    }
    return count;
}

void ler_teclado(char* texto, int tamanho) {
    std::cout << "Digite uma frase (max " << tamanho - 1 << " caracteres): ";
    std::cin.getline(texto, tamanho);
}

int main() {
    char texto[50];
    ler_teclado(texto, sizeof(texto));
    std::cout << "Você digitou a frase abaixo:\n";
    std::cout << texto << std::endl;
    int num = contar_vogais(texto);
    std::cout << "Total de vogais: " << num << std::endl;
    return 0;
}
