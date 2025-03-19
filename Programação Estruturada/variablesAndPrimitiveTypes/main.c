#include<stdio.h>
#include<stdlib.h>

int main(){
    char letra;
    char letra2;

    printf("Digite uma letra: ");
    letra = getc(stdin);  // Lê um caractere usando getc()

    // Limpa o buffer de entrada para evitar problemas com o caractere de nova linha

    while(getchar() != '\n');  // Limpa o buffer até encontrar o caractere de nova linha

    printf("Digite uma letra: ");
    letra2 = fgetc(stdin);

    printf("Caractere lido: %c\n", letra);
    printf("Caractere lido: %c\n", letra2);

    return 0;
}
