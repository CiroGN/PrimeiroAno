#include <iostream>

class Autor {
public:
    std::string nome;
    std::string nacionalidade;

    Autor(const std::string& nome, const std::string& nacionalidade)
        : nome(nome), nacionalidade(nacionalidade) {}
};

class Livro {
public:
    std::string titulo;
    Autor* autor;

    Livro(const std::string& titulo, Autor* autor)
        : titulo(titulo), autor(autor) {}

    void mostrarInformacoes() {
        std::cout << "Livro: " << titulo << std::endl;
        std::cout << "Autor: " << autor->nome << ", Nacionalidade: " << autor->nacionalidade << std::endl;
    }
};

int main() {
    Autor autor("José de Alencar", "Brasileiro");
    Livro livro("O Guarani", &autor);
    livro.mostrarInformacoes();

    return 0;
}
