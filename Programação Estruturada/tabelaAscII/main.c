#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Tabela ASCII e acentuação

int main(){

    //Cada caracter possui um número decimal equivalente que por sua vez tem um binário equivalente
    //Unsigned byte = 0 a 255 bites (256 caracteres)

    setlocale(LC_ALL,"pt_BR.UTF-8");

    char letra = 'f';
    printf("Letra: %d", letra);

    char numero = 102;
    printf("\tNumero: %c", numero);

    printf("\nLetra acentuada: %s", "È");

    unsigned char letra136 = 'È';
    printf("\tLetra: %d", letra136);

}
