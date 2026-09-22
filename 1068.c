#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *prox;
} No;

void empilhar(No **topo, char valor) {
    No *novo = malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

char desempilhar(No **topo) {
    No *aux = *topo;
    char valor = aux->valor;

    *topo = aux->prox;
    free(aux);

    return valor;
}

int main() {
    int N;
    char expressao[1001];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        No *topo = NULL;
        int correta = 1;

        fgets(expressao, 1001, stdin);

        for (int j = 0; expressao[j] != '\0'; j++) {

            if (expressao[j] == '(') {
                empilhar(&topo, '(');
            }

            else if (expressao[j] == ')') {

                if (topo == NULL) {
                    correta = 0;
                    break;
                }

                desempilhar(&topo);
            }
        }

        if (topo != NULL) {
            correta = 0;
        }

        while (topo != NULL) {
            desempilhar(&topo);
        }

        if (correta) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}