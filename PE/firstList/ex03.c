#include <stdio.h>
#include <stdlib.h>

//Exercício 03

int main(){
    float total, gorjeta, valor;
    int pessoas;

    printf("Digite o valor total: ");
    scanf("%f", &total);

    printf("Quantas pessoas para dividir a conta e gorjeta (opcional): ");
    scanf("%d %f", &pessoas, &gorjeta);

    gorjeta = (gorjeta/100);
    total = (total + (total * gorjeta));
    valor = total/pessoas;

    printf("Total com a gorjeta: R$ %.2f\nDivido entre %d pessoas\nR$ %.2f para cada", total, pessoas, valor);

    return 0;
}
