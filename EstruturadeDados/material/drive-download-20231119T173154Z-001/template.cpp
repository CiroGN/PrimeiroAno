#include <iostream>
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
            int indice = std::rand() % alfabeto.length(); // garante que o indice esteja dentro dos limites do tamanho do alfabeto
            nome += alfabeto[indice]; // a cada interação uma letra eh escolhida a partir do indice sendo adicionada a nome
        }

        // idade aleatória (1-100)
        idade = std::rand() % 100 + 1;

        // peso aleatório (1-120)
        peso = std::rand() % 120 + 1;

    }

    void toString() {
        std::cout << "nome: " << nome << " ; " << "idade: " << idade << " ; " << "peso: " << peso << std::endl;
    }
};

template<class T>
class vQueue {
private:
    std::vector<T> _q;

public:
    vQueue() {
    }

    void enqueue(T e) {
        _q.push_back(e);
    }

    T dequeue() {
        T e = _q[0];
        
        _q.erase(_q.begin());
        return e;
    }
   

    bool empty() {
        return _q.empty();
    }

    int size() {
        return _q.size();
    }

    T front() {
        return _q[0];
    }
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Pessoa> pessoas;

    // Criar e preencher o vetor de pessoas (mesmo código que você compartilhou anteriormente).
    int contador = 0;
    while (contador < 10000) {
        Pessoa novaPessoa;
        pessoas.push_back(novaPessoa);
        contador++;
    }

    // imprimindo as pessoas 
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].toString();
    }

    // verificando se foram criadas 10.000 pessoas
    if (pessoas.size() == 10000) {
        std::cout << "Foram criadas exatamente 10.000 pessoas." << std::endl;
    } else {
        std::cout << "O número de pessoas criadas é diferente de 10.000." << std::endl;
    }

    const int num_execucoes = 20; // testaremos o programa de forma constante 100 vezes
    double tempo_criacao_total = 0; 
    double tempo_retirada_total = 0;

    // loop para atendermos as 100 execuçoes 
    for (int execucao = 0; execucao < num_execucoes; ++execucao) {
        vQueue<Pessoa> fila;
        
            auto start_criacao = std::chrono::high_resolution_clock::now();
            for (size_t i = 0; i < pessoas.size(); i++) {
                fila.enqueue(pessoas[i]);
            }

            auto stop_criacao = std::chrono::high_resolution_clock::now();
            std::chrono::nanoseconds duracao_criacao = std::chrono::duration_cast<std::chrono::microseconds>(stop_criacao - start_criacao);
            tempo_criacao_total += duracao_criacao.count();

            auto start_retirada = std::chrono::high_resolution_clock::now();

            while (!fila.empty()) {
                fila.dequeue();
            }
            auto stop_retirada = std::chrono::high_resolution_clock::now();
            std::chrono::nanoseconds duracao_retirada = std::chrono::duration_cast<std::chrono::microseconds>(stop_retirada - start_retirada);
            tempo_retirada_total += duracao_retirada.count();
        }

        double tempo_criacao_medio = tempo_criacao_total / num_execucoes;
        double tempo_retirada_medio = tempo_retirada_total / num_execucoes;

        std::cout << "tempo medio para criar a fila: " << tempo_criacao_medio << " microsegundos" << std::endl;
        std::cout << "tempo medio para retirar elementos da fila: " << tempo_retirada_medio << " microsegundos" << std::endl;

        return 0;
}

