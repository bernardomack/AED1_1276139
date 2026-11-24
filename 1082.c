
#include <stdio.h>

int adj[26][26];
int visitado[26];
int componente[26];

void dfs(int u) {
    visitado[u] = 1;
    componente[u] = 1;

    for (int v = 0; v < 26; v++) {
        if (adj[u][v] == 1 && !visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++) {
        int V, E;
        scanf("%d %d", &V, &E);

        for (int i = 0; i < 26; i++) {
            visitado[i] = 0;
            componente[i] = 0;

            for (int j = 0; j < 26; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);

            int u = a - 'a';
            int v = b - 'a';

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int total = 0;

        printf("Case #%d:\n", caso);

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                dfs(i);

                for (int j = 0; j < V; j++) {
                    if (componente[j]) {
                        printf("%c,", j + 'a');
                    }
                }

                printf("\n");

                for (int j = 0; j < V; j++) {
                    componente[j] = 0;
                }

                total++;
            }
        }

        printf("%d connected components\n\n", total);
    }

    return 0;
}
