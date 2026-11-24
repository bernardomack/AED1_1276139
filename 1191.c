
#include <stdio.h>
#include <string.h>

char pre[30], in[30];

void posOrdem(int inicio, int fim, int *pos) {
    if (inicio > fim) {
        return;
    }

    char raiz = pre[*pos];
    (*pos)++;

    int meio = inicio;

    while (in[meio] != raiz) {
        meio++;
    }

    posOrdem(inicio, meio - 1, pos);
    posOrdem(meio + 1, fim, pos);

    printf("%c", raiz);
}

int main() {
    while (scanf("%s %s", pre, in) != EOF) {
        int n = strlen(pre);
        int pos = 0;

        posOrdem(0, n - 1, &pos);

        printf("\n");
    }

    return 0;
}
