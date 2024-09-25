#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[20];
    int idade;
    int notas[5];
};
int i;
int j;
int main(){
    struct aluno alunos[3];
    for(i = 0; i < 3; i++){
            printf("Nome: ");
            fgets(alunos[i].nome, 20, stdin);
            fflush(stdin);
            //alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
            for(j = 0; j < 5; j++){
            printf("notas: ");
            scanf("%d",&alunos[i].notas[j]);}
            fflush(stdin);
            //alunos[i].notas[j][strcspn(alunos[i].notas[j], "\n")] = '\0';
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
            printf("Aluno: %s - nota %d: %d \n", alunos[i].nome, (j+1), alunos[i].notas[j]);
        }
    }
}
