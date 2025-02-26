#include<stdio.h>
#include<stdlib.h>

int main(){

/*Ambas as formas de realizar leituras de
 caracteres permitem a leitura de arquivos*/

    char letra;
    char letra2;

    printf("Digite uma  letra: ");
    letra = getc(stdin);

    printf("Caractere lido: %c\n\n", letra);

    printf("Digite uma  letra: ");
    letra2 = fgetc(stdin);

    printf("Caractere lido: %c", letra2);

    return 0;
}
