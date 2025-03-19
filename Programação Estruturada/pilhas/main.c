#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas dinâmicas - Pilhas

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data data;
} Pessoa;

typedef struct no {
    Pessoa p;
    struct no *proximo;
} No;

Pessoa Ler_pessoa() {
    Pessoa p;

    printf("\nDigite nome e data de nascimento (dd mm aaaa):\n");
    scanf(" %49[^\n]", p.nome);
    scanf("%d %d %d", &p.data.dia, &p.data.mes, &p.data.ano);

    return p;
}

void imprimirPessoa(Pessoa p) {
    printf("\nNome: %s\nData de nascimento: %02d/%02d/%04d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//Push function
No* empilhar (No *Topo){
    No *novo = malloc(sizeof(No));

    if(novo){

        novo->p = Ler_pessoa();
        novo->proximo = Topo;
        return novo;

    } else

        printf("\nErro ao alocar memoria!");

    return NULL;

}

int main() {
    No *topo = NULL;
    int opcao;

    do {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        printf("\nOpção: %d\n", opcao);

        switch (opcao) {
            case 1:
                printf("Empilhar\n");
                break;
            case 2:
                printf("Desempilhar\n");
                break;
            case 3:
                printf("Imprimir\n");
                break;
            default:
                if (opcao != 0) {
                    printf("\nOpção Inválida!\n");
                }
        }
    } while (opcao != 0);

    return 0;
}
