#include<stdio.h>
#include<stdlib.h>

int main(){

    /*Sizeof x sizeof(int)*/

    int y = 0;
    short int x = 32768;
    int z = 2147483647;
    long int w = 2147483647;

    printf("Tamanho de um int na memória: %d bytes\n", sizeof y);

    //32 bits -> -2147483648 até 2147483647
    printf("Tamanho de um int na memória: %d bytes\n", sizeof(int));
    //16 bits -> -32768 = 1000000000000000 até 32767 = 0111111111111111
    printf("Tamanho de um short int (valor = %hi) na memória: %d bytes\n", x, sizeof x);
    //32 bits -> -2147483648 até 2147483647
    printf("Tamanho de um int (valor = %d) na memória: %d bytes\n", z, sizeof z);
    //64 bits -> -2147483648 até 2147483647
    printf("Tamanho de um long int (valor = %li) na memória: %d bytes\n", w, sizeof w);


    return 0;
}
