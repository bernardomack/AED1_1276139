
#include <stdio.h>

#define INF 1000000000

int adj[250][250];
int dist[250];
int visitado[250];

int main() {
    int N, M, C, K;

    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);

        if (N == 0 && M == 0 && C == 0 && K == 0) {
            break;
        }

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            visitado[i] = 0;

            for (int j = 0; j < N; j++) {
                adj[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);

            adj[U][V] = P;
            adj[V][U] = P;
        }

        dist[K] = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;
            int menor = INF;

            for (int j = 0; j < N; j++) {
                if (!visitado[j] && dist[j] < menor) {
                    menor = dist[j];
                    u = j;
                }
            }

            if (u == -1) {
                break;
            }

            visitado[u] = 1;

            for (int v = 0; v < N; v++) {

                if (adj[u][v] == INF || visitado[v]) {
                    continue;
                }

                if (u < C - 1 && v != u + 1) {
                    continue;
                }

                if (u == C - 1) {
                    continue;
                }

                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        printf("%d\n", dist[C - 1]);
    }

    return 0;
}
