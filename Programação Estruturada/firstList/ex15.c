#include<stdio.h>
#include<stdlib.h>

// Exercício 15

int main(){
    int par, impar;
    int n = 1;
    while(1){
        printf("\nDigite zero para finalizar");
        printf("\nDigite um número: ");
        scanf("%d", &n);

        if(n==0){break;}

        if(n % 2 == 0){
            printf("\nPar\n");
            par = par + 1;
        } else {
            printf("\nímpar\n");
            impar++;
        }
    }

    printf("\n\nTotal de números Pares: %d", par);
    printf("\tTotal de números Ímpares: %d", impar);

}
