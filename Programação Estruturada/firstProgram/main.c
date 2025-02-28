#include <stdio.h>
#include <stdlib.h>

int main(){
    //Comentários em linhas

    /*
    Comentários em blocos
    */

    printf("Hello world!\n\n");

    // "/n" Salto de linhas - usado dentro dos parênteses

    printf("\nRetornar um valor: %d", printf("ola"));
    //O print retorna a quantidade de caracteres na paralvra "ola" nesse caso

    //Leitura de numeros inteiros
    int valor, valorNovo;

    valor = 50;

    printf("\n\nDigite um valor inteiro: ");
    scanf("%d\n", &valorNovo);
    printf("\n\nPrimeiro valor: %d\nSegundo valor: %d\n", valor, valorNovo);

    //%d - Numeros inteiros | %f - Numeros reais | %c - Caracteres

    //Leitura com getchar
    char letra;
    printf("\n\nDigite uma letra: ");
    letra = getchar();
    printf("\nCaracter lido: %c\n", letra);


    /*
    system("pause") só funciona no windows, segue outra alternativa
    printf("\n\nPressione qualquer tecla para finalizar: ");
    getchar();
    */

    return 0;
}
