#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        No *inicio = NULL;
        No *fim = NULL;

        /* Cria a lista */
        for (int i = 1; i <= n; i++) {
            No *novo = malloc(sizeof(No));

            novo->valor = i;
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }
        }

        printf("Discarded cards:");

        int primeiro = 1;

        while (inicio->prox != NULL) {
            /* Descarta o primeiro */
            No *descartado = inicio;

            if (primeiro) {
                printf(" %d", descartado->valor);
                primeiro = 0;
            } else {
                printf(", %d", descartado->valor);
            }

            inicio = inicio->prox;
            free(descartado);

            /* Move o primeiro para o final */
            No *movido = inicio;

            inicio = inicio->prox;

            movido->prox = NULL;
            fim->prox = movido;
            fim = movido;
        }

        printf("\n");
        printf("Remaining card: %d\n", inicio->valor);

        free(inicio);
    }

    return 0;
}