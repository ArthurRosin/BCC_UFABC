#include <stdio.h>
#include <stdlib.h>

//Exerc�cio 01

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
    printf("O primeiro numero � %d e o segundo � %d", a, b);
    return 0;
}
