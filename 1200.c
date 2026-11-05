
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, char valor) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

int buscar(No *raiz, char valor) {
    if (raiz == NULL)
        return 0;

    if (raiz->valor == valor)
        return 1;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

void prefixa(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;

    prefixa(raiz->esq, primeiro);
    prefixa(raiz->dir, primeiro);
}

void infixa(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    infixa(raiz->esq, primeiro);

    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;

    infixa(raiz->dir, primeiro);
}

void posfixa(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    posfixa(raiz->esq, primeiro);
    posfixa(raiz->dir, primeiro);

    if (!(*primeiro)) printf(" ");
    printf("%c", raiz->valor);
    *primeiro = 0;
}

int main() {
    No *raiz = NULL;
    char comando[20], valor;

    while (scanf("%s", comando) != EOF) {

        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }

        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);

            if (buscar(raiz, valor))
                printf("%c existe\n", valor);
            else
                printf("%c nao existe\n", valor);
        }

        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
    }

    return 0;
}
