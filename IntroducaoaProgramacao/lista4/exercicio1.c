#include <stdio.h>

int main(){
    int i = 0;
    printf("While:");
    while(i <= 10){
         printf("\n%d", i);
        i++;
    }
    printf("\nDo...While:");
    i = 0;
    do {
        printf("\n%d", i);
        i++;
    }while (i<=10);

    printf("\nFor:");
    for(i=0; i<=10; i++){
        printf("\n%d", i);
    }

}