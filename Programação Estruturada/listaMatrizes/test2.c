#include<stdio.h>
#include<stdlib.h>

int tamanho(){
    int n;
    printf("Escolha o número de andares da piramide: ");
    scanf("%d", &n);
    return n;
}

int main (){
    int i, j;
    int altura = tamanho();

    while(i <= altura){
        for(j=0; j<i; j++)
            printf("* ");
        printf("\n");
        i++;
    }
}
