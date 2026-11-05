#include <stdio.h>

int main() {
    int n, amount;
    int coelhos = 0, ratos = 0, sapos = 0;
    int total = 0;
    char tipo;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %c", &amount, &tipo);

        total += amount;

        if (tipo == 'C') {
            coelhos += amount;
        }
        else if (tipo == 'R') {
            ratos += amount;
        }
        else if (tipo == 'S') {
            sapos += amount;
        }
    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);

    printf("Percentual de coelhos: %.2f %%\n", (float)coelhos / total * 100);
    printf("Percentual de ratos: %.2f %%\n", (float)ratos / total * 100);
    printf("Percentual de sapos: %.2f %%\n", (float)sapos / total * 100);

    return 0;
}