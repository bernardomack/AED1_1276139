
#include <stdio.h>
#include <string.h>

char pre[53], in[53];

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
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        scanf("%d %s %s", &N, pre, in);

        int pos = 0;

        posOrdem(0, N - 1, &pos);

        printf("\n");
    }

    return 0;
}
