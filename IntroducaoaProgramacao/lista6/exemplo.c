#include<stdio.h>
#include<locale.h>
#include<string.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    char string1[20] = {'I', 'F', 'P', 'R', '\0'};
    char string2[20] = "Câmpus Pinhais";
    char string3[] = "GTI e BCC";

    printf("\n%s", string1);
    printf("\n%s", string2);
    printf("\n%s", string3);

    char letra_inicial = string1[0];
    printf("\n%c", letra_inicial);

    string1[2] = 'p';
    string1[3] = 'r';
    printf("\n%s", string1);

    char nome1[20];
    char nome2[30];

    /*
    printf("\nDigite seu nome: ");
    scanf("%s", nome1);
    printf("\nSeu nome é: %s", nome1);


    printf("\nDigite seu nome completo: ");
    scanf("%s", nome2);
    printf("\nSeu nome é: %s", nome2);
    */
    char nome3[30];
    printf("\nDigite seu nome: ");
    fgets(nome3, 30, stdin);
    printf("\nSeu nome é: %s", nome3);

    char cep[15];
    char cep2[15];

    strcpy(cep, "88.234-000");
    strcpy(cep2, "87.234-000");

    if  (strcmp(cep, cep2) == 0){
        printf("\nOs CEPs sao IGUAIS!");
    } else {
        printf("\nOs CEPs sao DIFERENTES!");
    }

    int tamanho_cep = strlen(cep2);
    printf("O tamanho do CEP2 eh: %d", tamanho_cep);

}