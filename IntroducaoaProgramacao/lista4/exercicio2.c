#include<stdio.h>

int valor;
int tabuada(){
    int escolhaordem;
    int escolhalaco;
    int result;
    int multiplicando;
    printf("\nordem 1 - crescente ou 2 - decrescente\nordem:");
    scanf("%d", &escolhaordem);
    if(escolhaordem==1){
        multiplicando = 1;
        printf("escolha um laco de repeticao: 1 - while, 2 - do...while, 3 - for\nlaco:");
        scanf("%d", &escolhalaco);
        if(escolhalaco==1){
            while(multiplicando <=10){
                result = (valor * multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
                multiplicando++;
            }
        }
        if(escolhalaco==2){
            do{
                result = (valor*multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
                multiplicando++;
            }while(multiplicando<=10);
        }
        if(escolhalaco==3){
            for(multiplicando = 1; multiplicando <=10; multiplicando++){
                result = (valor * multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
            }
        }
    }
    if(escolhaordem==2){
        multiplicando = 10;
        printf("escolha um laco de repeticao: 1 - while, 2 - do...while, 3 - for\nlaco:");
        scanf("%d", &escolhalaco);
        if(escolhalaco==1){
            while(multiplicando >=1){
                result = (valor * multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
                multiplicando--;
            }
        }
        if(escolhalaco==2){
            do{
                result = (valor*multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
                multiplicando--;
            }while(multiplicando>=1);
        }
        if(escolhalaco==3){
            for(multiplicando = 10; multiplicando >=1; multiplicando--){
                result = (valor * multiplicando);
                printf("\n%d * %d = %d", valor, multiplicando, result);
            }
        }
    }
    else{
        printf("escolha uma opcao valida");
        return tabuada();
    }
}

int main(){
    printf("Digite um valor: ");
    scanf("%d", &valor);
    printf("sera realizada a tabuada de 1 a 10 com o valor");
    tabuada();

}