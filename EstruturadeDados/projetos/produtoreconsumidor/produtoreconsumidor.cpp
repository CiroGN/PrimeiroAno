#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

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

const int BUFFER_SIZE = 20;
std::vector<Pessoa> buffer;
std::mutex mtx;
std::condition_variable bufferNotEmpty, bufferNotFull;

void produtor() {
    while (true) {
        Pessoa novaPessoa;

        {
            std::unique_lock<std::mutex> lock(mtx);
            bufferNotFull.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

            buffer.push_back(novaPessoa);
            std::cout << "Produzido: ";
            novaPessoa.toString();

            bufferNotEmpty.notify_one();
        }

        // delay entre 0 e 2 sec
            std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 2000 + 0000));
    }
}

void consumidor() {
    while (true) {
        Pessoa pessoaASerConsumida;

        {
            std::unique_lock<std::mutex> lock(mtx);
            bufferNotEmpty.wait(lock, [] { return !buffer.empty(); });

            pessoaASerConsumida = buffer.back();
            buffer.pop_back();
            std::cout << "Consumido: ";
            pessoaASerConsumida.toString();

            bufferNotFull.notify_one();
        }

        // delay entre 0 e 2 sec
            std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 2000 + 0000));
    }
}

int main() {
    std::thread produtorThread(produtor);
    std::thread consumidorThread(consumidor);

    produtorThread.join();
    consumidorThread.join();

    return 0;
}
