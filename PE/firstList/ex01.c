#include <stdio.h>
#include <stdlib.h>

//Exercício 01

int main(){
    int a, b, c;
    printf("Digite o primeiro numero:");
    scanf("%d\n\n",a);
    printf("Digite o primeiro numero:");
    scanf("%d\n\n",b);
    printf("Trocando as variaveis de lugar...\n\n");
    c = b;
    b = a;
    a = c;
    printf("O primeiro numero é %d e o segundo é %d", a, b);
    return 0;
}
