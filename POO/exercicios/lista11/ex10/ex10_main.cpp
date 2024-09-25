#include <iostream>

class Estudante {
private:
    std::string nome;
    int idade;

public:
    Estudante(std::string nome, int idade) : nome(nome), idade(idade) {}

    int getIdade() const {
        return idade;
    }

    std::string getNome() const {
        return nome;
    }
};

void estudante_maior(Estudante* lista, int tamanho) {
    int maiorIdade = -1;
    int idx = -1;

    for (int i = 0; i < tamanho; ++i) {
        if (lista[i].getIdade() > maiorIdade) {
            maiorIdade = lista[i].getIdade();
            idx = i;
        }
    }

    if (idx != -1) {
        std::cout << "Estudante com maior idade: " << lista[idx].getNome() << std::endl;
        std::cout << "Idade: " << lista[idx].getIdade() << std::endl;
        std::cout << "Posição no array: " << idx << std::endl;
    } else {
        std::cout << "Nenhum estudante encontrado!" << std::endl;
    }
}

int main() {
    Estudante e1 = Estudante("nome1", 22);
    Estudante e2 = Estudante("nome2", 33);
    Estudante e3 = Estudante("nome3", 19);
    Estudante e4 = Estudante("nome4", 26);
    Estudante e5 = Estudante("nome5", 30);

    Estudante estudantes[] = {e1, e2, e3, e4, e5};
    estudante_maior(estudantes, sizeof(estudantes) / sizeof(estudantes[0]));

    return 0;
}
