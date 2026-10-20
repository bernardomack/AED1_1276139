#include <stdio.h>

int main() {
    int n, m[9][9], ok, vistos[10];

    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        ok = 1;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &m[i][j]);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++)
                vistos[j] = 0;

            for (int j = 0; j < 9; j++) {
                int v = m[i][j];
                if (v < 1 || v > 9 || vistos[v])
                    ok = 0;
                else
                    vistos[v] = 1;
            }
        }

        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 10; i++)
                vistos[i] = 0;

            for (int i = 0; i < 9; i++) {
                int v = m[i][j];
                if (v < 1 || v > 9 || vistos[v])
                    ok = 0;
                else
                    vistos[v] = 1;
            }
        }

        for (int a = 0; a < 9; a += 3) {
            for (int b = 0; b < 9; b += 3) {
                for (int i = 0; i < 10; i++)
                    vistos[i] = 0;

                for (int i = a; i < a + 3; i++) {
                    for (int j = b; j < b + 3; j++) {
                        int v = m[i][j];
                        if (v < 1 || v > 9 || vistos[v])
                            ok = 0;
                        else
                            vistos[v] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", k);
        printf("%s\n\n", ok ? "SIM" : "NAO");
    }

    return 0;
}
