#include <iostream>
#include <string>

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {}

    void mostra_info() {
        std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
    }

    int getIdade() const {
        return idade;
    }
};

Pessoa* criar_pessoa() {
    std::string nome;
    int idade;

    std::cout << "Digite o nome da pessoa: ";
    std::cin >> nome;

    std::cout << "Digite a idade da pessoa: ";
    std::cin >> idade;

    return new Pessoa(nome, idade);
}

void my_init(Pessoa* todos[], int TOTAL_PESSOAS) {
    std::cout << "\nCriando todas pessoas...\n";
    for (int idx = 0; idx < TOTAL_PESSOAS; idx++) {
        todos[idx] = criar_pessoa();
    }
}

void my_print_all(Pessoa* todos[], int TOTAL_PESSOAS) {
    std::cout << "\nPrint all...\n";
    for (int idx = 0; idx < TOTAL_PESSOAS; idx++) {
        todos[idx]->mostra_info();
    }
}

Pessoa* verifica_maior_idade(Pessoa* todos[], int TOTAL_PESSOAS) {
    Pessoa* pessoaMaiorIdade = todos[0];
    for (int idx = 1; idx < TOTAL_PESSOAS; idx++) {
        if (todos[idx]->getIdade() > pessoaMaiorIdade->getIdade()) {
            pessoaMaiorIdade = todos[idx];
        }
    }
    return pessoaMaiorIdade;
}



int main() {
    const int TOTAL_PESSOAS = 5;
    Pessoa* pessoas[TOTAL_PESSOAS];

    my_init(pessoas, TOTAL_PESSOAS);
    my_print_all(pessoas, TOTAL_PESSOAS);

    Pessoa* result = verifica_maior_idade(pessoas, TOTAL_PESSOAS);
    std::cout << "\nMaior idade:" << std::endl;
    result->mostra_info();

    // Liberar a memória alocada dinamicamente
    for (int i = 0; i < TOTAL_PESSOAS; ++i) {
        delete pessoas[i];
    }

    return 0;
}
