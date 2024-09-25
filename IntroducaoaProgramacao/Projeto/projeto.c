#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Tarefa {
    char titulo[20];
    char descricao[100];
    int status;  // 0 para não concluída e 1 para concluída tipo um bool 
};

struct Tarefa tarefas[100];
int totalTarefas = 0;

void Cadastro_de_tarefas() {

    if (totalTarefas < 100) {
        struct Tarefa novaTarefa;
        fflush(stdin);
        printf("Digite o titulo da tarefa: ");
        fgets(novaTarefa.titulo, 20, stdin);
        fflush(stdin);
        printf("Digite a descricao da tarefa: ");
        fgets(novaTarefa.descricao, 100, stdin);
        fflush(stdin);

        // Verifica se a tarefa já existe
        for (int i = 0; i < totalTarefas; i++) {
            if (strcmp(novaTarefa.titulo, tarefas[i].titulo) == 0 &&
                strcmp(novaTarefa.descricao, tarefas[i].descricao) == 0) {
                printf("Erro: Tarefa ja cadastrada.\n");
                return;
            }
        }
        
        novaTarefa.status = 0;

        tarefas[totalTarefas] = novaTarefa;
        totalTarefas++;

        printf("Tarefa cadastrada com sucesso.\n");
    } else {
        printf("Erro: Limite maximo de tarefas atingido.\n");
    }
}

void Listagem_de_tarefas() {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < totalTarefas; i++) {
        
        printf("%d. Titulo: %s   Descricao: %s ",
               i + 1, tarefas[i].titulo, tarefas[i].descricao);
        if(tarefas[i].status == 0){
            printf("  Status: Nao concluida\n\n");
        }
        else{
            printf("  Status: Concluida\n\n");
        }
    }
}

void Edicao_de_tarefas() {
    int numeroTarefa;
    printf("Digite o numero da tarefa que deseja editar: ");
    scanf("%d", &numeroTarefa);
    fflush(stdin);

    if (numeroTarefa >= 0 && numeroTarefa <= totalTarefas) {
        char novoTitulo[20];
        char novaDescricao[100];

        printf("Digite o novo titulo da tarefa: ");
        fgets(novoTitulo, 20, stdin);
        fflush(stdin);

        printf("Digite a nova descricao da tarefa: ");
        fgets(novaDescricao, 100, stdin);
        fflush(stdin);

        // Verifica se outra tarefa já possui os mesmos valores
        bool tarefaDuplicada = false;
        for (int i = 0; i < totalTarefas; i++) {
            if (i != numeroTarefa - 1 &&
                strcmp(novoTitulo, tarefas[i].titulo) == 0 &&
                strcmp(novaDescricao, tarefas[i].descricao) == 0) {
                tarefaDuplicada = true;
                break;
            }
        }

        if (tarefaDuplicada) {
            printf("Erro: Tarefa ja cadastrada.\n");
        } else {
            strcpy(tarefas[numeroTarefa - 1].titulo, novoTitulo);
            strcpy(tarefas[numeroTarefa - 1].descricao, novaDescricao);
            printf("Tarefa editada com sucesso.\n");
        }
    } else {
        printf("Erro: Tarefa nao encontrada.\n");
    }
}


void Remocao_de_tarefas() {
    int numeroTarefa;
    printf("Digite o numero da tarefa que deseja remover: ");
    scanf("%d", &numeroTarefa);

    if (numeroTarefa >= 0 && numeroTarefa <= totalTarefas) {
        printf("Tem certeza que deseja remover a tarefa '%s'? (1 para sim, 0 para nao): ",
               tarefas[numeroTarefa - 1].titulo);
        int confirmacao;
        scanf("%d", &confirmacao);

        if (confirmacao == 1) {
            // Move as tarefas seguintes uma posição para trás
            for (int i = numeroTarefa - 1; i < totalTarefas - 1; i++) {
                tarefas[i] = tarefas[i + 1];
            }
            totalTarefas--;

            printf("Tarefa removida com sucesso.\n");
        } else {
            printf("Acao cancelada.\n");
        }
    } else {
        printf("Erro: Tarefa nao encontrada.\n");
    }
}

void Mudar_status() {
    int numeroTarefa;
    printf("Digite o numero da tarefa para alterar o status: ");
    scanf("%d", &numeroTarefa);

    if (numeroTarefa >= 0 && numeroTarefa <= totalTarefas) {
        if (tarefas[numeroTarefa - 1].status == 0){
            tarefas[numeroTarefa - 1].status = 1;
        }
        else if(tarefas[numeroTarefa - 1].status == 1){
            tarefas[numeroTarefa - 1].status = 0;
        }

        printf("Status da tarefa alterado com sucesso.\n");
    } else {
        printf("Erro: Tarefa nao encontrada.\n");
    }
}

void Exportar() {
    FILE *arquivo = fopen("tarefas.txt", "w");

    for (int i = 0; i < totalTarefas; i++) {
        fprintf(arquivo,"%d. Titulo: %s   Descricao: %s",
                i + 1, tarefas[i].titulo, tarefas[i].descricao);
                if(tarefas[i].status == 0){
                    fprintf(arquivo,"   Status: Nao concluida\n\n");
                }
                else{
                    fprintf(arquivo,"   Status: Concluida\n\n");
                }
    }

    fclose(arquivo);

    printf("Tarefas exportadas com sucesso para 'tarefas.txt'.\n");
}


void Sair_da_aplicação(){
    printf("Saindo do gerenciador de tarefas.\n");
}
int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Editar Tarefa\n");
        printf("4. Remover Tarefa\n");
        printf("5. Alterar Status\n");
        printf("6. Exportar Tarefas\n");
        printf("7. Sair da Aplicacao\n");

        printf("Escolha a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Cadastro_de_tarefas();
                break;
            case 2:
                Listagem_de_tarefas();
                break;
            case 3:
                Edicao_de_tarefas();
                break;
            case 4:
                Remocao_de_tarefas();
                break;
            case 5:
                Mudar_status();
                break;
            case 6:
                Exportar();
                break;
            case 7:
                Sair_da_aplicação();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);
}
