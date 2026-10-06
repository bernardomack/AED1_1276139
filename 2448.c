#include <stdio.h>
#include <stdlib.h>

// Função para busca binária que retorna o índice do elemento
int busca_binaria(const int casas[], int n, int alvo) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (casas[meio] == alvo) {
            return meio;
        } else if (casas[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Não encontrado (não deve ocorrer segundo o enunciado)
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    int *casas = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }

    int pos_atual = 0; // O carteiro começa na primeira casa (índice 0)
    long long tempo_total = 0;

    for (int i = 0; i < M; i++) {
        int destino;
        scanf("%d", &destino);

        // Busca o índice da casa de destino via busca binária
        int pos_destino = busca_binaria(casas, N, destino);

        // Calcula a distância absoluta em relação ao índice
        long long dist = pos_destino - pos_atual;
        if (dist < 0) {
            dist = -dist;
        }

        tempo_total += dist;
        pos_atual = pos_destino;
    }

    printf("%lld\n", tempo_total);

    free(casas);
    return 0;
}