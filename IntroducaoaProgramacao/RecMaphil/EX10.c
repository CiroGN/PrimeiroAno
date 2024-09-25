#include <stdio.h>

struct Endereco {
    char nomeRua[50];
    char cep[10];
};

struct Pessoa {
    char nome[50];
    char cpf[15];
    char identidade[20];
    char dataNascimento[15];
    int idade;
    char estado[30];
    char cidade[30];
    char cep[10];
    char nomeRua[50];
    int numeroCasa;
    char complemento[50];
    char telefone[15];
    char profissaoOcupacao[50];
};

int main() {
    struct Pessoa pessoas[2];

    for (int i = 0; i < 2; i++) {
        printf("Cadastro da Pessoa %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        fflush(stdin);

        printf("CPF: ");
        scanf("%s", pessoas[i].cpf);
        fflush(stdin);

        printf("RG: ");
        scanf("%s", pessoas[i].identidade);
        fflush(stdin);

        printf("Data de Nascimento: ");
        scanf("%s", pessoas[i].dataNascimento);
        fflush(stdin);

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        fflush(stdin);

        printf("Estado: ");
        scanf("%s", pessoas[i].estado);
        fflush(stdin);

        printf("Cidade: ");
        scanf("%s", pessoas[i].cidade);
        fflush(stdin);

        printf("CEP: ");
        scanf("%s", pessoas[i].cep);
        fflush(stdin);

        printf("Nome da Rua: ");
        scanf("%s", pessoas[i].nomeRua);
        fflush(stdin);

        printf("Numero da Casa: ");
        scanf("%d", &pessoas[i].numeroCasa);
        fflush(stdin);

        printf("Complemento: ");
        scanf("%s", pessoas[i].complemento);
        fflush(stdin);

        printf("Telefone: ");
        scanf("%s", pessoas[i].telefone);
        fflush(stdin);

        printf("Profissao/Ocupaçao: ");
        scanf("%s", pessoas[i].profissaoOcupacao);
        fflush(stdin);

        printf("\n");
    }

    printf("Dados Cadastrados:\n");
    for (int i = 0; i < 2; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("RG: %s\n", pessoas[i].identidade);
        printf("Data de Nascimento: %s\n", pessoas[i].dataNascimento);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Estado: %s\n", pessoas[i].estado);
        printf("Cidade: %s\n", pessoas[i].cidade);
        printf("CEP: %s\n", pessoas[i].cep);
        printf("Nome da Rua: %s\n", pessoas[i].nomeRua);
        printf("Numero da Casa: %d\n", pessoas[i].numeroCasa);
        printf("Complemento: %s\n", pessoas[i].complemento);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("Profissao/Ocupaçao: %s\n", pessoas[i].profissaoOcupacao);
    }

    return 0;
}