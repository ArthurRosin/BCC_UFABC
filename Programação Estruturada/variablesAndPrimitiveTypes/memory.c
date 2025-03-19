#include<stdio.h>
#include<stdlib.h>

int main(){

    /*Sizeof x sizeof(int)*/

    int y = 0;
    short int x = 32768;
    int z = 2147483647;
    long int w = 2147483647;

    printf("Tamanho de um int na mem�ria: %d bytes\n", sizeof y);

    //32 bits -> -2147483648 at� 2147483647
    printf("Tamanho de um int na mem�ria: %d bytes\n", sizeof(int));
    //16 bits -> -32768 = 1000000000000000 at� 32767 = 0111111111111111
    printf("Tamanho de um short int (valor = %hi) na mem�ria: %d bytes\n", x, sizeof x);
    //32 bits -> -2147483648 at� 2147483647
    printf("Tamanho de um int (valor = %d) na mem�ria: %d bytes\n", z, sizeof z);
    //64 bits -> -2147483648 at� 2147483647
    printf("Tamanho de um long int (valor = %li) na mem�ria: %d bytes\n", w, sizeof w);


    return 0;
}
