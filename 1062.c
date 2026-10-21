#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int *v = malloc(n * sizeof(int));

        while (1) {
            scanf("%d", &v[0]);

            if (v[0] == 0)
                break;

            for (int i = 1; i < n; i++)
                scanf("%d", &v[i]);

            no *topo = NULL;
            int prox = 1, ok = 1;

            for (int i = 0; i < n; i++) {
                while (prox <= n && (topo == NULL || topo->valor != v[i])) {
                    no *novo = malloc(sizeof(no));
                    novo->valor = prox++;
                    novo->prox = topo;
                    topo = novo;
                }

                if (topo != NULL && topo->valor == v[i]) {
                    no *lixo = topo;
                    topo = topo->prox;
                    free(lixo);
                } else {
                    ok = 0;
                    break;
                }
            }

            while (topo != NULL) {
                no *lixo = topo;
                topo = topo->prox;
                free(lixo);
            }

            printf("%s\n", ok ? "Yes" : "No");
        }

        printf("\n");
        free(v);
    }

    return 0;
}
