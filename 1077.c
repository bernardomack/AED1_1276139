#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prioridade(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main() {
    int n;
    char s[1001], pilha[1001], saida[1001];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", s);

        int topo = -1, j = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            char c = s[i];

            if (isalnum(c)) {
                saida[j++] = c;
            } else if (c == '(') {
                pilha[++topo] = c;
            } else if (c == ')') {
                while (topo >= 0 && pilha[topo] != '(')
                    saida[j++] = pilha[topo--];
                topo--;
            } else {
                while (topo >= 0 && pilha[topo] != '(' &&
                       (prioridade(pilha[topo]) > prioridade(c) ||
                       (prioridade(pilha[topo]) == prioridade(c) && c != '^')))
                    saida[j++] = pilha[topo--];

                pilha[++topo] = c;
            }
        }

        while (topo >= 0)
            saida[j++] = pilha[topo--];

        saida[j] = '\0';
        printf("%s\n", saida);
    }

    return 0;
}
