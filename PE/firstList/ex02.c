#include <stdio.h>
#include <stdlib.h>

//Exercício 02

int main(){
    int a, b, c;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o primeiro numero: ");
    scanf("%d", &b);
    printf("Trocando as variaveis de lugar...\n\n");
    a = a + b;
    b = a - b;
    a = a - b;
    printf("O primeiro numero: %d e o segundo: %d", a, b);

    return 0;
}
