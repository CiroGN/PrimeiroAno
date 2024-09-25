#include <iostream>
#include <string>

class Aluno {
private:
    std::string nome;
    int idade;
    int notas[3];

public:
    Aluno(std::string nome, int idade, int nota1, int nota2, int nota3) : nome(nome), idade(idade) {
        notas[0] = nota1;
        notas[1] = nota2;
        notas[2] = nota3;
    }

    void mostra_info() {
        std::cout << "Nome: " << nome << ", Idade: " << idade << ", Notas: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << notas[i] << " ";
        }
        std::cout << std::endl;
    }

    int getIdade() const {
        return idade;
    }

    int getNotaMaisAlta() const {
        int maxNota = -1;
        for (int i = 0; i < 3; ++i) {
            if (notas[i] > maxNota) {
                maxNota = notas[i];
            }
        }
        return maxNota;
    }
};

class Turma {
private:
    Aluno* alunos[3];

public:
    Turma() {
        alunos[0] = new Aluno("Ana", 25, 8, 9, 7);
        alunos[1] = new Aluno("João", 30, 7, 6, 9);
        alunos[2] = new Aluno("Maria", 20, 9, 8, 8);
    }

    Aluno* alunoMaiorIdade() {
        Aluno* alunoMaior = alunos[0];
        for (int i = 1; i < 3; ++i) {
            if (alunos[i]->getIdade() > alunoMaior->getIdade()) {
                alunoMaior = alunos[i];
            }
        }
        return alunoMaior;
    }

    Aluno* alunoNotaMaisAlta() {
        Aluno* alunoNotaAlta = alunos[0];
        for (int i = 1; i < 3; ++i) {
            if (alunos[i]->getNotaMaisAlta() > alunoNotaAlta->getNotaMaisAlta()) {
                alunoNotaAlta = alunos[i];
            }
        }
        return alunoNotaAlta;
    }

    ~Turma() {
        for (int i = 0; i < 3; ++i) {
            delete alunos[i];
        }
    }
};

int main() {
    Turma turma;

    Aluno* alunoMaiorIdade = turma.alunoMaiorIdade();
    std::cout << "Aluno de maior idade: ";
    alunoMaiorIdade->mostra_info();

    Aluno* alunoNotaMaisAlta = turma.alunoNotaMaisAlta();
    std::cout << "Aluno com a nota mais alta: ";
    alunoNotaMaisAlta->mostra_info();

    return 0;
}
