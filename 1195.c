
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void preOrdem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;

    preOrdem(raiz->esquerda, primeiro);
    preOrdem(raiz->direita, primeiro);
}

void emOrdem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    emOrdem(raiz->esquerda, primeiro);

    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;

    emOrdem(raiz->direita, primeiro);
}

void posOrdem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    posOrdem(raiz->esquerda, primeiro);
    posOrdem(raiz->direita, primeiro);

    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
}

void liberar(No *raiz) {
    if (raiz == NULL) return;

    liberar(raiz->esquerda);
    liberar(raiz->direita);

    free(raiz);
}

int main() {
    int C, N, valor;

    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        No *raiz = NULL;

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);

        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        emOrdem(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
