
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        int *cabeca = calloc(N + 1, sizeof(int));
        int *destino = malloc((M + 1) * sizeof(int));
        int *proximo = malloc((M + 1) * sizeof(int));
        int *grau = calloc(N + 1, sizeof(int));
        int *fila = malloc((N + 1) * sizeof(int));

        int aresta = 1;

        for (int i = 1; i <= N; i++)
            cabeca[i] = -1;

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            destino[aresta] = B;
            proximo[aresta] = cabeca[A];
            cabeca[A] = aresta++;

            grau[B]++;
        }

        int inicio = 0, fim = 0;

        for (int i = 1; i <= N; i++) {
            if (grau[i] == 0)
                fila[fim++] = i;
        }

        int processados = 0;

        while (inicio < fim) {
            int u = fila[inicio++];
            processados++;

            for (int e = cabeca[u]; e != -1; e = proximo[e]) {
                int v = destino[e];

                grau[v]--;

                if (grau[v] == 0)
                    fila[fim++] = v;
            }
        }

        if (processados < N)
            printf("SIM\n");
        else
            printf("NAO\n");

        free(cabeca);
        free(destino);
        free(proximo);
        free(grau);
        free(fila);
    }

    return 0;
}
