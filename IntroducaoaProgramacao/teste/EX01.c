#include <stdio.h>
#include <string.h>

struct Usuario {
    char nome[50];
    char cpf[12];
    char rg[10];
    char dataNascimento[11];
    char endereco[100];
    char cidade[50];
    char estado[3];
    char celular[12];
    char email[50];
};

int main() {
    struct Usuario usuario;

    printf("Digite o nome: ");
    fgets(usuario.nome, sizeof(usuario.nome), stdin);
    fflush(stdin);

    printf("Digite o CPF (somente numeros): ");
    fgets(usuario.cpf, sizeof(usuario.cpf), stdin);
    fflush(stdin);
    usuario.cpf[strcspn(usuario.cpf, "\n")] = '\0';

    printf("Digite o RG: ");
    fgets(usuario.rg, sizeof(usuario.rg), stdin);
    fflush(stdin);
    usuario.rg[strcspn(usuario.rg, "\n")] = '\0';

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(usuario.dataNascimento, sizeof(usuario.dataNascimento), stdin);
    fflush(stdin);
    usuario.dataNascimento[strcspn(usuario.dataNascimento, "\n")] = '\0';

    printf("Digite o endereco: ");
    fgets(usuario.endereco, sizeof(usuario.endereco), stdin);
    fflush(stdin);
    usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';

    printf("Digite a cidade: ");
    fgets(usuario.cidade, sizeof(usuario.cidade), stdin);
    fflush(stdin);
    usuario.cidade[strcspn(usuario.cidade, "\n")] = '\0';

    printf("Digite o estado (sigla): ");
    fgets(usuario.estado, sizeof(usuario.estado), stdin);
    fflush(stdin);
    usuario.estado[strcspn(usuario.estado, "\n")] = '\0';

    printf("Digite o celular (somente numeros): ");
    fgets(usuario.celular, sizeof(usuario.celular), stdin);
    fflush(stdin);
    usuario.celular[strcspn(usuario.celular, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(usuario.email, sizeof(usuario.email), stdin);
    fflush(stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    printf("\nCadastro realizado com sucesso:\n");
    printf("Nome: %s", usuario.nome);        
    printf("CPF: %s         RG: %s          Data de Nascimento: %s\n", usuario.cpf, usuario.rg, usuario.dataNascimento);
    printf("Endereco: %s\n", usuario.endereco);
    printf("Cidade: %s      Estado: %s\n", usuario.cidade, usuario.estado);
    printf("Celular: %s     Email: %s", usuario.celular, usuario.email);

    return 0;
}