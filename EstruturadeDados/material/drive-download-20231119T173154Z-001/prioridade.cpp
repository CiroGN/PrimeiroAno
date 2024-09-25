#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

class Pessoa {
private:
    std::string nome;
    int idade;
    float peso;

public:
    Pessoa() {
        // nome aleatório usando o alfabeto
        const std::string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        int nomeRandom = std::rand() % 10 + 1; // Tamanho do nome aleatório (1-10 caracteres)
        nome = ""; // inicializando vazia para ser preenchida de forma randomica
        for (int i = 0; i < nomeRandom; i++) {
            int indice = std::rand() % alfabeto.length();
            nome += alfabeto[indice];
        }

        // idade aleatória (1-100)
        idade = std::rand() % 100 + 1;

        // peso aleatório (1-120)
        peso = std::rand() % 120 + 1;
    }

    void toString() {
        std::cout << "nome: " << nome << " ; " << "idade: " << idade << " ; " << "peso: " << peso << std::endl;
    }

    int getIdade() const {
        return idade;
    }

    int getPeso() const {
        return peso;
    }
};

class PrioridadeFilaBanco {
public:
    // trabalhando com duas referências constantes da classe 
    bool operator()(const Pessoa& p1, const Pessoa& p2) const {
        // primeiro, pessoas mais velhas.
        if (p1.getIdade() > p2.getIdade()) {
            return true;
        } else if (p1.getIdade() == p2.getIdade()) {
            // em caso de mesma idade, pessoas mais pesadas têm prioridade.
            if (p1.getPeso() > p2.getPeso()) {
                return true;
            } else if (p1.getPeso() == p2.getPeso()) {
                // em caso de empate no peso, a ordem de chegada começa a valer
                return false;
            }
        }
        return false;
    }

};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Pessoa> pessoas;
    int contador = 0;

    while (contador < 10000) {
        Pessoa novaPessoa;
        pessoas.push_back(novaPessoa);
        contador++;
    }

    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].toString();
    }

    if (pessoas.size() == 10000) {
        std::cout << "foram criadas exatamente 10.000 pessoas." << std::endl;
    } else {
        std::cout << "o numero de pessoas criadas é diferente de 10.000." << std::endl;
    }

    const int num_execucoes = 100;
    double tempo_criacao_total = 0;
    double tempo_retirada_total = 0;

    for (int execucao = 0; execucao < num_execucoes; ++execucao) {
        std::priority_queue<Pessoa, std::vector<Pessoa>, PrioridadeFilaBanco> filaPrioritaria;

        auto start_criacao = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < pessoas.size(); i++) {
            filaPrioritaria.push(pessoas[i]);
        }

        auto stop_criacao = std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duracao_criacao = std::chrono::duration_cast<std::chrono::microseconds>(stop_criacao - start_criacao);
        tempo_criacao_total += duracao_criacao.count();

        auto start_retirada = std::chrono::high_resolution_clock::now();

        while (!filaPrioritaria.empty()) {
            filaPrioritaria.pop();
        }

        auto stop_retirada = std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duracao_retirada = std::chrono::duration_cast<std::chrono::microseconds>(stop_retirada - start_retirada);
        tempo_retirada_total += duracao_retirada.count();
    }

    double tempo_criacao_medio = tempo_criacao_total / num_execucoes;
    double tempo_retirada_medio = tempo_retirada_total / num_execucoes;

    std::cout << "tempo medio para criar a fila prioritaria: " << tempo_criacao_medio << " microsegundos" << std::endl;
    std::cout << "tempo medio para retirar elementos da fila prioritaria: " << tempo_retirada_medio << " microsegundos" << std::endl;

    return 0;
}
