
#include <stdio.h>

int adj[50][50];
int grau[50];
int visitado[50];
int repetidas;

int dfs(int u, int pai, int V) {
    visitado[u] = 1;

    int impares = grau[u] % 2;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] > 0 && v != pai && !visitado[v]) {

            int resultado = dfs(v, u, V);

            if (resultado % 2 == 1) {
                repetidas++;
            }

            impares += resultado;
        }
    }

    return impares % 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, V, A;

        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        for (int i = 0; i < 50; i++) {
            grau[i] = 0;
            visitado[i] = 0;

            for (int j = 0; j < 50; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            adj[u][v]++;
            adj[v][u]++;

            grau[u]++;
            grau[v]++;
        }

        repetidas = 0;

        dfs(N, -1, V);

        printf("%d\n", A + repetidas);
    }

    return 0;
}
