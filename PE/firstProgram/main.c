#include <stdio.h>
#include <stdlib.h>

int main(){
    //Coment�rios em linhas

    /*
    Coment�rios em blocos
    */

    printf("Hello world!\n\n");

    // "/n" Salto de linhas - usado dentro dos par�nteses

    printf("\nRetornar um valor: %d", printf("ola"));
    //O print retorna a quantidade de caracteres na paralvra "ola" nesse caso

    //Leitura de numeros inteiros
    int valor, valorNovo;

    valor = 50;

    printf("\n\nDigite um valor inteiro: ");
    scanf("%d", &valorNovo);
    printf("\n\nPrimeiro valor: %d\nSegundo valor: %d", valor, valorNovo);

        //system("pause") s� funciona no windows, segue outra alternativa
    printf("\n\nPressione qualquer tecla para finalizar: ");
    getchar();

    return 0;
}
