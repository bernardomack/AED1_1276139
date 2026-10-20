#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = malloc(100 * sizeof(int));
    int maior, pos;

    for (int i = 0; i < 100; i++) {
        scanf("%d", &v[i]);

        if (i == 0 || v[i] > maior) {
            maior = v[i];
            pos = i + 1;
        }
    }

    printf("%d\n%d\n", maior, pos);

    free(v);

    return 0;
}
