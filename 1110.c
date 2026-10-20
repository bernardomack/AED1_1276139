#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        no *inicio = NULL, *fim = NULL;

        for (int i = 1; i <= n; i++) {
            no *novo = malloc(sizeof(no));
            novo->valor = i;
            novo->prox = NULL;

            if (inicio == NULL)
                inicio = novo;
            else
                fim->prox = novo;

            fim = novo;
        }

        fim->prox = inicio;

        printf("Discarded cards:");

        while (inicio->prox != inicio) {
            no *lixo = inicio;
            inicio = inicio->prox;

            printf(" %d", lixo->valor);

            if (inicio->prox != inicio)
                printf(",");

            inicio = inicio->prox;
            fim->prox = inicio;

            lixo->prox = NULL;
            free(lixo);
        }

        printf("\nRemaining card: %d\n", inicio->valor);

        free(inicio);
    }

    return 0;
}
