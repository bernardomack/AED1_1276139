#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char valor;
    struct no *prox;
} no;

int main() {
    char s[1001];

    while (fgets(s, 1001, stdin) != NULL) {
        no *topo = NULL;
        int ok = 1;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                no *novo = malloc(sizeof(no));
                novo->valor = '(';
                novo->prox = topo;
                topo = novo;
            } else if (s[i] == ')') {
                if (topo == NULL) {
                    ok = 0;
                    break;
                }

                no *lixo = topo;
                topo = topo->prox;
                free(lixo);
            }
        }

        if (topo != NULL)
            ok = 0;

        while (topo != NULL) {
            no *lixo = topo;
            topo = topo->prox;
            free(lixo);
        }

        printf("%s\n", ok ? "correct" : "incorrect");
    }

    return 0;
}
