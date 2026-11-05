
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

void largura(No *raiz) {
    if (raiz == NULL) return;

    No *fila[500];
    int inicio = 0, fim = 0;
    int primeiro = 1;

    fila[fim++] = raiz;

    while (inicio < fim) {
        No *atual = fila[inicio++];

        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL)
            fila[fim++] = atual->esq;

        if (atual->dir != NULL)
            fila[fim++] = atual->dir;
    }

    printf("\n");
}

void liberar(No *raiz) {
    if (raiz == NULL) return;

    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n, valor;

    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        No *raiz = NULL;

        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        largura(raiz);
        printf("\n");

        liberar(raiz);
    }

    return 0;
}
