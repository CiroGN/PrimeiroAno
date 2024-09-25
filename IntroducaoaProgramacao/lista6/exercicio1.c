#include<stdio.h>
#include<string.h>

//variaveis
char nome[20];
char nomeaux[20];
char cpf[11];
char cpfaux[20];
char rg[9];
char rgaux[20];
char datanasc[8];
char datanascaux[20];
char endereco[20];
char enderecoaux[20];
char cidade[20];
char cidadeaux[20];
char estado[20];
char estadoaux[20];
char celular[11];
char celularaux[20];
char email[20];
char emailaux[20];

int main(){

    printf("nome: ");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';//procura o char \n e substitui por \0
    strcpy(nomeaux, nome);

    printf("cpf: ");
    fgets(cpf, 20, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    strcpy(cpfaux, cpf);

    printf("rg: ");
    fgets(rg, 20, stdin);
    rg[strcspn(rg, "\n")] = '\0';
    strcpy(rgaux, rg);

    printf("data de nascimento: ");
    fgets(datanasc, 20, stdin);
    datanasc[strcspn(datanasc, "\n")] = '\0';
    strcpy(datanascaux, datanasc);

    printf("endereco: ");
    fgets(endereco, 20, stdin);
    endereco[strcspn(endereco, "\n")] = '\0';
    strcpy(enderecoaux, endereco);

    printf("cidade: ");
    fgets(cidade, 20, stdin);
    cidade[strcspn(cidade, "\n")] = '\0';
    strcpy(cidadeaux, cidade);

    printf("estado: ");
    fgets(estado, 20, stdin);
    estado[strcspn(estado, "\n")] = '\0';
    strcpy(estadoaux, estado);

    printf("celular: ");
    fgets(celular, 20, stdin);
    celular[strcspn(celular, "\n")] = '\0';
    strcpy(celularaux, celular);

    printf("email: ");
    fgets(email, 20, stdin);
    email[strcspn(email, "\n")] = '\0';
    strcpy(emailaux, email);

    printf("\nNome\n%s\n", nomeaux);
    printf("CPF                         RG                          Data Nascimento\n");
    printf("%s                          %s                          %s\n",cpfaux, rgaux, datanascaux);
    printf("Endereco\n%s\n", endereco);
    printf("Cidade                      Estado\n%s                  %s\n", cidadeaux, estadoaux);
    printf("Celular                     Email\n%s                   %s", celularaux, emailaux);
}