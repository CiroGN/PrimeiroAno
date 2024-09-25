#include<stdio.h>
#include<string.h>

struct cadastro{
    char nome[20];
    char cpf[11];
    char rg[9];
    char datanasc[8];
    char endereco[20];
    char cidade[20];
    char estado[20];
    char celular[11];
    char email[20];
};
int main(){
    struct cadastro info;

    printf("nome: ");
    fgets(info.nome, 20, stdin);
    info.nome[strcspn(info.nome, "\n")] = '\0';

    printf("cpf: ");
    fgets(info.cpf, 20, stdin);
    info.cpf[strcspn(info.cpf, "\n")] = '\0';

    printf("rg: ");
    fgets(info.rg, 20, stdin);
    info.rg[strcspn(info.rg, "\n")] = '\0';

    printf("data de nascimento: ");
    fgets(info.datanasc, 20, stdin);
    info.datanasc[strcspn(info.datanasc, "\n")] = '\0';

    printf("endereco: ");
    fgets(info.endereco, 20, stdin);
    info.endereco[strcspn(info.endereco, "\n")] = '\0';

    printf("cidade: ");
    fgets(info.cidade, 20, stdin);
    info.cidade[strcspn(info.cidade, "\n")] = '\0';

    printf("estado: ");
    fgets(info.estado, 20, stdin);
    info.estado[strcspn(info.estado, "\n")] = '\0';

    printf("celular: ");
    fgets(info.celular, 20, stdin);
    info.celular[strcspn(info.celular, "\n")] = '\0';

    printf("email: ");
    fgets(info.email, 20, stdin);
    info.email[strcspn(info.email, "\n")] = '\0';

    printf("\nNome\n%s\n", info.nome);
    printf("CPF                         RG                          Data Nascimento\n");
    printf("%s                          %s                          %s\n",info.cpf, info.rg, info.datanasc);
    printf("Endereco\n%s\n", info.endereco);
    printf("Cidade                      Estado\n");
    printf("%s                          %s\n", info.cidade, info.estado);
    printf("Celular                     Email\n");
    printf("%s                          %s", info.celular, info.email);
}

