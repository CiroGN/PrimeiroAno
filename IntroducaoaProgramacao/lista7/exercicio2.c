#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[20];
    int matricula;
    float mediafinal;
};

int main() {
    struct aluno alunos[10];

    for (int i = 0; i < 10; i++) {
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        //limpar o buffer do teclado
        //o buffer precisa ser limpo para que o fgets funcione corretamente mos proximos loops
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Media final: ");
        scanf("%f", &alunos[i].mediafinal);

        while ((c = getchar()) != '\n' && c != EOF);

        printf("Aluno: %d - Nome: %s - Matricula: %d - Media final: %.1f\n", i+1, alunos[i].nome, alunos[i].matricula, alunos[i].mediafinal);
    }

    int indiceMaiorMedia = 0;
    for (int i = 1; i < 10; i++) {
        if (alunos[i].mediafinal > alunos[indiceMaiorMedia].mediafinal) {
            indiceMaiorMedia = i;
        }
    }

    printf("\nAluno com maior media:\nNome: %s - Matricula: %d - Media final: %.1f\n",
           alunos[indiceMaiorMedia].nome, alunos[indiceMaiorMedia].matricula, alunos[indiceMaiorMedia].mediafinal);

    printf("\nAlunos Aprovados:\n");
    for (int i = 0; i < 10; i++) {
        if (alunos[i].mediafinal >= 6.5) {
            printf("Nome: %s - Matricula: %d - Media final: %.1f\n", alunos[i].nome, alunos[i].matricula, alunos[i].mediafinal);
        }
    }

    printf("\nAlunos Reprovados:\n");
    for (int i = 0; i < 10; i++) {
        if (alunos[i].mediafinal < 6.5) {
            printf("Nome: %s - Matricula: %d - Media final: %.1f\n", alunos[i].nome, alunos[i].matricula, alunos[i].mediafinal);
        }
    }
}
