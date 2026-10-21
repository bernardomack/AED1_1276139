#include <stdio.h>
#include <stdlib.h>

int busca(int v[], int n, int x) {
    int ini = 0, fim = n - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;

        if (v[meio] == x)
            return meio;

        if (v[meio] < x)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int atual = 0;
    long long tempo = 0;

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);

        int destino = busca(v, n, x);
        tempo += abs(destino - atual);
        atual = destino;
    }

    printf("%lld\n", tempo);

    free(v);

    return 0;
}
